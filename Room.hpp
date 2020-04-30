#include "Door.hpp"
#include <string>

using namespace std;

class Room
{
    private:
        Door* NorthDoor;
        Door* EastDoor;
        Door* WestDoor;
        Door* SouthDoor;
        Room* NorthRoom;
        Room* EastRoom;
        Room* WestRoom;
        Room* SouthRoom;
        string RoomName;
        string resident;

    public:
        Room(string name, string resident);
        Room* addRoom(int direction, string RoomName, string resident);    
        //direction tells you which cardinal direction you 
        //add the door to(N or S, E or W)
        void addDoorEW(Room* eastRoom,Room* westRoom);
        void addDoorNS(Room* northRoom,Room* southRoom);

        string getRoomName();
        string getResident();

        bool checkNorth();
        bool checkSouth();
        bool checkEast();
        bool checkWest();

        Room* getNorthRoom();
        Room* getSouthRoom();
        Room* getWestRoom();
        Room* getEastRoom();

};