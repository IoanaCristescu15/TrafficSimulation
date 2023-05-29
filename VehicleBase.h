#ifndef __VEHICLE_BASE_H__
#define __VEHICLE_BASE_H__

#include <sstream>
#include <vector>
using namespace std;

// enum: see http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-enum
enum class Direction   {north, south, east, west, noDirection};
enum class VehicleType {car, suv, truck, noType};
enum class LightColor  {green, yellow, red, noColor};
enum class IntendedDirection {right, left, straight, noDirection};

class VehicleBase{
   public:
      static int vehicleCount;

   private:
      int         vehicleID;
      VehicleType vehicleType;
      Direction   vehicleDirection;

   public:
      VehicleBase(VehicleType type, Direction originalDirection); //constructor
      VehicleBase(const VehicleBase& other); //copy constructor
      VehicleBase& operator=(const VehicleBase& other); // copy assignmnet 
      VehicleBase(VehicleBase&& other)noexcept; // move constructor 
      VehicleBase& operator=(VehicleBase&& other)noexcept; // move assignment 

      ~VehicleBase();

      inline int getVehicleID() const { return this->vehicleID; }
      inline VehicleType getVehicleType() const { return this->vehicleType; }
      inline Direction   getVehicleOriginalDirection() const { return this->vehicleDirection; }
      virtual IntendedDirection getVehicleIntendedDirection() const;

      virtual void moveForward(vector<VehicleBase*> &road, int ticksTillRed);
      virtual void moveRight(vector<VehicleBase*> &road1, vector<VehicleBase*> &road2);

};

#endif
