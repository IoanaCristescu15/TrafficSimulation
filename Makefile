#THIS IS THE TESTING MAKEFILE

EXECS = main catch 
OBJS = Animator.o Car.o CarRandom.o Simulation.o Suv.o Truck.o VehicleBase.o 
HFILES = Simulation.h CarRandom.h Animator.h VehicleBase.h Car.h Suv.h Truck.h
CPPFILES = Simulation.cpp CarRandom.cpp Animator.cpp VehicleBase.cpp Car.cpp Suv.cpp Truck.cpp

#### use next two lines for Mac
#CC = clang++
#CCFLAGS	 = -std=gnu++2a -stdlib=libc++

#### use next two lines for mathcs* machines:
CC = g++
CCFLAGS = -std=c++17

all: $(EXECS)

catch: $(OBJS) catch.o
	$(CC) $(CCFLAGS) $^ -o $@

main: $(OBJS) main.o
	$(CC) $(CCFLAGS) $^ -o $@

catch.o: catch.cpp $(CPPFILES) catch.hpp $(HFILES)
	$(CC) $(CCFLAGS) -c catch.cpp $(CPPFILES)

main.o: main.cpp $(CPPFILES) $(HFILES)
	$(CC) $(CCFLAGS) -c main.cpp $(CPPFILES)

Simulation.o: $(CPPFILES) $(HFILES)
	$(CC) $(CCFLAGS) -c $(CPPFILES)

Animator.o: Animator.cpp VehicleBase.cpp Animator.h VehicleBase.h
	$(CC) $(CCFLAGS) -c Animator.cpp VehicleBase.cpp

Car.o: Car.cpp VehicleBase.cpp Car.h 
	$(CC) $(CCFLAGS) -c Car.cpp VehicleBase.cpp

Suv.o: Suv.cpp VehicleBase.cpp Suv.h 
	$(CC) $(CCFLAGS) -c Suv.cpp VehicleBase.cpp

Truck.o: Truck.cpp VehicleBase.cpp Truck.h 
	$(CC) $(CCFLAGS) -c Truck.cpp VehicleBase.cpp

VehicleBase.o: VehicleBase.cpp VehicleBase.h
	$(CC) $(CCFLAGS) -c VehicleBase.cpp 

CarRandom.o: CarRandom.cpp CarRandom.h
	$(CC) $(CCFLAGS) -c CarRandom.cpp 

clean:
	/bin/rm -f a.out $(OBJS) main.o catch.o $(EXECS)
