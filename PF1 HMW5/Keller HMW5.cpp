/*
Ben Keller 
11/9/2022
Do not use with out permission
*/
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
const int numOptions = 7;
string Option1 = "1: Add random values between a range to a tip calendar";
string Option2 = "2: Edit the value of tips on a specific day in the calendar";
string Option3 = "3: Print all the tips from one of the 12 weeks";
string Option4 = "4: Print total tips over the quarter";
string Option5 = "5: Print every weeks tips and which week you earned the most";
string Option6 = "6: Print the average amount of tips earned each day of the week and then which day had highest average.";
string Option7;
int selection = 0;
const int day = 7; // days = 12 * 7 = 84 total
const int weeks = 12;
int week = 2;
int greatestValue = 0;
int greatestWeek = 0;
int greatestDayValue = 0;
int greatestDay = 0;
int highestTotal;
int Tipstore[weeks][day];

// --------------------------- End of Global Variables --------------------------------

void printStart(){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "      Choices                           " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "0: Exit program" << endl << endl << "-- Simple functions" << endl;
    for(int i = 0; i < numOptions; i++)
    {
    if(i == 1)
    {
        cout << Option1 << endl;
    }
    if(i == 2)
    {
        cout << Option2 << endl << endl;
    }
    if(i == 3)
    {
        cout << "-- Print out functions" << endl;
        cout << Option3 << endl;
    }
    if(i == 4)
    {
        cout << Option4 << endl << endl;
    }
    if(i == 5)
    {
        cout << "-- Math functions" << endl;
        cout << Option5 << endl;
    }
    if(i == 6)
    {
        cout << Option6 << endl;
    }
}
}
int choiceSelect(){
    int selection;
    cin >> selection;
    while(selection < 0 || selection > 6)
    {
        printStart();
        cout << endl << "Sorry that is not one of the choices." << endl;
        cin >> selection;
    }
    return selection;
}
int ranGen(int min, int max)
{
    int generated;
    int dif = max - min;
    dif = dif + 1;
    generated = rand() % dif;
    while(generated == generated - min){
    generated = rand() % dif;
    }
    generated = rand() % dif;
    generated = generated + min;
    return generated;
    
}
void randomInput(){
    int min, max;
    cout << "What is the lowest you could make in tips?" << endl;
    cin >> min;
    while(min <= 0)
    {
        cout << "The minimum should be a non zero positive number" << endl;
        cin >> min;
    }
    cout << "What is the most you could make in tips?" << endl;
    cin >> max;
    while(max <= min)
    {
        cout << "The max should be a number greater than the minimum which was " << min << endl;
        cin >> max;
    }
    for(int setWeekZero = 0; setWeekZero < weeks; setWeekZero++)
    {
        for(int setDayZero = 0; setDayZero < day; setDayZero++)
        {
            Tipstore[setWeekZero][setDayZero] = ranGen(min, max);
            //cout << setWeekZero << " " << setDayZero << " = " << Tipstore[setWeekZero][setDayZero] << endl; used this to test output of randomizer.
        }
        ranGen(min,max);
        
    }
   
}
void changeEntry(){
    cout << "What day do you want to edit the value? (0-6):";
    int daySelect, weekSelect, entry;
    cin >> daySelect;
    while(daySelect < 0 || daySelect > 6)
    {
        cout << endl << "Sorry that is not one of the days (0-6):";
        cin >> daySelect;
    }
    cout << "What week is the value you want to edit in? (0-11):";
    cin >> weekSelect;
    while(weekSelect < 0 || weekSelect > 11)
    {
        cout << endl << "Sorry that is not one of the weeks (0-11):";
        cin >> weekSelect;
    }
    cout << endl << "The current value of that entry is $" << Tipstore[weekSelect][daySelect] << " for the day" << endl << "What value would you like to change it too? ";
    cin >> entry;
    while(entry < 0)
    {
        cout << "The value must be greater than 0 please try again:";
        cin >> entry;
    }
    Tipstore[weekSelect][daySelect] = entry;
    cout << endl << "The new value of that entry is $" << Tipstore[weekSelect][daySelect] << endl;
    
}
void setup()
{ // weeks = 1 - 12 day = 1 - 7 value returned is tip
    for(int setWeekZero = 0; setWeekZero < weeks; setWeekZero++)
    {
        for(int setDayZero = 0; setDayZero < day; setDayZero++)
        {
            Tipstore[setWeekZero][setDayZero] = 0;
        }
        
    }
    ranGen(1,1);
}
int printWeek(int weekSelect){
   // int weekSelect, entry;
    
    cout << endl << "Tips for week " << weekSelect << endl << endl;
    for(int i = 0; i < (day - 1);i++){
        //cout << setw(10) << "$" + Tipstore[weekSelect][i] << "|";
        cout << " $" << Tipstore[weekSelect][i] << " |";
    }
    cout << " $" << Tipstore[weekSelect][6] << endl << endl;
    return 0;
}
void getWeekTips(){
    int weekSelect;
    cout << "What week do you want to return the tips for? (0-11):";
    cin >> weekSelect;
    while(weekSelect < 0 || weekSelect > 11)
    {
        cout << endl << "Sorry that is not one of the weeks (0-11):";
        cin >> weekSelect;
    }
    printWeek(weekSelect); 
}
void getAllTips(){
    for(int i = 0; i < weeks; i++){
        printWeek(i);
    }
}
void timetaker(){
    string nnull = "";
    cout << "Press enter to continue";
    //cin >> nnull;
    getline(cin, nnull);
    cin.ignore();
    cout << endl;
}
int weeklyTotal(int weeknum){
    int total = 0;
    for(int i = 0; i < day; i++){
    total = total + Tipstore[weeknum][i];
    }
    return total; 
}
int printWeekTotal(int weekdollars, int numweek){
    int greatestWk;
    if(numweek != -1){
    cout << "In week " << numweek << " you made $" << weekdollars << " from tips" << endl;
    }
    if(weekdollars > greatestValue){
        greatestValue = weekdollars;
        greatestWeek = numweek;
        //cout << "updated greatest " << endl;
    }
    greatestWk = greatestWeek;
    return greatestWk;
}
void num5()
{
    int week0,week1, week2, week3, week4, week5, week6, week7, week8, week9, week10, week11, greatestWeek;
    week0 = weeklyTotal(0);
    printWeekTotal(week0, 0);
    week1 = weeklyTotal(1);
    printWeekTotal(week1, 1);
    week2 = weeklyTotal(2);
    printWeekTotal(week2, 2);
    week3 = weeklyTotal(3);
    printWeekTotal(week3, 3);
    week4 = weeklyTotal(4);
    printWeekTotal(week4, 4);
    week5 = weeklyTotal(5);
    printWeekTotal(week5, 5);
    week6 = weeklyTotal(6);
    printWeekTotal(week6, 6);
    week7 = weeklyTotal(7);
    printWeekTotal(week7, 7);
    week8 = weeklyTotal(8);
    printWeekTotal(week8, 8);
    week9 = weeklyTotal(9);
    printWeekTotal(week9, 9);
    week10 = weeklyTotal(10);
    printWeekTotal(week10, 10);
    week11 = weeklyTotal(11);
    greatestWeek = printWeekTotal(week11, 11);
    cout << "You made the most money week " << greatestWeek << " with $" << weeklyTotal(greatestWeek) << " in tips" << endl << endl;
}
int bestDay(int profit, int daynumb){
    int greatestDy;
    if(profit > greatestDayValue){
        greatestDayValue = profit;
        greatestDay = daynumb;
    }
    greatestDy = greatestDay;
        return greatestDy;
}
int dailyTotal(int daychoice){
    int total = 0;
    for(int i = 0; i < weeks; i++){
    total = total + Tipstore[i][daychoice];
    bestDay(total,daychoice);
    }
    return total; 
}
int printBestDay(int bstday){
   
    highestTotal = dailyTotal(bstday);
    if(bstday == 0){
        cout << "Mondays averaged you the most money in tips with $" << highestTotal /12 << " in tips" << endl;
    }
    if(bstday == 1){
        cout << "Tuesdays averaged you the most money in tips with $" << highestTotal /12 << " in tips" << endl;
    }
    if(bstday == 2){
        cout << "Wednesdays averaged you the most money in tips with $" << highestTotal /12 << " in tips" << endl;
    }
    if(bstday == 3){
        cout << "Thursdays averaged you the most money in tips with $" << highestTotal /12 << " in tips" << endl;
    }
    if(bstday == 4){
        cout << "Fridays averaged you the most money in tips with $" << highestTotal /12 << " in tips" << endl;
    }
    if(bstday == 5){
        cout << "Saturdays averaged you the most money in tips with $" << highestTotal /12 << " in tips" << endl;
    }
    if(bstday == 6){
        cout << "Sundays averaged you the most money in tips with $" << highestTotal << " in tips" << endl;
    }
    return 0;
}
void num6(){
    int result;
    cout << "Daily averages" << endl;
    cout << "On Mondays you made an average of  $" << dailyTotal(0) / 12 << " in tips" << endl;
    cout << "On Tuesdays you made an average of  $" << dailyTotal(1) / 12 << " in tips" << endl;
    cout << "On Wednesdays you made an average of  $" << dailyTotal(2) / 12 << " in tips" << endl;
    cout << "On Thursdays you made an average of  $" << dailyTotal(3) / 12 << " in tips" << endl;
    cout << "On Fridays you made an average of  $" << dailyTotal(4) / 12 << " in tips" << endl;
    cout << "On Saturdays you made an average of  $" << dailyTotal(5) / 12 << " in tips" << endl;
    cout << "On Sundays you made an average of  $" << dailyTotal(6) /12 << " in tips" << endl;
    result = bestDay(0,0);
    cout << endl;
    printBestDay(result);
    
}
void resetNumbs(){
    //int greatestValue = -1;
    printWeekTotal(0, -1);
    /*
    greatestValue = 0;
    int greatestWeek = 0;
    int greatestDayValue = 0;
    int greatestDay = 0;
    int highestTotal = 0;
    */
}
int main()
{
    cout << "Welcome to the tip storage and calculator app!!" << endl << "You can use this app to help calculate many different ways you can get the maximum amount of tips per quarter(12 weeks)" << endl << "You will find the apps options below:" << endl << endl;
    srand(time(0));
    printStart();
    setup();
    int choice = choiceSelect();
    do
    {
    if(choice == 1){
    greatestDayValue = 0;
    greatestValue = 0;
    resetNumbs();
    randomInput();
    timetaker();
    //cout << greatestValue << " GV" << endl; checking that proper items are reset
    }
    if(choice == 2){
    greatestDayValue = 0;
    greatestValue = 0;
    changeEntry(); 
    timetaker();
    }
    if(choice == 3){
    getWeekTips();
    timetaker();
    }
    if(choice == 4){
    getAllTips();
    timetaker();
    }
    if(choice == 5){
    num5();
    timetaker();    
    }
    if(choice == 6){
    num6();
    timetaker();    
    }
    printStart();
    choice = choiceSelect();
    }
    while(choice != 0);
    cout << "Thank you for using the app" << endl;
    return 0;
}
