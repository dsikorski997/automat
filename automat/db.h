#include "naglowki.h"
#pragma once

class Db
{
public:
    void set_database_path(std::string);
    void set_data(std::vector<int>); //pobiera dane do klasy
    std::vector<int> get_data(); //wypisuje dane w podany vektor
    Db();
    ~Db();
protected:
    std::vector<int> data; //wektor przechowuj¹cy wczytane dane
};
