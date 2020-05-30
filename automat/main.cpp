#include <iostream>
#include "naglowki.h"
#include "db.h"
using namespace std;

int main()
{
Db db;
Transakcje transakcje;
transakcje.set_data(db.get_data());

transakcje.test();

db.set_data(transakcje.get_data());
return 0;
}
