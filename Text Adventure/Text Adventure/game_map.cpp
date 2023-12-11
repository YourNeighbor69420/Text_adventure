//Allows this file to access the header file called 'game_map'
#include "game_map.h"
//Allows access to librarys so the code can use different predefined functions and data types
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

//Delcaring the method outside the class with the parameters set to ensure
//the 'inventory' can be accessed
int game_map::room0(map<string, bool> &inventory)
{
    //Variable to store the players input
    string choice;
    //Variables for while loop redundancy
    bool choice1 = true;
    bool choice2 = true;

    //While loop for input redundancy
    while (choice1 == true){
        //Getting and storing input from the player
        cout << "What would you like to do? \n\n1.Search\n2.Approach the door\n" << endl;
        getline(cin, choice);
        //Checks the input to see what the player has and wants to do and executes it
        if (choice == "1" and inventory["room1_key"] == false)
        {
            cout << "You search and the room and come across a rusted key in the bookcase.\n" << endl;
            //Sets the key as picked up
            inventory["room1_key"] = true;
            
        }
        //Doesn't allow the player to pick the key up twice
        else if (choice == "1" and inventory["room1_key"] == true)
        {
            cout << "There seems to be nothing else notable in the room.\n" << endl;
        }
        else if (choice == "2") 
        {
            cout << "You approach the looming wooden door reinforced with iron. It has a large key hole placed in the middle of it. A slight gust causes the door to creak as if it was in agony.\n" << endl;
            //While loop for input redundancy
            while (choice2 == true) 
            {
                //Getting and storing input from the player
                cout << "What would you like to do? \n\n1.Attempt the door\n2.Back away\n" << endl;
                getline(cin, choice);
                if (choice == "1") 
                {
                    //Checks if the player has the key
                    cout << "You attempt to open the door." << endl;
                    if (inventory["room1_key"] == true)
                    {
                        cout << "\nYou place the rusty key inside the lock and turn the key. It groans until you hear a faint click." << endl;
                        cout << "You push on the large door and it slowly opens.You find yourself in a courtyard." << endl;
                        cout << "You hear the door behind you slam shut." << endl;
                        cout << "It seems obvious now looking at it from the front that it was only intended to be opened from one side.\n\n" << endl;
                        //Sends 1 to main so that the room can change
                        return 1;
                    }
                    else 
                    {
                        cout << "It seems to be locked, there should be a key around here.\n" << endl;
                    }
                }
                else if (choice == "2") 
                {
                    cout << "You back away from the door." << endl;
                    //Sends 0 to the main so the room stays the same
                    return 0;
                }
                else 
                {
                    cout << "That is not a valid action." << endl;
                }
            }
        }
        else 
        {
            cout << "That is not a valid action." << endl;
        }
    }

  
}

//Delcaring the method outside the class with the parameters set to ensure
//the 'inventory' can be accessed
int game_map::room1(map<string, bool> &inventory)
{
    //Variable to store the players input
    string choice;
    //Variables for while loop redundancy
    bool choice1 = true;
    bool choice2 = true;


    //Outputs a different description of the locations depending on whether the player has certain items
    if (inventory["handle_part"] == false)
    {
        cout << "To the right lies an out of place path of winding marble leading off behind the clinic.\n" << endl;
    }

    if (inventory["blade_part"] == false)
    {
        cout << "Infront of you lies a straight path of gravel and stone that seems to be leading off into another building." << endl;
        cout << "It's hard to make out with the fog and foliage .\n" << endl;
    }
    cout << "To the left lies a tall iron gate locked shut with snake shaped chain that is biting its own tail.\n" << endl;


    //While loop for input redundancy
    while (choice1 == true) 
    {
        //Getting and storing input from the player
        cout << "What would you like to do? \n\n1.Go right\n2.Go forward\n3.Approach the gate\n" << endl;
        getline(cin, choice);
        if (choice == "1" and inventory["handle_part"] == false)
        {
            cout << "You make your way onto the right pathway, your footsteps echoeing off of the marble as you make you walk behind the clinic...\n\n" << endl;
            //Sends 1 to main so that the room can change to the mausoleum
            return 1;
        }
        else if (choice == "1" and inventory["handle_part"] == true)
        {
            cout << "You have already found everything notable from there." << endl;
        }
        else if (choice == "2" and inventory["blade_part"] == false)
        {
            cout << "You make your way onto the pathway infront, the gravel crunching with every step as your walk deeper and deeper into the fog...\n\n" << endl;
            //Sends 2 to main so that the room can change to the research building
            return 2;
        }
        else if (choice == "2" and inventory["blade_part"] == true)
        {
            cout << "You have already found everything notable from there." << endl;
        }
        else if (choice == "3") 
        {
            cout << "You approach the giant iron gate." << endl;
            cout << "Upon closer inspection there appears to be a deep slit across the neck of the snake chain almost as if something is supposed to be inserted into it." << endl;
            //Allows the redundancy loop to continue
            choice2 = true;
            //While loop for input redundancy
            while (choice2 == true)
            {
                //Getting and storing input from the player
                cout << "What would you like to do? \n\n1.Attempt the chain\n2.Back away\n" << endl;
                getline(cin, choice);
                
                if (choice == "1")
                {
                    cout << "You search for something to stick in the hole." << endl;
                    //Checks to see if both items have been obtained
                    if (inventory["blade_part"] == true and inventory["handle_part"] == true)
                    {
                        cout << "You take the blade and the handle you have and push them together." << endl;
                        cout << "The blade perfectly slots into the handle." << endl;
                        cout << "Now a full blade, you plunge it into the snakes neck and twist." << endl;
                        cout << "The snakes mouth releases its tail and almost resisting, the snake falls off of the gate." << endl;
                        //Sends 3 to main to bring the player to the winning condition
                        return 3;
                    }
                    else
                    {
                        cout << "Nothing seems to fit, there should be something that fits around here\n" << endl;
                        //Gets rid of any error flag to make sure future inputs don't fail
                        cin.clear();
                    }
                }
                else if (choice == "2")
                {
                    cout << "You back away from the gate." << endl;
                    //Breaks the redundancy loop
                    choice2 = false;
                }
                else
                {
                    cout << "That is not a valid action." << endl;
                }
            }
        }
        else
        {
            cout << "That is not a valid action." << endl;
        }
    }
   
}

//Delcaring the method outside the class with the parameters set to ensure
//the 'inventory' and the 'blade_code' can be accessed
int game_map::room2(map<string, bool> &inventory,int blade_code)
{
    //Variables to store the players input
    string choice;
    int location_choice;
    //Variables for while loop redundancy
    bool choice1 = true;
    bool choice2 = true;
    //Predefined function creates a random number with a parameter of 0
    srand(time(NULL));
    //Makes a random number between 1 and 50
    int handle_location = rand() % 50 + 1;

    cout << "You come across a marble mausoleum behind the clinic. You notice the doors are slightly a jar open." << endl;
    cout << "A gust of wind blows out of it. It reeks of death. You slip between the doors and make your way inside." << endl; 
    cout << "Inside you see bodies piled into different sepulchers in the wall." << endl;
    
    //While loop for input redundancy
    while (choice1 == true)
    {
        //Getting and storing input from the player
        cout << "You determine that one of the bodies could contain something useful. What would you like to do?\n\n1.Search\n2.Leave the Mausoleum\n" << endl;
        getline(cin, choice);
        if (choice == "1")
        {
            //While loop for input redundancy
            while (choice2 == true)
            {
                //Getting and storing input from the player
                cout << "Which sepulcher would you like to search? (1 - 50)\n" << endl;
                cin >> location_choice;
                //Discards the input buffer to allow for fresh input so the input doesn't fail
                cin.ignore();

                //Checks the input to see if it is the same as the random number
                if (location_choice == handle_location)
                {
                    cout << "You find a handle, it seems to be missing its blade." << endl;
                    cout << "You also come across a piece of parchment with '" << blade_code << "' scrawled across it." << endl;
                    cout << "After searching around more, you seem to find all there was to be found here so you leave back to the courtyard.\n\n" << endl;
                    //Tells the 'inventory' that the player has picked up the item
                    inventory["handle_part"] = true;
                    return -1;
                }
                else if (location_choice > handle_location or location_choice < handle_location)
                {
                    cout << "Among the rotting corpse you dont seem to find anything except dust." << endl;

                }
                else
                {
                    cout << "That is not a valid action." << endl;

                }
            }
        }
        else if (choice == "2")
        {
            cout << "You slowly back away and slip through the door, leaving the mausoleum finding your self back in the courtyard.\n\n" << endl;
            //Sends -1 to main to send the player back to the courtyard
            return -1;
        }
        else
        {
            cout << "That is not a valid action." << endl;

        }
    }
}


//Delcaring the method outside the class with the parameters set to ensure
//the 'inventory' and the 'blade_code' can be accessed
int game_map::room3(map<string, bool> &inventory, int blade_code)
{
    //Variables to store the players input
    string choice;
    int code_choice;
    //Variables for while loop redundancy
    bool choice1 = true;
    bool choice2 = true;
    bool choice3 = true;
    

    cout << "You pass underneath a rusted arch covered in light bits of dead foliage." << endl;
    cout << "As you emerge on the otherside you see a building with latin written above the door way." << endl;
    cout << "On entry you see it seems to be a lab of some sorts, most likely used for research." << endl;
   
    //While loop for input redundancy
    while (choice1 == true)
    {
        //Getting and storing input from the player
        cout << "Theres probably something of value in here, what would you like to do?\n\n1.Search\n2.Leave\n" << endl;
        getline(cin, choice);

        if (choice == "1" and inventory["handle_part"] == true)
        {
            cout << "Underneath the desk you find a locked safe." << endl;
            cout << "It looks like it requires a 3 digit code" << endl;   
            
            //While loop for input redundancy
            while (choice2 == true)
            {
                //Getting and storing input from the player
                cout << "What would you like to do?\n\n1.Attempt it\n2.Back away\n" << endl;
                getline(cin, choice);
                //Allows the redundancy loop to continue
                choice2 = true;

                if (choice == "1")
                {

                    //While loop for input redundancy
                    while (choice3 == true)
                    {        
                        //Getting and storing input from the player
                        cout << "It looks like a combination lock" << endl;
                        cout << "What would you like to input? (0,0,0)" << endl;
                        cin >> code_choice;     
                        
                        //Checks if the input is the same as the random 'blade_code'
                        if (code_choice == blade_code)
                        {
                            cout << "After the third digit is slotted into place, you hear a click and the safe slowly opens." << endl;
                            cout << "Inside you find a strangely shaped blade missing a handle." << endl;
                            cout << "Upon futher inspection you see that the the base of the blade is cut into a certain pattern almost like a key." << endl;
                            cout << "After searching a bit more you deem this building empty and make your way back to the courtyard\n\n" << endl;
                            inventory["blade_part"] = true;
                            //Gets rid of any error flag to make sure future inputs don't fail
                            cin.clear();
                            //Discards the input buffer to allow for fresh input so the input doesn't fail
                            cin.ignore();
                            return -2;
                        }
                        else if (code_choice != blade_code)
                        {
                            cout << "You move the numbers around and nothing seems to happen.\n" << endl;
                            //Gets rid of any error flag to make sure future inputs don't fail
                            cin.clear();
                            //Discards the input buffer to allow for fresh input so the input doesn't fail
                            cin.ignore();
                        }
                        
                    }
                }
                else if(choice == "2")
                {
                    cout << "You back away from the safe." << endl;
                    //Breaks the redundancy loop
                    choice2 = false;
                }
                else
                {
                    cout << "That is not a valid action." << endl;
                }
                
            }
        }
        //Different output for not having the 'handle_part'
        else if (choice == "1" and inventory["handle_part"] == false)
        {
            cout << "Underneath the desk you find a locked safe." << endl;
            cout << "It looks like it requires a 3 digit code, there should be one somewhere. You back away from the safe." << endl;
        }
        else if (choice == "2")
        {
            cout << "You slowly back away and slip through the door, leaving the facility finding your self back in the courtyard.\n\n" << endl;
            //Sends -2 to main to send the player back to the courtyard
            return -2;
        }
        else
        {
            cout << "That is not a valid action." << endl;

        }
    }
}
