#include "villager.h"
#include "simulationhelper.h"

Villager::Villager()
{
    _maxAge=rand()%101;
    _age=0;
    _isMan=rand()%2;
    if(_isMan)
    {
        _name=manName[rand()%6];
    }
    else
    {
        _name=womanName[rand()%6];
    }
    SimulationHelper::AddLog("Urodzila sie nowa osobe o imieniu "+_name);
}

Villager::Villager(string name, unsigned int age, unsigned int maxAge, bool isMan)
{
    this->_name=name;
    this->_age=age;
    this->_maxAge=maxAge;
    this->_isMan=isMan;
    SimulationHelper::AddLog("Dodano nowa osobe o imieniu "+_name);
}

Villager::~Villager()
{
    SimulationHelper::AddLog("Obiekt o imieniu "+_name+" umarl w wieku "+to_string(_age)+" lat.");
}

void Villager::incrementAge()
{
    _age++;
}

bool Villager::isAlive()
{
    return (_age<_maxAge);
}

unsigned int Villager::age() const
{
    return _age;
}

bool Villager::isMan() const
{
    return _isMan;
}
string Villager::name()
{
    return _name;
}
