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

class Gang
{
    public:
        Gang();
        Gang(string);
        ~Gang();

        string getName();
        bool getAlive();
        int getSickDays();

        void setName(string);
        void setAlive(bool);
        void setSickDays(int);

    private:

        string name;
        bool alive;
        int sickDays;

};

#endif 

Gang::Gang()
{
    name = "NONE";
    alive = false;
    sickDays = 0;
}

Gang::Gang(string Title)
{
    name = Title;
    alive = true;
    sickDays = 0;
}

string Gang::getName()
{
    return name;
}

bool Gang::getAlive()
{
    return alive;
}

int Gang::getSickDays()
{
    return sickDays;
}

void Gang::setName(string newName)
{
    name = newName;
}

void Gang::setAlive(bool maybe)
{
    alive = maybe;
}

void Gang::setSickDays(int amount)
{
    sickDays = amount;
}

Gang::~Gang()
{
    
}