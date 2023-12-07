#include "NearestNeighbor.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>

NearestNeighbor::NearestNeighbor(const std::string& filename) {
    // Initialize cities and tour vectors from the input file
    // Your code to read input and initialize cities vector goes here
}

void NearestNeighbor::nearestNeighbor() {
    auto start = std::chrono::high_resolution_clock::now();

    // Start from node 1
    Node* currentCity = &cities[0];
    currentCity->visited = true;
    tour.push_back(currentCity);

    // Visit the nearest unvisited cities until all nodes are visited
    while (tour.size() < cities.size()) {
        Node* nearestCity = findNearestCity(*currentCity);
        nearestCity->visited = true;
        tour.push_back(nearestCity);
        totalDistance += calculateDistance(*currentCity, *nearestCity);
        currentCity = nearestCity;
    }

    // Return to node 1 to complete the tour
    totalDistance += calculateDistance(*currentCity, cities[0]);
    tour.push_back(&cities[0]);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    // Print the tour details
    printTour();

    // Print the total distance and time taken
    std::cout << "Total Distance: " << totalDistance << "\n";
    std::cout << "Time in ms: " << diff.count() * 1000 << "\n";
}

double NearestNeighbor::calculateDistance(const Node& city1, const Node& city2) {
    // Your code to calculate the Euclidean distance between two cities goes here
    return 0.0; // Replace with your distance calculation
}

NearestNeighbor::Node* NearestNeighbor::findNearestCity(Node& currentCity) {
    // Your code to find the nearest unvisited city goes here
    // Return a pointer to the nearest city
    return nullptr; // Replace with your implementation
}

void NearestNeighbor::printTour() {
    // Your code to print the IDs of the nodes visited in order goes here
    std::cout << "Tour: ";
    for (const auto& city : tour) {
        std::cout << city->id << " ";
    }
    std::cout << "\n";
}