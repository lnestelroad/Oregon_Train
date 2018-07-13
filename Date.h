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

        Date();  //construsts a defult date
        Date(int, string);  //constructs a costum date,
        ~Date(); //deconstructs the date class.

        int getDay();  //returns the day
        string getMonth();  //returns the month
        int getYear();  //returns the year

        void setDay(int);  //sets the day
        int intMonth(string);  //gets the month as an int
        void setMonth(int);  //sets the month
        void setYear(int);  //sets the year

    private:

        int day;  //holds the day
        string month;  //holds the month
        int year;  //holds the year

        string Months[12];  //holds every month in the yaer
};

#endif 

/**
 *Algorithm: constructs the date class
    1. sets the day to 28, month to march, the yaer to 1846, and the months to there respective slot in the month array
 * Input Parameter:none
 * Output:none
 * Return:none
 */
Date::Date()
{
    day = 28; //sets day to 28
    month = "March";  //sets month to march
    year = 1846;  //sets year to 1846
    
    //sets the months to their respective month array slots.
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

/**
 *Algorithm: constructs a costum date class
    1. sets the day to Day, month to Month, the yaer to 1846, and the months to there respective slot in the month array
 * Input Parameter: A day and a month
 * Output:none
 * Return:none
 */
Date::Date(int Day, string Month)
{
    day = Day;  //day is set to Day
    month = Month;  //month is set to Month
    year = 1846;  //year is set to 1846

    //sets the months to their respective month array slots.
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

/**
 *Algorithm: returns the day
    1. returns the day
 * Input Parameter:none
 * Output:none
 * Return:none
 */
int Date::getDay()
{
    return day;  //returns the day
}

/**
 *Algorithm: returns the month
    1.  returns the month
 * Input Parameter:
 * Output:
 * Return:
 */
string Date::getMonth()
{
    return month;  //returns the month
}

/**
 *Algorithm: returns the year
    1. returns the year
 * Input Parameter:
 * Output:
 * Return:
 */
int Date::getYear()
{
    return year;  //returns the year
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

/**
 *Algorithm: returns the months as an it in the month array
    1. runs through every month in the array and compares it to the input parameter until a match is made
    2. th emonth element is returned.
 * Input Parameter: a month
 * Output: none
 * Return: the month element
 */
int Date::intMonth(string Month)
{
    for (int i = 0; i < 11; i++)  //loops throught every month in the month array
    {
        if (Month == Months[i])  //determines of the input parameter matchs any of the months
            return i;  //returns the month element
    }
    return 0;  //returns 0
}

/**
 *Algorithm: sets the month to the input parameter
    1. sets the month to the input parameter
 * Input Parameter: a new month
 * Output:none
 * Return:none
 */
void Date::setMonth(int newMonth)
{
    month = Months[newMonth];  //sets the month to the input parameter
}

/**
 *Algorithm: sets the year to the input parameter
    1. sets the year to the input parameter
 * Input Parameter:none
 * Output:none
 * Return:none
 */
void Date::setYear(int newYear)
{
    year = newYear;  //sets the year to the input parameter
}

Date::~Date()
{
    
}