#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string womanName[6]={"Ala","Ada","Ania","Monika","Basia","Anastazja"};
string manName[6]={"Adam","Piotr","Stefan","Michal","Marcin","Bartek"};
int year;

class SimulationHelper
{
public:
    static void AddLog(string log)
    {
        cout<<"Rok: "<<year<<": "<<log<<endl;
    }
};

class Villager
{
    string _name;
    unsigned int _age;
    unsigned int _maxAge;
    bool _isMan;
public:
    Villager()
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

    Villager(string name, unsigned int age, unsigned int maxAge, bool isMan)
    {
        this->_name=name;
        this->_age=age;
        this->_maxAge=maxAge;
        this->_isMan=isMan;
        SimulationHelper::AddLog("Dodano nowa osobe o imieniu "+_name);
    }
    ~Villager()
    {
        SimulationHelper::AddLog("Obiekt o imieniu "+_name+" umarl w wieku "+to_string(_age)+" lat.");
    }
    void incrementAge()
    {
        _age++;
    }
    bool isAlive()
    {
        return (_age<_maxAge);
    }

    unsigned int age() const
    {
        return _age;
    }
    bool isMan() const
    {
        return _isMan;
    }
};

class Household
{
    const unsigned int villagerArraySize;
    Villager **villagerArray;
    unsigned int numberOfResidents;

public:
    Household(unsigned int arraySize) : villagerArraySize(arraySize)
    {
        villagerArray = new Villager*[villagerArraySize];
        numberOfResidents=0;
    }

    ~Household()
    {
        for(unsigned int i=0;i<numberOfResidents;++i)
        {
            delete villagerArray[i];
        }
        delete[] villagerArray;
    }

    bool createNewVillager()
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

    void deleteDeadVillager()
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

    void bornNewVillagers()
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
            else if(villagerArray[i]->age()<5)
            {
                isChildExistInHousehold=true;
            }
        }
        if(isProlificManExistInHousehold && isProlificWomanExistInHousehold && !isChildExistInHousehold)
        {
            createNewVillager();
        }
    }

    void incrementAgeOfEveryone()
    {
        for(unsigned int i=0;i<numberOfResidents;++i)
        {
            villagerArray[i]->incrementAge();
        }
    }

    void simulateYear()
    {
        incrementAgeOfEveryone();
        deleteDeadVillager();
        bornNewVillagers();
    }
    int getNumberOfResidents()
    {
        return numberOfResidents;
    }
};
//Klasa powinnna posiadać metodę postarzającą domostwa o jeden rok. Jeżeli dziecko musiało się wyprowadzić z
//domu, powinno poszukać możliwości zamieszkania w tej samej wiosce - poprzez dosiedlenie się do samotnej osoby
//przeciwnej płci lub poprzez założenie domostwa. W pierwszej kolejności należy poszukać istniejącego domostwa,
//następnie dosiedlenia się do innej osoby, w ostateczności należy założyć nowe domostwo. Przy zakładaniu
//swojego domostwa, w pierwszej kolejności należy sprawdzić najbliższe sąsiedztwo domu rodziców (8 pól), a
//jeżeli są zajęte, wybrać dowolne inne miejsce. Jeżeli nie ma miejsca do osiedlenia, osoba musi opuścić wioskę.
//Destruktor powinien wówczas wyświetlić informację o emigracji. Jeżeli nikt przez rok nie zasiedli domostwa,
//powinno ono zostać zniszczone.

class Village
{
    Household ***householdMap;
    const unsigned int _mapSizeX;
    const unsigned int _mapSizeY;
    unsigned int _householdCounter;
public:
    Village(unsigned int mapSizeX, unsigned int mapSizeY) : _mapSizeX(mapSizeX), _mapSizeY(mapSizeY)
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

    Household& getHousehold(int x, int y)
    {
        return *householdMap[x][y];
    }

    void createHousehold(unsigned int x, unsigned int y, unsigned int numberOfResidents)
    {
        householdMap[x][y] = new Household(numberOfResidents);
        _householdCounter++;
    }

    void printMap()
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

    void simulateYear()
    {
        for(unsigned int i=0;i<_mapSizeX;i++)
        {
            for(unsigned int j=0;j<_mapSizeY;j++)
            {
                householdMap[i][j]->simulateYear();
            }
        }
    }
};

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


