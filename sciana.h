//
// Created by Lukasz on 14.03.2023.
//

#ifndef LECZENIE_PI_ZDERZENIA_SCIANA_H
#define LECZENIE_PI_ZDERZENIA_SCIANA_H

#include "obiekt.h"
class sciana : public obiekt
{
public:
    sciana(double pos_x, double szerokosc)
    {
        dlugosc = szerokosc;
        obiekt::pos_x = pos_x;
        predkosc = 0;
    }
};

#endif //LECZENIE_PI_ZDERZENIA_SCIANA_H
