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

void Transakcje::payment(std::vector<int> pay){
    for(int i = 0 ; i <= 5 ; i++) data[i] += pay[i]; //wpisuje wplacone monety do wektora danych
}

bool Transakcje::rest(double money){
    const std::vector<double> denom{ 500, 200, 100, 50, 20, 10};
    int j = 0;
    money = money * 100;
//std::cout << "/n/nsuma * 10: " << money <<  "\n\n";
    do{
        for(int i = 0 ; i <= 5 ; i++){
            if((money - denom[i] >= 0) && (data[i+5] > 0)){
                //std::cout << "\nsuma przed: " << suma << std::endl;
                std::cout << "\nWydaje\n";
                std::cout << denom[i]/100 << "zl  ";
                money = money - denom[i];
                data[i+5]--;
            //std::cout << "suma: " << suma << std::endl;
            //std::cout << "\nsuma po: " << suma << std::endl;
            //std::cout << "i: " << i << std::endl;
            }
        }
        j++;
    //std::cout << std::endl << "j: " << j << std::endl;
    }while(money > 0 && j <= 15);

    if(money > 0){
        return false;
    }
    else{
        return true;
    }
}

void Transakcje::give_prod(int prod){ //przyjmuje numer produktu 1-6 i zdejdmuje 1szt ze stanu
    data[prod+11]--;
}

int Transakcje::processing(std::vector<int> pay, double price, int set){ //wektor z wplata, cena , wybor
    double sum  = calc(pay);
//liczy sume wplaty na potrzebe klasy

    if(input_check(set)){                //sprawdza poprawnosc danych
        if(prod_avail(set)){                //sprawdza czy produkt jest dostepny
            if(sum >= price){               //sprawdza czy kwota wplaty jest wystarczajaca
                give_prod(set);             //wydaje produkt
                payment(pay);               //wplaca pieniadze do kasetki
                if(1/*rest(sum - price)*/){
                    return 0;
                }
                else{
                    return 4;
                }

            }
            else{

                return 1;
            }
        }
        else{

            return 2;
        }
    }
    else{

        return 3;
    }

}

Transakcje::Transakcje()
{

}

Transakcje::~Transakcje()
{

}
