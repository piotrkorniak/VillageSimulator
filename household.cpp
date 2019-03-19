#include "household.h"

Household::Household(unsigned int arraySize) : villagerArraySize(arraySize)
{
    villagerArray = new Villager*[villagerArraySize];
    numberOfResidents=0;
}

Household::~Household()
{
    for(unsigned int i=0;i<numberOfResidents;++i)
    {
        delete villagerArray[i];
    }
    delete[] villagerArray;
}

bool Household::createNewVillager()
{
    if(numberOfResidents<villagerArraySize)
    {
        Villager* villager=new Villager();
        villagerArray[numberOfResidents]=villager;
        numberOfResidents++;
        return true;
    }
    return false;
}

void Household::deleteDeadVillager()
{
    for(int i=numberOfResidents-1;i>=0;--i)
    {
        if(!villagerArray[i]->isAlive())
        {
            delete villagerArray[i];
            villagerArray[i]=villagerArray[numberOfResidents-1];
            numberOfResidents--;
        }
    }
}

void Household::bornNewVillagers()
{
    bool isProlificManExistInHousehold=false, isProlificWomanExistInHousehold=false, isChildExistInHousehold=false;
    for(unsigned int i=0;i<numberOfResidents;++i)
    {
        if(!isProlificManExistInHousehold && villagerArray[i]->isMan() && villagerArray[i]->age() > 18 && villagerArray[i]->age() < 45)
        {
            isProlificManExistInHousehold=true;
        }
        else if(!isProlificWomanExistInHousehold && !villagerArray[i]->isMan() && villagerArray[i]->age() > 18 && villagerArray[i]->age() < 45)
        {
            isProlificWomanExistInHousehold=true;
        }
        else if(villagerArray[i]->age()<4)
        {
            isChildExistInHousehold=true;
        }
    }
    if(isProlificManExistInHousehold && isProlificWomanExistInHousehold && !isChildExistInHousehold)
    {
        createNewVillager();
    }
}

void Household::incrementAgeOfEveryone()
{
    for(unsigned int i=0;i<numberOfResidents;++i)
    {
        villagerArray[i]->incrementAge();
    }
}

void Household::simulateYear()
{
    incrementAgeOfEveryone();
    deleteDeadVillager();
    bornNewVillagers();
}

unsigned int Household::getNumberOfResidents()
{
    return numberOfResidents;
}

void Household::addNewVillager(Villager* newVillager)
{
    villagerArray[numberOfResidents]=newVillager;
    numberOfResidents++;
}

Villager *Household::findVillagerWhichMoveOut()
{
    if(numberOfResidents==1)
    {
        return nullptr;
    }
    for(unsigned int i=0;i<numberOfResidents;++i)
    {
        if(villagerArray[i]->age()==20)
        {
            return villagerArray[i];
        }
    }
    return nullptr;
}

Villager** Household::getVillagerArray()
{
    return villagerArray;
}

bool Household::isFreeSpace()
{
    return numberOfResidents<villagerArraySize;
}

void Household::deleteFromPreviousHousehold(Villager *deleteVillager)
{
    for(int i=numberOfResidents-1;i>=0;--i)
    {
        if(villagerArray[i]==deleteVillager)
        {
            villagerArray[i]=villagerArray[numberOfResidents-1];
            numberOfResidents--;
        }
    }
}
