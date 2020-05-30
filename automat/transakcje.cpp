#include "transakcje.h"

void Transakcje::set_data(std::vector<int> _data){ //pobiera dane z podanego wektora
    data = _data;
}

std::vector<int> Transakcje::get_data(){ //wypisuje dane do podanego wektora
    return data;
}

Transakcje::test(){
    for(size_t i = 0 ; i < data.size() ; i++) std::cout << data[i] << std::endl;
}

double Transakcje::calc(std::vector<int> pay){
    return static_cast<float>(pay[0]*5 + pay[1]*2 + pay[2]*1 + pay[3]*0.5 + pay[4]*0.2 + pay[5]*0.1);
}

Transakcje::Transakcje()
{

}

Transakcje::~Transakcje()
{

}
