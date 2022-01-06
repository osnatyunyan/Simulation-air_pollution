
#include "Simulation.h"

int main(int argc,char * argv[]) {
    char* graphMet = argv[1];
    char* sVehicle = argv[2];
    Simulation simulation; //Using a default constructor
    simulation.start(graphMet,sVehicle);
    return 0;
}