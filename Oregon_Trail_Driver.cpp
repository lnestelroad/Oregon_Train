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
#include <ctime>
#include "Wagon.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * After each stage/turn, any changes to the user data will be saved to a file so that it can be transfered to the next stage/turn.
 */ 
void saveData(Wagon one)
{
    ofstream save;
    save.open("ProgressUpdate.txt");

    if (save.is_open())
    {   
        //--------------------------------------------------------------//
        for (int i = 0; i < 7; i++)
        {
            save << one.getMaterials(i).getAmount() << ' ';
            save << one.getMaterials(i).getCost() << endl;
        }
        //--------------------------------------------------------------//
        for (int i = 0; i < 5; i++)
        {
            save << one.getPersons(i).getAlive() << ' ';
            save << one.getPersons(i).getSickDays() << endl;
        }
        //--------------------------------------------------------------//
            save << one.getTime().getMonth() << ' ';
            save << one.getTime().getDay() << ' ';
            save << one.getTime().getYear() << endl;
        //--------------------------------------------------------------//
            save << one.getMoney() << endl;
            save << one.getMiles() << endl;
        //--------------------------------------------------------------//    
    }
    else
    {
        cout << "Failed to save." << endl;
    }

    save.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadData(Wagon one)
{
    ifstream load;
    load.open("ProgressUpdate.txt");
    string line = "";
    string temp[5];
    int counter = 0;

    if (load.is_open())
    {
        while(getline(load, line))
        {
            Split(line, ' ', temp, 5);

            if (counter > 7)
            {   
                int amount = stof(temp[0]);
                one.setMaterialAmount(amount, counter);
            }

            counter++;
        }
    }
    else 
        cout << "failed to open" << endl;
    
    load.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon shop(Wagon one)
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

        cout << "1. Oxen           " << "$" << one.getMaterials(0).getCost() * one.getMaterials(0).getAmount() << endl;
        cout << "2. Food           " << "$" << one.getMaterials(1).getCost() * one.getMaterials(1).getAmount() << endl;
        cout << "3. Bullets        " << "$" << one.getMaterials(2).getCost() * one.getMaterials(2).getAmount() << endl;
        cout << "4. Spare Parts    " << "$" << (one.getMaterials(3).getCost() * one.getMaterials(3).getAmount())
                                      + (one.getMaterials(4).getCost() * one.getMaterials(4).getAmount())
                                      + (one.getMaterials(5).getCost() * one.getMaterials(5).getAmount())
                                      + (one.getMaterials(6).getCost() * one.getMaterials(6).getAmount()) << endl;

    //*********************************************************************************************************//
    /**
     * This block is used to calculate the total bill after each puchase
     */
        bill = ((one.getMaterials(0).getAmount() * one.getMaterials(0).getCost()) 
               +(one.getMaterials(1).getAmount() * one.getMaterials(1).getCost())
               +(one.getMaterials(2).getAmount() * one.getMaterials(2).getCost())
               +(one.getMaterials(3).getAmount() * one.getMaterials(3).getCost())
               +(one.getMaterials(4).getAmount() * one.getMaterials(4).getCost())
               +(one.getMaterials(5).getAmount() * one.getMaterials(5).getCost())
               +(one.getMaterials(6).getAmount() * one.getMaterials(6).getCost()));
        cout << "\nYour bill is: $" << bill << endl; 

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

            cout << "There are 2 oxen in a yoke and each yoke will cost $" << one.getMaterials(0).getCost() << endl;
            cout << "Remember, you must spend $100-$200 on oxen." << endl;
            cout << "How many would you like to buy?" << endl;

            //Takes the amount the user wants and adds it the amount data member in the specified supply object
            //if there is enough money and the amount spent on oxen is between 100 and 200.                 
            
            numAmount = Amount();

            if (numAmount * one.getMaterials(0).getCost() < one.getMoney() - bill && numAmount * one.getMaterials(0).getCost() >= 100 && numAmount * one.getMaterials(0).getCost() <= 200)
                one.setMaterialAmount(numAmount, 0);
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
            cout << "As of now, the price of food is " << one.getMaterials(1).getCost() << " cents per pound." << endl;
            cout << "How many pounds of food would you like to puchase?" << endl;                   
            
            numAmount = Amount();

            if (numAmount * one.getMaterials(1).getCost() < one.getMoney() - bill)
                one.setMaterialAmount(numAmount, 1);
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

            cout << "Ammunition is sold in boxes of 20 bullets. Each box costs $" << one.getMaterials(2).getCost() << endl;
            cout << "How many boxes do you want?" << endl;                  
            
            numAmount = Amount();

            if (numAmount * one.getMaterials(2).getCost() < one.getMoney() - bill)
                one.setMaterialAmount(numAmount, 2);
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
                cout << "1. Wheels     " << "$" << one.getMaterials(3).getAmount() * one.getMaterials(3).getCost() << endl;
                cout << "2. Axles      " << "$" << one.getMaterials(4).getAmount() * one.getMaterials(4).getCost() << endl;
                cout << "3. Tongues    " << "$" << one.getMaterials(5).getAmount() * one.getMaterials(5).getCost() << endl;
                cout << "4. MedKits    " << "$" << one.getMaterials(6).getAmount() * one.getMaterials(6).getCost() << endl;

                cout << "\nWhich item would you like to purchase?" << endl;
                cout << "press 'q' to return to the store" << endl;
                getline(cin, choice);
            //---------------------------------------------------------------------------//
                if (choice == "1")
                {
                    cout << "How many wheels do you want?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(3).getCost() < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, 3);
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
            //---------------------------------------------------------------------------//
                else if (choice == "2")
                {
                    cout << "How many axles would you like?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(4).getCost() < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, 4);
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
            //---------------------------------------------------------------------------//
                else if (choice == "3")
                {
                    cout << "How many tongues do you want?" << endl;
                                
                                
                                numAmount = Amount();

                    if (numAmount * one.getMaterials(5).getCost() < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, 5);
                    else
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                }
            //---------------------------------------------------------------------------//
                else if (choice == "4")
                {
                    cout << "How many medKits do you want?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(6).getCost() < one.getMoney() - bill)
                        one.setMaterialAmount(numAmount, 6);
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
    system("clear");
    saveData(one);
    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** 
 * This is the function which allows to user to select how many days they wish to wait.
 */
Wagon Stop(Wagon one)
{
    system("clear");  //clears the consol

    string DaysToWait;  //stores the time to wait as a string
    float waitTime = 0;  //store the time to wait as an int

    cout << "How many days would you like to rest?" << endl;  //asks the user how long to wait.
    waitTime = Amount();  //has the user input an amount using the Amount function.

    one.setTimeDay(waitTime);  //sets the date to however many days the player chose to wait
    one.setMaterialAmount(one.getMaterials(1).getAmount() - (3 * waitTime), 1);  //Removes 3 lbs. of food per day
    
    if (waitTime >= 2)  //checks to see if the wait time is larger than 2
    {
        for (int i = 0; i < 5; i++)  //runs through every memeber on the wagon
        {
            if (one.getPersons(i).getSickDays() != 0)  //checks for any sick members
                one.setPersonsSickDays(0, i);  //resets the time a person has been sick thus making them healthy
        }
    }

    return one;  //returns the changes to the object
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Continue(Wagon one)
{
    system("clear");

    one.setTimeDay(14);  //sets the date to 2 weeks in the futur
    one.setMaterialAmount(one.getMaterials(1).getAmount() - (3 * 14), 1);  //Removes 3 lbs. of food per day
    one.setMiles(one.getMiles() + randomNumbers(70, 140));

    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Hunt(Wagon one)
{
    system("clear");

    cout << "Hunt" << endl;
    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Quit(Wagon one)
{
    system("clear");

    cout << "quit" << endl;
    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Display(Wagon one)
{
    string choice = "";

    cout << "Today is " << one.getTime().getMonth() << ' ' << one.getTime().getDay() << ", " << one.getTime().getYear() << endl;
    cout << "\n   Miles traveled: " << one.getMiles() << " miles" << endl;
    cout <<   "   Next landmark:  0" << " miles" << endl;
    cout <<   "   Food:           " << one.getMaterials(1).getAmount() << " lbs." << endl;
    cout <<   "   Bullets left:   " << one.getMaterials(2).getAmount() << endl;
    cout <<   "   Money left:     $" << one.getMoney() << endl;

    cout << "\n\nHow would you like to proceed?\n" << endl;
    cout << "1. Stop and rest" << endl;
    cout << "2. Continue on the trial" << endl;
    cout << "3. Hunt for food" << endl;
    cout << "4. Quit" << endl;

    getline(cin, choice);
    if(choice == "1")
    {
        one = Stop(one);
    }
    else if (choice == "2")
    {
        one = Continue(one);
    }
    else if(choice == "3")
    {
        one = Hunt(one);
    }
    else if(choice == "4")
    {
        one = Quit(one);
    }
    return one;
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
        one = shop(one);  //the function takes the play into the shop function and then overloads the wagon object so data is saved
    }
//*********************************************************************************************************//

    while (one.getMiles() < 2048)  
    {
        one = Display(one);
        clear();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////