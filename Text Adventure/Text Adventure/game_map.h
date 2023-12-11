#pragma once
//Allows access to librarys so the code can use different predefined functions and data types
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

//Creates a class to hold the different room methods
class game_map
{
//The access specifier that allows the methods to be accessible anywhere
public:
    //Declaring the method inside the class
    //The '&' symbol allows each of this to pass by reference making sure that it doesnt create copies and the data is always accessible
    int room0(map<string, bool> &inventory);
    int room1(map<string, bool> &inventory);
    //Passing the information from the Inventory map and the 'blade_code' variable so the methods can access the data
    int room2(map<string, bool> &inventory, int blade_code);
    int room3(map<string, bool> &inventory, int blade_code);
};

