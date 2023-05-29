#ifndef __CAR_CPP__
#define __CAR_CPP__

#include "Car.h"
#include <iostream>

// Constructor
Car::Car(VehicleType type, Direction originalDirection, IntendedDirection intendedDirection) 
    : VehicleBase(type, originalDirection){
    length = 2;
    start = 3;
    end = 2;
    this->intendedDirection = intendedDirection;
}

// Copy Constructor
Car::Car(const Car& other)
    : VehicleBase(other),
      length(other.length),
      start(other.start),
      end(other.end),
      intendedDirection(other.intendedDirection)
{}

// Copy Assignment 
Car& Car::operator=(const Car& other){
    if (this == &other){
        return *this;
    }
    (VehicleBase&)(*this) = other;
    //*this = other;
    length = other.length;
    start = other.start;
    end = other.end;
    intendedDirection = other.intendedDirection;
    return *this;
}

// Move Constructor
Car::Car(Car&& other) noexcept 
    : VehicleBase(other),
      length(other.length),
      start(other.start),
      end(other.end),
      intendedDirection(other.intendedDirection){
          other.length = -1;
          other.start = -1;
          other.end = -1;
          other.intendedDirection = IntendedDirection::noDirection;
      }

// Move Assignment 
Car& Car::operator=(Car&& other) noexcept {
    if (this == &other){
        return *this;
    }
    (VehicleBase&)(*this) = other;
    length = other.length;
    start = other.start;
    end = other.end;
    intendedDirection = other.intendedDirection;
    other.length = -1;
    other.start = -1;
    other.end = -1;
    other.intendedDirection = IntendedDirection::noDirection;
    return *this;
}

// Destructor 
Car::~Car() {}

// Move forward 1 step 
void Car::moveForward(vector<VehicleBase*> &road, int ticksTillRed){
    int numSections = (road.size() - 8)/2;
    if (start >= road.size()-4){
        road[start+1] = this;
        road[end] = nullptr; 
        start++;
        end++;
    }
    else if(road[start+1] == nullptr){
        if (start != numSections + 2){
            road[start+1] = this;
            road[end] = nullptr; 
            start++;
            end++;
        }
        else if(start == numSections + 2 and ticksTillRed > length){
            road[start+1] = this;
            road[end] = nullptr;
            start++;
            end++;
        }
    }
}

// Move between 2 lanes 
void Car::moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2){
    int numSections = (road1.size() - 8)/2;
    if (start == numSections + 3 and road2[numSections+5] == nullptr){
        road2[numSections+5] = this;
        road1[end] = nullptr;
        start = numSections + 5;
        end++;
    }
    else if(end == numSections + 3 and road2[start+1] == nullptr){
        road2[start+1] = this;
        road1[end] = nullptr;
        start++;
        end = numSections + 5;
    }
}


#endif