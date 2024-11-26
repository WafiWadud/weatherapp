from typing import Any
import requests


def get_coordinates(city: str, api_key: str) -> tuple[float | None, float | None]:
    base_url: str = "http://api.openweathermap.org/geo/1.0/direct"
    params: dict[str, str | int] = {"q": f"{city}", "limit": 1, "appid": api_key}
    response: requests.Response = requests.get(base_url, params=params)
    if data := response.json():
        return data[0]["lat"], data[0]["lon"]
    else:
        return None, None


def get_weather(lat: float, lon: float, api_key: str) -> Any:
    base_url: str = "http://api.openweathermap.org/data/2.5/weather"
    params: dict = {
        "lat": lat,
        "lon": lon,
        "appid": api_key,
        "units": "metric",  # Use "imperial" for Fahrenheit
    }
    response: requests.Response = requests.get(base_url, params=params)
    data: Any = response.json()
    return data


def determine_emojis(weather_data: dict[str, float]) -> tuple[str, str, str]:
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
    return feels_like_emoji, humidity_emoji, temp_emoji


def main() -> None:
    api_key: str = (
        "6686d8ea951a043615db0329e612361a"  # Replace with your actual API key
    )
    city: str = input("Enter city name: ")
    lat, lon = get_coordinates(city, api_key)
    if lat and lon:
        display_weather(lat, lon, api_key)
    else:
        print("City not found.")


def display_weather(lat, lon, api_key):
    weather_data: dict[str, float] = get_weather(lat, lon, api_key)["main"]
    feels_like_emoji, humidity_emoji, temp_emoji = determine_emojis(weather_data)
    print(f"Feels like: {weather_data['feels_like']}° {feels_like_emoji}")
    print(f"Humidity: {weather_data['humidity']}% {humidity_emoji}")
    print(f"Temperature: {weather_data['temp']}° {temp_emoji}")
    print("Temperature min:", weather_data["temp_min"])
    print("Temperature max:", weather_data["temp_max"])


main()
