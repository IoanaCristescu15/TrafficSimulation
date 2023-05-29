#ifndef __CARRANDOM_H__
#define __CARRANDOM_H__

#include <iostream>
#include <random>

class CarRandom
{
    private:
        std::mt19937 randomNumberGenerator; // Mersenne twister
        double threshold;
    public:
        CarRandom(int seed);
        ~CarRandom();

        bool genVehicle(double probability);
        int getVehicleDirection(double probRight, double probLeft);
        int getVehicleType(double probCar, double probSUV);
};

#endif
