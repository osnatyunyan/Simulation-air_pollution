
#include "Simulation.h"
#include "Metropolis.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

void Simulation::readFile(char* graphMetv, char* Vehicle) {
    //Receives the files, reads and checks their integrity
    ifstream graphMet;
    graphMet.open(graphMetv);
    ifstream sVehicle;
    sVehicle.open(Vehicle);
    if(!graphMet.is_open() || !sVehicle.is_open()){
        cerr<<"error: invalid input."<<endl;
        exit(1);
    }
    string size;
    getline(graphMet,size);
    stringstream size1(size);
    size1>>sizeMet;
    graph=new double *[sizeMet];
    for(unsigned int i=0;i<sizeMet;i++){
        graph[i]=new double [sizeMet];
    }
    unsigned int counter=0;
    unsigned int i=0;
    unsigned int j=0;
    char* p;
    string line;
    while(!graphMet.eof()){
        //Transfer the file to a matrix
        getline(graphMet,line);
       char *lineC=&line[0];
        p = strtok( lineC, " ");
        while (p != NULL)
        {
            graph[i][j] = atof(p);
            if(i==j && graph[i][j]!=0){
                cerr<<"error: invalid input."<<endl;
                exit(1);
            }
            p = strtok(NULL, " ");
            j++;
        }
        j=0;
        i++;
        counter++;
    }
    if(counter>sizeMet){
        cerr<<"error: invalid input."<<endl;
        exit(1);
    }
    counter=0;
    sJunction=new string [sizeMet];
    while(!sVehicle.eof()){
        getline(sVehicle,sJunction[counter]);
        counter++;
    }
    if(counter>sizeMet){
        cerr<<"error: invalid input."<<endl;
        exit(1);
    }
    cin>>c;
    cin>>time;
    graphMet.close();
    sVehicle.close();
}

void Simulation::start(char* graphMetv, char* Vehicle) {
    //Responsible for operating the program
    readFile(graphMetv,Vehicle);
    Metropolis m(graph, sizeMet);
    m.setJunction(sJunction,c);
    while(time){
        m.update();
        time--;
    }
    m.print();
}

Simulation::~Simulation() {
    delete[] sJunction;
    for(unsigned int i=0;i<sizeMet;i++){
        delete[] graph[i];
    }
    delete [] graph;
}

