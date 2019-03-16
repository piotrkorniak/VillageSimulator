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
    int getNumberOfResidents();

    Villager* moveVillager();
};

#endif // HOUSEHOLD_H
