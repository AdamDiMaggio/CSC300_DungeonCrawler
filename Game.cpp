#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

Game::Game()
{
    //create dungeon and entrance
    this->d = new Dungeon("Nazarick");
    this->d->addEntrance();

    //custom dungeon
    Room* currRoom = d->getEntrance()->addRoom(12, "The First Room", "skeleton");
    Room* rightPath = currRoom->addRoom(3, "Right Path 1", "nothing");
    Room* leftPath = currRoom->addRoom(9, "Left Path 1", "skeleton");
    rightPath = rightPath->addRoom(12, "Right Path 2", "nothing");
    leftPath = leftPath->addRoom(12, "Left Path 2", "rotting flesh");
    rightPath = rightPath->addRoom(12, "Right Path 3", "rotting flesh");
    leftPath = leftPath->addRoom(12, "Left Path 3", "rotting flesh");
    currRoom = leftPath->addRoom(3,"Convergence", "skeleton");
    currRoom->addDoorEW(currRoom, rightPath);
    currRoom =  currRoom->addRoom(12, "A Hallway", "rotting flesh");
    currRoom = currRoom->addRoom(12, "The Chamber's Entrance", "skeleton");
    rightPath = currRoom->addRoom(3, "Right Chamber 1", "rotting flesh");
    rightPath = rightPath->addRoom(12, "Right Chamber 2", "skeleton");
    leftPath = currRoom->addRoom(9, "Left Chamber 1", "nothing");
    leftPath = leftPath->addRoom(12, "Left Chamber 2", "skeleton");
    leftPath = leftPath->addRoom(3, "The Boss Room", "danger");
    leftPath->addDoorEW(leftPath, rightPath);
    currRoom->addDoorNS(leftPath, currRoom);
    this->d->setBossRoom(leftPath);
}    


void Game::playGame()
{
    cout << ". . .\n";
    cout<<"...\n";
    cout << "You awake to find yourself in a mossy room. There are no windows.\n";
    cout << "You see a dirty plaque on the wall that says:\n\n";

    cout<< " _________________\n";
    cout<< "|=====Dungeon=====|\n";
    cout<< "|=======of========|\n";
    cout<< "|=====" << this->d->getName() << "====|\n";
    cout<< "|=====Entrance====|\n";
    cout<< "|_________________|\n";

    cout << "You can't seem to recall how you got here. Can you remeber your name?\n";
    string playerName;
    cin >> playerName;
    Player* player1 = new Player(playerName, d->getEntrance());
    
    while(player1->getCurrPos() != d->getBossRoom())
    {
        player1->checkRoom();
        cout << "Where do you want to go? [";
        if(player1->getCurrPos()->checkNorth())
        {
            cout << "north, ";
        }
        if(player1->getCurrPos()->checkWest())
        {
            cout << "west, ";
        }
        if(player1->getCurrPos()->checkEast())
        {
            cout << "east, ";
        }
        if(player1->getCurrPos()->checkSouth())
        {
            cout << "south, ";
        }
        cout << "]\n";
        string direction;
        cin >> direction;
        player1->moveRooms(direction);
        cout << "You find yourself in " << player1->getCurrPos()->getRoomName() << ".\n";
        player1->seeResident();
    }
        cout << "As you enter the room, the door disapears into the wall behind you.\n";
        cout << "A deep, rumbling voice echoes across the walls.\n";
        cout << "'I...SMELL...DINNER!!!'";
        cout << "Seconds later, your face is ripped off and eaten.\n";
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
        cout << "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀\n";
        cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼\n";
        cout << "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀\n";
        cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼\n";
        cout << "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄\n";
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
        cout << "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼\n";
        cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼\n";
        cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼\n";
        cout << "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼\n";
        cout << "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄\n";
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n";
    

}