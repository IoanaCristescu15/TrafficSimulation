#ifndef __SIMULATION_CPP__
#define __SIMULATION_CPP__

#include "Simulation.h"
using namespace std;

//Constructor
Simulation::Simulation(string fileName, int seed){
    this->seed = seed;
    random = CarRandom(seed);
    parseInput(fileName);
}

//Destructor
Simulation::~Simulation() {}

// Read the input file helper method
void Simulation::parseInput(string fileName){
    std::ifstream inFile;
    inFile.open(fileName);

    string property;
    string value;
    vector<string> properties; 
    vector<string> values; 

    while(inFile >> property >> value){
        properties.push_back(property.erase());
        values.push_back(value);
    }
    
    maximum_simulated_time = stoi(values[0]);
    halfSize = stoi(values[1]);
    green_north_south = stoi(values[2]);
    yellow_north_south = stoi(values[3]);
    green_east_west = stoi(values[4]);
    yellow_east_west = stoi(values[5]);
    prob_new_vehicle_northbound = stof(values[6]);
    prob_new_vehicle_southbound = stof(values[7]);
    prob_new_vehicle_eastbound = stof(values[8]);
    prob_new_vehicle_westbound = stof(values[9]);
    proportion_of_cars = stof(values[10]); 
    proportion_of_SUVs = stof(values[11]); 
    proportion_right_turn_cars = stof(values[12]);
    proportion_left_turn_cars = stof(values[13]);
    proportion_right_turn_SUVs = stof(values[14]);
    proportion_left_turn_SUVs = stof(values[15]);
    proportion_right_turn_trucks = stof(values[16]);
    proportion_left_turn_trucks = stof(values[17]);
} 

// New vehicles get generated on the north lane - helper method
void Simulation::generateVehiclesNorthBound(vector<VehicleBase*> &northbound){
    IntendedDirection direction = IntendedDirection::straight;  
    // The random generator decides if a new vehicles gets generated 
    // and then it gets generated if there is an empty spot
    if (random.genVehicle(prob_new_vehicle_northbound) == true and northbound[3] == nullptr){
            // A car is generated
            if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==1){
                // The car turns right
                if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 3){
                    direction = IntendedDirection::straight;
                }
                Car *newCar = new Car(VehicleType::car, Direction::north, direction);
                northbound[2] = northbound[3] = newCar;
            }

            // A SUV is generated
            else if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==2){
                // The SUV turns right
                if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 1){
                    direction = IntendedDirection::right;
                }
                // The SUV goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 3){
                    direction = IntendedDirection::straight;
                }
                Suv *newSuv = new Suv(VehicleType::suv, Direction::north, direction);
                northbound[1] = northbound[2] = northbound[3] = newSuv;
            }

            // A truck is generated 
            else{
                // The truck turns right
                if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 3){
                    direction = IntendedDirection::straight;
                }
                Truck *newTruck = new Truck(VehicleType::truck, Direction::north, direction);
                northbound[0] = northbound[1] = northbound[2] = northbound[3] = newTruck;
            }
        }
}

// New vehicles get generated on the east lane - helper method
void Simulation::generateVehiclesEastBound(vector<VehicleBase*> &eastbound){
    IntendedDirection direction = IntendedDirection::straight;
    // The random generator deciides if a new vehicles gets generated and 
    // then it gets generated if there is an empty spot
    if (random.genVehicle(prob_new_vehicle_eastbound) == true and eastbound[3] == nullptr){
            // A car is generated
            if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==1){
                // The car turns right
                if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 3){
                    direction = IntendedDirection::straight;
                }
                Car *newCar = new Car(VehicleType::car, Direction::east, direction);
                eastbound[2] = eastbound[3] = newCar;
            }

            // A SUV is generated
            else if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==2){
                // The SUV turns right
                if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 1){
                    direction = IntendedDirection::right;
                }
                // The SUV goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 3){
                    direction = IntendedDirection::straight;
                }
                Suv *newSuv = new Suv(VehicleType::suv, Direction::east, direction);
                eastbound[1] = eastbound[2] = eastbound[3] = newSuv;
            }

            // A truck is generated 
            else{
                // The truck turns right
                if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 3){
                    direction = IntendedDirection::straight;
                }
                Truck *newTruck = new Truck(VehicleType::truck, Direction::east, direction);
                eastbound[0] = eastbound[1] = eastbound[2] = eastbound[3] = newTruck;
            }
        }
}

// New vehicles get generated on the south lane - helper method
void Simulation::generateVehiclesSouthBound(vector<VehicleBase*> &southbound){
    IntendedDirection direction = IntendedDirection::straight;
    // The random generator decides if a new vehicles gets generated 
    // and then it gets generated if there is an empty spot
    if (random.genVehicle(prob_new_vehicle_southbound) == true and southbound[3] == nullptr){
            // A car is generated
            if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==1){
                // The car turns right
                if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 3){
                    direction = IntendedDirection::straight;
                }
                Car *newCar = new Car(VehicleType::car, Direction::south, direction);
                southbound[2] = southbound[3] = newCar;
            }

            // A SUV is generated
            else if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==2){
                // The SUV turns right
                if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 1){
                    direction = IntendedDirection::right;
                }
                // The SUV goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 3){
                    direction = IntendedDirection::straight;
                }
                Suv *newSuv = new Suv(VehicleType::suv, Direction::south, direction);
                southbound[1] = southbound[2] = southbound[3] = newSuv;
            }

            // A truck is generated 
            else{
                // The truck turns right
                if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 3){
                   direction = IntendedDirection::straight;
                }
                Truck *newTruck = new Truck(VehicleType::truck, Direction::south, direction);
                southbound[0] = southbound[1] = southbound[2] = southbound[3] = newTruck;
            }
        }
}

// New vehicles get generated on the west lane - helper method
void Simulation::generateVehiclesWestBound(vector<VehicleBase*> &westbound){
    IntendedDirection direction = IntendedDirection::straight;
    // The random generator deciides if a new vehicles gets generated 
    // and then it gets generated if there is an empty spot
    if (random.genVehicle(prob_new_vehicle_westbound) == true and westbound[3] == nullptr){
            // A car is generated
            if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==1){
                // The car turns right
                if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_cars, proportion_left_turn_cars) == 3){
                    direction = IntendedDirection::straight;
                }
                Car *newCar = new Car(VehicleType::car, Direction::west, direction);
                westbound[2] = westbound[3] = newCar;
            }

            // A SUV is generated
            else if (random.getVehicleType(proportion_of_cars, proportion_of_SUVs)==2){
                // The SUV turns right
                if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 1){
                    direction = IntendedDirection::right;
                }
                // The SUV goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_SUVs, proportion_left_turn_SUVs) == 3){
                    direction = IntendedDirection::straight;
                }
                Suv *newSuv = new Suv(VehicleType::suv, Direction::west, direction);
                westbound[1] = westbound[2] = westbound[3] = newSuv;
            }

            // A truck is generated 
            else{
                // The truck turns right
                if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 1){
                    direction = IntendedDirection::right;
                }
                // The car goes straight 
                else if (random.getVehicleDirection(proportion_right_turn_trucks, proportion_left_turn_trucks) == 3){
                    direction = IntendedDirection::straight;
                }
                Truck *newTruck = new Truck(VehicleType::truck, Direction::west, direction);
                westbound[0] = westbound[1] = westbound[2] = westbound[3] = newTruck;
            }
        }
}

// Update the position of the vehicles found in the second half of the road or second space of the intersection
// Helper method
void Simulation::updatePositionSecondHalf(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2, int ticksTillRed){
    for (int i = road1.size() - 4; i >= halfSize + 4; i--){
        if (road1[i] != nullptr)
        {   
            // Vehicle found at the last space available on the road moves forward
            if (i == road1.size() - 4){
                (*road1[i]).moveForward(road1, ticksTillRed);
            }
            // Vehicle found to any other position and that has an empty space in front of it
            else if(road1[i+1] == nullptr){
                if ((*road1[i]).getVehicleIntendedDirection() == IntendedDirection::right){
                    if (road2[halfSize+3] != nullptr){
                        // Vehicle moving to the right from road2 to road1 if the vehicle is still in intersection
                        if ((*road1[i]).getVehicleID() == (*road2[halfSize+3]).getVehicleID()){
                            (*road1[i]).moveRight(road2, road1);
                        }
                        // Vehicle that was moving right is out of the intersection and now is moving forward
                        // There is another vehicle in the road2[halfsize+3] position
                        else{
                            (*road1[i]).moveForward(road1, ticksTillRed);
                        }
                    }
                    // Vehicle moves forward if it's out of the intersection
                    // There is no another vehicle in the road2[halfsize+3] position
                    else{
                        (*road1[i]).moveForward(road1, ticksTillRed);
                    }
                }
                // Vehicle that moves forward
                else if((*road1[i]).getVehicleIntendedDirection() == IntendedDirection::straight) {
                    (*road1[i]).moveForward(road1, ticksTillRed);
                }
            }
        }
    }
}

// Update the position of the vehicle found in the first space of the intersection depending on if it's going 
// straight or to the right
// Helper method
void Simulation::updatePositionIntersection(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2, int ticksTillRed){
    if (road1[halfSize+3] != nullptr){
        // Vehicle moves forward
        if ((*road1[halfSize+3]).getVehicleIntendedDirection() == IntendedDirection::straight and road1[halfSize+4] == nullptr){
            (*road1[halfSize+3]).moveForward(road1, ticksTillRed);
        }
        //Vehicle moves to the right
        else if((*road1[halfSize+3]).getVehicleIntendedDirection() == IntendedDirection::right and road2[halfSize+5] == nullptr){
            (*road1[halfSize+3]).moveRight(road1, road2);
        }
    }
}

// Update the position of the vehicles found in the first half of the road 
// Helper method
void Simulation::updatePositionFirstHalf(vector<VehicleBase*> &road, int ticksTillRed){
    for(int i = halfSize + 2; i >= 3; i--){
        if(road[i] != nullptr and road[i+1] == nullptr){
            (*road[i]).moveForward(road, ticksTillRed);
        }
    }
}


void Simulation::runSim(){
    // Vehicles will be displayed with three digits
    Animator::MAX_VEHICLE_COUNT = 999; 
    Animator anim(halfSize);
    //CarRandom random(seed);

    // Construct vectors of VehicleBase* of appropriate size + 6, init to nullptr
    // 3 dummy locations at the beginning and end of each vector
    vector<VehicleBase*> northbound(halfSize * 2 + 8, nullptr);
    vector<VehicleBase*> eastbound(halfSize * 2 + 8, nullptr);
    vector<VehicleBase*> southbound(halfSize * 2 + 8, nullptr);
    vector<VehicleBase*> westbound(halfSize * 2 + 8, nullptr);

    char dummy;

    // Set up initial lights 
    anim.setLightNorthSouth(LightColor::green);
    anim.setLightEastWest(LightColor::red);

    int ticksTillRedNS = green_north_south + yellow_north_south;
    int ticksTillRedEW = 0;
    bool checkNS = true; // check if the lights for North/South are not red

    for (int i=0; i<maximum_simulated_time; i++){
        // Create temporary vectors of appropiate size to be able to animate
        vector<VehicleBase*> nb(northbound.begin() + 3, northbound.end() - 3); // north bound
        vector<VehicleBase*> eb(eastbound.begin() + 3, eastbound.end() - 3); // east bound
        vector<VehicleBase*> sb(southbound.begin() + 3, southbound.end() - 3); // south bound
        vector<VehicleBase*> wb(westbound.begin() + 3, westbound.end() - 3); // west bound

        // Animate 
        anim.setVehiclesNorthbound(nb);
        anim.setVehiclesEastbound(eb);
        anim.setVehiclesSouthbound(sb);
        anim.setVehiclesWestbound(wb);

        anim.draw(i);
        cin.get(dummy);

        // Update ticks for the next step
        if (checkNS == true){
            ticksTillRedNS--;
        }
        else{
            ticksTillRedEW--;
        } 

        // Update lights to yellow if necessary
        // If North - South is green and East - West is red
        if (ticksTillRedNS  == yellow_north_south and yellow_north_south != 0){
            anim.setLightNorthSouth(LightColor::yellow);
        }
        // If East - West is green and North - South is red
        else if(ticksTillRedEW  == yellow_east_west and yellow_east_west != 0){
            anim.setLightEastWest(LightColor::yellow);
        }
        // Update lights to green and red if necessary and update ticksTillRed for the lane that turns green
        else if (ticksTillRedEW == 0 and ticksTillRedNS == 0){
            if (checkNS == true){
                anim.setLightNorthSouth(LightColor::red);
                anim.setLightEastWest(LightColor::green);
                checkNS = false;
                ticksTillRedEW = green_east_west + yellow_east_west;
                ticksTillRedNS = 0;
            }
            else{
                anim.setLightNorthSouth(LightColor::green);
                anim.setLightEastWest(LightColor::red);
                checkNS = true;
                ticksTillRedNS = green_north_south + yellow_north_south;
                ticksTillRedEW = 0;
            }
        }

        // Update positions of vehicles for the next tick
        // Part after the intersection and the second space in the intersection
        updatePositionSecondHalf(northbound, westbound, ticksTillRedNS);
        updatePositionSecondHalf(eastbound, northbound, ticksTillRedEW);
        updatePositionSecondHalf(southbound, eastbound, ticksTillRedNS);
        updatePositionSecondHalf(westbound, southbound, ticksTillRedEW);

        // First position in the intersection 
        updatePositionIntersection(northbound, eastbound, ticksTillRedNS);
        updatePositionIntersection(eastbound, southbound, ticksTillRedEW);
        updatePositionIntersection(southbound, westbound, ticksTillRedNS);
        updatePositionIntersection(westbound, northbound, ticksTillRedEW);

        // Part before the intersection 
        updatePositionFirstHalf(northbound, ticksTillRedNS);
        updatePositionFirstHalf(eastbound, ticksTillRedEW);
        updatePositionFirstHalf(southbound, ticksTillRedNS);
        updatePositionFirstHalf(westbound, ticksTillRedEW);


        // New vehicles get generated
        generateVehiclesNorthBound(northbound);
        generateVehiclesEastBound(eastbound);
        generateVehiclesSouthBound(southbound);
        generateVehiclesWestBound(westbound);
    }
}

#endif