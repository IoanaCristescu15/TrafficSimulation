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
Traffic Simulation is an animated simulation of a four-way street intersection.
The visuals of the simulation include: road lanes (northbound, southbound, eastbound, westbound), vehicles (cars, SUVs, and trucks), traffic lights (4 independent stationary blocks that change color), a display of the number of time ticks that have passed. <br />
When the program is ran, with each tick of time, vehicles on the road are expected to behave similarly to normal traffic-- they are meant to stop in time for red lights, approach red lights if they have space remaining before the intersection, continue driving after an intersection (where they should no longer worry about the lights), turn or continue straight, and, lastly, never crash.
