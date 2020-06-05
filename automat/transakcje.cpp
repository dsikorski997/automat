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

double Transakcje::get_coins(){
    double tmp = calc(data); //zapisuje sume wplaconych monet
    for(size_t i = 0 ; i <= 5 ; i++) data[i] = 0; //zeruje dane w bazie
    return tmp; //zwraca sume
}

bool Transakcje::input_check(int input){ //przyjmuje wybor
    if(input >=1 && input <= 6){  //sprawdza czy jest w odpowiednim zakresie
        return true;
    }
    else{
        return false;
    }
}

bool Transakcje::prod_avail(int prod){ //sprawdza czy produkt jest dostepny
    if(data[prod+11] > 0){
        return true;
    }
    else{
        return false;
    }
}

Transakcje::Transakcje()
{

}

Transakcje::~Transakcje()
{

}
