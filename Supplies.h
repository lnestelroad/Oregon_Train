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

#ifndef SUPPLIES_H
#define SUPPLIES_H


/**
 * Class: this class is used to house supplies and thier attributes.
 * Member Functions: 2 constructors, 1 defult and 1 custom.
 *                   3 getters and setter for each data memeber
 * Data Members: a name, an amount, and a cost 
 */
class Supplies
{
    public: 

        Supplies();  //constructs the supply object (defult)
        Supplies(string, float);  //constructs the custom supply object
        ~Supplies();  //deconstructs the supply object

        string getName();  //returns the name of the supply
        float getAmount();  //returns the amount of the supply
        float getCost();  //returns the cost of the supply

        void setName(string);  //sets the name of the supply object
        void setAmount(float);  //sets the amount of the supply object
        void setCost(float);  //sets the cost of the supply object

    private:

        string name;  //holds the name of the supply
        float amount;  //holds the amount of the supply
        float cost;  //holds the cost of the supply

};

#endif 

/**
 *Algorithm: Consturcts the supply object (defult)
    1. sets name to none, amount to 0, and cost to 0
 * Input Parameter:none
 * Output:none
 * Return:none
 */
Supplies::Supplies()
{
    name = "NONE";  //sets supply name to none
    amount = 0; //sets amount ot 0
    cost = 0;  //sets cost to 0
}

/**
 *Algorithm: Constructs a custom Supply object
    1. sets name and cost to the input parameters and amount to 0
 * Input Parameter: a name and an initial cost
 * Output:none
 * Return:none
 */
Supplies::Supplies(string Title, float Dollars)
{
    name = Title;  //sets name to input parameter
    amount = 0;  //sets amount to 0
    cost = Dollars;  //sets cost to input parameter
}

/**
 *Algorithm: returns the name of the supply
    1. returns the name of the supply
 * Input Parameter:none
 * Output:none
 * Return:name
 */
string Supplies::getName()
{
    return name;  //returns the name of the supply
}

/**
 *Algorithm: returns the name of the supply
    1. returns the name of the supply
 * Input Parameter:none
 * Output:none
 * Return:amount
 */
float Supplies::getAmount()
{
    return amount;  //returns the name of the supply
}

/**
 *Algorithm: returns the cost of the supply
    1. returns the cost of the supply
 * Input Parameter:none
 * Output:none
 * Return:cost
 */
float Supplies::getCost()
{
    return cost;  //returns the cost of the supply
}

/**
 *Algorithm: sets the name of the supply to the input parameter
    1. sets the name of the supply to the input parameter
 * Input Parameter: a name
 * Output:none
 * Return:none
 */
void Supplies::setName(string Title)
{
    name = Title; //sets the name of the supply to the input parameter
}

/**
 *Algorithm: sets the amount of the supply to the input parameter
    1. sets the amount of the supply to the input parameter
 * Input Parameter: a new amount
 * Output:
 * Return:
 */
void Supplies::setAmount(float newAmount)
{
    amount = newAmount;  //sets the amount of the supply to the input parameter
}

/**
 *Algorithm: sets the cost of the supply to the input parameter
    1. sets the cost of the supply to the input parameter
 * Input Parameter: a new cost
 * Output:none
 * Return:none
 */
void Supplies::setCost(float newCost)
{
    cost = newCost;  //sets the name of the supply to the input parameter
}

/**
 *Algorithm: Deconstructs the supply object
    1.
 * Input Parameter:
 * Output:
 * Return:
 */
Supplies::~Supplies()
{

}