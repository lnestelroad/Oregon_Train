/*
CSCI 1300 spring
Author: Liam Nestelroad
Assignment: Homework 8; project proposal
Rectitaion: 103 - Arcaida Zhang
Cloun9 Workspace Editor Link: https://ide.c9.io/line4246/csci1300_amish
*/

/**
 * Project Proposal: Chess
 * 
 * Porject Goal: The goal of the project is to allow two users to play a game of chess. The game will have an output display so that the 
 * users can see the current board and piece positions. The program will keep track of position pieces and only allow piece 
 * movement which are considered legal moves.
 * 
 * Minimum Requirements:
    1.Classes:
        A. A class for each type of chess piece
        B. A class for the board
        C. A class for rules.
    2. Data Members: 
        A. Each chess piece will have a data type for position, move type (diagonal, straigh, L shape, backwards, ext...) and
           whether the piece is black or white.
        B. The board will have information about where each poistion is located based on a 2D grid.
        C. The rules will store true of false data about specific moves and winning.
    3. Read from File:
        A. A file will be used to store the current position of every piece of the board   
    4. Write to File: 
        A. The program will write to a file real time about where each piece on the board is
        B. the program will also keep track of which pieces are missing (captured) and if they are black or white.
 * 
 * How this will meet the minimun requirements: This program will require at least 6 classes (one for each piece) and each piece 
 * will require at a minimum of 4 data types (color, position, name, on board). Input and Output files will also be required to 
 * store temperary information so that the game can take place over long periods of time. As far as the While, For, IF, Else and
 * other commands go, I can garentee the requirements will be met. each piece will require multiple if and while loops to check
 * position inorder to confirm the next move as legit. Each possible move will need to be confirmed by the program before
 * any move is even made in order to ensure the users play by the rules. In order to drive the game, the program will have a terminal
 * open for user inputs. This is how the program will be interactive.
 * 
 * 
 */