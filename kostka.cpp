
#include "kostka.h"

using namespace std;

kostka::kostka(string _nazwa, long double _masa, int _dlugosc, double _pos_x, double _predkosc) : masa(_masa)
{
    nazwa = _nazwa;
    dlugosc = _dlugosc;
    pos_x = _pos_x;
    predkosc = _predkosc;
}

void kostka::rusz()
{
    pos_x -= predkosc;
}

void kostka::info()
{
    cout << "\nInfo" + nazwa;
    cout << ": Masa: " << masa;
    cout << "; Dlugosc boku: " << dlugosc;
    cout << "; Aktualna predkosc: " << predkosc;
    cout << "; Aktualna pozycja: " << pos_x << endl;
}