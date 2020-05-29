#include <iostream>
#include "naglowki.h"
#include "db.h"
using namespace std;

int main()
{
Db db;

std::vector<int> a;
a = db.get_data();
for(size_t i = 0 ; i < a.size() ; i++) a[i];
std::cout << "---------";
db.set_data(a);
return 0;
}
