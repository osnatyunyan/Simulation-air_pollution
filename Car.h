
#ifndef HW3_CAR_H
#define HW3_CAR_H

class Car{
public:
    //There is no need for a build copy and destructor because I did not allocate space
    Car();
    Car(unsigned int serial,unsigned int  currentEdge);
    unsigned int getSerial() const;
    unsigned int getCurrentEdge() const;
    void setCurrentEdge(unsigned int  currentEdge);
    bool operator==(const Car &rhs) const;
    bool operator!=(const Car &rhs) const;

private:
    unsigned int serial;
    unsigned int  currentEdge;
};

#endif //HW3_CAR_H
