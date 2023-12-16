//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 3
#include "NearestNeighbor.hpp"
#include <iostream>
#include <chrono>

int main() {
    std::string filename = "ar9152.tsp"; //read in the file
    NearestNeighbor nearestNeighbor(filename);

    auto startTime = std::chrono::high_resolution_clock::now(); //start timing
    nearestNeighbor.nearestNeighborAlgorithm();
    auto endTime = std::chrono::high_resolution_clock::now(); //stop timing
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime); //calc duration duh

    nearestNeighbor.printResult();

    std::cout << "Time in ms: " << duration.count() << std::endl;

    return 0;
}