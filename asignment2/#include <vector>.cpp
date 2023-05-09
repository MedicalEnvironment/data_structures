#include <vector>
#include <string>
#include <iostream>

// Enumerations for room and building types
enum RoomType {
    BEDROOM,
    KITCHEN,
    BATHROOM,
    NURSERY,
    LIVINGROOM
};

enum BuildingType {
    RESIDENTIAL,
    GARAGE,
    BARN,
    BATHHOUSE
};

// Room structure
struct Room {
    RoomType type;
    double area;
};

// Floor structure
struct Floor {
    std::vector<Room> rooms;
    double ceilingHeight;
    bool hasStove;
};

// Building structure
struct Building {
    BuildingType type;
    double area;
    std::vector<Floor> floors;
};

// Plot structure
struct Plot {
    int number;
    std::vector<Building> buildings;
};

// Village structure
struct Village {
    std::vector<Plot> plots;
    double totalArea;
};

int main() {
    // Create a village
    Village myVillage;
    myVillage.totalArea = 1000;  // in sq. m

    // Create a plot
    Plot myPlot;
    myPlot.number = 1;

    // Create a building
    Building myBuilding;
    myBuilding.type = RESIDENTIAL;
    myBuilding.area = 100;  // in sq. m

    // Create a floor
    Floor myFloor;
    myFloor.ceilingHeight = 2.5;  // in m
    myFloor.hasStove = true;

    // Create rooms
    Room myRoom1;
    myRoom1.type = BEDROOM;
    myRoom1.area = 20;  // in sq. m

    Room myRoom2;
    myRoom2.type = KITCHEN;
    myRoom2.area = 15;  // in sq. m

    // Add rooms to floor
    myFloor.rooms.push_back(myRoom1);
    myFloor.rooms.push_back(myRoom2);

    // Add floor to building
    myBuilding.floors.push_back(myFloor);

    // Add building to plot
    myPlot.buildings.push_back(myBuilding);

    // Add plot to village
    myVillage.plots.push_back(myPlot);

    // Display a simple message to show that the village has been created
    std::cout << "The village has been created!" << std::endl;

    return 0;
}
