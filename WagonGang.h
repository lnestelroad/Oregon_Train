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

#ifndef WAGON_H
#define WAGON_H

class Gang
{
    public:

        Gang();

        string getName();
        bool getAlive();
        int getSickDays();

        void setName();
        void setAlive();
        void setSickDays();

    private:

        string name;
        bool alive;
        int sickDays;

};

#endif 

Gang::Gang()
{

    
}