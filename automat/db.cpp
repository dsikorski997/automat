#include "db.h"

void Db::set_data(std::vector<int> _data){ //pobiera dane z innych funkcji
    check_data(_data); //sprawdza czy dane z innych funkcji s¹ poprawne
    data = _data;
}

std::vector<int> Db::get_data(){ //wypisuje dane do podanego wektora, nie sprawdza poprawnosci bo byly sprawdzone w dbread
    return data;                   //zwraca wektor std::vector<int> zew = db.get_data();
}
