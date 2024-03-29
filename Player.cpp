#include "Player.hpp"

Player::Player(string playerName, Room* Entrance)
{
    this->playerName = playerName;
    this->currPos = Entrance;
}

string Player::getPlayerName()
{
    return this->playerName;
}

void Player::checkRoom()
{
    cout << "You look around for some sort of door.\n";
    cout << "There is hope to the ";
    if(this->currPos->checkNorth())
    {
        cout << "north, ";
    }
    if(this->currPos->checkEast())
    {
        cout << "east, ";
    }
    if(this->currPos->checkWest())
    {
        cout << "west, ";
    }
    if(this->currPos->checkSouth())
    {
        cout << "south";
    }
    if(!this->currPos->checkNorth() && !this->currPos->checkSouth() && !this->currPos->checkWest() && !this->currPos->checkEast())
    {
        cout << "You see no way out. You were trapped and died of starvation. It was miserable.\n";
    }
    cout << ".\n";
}

void Player::moveRooms(string direction)
{
    if(direction == "north" || direction == "North")
    {
        cout << "You decide to take the door to your North.\n\n";
        if(this->currPos->checkNorth())
        {
        this->currPos = this->currPos->getNorthRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
        
    }
    else if(direction == "east" || direction == "East")
    {
        cout << "You decide to take the door to your East.\n\n";
        if(this->currPos->checkEast())
        {
        this->currPos = this->currPos->getEastRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
    }
    else if(direction == "west" || direction == "West")
    {
        cout << "You decide to take the door to your West.\n\n";
        if(this->currPos->checkWest())
        {
        this->currPos = this->currPos->getWestRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
    }
    else if(direction == "south" || direction == "South")
    {
        cout << "Your cowardice overtakes you, so you go backwards.\n\n";
        if(this->currPos->checkSouth())
        {
        this->currPos = this->currPos->getSouthRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
    }
    else
    {
        cout << "Your stupidity overwhelms you and fail to make a decision.\n\n";
    }
    

}

Room* Player::getCurrPos()
{
    return this->currPos;
}

void Player::seeResident()
{
    if(this->getCurrPos()->getResident() == "skeleton")
    {
        cout << "You notice there is a pile of bones in the corner of the room. Strange, they look human...\n";
    }
    else if(this->getCurrPos()->getResident() == "rotting flesh")
    {
        cout << "You gag as you enter the room. There is a pile of rotting flesh in the center of the room.\n";
    }
    else if(this->getCurrPos()->getResident() == "danger")
    {
        cout << "You feel an evil presence watching you...\n";
    }
    else
    {
        cout << "Doesn't look like there is anything interesting in here. Better get moving.\n";
    }
    
}