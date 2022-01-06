
#ifndef HW3_JUNCTION_H
#define HW3_JUNCTION_H
#include "Car.h"
#include "Road.h"

class Junction{

public:
    //No copy constructor and equal operator needed
    Junction();
    explicit Junction(unsigned int size);
    void addNewCar(Car& newCar);
    void removeCar(Car& removeCar);
    void setRoad(unsigned int  from, unsigned int  to,unsigned int  index, double length,double c);
    Road& getRoad(unsigned int  from, unsigned int  to);
    void setArrayRoad();
    void setNeighbors(unsigned int n, unsigned int index);
    unsigned int& getNeighbors(unsigned int index);
    void setNumNeighbors(unsigned int counter);
    unsigned int getNumNeighbors() const;
    void clear();

    //A structure for building a linked list
private:
    typedef struct NodeCar {
        Car car;
        struct NodeCar *next;
    } NodeCar;
    NodeCar* carInJunction;
    unsigned int numNeighbors;
    unsigned  int *neighbors;
    Road* roads;
    unsigned int sizeMet;
};

#endif //HW3_JUNCTION_H
