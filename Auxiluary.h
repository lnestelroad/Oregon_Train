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
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Algorithm: This function is used to clear the sceen when ever an option is chosen. This is used to simulate the real game and limit clutter 
              the terminal.
    1. creates a variable for the user to enter
    2. takes in the users input
    3.if that user input is 0, the screen is cleared.
 * Input Parameter: none
 * Output: Press enter to coninue
 * Return: none.
 */
void clear()
{
    string enter = "";  // creats a variable for the user input
    cout << "\nPress enter to continue" << endl;  //has to user press enter

    getline(cin, enter);  //takes in the users enter from the terminal
    system("clear");  //clears the screen
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *Algorithm: This function is a helper function ment to convert inputted values and sort out things that cannot be converted.
            Since this is problem is so common in the store, it was given its own function.
    1. initilized all the neccessary variables include ones to hold the user input and the casted versions.
    2. The string is check to determine if anything is in there
    3. Every element in the string is check for digits
    4. all digits are converted to floats
 * Input Parameter: None
 * OutPut: None
 * Return: users input as a float.
 */
float Amount()
{
    string amount = "";  //holds the user input
    string temp = "~";  //holds the values in the user input
    float numAmount = 0;  //casted form of the amoun variable

    while(true)  //runs indefinatly or until broken out of
    {
        getline(cin, amount);  //takes in the user input

        if (amount.length() == 0)  //determines if there was anything in the user inut
            cout << "Your choice cannot be blank. Please try again." << endl;  //tells the user their anser cannot be blank
        else 
            break;  //breaks when something is entered.
    }

    for (int i = 0; i < amount.length(); i++)  //iterated through every character in the users string.
    {
        if (int(amount[i]) >= 48 && int(amount[i]) <= 57)  //determines if the characters are letters or digits
            temp[i] = amount[i];  //saves all of the digits to a seperate sting.
    }
    
    if (temp == "~")  //determines of there are digits withn the temp sting
    {
        system("clear");

        cout << "Your choice cannot conatin characters. Please try again." << endl;  //tells the users there inoit cannot contain letters
        clear();  //clears the screen
        return 0;  //ends the function
    }
    else
    {
        numAmount = stof(temp);  //convers all the digits to floats
        return numAmount;  //the digits are then returned.
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *Algorithm: This function will take a string and seperate it based on a special character. each seperated fragment will then be stored in an array.
    1. The function will first start by initializing all of the variables.
    2. An if statement will be used so sort out edge cases. Specifically for when nothing is entered in the phrase.
    3. A loop will the iterate for the length of the phrase so that each element can be analized.
        A. an if statement will determine if the current element is equivolent to the special dividing character
            *. When it does, the function will make a substring of the phrase based on the last occurance of the special dividing character and the
               distance to the current special dividing character.
            *. The counter variable is the incrimented by 1.
            *. The current position is then stored as the previous postion for the next iteration.
    4. The wordCounter is then returned.
 * Input Parameter: a phrase, a dividing character, an empty array, and an array size.
 * Output: nothing
 * Return: work count
 */
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
int randomNumbers(int min, int max)
{
    int num = 0;
    // need to write before calling rand() to seed the random number generator
    srand(time(0));
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}