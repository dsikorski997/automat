#include "transakcje.h"

void Transakcje::set_data(std::vector<int> _data){ //pobiera dane z podanego wektora
    data = _data;
}

std::vector<int> Transakcje::get_data(){ //wypisuje dane do podanego wektora
    return data;
}

Transakcje::Transakcje()
{

}

Transakcje::~Transakcje()
{

}
