#include "menu.h"


Menu::Menu() //konstruktor wypelnia zmienne przy tworzeniu obiektu
{
    flaga_menu_wplaty = 0; //flaga petli wyswietlania
    flaga_menu_wyboru = 0; //flaga petli wyswietlania
    flaga_menu_serwisowe = 0; //flaga petli wyswietlania
    wybor = 7; //zmienna do switcha
    suma = 0; //zmienna przechowujaca sume wplaty
    wplata[6]; //tablica przechowujaca dane o ilosci wrzuconych monet
    for(int i = 0 ; i <= 5 ; i++) wplata[i] = 0;
    //for(int i = 0 ; i <= 5 ; i++) std::cout << wplata[i] << std::endl;

}

Menu::~Menu()
{

};

void Menu::wyswietl_menu_wplaty()
{
flaga_menu_wplaty = 1;
    while(flaga_menu_wplaty){
        std::cout<<"Automat przyjmuje monety 5, 2, 1, 0.50, 0.20, 0.10 zl";
        std::cout<<"\nWpisz jakie wrzuciles monety\n";
        std::cout<<"1: 5zl\n";
        std::cout<<"2: 2zl\n";
        std::cout<<"3: 1zl\n";
        std::cout<<"4: 0.50zl\n";
        std::cout<<"5: 0.20zl\n";
        std::cout<<"6: 0.10zl\n";
        std::cout<<"7: Zakoncz wplacanie\n";
        std::cout<< "suma: " << std::fixed << std::setprecision(2) << suma <<std::endl;
        std::cin>>wybor;


        switch(wybor){
                case 1: wplata[0]++; break;
                case 2: wplata[1]++; break;
                case 3: wplata[2]++; break;
                case 4: wplata[3]++; break;
                case 5: wplata[4]++; break;
                case 6: wplata[5]++; break;
                case 7: if(suma >= 2.00){ //sprawdza czy do automatu wrzucono wystarczajaca ilosc pieniedzy, zanim przejdzie dalej
                            wyswietl_menu_wyboru();
                            flaga_menu_wplaty = 0; break; //przenosi do sekcji menu wyboru
                        }
                        else{
                            std::cout << "niewystarczajaca ilosc pieniedzy";
                            break;
                        }
                case 9: wyswietl_menu_serwisowe(); flaga_menu_wplaty = 0; break; //ukryta opcja wejscia w menu serwisowe
                case 0: flaga_menu_wplaty = 0; break; //wyjscie z programuplan jest taki
            }
    //for(int i = 0 ; i <= 5 ; i++) std::cout << wplata[i] << std::endl; //petle do debugowania
    suma = static_cast<float>(wplata[0]*5 + wplata[1]*2 + wplata[2]*1 + wplata[3]*0.5 + wplata[4]*0.2 + wplata[5]*0.1); //rzutowanie na float zeby obsluzyc grosze
    //for(int i = 0 ; i <= 5 ; i++) std::cout << wplata[i] << std::endl; //petle do debugowania
    }
}
void Menu::wyswietl_menu_wyboru()
{
flaga_menu_wyboru = 1;
int wybor = 0;
while(flaga_menu_wyboru)
std::cout << "1: Coca Cola \t2zl";
std::cout << "\n2: Fanta \t2zl";
std::cout << "\n3: Pepsi \t2zl";
std::cout << "\n4: Sprite \t2zl";
std::cin >> wybor;
    if(Transakcje::check_prod_avail(data, wybor)==true){
        //w tym momencie zakladamy ze suma byla wystarczajaca, napoj dostepny i wydany
        flaga_menu_wyboru = 0;
        flaga_menu_wplaty = 1;

    }
    else{
        flaga_menu_wyboru = 0;
        flaga_menu_wplaty = 1;
    }
}

void Menu::wyswietl_menu_serwisowe()
{

}
