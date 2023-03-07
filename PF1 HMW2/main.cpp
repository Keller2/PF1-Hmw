#include "Animal.h"
#include "AnimalDB.h"
#include <iostream>
using namespace std;


void readFile(const string filename, AnimalDB &animals) {
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // declare local temp. class variables for reading data
    int id = 1;
    string type;
    float weight;
    int age;
    float price;
    string extra;
    char dollar;

    while (!din.eof()) {
        // logic for reading in data, ignoring unwanted data
        din >> type >> weight;
        getline(din, extra);
        din >> age;
        getline(din, extra);
        din.get(dollar);
        din >> price;
        getline(din, extra);

        // define new Animal object and insert new animal into Donna's inventory
        Animal newAnimal(id++, type, weight, age, price);
        //cout << id << " " << type << " " << weight << " " << age << " " <<  price << endl;
        if (!din.eof())
            animals.insertDonnaAnimal(newAnimal);
    }
    din.close();
    cout << "readfile" << endl;
}

void writeFile(const string filename, AnimalDB & animals) {
    // open file for output, check if failed
    ofstream dout;
    dout.open(filename.c_str());

    if (dout.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }
    // loop for each index in the userCart array, write data of each Animal object to output file in CSV formats
    for (int i = 0; i < animals.getNumChoices(); i++) {
        //cout << animals.getNumChoices() << " Num Choices" << endl;
        Animal currentAnimal = animals.getUserAnimal(i);
        dout << currentAnimal.getID() << ','
        << currentAnimal.getType() << ','
        << currentAnimal.getWeight() << ','
        << currentAnimal.getAge() << ','
        << currentAnimal.getPrice() << ',' << endl;
    }
    //dout << ",,,," << animals.getCurrentTotal();
    dout.close();
}

void printMenu() {
    cout << "\nWelcome to Donna's Farm! Here are your choices:"
    << "\n1: Print all animals in Donna's inventory"
    << "\n2: Print your current shopping cart"
    << "\n3: Print animals of a certain type"
    << "\n4: Print animals within a range of weight"
    << "\n5: Print animals within a range of age"
    << "\n6: Add an animal to your shopping cart"
    << "\n7: Print your current shopping cart total"
    << "\n8: Complete your order, print receipt and exit the program\n";
}

char getUserChoice(char min, char max) {
    char userChoice = '\0';

    do {
        cout << "\nEnter selection: ";
        cin >> userChoice;
        if (userChoice < min || userChoice > max)
            cout << "\nError: invalid input. Please try again." << endl;
    } while (userChoice < min || userChoice > max);

    return userChoice;
} 
int main() {
    string type;
    int ID;
    float weightmin, weightmax, agemin, agemax, price;
    bool isfound = false;
    AnimalDB animals;
    Animal choice;
    readFile("donnaInventory.txt", animals);
    printMenu();
    char selectedChoice = 0;
    /*if(choice == '1'){
    for(int i = 0; i < animals.getNumChoices(); i++)
        {
            Animal allAnimals = animals.getUserAnimal(i);
            allAnimals.printAnimal();
        }
    }
    */
    do{
    selectedChoice = getUserChoice('1','8');   
    switch(selectedChoice){
        case '1':
        {
            animals.printAllAnimals(animals);
            break;
        }
        case '2':
        {
            animals.bill();
            //cout << "shopping cart is ..." << endl;
        
        break;
        }
        case '3':
        {
            
            cout << "What type of animal are you looking for? ";
            cin >> type;
            isfound = animals.printAllAnimalsOfType(type);
            if(isfound == false){
                cout << "Sorry there are no animals matching that type in our data base." << endl;
            }
            isfound == false;
        
        break;
        }
        case '4':
            cout << "What weight range is the animal you are looking for? " << endl;
            cout << "minimum weight:";
            cin >> weightmin;
            cout << "maximum weight:";
            cin >> weightmax;
            isfound = animals.printAllAnimalsOfWeight(weightmin, weightmax);
            if(isfound == false){
                cout << "Sorry there are no animals matching that weight range in our data base." << endl;
            }
            isfound == false;
        break;
        case '5':
            cout << "What age range is the animal you are looking for? " << endl;
            cout << "minimum age:";
            cin >> agemin;
            cout << "maximum age:";
            cin >> agemax;
            isfound = animals.printAllAnimalsOfAge(agemin, agemax);
            if(isfound == false){
                cout << "Sorry there are no animals matching that age range in our data base." << endl;
            }
            isfound == false;
        break;
        case '6':
            cout << "What animal do you want to add to cart 1-100: ";
            //ID = getUserChoice('1','100');
            cin >> ID;
            ID = ID - 1;
            choice = animals.getUserAnimal(ID);
            cout << "you selected: " << ID + 1;
            animals.insertSelectedAnimal(choice);
        break;
        case '7':
            cout << "shopping cart costs ..." << endl;
            int total;
            total = animals.calculateTotal();
            cout << "$"  << total << endl;
        break;
        case ' ':
        printMenu();
        break;
}
    }
    while(selectedChoice != '8');

    Animal newAnimal = animals.bill();
    writeFile("donnaPurchaseOut.csv", newAnimal);

    //you will be writing this code!
    cout << endl;

    return 0;
}






   /*for(int i = 0; i < animals.getNumChoices(); i++)
        {
            Animal allAnimals = animals.getUserAnimal(i);
            allAnimals.printAnimal();
        }
        */
