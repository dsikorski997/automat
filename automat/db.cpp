#include "db.h"

void Db::set_data(std::vector<int> _data){ //pobiera dane z innych funkcji
    check_data(_data); //sprawdza czy dane z innych funkcji s¹ poprawne
    data = _data;
}

std::vector<int> Db::get_data(){ //wypisuje dane do podanego wektora, nie sprawdza poprawnosci bo byly sprawdzone w dbread
    return data;                   //zwraca wektor std::vector<int> zew = db.get_data();
}

void Db::check_data(std::vector<int> _data){
    if(_data.size() == 16){  //sprawdza czy wczytala sie odpowiednia ilosc pól
            std::cout << "\ncorrect data\n";
    }
    else{
        std::cout << "\ninvalid amount of data in the vector 18 != "  << _data.size() << std::endl;
        exit(3);
    }
}

bool Db::check_database_file(){

    if(database.good() == true){
        std::cout << "\ndatabase opened correctly\n";
        return true;
    }
    else{
        std::cout << "\ndatabase open error: " << database_path << std::endl;
        exit(3);  //jeœli nie to koñczy program z kodem 3
    }
}
