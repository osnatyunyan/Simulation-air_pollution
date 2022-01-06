

#include <cstdio>
#include <iostream>
#include "Junction.h"

Junction::Junction( unsigned int size) {
    sizeMet=size;
    neighbors=new unsigned int  [sizeMet];
    carInJunction=NULL;
    numNeighbors=0;
    roads=NULL;
}

Junction::Junction() {
    sizeMet=0;
    carInJunction=NULL;
    neighbors=NULL;
    carInJunction=NULL;
    numNeighbors=0;
    roads=NULL;
}

void Junction::setRoad(unsigned int from, unsigned int  to,unsigned int  index,double length,double c) {
    roads[index]= Road(from, to, c,length);
}

void Junction::setNeighbors(unsigned int  n, unsigned int  index) {
   neighbors[index]=n;
}

void Junction::setNumNeighbors(unsigned int  counter) {
    numNeighbors=counter;
}

void Junction::addNewCar(Car& newCar) {
    //Add a car to the linked list

    NodeCar* newNode=new NodeCar;
    newNode->car=newCar;
    newNode->next=carInJunction;
    carInJunction=newNode;
}

void Junction::setArrayRoad() {
    //Assigns space to the array of roads
    roads=new Road[numNeighbors];
}

void Junction::removeCar(Car& removeCar) {
    //Deleting a car from the linked list
    NodeCar * tmp=carInJunction;
    NodeCar *prev;
    if(tmp->car==removeCar){
        carInJunction=tmp->next;
        delete (tmp);
        return;
    }
    while (tmp){
        if(tmp->car==removeCar){
            prev->next=tmp->next;
            delete (tmp);
            return;
        } else{
            prev=tmp;
            tmp=tmp->next;
        }
    }
}

unsigned int  Junction::getNumNeighbors() const {
    return numNeighbors;
}

unsigned int & Junction::getNeighbors(unsigned int  index) {
    return neighbors[index];
}

Road& Junction::getRoad(unsigned int  from, unsigned int  to) {
    //Searches through the junction from and junction to ,who the road is and returns it
    for(unsigned int i=0; i<numNeighbors;i++){
        if(roads[i].getFrom()==from && roads[i].getTo()==to){
           return roads[i];
        }
    }
    return roads[numNeighbors];
}
//use a destructor when I call to this function
void Junction::clear() {
    while (carInJunction!=NULL){
        NodeCar * tmp=carInJunction;
        carInJunction=tmp->next;
        delete (tmp);
    }
    delete [] roads;
    delete [] neighbors;
}









