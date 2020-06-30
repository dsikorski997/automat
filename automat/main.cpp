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



int main()
{
Db db;
Transakcje transakcje;
transakcje.set_data(db.get_data());

transakcje.test();

db.set_data(transakcje.get_data());
return 0;
}
