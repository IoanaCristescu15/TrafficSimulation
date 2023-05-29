#ifndef __TRUCK_CPP__
#define __TRUCK_CPP__

#include "Truck.h"

// Constructor
Truck::Truck(VehicleType type, Direction originalDirection, IntendedDirection intendedDirection) 
    : VehicleBase(type, originalDirection){
    length = 4;
    start = 3;
    end = 0;
    this->intendedDirection = intendedDirection;
}

// Copy Constructor
Truck::Truck(const Truck& other)
    : VehicleBase(other),
      length(other.length),
      start(other.start),
      end(other.end),
      intendedDirection(other.intendedDirection)
{}

// Copy Assignment 
Truck& Truck::operator=(const Truck& other){
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
Truck::Truck(Truck&& other) noexcept 
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
Truck& Truck::operator=(Truck&& other) noexcept {
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
Truck::~Truck() {}

// Move forward 1 step 
void Truck::moveForward(vector<VehicleBase*> &road, int ticksTillRed){
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
void Truck::moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2){
    int numSections = (road1.size() - 8)/2;
    if (start == numSections + 3 and road2[numSections+5] == nullptr){
        road2[numSections+5] = this;
        road1[end] = nullptr;
        start = numSections + 5;
        end++;
    }
    else if(end == numSections + 1 and road2[start+1] == nullptr){
        road2[start+1] = this;
        road1[end] = nullptr;
        start++;
        end++;
    }
    else if(end == numSections + 2 and road2[start+1] == nullptr){
        road2[start+1] = this;
        road1[end] = nullptr;
        start++;
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