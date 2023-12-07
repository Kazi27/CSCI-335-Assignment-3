#ifndef NEAREST_NEIGHBOR_HPP
#define NEAREST_NEIGHBOR_HPP

#include <vector>
#include <string>

class NearestNeighbor {
public:
    NearestNeighbor(const std::string& filename);

    // Function to perform the Nearest Neighbor algorithm
    void nearestNeighbor();

private:
    // Node structure to represent cities
    struct Node {
        int id;
        double x, y; // Coordinates of the city
        bool visited;
    };

    // Function to calculate the distance between two cities
    double calculateDistance(const Node& city1, const Node& city2);

    // Function to find the nearest unvisited city
    Node* findNearestCity(Node& currentCity);

    // Function to print the tour details
    void printTour();

    std::vector<Node> cities; // Vector to store information about cities
    std::vector<Node*> tour;  // Vector to store the tour order
    double totalDistance;     // Total distance traveled
};

#endif // NEAREST_NEIGHBOR_HPP