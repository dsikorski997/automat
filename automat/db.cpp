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
            std::cout << "\nsprawdzam dane\n";
    }
    else{
        std::cout << "\nblad wczytywania danych, ilosc danych sie nie zgadza: "  << _data.size() << std::endl;
        exit(3);
    }
}

bool Db::check_database_file(){

    if(database.good() == true){
        return true;
    }
    else{
        std::cout << "\nblad otwarcia pliku: " << database_path << std::endl;
        exit(3);
    }
}
