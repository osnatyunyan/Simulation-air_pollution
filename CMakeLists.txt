cmake_minimum_required(VERSION 3.20)
project(hw3)

set(CMAKE_CXX_STANDARD 98)

add_executable(hw3 main.cpp Car.h Car.cpp Road.cpp Road.h Junction.cpp Junction.h Metropolis.cpp Metropolis.h Simulation.cpp Simulation.h met_graph.dat vehicle_locations.dat)
