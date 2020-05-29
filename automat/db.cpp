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

void Db::read_database(){  //odczytuje baze pod podana sciezka i zapisuje do wektora
    std::cout << "\nloading database\n";
    database.open(database_path, std::ios::in);
    if(check_database_file()){  //wywo³uje funkcje check_database_file i jeœli funkcja zwróci true to idzie dalej
        std::cout << "\nread database to ram\n";
        while(!database.eof()){  //czytaj do konca pliku database
            std::string tmp;    //zmienna tymczasowa
            getline(database, tmp);  //odczytaj linie z database i zapisz do tmp
            data.push_back(tmp); //przekonwertuj na inta i dodaj na koniec wektora
        }
            database.close(); //po pobraniu danych zamyka plik
            check_data(data);  //wywo³uje
    }
}
