
#ifndef HW3_SIMULATION_H
#define HW3_SIMULATION_H
#include <fstream>

using namespace std;

class Simulation{

public:
    //No copy builder and equal operator needed
    void readFile(char* graphMetv, char* sVehicle);
    void start(char* graphMetv, char* Vehicle);
    virtual ~Simulation();

private:
    unsigned int sizeMet;
    double c;
    unsigned int time;
    double **graph;
    string *sJunction;

};

#endif //HW3_SIMULATION_H
