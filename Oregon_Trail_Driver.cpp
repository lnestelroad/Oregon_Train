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
/**
 * prints off the current items in the users shopping cart along with the bill for each item
 * and askes what the user would like to buy next
 */
    string choice = "";
    string amount = "";
    float numAmount;  //casted form of the amoun variable
    float bill = 0.0;  //sets the intial bill to $0.

    while (true)  //runs indefinatly or until q is chosen (contains a break command)
    {
        system("clear");

        cout << "\nCurrent Items:\n" << endl;

        cout << "1. Oxen           " << "$" << one.getMaterials("oxen").getCost() * one.getMaterials("oxen").getAmount() << endl;
        cout << "2. Food           " << "$" << one.getMaterials("food").getCost() * one.getMaterials("food").getAmount() << endl;
        cout << "3. Bullets        " << "$" << one.getMaterials("bullets").getCost() * one.getMaterials("bullets").getAmount() << endl;
        cout << "4. Spare Parts    " << "$" << (one.getMaterials("wheels").getCost() * one.getMaterials("wheels").getAmount())
                                      + (one.getMaterials("axles").getCost() * one.getMaterials("axles").getAmount())
                                      + (one.getMaterials("tongues").getCost() * one.getMaterials("tongues").getAmount())
                                      + (one.getMaterials(6).getCost() * one.getMaterials(6).getAmount()) << endl;

//*********************************************************************************************************//
/**
 * This block is used to calculate the total bill after each puchase
 */
        bill = ((one.getMaterials("oxen").getAmount() * 40.0) 
               +(one.getMaterials("food").getAmount() * 0.5)
               +(one.getMaterials("bullets").getAmount() * 2.0)
               +(one.getMaterials("wheels").getAmount() * 20.0)
               +(one.getMaterials("axles").getAmount() * 20.0)
               +(one.getMaterials("tongues").getAmount() * 20.0)
               +(one.getMaterials("medkits").getAmount() * 0.0));
        cout << "Your bill is: $" << bill << endl; 

        cout << "\nWhich item would you like to purchase?" << endl;
        cout << "Press 'q' to leave store." << endl;
        getline(cin, choice);
//*********************************************************************************************************//
/**
 * This block is the branch for if the user elects to buy oxen
 */
        if (choice == "1")
        {
            system("clear");

            cout << "There are 2 oxen in a yoke and each yoke will cost $" << one.getMaterials("oxen").getCost() << endl;
            cout << "Remember, you must spend $100-$200 on oxen." << endl;
            cout << "How many would you like to buy?" << endl;

            //Takes the amount the user wants and adds it the amount data member in the specified supply object
            //if there is enough money and the amount spent on oxen is between 100 and 200.                 
            
            numAmount = Amount();

            if (numAmount * 40 < one.getMoney() - bill && numAmount * 40 >= 100 && numAmount <= 200)
                one.setMaterialAmount(numAmount, "oxen");
            else if (numAmount * 40 > one.getMoney())
                cout << "Sorry sport, looks like you don't have enough!" << endl;
            else
            {
                cout << "Sorry champ, you must speen between $100 and $200 on oxen" << endl;
                clear();
            }
        }
//*********************************************************************************************************//
/**
 * This block is the branch for if the user elects to buy food
 */
        else if (choice == "2")
        {
            system("clear");

            cout << "It is recommended that you bring at least 200 lbs. of food per person." << endl;
            cout << "As of now, the price of food is " << one.getMaterials("food").getCost() << " cents per pound." << endl;
            cout << "How many pounds of food would you like to puchase?" << endl;                   
            
            numAmount = Amount();

            if (numAmount * 0.5 < one.getMoney() - bill)
                one.setMaterialAmount(numAmount, "food");
            else
                cout << "Sorry buckaroo, looks like you don't have enough!" << endl;
        }
//*********************************************************************************************************//  
/**
 * This block is the branch for if the user elects to buy bullets
 */
        else if (choice == "3")
        {
            system("clear");

            cout << "Ammunition is sold in boxes of 20 bullets. Each box costs $" << one.getMaterials("bullets").getCost() << endl;
            cout << "How many boxes do you want?" << endl;                  
            
            numAmount = Amount();

            if (numAmount * 2 < one.getMoney() - bill)
                one.setMaterialAmount(numAmount, "bullets");
            else
                cout << "Sorry slugger, looks like you don't have enough!" << endl;
        }
//*********************************************************************************************************// 
/**
 * This block is the branch for if the user elects to buy spare parts. The function will take the user into a 
 * new menu function like the supplies menu.
 */
        else if (choice == "4")
        {
            while(true)
            {
                system("clear");

                cout << "It's a food idea to have a few spare parts for your wagon. Here are the prices: " << endl;
                cout << "1. Wheels     " << "$" << one.getMaterials("wheels").getCost() << " each"  << endl;
                cout << "2. Axles      " << "$" << one.getMaterials("axles").getCost() << " each" << endl;
                cout << "3. Tongues    " << "$" << one.getMaterials("tongues").getCost() << " each" << endl;
                cout << "4. MedKits    " << "$" << one.getMaterials(6).getCost() << " each" << endl;

                cout << "\nWhich item would you like to purchase?" << endl;
                cout << "press 'q' to return to the store" << endl;
                getline(cin, choice);
            //---------------------------------------------------------------------------//
                if (choice == "1")
                {
                    cout << "How many wheels do you want?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * 20 < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, "wheels");
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
            //---------------------------------------------------------------------------//
                else if (choice == "2")
                {
                    cout << "How many axles would you like?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * 20 < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, "axles");
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
            //---------------------------------------------------------------------------//
                else if (choice == "3")
                {
                    cout << "How many tongues do you want?" << endl;
                                
                                
                                numAmount = Amount();

                    if (numAmount * 20 < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, "tongues");
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
            //---------------------------------------------------------------------------//
                else if (choice == "4")
                {
                    cout << "How many medKits do you want?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * 20 < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, "medkits");
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
                else
                    break;
            }
        }
//*********************************************************************************************************// 
/**
 * This block is the branch for if the user elects to leave the shop
 */      
        else if (choice == "q")
        {
            one.setMoney(1000.0 - bill);  //1000 because 200 was spent on the wagon itself.
            break;
        }
    }
    cout << one.getMoney() << endl;
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

    // while (one.getMiles() < 2048)  
    // {
        
    // }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////