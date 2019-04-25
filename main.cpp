#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "my_lib.cpp"
#include "aux_lib.cpp"

#define LINE_LENGTH 130
#define CITY_COUNTRY_LENGTH 32

using namespace std;

int main(int argc, char** argv) {
        int city_counter = 0, earthquake_counter = 0;
        bool first_earthquake = true;
        int city_chars = 0, country_chars = 0;
        char c;
        double *intensities, intensity;
        int *durations, *dates, *times, day, month, year, hours, minutes, seconds, duration;

        cout.precision(2);
        cout << fixed;
        cout << setw(90) << "Reporte de los sismos a traves del tiempo" << endl;

        while (1) {
                cin.clear();

                city_counter++;
                earthquake_counter=0;
                first_earthquake = true;

                print_line('=', LINE_LENGTH);
                cout << "No" << setw(7) << "PAIS"
                          << setw(32) << "CIUDAD"
                          << setw(32) << "INTENSIDAD"
                          << setw(12) << "DURACION"
                          << setw(10) << "FECHA"
                          << setw(11) << "HORA"
                          << setw(17) << "OBSERVACION" << endl;
                print_line('=', LINE_LENGTH);

                cout << setw(2) << city_counter << "     ";
                city_chars = country_chars = 0;

                while ( (c = cin.get()) != ',' ) {
                        city_chars++;
                        cout.put(c);
                }
                for (int i = 0; i < CITY_COUNTRY_LENGTH-city_chars; i++) cout.put(' ');

                cin >> ws;

                while ( (c = cin.get()) != ':' ) {
                        country_chars++;
                        cout.put(c);
                }
                for (int i = 0; i < CITY_COUNTRY_LENGTH-country_chars; i++) cout.put(' ');

                while (cin >> intensity) {
                        cin >> duration;
                        cin >> day >> c >> month >> c >> year;
                        cin >> hours >> c >> minutes >> c >> seconds;
                        intensities[earthquake_counter] = intensity;
                        durations[earthquake_counter] = duration;
                        dates[earthquake_counter] = day + month*30 + year*365;
                        times[earthquake_counter] = hours*3600 + minutes*60 + seconds;
                        earthquake_counter++;
                }


                print_line('-', LINE_LENGTH);
                cout << "RESUMEN" << endl;
                cout << "SISMO MAS ANTIGUO" << endl;
                cout << "SISMO MAS RECIENTE" << endl;
                print_line('*', LINE_LENGTH);
                cout << "DISTRIBUCION DE FRECUENCIAS" << endl;
                cout << "INTENSIDADES" << endl;
                print_line('_', LINE_LENGTH);
                cout << "DURACIONES" << endl;
                print_line('/', LINE_LENGTH);
                cout << "CANTIDAD DE REGISTROS: " << endl;
                print_line('/', LINE_LENGTH);

                if (cin.eof())
                        break;
                cin.clear();
        }
}
