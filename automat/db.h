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
    void check_data(std::vector<int>); //sprawdza czy dane sa poprawnie wczytane
    std::fstream database; //uchwyt zewnêtrznego pliku bazy danych
    std::string database_path; //sciezka do pliku bazy danych
    bool check_database_file(); //sprawdza czy plik zostal poprawnie otwarty, jesli tak zwraca true, jesli nie to konczy program
};
