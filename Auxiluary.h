/*
CSCI 1300 spring
Author: Liam Nestelroad
Assignment: Homework 8; Auxilarly function file
Rectitaion: 103 - Arcaida Zhang
Cloun9 Workspace Editor Link: https://ide.c9.io/line4246/csci1300_amish
*/

#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This function is used to clear the sceen when ever an option is chosen. This is used to simulate the real game and limit clutter 
 * the terminal.
 */
void clear()
{
    string enter = "";
    cout << "\nPress enter to continue" << endl;

    getline(cin, enter);  //takes in the users enter from the terminal
    if (enter.length() == 0)  //makes sure the users input was an enter
    {
        system("clear");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This function is a helper function ment to convert inputted values and sort out things that cannot be converted.
 * Since this is problem is so common in the store, it was given its own function.
 */
float Amount()
{
    string amount = "";
    string temp = "~";
    float numAmount = 0;  //casted form of the amoun variable

    while(true)
    {
        getline(cin, amount);

        if (amount.length() == 0)
            cout << "Your choice cannot be blank. Please try again." << endl;
        else 
            break;
    }

    for (int i = 0; i < amount.length(); i++)
    {
        if (int(amount[i]) >= 48 && int(amount[i]) <= 57)
            temp[i] = amount[i];
    }
    
    if (temp == "~")
    {
        system("clear");

        cout << "Your choice cannot conatin characters. Please try again." << endl;
        clear();
        return 0;
    }
    else
    {
        numAmount = stof(temp);
        return numAmount;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
