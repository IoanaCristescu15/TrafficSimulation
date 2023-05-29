# TrafficSimulation
Authors: Ioana Cristescu, Kevorc Ibrahimian, Alex Shaw, and Liz Smith

## Directions for compiling:
To compile the program use the Makefile provided, type: make <br /> <br />
To run executable: ./main [input_file] [seed] <br />
&emsp;- first argument: txt file containing the inputs for the program <br />
&emsp;- second argument: random generation seed <br />
&emsp;- Example: ./main input_text.txt 1893430940 <br /> <br />
To build and run the test: type make and ./catch 

## Design Decisions:
### Front End:
#### Animator
Traffic Simulation is an animated simulation of a four-way street intersection. <br />
Animator is a class that displays the visuals of the simulation: road lanes (northbound, southbound, eastbound, westbound), vehicles (cars, SUVs, and trucks), traffic lights (4 independent stationary blocks that change color), a display of the number of time ticks that have passed. <br />
When the program is ran, with each tick of time, vehicles on the road are expected to behave similarly to normal traffic-- they are meant to stop in time for red lights, approach red lights if they have space remaining before the intersection, continue driving after an intersection (where they should no longer worry about the lights), turn or continue straight, and, lastly, never crash.

### Back End:
#### CarRandom
CarRadom is a random generator class that decides the type of vehicle, when it shows up on the road and its movement.  <br />
&emsp;- randomly decides if a vehicle should be generated (given the probability)
&emsp;- randomly decides if a vehicle should turn right (given probability to turn right and probability to turn left)
&emsp;- randomly decides the type of vehicle (given probability to be a car and probability to be an SUV)

#### VehicleBase
Car, Suv, and Truck are subclasses of the parent class VehicleBase which handle the movement of each type of vehicle (move forward or turn right).

#### Simulation
Simulation is a class that includes all the classes; it runs and animates the simulation. It reads the input file in the constructor. It creates instances of all needed classes and has an integer clock to step through the simulation in runSim() method. With every iteration it generates new vehicles for eacch lane, asks vehicles to move and also handles the deletion of all vehicles when they exit their lane.
