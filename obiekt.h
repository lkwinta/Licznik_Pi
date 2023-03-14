//
// Created by Lukasz on 14.03.2023.
//

#ifndef LECZENIE_PI_ZDERZENIA_OBIEKT_H
#define LECZENIE_PI_ZDERZENIA_OBIEKT_H

#include <string>
#include <iostream>

class obiekt
{
protected:
    double dlugosc;
    double pos_x;

public:
    double predkosc;

    virtual bool czy_kolizja(obiekt o)
    {
        if (pos_x - dlugosc / 2 <= o.pos_x + o.dlugosc  / 2){
            //std::cout << "!! KOLIZJA !!";
            return true;
        }
        else
            return false;
    }

    virtual void zmien_kierunek(){
        predkosc *= -1;
    }
};

#endif //LECZENIE_PI_ZDERZENIA_OBIEKT_H
