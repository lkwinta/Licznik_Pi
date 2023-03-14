#include <iostream>
#include <cmath>
#include <Windows.h>
#include <time.h>
#include <string>

#include "kostka.h"
#include "sciana.h"

int liczba_cyfr;
double dlugosc;
double pos_x;
double start_predkosc;
double dlugosc_2;
double pos_x_2;

int main()
{
	//std::cout.precision(30);
	std::cout << "Liczenie PI: liczba kolizji\n";
	std::cout << "Podaj liczba cyfr: ";
	std::cin >> liczba_cyfr;
	std::cout << "Inicjalizacja:\nKostka 1:";
	std::cout << "\nPodaj dlugosc boku:";
	std::cin >> dlugosc;
	std::cout << "Podaj pozycje:";
	std::cin >> pos_x;
	std::cout << "Podaj predkosc startowa:";
	std::cin >> start_predkosc;
	std::cout << "Kostka 2:\nDlugosc boku: ";
	std::cin >> dlugosc_2;
	std::cout << "Podaje pozycje:";
	std::cin >> pos_x_2;

	kostka kostka1("Kostka 1", pow(100, liczba_cyfr - 1), dlugosc, pos_x, start_predkosc);
	kostka kostka2("Kostka 2", 1, dlugosc_2, pos_x_2, 0);

	kostka1.info();
	kostka2.info();

	sciana sciana(0, 2);

	bool koniec = false;
	long long kolizje = 0;

	clock_t start = clock();

	while (!koniec)
	{
		if (kostka1.czy_kolizja(kostka2))
		{
			double k1_predkosc_stara = kostka1.predkosc;
			double k2_predkosc_stara = kostka2.predkosc;

			kostka1.predkosc = k1_predkosc_stara * (kostka1.masa - kostka2.masa) + 2 * kostka2.masa * k2_predkosc_stara;
			kostka1.predkosc /= (kostka1.masa + kostka2.masa);

			kostka2.predkosc = k2_predkosc_stara * (kostka2.masa - kostka1.masa) + 2 * kostka1.masa * k1_predkosc_stara;
			kostka2.predkosc /= (kostka1.masa + kostka2.masa);

			kolizje++;
		}

		if (kostka2.czy_kolizja(sciana))
		{
			kostka2.zmien_kierunek();
			kolizje++;
		}

		kostka1.rusz();
		kostka2.rusz();
		//kostka1.info();
		//kostka2.info();

		if (kostka1.predkosc < 0 && kostka2.predkosc <= 0 && kostka1.predkosc < kostka2.predkosc)
			koniec = true;

		//printf("\rKolizje: %d Ilosc cyfr  %I64 / %d  :" , kolizje , to_string(kolizje).length() , liczba_cyfr);
	}

	std::cout << "------------------------------" << endl;
	std::cout << "WYNIK";
	std::cout << endl << "KOLIZJE " << kolizje;
	std::cout.precision(13);
	std::cout << endl << "PI " << kolizje / pow(10.0, (liczba_cyfr - 1.0));
	std::cout << endl << "TIME " << (double)(clock() - start)/CLOCKS_PER_SEC << endl << endl;
}
