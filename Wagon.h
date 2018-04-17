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

#ifndef WAGON_H
#define WAGON_H

class Wagon
{
    public:

        Wagon();
        ~Wagon();

        Date getTime();
        Gang getPersons(int);
        Supplies getMaterials(string);
        float getMoney();
        int getMiles();

        void setMoney(int);
        void setMiles(int);

    private:

        Date time;
        Gang persons[5];
        Supplies materials[7];
        float money;
        int miles;
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
    ///////////////////////////////////////////////////////
    Supplies food = Supplies("food", 0.5);
        materials[0] = food;
    Supplies bullets = Supplies("bullets", 2);
        materials[1] = bullets;
    Supplies oxen = Supplies("oxen", 40);
        materials[2] = oxen;

    Supplies wheels = Supplies("wheels", 20);
        materials[3] = wheels;
    Supplies axles = Supplies("axles", 20);
        materials[4] = axles;
    Supplies tongues = Supplies("tongues", 20);
        materials[5] = tongues;

    Supplies medKit = Supplies("medKit", 25);
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
    money = 1200;
    miles = 0;
}

Date Wagon::getTime()
{
    return time;
}

Gang Wagon::getPersons(int index)
{
    return persons[index];
}

Supplies Wagon::getMaterials(string name)
{
    int index = 0;

    for (int i = 0; i < 7; i++)
    {
        if(name == materials[i].getName())
        {
            index = i;
        }
    }

    return materials[index];
}

float Wagon::getMoney()
{
    return money;
}

int Wagon::getMiles()
{
    return miles;
}

void Wagon::setMoney(int newMoney)
{
    money = newMoney;
}

void Wagon::setMiles(int newMiles)
{
    miles = newMiles;
}

Wagon::~Wagon()
{

}