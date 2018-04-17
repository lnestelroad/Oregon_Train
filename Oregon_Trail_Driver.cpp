/*
CSCI 1300 spring
Author: Liam Nestelroad
Assignment: Homework 8; Oregon Trail Driver
Rectitaion: 103 - Arcaida Zhang
Cloun9 Workspace Editor Link: https://ide.c9.io/line4246/csci1300_amish
*/

#include <iostream>
#include <string> 
#include <fstream>
#include "Wagon.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This is an auxilary fucntion which when called upon will clear the terminal screen.
 */
void clear()
{
    string enter = "";
    cout << "\nPress enter to continue" << endl;

    getline(cin, enter);  //takes in the users enter from the terminal
    if (enter.length() == 0)  //makes sure the users input was an enter
    {
        system("clear");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void shop(Wagon one)
{
//*********************************************************************************************************//
/**
 * Prints out what the user will need and the use of each object from a seperate file.
 */
    
    ifstream storeScript;
    storeScript.open("store.txt");
    string line = "";

    system("clear");
    while (getline(storeScript, line))
    {
        cout << line << endl;
    }
    storeScript.close();
    clear();
//*********************************************************************************************************//
    string choice = "";
    string amount = "";
    float numAmount;

    while (true)
    {
        cout << "\nCurrent Items:\n" << endl;

        cout << "1. Oxen           " << "$" << one.getMaterials("oxen").getCost() * one.getMaterials("oxen").getAmount() << endl;
        cout << "2. Food           " << "$" << one.getMaterials("food").getCost() * one.getMaterials("food").getAmount() << endl;
        cout << "3. Bullets        " << "$" << one.getMaterials("bullets").getCost() * one.getMaterials("bullets").getAmount() << endl;
        cout << "4. Spare Parts    " << "$" << (one.getMaterials("wheels").getCost() * one.getMaterials("wheels").getAmount()) 
                                      + (one.getMaterials("axles").getCost() * one.getMaterials("axles").getAmount())
                                      + (one.getMaterials("tongues").getCost() * one.getMaterials("tongues").getAmount())
                                      + (one.getMaterials("medkits").getCost() * one.getMaterials("medkits").getAmount()) << endl;
        cout << "which item would you like to purchase?" << endl;
        cout << "Press 'q' to leave store." << endl;
        getline(cin, choice);

        if (choice == "1")
        {
            system("clear");

            cout << "There are 2 oxen in a yoke and each yoke will cost $40." << endl;
            cout << "Remember, you must spend $100-$200 on oxen." << endl;
            cout << "How many would you like to buy?" << endl;

            //Takes the amount the user wants and adds it the amount data member in the specified supply object
            //if there is enough money and the amount spent on oxen is between 100 and 200.
            getline(cin, amount);
            numAmount = stof(amount);
            if (numAmount * 40 < one.getMoney() && numAmount * 40 >= 100 && numAmount <= 200)
            {
                one.setMaterialAmount(numAmount, "oxen");
                // int currentMoney = one.getMoney();
                // one.setMoney(currentMoney - (numAmount * 40));
            }
            else if (numAmount * 40 > one.getMoney())
                cout << "Sorry sport, looks like you don't have enough!" << endl;
            else
                cout << "Sorry champ, you must speen between $100 and $200 on oxen" << endl;
        }
        else if (choice == "q")
        {
            // one.setMoney(1200 - bill);
            break;
        }
        float bill = ((one.getMaterials("oxen").getAmount() * 40));
        cout << "Your bill is: " << bill << endl; 
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Misfortune()
{ 
    //this function will simulate the misfortune chance and the puzzles.
    //a 40 percent change for a missfortune will occure every round
    //one miss fortune will be chosen at randome the player.

    //depending on the mis fortune, a specific consquence will happen.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void raiders()
{
    //function that will similate a raider attack and the options the user can do,

    //raiders eill be given a specifioc chance to invade.

    //if an invasion occurs, the user will be given options on how to proceed.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu()
{
    //here is where each turn will be simulatied.
    //the user will be given every option through thise function.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    string enter = "";
//*********************************************************************************************************//
/**
 * This section of the Driver file will welcom the user to the game and
 *  have the user enter all of the information for the wagon constructor
 */

    cout << "Welcome to The Oregon Trail!" << endl;
    Wagon one = Wagon();
//*********************************************************************************************************//
/**
 * Here the game will tell the user about the shop and initiate the shop simulation function.
 */
    system("clear");

    cout << "Before leaving Independence, you should consider buying supplies." << endl;
    cout << "After buying your wagon, you have $1000 left to spend in the shop." << endl;
    cout << "All of the neccessary materials can be found there, but you do not need to spend all of your money now." << endl;
    cout << "\nPress enter to continue" << endl;

    getline(cin, enter);  //takes in the users enter from the terminal
    if (enter.length() == 0)  //makes sure the users input was an enter
    {
        shop(one);  //the function takes the play into the shop function.
    }
//*********************************************************************************************************//



    // shop();
    // while (miles < 2048)  
    // {
        
    // }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////