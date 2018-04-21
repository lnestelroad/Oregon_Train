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

/**
 * Class: this class is used to house the date.
 * Member Functions: 2 constructors, 1 defult and 1 custom.
 *                   3 getters and setter for each data memeber
 *                   1 helper function for the setDay function.
 * Data Members: a day, a month, and a year 
 */
class Date
{ 
    public:

        Date();
        Date(int, string);

        int getDay();
        string getMonth();
        int getYear();

        void setDay(int);
        int intMonth(string);
        void setMonth(int);
        void setYear(int);

    private:

        int day;
        string month;
        int year;

        string Months[12];
};

#endif 

Date::Date()
{
    day = 28;
    month = "March";
    year = 1846;

    Months[3] = "March";
    Months[4] = "April";
    Months[5] = "May";
    Months[6] = "June";
    Months[7] = "July";
    Months[8] = "August";
    Months[9] = "September";
    Months[10] = "October";
    Months[11] = "November";
}

Date::Date(int Day, string Month)
{
    day = Day;
    month = Month;
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

/**
 *Algorithm: This function is used to reset the day. I will also change the month if the number of days exceeds
             the amount in current given month.
    1. The function will first go through and fetch the current day and month.
    2. variables will then be created to hold the current amount of days + the number of pasted days,
       a variable to hold the currnt month as a value, and a variable to hold the next month as a value
    3. the function will then determine what month it currently is with an if statment.
        A. Should the current month contain 31 days, the function will then check whether of not the change in time
           exists within the same month.
        B. if the time passes exceeds the amount of days in the current month, the current month will be progressed
           to the next month and and days will be subtracted by 31 or 30 depending on the starting month.
 * Input Parameter: the amount of time passed in days
 * Output: the new time.
 * Return: none
 */
void Date::setDay(int newDay)
{
    string CurrentMonth = getMonth();  //variable used to store the starting month
    int CurrentDay = getDay();  //variable used to store the starting day
    int change = newDay+CurrentDay;  //variable used to store the time passed.
    int i = 0;  //vairalbe used to hold the month as an int
    int nextMonth = 0;  //variable used to hold the next month as an int

    if(CurrentMonth == "March"  || 
       CurrentMonth == "May"    || 
       CurrentMonth == "July"   || 
       CurrentMonth == "August" || 
       CurrentMonth == "October")  //checks whether the current month has 31 days
    {
        if (change >= 1 && change <= 31)  //checks whether the change in days exceeds 31 days
            day = change;  //if it does not, the change in time will be added to the new day
        else
        {
            i = intMonth(CurrentMonth);  //the currnt month is store in a vaule sense
            nextMonth = i+1;  //the next month is found and stored as a value
            setMonth(nextMonth);  //the month is set using the the month setter function
            day = change - 31;  //the day subtracted by 31 so that the date in the next month is accurate
        }
    }
    else
    {
        if (newDay >= 1 && change <= 30)  //checks whether the change in days exceeds 30 days
            day = change;  //if it does not, the change in time will be added to the new day
        else
        {
            i = intMonth(CurrentMonth);  //the currnt month is store in a vaule sense
            nextMonth = i+1;  //the next month is found and stored as a value
            setMonth(nextMonth);  //the month is set using the the month setter function
            day = change - 30;  //the day subtracted by 30 so that the date in the next month is accurate
        }
    }
}

int Date::intMonth(string Month)
{
    for (int i = 0; i < 11; i++)
    {
        if (Month == Months[i])
            return i;
    }
    return 0;
}

void Date::setMonth(int newMonth)
{
    month = Months[newMonth];
}

void Date::setYear(int newYear)
{
    year = newYear;
}