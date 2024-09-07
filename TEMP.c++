#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;
 
int main() {
    vector<vector<float>> temperatures;
    int cities, days;
    int choice;

    do {
        
        cout << "Menu:\n";
        cout << "What option do you choose?\n";
        cout << "1. Enter temperature data\n";
        cout << "2. Calculate statistics\n";
        cout << "3. Generate report\n";
        cout << "4. Modify data\n";
        cout << "5. Delete city\n";
        cout << "6. Save data to file\n";
        cout << "7. Cargar datos desde archivo\n";
        cout << "8. Exit\n";
        int optionMenu;
        cin >> optionMenu;
        int confirm;
        vector <float> tempVector;

        switch (choice) 
        { 
        case 1:
            cout << "Set the number of cities: ";
            cin >> cities;
            cout << "et the number of days: ";
            cin >> days;
            temperaturas.resize(cities, vector<float>(days));

            for (int i = 0; i < cities; ++i)
            {
                for (int j = 0; j < days; ++j)
                {
                    float temp;
                    cout << "Enter the temperature for the city" << i + 1 << ", day " << j + 1 << ": ";
                    cin >> temp;
                    if (isTemperatureValid(temp)) {
                        temperatures[i][j] = temp;
                    }
                    else {
                        cout << "Invalid temperature. It should be between -100 and 60 degrees Celsius. 0 will be entered by default." << endl;
                        temperatures[i][j] = 0.0f;
                    }
                }
            }
        }



        case 2:
            calculateStatistics(temperatures);
            break;
        case 3:
            generateReports(temperatures);
            break;
        case 4:
            modifyTemperature(temperatures);
            break;
        case 5:
            deleteCity(temperatures);
            break;
        case 6:
            saveToFile(temperatures);
            break;
        case 7:
            loadFromFile(temperatures);
            break;
        case 8:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (choice != 8);
