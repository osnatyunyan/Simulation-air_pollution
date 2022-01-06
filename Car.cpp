#include "Car.h"


Car::Car(unsigned int serial, unsigned int  currentEdge) {
    Car::serial = serial;
    Car::currentEdge = currentEdge;
}

//default constructor
Car::Car() {
    Car::currentEdge = 0;
    Car::serial = 0;
}

unsigned int Car::getSerial() const {
    return serial;
}

unsigned int  Car::getCurrentEdge() const {
    return currentEdge;
}

void Car::setCurrentEdge(unsigned int  currJunction) {
    currentEdge = currJunction;
}

bool Car::operator==(const Car &rhs) const {
    return
           serial == rhs.serial &&
           currentEdge == rhs.currentEdge;
}

bool Car::operator!=(const Car &rhs) const {
    return !(rhs == *this);
}





