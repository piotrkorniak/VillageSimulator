#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "globals.h"
#include "villager.h"

class Household
{
    const unsigned int villagerArraySize;
    Villager **villagerArray;
    unsigned int numberOfResidents;

public:
    Household(unsigned int arraySize);

    ~Household();

    bool createNewVillager();

    void deleteDeadVillager();

    void bornNewVillagers();

    void incrementAgeOfEveryone();

    void simulateYear();

    unsigned int getNumberOfResidents();

    void addNewVillager(Villager *newVillager);

    Villager* findVillagerWhichMoveOut();

    Villager** getVillagerArray();

    bool isFreeSpace();

    void deleteFromPreviousHousehold(Villager *deleteVillager);
};

#endif // HOUSEHOLD_H
