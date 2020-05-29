#include "naglowki.h"
#pragma once
class Menu :protected Transakcje
{
protected:
    bool flaga_menu_wplaty; //flaga petli wyswietlania
    bool flaga_menu_wyboru; //flaga petli wyswietlania
    bool flaga_menu_serwisowe; //flaga petli wyswietlania
    int wybor; //zmienna do switcha
    float suma; //zmienna przechowujaca sume wplaty
    int wplata[6]; //tablica przechowujaca dane o ilosci wrzuconych monet
public:
    void wyswietl_menu_wplaty();
    void wyswietl_menu_wyboru();
    void wyswietl_menu_serwisowe();

    Menu();
    ~Menu();
};

