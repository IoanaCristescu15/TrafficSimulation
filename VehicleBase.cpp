#ifndef __VEHICLE_BASE_CPP__
#define __VEHICLE_BASE_CPP__

#include "VehicleBase.h"

int VehicleBase::vehicleCount = 0;

// constructor
VehicleBase::VehicleBase(VehicleType type, Direction direction)
    : vehicleID(VehicleBase::vehicleCount++), 
      vehicleType(type),
      vehicleDirection(direction)
{}

//copy constructor
VehicleBase::VehicleBase(const VehicleBase& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection)
{}

// Copy Assignment
VehicleBase& VehicleBase::operator=(const VehicleBase& other){
    if (this == &other){
        return *this;
    }
    vehicleID = other.vehicleID;
    vehicleType = other.vehicleType;
    vehicleDirection = other.vehicleDirection;
    return *this;
}

// Move Constructor
VehicleBase::VehicleBase(VehicleBase&& other) noexcept 
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection){
          other.vehicleID = -1;
          other.vehicleType = VehicleType::noType;
          other.vehicleDirection = Direction::noDirection;
      }

// Move Assignment 
VehicleBase& VehicleBase::operator=(VehicleBase&& other) noexcept {
    if (this == &other){
        return *this;
    }
    vehicleID = other.vehicleID;
    vehicleType = other.vehicleType;
    vehicleDirection = other.vehicleDirection;
    other.vehicleID = -1;
    other.vehicleType = VehicleType::noType;
    other.vehicleDirection = Direction::noDirection;
    return *this;
}

VehicleBase::~VehicleBase() {}

void VehicleBase::moveForward(vector<VehicleBase*> &road, int ticksTillRed){}

void VehicleBase::moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2){}

IntendedDirection VehicleBase::getVehicleIntendedDirection() const { return IntendedDirection::noDirection; }

#endif
