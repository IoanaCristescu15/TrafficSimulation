#ifndef __TRUCK_H__
#define __TRUCK_H__

#include <vector>
#include "VehicleBase.h"


class Truck : public VehicleBase{
  private:
     int length;
     int start;
     int end;
     IntendedDirection intendedDirection;

   public:
     Truck(VehicleType type, Direction originalDirection, IntendedDirection intendedDirection);
     Truck(const Truck& other); // copy constructor
     Truck& operator=(const Truck& other); // copy assignment
     Truck(Truck&& other)noexcept; // move constructor
     Truck& operator=(Truck&& other)noexcept; // move assignment

     ~Truck();

     inline int getLength() const { return this->length; }
     inline int getStart() const { return this->start; }
     inline int getEnd() const { return this->end; }
     inline IntendedDirection getVehicleIntendedDirection() const { return this->intendedDirection; }

     void moveForward(vector<VehicleBase*> &road, int ticksTillRed);
     void moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2);
};

#endif
