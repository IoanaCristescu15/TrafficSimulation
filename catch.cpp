#define CATCH_CONFIG_MAIN


#include <iostream>
#include "catch.hpp"
#include "Simulation.h"
#include "CarRandom.h"
#include "Animator.h"
#include "Car.h"
#include "Suv.h"
#include "Truck.h"
#include "VehicleBase.h"


TEST_CASE("Car Variables") { // tests to ensure car variables are assigned correctly

  // new car object with type car, direction north, and intended direction straight
  Car *testCar = new Car(VehicleType::car, Direction::north, IntendedDirection::straight);

  SECTION(" vehicle type is 'car' ") {
    // is the vehicle still a car?
    REQUIRE(testCar->getVehicleType() == VehicleType::car);
  }
  SECTION(" vehicle direction is 'north' ") {
     // is the direction still north?
    REQUIRE(testCar->getVehicleOriginalDirection() == Direction::north);
  }
  SECTION(" vehicle intended direction is 'straight' ") {
    // is the intended direction still straight?
    REQUIRE(testCar->getVehicleIntendedDirection() == IntendedDirection::straight); //
  }
  SECTION(" vehicle length is '2' ") {
    // is the vehicle's length 2? (correct length of a car is 2)
    REQUIRE(testCar->getLength() == 2);
  }
  SECTION(" vehicle start is 3 ") {
    // is the front of the vehicle at the intended index?
    REQUIRE(testCar->getStart() == 3);
  }
  SECTION(" vehicle end is 2 ") {
    // is the back of the vehicle at the intended index?
    REQUIRE(testCar->getEnd() == 2);
  }
}

TEST_CASE("Car Movement"){ // tests to ensure a car move's correctly down a street

  Car *testCar2 = new Car(VehicleType::car, Direction::north, IntendedDirection::right);
  vector<VehicleBase*> road1(5 * 2 + 4, nullptr); // road (vector) size is 14, a range of [0-13]
  vector<VehicleBase*> road2(5 * 2 + 4, nullptr); //
  road1[2] = road1[3] = testCar2; // puts testCar2 on the road
  testCar2->moveForward(road1, 10); // testCar2 drives forward once...
  testCar2->moveForward(road1, 10); // testCar2 drives forward again...
  SECTION(" move forward (no impediment) ") {
    // testCar2 should now exist on road1 at index 4 and 5, and nowhere else
    REQUIRE(testCar2 == road1[4]);
    REQUIRE(testCar2 == road1[5]);
    REQUIRE(road1[2] == nullptr);
    REQUIRE(road1[3] == nullptr);
  }

  Car *testCar3 = new Car(VehicleType::car, Direction::north, IntendedDirection::straight);
  road1[2] = road1[3] = testCar3;
  testCar3->moveForward(road1, 10); // tries to move testCar3 forward
  SECTION(" move forward (vehicle impediment) ") {
    // testCar2 already exists at road1[4], so testCar3 should not have moved forward...
    REQUIRE(testCar2 == road1[4]);
    REQUIRE(road1[2] == testCar3);
    REQUIRE(road1[3] == testCar3);
  }

  testCar2->moveForward(road1, 10); // intersection at road1[6]
  testCar2->moveRight(road1, road2); // testCar2 should now be on both road1 and road2
  SECTION(" move right (part 1)"){
    // does testCar2 exist at the right indices?...
    REQUIRE(testCar2 == road2[8]);
    REQUIRE(testCar2 == road1[6]);
    REQUIRE(road1[5] == nullptr); // and not exist where it shouldn't?
  }

  testCar2->moveRight(road1, road2); // should complete the right turn, testCar2 should be on road2
  SECTION(" move right (part 2)"){
    // same kind of checks as part 1
    REQUIRE(testCar2 == road2[9]);
    REQUIRE(testCar2 == road2[8]);
    REQUIRE(road1[6] == nullptr);
  }

  testCar3->moveForward(road1, 3); //road1[4]
  testCar3->moveForward(road1, 2); //road1[5]
  testCar3->moveForward(road1, 1); //should stay at road1[5]
  testCar3->moveForward(road1, 1); //should stay at road1[5]
  testCar3->moveForward(road1, 1); //should stay at road1[5]
  SECTION(" move forward (light impediment) "){
    // did it stay where it is supposed to?
    REQUIRE(road1[5] == testCar3);
    REQUIRE(road1[4] == testCar3);
  }
}

TEST_CASE("Random Generator"){
  CarRandom rng = CarRandom(400);
  SECTION(" vehicle generation probability "){
    // are proper bool values returned for the most extreme probabilities?
    REQUIRE(rng.genVehicle(1) == true);
    REQUIRE(rng.genVehicle(0) == false);
  }

  // below code runs 1000 iterations of finding a vehicle's direction
  // and averages the number of returns for each category (left, right, straight)
  double rightAVG = 0.0;
  double leftAVG = 0.0;
  double strAVG = 0.0;
  for (int i = 0; i < 1000; i++){
    double beep = rng.getVehicleDirection(0.30, 0.30);
    if (beep == 1) rightAVG += 1;
    if (beep == 2) leftAVG += 1;
    if (beep == 3) strAVG += 1;
  }
  rightAVG = rightAVG/1000;
  leftAVG = leftAVG/1000;
  strAVG = strAVG/1000;
  SECTION(" vehicle generation probability "){
    // are vehicle directions generated closely to their assigned probabilities over the 1000 iterations?
    REQUIRE(abs(rightAVG - 0.30) <= 0.10);
    REQUIRE(abs(leftAVG - 0.30) <= 0.10);
    REQUIRE(abs(strAVG - 0.40) <= 0.10);
  }
}
