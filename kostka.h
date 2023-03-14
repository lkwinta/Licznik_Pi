//
// Created by Lukasz on 14.03.2023.
//

#ifndef LECZENIE_PI_ZDERZENIA_KOSTKA_H
#define LECZENIE_PI_ZDERZENIA_KOSTKA_H
#include "obiekt.h"

using namespace std;
class kostka : public obiekt
{
public:
    kostka(string _nazwa, long double _masa, int _dlugosc, double _pos_x, double _startowa_predkosc);
    void rusz();
    void info();
    const long double masa;

private:
    string nazwa;
};


#endif //LECZENIE_PI_ZDERZENIA_KOSTKA_H
