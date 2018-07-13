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

#ifndef WAGONGANG_H
#define WAGONGANG_H

/**
 * Class: this class is used to house the people and thier attributes.
 * Member Functions: 2 constructors, 1 defult and 1 custom.
 *                   3 getters and setter for each data memeber
 * Data Members: a name, living status, and the amount of days a person has been sick 
 */
class Gang
{
    public:
        Gang();  //Constructs the compainio(defult)
        Gang(string);  //custom constructor for a companion
        ~Gang();  //deconstructor

        string getName();  //returns the person name
        bool getAlive();  //returns the person Alive stauts
        int getSickDays();  //returns the person sick days

        void setName(string);  //sets the persons name
        void setAlive(bool);  //sets the persons alive status
        void setSickDays(int);  //sets the persons sick days

    private:

        string name;  //holds the persons name
        bool alive;  //holds the persons alive stauts
        int sickDays;  //holds the persons sicks days

};

#endif 

/**
 *Algorithm: constructs a defult person
    1. sets name to none, alive to false, sick days to 0
 * Input Parameter:none
 * Output:none
 * Return:none
 */
Gang::Gang()
{
    name = "NONE";  //name is set to none
    alive = false;  //alive set to no
    sickDays = 0;  //sick days set to 0
}

/**
 *Algorithm: constructs a custom person
    1. sets name to the input parameter, alive to yes, and sick days to none
 * Input Parameter: a name
 * Output: none
 * Return:none
 */
Gang::Gang(string Title)
{
    name = Title;
    alive = true;
    sickDays = 0;
}

/**
 *Algorithm: returns the person name
    1. returns the person name
 * Input Parameter:none
 * Output:none
 * Return:name
 */
string Gang::getName()
{ 
    return name;  //returns the person name
}

/**
 *Algorithm: returns the person alive status
    1. returns the person alive status
 * Input Parameter:
 * Output:none
 * Return:none
 */
bool Gang::getAlive()
{
    return alive;  //returns the person alive status
}

/**
 *Algorithm: returns the person sick days
    1. returns the person sick days
 * Input Parameter:none
 * Output:none
 * Return:none
 */
int Gang::getSickDays()
{
    return sickDays;  //returns the person sick days
}

/**
 *Algorithm: sets the name to the input parameter
    1. sets the name to the input parameter
 * Input Parameter:a name
 * Output:none
 * Return:none
 */
void Gang::setName(string newName)
{
    name = newName; // sets the name to the input parameter
}

/**
 *Algorithm:  sets the alive to the input parameter
    1.  sets the alive to the input parameter
 * Input Parameter:
 * Output:
 * Return:
 */
void Gang::setAlive(bool maybe)
{
    alive = maybe; // sets the alive to the input parameter
}

/**
 *Algorithm:  sets the sick day to the input parameter
    1. sets the sick day to the input parameter
 * Input Parameter: sick day amount
 * Output:none
 * Return:none
 */
void Gang::setSickDays(int amount)
{
    sickDays = amount;  //sets the sick day to the input parameter
}

/**
 *Algorithm: Deconstructs the person object
    1.
 * Input Parameter:
 * Output:
 * Return:
 */
Gang::~Gang()
{
    
}