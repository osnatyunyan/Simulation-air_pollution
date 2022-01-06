
#ifndef HW3_ROAD_H
#define HW3_ROAD_H

class Road{

public:
    //No need a destructor and equal operator ,because I did not assign objects
    Road();
    Road(unsigned int from, unsigned int  to, double c, double length);
    Road( const Road & rhs);
    double getAirPollution() const;
    const Road operator++(int);
    unsigned int  getFrom() const;
    unsigned int  getTo() const;

private:
    unsigned int from;
    unsigned int to;
    double c;
    double AirPollution;
    double length;
};
#endif //HW3_ROAD_H
