#include "Animal.h"
#include <cstdlib>
using namespace std;


Animal::Animal()
{
   // cout << "constructor" << endl;
}

Animal::Animal(const Animal & copy)
{
this->id = copy.getID();
//cout << "ID:" << id << endl;
this->type = copy.getType();
//cout << "Type:" << type << endl;
this->weight = copy.getWeight();
//cout << "Weight:" << weight << endl;
this->age = copy.getAge();
//cout << "Age:" << age << endl;
this->price = copy.getPrice();
//cout << "Copy Animal" << endl;
}

Animal::Animal(int id, string type, float weight, int age, float price)
{
this->id = id;
this->type = type;
this->weight = weight;
this->age = age;
this->price = price;
/*
for(int i = 0; i < 100; i++){
    if (allTypes[i] == type){
        cout << type << " == " << allTypes[i] << endl;
        allTypes[id] = "";
        break;
        //cout << "already added " << type << endl;
        //i = id;
    }
    allTypes[id] = type;
}
//cout << "Animal 2" << endl;
if(id == 100){
    cout << "allTypes content:" << endl;
for(int j = 0; j <= 100; j++){
    cout << allTypes[j] << " ";
}
cout << endl;
}*/
}

Animal::~Animal()
{
  //  cout << "Animal destructor" << endl;
}

int Animal::getID() const
{
    return this->id;
}

float Animal::getWeight() const
{
    return this->weight;
}

int Animal::getAge() const
{
    return this->age;
}

float Animal::getPrice() const
{
    return this->price;
}

string Animal::getType() const
{
    return this->type;
}

void Animal::setID(int id)
{
this->id = id;
}

void Animal::setWeight(float weight)
{
this->weight = weight;
}

void Animal::setAge(int age)
{
this->age = age;
}

void Animal::setPrice(float price)
{
this->price = price;
}

void Animal::setType(string type)
{
this->type = type;
}

void Animal::printAnimal()
{
7cout << "ID: " << id << " Type: " << type << " Weight: " << weight << " Age: " << age << " Price: " << price << endl;
}
