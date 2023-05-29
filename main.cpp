#include <exception>
#include <iostream>
#include <string>
#include "Simulation.h"

using namespace std;

int main(int argc, char *argv[]){
    int seed;
    // If there are more or less arguments than the names of the input and output files
    if (argc != 3)
    {
    // Give a useful usage message
        cout << argc << "\n";
        cerr << "Usage: " << argv[0] << " [input file]" << " seed" <<"\n";
        exit(1);
    }

    try{
        string stringSeed(argv[2]);
        string::size_type sz;
        seed = stoi(argv[2], &sz);

        // If the seed is invalid generat a message
        if (stringSeed.substr(sz) != "")
        {
            cerr<<"Invalid initial seed " <<argv[2]<<"\n"; 
            exit(1);
        }
    }
    catch (exception &err){
        // If the seed is invalid generat a message
        cerr<< "Invalid initial seed " <<argv[2]<<"\n";
        exit(1);
    }

    // If the arguments are correct create and run the simulation
    Simulation Simulation(argv[1], seed);
    Simulation.runSim();
    return 0;
}