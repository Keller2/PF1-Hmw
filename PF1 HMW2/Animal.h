#ifndef ANIMAL_H
#define ANIMAL_H

#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Animal
{
    public:
    Animal();
    Animal(int id, string type, float weight, int age, float price);
    Animal(const Animal & copy);
    ~Animal();
    int getID() const;
    float getWeight() const;
    int getAge() const;
    float getPrice() const;
    string getType() const;
    void setID(int id);
    void setWeight(float weight);
    void setAge(int age);
    void setPrice(float price);
    void setType(string type);
    void printAnimal();

    private:
    int id;
    string type;
    string allTypes[100];
    int allAges[100];
    float allWeights[100];
    float weight;
    int age;
    float price;
    
};









#endif
