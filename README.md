#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int cities = 0, days = 0;
    vector<vector<float>> temperatures;

    int menu;

    do {
        cout << "\n------------- Menu Options -------------\n";
        cout << "Which option do you choose?\n";
        cout << "1. Add data\n";
        cout << "2. Delete data\n";
        cout << "3. Modify data\n";
        cout << "4. Generate reports\n";
        cout << "5. Calculate statistics\n";
        cout << "6. Exit\n";
        cin >> menu;

        vector<float> tempVector;

        switch (menu) {
        case 1: {
            float z;

            cout << "\n------------- Add data -------------\n";
            cout << "Set the number of cities: ";
            cin >> cities;
            cout << "Set the number of days: ";
            cin >> days;

            temperatures.clear(); // Clear previous data
            cout << "\n------------------------------------\n";
            for (int a = 0; a < cities; a++) {
                tempVector.clear();
                for (int b = 0; b < days; b++) {
                    do {
                        cout << "Enter the temperature value for day #" << b + 1 << " for city #" << a + 1 << ": ";
                        cin >> z;
                        if (z < -100 || z > 60) {
                            cout << "Invalid temperature. Please enter a value between -100 and 60.\n";
                        }
                    } while (z < -100 || z > 60); // Temperature validation
                    tempVector.push_back(z);
                }
                temperatures.push_back(tempVector);
            }

            cout << "\n------------------------------------\nNow you have this data:\n";
            for (int c = 0; c < temperatures.size(); c++) {
                cout << "\nCity #" << c + 1 << endl;
                for (int d = 0; d < temperatures[c].size(); d++) {
                    cout << "Day #" << d + 1 << ": " << temperatures[c][d] << endl;
                }
            }
            break;
        }
        case 2: {
            if (temperatures.empty()) {
                cout << "No data available to delete.\n";
                break;
            }

            int cityIndex, dayIndex;
            cout << "\n---------------------- Delete data ----------------------\n";
            cout << "Select the city number to delete data from (1 to " << temperatures.size() << "): ";
            cin >> cityIndex;

            if (cityIndex < 1 || cityIndex > temperatures.size()) {
                cout << "Invalid city selection.\n";
                break;
            }

            cout << "Select the day number to delete (1 to " << temperatures[cityIndex - 1].size() << "): ";
            cin >> dayIndex;

            if (dayIndex < 1 || dayIndex > temperatures[cityIndex - 1].size()) {
                cout << "Invalid day selection.\n";
                break;
            }

            temperatures[cityIndex - 1][dayIndex - 1] = 0;
            cout << "Temperature for City #" << cityIndex << ", Day #" << dayIndex << " has been deleted (set to 0).\n";
            break;
        }
        case 3: {
            if (temperatures.empty()) {
                cout << "No data available to modify.\n";
                break;
            }

            int tempCity, tempDay;
            cout << "\nYou have this data:\n";
            for (int c = 0; c < temperatures.size(); c++) {
                cout << "\nCity #" << c + 1 << endl;
                for (int d = 0; d < temperatures[c].size(); d++) {
                    cout << "Day #" << d + 1 << ": " << temperatures[c][d] << endl;
                }
            }

            cout << "\nWhich city would you like to modify data from?\nYour selection: ";
            cin >> tempCity;

            if (tempCity > 0 && tempCity <= temperatures.size()) {
                cout << "\nData for City #" << tempCity << ":\n";
                for (int e = 0; e < temperatures[tempCity - 1].size(); e++) {
                    cout << "Day #" << e + 1 << ": " << temperatures[tempCity - 1][e] << endl;
                }

                cout << "\nWhich day would you like to modify?\nYour selection: ";
                cin >> tempDay;

                if (tempDay > 0 && tempDay <= temperatures[tempCity - 1].size()) {
                    float tempSelection;
                    do {
                        cout << "\nEnter the new value (between -100 and 60): ";
                        cin >> tempSelection;
                        if (tempSelection < -100 || tempSelection > 60) {
                            cout << "Invalid value. Please try again.\n";
                        }
                    } while (tempSelection < -100 || tempSelection > 60);

                    temperatures[tempCity - 1][tempDay - 1] = tempSelection;
                } else {
                    cout << "Invalid day number.\n";
                }
            } else {
                cout << "Invalid city number.\n";
            }
            break;
        }
        case 4: {
            cout << "\n---------------------- Report ----------------------\n";

            // Report for each city
            for (int c = 0; c < temperatures.size(); c++) {
                float sum = 0, average, max = -numeric_limits<float>::infinity(), min = numeric_limits<float>::infinity();
                for (float temp : temperatures[c]) {
                    sum += temp;
                    if (temp > max) max = temp;
                    if (temp < min) min = temp;
                }
                average = sum / temperatures[c].size();
                cout << "City #" << c + 1 << " Report:\n";
                cout << "Average: " << average << "°C\n";
                cout << "Max: " << max << "°C\n";
                cout << "Min: " << min << "°C\n";
            }

            // Report for each day considering all cities
            for (int d = 0; d < days; d++) {
                float sum = 0, average, max = -numeric_limits<float>::infinity(), min = numeric_limits<float>::infinity();
                for (int c = 0; c < cities; c++) {
                    if (d < temperatures[c].size()) {
                        float temp = temperatures[c][d];
                        sum += temp;
                        if (temp > max) max = temp;
                        if (temp < min) min = temp;
                    }
                }
                average = (cities > 0) ? sum / cities : 0;
                cout << "Day #" << d + 1 << " (all cities) Report:\n";
                cout << "Average: " << average << "°C\n";
                cout << "Max: " << max << "°C\n";
                cout << "Min: " << min << "°C\n";
            }
            break;
        }
        case 5: {
            cout << "\n---------------------- Statistics ----------------------\n";

            // Statistics for each city
            for (int c = 0; c < temperatures.size(); c++) {
                float sum = 0, average, max = -numeric_limits<float>::infinity(), min = numeric_limits<float>::infinity();
                for (float temp : temperatures[c]) {
                    sum += temp;
                    if (temp > max) max = temp;
                    if (temp < min) min = temp;
                }
                average = sum / temperatures[c].size();
                cout << "City #" << c + 1 << " Statistics:\n";
                cout << "Average: " << average << "°C\n";
                cout << "Max: " << max << "°C\n";
                cout << "Min: " << min << "°C\n";
            }

            // Statistics for each day considering all cities
            for (int d = 0; d < days; d++) {
                float sum = 0, average, max = -numeric_limits<float>::infinity(), min = numeric_limits<float>::infinity();
                for (int c = 0; c < cities; c++) {
                    if (d < temperatures[c].size()) {
                        float temp = temperatures[c][d];
                        sum += temp;
                        if (temp > max) max = temp;
                        if (temp < min) min = temp;
                    }
                }
                average = (cities > 0) ? sum / cities : 0;
                cout << "Day #" << d + 1 << " Statistics:\n";
                cout << "Average: " << average << "°C\n";
                cout << "Max: " << max << "°C\n";
                cout << "Min: " << min << "°C\n";
            }

            // Overall statistics
            vector<float> allTemperatures;
            for (const auto& cityTemps : temperatures) {
                allTemperatures.insert(allTemperatures.end(), cityTemps.begin(), cityTemps.end());
            }
            float sum = 0, average, max = -numeric_limits<float>::infinity(), min = numeric_limits<float>::infinity();
            for (float temp : allTemperatures) {
                sum += temp;
                if (temp > max) max = temp;
                if (temp < min) min = temp;
            }
            average = (allTemperatures.size() > 0) ? sum / allTemperatures.size() : 0;
            cout << "Overall Statistics:\n";
            cout << "Average: " << average << "°C\n";
            cout << "Max: " << max << "°C\n";
            cout << "Min: " << min << "°C\n";
            break;
        }
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please choose a valid option.\n";
            break;
        }
    } while (menu != 6);

    return 0;
}
