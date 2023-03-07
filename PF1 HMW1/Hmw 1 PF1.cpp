/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <time.h> // used for sleep function
#include <unistd.h> //used for sleep function

using namespace std;
int main()
{
    int numPeople;
cout << " ------------ How many people frequent the arcade? -----------" << endl;
cout << "                        # between 1 - 5                       " << endl;
cout << "                                ";
cin >> numPeople;
cout << endl;

if (numPeople < 1)
{ 
    numPeople = 1;
    cout << "Invalid entry number set to 1" << endl;
    
}
if (numPeople > 5)
{
    numPeople = 5;
    cout << "Number input was greater than 5 so number was set to the max 5" << endl;
}
// qtr and cost of game ints 
int lucasqtr = 0;
int dustinqtr = 0;
int mikeqtr = 0;
int maxqtr = 0;
int bobqtr = 0;
int tracker = 0;
int lucasgm = 0;
int dustingm = 0;
int mikegm = 0;
int maxgm = 0;
int bobgm = 0;

// math ints 
int lucasNumGame = 0;
int dustinNumGame = 0;
int mikeNumGame = 0;
int maxNumGame = 0;
int bobNumGame = 0;
int lucaslftover = 0;
int dustinlftover = 0;
int mikegmlftover = 0;
int maxgmlftover = 0;
int boblftover = 0;
// ints for print statements

int numPrint = 0;

//
cout << endl;
cout << endl;
cout << endl;
if (numPeople == 5)
{
//cout << "                                ";
cout << "How many quarters did Lucas bring? ";
cin >> lucasqtr;
cout << endl;
cout << "How many quarters does Lucas's favorite game cost? ";
cin >> lucasgm;
cout << endl;
cout << "How many quarters did Dustin bring? ";
cin >> dustinqtr;
cout << endl;
cout << "How many quarters does Dustin's favorite game cost? ";
cin >> dustingm;
cout << endl;
cout << "How many quarters did Mike bring? ";
cin >> mikeqtr;
cout << endl;
cout << "How many quarters does Mike's favorite game cost? ";
cin >> mikegm;
cout << endl;
cout << "How many quarters did Max bring? ";
cin >> maxqtr;
cout << endl;
cout << "How many quarters does Max's favorite game cost? ";
cin >> maxgm;
cout << endl;
cout << "How many quarters did Bob bring? ";
cin >> bobqtr;
cout << endl;
cout << "How many quarters does Bob's favorite game cost? ";
cin >> bobgm;
cout << endl;
}
if (numPeople == 4)
{
//cout << "                                ";
cout << "How many quarters did Lucas bring? ";
cin >> lucasqtr;
cout << endl;
cout << "How many quarters does Lucas's favorite game cost? ";
cin >> lucasgm;
cout << endl;
cout << "How many quarters did Dustin bring? ";
cin >> dustinqtr;
cout << endl;
cout << "How many quarters does Dustin's favorite game cost? ";
cin >> dustingm;
cout << endl;
cout << "How many quarters did Mike bring? ";
cin >> mikeqtr;
cout << endl;
cout << "How many quarters does Mike's favorite game cost? ";
cin >> mikegm;
cout << endl;
cout << "How many quarters did Max bring? ";
cin >> maxqtr;
cout << endl;
cout << "How many quarters does Max's favorite game cost? ";
cin >> maxgm;
cout << endl;

}
if (numPeople == 3)
{
//cout << "                                ";
cout << "How many quarters did Lucas bring? ";
cin >> lucasqtr;
cout << endl;
cout << "How many quarters does Lucas's favorite game cost? ";
cin >> lucasgm;
cout << endl;
cout << "How many quarters did Dustin bring? ";
cin >> dustinqtr;
cout << endl;
cout << "How many quarters does Dustin's favorite game cost? ";
cin >> dustingm;
cout << endl;
cout << "How many quarters did Mike bring? ";
cin >> mikeqtr;
cout << endl;
cout << "How many quarters does Mike's favorite game cost? ";
cin >> mikegm;
cout << endl;

}
if (numPeople == 2)
{
//cout << "                                ";
cout << "How many quarters did Lucas bring? ";
cin >> lucasqtr;
cout << endl;
cout << "How many quarters does Lucas's favorite game cost? ";
cin >> lucasgm;
cout << endl;
cout << "How many quarters did Dustin bring? ";
cin >> dustinqtr;
cout << endl;
cout << "How many quarters does Dustin's favorite game cost? ";
cin >> dustingm;
cout << endl;


}

if (numPeople == 1)
{
//cout << "                                ";
cout << "How many quarters did Lucas bring? ";
cin >> lucasqtr;
//cout << lucasqtr << endl;
cout << endl;
cout << "How many quarters does Lucas's favorite game cost? ";
cin >> lucasgm;
cout << endl;
cout << endl;
//cout << lucasqtr / lucasgm << endl;

}

cout << " ------------------------- Calculating -----------------------" << endl;
cout << endl;
cout << endl;
/*
                This section is used to do the math while making the program look better
*/
if (lucasqtr && lucasgm > 0){
lucasNumGame = lucasqtr / lucasgm;
lucaslftover = lucasqtr % lucasgm;
}
//cout << lucasNumGame << endl;
//cout << lucaslftover << endl;
if (dustinqtr && dustingm > 0){
dustinNumGame = dustinqtr / dustingm;
dustinlftover = dustinqtr % dustingm;
}
if (maxqtr && maxgm > 0){
maxNumGame = maxqtr / maxgm;
maxgmlftover = maxqtr % maxgm;
}
if (mikeqtr && mikegm > 0){
mikeNumGame = mikeqtr / mikegm;
mikegmlftover = mikeqtr % mikegm;
}
if (bobqtr && mikegm > 0){
bobNumGame = bobqtr / bobgm;
boblftover = bobqtr % bobgm;
}
sleep(2);
cout << endl;
cout << "                               50%                            " << endl;
sleep(2);
cout << endl;
cout << "                              100%                            " << endl;
sleep(2);
cout << endl;
cout << "                            Complete                          " << endl;
cout << endl;
cout << "Lucas will be able to play " << lucasNumGame << " games that each cost " << lucasgm << " quarter(s), and will have " << lucaslftover << " quarters remaining." << endl;
if (numPeople > 1){
cout << "Dustin will be able to play " << dustinNumGame << " games that each cost " << dustingm << " quarter(s), and will have " << dustinlftover << " quarters remaining." << endl;
}
if (numPeople > 2){
cout << "Mike will be able to play " << mikeNumGame << " games that each cost " << mikegm << " quarter(s), and will have " << mikegmlftover << " quarters remaining." << endl;
}
if (numPeople > 3){
cout << "Max will be able to play " << maxNumGame << " games that each cost " << maxgm << " quarter(s), and will have " << maxgmlftover << " quarters remaining." << endl;
}
if (numPeople > 4){
cout << "Bob will be able to play " << bobNumGame << " games that each cost " << bobgm << " quarter(s), and will have " << boblftover << " quarters remaining." << endl;
}
cout << endl;
cout << " ------------------------- Calculating -----------------------" << endl;
cout << " -------------------------    Profit   -----------------------" << endl;
sleep(2);
cout << endl;
cout << "                               50%                            " << endl;
sleep(2);
cout << endl;
cout << "                              100%                            " << endl;
sleep(2);
cout << endl;
cout << "                            Complete                          " << endl;
cout << endl;
cout << endl;
double nightlyProfit;
nightlyProfit = ((lucasNumGame * lucasgm) + (dustinNumGame * dustingm) + (mikeNumGame * mikegm) + (maxNumGame * maxgm) + (bobNumGame * bobgm)); 
int numqtr;
numqtr = nightlyProfit;
nightlyProfit = (nightlyProfit * 0.25);
double weekProfit = 0;
weekProfit = (nightlyProfit * 6);
double monthlyProfit = 0;
monthlyProfit = (weekProfit * 4);
double yearlyProfit;
yearlyProfit = (weekProfit * 52);
// nightlyProfit = numgames * cost of those games * 25 
cout << fixed << setprecision(2) << "The Palace would make $" << nightlyProfit << " in one night with the given inputs. Resulting in " << numqtr << " quarter(s) spent." << endl;
cout << fixed << setprecision(2) << "The Palace would make $" << weekProfit << " in one week with the given inputs." << endl;
cout << fixed << setprecision(2) << "The Palace would make $" << monthlyProfit << " in one month with the given inputs." << endl;
cout << fixed << setprecision(2) << "The Palace would make $" << yearlyProfit << " in one year with the given inputs." << endl;
return 0;

}
