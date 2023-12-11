// Text Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.


using namespace std;

#include <iostream>
//Allows access to librarys so the code can use different predefined functions and data types
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
//Allows this file to access the header file called game_map
#include "game_map.h"


//A variable that changes to false depending on whether or not the win/lose condition has been met 
bool game_running = true;

//The main method that runs the game
int main()
{
    //The variable for what room the player is in
    int room = 0;
    //Create and declares a class that holds the room methods
    game_map current_room;
    //A variable that determines how long the game has been going for and when to activate the lose condition
    int game_timer = 0;

    //Creating and declaring a map called inventory that takes string and bool data types
    map<string, bool> inventory;

    //This defines what is inside the Inventory map allowing items to be picked up through true or false
    inventory["room1_key"] = false;
    inventory["handle_part"] = false;
    inventory["blade_part"] = false;

    //Using the predefined function, srand lets me create random numbers allowing me to create a random 3 digit code
    srand(time(NULL));
    int blade_code = rand() % 900 + 100;

    //Intro text to be outputted
    cout << "You wake up in a locked abandoned clinic. When you open your eyes you can make out a towering door, a desk drawer and a dusty bookcase.\n" << endl;
    cout << "You feel as if you shouldnt stick around for too long, whoever put you here could be back at any time." << endl;


    //A while loop that lets the game continue for as long as game_running is true
    while (game_running) {

        //increases the 'game_timer' everytime someone enters a new room
        game_timer++;

        // 0 = starting room
        // 1 = courtyard
        // 2 = marble mausoleum 
        // 3 = research building
        // 4 = Win
        //An if statement that calls functions that correspond to their respective room depending on whether or not the 'game_timer' is exceeded
        if (game_timer < 10)
        {
            if (room == 0)
            {
                //Adds the returned value onto the 'room' variable so the if statement knows what room the player is in
                room += current_room.room0(inventory);
            }
            else if (room == 1)
            {
                room += current_room.room1(inventory);
            }
            else if (room == 2)
            {
                room += current_room.room2(inventory, blade_code);
            }
            else if (room == 3)
            {
                room += current_room.room3(inventory, blade_code);
            }
            else if (room == 4)
            {
                //Ending text output
                cout << "You take one last look behind you push open the gate infront of you" << endl;
                cout << "With no certain destination in mind, you walk off into the fog, wondering what awaits you" << endl;
                cout << "..." << endl;
                cout << "The End?" << endl;
                         
                //Stops the while loop as a win condition
                game_running = false;
            }
        }
        else
        {
            //Ending text output
            cout << "." << endl;
            cout << "." << endl;
            cout << "." << endl;
            cout << "You hear a crunch behind you and turn around to see an axe come down on your head." << endl;
            cout << "Darkness..." << endl;
            cout << "You took too long to escape" << endl;
            
            //Stops the while loop as a lose condition
            game_running = false;
        }
    }
}

