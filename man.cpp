#include <iostream>
#include <string>
#include "Perso.h"
#include "Wpn.h"

using namespace std;


int main()
{
    Perso ron("Trident", 35), saul;

    saul = ron;
    cout << saul;

    return 0;
}


