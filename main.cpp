#include "globals.h"
#include "villager.h"
#include "household.h"
#include "village.h"

#include "test.h"

//wiek+20, jedyny mieszkaniec domu
//Klasa powinnna posiadać metodę postarzającą domostwa o jeden rok. Jeżeli dziecko musiało się wyprowadzić z
//domu, powinno poszukać możliwości zamieszkania w tej samej wiosce - poprzez dosiedlenie się do samotnej osoby
//przeciwnej płci lub poprzez założenie domostwa. W pierwszej kolejności należy poszukać istniejącego domostwa,
//następnie dosiedlenia się do innej osoby, w ostateczności należy założyć nowe domostwo. Przy zakładaniu
//swojego domostwa, w pierwszej kolejności należy sprawdzić najbliższe sąsiedztwo domu rodziców (8 pól), a
//jeżeli są zajęte, wybrać dowolne inne miejsce. Jeżeli nie ma miejsca do osiedlenia, osoba musi opuścić wioskę.
//Destruktor powinien wówczas wyświetlić informację o emigracji. Jeżeli nikt przez rok nie zasiedli domostwa,
//powinno ono zostać zniszczone.

string womanName[6]={"Ala","Ada","Ania","Monika","Basia","Anastazja"};
string manName[6]={"Adam","Piotr","Stefan","Michal","Marcin","Bartek"};
int year;

int main()
{
    //    int numberOfVillagers=500;
    //    int numberOfSpaceInHousehold=1000;
    //    int numberOfYears=10000;

    //    srand( time( NULL ) );
    //    Household h(numberOfSpaceInHousehold);
    //    for(int i=0; i<numberOfVillagers; ++i)
    //    {
    //        h.createNewVillager();
    //    }
    //    for(year=0;year<numberOfYears;year++)
    //    {
    //        h.simulateYear();
    //    }
    Village metelin(10,15);
    metelin.createHousehold(1,1,10);
    metelin.getHousehold(1,1).createNewVillager();
    metelin.getHousehold(1,1).createNewVillager();
    metelin.getHousehold(1,1).createNewVillager();
    metelin.getHousehold(1,1).createNewVillager();
    metelin.printMap();

    return 0;
}


