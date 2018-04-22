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

class Milestone
{
    public:

        Milestone();
        ~Milestone();
        
        string getName();
        int getMiles();
        string getType();

        void setInfo();

    private:
        string name[15];
        int miles[15];
        string type[15];

        int NamePlace;
        int MilePlace;
        int TypePlace;

};

#endif

Milestone::Milestone()
{
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

    NamePlace = 0;
    MilePlace = 0;
    TypePlace = 0;
}

string Milestone::getName()
{
    return name[NamePlace];
}

int Milestone::getMiles()
{
    return miles[MilePlace];
}

string Milestone::getType()
{
    return type[TypePlace];
}

void Milestone::setInfo()
{
    MilePlace += 1;
    NamePlace += 1;
    TypePlace += 1;
}

Milestone::~Milestone()
{
    
}