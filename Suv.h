#ifndef __SUV_H__
#define __SUV_H__

#include <vector>
#include "VehicleBase.h"


class Suv : public VehicleBase{
  private:
     int length;
     int start;
     int end;
     IntendedDirection intendedDirection;

   public:
     Suv(VehicleType type, Direction originalDirection, IntendedDirection intendedDirection);
     Suv(const Suv& other); // copy constructor
     Suv& operator=(const Suv& other); // copy assignment
     Suv(Suv&& other)noexcept; // move constructor
     Suv& operator=(Suv&& other)noexcept; // move assignment

     ~Suv();

     inline int getLength() const { return this->length; }
     inline int getStart() const { return this->start; }
     inline int getEnd() const { return this->end; }
     inline IntendedDirection getVehicleIntendedDirection() const { return this->intendedDirection; }

     void moveForward(vector<VehicleBase*> &road, int ticksTillRed);
     void moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2);
};

#endif
