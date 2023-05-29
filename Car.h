#ifndef __CAR_H__
#define __CAR_H__

#include <vector>
#include "VehicleBase.h"


class Car : public VehicleBase{
  private:
     int length;
     int start;
     int end;
     IntendedDirection intendedDirection;

   public:
     Car(VehicleType type, Direction originalDirection, IntendedDirection intendedDirection);
     Car(const Car& other); // copy constructor
     Car& operator=(const Car& other); // copy assignment
     Car(Car&& other)noexcept; // move constructor
     Car& operator=(Car&& other)noexcept; // move assignment

     ~Car();

     inline int getLength() const { return this->length; }
     inline int getStart() const { return this->start; }
     inline int getEnd() const { return this->end; }
     inline IntendedDirection getVehicleIntendedDirection() const { return this->intendedDirection; }

     void moveForward(vector<VehicleBase*> &road, int ticksTillRed);
     void moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2);
};

#endif
