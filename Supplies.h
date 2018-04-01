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

class Supplies
{
    public:

        Supplies();

        int getNumOxen();
        int getNumFood();
        int getNumBullets();

        int getNumWheels();
        int getNumAxles();
        int getNumTongues();

        int getBill();
        int getMoney();

        void setNumFood();
        void setNumBullets();
        void setNumOxen();

        void setNumWheels();
        void setNumAxles();
        void setNumTongues();

        void setBill();
        void setMoney();

    private:

        int numOxen;
        int numFood;
        int numBullets;

        int numWheels;
        int numAxles;
        int numTongues;

        int bill;
        int money;

};

#endif 