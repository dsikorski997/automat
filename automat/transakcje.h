#include "naglowki.h"
#pragma once

class Transakcje
{
//friend class Menu
public:
    void set_data(std::vector<int>);
    std::vector<int> get_data();
    void test()
    double get_coins();
    int processing(std::vector<int>, double, int);
    int add_prod(int, int);
    int prod_quan(int);
    int coins_quan(int);
    Transakcje();
    ~Transakcje();

protected:
    std::vector<int> data;  //pola 0-5 wplacone monety, 6-11 monety do wydawania reszty, 12-17 ilosc napojow w auromacie
    double calc(std::vector<int>);
    bool input_check(int);
    bool prod_avail(int);
    void give_prod(int);
    void payment(std::vector<int>);
    bool rest(double);
};
