from typing import Any
import requests
from dataclasses import dataclass


@dataclass
class Coordinates:
    lat: float | None
    lon: float | None


@dataclass
class WeatherEmojis:
    feels_like: str
    humidity: str
    temp: str


class WeatherAPI:
    def __init__(self, api_key: str) -> None:
        self.api_key: str = api_key
        self.geo_base_url: str = "http://api.openweathermap.org/geo/1.0/direct"
        self.weather_base_url: str = "http://api.openweathermap.org/data/2.5/weather"

    def get_coordinates(self, city: str) -> Coordinates:
        params: dict[str, str | int] = {
            "q": f"{city}",
            "limit": 1,
            "appid": self.api_key,
        }
        response: requests.Response = requests.get(self.geo_base_url, params=params)
        if data := response.json():
            return Coordinates(data[0]["lat"], data[0]["lon"])
        return Coordinates(None, None)

    def get_weather(self, coordinates: Coordinates) -> Any:
        params: dict = {
            "lat": coordinates.lat,
            "lon": coordinates.lon,
            "appid": self.api_key,
            "units": "metric",  # Use "imperial" for Fahrenheit
        }
        response: requests.Response = requests.get(self.weather_base_url, params=params)
        data: Any = response.json()
        return data


class WeatherEmojiDeterminer:
    @staticmethod
    def determine_emojis(weather_data: dict[str, float]) -> WeatherEmojis:
        feels_like: float = weather_data["feels_like"]
        humidity: float = weather_data["humidity"]
        temp: float = weather_data["temp"]

        # Determine emojis based on feels_like temperature
        if feels_like >= 30:
            feels_like_emoji = "☀️"  # Sunny
        elif feels_like >= 20:
            feels_like_emoji = "☁️"  # Partly Sunny
        else:
            feels_like_emoji = "❄️"  # Snowflake

        # Determine emojis based on humidity
        humidity_emoji = "💦" if humidity >= 70 else "💧"

        # Determine emojis based on temperature in Celsius
        if temp >= 30:
            temp_emoji = "🔥"  # Fire
        elif temp >= 20:
            temp_emoji = "☀️"  # Sunny
        elif temp >= 10:
            temp_emoji = "🌡️"  # Hot Face
        else:
            temp_emoji = "❄️"  # Snowflake

        return WeatherEmojis(feels_like_emoji, humidity_emoji, temp_emoji)


class WeatherDisplay:
    def __init__(self, api_key: str) -> None:
        self.weather_api: WeatherAPI = WeatherAPI(api_key)
        self.emoji_determiner: WeatherEmojiDeterminer = WeatherEmojiDeterminer()

    def display_weather(self, coordinates: Coordinates) -> None:
        weather_data: dict[str, float] = self.weather_api.get_weather(coordinates)[
            "main"
        ]
        emojis: WeatherEmojis = self.emoji_determiner.determine_emojis(weather_data)

        print(f"Feels like: {weather_data['feels_like']}° {emojis.feels_like}")
        print(f"Humidity: {weather_data['humidity']}% {emojis.humidity}")
        print(f"Temperature: {weather_data['temp']}° {emojis.temp}")
        print("Temperature min:", weather_data["temp_min"])
        print("Temperature max:", weather_data["temp_max"])


def main() -> None:
    api_key: str = (
        "6686d8ea951a043615db0329e612361a"  # Replace with your actual API key
    )
    weather_display: WeatherDisplay = WeatherDisplay(api_key)
    weather_api: WeatherAPI = WeatherAPI(api_key)

    city: str = input("Enter city name: ")
    coordinates: Coordinates = weather_api.get_coordinates(city)

    if coordinates.lat and coordinates.lon:
        weather_display.display_weather(coordinates)
    else:
        print("City not found.")


if __name__ == "__main__":
    main()
