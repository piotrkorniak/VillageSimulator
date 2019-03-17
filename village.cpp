#include "village.h"
#include "simulationhelper.h"


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
            if(householdMap[i][j]!=nullptr)
            {
                householdMap[i][j]->simulateYear();
                simulateMigration(i,j);
            }
        }
    }
}

void Village::simulateMigration(unsigned int x, unsigned int y)
{
    Household* currentHousehold=householdMap[x][y];
    Villager *villagerWhichMoveOut=currentHousehold->findVillagerWhichMoveOut();
    if(!villagerWhichMoveOut)
    {
        return;
    }
    //-----------------------------------------------------------------
    for(unsigned int i=0;i<_mapSizeX;i++)
    {
        for(unsigned int j=0;j<_mapSizeY;j++)
        {
            Household* newHousehold=householdMap[i][j];
            if(newHousehold!=nullptr && newHousehold->getNumberOfResidents()==0)
            {
                newHousehold->addNewVillager(villagerWhichMoveOut);
                SimulationHelper::AddLog("Obiekt "+villagerWhichMoveOut->name() + "przeprowadza sie do pustego domostwa.");
                currentHousehold->deleteFromPreviousHousehold(villagerWhichMoveOut);
                return;
            }
        }
    }
    //------------------------------------------------------------------------------------
    for(unsigned int i=0;i<_mapSizeX;i++)
    {
        for(unsigned int j=0;j<_mapSizeY;j++)
        {
            Household* newHousehold=householdMap[i][j];
            if(newHousehold!=nullptr && newHousehold->isFreeSpace() && newHousehold->getNumberOfResidents()==1 &&
                    ((newHousehold->getVillagerArray()[0]->isMan() && !villagerWhichMoveOut->isMan()) ||
                     (!newHousehold->getVillagerArray()[0]->isMan() && villagerWhichMoveOut->isMan())))
            {
                newHousehold->addNewVillager(villagerWhichMoveOut);
                SimulationHelper::AddLog("Obiekt "+villagerWhichMoveOut->name() + "przeprowadza sie do samtonego obiektu.");
                currentHousehold->deleteFromPreviousHousehold(villagerWhichMoveOut);
                return;
            }

        }
    }


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
