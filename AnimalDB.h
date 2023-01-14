#ifndef ANIMALDB_H
#define ANIMALDB_H

#include <fstream>
#include <iostream>
#include "Animal.h"
using namespace std;
const int MAX_ARRAY = 100;

class AnimalDB
{
    public:
    AnimalDB();
    ~AnimalDB();
    //AnimalDB(const AnimalDB & copy);
    int getAnimalCartSize();
    int getCurrentAnimalSize();
    void insertDonnaAnimal(Animal newAnimal);
    void insertSelectedAnimal(Animal newAnimal);
    int getNumChoices();
    //void getUserAnimal(int id, string type, float weight, int age, float price);
    Animal getUserAnimal(const int i);
    void printAnimal();
    void printAllAnimals(AnimalDB animals);
    void bill();
    bool printAllAnimalsOfType( const string type);
    bool printAllAnimalsOfWeight( const float weightmin, const float weightmax);
    bool printAllAnimalsOfAge( const float agemin, const float agemax);
    float calculateTotal();

    private:
    float total = 0;
    int numAnimals = 0;
    int numCurrentAnimal = 0;
    Animal animals[MAX_ARRAY];
    Animal currentAnimal[MAX_ARRAY];
    bool exists;

};























#endif