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

#ifndef DATE_H
#define DATE_H

class Date
{
    public:

        Date();

        int getDay();
        string getMonth();
        int getYear();

        void setDay(int);
        void setMonth(string);
        void setYear(int);

    private:

        int day;
        string month;
        int year;

};

#endif 

Date::Date()
{
    day = 28;
    month = "March";
    year = 1846;
}

int Date::getDay()
{
    return day;
}

string Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay(int newDay)
{
    day = newDay;
}

void Date::setMonth(string newMonth)
{
    month = newMonth;
}

void Date::setYear(int newYear)
{
    year = newYear;
}