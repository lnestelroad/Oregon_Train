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
int Split (string phrase, char div, string words[], int size)
{
	//words[size];
    int wordCounter = 0;//this variable is initilized to count the amount of words in the phrase.
    int stop = 0;//this varialbe is used to store the length of the substring depending on the iteration and the start position
    int start = 0;//This variable is what determines where the substring will start.
    int counter = 0;//this variable is what determines which element to store the substring in.

    if (phrase.length() == 0)//This is used to determine whether or not anything was entered
        return 0;//if nothing is entered, the function is returned 0

    for (int i = 0; i <= phrase.length(); i++)//a for loop is created to run for the length of the phrase
    {
        if (phrase[i] == div || phrase[i] == '\0')//For every element of the phrase, this if statment is what determines whether it equals the special dividing character
        {
            stop = i - start;//here is where the length of the substring is determined. it takes the position of the start and subtracts it from the current element

            string parse = phrase.substr(start, stop);//here is where the substring is made.
            words[counter] = parse;//this array is where the substring is stored
        
            counter += 1;//here is where the element for the array is determined
			wordCounter += 1;//this is the counter which counts the words
            start = i + 1;//this is where the starting point for the next iteration is determined. Its found by storing the next position such that the special dividing character is not included
        }
    }
    return wordCounter;//here is where the word count is returned.
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string checkPoint(int info)
{
    ifstream check;
    check.open("milestones.txt");
    string line = "";

    string temp[2];
    string temp2[3];

    string Name[15];
    string distance[15];
    string type[15];
    string depth[15];

    int counter = 0;

    if (check.is_open())
    {
        while(getline(check, line))
        {
            Split(line, ',', temp, 2);
            Split(temp[1], ' ', temp2, 3);

            Name[counter] = temp[0];
            distance[counter] = temp2[0];

            if(temp2[1].length() != 0)
                type[counter] = temp2[1];
            else
                type[counter] = "Landmark";

            if(temp2[2].length() != 0)
            {
                depth[counter] = temp2[2];
            }
        }
    }

    // if(info = 1)
    // {
    //     return
    // }
    // return checkPoint;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int randomNumbers(int min, int max)
{
    int num = 0;
    // need to write before calling rand() to seed the random number generator
    srand(time(0));
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}