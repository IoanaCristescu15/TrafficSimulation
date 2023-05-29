#ifndef __CARRANDOM_CPP__
#define __CARRANDOM_CPP__

#include <iostream>
#include <random>
#include "CarRandom.h"

using namespace std;

//Constructor
CarRandom::CarRandom(int seed){
    this->randomNumberGenerator.seed(seed); //Chooses seed for RNG

    this->threshold = .0001;
}

//Destructor
CarRandom::~CarRandom() {}

//Method that randomly decides if a car should be generated 
//given the probability that it should be generated
bool CarRandom::genVehicle(double probability){
    std::uniform_real_distribution<double> rand_double(0,1);
    double randNum = rand_double(randomNumberGenerator);

//if the randomly generated number is between 0 and probability, it will return true
    if((0 <= randNum) && (randNum < probability)){ 
        return true;
    } else{
        return false;
    }
}

//method that randomly decides if a car should turn right, given a probability
int CarRandom::getVehicleDirection(double probRight, double probLeft){
    std::uniform_real_distribution<double> rand_double(0,1);
    double randNum = rand_double(randomNumberGenerator);

//if the randomly generated number is between 0 and probRight, the vehicle will turn right
    if((0 <= randNum) && (randNum < probRight)){
        return 1;
//if the randomly generated number is between 0 and probRight, the vehicle will turn left
    } else if((probRight <= randNum) && (randNum < (probRight + probLeft))){
        return 2;
//if the randomly generated number is between 0 and probRight, the vehicle will go straight
    }else{
        return 3;
    }
}

//given three probabilities, one for each vehicle type. This method will randomly
//choose one to be generated 
int CarRandom::getVehicleType(double probCar, double probSUV){
    std::uniform_real_distribution<double> rand_double(0,1);
    double randNum = rand_double(randomNumberGenerator);

//if randomly generated number is between 0 and probCar, a car should be generate
    if((0 <= randNum) && (randNum < probCar)){
        return 1;
//if randomly generated number is between probCar and probCar+probSUV an SUV should be generated
    } else if((probCar <= randNum) && (randNum < (probCar + probSUV))){
        return 2;
//else a truck should be generated
    } else{
        return 3;
    }
}


#endif
