#include "AnimalDB.h"
#include "Animal.h"
using namespace std;

AnimalDB::AnimalDB()
{
  //  cout << "Animal constructor" << endl;
}

/*AnimalDB::AnimalDB(const AnimalDB & copy)
{
this->firstName = copy.getFirstName();
this->lastName = copy.getLastName();
this->PIN = copy.getPIN();
this->accountNumber = copy.getAccountNumber();
*/



AnimalDB::~AnimalDB()
{
 //   cout << "Animal destructor" << endl;
}

int AnimalDB::getAnimalCartSize()
{
 return numCurrentAnimal;
}

int AnimalDB::getCurrentAnimalSize()
{
 return numCurrentAnimal;
}

void AnimalDB::insertDonnaAnimal(Animal newAnimal)
{
    if(numAnimals>=MAX_ARRAY)
    {
        return;
    }
    animals[numAnimals] = newAnimal;
    numAnimals++;

}
void AnimalDB::insertSelectedAnimal(Animal newAnimal)
{
       if(numCurrentAnimal>=MAX_ARRAY)
    {
        return;
    }
    currentAnimal[numCurrentAnimal] = newAnimal;
    numCurrentAnimal++;

}

int AnimalDB::getNumChoices()
{
    return numAnimals;
}
/*
void AnimalDB::getUserAnimal(int id, string type, float weight, int age, float price)
{
    id = id;
    type = type;
    weight = weight;
    age = age;
    price = price;
}
*/
Animal AnimalDB::getUserAnimal(const int i)
{
    //for(int i = 0; i < );
    //return Animal(id);
    return animals[i];
}

void AnimalDB::printAnimal()
{
cout << "ID: " << animals->getAge() << " Type: " << animals->getType() << " Weight: " << animals->getWeight() << " Age: " << animals->getAge() << " Price: " << animals->getPrice() << endl;
}

void AnimalDB::printAllAnimals(AnimalDB animals)
{
    //AnimalDB animals;
    for(int i = 0; i < animals.getNumChoices(); i++)
        {
            Animal allAnimals = animals.getUserAnimal(i);
            allAnimals.printAnimal();
        }
}

bool AnimalDB::printAllAnimalsOfType(const string type)
{
   // cout << "In Printalltype" << endl;
    exists = false;
    for(int p = 0; p < 100; p++)
        {
            
            
            if(animals[p].getType() == type){
            animals[p].printAnimal();
            exists = true;
            }
            
        }
        /*
        if(exists == false){
                            cout << "Sorry there are no animals matching that type in our data base." << endl;
        }*/
        return exists;
}

bool AnimalDB::printAllAnimalsOfWeight( const float weightmin, const float weightmax)
{
    if(weightmin > weightmax){
        cout << "Sorry your minimum cannot be larger than your maximum" << endl;
        return true;
    }
    exists = false;
    for(int p = 0; p < 100; p++)
        {
            
            
            if((animals[p].getWeight() >= weightmin) && (animals[p].getWeight() <= weightmax)){
            animals[p].printAnimal();
            exists = true;
            }
            
        }
        /*
        if(exists == false){
                            cout << "Sorry there are no animals matching that type in our data base." << endl;
        }*/
        return exists;
}

bool AnimalDB::printAllAnimalsOfAge( const float agemin, const float agemax)
{
    if(agemin > agemax){
        cout << "Sorry your minimum cannot be larger than your maximum" << endl;
        return true;
    }
    if(agemin != agemin){
        cout << "Sorry your thats not a number" << endl;
        return true;
    }
     if(agemax != agemax){
        cout << "Sorry your thats not a number" << endl;
        return true;
    }
    exists = false;
    for(int p = 0; p < 100; p++)
        {
            
            
            if((animals[p].getAge() >= agemin) && (animals[p].getAge() <= agemax)){
            animals[p].printAnimal();
            exists = true;
            }
            
        }
        /*
        if(exists == false){
                            cout << "Sorry there are no animals matching that type in our data base." << endl;
        }*/
        return exists;
}

float AnimalDB::calculateTotal()
{
    cout << "you have # items: " << numCurrentAnimal << endl;
if(numCurrentAnimal = 0){
    return 0;
}
cout << "Getting total" << endl;
    for(int i = 0; i <= numCurrentAnimal; i++)
    {
        //cout << "price " <<currentAnimal[i].getPrice() << endl;
        total = total + currentAnimal[i].getPrice();
    }
    return total;

}

 void AnimalDB::bill()
      {
        cout << "in bill" << endl;
        for(int p=0; p < numCurrentAnimal;p++)
        {
            
            
           currentAnimal[p].printAnimal();
        }
      }
