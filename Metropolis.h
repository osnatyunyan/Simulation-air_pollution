
#ifndef HW3_METROPOLIS_H
#define HW3_METROPOLIS_H
#include "Junction.h"
#include <iostream>

using namespace std;

class Metropolis{
public:
    //    //No copy constructor and equal operator needed
    Metropolis (double** graph, unsigned int size);
    void setJunction(string *sJunction,double c);
    void update();
    static void printNum(double n);
    void print();
    virtual ~Metropolis();

private:
    Junction* junctions;
    unsigned int numOfCar;
    Car* cars;
    unsigned int sizeMet;
    double** metropolis;
};
#endif //HW3_METROPOLIS_H