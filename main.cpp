#include "globals.h"
#include "villager.h"
#include "household.h"
#include "village.h"

string womanName[6]={"Ala","Ada","Ania","Monika","Basia","Anastazja"};
string manName[6]={"Adam","Piotr","Stefan","Michal","Marcin","Bartek"};
int year;

int main()
{
    Village metelin(50,50);
    int numberOfYears=5000;
    srand( time( nullptr ) );
    metelin.createHousehold(0,0,10);
    metelin.createHousehold(0,1,10);
    metelin.createHousehold(0,2,10);
    metelin.createHousehold(0,3,10);
    metelin.createHousehold(1,0,10);
    metelin.createHousehold(1,1,10);
    metelin.createHousehold(1,2,10);
    metelin.createHousehold(1,3,10);
    for(int i=0;i<10;i++)
    {
        metelin.getHousehold(0,0).createNewVillager();
        metelin.getHousehold(0,1).createNewVillager();
        metelin.getHousehold(0,2).createNewVillager();
        metelin.simulateYear();
        metelin.getHousehold(0,0).createNewVillager();
        metelin.getHousehold(0,1).createNewVillager();
        metelin.getHousehold(0,2).createNewVillager();
        metelin.simulateYear();
        metelin.getHousehold(0,0).createNewVillager();
        metelin.getHousehold(0,1).createNewVillager();
        metelin.getHousehold(0,2).createNewVillager();
        metelin.simulateYear();
        metelin.getHousehold(1,0).createNewVillager();
        metelin.getHousehold(1,1).createNewVillager();
        metelin.getHousehold(1,2).createNewVillager();
        metelin.simulateYear();
        metelin.getHousehold(1,0).createNewVillager();
        metelin.getHousehold(1,1).createNewVillager();
        metelin.getHousehold(1,2).createNewVillager();
        metelin.simulateYear();
        metelin.getHousehold(1,0).createNewVillager();
        metelin.getHousehold(1,1).createNewVillager();
        metelin.getHousehold(1,2).createNewVillager();
        metelin.simulateYear();
    }

    for(year=0;year<numberOfYears;year++)
    {
        metelin.simulateYear();
       if(year%100==0)
        {
           metelin.printMap();
        }
    }

    return 0;
}


