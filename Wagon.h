/*
CSCI 1300 spring
Author: Liam Nestelroad
Assignment: Homework 8; Oregon Trail Wagon Gang Class
Rectitaion: 103 - Arcaida Zhang
Cloun9 Workspace Editor Link: https://ide.c9.io/line4246/csci1300_amish
*/

#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

#include "Supplies.h"
#include "WagonGang.h"
#include "Date.h"
#include "Auxiluary.h"
#include "milestone.h"

#ifndef WAGON_H
#define WAGON_H

/**
 * Class: this class is used to house the Wagon class. Here, all other class objects will 
 *        be stored/modified
 * Member Functions: 1 constructors.
 *                   5 getters, one for each data member, some requiring an index for the array. 
 * Data Members: a name, an amount, and a cost 
 */
class Wagon
{
    public:

        Wagon();  //defult constructor
        Wagon(int);  //used for the shop
        ~Wagon();  //deconstructor

        Date getTime();  //returns the time object
        Gang getPersons(int);  ////returns the person object at a given index
        Supplies getMaterials(int);  //returns the supply object at a given index
        float getMoney();  //returns the amount of money
        int getMiles();  //returns the milese travelled
        Milestone getCheckPoint();  //returns the milestone object

        void setMaterialAmount(int, int);  //sets the material amount at given index
        void setMaterialCost(float, int);  //sets the material cost at given index

        void setPersonsAlive(bool, int);  //sets the person alive staus at a given index
        void setPersonsSickDays(int, int);  //sets the person sick staus at a given index

        void setTimeMonth(int);  //sets the time objects month
        void setTimeDay(int);  //sets the time objects day and possible month depending of how many days pass
        
        void setMoney(float);  //set the objects money amount
        void setMiles(int);  //set the objects miles amount

        void setCheckPoint();  //sets the check point to the next check point.

    private:

        Date time;  //stores the time object
        Gang persons[5];  //stores all of the wagon members
        Supplies materials[7];  //stores all of the wagons supplies
        float money;  //stores all of the wagons money
        int miles;  //stores the miles travelled
        Milestone checkPoint;  //stores the milestone object.
};

#endif

/**
 *Algorithm: Constructs the wagon class
    1. sets the leader and gang member to the user inputted names
    2. creats all necessary supplies
    3. ask the user if they want to defult date or a constom date.
        A. constructs a date object
    4. creates a milestone object
    5. sets money to 1000
    6. sets miles to 0
 * Input Parameter: None
 * Output: None
 * Return: None
 */
Wagon::Wagon()
{
    ///////////////////////////////////////////////////////
    string leader = "";  //stores the wagon leaders name
    string companion = "";  //stores the companions names

    while (true) //runs forever or until broken out of
    {
        cout << "What is the name of the wagon leader?" << endl;  //asks the user for the name of the leader
        getline(cin,leader);  //brings in the name of the leader

        if (leader.length() != 0)  //determines if the user entered anything for their name
        {
            Gang person = Gang(leader);  //creates a new companion with the inputted name
            persons[0] = leader;  //sets person 0 as the leader
            break;
        }
        else
        {
            cout << "User name cannot be blank. Please try again" << endl;  // tells the user their name cannot be blank
            clear();
        }
    }

    cout << "Who will be joining you?" << endl;  //asks who will be the companions

    for (int i = 1; i < 5; i++)  //creats 4 different companion onjects
    {
        while (true)  //runs forever or until broken out of
        {
            cout << "Companion " << i << ":";  //creats an out put for the companion along with a counter
            getline(cin,companion);  //retreives the name for the current companion from the terminal

            if(companion.length() != 0) //determines if the user entered anything for their name
            {
                Gang person = Gang(companion);  //creates a new companion with the inputted name
                persons[i] = person;  //puts said companion in the persons array.
                break;  //while statemnet ends
            }
            else
            {
                cout << "Companion name cannot be blank. Please try again" << endl;  // tells the user their name cannot be blank
                clear();
            }
        }
    }

    clear();  //screen is cleared
    ///////////////////////////////////////////////////////
    
    //all of the wagons supplies are created with the inital cost and name. Then all are placed in their respective array space.
    Supplies oxen("oxen", 40);
        materials[0] = oxen;
    Supplies food("food", 0.5);
        materials[1] = food;
    Supplies bullets("bullets", 2);
        materials[2] = bullets;

    Supplies wheels("wheels", 20);
        materials[3] = wheels;
    Supplies axles("axles", 20);
        materials[4] = axles;
    Supplies tongues("tongues", 20);
        materials[5] = tongues;

    Supplies medKit("medKit", 25);
        materials[6] = medKit;
    //////////////////////////////////////////////////////
    string choice;  //stores the users date change
    cout << "The start date is March 28, 1846. If you would like to start at a different time press y. If not press enter " << endl; //tells the user the defult start date
    getline(cin, choice);  //retrieves the users choice

    if (choice == "y")  //determines if the user said yes
    {
        string date;  //holds the user choosen day
        string month;  //holds the user choosen month
        cout << "What day would you like to start?" << endl;  //asks the user what day to start
        getline(cin, date);  //brings in the users choice
        cout << "what month do you want to start? March, April, May, or June?" << endl;  //asks the user what month to start
        getline(cin, month);  //brings in the users choice

        int day = stoi(date);  //converts the day to an int

        Date today = Date(day, month);  //sets the date to the inputted date.
    }
    else 
    {
        Date today = Date();  //sets the date to the defult
    }
    //////////////////////////////////////////////////////
    Milestone checkPoint;  //creates a deful check point 
    money = 1000;  //sets money at 1000
    miles = 0;  //sets miles to 0
}

/**
 *Algorithm: Only adds supplies to the wagon class. Only used for the shop
    1. all of the supplies are made and stored in an array
 * Input Parameter: a value
 * Output: none
 * Return: none
 */
Wagon::Wagon(int tienda)
{
    //all of the wagons supplies are created with the inital cost and name. Then all are placed in their respective array space.
    Supplies oxen("oxen", 40);
        materials[0] = oxen;
    Supplies food("food", 0.5);
        materials[1] = food;
    Supplies bullets("bullets", 2);
        materials[2] = bullets;

    Supplies wheels("wheels", 20);
        materials[3] = wheels;
    Supplies axles("axles", 20);
        materials[4] = axles;
    Supplies tongues("tongues", 20);
        materials[5] = tongues;

    Supplies medKit("medKit", 25);
        materials[6] = medKit;
}

/**
 *Algorithm: Returns the time object
    1. Returns the time object
 * Input Parameter: none
 * Output: none
 * Return: the time object
 */
Date Wagon::getTime()
{
    return time;  //time object is returned
}

/**
 *Algorithm: Returns the persons object at a specific index
    1. Returns the persons object at a specific index
 * Input Parameter: and index
 * Output: none
 * Return: a person object
 */
Gang Wagon::getPersons(int index)
{
    return persons[index]; //Returns the persons object at a specific index
}

/**
 *Algorithm: Returns the supply object at a specific index
    1. Returns the supply object at a specific index
 * Input Parameter: and index
 * Output: none
 * Return: a supply object
 */
Supplies Wagon::getMaterials(int i)
{
    return materials[i];  //Returns the supply object at a specific index
}

/**
 *Algorithm: returns the wagons money
    1. returns the wagons money
 * Input Parameter:none
 * Output: none
 * Return: the money amount
 */
float Wagon::getMoney()
{
    return money;  //returns the wagons money
}

/**
 *Algorithm: Returns the wagons miles
    1.  Returns the wagons miles
 * Input Parameter:none
 * Output:none
 * Return: the wagons miles.
 */
int Wagon::getMiles()
{
    return miles;  //Returns the wagons miles
}

/**
 *Algorithm: returns the wagons milestone object
    1. returns the wagons milestone object
 * Input Parameter:none
 * Output:none
 * Return:the checkpoint object
 */
Milestone Wagon::getCheckPoint()
{
    return checkPoint;  //returns the wagons milestone object
}

/**
 *Algorithm: sets the material amount to a new amount at a specific index
    1. the supply setter function is used to reset a supply amount
 * Input Parameter: a new amount and an index
 * Output:none
 * Return:none
 */
void Wagon::setMaterialAmount(int newAmount, int index)
{
    materials[index].setAmount(newAmount);  //the supply setter function is used to reset a supply amount
}

/**
 *Algorithm: sets the material cost to a new amount at a specific index
    1. the supply setter function is used to reset a supply cost
 * Input Parameter: a new amount and an index
 * Output: none 
 * Return: none
 */
void Wagon::setMaterialCost(float newAmount, int index)
{
    materials[index].setCost(newAmount);  //the supply setter function is used to reset a supply cost
}

/**
 *Algorithm: sets a person alive status at a given index.
    1. uses the persons class to set the person object alive status
 * Input Parameter: a new alive status and an index
 * Output: none
 * Return: none
 */
void Wagon::setPersonsAlive(bool alive, int index)
{
    persons[index].setAlive(alive);  //uses the persons class to set the person object alive status
}

/**
 *Algorithm: sets a person sick day status at a given index.
    1. uses the persons class to set the person object sick day status
 * Input Parameter: a new sick day status and an index
 * Output: none
 * Return: none
 */
void Wagon::setPersonsSickDays(int days, int index)
{
    persons[index].setSickDays(days); //uses the persons class to set the person object sick day status
}

/**
 *Algorithm: sets the time object to a new month
    1. sets the time object to a new month
 * Input Parameter: a new month 
 * Output: none
 * Return: none
 */
void Wagon::setTimeMonth(int month)
{
    time.setMonth(month); //sets the time object to a new month
}

/**
 *Algorithm: sets the time object to a new day
    1. sets the time object to a new day  
 * Input Parameter: a new day
 * Output:none
 * Return:none
 */
void Wagon::setTimeDay(int day)
{
    time.setDay(day);  //sets the time object to a new day
}

/**
 *Algorithm:  sets the wagons money
    1. sets the wagons money
 * Input Parameter: a new money amount
 * Output:none
 * Return:none
 */
void Wagon::setMoney(float newMoney)
{
    money = newMoney;  //sets the wagons money
}

/**
 *Algorithm: sets the wagon miles
    1. sets the wagon miles
 * Input Parameter: a new mile amount
 * Output:none
 * Return:none
 */
void Wagon::setMiles(int newMiles)
{
    miles = newMiles;  //sets the wagon miles
}

/**
 *Algorithm: sets the mile marker ahead one in all of the milemarker arrays
    1. sets the mile marker ahead one in all of the milemarker arrays
 * Input Parameter:none
 * Output:none
 * Return:none
 */
void Wagon::setCheckPoint()
{
    checkPoint.setInfo();  //sets the mile marker ahead one in all of the milemarker arrays
}

/**
 *Algorithm: Deconstructs the wagon
    1.
 * Input Parameter:none
 * Output:none
 * Return:none
 */
Wagon::~Wagon()
{

}