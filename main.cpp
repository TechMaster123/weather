
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Weather {
private:
    string location;
    map<string, map<string, bool>> weatherData;
    map<string, int> temperatureData;
    map<string, int> rainProbabilityData;
    map<string, int> humidityData;

public:
    Weather(const string& location)
        : location(location)
    {
        // Initialize weather data
        weatherData["today"] = { {"cloudy", false}, {"dry", true}, {"rain", false}, {"thunderstorm", false}, {"heatwaves", false} };
        weatherData["yesterday"] = { {"cloudy", true}, {"dry", false}, {"rain", true}, {"thunderstorm", false}, {"heatwaves", false} };
        weatherData["tomorrow"] = { {"cloudy", true}, {"dry", false}, {"rain", true}, {"thunderstorm", true}, {"heatwaves", false} };
        weatherData["week"] = { {"cloudy", false}, {"dry", true}, {"rain", true}, {"thunderstorm", true}, {"heatwaves", false} };
        weatherData["month"] = { {"cloudy", true}, {"dry", false}, {"rain", true}, {"thunderstorm", true}, {"heatwaves", false} };

        // Initialize temperature data
        temperatureData["today"] = 25;
        temperatureData["yesterday"] = 20;
        temperatureData["tomorrow"] = 22;
        temperatureData["week"] = 26;
        temperatureData["month"] = 24;

        // Initialize rain probability data
        rainProbabilityData["today"] = 10;
        rainProbabilityData["yesterday"] = 80;
        rainProbabilityData["tomorrow"] = 70;
        rainProbabilityData["week"] = 60;
        rainProbabilityData["month"] = 50;

        // Initialize humidity data
        humidityData["today"] = 70;
        humidityData["yesterday"] = 85;
        humidityData["tomorrow"] = 80;
        humidityData["week"] = 65;
        humidityData["month"] = 75;
    }

    map<string, bool> getWeather(const string& date) const {
        if (weatherData.find(date) != weatherData.end()) {
            return weatherData.at(date);
        }
        else {
            return {};
        }
    }

    int getTemperature(const string& date) const {
        if (temperatureData.find(date) != temperatureData.end()) {
            return temperatureData.at(date);
        }
        else {
            return 0;
        }
    }

    int getRainProbability(const string& date) const {
        if (rainProbabilityData.find(date) != rainProbabilityData.end()) {
            return rainProbabilityData.at(date);
        }
        else {
            return 0;
        }
    }

    int getHumidity(const string& date) const {
        if (humidityData.find(date) != humidityData.end()) {
            return humidityData.at(date);
        }
        else {
            return 0;
        }
    }
};

int main() {
    string name, collegeName, location;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your college name: ";
    getline(cin, collegeName);
    cout << "Enter the location: ";
    getline(cin, location);

    Weather app(location);

    cout << "Weather App" << endl;
    cout << "Name: " << name << endl;
    cout << "College name: " << collegeName << endl;
    cout << "Location: " << location << endl;
    cout << endl;

    vector<string> durations = { "today", "yesterday", "tomorrow", "week", "month" };

    while (true) {
        cout << "Select the weather report duration:" << endl;
        for (int i = 0; i < durations.size(); i++) {
            cout << i + 1 << ". " << durations[i] << endl;
        }
        cout << durations.size() + 1 << ". Exit" << endl;

        int choice;
        cout << "Enter your choice (1-" << durations.size() + 1 << "): ";
        cin >> choice;

        if (choice < 1 || choice > durations.size() + 1) {
            cout << "Invalid choice. Exiting the program." << endl;
            break;
        }

        if (choice == durations.size() + 1) {
            cout << "Exiting the program." << endl;
            break;
        }

        string selectedDuration = durations[choice - 1];

        map<string, bool> weatherInfo = app.getWeather(selectedDuration);
        if (!weatherInfo.empty()) {
            cout << endl;
            cout << "Weather Details for " << selectedDuration << ":" << endl;
            cout << "Cloudy: " << (weatherInfo["cloudy"] ? "Yes" : "No") << endl;
            cout << "Dry: " << (weatherInfo["dry"] ? "Yes" : "No") << endl;
            cout << "Rain: " << (weatherInfo["rain"] ? "Yes" : "No") << endl;
            cout << "Thunderstorm: " << (weatherInfo["thunderstorm"] ? "Yes" : "No") << endl;
            cout << "Heatwaves: " << (weatherInfo["heatwaves"] ? "Yes" : "No") << endl;
            cout << "Temperature: " << app.getTemperature(selectedDuration) << endl;
            cout << "Rain Probability: " << app.getRainProbability(selectedDuration) << endl;
            cout << "Humidity: " << app.getHumidity(selectedDuration) << endl;
            cout << endl;
        }
        else {
            cout << "Weather information not available for the selected duration." << endl;
        }
    }

    return 0;
}

















