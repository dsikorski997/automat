#include "naglowki.h"
#include "db.h"
#include "transakcje.h"
#include "menu.h"

    bool menu = 1;
    bool flaga_menu_wplaty = 1; //flaga petli wyswietlania
    bool flaga_menu_wyboru = 0; //flaga petli wyswietlania
    bool flaga_menu_serwisowe = 0; //flaga petli wyswietlania
    bool flaga_menu_srv_wplac = 0; //flaga podmenu serwisowego
    bool flaga_menu_srv_dodaj = 0; //flaga podmenu serwisowego
    int wybor = 0; //zmienna do switcha
    float suma = 0; //zmienna przechowujaca sume wplaty
    std::vector<int> wplata{0,0,0,0,0,0}; //tablica przechowujaca dane o ilosci wrzuconych monet

void obsluga_processing(int kod_z_processing, bool &flaga_menu_wyboru, bool &flaga_menu_wplaty, std::vector<int> &wplata, float &suma){
    switch(kod_z_processing){
        case 0:
            std::cout << "\nWydano produkt\n";
            flaga_menu_wyboru = 0; flaga_menu_wplaty = 1; for(size_t z = 0 ; z <= 5 ; z++)wplata[z]=0; suma = 0.00; break;
        case 1:
            std::cout << "\nZa mala kwota wplaty\n"; flaga_menu_wyboru = 0; flaga_menu_wplaty = 1; break;
        case 2:
            std::cout << "\nBrak produktu. Dokonaj innego wyboru\n"; flaga_menu_wyboru = 0; flaga_menu_wplaty = 1; break;
        case 3:
            std::cout << "\nNieprawidlowy wybor produktu\n"; flaga_menu_wyboru = 0; flaga_menu_wplaty = 1; break;
        case 4:
            std::cout << "\nBrak mozliwosci wydania reszty, skontaktuj sie z obsluga\n"; flaga_menu_wyboru = 0; flaga_menu_wplaty = 1; for(size_t z = 0 ; z <= 5 ; z++)wplata[z]=0; suma = 0.00; break;
    }


}

int main()
{
Db db; //tworzy obiekt bazy
Transakcje transakcje;  //tworzy obiekt transakcji
transakcje.set_data(db.get_data()); //przepisuje dane z bd do transakcje przez settery i gettery

Sleep(4000);

//stworzenie instancji klasy dzedziczonej tworzy tez instancje klasy bazowej dlatego to dziala
while(menu){
//flaga_menu_wplaty = 1;
    while(flaga_menu_wplaty){
        system("cls");
        std::cout<<"Napoje w ofercie\n";
        std::cout <<"Coca Cola \t2zl\n";
        std::cout <<"Fanta \t\t2zl\n";
        std::cout <<"Pepsi \t\t2zl\n";
        std::cout <<"Sprite\t\t2zl\n";
        std::cout <<"Burn \t\t3zl\n";
        std::cout <<"Red Bull \t4.50zl\n";
        std::cout<<"Automat przyjmuje monety 5, 2, 1, 0.50, 0.20, 0.10 zl\n";
        std::cout<<"Wpisz jakie wrzuciles monety\n";
        std::cout<<"1: 5zl\n";
        std::cout<<"2: 2zl\n";
        std::cout<<"3: 1zl\n";
        std::cout<<"4: 0.50zl\n";
        std::cout<<"5: 0.20zl\n";
        std::cout<<"6: 0.10zl\n";
        std::cout<<"7: Zakoncz wplacanie\n";
        std::cout<<"8: Zwrot pieniedzy\n";
        std::cout<<"9: Zakoncz program\n";
        std::cout<< "suma: " << std::fixed << std::setprecision(2) << suma <<std::endl;
        std::cin>>wybor;

            switch(wybor){
                case 1: wplata[0]++; break;
                case 2: wplata[1]++; break;
                case 3: wplata[2]++; break;
                case 4: wplata[3]++; break;
                case 5: wplata[4]++; break;
                case 6: wplata[5]++; break;
                case 7: flaga_menu_wyboru = 1; flaga_menu_wplaty = 0; break;
                case 8: system("cls"); std::cout << "Zwrot " << suma << "zl"; for(size_t z = 0 ; z <= 5 ; z++)wplata[z]=0; Sleep(4000); break;
                case 9: menu = 0; flaga_menu_wplaty = 0; break; //wyjscie z programuplan jest taki
                case 13: sprawdz_haslo(flaga_menu_serwisowe, flaga_menu_wplaty, flaga_menu_wyboru); break;  //ukryta opcja wejscia w menu serwisowe
            }
    suma = static_cast<float>(wplata[0]*5 + wplata[1]*2 + wplata[2]*1 + wplata[3]*0.5 + wplata[4]*0.2 + wplata[5]*0.1); //rzutowanie na float zeby obsluzyc grosze
    }

system("cls");
wybor = 0;
while(flaga_menu_wyboru){
    system("cls");
    std::cout << "\n1: Coca Cola    2zl";
    std::cout << "\n2: Fanta \t2zl";
    std::cout << "\n3: Pepsi \t2zl";
    std::cout << "\n4: Sprite \t2zl";
    std::cout << "\n5: Burn \t3zl";
    std::cout << "\n6: Red Bull \t4.50zl\n";
    std::cin >> wybor;
        if(wybor >=1 && wybor <= 6){
        switch(wybor){
            case 1: obsluga_processing(transakcje.processing(wplata, 2.00, wybor), flaga_menu_wyboru, flaga_menu_wplaty, wplata, suma); break;

            case 2: obsluga_processing(transakcje.processing(wplata, 2.00, wybor), flaga_menu_wyboru, flaga_menu_wplaty, wplata, suma); break;

            case 3: obsluga_processing(transakcje.processing(wplata, 2.00, wybor), flaga_menu_wyboru, flaga_menu_wplaty, wplata, suma); break;

            case 4: obsluga_processing(transakcje.processing(wplata, 2.00, wybor), flaga_menu_wyboru, flaga_menu_wplaty, wplata, suma); break;

            case 5: obsluga_processing(transakcje.processing(wplata, 3.00, wybor), flaga_menu_wyboru, flaga_menu_wplaty, wplata, suma); break;

            case 6: obsluga_processing(transakcje.processing(wplata, 4.50, wybor), flaga_menu_wyboru, flaga_menu_wplaty, wplata, suma); break;
        }
        }
        else{
            std::cout << "\nnieprawidlowy wybor\n";

        }
Sleep(4000);
}

}
return 0;
}
