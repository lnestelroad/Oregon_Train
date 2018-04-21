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

        Supplies();
        Supplies(string, float);
        ~Supplies();

        string getName();
        float getAmount();
        float getCost();

        void setName(string);
        void setAmount(float);
        void setCost(float);

    private:

        string name;
        float amount;
        float cost;

};

#endif 

Supplies::Supplies()
{
    name = "NONE";
    amount = 0;
    cost = 0;
}

Supplies::Supplies(string Title, float Dollars)
{
    name = Title;
    amount = 0;
    cost = Dollars;
}

string Supplies::getName()
{
    return name;
}

float Supplies::getAmount()
{
    return amount;
}

float Supplies::getCost()
{
    return cost;
}

void Supplies::setName(string Title)
{
    name = Title;
}

void Supplies::setAmount(float newAmount)
{
    amount = newAmount;
}

void Supplies::setCost(float newCost)
{
    cost = newCost;
}

Supplies::~Supplies()
{

}