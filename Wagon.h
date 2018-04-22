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

        Wagon();
        Wagon(int);  //used for the shop
        ~Wagon();

        Date getTime();
        Gang getPersons(int);
        Supplies getMaterials(int);
        float getMoney();
        int getMiles();
        Milestone getCheckPoint();

        void setMaterialAmount(int, int);
        void setMaterialCost(float, int);

        void setPersonsAlive(bool, int);
        void setPersonsSickDays(int, int);

        void setTimeMonth(int);
        void setTimeDay(int);
        
        void setMoney(float);
        void setMiles(int);

        void setCheckPoint();

    private:

        Date time;
        Gang persons[5];
        Supplies materials[7];
        float money;
        int miles;
        Milestone checkPoint;
};

#endif

Wagon::Wagon()
{
    ///////////////////////////////////////////////////////
    string leader = "";
    string companion = "";

    cout << "What is the name of the wagon leader?" << endl;
    getline(cin,leader);
    persons[0] = leader;

    cout << "Who will be joining you?" << endl;

    for (int i = 1; i < 5; i++)
    {
        cout << "Companion " << i << ":";
        getline(cin,companion);
        Gang person = Gang(companion);
        persons[i] = person;
    }

    clear();
    ///////////////////////////////////////////////////////
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
    string choice;
    cout << "The start date is March 28, 1846. If you would like to start at a different time press y. If not press enter " << endl;
    getline(cin, choice);

    if (choice == "y")
    {
        string date;
        string month;
        cout << "What day would you like to start?" << endl;
        getline(cin, date);
        cout << "what month do you want to start? " << endl;
        getline(cin, month);

        int day = stoi(date);

        Date today = Date(day, month);
    }
    else 
    {
        Date today = Date();
    }
    //////////////////////////////////////////////////////
    Milestone checkPoint;
    money = 1000;
    miles = 0;
}

Wagon::Wagon(int tienda)
{
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

Date Wagon::getTime()
{
    return time;
}

Gang Wagon::getPersons(int index)
{
    return persons[index];
}

Supplies Wagon::getMaterials(int i)
{
    return materials[i];
}

float Wagon::getMoney()
{
    return money;
}

int Wagon::getMiles()
{
    return miles;
}

Milestone Wagon::getCheckPoint()
{
    return checkPoint;
}

void Wagon::setMaterialAmount(int newAmount, int index)
{
    materials[index].setAmount(newAmount);
}

void Wagon::setMaterialCost(float newAmount, int index)
{
    materials[index].setCost(newAmount);
}

void Wagon::setPersonsAlive(bool alive, int index)
{
    persons[index].setAlive(alive);
}

void Wagon::setPersonsSickDays(int days, int index)
{
    persons[index].setSickDays(days);
}

void Wagon::setTimeMonth(int month)
{
    time.setMonth(month);
}

void Wagon::setTimeDay(int day)
{
    time.setDay(day);
}

void Wagon::setMoney(float newMoney)
{
    money = newMoney;
}

void Wagon::setMiles(int newMiles)
{
    miles = newMiles;
}

void Wagon::setCheckPoint()
{
    checkPoint.setInfo();
}

Wagon::~Wagon()
{

}