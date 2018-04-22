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
#include <math.h>
#include "Wagon.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * After each stage/turn, any changes to the user data will be saved to a file so that it can be transfered to the next stage/turn.
 */ 
void saveData(Wagon one)
{
    ofstream save;
    save.open("results.txt");

    if (save.is_open())
    {   
        save << "Leaders name: " << one.getPersons(0).getName() << endl;
        save << "Miles Travelled: " << one.getMiles();
        save << "Food Remaining: " << one.getMaterials(1).getAmount() << endl;
        save << "Cash Remaining: " << one.getMoney();  
    }
    else
    {
        cout << "Failed to save." << endl;
    }

    save.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Puzzle()
{
    int tries = 0;  // initilized the amount of tries the user has to win.
    int target = randomNumbers(1, 10);  //creats a random number between one and ten for the user to guess.

    while (tries < 3)  //loops until all 3 tries are up.
    {
        cout << "Guess a number between 1 and 10." << endl;  //asks the user to guess a number
        int guess = Amount();  //runs the unser input through the amount function to weed out edge cases.

        if (guess == target)  //determines if the user guessed the right value
        {
            cout << "You guess the right number! You solved the puzzle!" << endl;  //tells the user they won.
            return true;  //returns true signifying the puzzle was solved
        }
        else
        {
            cout << "Not quite. Try again." << endl;  //tells the user they were wrong.
            tries++;  //adds one to the try counter.
        }
    }
    
    cout << "Sorry, but you've ran out of tries and failed the puzzle." << endl;  //tells the user they lost.
    return false;  //returns false signifying the user failed to solve the puzzle.
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon shop(Wagon one, Wagon cart)
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

        //prints out what the player current has on hand
        cout << "\nCurrent Items:\n" << endl;
        cout << "Oxen:    " << one.getMaterials(0).getAmount() << endl;
        cout << "Food:    " << one.getMaterials(1).getAmount() << endl;
        cout << "Bullets: " << one.getMaterials(2).getAmount() << endl;
        cout << "Wheels:  " << one.getMaterials(3).getAmount() << endl;
        cout << "Axles:   " << one.getMaterials(4).getAmount() << endl;
        cout << "Tongues: " << one.getMaterials(5).getAmount() << endl;
        cout << "MedKits: " << one.getMaterials(6).getAmount() << endl;

        cout << "\n------------------------\n" << endl;

        cout << "1. Oxen           " << "$" << one.getMaterials(0).getCost() * cart.getMaterials(0).getAmount() << endl;
        cout << "2. Food           " << "$" << one.getMaterials(1).getCost() * cart.getMaterials(1).getAmount() << endl;
        cout << "3. Bullets        " << "$" << one.getMaterials(2).getCost() * cart.getMaterials(2).getAmount() << endl;
        cout << "4. Spare Parts    " << "$" << (one.getMaterials(3).getCost() * cart.getMaterials(3).getAmount())
                                             + (one.getMaterials(4).getCost() * cart.getMaterials(4).getAmount())
                                             + (one.getMaterials(5).getCost() * cart.getMaterials(5).getAmount())
                                             + (one.getMaterials(6).getCost() * cart.getMaterials(6).getAmount()) << endl;

    //*********************************************************************************************************//
    /**
     * This block is used to calculate the total bill after each puchase
     */
        bill = ((cart.getMaterials(0).getAmount() * one.getMaterials(0).getCost()) 
               +(cart.getMaterials(1).getAmount() * one.getMaterials(1).getCost())
               +(cart.getMaterials(2).getAmount() * one.getMaterials(2).getCost())
               +(cart.getMaterials(3).getAmount() * one.getMaterials(3).getCost())
               +(cart.getMaterials(4).getAmount() * one.getMaterials(4).getCost())
               +(cart.getMaterials(5).getAmount() * one.getMaterials(5).getCost())
               +(cart.getMaterials(6).getAmount() * one.getMaterials(6).getCost()));
        cout << "\nYour bill is: $" << bill << endl; 
        cout << "After payment, you will have $" << one.getMoney() - bill << endl;

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
            
            numAmount = Amount() + one.getMaterials(0).getAmount();

            if (numAmount * one.getMaterials(0).getCost() < one.getMoney() - bill && numAmount * one.getMaterials(0).getCost() >= 100 && numAmount * one.getMaterials(0).getCost() <= 200)
                cart.setMaterialAmount(numAmount, 0);
            else if (numAmount * 40 > one.getMoney())
            {
                cout << "Sorry sport, looks like you don't have enough!" << endl;
                clear();
            }
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

            if (numAmount * one.getMaterials(1).getCost() < one.getMoney() - bill)   //determines of the player has enough to purchase this item
                cart.setMaterialAmount(numAmount, 1);  //adds the food to the players cart.
            else
            {
                cout << "Sorry buckaroo, looks like you don't have enough!" << endl;
                clear();
            }
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

            if (numAmount * one.getMaterials(2).getCost() < one.getMoney() - bill)  //determines of the player has enough to purchase this item
                cart.setMaterialAmount(numAmount * 20, 2);  //adds 20 * however many boxes of bullets to the playes cart
            else
            {
                cout << "Sorry slugger, looks like you don't have enough!" << endl;
                clear();
            }
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
                cout << "1. Wheels     " << "$" << cart.getMaterials(3).getAmount() * one.getMaterials(3).getCost() << endl;
                cout << "2. Axles      " << "$" << cart.getMaterials(4).getAmount() * one.getMaterials(4).getCost() << endl;
                cout << "3. Tongues    " << "$" << cart.getMaterials(5).getAmount() * one.getMaterials(5).getCost() << endl;
                cout << "4. MedKits    " << "$" << cart.getMaterials(6).getAmount() * one.getMaterials(6).getCost() << endl;

                cout << "\nWhich item would you like to purchase?" << endl;
                cout << "press 'q' to return to the store" << endl;
                getline(cin, choice);
            //---------------------------------------------------------------------------//
                if (choice == "1")
                {
                    cout << "How many wheels do you want?" << endl;
                    
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(3).getCost() < one.getMoney() - bill)
                        cart.setMaterialAmount(numAmount, 3);
                    else
                    {
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                        clear();
                    }
                }
            //---------------------------------------------------------------------------//
                else if (choice == "2")
                {
                    cout << "How many axles would you like?" << endl;
                    
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(4).getCost() < one.getMoney() - bill)
                        cart.setMaterialAmount(numAmount, 4);
                    else
                    {
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                        clear();
                    }
                }
            //---------------------------------------------------------------------------//
                else if (choice == "3")
                {
                    cout << "How many tongues do you want?" << endl;
                                
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(5).getCost() < one.getMoney() - bill)
                        cart.setMaterialAmount(numAmount, 5);
                    else
                    {
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                        clear();
                    }
                }
            //---------------------------------------------------------------------------//
                else if (choice == "4")
                {
                    cout << "How many medKits do you want?" << endl;
                    
                    
                    numAmount = Amount();

                    if (numAmount * one.getMaterials(6).getCost() < one.getMoney() - bill)
                        cart.setMaterialAmount(numAmount, 6);
                    else
                    {
                        cout << "Sorry chief, looks like you don't have enough!" << endl;
                        clear();
                    }
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
            
            for(int i = 0; i < 7; i++)
            {
                one.setMaterialAmount(cart.getMaterials(i).getAmount() + one.getMaterials(i).getAmount(), i);  //adds new items to players inventory.
            }

            one.setMoney(one.getMoney() - bill);  //1000 because 200 was spent on the wagon itself.
            break;
        }
    }
    system("clear");
    //saveData(one);
    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void progressUpdate(Wagon one)
{
    if(one.getMaterials(1).getAmount() == 0  || 
       one.getPersons(0).getAlive() == false ||
       one.getMaterials(0).getAmount() == 0 )  //needs wagon status!!
    {
        cout << "YOU HAVE DIED OF DYSENTERY!" << endl;
        cout << "Leaders name: " << one.getPersons(0).getName() << endl;
        cout << "Miles Travelled: " << one.getMiles() << endl;
        cout << "Food Remaining: " << one.getMaterials(1).getAmount() << endl;
        cout << "Cash Remaining: " << one.getMoney() << endl;
        saveData(one);
        exit(0);
    }
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

    for (int i = 0; i < 5; i++)  //loops through each person on the wagon
    {
        if (one.getPersons(i).getSickDays() > 0 && one.getPersons(i).getSickDays() >= waitTime)  //check to see if anyone is sick
        {
            one.getPersons(i).setSickDays(one.getPersons(i).getSickDays() - waitTime);  //takes one day off the sick person
            cout << one.getPersons(i).getName() << " is starting to feel better." << endl;  //tells the user sick people are feeling better.
        }
        else if (one.getPersons(i).getSickDays() > 0)
        {
            one.getPersons(i).setSickDays(0);  //takes one day off the sick person
            cout << one.getPersons(i).getName() << " is all healthy!" << endl;  //tells the user sick people are feeling better.
        }
        else
        {
            ;
        }
    }

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
Wagon Continue(Wagon one, Wagon cart)
{
    system("clear");  // the terminal is cleared for the next turn/screen

    for (int i = 0; i < 5; i++)  //loops through each person on the wagon
    {
        if (one.getPersons(i).getSickDays() > 0)  //check to see if anyone is sick
        {
            one.getPersons(i).setSickDays(0);  //takes one day off the sick person
            cout << one.getPersons(i).getName() << " is all healthy now." << endl;  //tells the user sick people are feeling better.
        }
    }

    one.setTimeDay(14);  //sets the date to 2 weeks in the futur
    one.setMaterialAmount(one.getMaterials(1).getAmount() - (3 * 14), 1);  //Removes 3 lbs. of food per day
    one.setMiles(one.getMiles() + randomNumbers(70, 140));  //the miles is increased from where the turn started to where it ended.

    if (one.getMiles() >= one.getCheckPoint().getMiles())  //check to see if the player is at a milestone
    {
        cout << "You have reached the " << one.getCheckPoint().getName() << endl; 
        one.setMiles(one.getCheckPoint().getMiles());  //sets the miles travelled to where the milestone is so that the player cannot go past it.
        
        if (one.getCheckPoint().getType() == "m")  //check to see if the milestone is a rock
        {
            cout << "You can either (1)rest here or (2)continue on." << endl;  //tells the user thier options
            float choice = Amount();

            while(true)  //runs until the user picks 1 or 2
            {
                if (choice == 1)  //check to see if the choice is 1
                {
                    Stop(one);  //if it is, the function goes to the stop function
                    one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                    break;  //the loop breaks
                }
                else if (choice == 2)
                {
                    one.setTimeDay(14);  //sets the date to 2 weeks in the futur
                    one.setMaterialAmount(one.getMaterials(1).getAmount() - (3 * 14), 1);  //Removes 3 lbs. of food per day
                    one.setMiles(one.getMiles() + randomNumbers(70, 140));  //the miles is increased from where the turn started to where it ended.
                    break; //the loop breaks
                }
                else
                    cout << "Invalid choice, please try again." << endl;  //tells the user to try again
            }
        }

        else if (one.getCheckPoint().getType() == "f")  //check to see if the milestone is a fort
        {
            cout << "You can either (1)rest here (2)continue on or (3)shop" << endl;  //tells the user thier options
            float choice = Amount();  //the user is asked to chose.

            while(true)  //runs until the user picks 1 or 2
            {
                if (choice == 1)  //check to see if the choice is 1
                {
                    Stop(one);  //if it is, the function goes to the stop function
                    one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                    break;  //the loop breaks
                }
                else if (choice == 2)  //check to see if the user wants to continue
                {
                    one.setTimeDay(14);  //sets the date to 2 weeks in the futur
                    one.setMaterialAmount(one.getMaterials(1).getAmount() - (3 * 14), 1);  //Removes 3 lbs. of food per day
                    one.setMiles(one.getMiles() + randomNumbers(70, 140));  //the miles is increased from where the turn started to where it ended.
                    break; //the loop breaks
                }
                else if(choice == 3)  //checks to see if the user wants to shop
                {
                    if (one.getMiles() >= 304 && one.getMiles() < 640)
                    {
                        for (int i = 0; i < 7; i++)  //loops through every supply in the wagon class
                            one.setMaterialCost(one.getMaterials(i).getCost() * 1.25, i);  //sets the materials cost to a higher value depended on where in the trail the user is
                        one = shop(one, cart);  //user is taken to the shop
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break; //the loop breaks
                    }
                    else if (one.getMiles() >= 640 && one.getMiles() < 989)  //determines where the user is on the trail.                   
                    {
                        for (int i = 0; i < 7; i++)  //loops through every supply in the wagon class
                            one.setMaterialCost(one.getMaterials(i).getCost() * 1.50, i);  //sets the materials cost to a higher value depended on where in the trail the user is
                        one = shop(one, cart);  //user is taken to the shop
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break; //the loop breaks
                    }
                    else if (one.getMiles() >= 989 && one.getMiles() < 1395)  //determines where the user is on the trail.                    
                    {
                        for (int i = 0; i < 7; i++)  //loops through every supply in the wagon class
                            one.setMaterialCost(one.getMaterials(i).getCost() * 1.75, i);  //sets the materials cost to a higher value depended on where in the trail the user is
                        one = shop(one, cart);  //user is taken to the shop
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break; //the loop breaks
                    }
                    else if (one.getMiles() >= 1395 && one.getMiles() < 1648)  //determines where the user is on the trail.
                    {
                        for (int i = 0; i < 7; i++)  //loops through every supply in the wagon class
                            one.setMaterialCost(one.getMaterials(i).getCost() * 2, i); //sets the materials cost to a higher value depended on where in the trail the user is                      
                        one = shop(one, cart);  //user is taken to the shop
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break; //the loop breaks
                    }
                    else if (one.getMiles() >= 1648 && one.getMiles() < 1863)  //determines where the user is on the trail.
                    {
                        for (int i = 0; i < 7; i++)  //loops through every supply in the wagon class
                            one.setMaterialCost(one.getMaterials(i).getCost() * 2.25, i);  //sets the materials cost to a higher value depended on where in the trail the user is
                        one = shop(one, cart);  //user is taken to the shop
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break; //the loop breaks
                    }
                }
                else
                    cout << "Invalid choice, please try again." << endl;  //tells the user to try again
            }
        }

        else if (one.getCheckPoint().getType() == "r")  //check to see if the milestone is a river
        {
            if (one.getMiles() != 185)
            {
                cout << "You can either (1)rest here or (2)cross the river by fairy ($10 dollars)." << endl;  //tells the user thier options
                float choice = Amount();  ////the user is asked to chose.

                while(true)  //runs until the user picks 1 or 2
                {
                    if (choice == 1)  //check to see if the choice is 1
                    {
                        Stop(one);  //if it is, the function goes to the stop function
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break;  //the loop breaks
                    }
                    else if (choice == 2)
                    {
                        one.setMoney(one.getMoney() - 10);
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break; //the loop breaks
                    }
                    else
                        cout << "Invalid choice, please try again." << endl;  //tells the user to try again
                }
            }
            else
            {
                cout << "You can either (1)rest here or (2)continue on." << endl;  //tells the user thier options
                float choice = Amount();

                while(true)  //runs until the user picks 1 or 2
                {
                    if (choice == 1)  //check to see if the choice is 1
                    {
                        Stop(one);  //if it is, the function goes to the stop function
                        one.setMiles(one.getMiles() + 1);  //sets the mile counter to +1 so that the user wont get stuck at a milestone
                        break;  //the loop breaks
                    }
                    else if (choice == 2)
                    {
                        one.setTimeDay(14);  //sets the date to 2 weeks in the futur
                        one.setMaterialAmount(one.getMaterials(1).getAmount() - (3 * 14), 1);  //Removes 3 lbs. of food per day
                        one.setMiles(one.getMiles() + randomNumbers(70, 140));  //the miles is increased from where the turn started to where it ended.
                        break; //the loop breaks
                    }
                    else
                        cout << "Invalid choice, please try again." << endl;  //tells the user to try again
                }
            }
        }
        one.setCheckPoint();  //each element in the milestone arrays are shifted down one.
    }

    return one;  //returns the changes to the object
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Hunt(Wagon one)
{
    system("clear");  // the terminal is cleared for the next turn/screen

    int foodGained = 0;

    if (randomNumbers(1, 2) == 1)  //determines if the user will encounter a rabit.
    {
        string choice;
        cout << "You got lucky! your encountered a rabbit! Do you want to hunt it? (y/n)" << endl;  //tells the user they found a rabbit
        getline(cin, choice);

        if (choice == "y")  //determines if the user chose to hunt the rabit
        {
             if (one.getMaterials(2).getAmount() >= 10)  //check to see if the player has enough bullets to hunt.
             {
                 if (Puzzle() == true)  //check to see if they passed the puzzle
                 {
                    cout << "Success! You have gained 2 lbs. of food!" << endl;  //tells the user they have had a successful hunt
                    foodGained += 2;  //adds 10 to the players food amount
                    one.setMaterialAmount(one.getMaterials(2).getAmount() - 10, 2); // removes 10 bullets from the users inventory.
                 }
                 else
                    cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
             }
             else
                cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
        }
    }
    if(randomNumbers(1, 4) == 1)  //determines if the user encountered a fox
    {
        string choice;  //stores the users choice.
        cout << "You got lucky! your encountered a fox! Do you want to hunt it? (y/n)" << endl;  //tells the user they found a rabbit
        getline(cin, choice);  //takes in the users choice from the command line.

        if (choice == "y")  //determines if the user chose to hunt the rabit
        {
             if (one.getMaterials(2).getAmount() >= 10)  //check to see if the player has enough bullets to hunt.
             {
                 if (Puzzle() == true)  //check to see if they passed the puzzle
                 {
                    cout << "Success! You have gained 5 lbs. of food!" << endl;  //tells the user they have had a successful hunt
                    foodGained += 8;  //adds 8 to the players food amount
                    one.setMaterialAmount(one.getMaterials(2).getAmount() - 8, 2); // removes 8 bullets from the users inventory.
                 }
                 else
                    cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
             }
             else
                cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
        }
    }
    int deerChance = randomNumbers(1, 100);  //created a variable which takes a random number from 1 tp 100
    if(deerChance >= 1 && deerChance <= 15)  //determines if the random number fell between 1 and 15 creating a 15% chance or occurance
    {
        string choice;  //stores the users choice.
        cout << "You got lucky! your encountered a deer! Do you want to hunt it? (y/n)" << endl;  //tells the user they found a rabbit
        getline(cin, choice);  //takes in the users choice from the command line.

        if (choice == "y")  //determines if the user chose to hunt the rabit
        {
             if (one.getMaterials(2).getAmount() >= 10)  //check to see if the player has enough bullets to hunt.
             {
                 if (Puzzle() == true)  //check to see if they passed the puzzle
                 {
                    int deerFood = randomNumbers(30, 55);  //finds a random number between 30 and 55
                    cout << "Success! You have gained " << deerFood << " lbs. of food!" << endl;  //tells the user they have had a successful hunt
                    foodGained += deerFood;  //adds 30-55 lbs. to the players food amount
                    one.setMaterialAmount(one.getMaterials(2).getAmount() - 5, 2); // removes 5 bullets from the users inventory.
                 }
                 else
                    cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
             }
             else
                cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
        }
    }
    int bearChance = randomNumbers(1, 100);  ////created a variable which takes a random number from 1 tp 100
    if(bearChance >= 1 && bearChance <= 7)  //determines if the user encounters a bear
    {
        string choice;  //stores the users choice.
        cout << "You got lucky! your encountered a bear! Do you want to hunt it? (y/n)" << endl;  //tells the user they found a rabbit
        getline(cin, choice);  //takes in the users choice from the command line.

        if (choice == "y")  //determines if the user chose to hunt the rabit
        {
             if (one.getMaterials(2).getAmount() >= 10)  //check to see if the player has enough bullets to hunt.
             {
                 if (Puzzle() == true)  //check to see if they passed the puzzle
                 {
                    int bearFood = randomNumbers(100, 250);  //finds a random number between 100 and 250
                    cout << "Success! You have gained " << bearFood << " lbs. of food!" << endl;  //tells the user they have had a successful hunt
                    foodGained += bearFood;  //adds 100-250 lbs. to the players food amount
                    one.setMaterialAmount(one.getMaterials(2).getAmount() - 10, 2); // removes 10 bullets from the users inventory.
                 }
                 else
                    cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
             }
             else
                cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
        }
    }
    if(randomNumbers(1, 20) == 1)  //determines if the user encounters a moose (5% chance).
    {
        string choice;  //stores the users choice.
        cout << "You got lucky! your encountered a moose! Do you want to hunt it? (y/n)" << endl;  //tells the user they found a rabbit
        getline(cin, choice);  //takes in the users choice from the command line.

        if (choice == "y")  //determines if the user chose to hunt the rabit
        {
             if (one.getMaterials(2).getAmount() >= 10)  //check to see if the player has enough bullets to hunt.
             {
                 if (Puzzle() == true)  //check to see if they passed the puzzle
                 {
                    int mooseFood = randomNumbers(300, 600);  //finds a random number between 300 and 600
                    cout << "Success! You have gained " << mooseFood << " lbs. of food!" << endl;  //tells the user they have had a successful hunt
                    foodGained += mooseFood;  //adds 300-600 lbs. to the players food amount
                    one.setMaterialAmount(one.getMaterials(2).getAmount() - 12, 2); // removes 12 bullets from the users inventory.
                 }
                 else
                    cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
             }
             else
                cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
        }
    }
    if (foodGained != 0)  //determines if the user gained any food.
    {
        string choice = "";

        //asks the user how well they want to eat.
        cout << "How well would you like to eat?" << endl;
        cout << "   (p)oorly: 2 lbs. of food per person" << endl;
        cout << "   (m)oderately: 3 lbs. of food per person" << endl;
        cout << "   (w)ell: 5 lbs. of food per person" << endl;
        getline(cin, choice);

        while(true)  //runs untill the user picks a valid choice
        {
            if(choice == "p")  //determines if the user chose p for poor
            {
                foodGained -= 2;  //takes 2 away from the food gained. since 3 was already eaten today, 1 is added to compensate
                break;  //the while loop is exited
            }
            else if(choice == "m")  //determines if the user chose m for moderate
            {
                foodGained -= 3;
                break;  //takes 3 away from the food gained. 
            }
            else if(choice == "w")  //determines if the user chose w for well
            {
                foodGained -= 5;  //takes 5 away from the food gained. since 3 was already eated, only 2 is taken away.
                for (int i = 0; i < 5; i++)  //loops through each person on the wagon
                {
                    if (one.getPersons(i).getSickDays() > 0)  //check to see if anyone is sick
                    {
                        one.getPersons(i).setSickDays(0);  //takes one day off the sick person
                        cout << one.getPersons(i).getName() << " is all healthy!" << endl;  //tells the user sick people are feeling better.
                    }
                }
                break;  //the while loop is exited
            }
            else 
            {
                cout << "Invalid choice. Please try again." << endl;  //tells the user their choice is invalid
                getline(cin, choice);  //retakes in the users choice.
            }
        }
    }
    else
    {
        cout << "Hunt was unsuccessful." << endl;  //informs the user their hunt was unsuccessful.
        foodGained -= 3;  //removes 3 from the users food for a wasted day.
    }

    if(one.getMaterials(1).getAmount() + foodGained <= 1000)  //determines if the food gained is greater than 1000
        one.setMaterialAmount(one.getMaterials(1).getAmount() + foodGained, 1);  //adds the food gained to the wagon
    else
    {
        cout << "The wagon can only hold 1000 lbs. of food. Some had to be left behind." << endl;  //tells the user there was too much food
        one.setMaterialAmount(1000, 1);  //the wagon food amount is set to 1000
        clear();
    }
    one.setTimeDay(1);  //the day is set to increase by one for the hunt.
    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Quit(Wagon one)
{
    system("clear");

    cout << "You were unable to make it to Oregon!" << endl;
    cout << "YOU HAVE DIED OF DYSENTERY!" << endl;
    cout << "Leaders name: " << one.getPersons(0).getName() << endl;
    cout << "Miles Travelled: " << one.getMiles() << endl;

    if (one.getMaterials(1).getAmount() < 0)  //check to see if the food remaining is less than 0
        cout << "Food Remaining: 0" << endl;  //print out 0 for food remaining
    else 
        cout << "Food Remaining: " << one.getMaterials(1).getAmount() << endl;  //prints out the food remaining.

    cout << "Cash Remaining: $" << one.getMoney() << endl;
    saveData(one);
    exit(0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Display(Wagon one, Wagon cart)
{
    string choice = "";  //initilizes a variable for the user to enter a choice 

    //the following 6 lines prints out the date, the miles travelled, the distance till the next landmark, and the food, bullets, and money remaining
    cout << "Today is " << one.getTime().getMonth() << ' ' << one.getTime().getDay() << ", " << one.getTime().getYear() << endl;
    cout << "\n   Miles traveled: " << one.getMiles() << " miles" << endl;
    cout <<   "   Next landmark:  " << one.getCheckPoint().getMiles() << " miles" << endl;
    cout <<   "   Food:           " << one.getMaterials(1).getAmount() << " lbs." << endl;
    cout <<   "   Bullets left:   " << one.getMaterials(2).getAmount() << endl;
    cout <<   "   Money left:     $" << one.getMoney() << endl;

    //the following lines display the options avaliabe to the user.
    cout << "\n\nHow would you like to proceed?\n" << endl;
    cout << "1. Stop and rest" << endl;
    cout << "2. Continue on the trial" << endl;
    cout << "3. Hunt for food" << endl;
    cout << "4. Quit" << endl;

    //here is here the users choice is sorted
    getline(cin, choice);
    if(choice == "1")  //determines if the user will want to stop
    {
        one = Stop(one);  //takes the user to the stop function
    }
    else if (choice == "2")  //determines if the user will want to continue
    {
        one = Continue(one, cart);  //takes the user to the continue function
    }
    else if(choice == "3")  //determines if the user will want to Hunt
    {
        one = Hunt(one);  //takes the user to the Hunt function
    }
    else if(choice == "4")  //determines if the user will want to Quit
    {
        Quit(one);  //takes the user to the quit function
    }
    return one;  //all data changed in the one class is returned to the main function
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Wagon Misfortune(Wagon one)
{ 
    system("clear");  //clears the terminal

    int event = randomNumbers(1, 5);  //this will randomly choose a misfortune to occure.

    //------------------------------------------------------------------//
    if (event == 1)  //determines if a person will get sick
    {
        int sickBoi = randomNumbers(1, 5);
        int sickness = randomNumbers(1, 6);

        if (one.getPersons(sickBoi).getSickDays() > 0)  //check to see if the person already had an illness
        {
            cout << "Oh no!" << one.getPersons(sickBoi).getName() << " caught and L and died." << endl;  //tells the player
            one.getPersons(sickBoi).setAlive(false);  //kills of the person.
        }

        if (sickness == 1) //check to see what illness the person will have
        {   
            cout << one.getPersons(sickBoi).getName() << " has falled ill with typhoid!" << endl;  //tells the player
            one.getPersons(sickBoi).setSickDays(5);  //sets the persons sick days to 1
        }
        else if (sickness == 2) //check to see what illness the person will have
        {   
            cout << one.getPersons(sickBoi).getName() << " has falled ill with cholera!" << endl;  //tells the player
            one.getPersons(sickBoi).setSickDays(5);  //sets the persons sick days to 1
        }
        else if (sickness == 3) //check to see what illness the person will have
        {   
            cout << one.getPersons(sickBoi).getName() << " has falled ill with diarrhea!" << endl;  //tells the player
            one.getPersons(sickBoi).setSickDays(5);  //sets the persons sick days to 1
        }
        else if (sickness == 4) //check to see what illness the person will have
        {   
            cout << one.getPersons(sickBoi).getName() << " has falled ill with measles!" << endl;  //tells the player
            one.getPersons(sickBoi).setSickDays(5);  //sets the persons sick days to 1
        }
        else if (sickness == 5) //check to see what illness the person will have
        {   
            cout << one.getPersons(sickBoi).getName() << " has falled ill with dysentery!" << endl;  //tells the player
            one.getPersons(sickBoi).setSickDays(5);  //sets the persons sick days to 1
        }
        else if (sickness == 6) //check to see what illness the person will have
        {   
            cout << one.getPersons(sickBoi).getName() << "has falled ill with fever!" << endl;  //tells the player
            one.getPersons(sickBoi).setSickDays(5);  //sets the persons sick days to 1
        }
    }
    else if (event == 2)  //determines if the player will loose an ox
    {
        cout << "Oh no! One of your oxen has gone to a farm up state and died." << endl;  //tells the play an ox died
        one.setMaterialAmount(one.getMaterials(0).getAmount() - 1, 0);  //and ox is removed from the players wagon
        cout << "You have " << one.getMaterials(0).getAmount() << " oxen left." << endl;  //tell the user how much is left
    }
    else if (event == 3)  //determines of the player will be robbed by thieves.
    {
        int foodGone = randomNumbers(10, 25);  //generate a randome amount of food to be stolen
        cout << "Oh no! Last night you got attacked by a thief!"  << endl;  //tells the play they were robbed
        one.setMaterialAmount(one.getMaterials(1).getAmount() - foodGone, 1);  //sets the food the the amount stolen
        cout << "You lost " << foodGone << " lbs. of food" << endl;  //tells the user how much good they have
    }
    else if (event == 4)  //determines if the players wagon will break
    {
        int brokenPart = randomNumbers(3, 5);
        cout << "Oh no! A(n) " << one.getMaterials(brokenPart).getName() << " has broken." << endl;  //tells the user what broke
        one.setMaterialAmount(one.getMaterials(brokenPart).getAmount() - 1, brokenPart);  //removes one of the spare parts from the players inventory
        
        if (one.getMaterials(brokenPart).getAmount() <= 0)  //check too see if they player has anymore parts when the misfourtone hits
        {
            cout << "You wagon has broke and you have no spare parts!" << endl;  //tells the user they are no more spare parts
        }
        else
        {
            cout << "It will take 1 day to fix your wagon." << endl;  //tells the user it will take one day to fix wagon
            one.setTimeDay(1);  //sets the day to one day in the future

            for (int i = 0; i < 5; i++)  //loops through each person on the wagon
            {
                if (one.getPersons(i).getSickDays() > 0)  //check to see if anyone is sick
                {
                    one.getPersons(i).setSickDays(one.getPersons(i).getSickDays() - 1);  //takes one day off the sick person
                    cout << one.getPersons(i).getName() << " is starting to feel better." << endl;  //tells the user sick people are feeling better.
                }
            }
        }
    }
    else if (event == 5)  //determines if the player will experience bad weather.
    {
        int weather = randomNumbers(1, 5);
        cout << weather << endl;
        string weatherType[5] = {"Hail!", "Heavy rain!", "Storm!", "Blizzard!", "Hurricane!"};

        if(weather == 1 || weather == 2)  //checks the weather for hail
        {
            cout << "Oh no! The weather has turned rotten. " << weatherType[weather - 1] << endl;  //tells the user that hail has struck
            one.setTimeDay(1);  //day is set to one

            for (int i = 0; i < 5; i++)  //loops through each person on the wagon
            {
                if (one.getPersons(i).getSickDays() > 0)  //check to see if anyone is sick
                {
                    one.getPersons(i).setSickDays(one.getPersons(i).getSickDays() - 1);  //takes one day off the sick person
                    cout << one.getPersons(i).getName() << " is starting to feel better." << endl;  //tells the user sick people are feeling better.
                }
            }
        }
        else if(weather == 3 || weather == 4)  //checks the weather for hail
        {
            cout << "Oh no! The weather has turned rotten. " << weatherType[weather - 1] << endl;  //tells the user that hail has struck
            one.setTimeDay(3);  //day is set to one

            for (int i = 0; i < 5; i++)  //loops through each person on the wagon
            {
                if (one.getPersons(i).getSickDays() > 0)  //check to see if anyone is sick
                {
                    one.getPersons(i).setSickDays(0);  //takes one day off the sick person
                    cout << one.getPersons(i).getName() << " is all healthy!" << endl;  //tells the user sick people are feeling better.
                }
            }
        }
        else if(weather == 5)  //checks the weather for hail
        {
            cout << "Oh no! The weather has turned rotten. " << weatherType[weather - 1] << endl;  //tells the user that hail has struck
            one.setTimeDay(7);  //day is set to one

            for (int i = 0; i < 5; i++)  //loops through each person on the wagon
            {
                if (one.getPersons(i).getSickDays() > 0)  //check to see if anyone is sick
                {
                    one.getPersons(i).setSickDays(0);  //takes one day off the sick person
                    cout << one.getPersons(i).getName() << " is all healthy!" << endl;  //tells the user sick people are feeling better.
                }
            }
        }
    }
    return one;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Wagon raiders(Wagon one)
{
    int choice;  //creates a varialbe for the user choice to be held

    cout << "Riders ahead! They look hostile" << endl;  //tells the user raiders are ahead.
    cout << "How do you wish to proceed" << endl;  //askes the user how to with to proceed
    cout << "   1. Run (will loose 1 ox, 10 lbs. or food, and 1 wagon part)" << endl;  //tells the use what they will loose if they run 
    cout << "   2. Attack (Can with win 50 lbs. of food and bullets or loose 50 lbs. of good and .25 of cash)" << endl; //tells the user what happens if they atteck.
    cout << "   3. Surrender (will loose a quarter of cash reserves)" << endl; // tells the user what they will loose if they surrender.

    choice = Amount();

    if (choice == 1)  //determines if the player will run
    {
        system("clear");  //clears the terminal

        int randomPart = randomNumbers(3, 5);  //randomly choses a wagon part to leave behind.

        cout << "Your party escapes the raider, but at what cost?" << endl; //tells the user they got away
        one.setMaterialAmount(one.getMaterials(0).getAmount() - 1, 0); //decreases the oxen amount by 1 from players inventory
        one.setMaterialAmount(one.getMaterials(1).getAmount() - 10, 1); //decreases the food amount by 10 from players inventory
        one.setMaterialAmount(one.getMaterials(randomPart).getAmount() - 1, randomPart); //decreases the wagon parts amount by 1 from players inventory
        clear(); //clears the terminal
    }
    else if (choice == 2)  //determines if the user will attack
    {
        system("clear");  //clears the terminal

        bool maybe = Puzzle();  //runs the player through the puzzle function

        if (maybe == true)  //determines of the play won the puzzle and therefore the attack
        {
            cout << "Congradulations! You defeat the raiders!" << endl;
            one.setMaterialAmount(one.getMaterials(1).getAmount() + 50, 1);  //they player gets 50 pounds of food added to their wagon
            one.setMaterialAmount(one.getMaterials(2).getAmount() + 50, 2);  //they player gets 50 bullets added to their wagon
            clear();   //clears the terminal
        }
        else
        {
            cout << "After fighting with the raiders, you and your wagon suffers losses" << endl;  //tells the user they lost
            one.setMaterialAmount(one.getMaterials(2).getAmount() - 50, 2);  //they player looses 50 bullets from their wagon
            one.setMoney(one.getMoney() - (one.getMoney() / 4));  //the player looses 1/4 of their cash reserves.
            clear();   //clears the terminal
        }
    }
    else if (choice == 3)  //determines if the user surrenders
    {
        cout << "Your party surrenders. For this, the raiders are merciful. Only cash is taken" << endl; //the user is told that only cash is taken.
        one.setMoney(one.getMoney() - (one.getMoney() / 4));  //the player looses 1/4 of their cash reserves.
        clear();   //clears the terminal
    }
    return one;
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

    cout << "Welcome to The Oregon Trail!" << endl;  //welcomes the user to the game
    Wagon one = Wagon();  //constructs a wagon
    Wagon cart = Wagon(1);  //constructs a second wagon for the shop
//*********************************************************************************************************//
/**
 * Here the game will tell the user about the shop and initiate the shop simulation function.
 */
    system("clear");

    //the following 4 lines of code are just a message to the play informing them about the shop
    cout << "Before leaving Independence, you should consider buying supplies." << endl;
    cout << "After buying your wagon, you have $1000 left to spend in the shop." << endl;
    cout << "All of the neccessary materials can be found there, but you do not need to spend all of your money now." << endl;
    clear();  //clears the screen untill the user presses enter.

    one = shop(one, cart);  //the function takes the play into the shop function and then overloads the wagon object so data is saved
//*********************************************************************************************************//

    while (one.getMiles() < 2048)  //this checks after each turn the amount of miles travled to determine if the player has made it to the end
    {
        one = Display(one, cart);  //after each turn the date is passed back into the one object.
                             // the new data is then passed right back into the display function for the next turn.
        int random = randomNumbers (1, 10);  //randomly pick a number between one and 10 for the is misfortune
        if (random <= 4 && random >= 1)  //created a 40 percent chance for misfortune to happen.
            one = Misfortune(one);

        int raidersProbability = (((pow((one.getMiles()/100) - 4, 2) + 72)/(pow((one.getMiles()/100) - 4, 2) + 12)) - 1) * 10;  //determines odds of meeting raiders.
        int odds = randomNumbers(1, 100);  //creates a randomNumber generator from 1 to 100
        if (odds >= 1 && odds <= raidersProbability)  //determines if raiders will occure
            one = raiders(one);

        //this if statement checks after each turn whether or not they play meets any of the conditions which ends the game
        if(one.getMaterials(1).getAmount() <= 0  || 
           one.getPersons(0).getAlive() == false ||
           one.getMaterials(0).getAmount() == 0  ||
           one.getMaterials(3).getAmount() < 0  ||
           one.getMaterials(4).getAmount() < 0  ||
           one.getMaterials(5).getAmount() < 0)  
        {
            // the following lines of code display the users status if they have failed and that they died
            cout << "YOU HAVE DIED OF DYSENTERY!" << endl;
            cout << "Leaders name: " << one.getPersons(0).getName() << endl;
            cout << "Miles Travelled: " << one.getMiles() << endl;

            if (one.getMaterials(1).getAmount() < 0)  //check to see if the food remaining is less than 0
                cout << "Food Remaining: 0" << endl;  //print out 0 for food remaining
            else 
                cout << "Food Remaining: " << one.getMaterials(1).getAmount() << endl;  //prints out the food remaining.

            cout << "Cash Remaining: $" << one.getMoney() << endl;
            saveData(one);  //the player status is also printed out to a results file
            exit(0);  //the entire program is ended 
        }
        clear();  //after each turn, the screen is cleared.
    }
    cout << "Congradulations! You have made it to Oregon!" << endl;  //the player wins and the game is over
    saveData(one);  //all data is saved and printed to a seperate file.
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////