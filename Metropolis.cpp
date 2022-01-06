#include <sstream>
#include "Metropolis.h"
#include <cstdlib>
#include <iomanip>


Metropolis::Metropolis(double **graph, unsigned int size) {
   //Initializes the metropolis
    metropolis=new double *[size];
    for(unsigned int i=0;i<size;i++){
        metropolis[i]=new double [size];
    }
    sizeMet=size;
    //Creating an array of nodes
    junctions=new Junction[sizeMet];
    for(unsigned int i=0;i<sizeMet;i++) {
        junctions[i]= Junction(sizeMet);
    }
    int counter=0;
    for(unsigned int i=0;i<sizeMet;i++){
        for(unsigned int j=0;j<sizeMet;j++){
            double k=graph[i][j];
            metropolis[i][j]=k;
            if(metropolis[i][j]!=0){
                junctions[i].setNeighbors(j,counter);
                counter++;
            }
        }
        junctions[i].setNumNeighbors(counter);
        counter=0;
    }
    //Creating an array of cars
    cars=new Car[500];
    for(int i=0;i<500;i++){
        cars[i]=Car();
    }
    numOfCar=0;
}

void Metropolis::setJunction(string *sJunction, double c) {
   //Initialization of cars and roads
    int counter = 0;
    for (unsigned int i = 0; i < sizeMet; i++) {
        junctions[i].setArrayRoad();
        for (unsigned int j = 0; j < sizeMet; j++) {
            if (metropolis[i][j] != 0) {
                junctions[i].setRoad(i, j, counter, metropolis[i][j], c);
                counter++;
            }
        }
        counter = 0;
    }
    for (unsigned int i=0;i<sizeMet;i++){
        unsigned int tempJunction, tempInt = 0;
        char ch;
        stringstream convert(sJunction[i]);
        convert>>tempJunction;
        convert>>ch;
        while (!convert.eof()){
            convert>>tempInt;
            if(tempInt!=0){
                Car newCar(tempInt,i);
                cars[numOfCar]= newCar;
                numOfCar++;
                junctions[i].addNewCar(newCar);
            }
        }
    }
}

void Metropolis::update() {
    unsigned int junctionFrom;
    unsigned int numOption;
    unsigned int junctionTo;
    for(unsigned int i=0;i<numOfCar;i++){
        junctionFrom=cars[i].getCurrentEdge();
        numOption=junctions[junctionFrom].getNumNeighbors()+1;
        junctionTo=(unsigned int)random()%numOption;
        if(junctionTo==(numOption-1)){
            //If chosen to stay at the junction, there is nothing to update and the program can continue
            continue;
        } else{
            junctionTo=junctions[junctionFrom].getNeighbors(junctionTo);
            junctions[junctionFrom].removeCar(cars[i]);
            junctions[junctionFrom].getRoad(junctionFrom,junctionTo)++;
            cars[i].setCurrentEdge(junctionTo);
            junctions[junctionTo].addNewCar(cars[i]);
        }
    }
}

void Metropolis:: printNum(double n){
    //Function for printing numbers as required
    std::stringstream ss;
    ss << fixed << setprecision(2) << n;
    string str = ss.str();

    // Remove trailing zeroes
    str = str.substr(0, str.find_last_not_of('0') + 1);
    // If the decimal point is now the last character, remove that as well
    if (str.find('.') == str.size() - 1) {
        str = str.substr(0, str.size() - 1);
    }
    cout << str;
}

void Metropolis::print() {
    //Print the metropolitan matrix after all updates
    for(unsigned int i=0;i<sizeMet;i++){
        for(unsigned int j=0;j<sizeMet;j++){
            if(metropolis[i][j]==0){
                cout<<'0';
                cout<<' ';
            } else{
                printNum(junctions[i].getRoad(i,j).getAirPollution());
                cout<<' ';
            }
        }
        cout<<endl;
    }
    //Printing the cars of vehicles at junction
    for (unsigned int i=0;i<sizeMet;i++){
        cout<<(i+1);
        cout<<": ";
        for(unsigned int j=0;j<numOfCar;j++){
            if(cars[j].getCurrentEdge()==i){
                cout<<cars[j].getSerial();
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

Metropolis::~Metropolis() {
    for(unsigned int i=0;i<sizeMet;i++){
        junctions[i].clear();
    }
    delete [] junctions;
    delete [] cars;
    for(unsigned int i=0;i<sizeMet;i++){
       delete[] metropolis[i];
    }
    delete [] metropolis;
}






