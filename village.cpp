#include "village.h"



Household &Village::getHousehold(int x, int y)
{
    return *householdMap[x][y];
}

void Village::createHousehold(unsigned int x, unsigned int y, unsigned int numberOfResidents)
{
    householdMap[x][y] = new Household(numberOfResidents);
    _householdCounter++;
}

void Village::printMap()
{
    for(unsigned int i=0;i<_mapSizeX;i++)
    {
        for(unsigned int j=0;j<_mapSizeY;j++)
        {
            unsigned int numberOfResidents;
            if(householdMap[i][j])
            {
                numberOfResidents=householdMap[i][j]->getNumberOfResidents();
            }
            else
            {
                numberOfResidents=0;
            }
            printf("%3d",numberOfResidents);
        }
        cout<<endl;
    }
}

void Village::simulateYear()
{
    for(unsigned int i=0;i<_mapSizeX;i++)
    {
        for(unsigned int j=0;j<_mapSizeY;j++)
        {
            householdMap[i][j]->simulateYear();
        }
    }
}

void Village::move(int x, int y)
{
    //householdMap[x][y]->
}




Village::Village(unsigned int mapSizeX, unsigned int mapSizeY) : _mapSizeX(mapSizeX), _mapSizeY(mapSizeY)
{
    householdMap = new Household**[_mapSizeX];
    for(unsigned int i=0;i<mapSizeX;i++)
    {
        householdMap[i] = new Household *[_mapSizeY];
        for(unsigned int j=0;j<mapSizeY;j++)
        {
            householdMap[i][j]=nullptr;
        }
    }
    _householdCounter=0;
}
