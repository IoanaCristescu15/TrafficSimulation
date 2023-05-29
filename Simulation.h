#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include <iostream>
#include <fstream>
#include <vector>
#include "CarRandom.h"
#include "Animator.h"
#include "Car.h"
#include "Suv.h"
#include "Truck.h"
#include "VehicleBase.h"

using namespace std;

class Simulation{
    private:
        int seed;
        int maximum_simulated_time;
        int halfSize;
        int green_north_south;
        int yellow_north_south;
        int green_east_west;
        int yellow_east_west;
        double prob_new_vehicle_southbound;
        double prob_new_vehicle_northbound;
        double prob_new_vehicle_eastbound;
        double prob_new_vehicle_westbound;
        double proportion_of_cars; 
        double proportion_of_SUVs; 
        double proportion_right_turn_cars;
        double proportion_left_turn_cars;
        double proportion_right_turn_SUVs;
        double proportion_left_turn_SUVs;
        double proportion_right_turn_trucks;
        double proportion_left_turn_trucks;
        CarRandom random = CarRandom(0);

        void parseInput(string fileName);
        void generateVehiclesNorthBound(vector<VehicleBase*> &northbound);
        void generateVehiclesEastBound(vector<VehicleBase*> &eastbound);
        void generateVehiclesSouthBound(vector<VehicleBase*> &southbound);
        void generateVehiclesWestBound(vector<VehicleBase*> &westbound);
        void updatePositionSecondHalf(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2, int ticksTillRed);
        void updatePositionIntersection(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2, int ticksTillRed);
        void updatePositionFirstHalf(vector<VehicleBase*> &road, int ticksTillRed);
        
    public:
        Simulation(string fileName, int seed);
        ~Simulation();

        void runSim();
};

#endif