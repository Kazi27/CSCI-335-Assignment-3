#include "GreedyTSP.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>

GreedyTSP::GreedyTSP(const std::string& filename) {
    // Initialize cities vector from the input file
    // Your code to read input and initialize cities vector goes here
}

void GreedyTSP::greedyTSP() {
    auto start = std::chrono::high_resolution_clock::now();

    // Calculate weights of all edges
    for (size_t i = 0; i < cities.size(); ++i) {
        for (size_t j = i + 1; j < cities.size(); ++j) {
            Edge edge;
            edge.from = &cities[i];
            edge.to = &cities[j];
            edge.weight = calculateDistance(cities[i], cities[j]);
            edges.push_back(edge);
        }
    }

    // Sort edges by weight in ascending order
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // Build the tour by adding edges
    for (const auto& edge : edges) {
        if (!createsCycle(edge)) {
            addEdgeToTour(edge);
            totalDistance += edge.weight;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    // Print the tour details
    printTour();

    // Print the total distance and time taken
    std::cout << "Total Distance: " << totalDistance << "\n";
    std::cout << "Time in ms: " << diff.count() * 1000 << "\n";
}

double GreedyTSP::calculateDistance(const Node& city1, const Node& city2) {
    // Your code to calculate the Euclidean distance between two cities goes here
    return 0.0; // Replace with your distance calculation
}

void GreedyTSP::addEdgeToTour(Edge& edge) {
    // Your code to add an edge to the tour goes here
}

bool GreedyTSP::createsCycle(Edge& edge) {
    // Your code to check if adding an edge creates a cycle goes here
    return false; // Replace with your implementation
}

void GreedyTSP::printTour() {
    // Your code to print the tour details goes here
    std::cout << "Tour: ";
    // Replace with your implementation
}
