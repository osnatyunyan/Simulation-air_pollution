
#include "Road.h"

Road::Road( unsigned int  from, unsigned int  to, double c, double length){
    Road::to=to;
    Road::from=from;
    Road::c=c;
    Road::AirPollution=0;
    Road::length=length;
}

//default constructor
Road::Road() {
    from=0;
    to=0;
    c=0;
    AirPollution=0;
    length=0;
}

double Road::getAirPollution() const {
    return AirPollution;
}

const Road Road::operator++(int) {
    Road temp = *this;
    AirPollution+= (c / length);
    return temp;
}

unsigned int Road::getFrom() const {
    return from;
}

unsigned int Road::getTo() const {
    return to;
}

//Copy constructor
Road::Road(const Road &rhs) {
    from=rhs.from;
    to=rhs.to;
    c=rhs.c;
    AirPollution=rhs.AirPollution;
    length=rhs.length;
}




