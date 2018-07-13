/*
CSCI 1300 spring
Author: Liam Nestelroad
Assignment: Homework 8; Mile stone class
Rectitaion: 103 - Arcaida Zhang
Cloun9 Workspace Editor Link: https://ide.c9.io/line4246/csci1300_amish
*/

#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
using namespace std;

#ifndef MILESTONE_H
#define MILESTONE_H


/**
 * Class: this class is used to house the milestone class. here is where all of the mile stones will
 *        be stored/modified
 * Member Functions: 1 constructors.
 *                   3 getters, one for each data member,
 * Data Members: a name, a mile amount, and a type 
 */
class Milestone
{
    public:

        Milestone();  //constructs a new milestone object
        ~Milestone();  //deconstructs the object
        
        string getName();  //returns the name of the class
        int getMiles();  //returns the miles of the milestone
        string getType();  //returns the type of mile stone

        void setInfo();  //sets all of the miles stone arrays ahead by one

    private:
        string name[15];  //holds the names of the mile markers
        int miles[15];  //holds the miles of the mile markers
        string type[15];  //holds the types of the mile markers

        int NamePlace;  //holds the index of the mile marker name
        int MilePlace;  //holds the index of the mile marker mile
        int TypePlace;  //holds the index of the mile marker type

};

#endif

/**
 *Algorithm: //constructs a new milestone object
    1. each aspect of the mile marker are hard coded in
 * Input Parameter:none
 * Output:none
 * Return:none
 */
Milestone::Milestone()
{
    //all of the land mark names are set to their respective array slot
    name[0] = "Kansas River Crossing";
    name[1] = "Big Blue River Crossing";
    name[2] = "Fort Kearney";
    name[3] = "Chimney Rock";
    name[4] = "Fort Laramie";
    name[5] = "Independence Rock";
    name[6] = "South Pass";
    name[7] = "Fort Bridger";
    name[8] = "Green River Crossing";
    name[9] = "Soda Springs";
    name[10] = "Fort Hall";
    name[11] = "Snake River Crossing";
    name[12] = "Fort Boise";
    name[13] = "Blue Mountains";
    name[14] = "Fort Walla Walla";

    //all of the land mark miles are set to their respective array slot
    miles[0] = 102; 
    miles[1] = 185;
    miles[2] = 304; 
    miles[3] = 554; 
    miles[4] = 640;
    miles[5] = 830;
    miles[6] = 932;
    miles[7] = 989; 
    miles[8] = 1151; 
    miles[9] = 1295; 
    miles[10] = 1395;
    miles[11] = 1534; 
    miles[12] = 1648; 
    miles[13] = 1808;
    miles[14] = 1863;
    
    //all of the land mark types are set to their respective array slot
    type[0] = "r"; 
    type[1] = "r"; 
    type[2] = "f"; 
    type[3] = "m"; 
    type[4] = "f"; 
    type[5] = "m";
    type[6] = "m"; 
    type[7] = "f"; 
    type[8] = "r";
    type[9] = "m"; 
    type[10] = "f"; 
    type[11] = "r";
    type[12] = "f";
    type[13] = "m";
    type[14] = "f";

    //the array indexs are all set to 0
    NamePlace = 0;  
    MilePlace = 0;
    TypePlace = 0;
}

/**
 *Algorithm: //returns the name of the class at a specific index
    1. //returns the name of the class at a specific index
 * Input Parameter: none
 * Output:none
 * Return:none
 */
string Milestone::getName()
{
    return name[NamePlace];  //returns the name of the class at a specific index
}

/**
 *Algorithm: returns the miles of the class at a specific index
    1. returns the miles of the class at a specific index
 * Input Parameter:none
 * Output:none
 * Return:none
 */
int Milestone::getMiles()
{
    return miles[MilePlace];  //returns the miles of the class at a specific index
}

/**
 *Algorithm: returns the type of the class at a specific index
    1. returns the type of the class at a specific index
 * Input Parameter:none
 * Output:none
 * Return:none
 */
string Milestone::getType()
{
    return type[TypePlace];  //returns the type of the class at a specific index
}

/**
 *Algorithm: all milestone arrays are set to 1 ahead
    1. all milestone arrays are set to 1 ahead
 * Input Parameter:none
 * Output:none
 * Return:none
 */
void Milestone::setInfo()
{
    //all milestone arrays are set to 1 ahead
    MilePlace += 1;
    NamePlace += 1;
    TypePlace += 1;
}

/**
 *Algorithm: milestone is deconstructed
    1.
 * Input Parameter:none
 * Output:none
 * Return:none
 */
Milestone::~Milestone()
{
    
}