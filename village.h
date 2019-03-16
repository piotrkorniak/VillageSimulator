#ifndef VILLAGE_H
#define VILLAGE_H
#include "globals.h"
#include "household.h"

class Village
{
    Household ***householdMap;
    const unsigned int _mapSizeX;
    const unsigned int _mapSizeY;
    unsigned int _householdCounter;
public:
    Village(unsigned int mapSizeX, unsigned int mapSizeY);

    Household& getHousehold(int x, int y);

    void createHousehold(unsigned int x, unsigned int y, unsigned int numberOfResidents);

    void printMap();

    void simulateYear();

    void move(int x, int y);
};





#endif // VILLAGE_H
