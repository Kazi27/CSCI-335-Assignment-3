// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 3
// #ifndef NEARESTNEIGHBOR_HPP
// #define NEARESTNEIGHBOR_HPP //like we learned in 260 these are include guards that the precompiler processes

// #include <string>
// #include <vector>
// #include <iostream> //input output 
// #include <fstream> //for reading the file
// #include <cmath> //math stuff
// #include <ctime> //to time
// #include <limits>
// #include <sstream>  //sstream for iss

// class Node //so this class is ur point with an id and x and y coords
// {
//     public:
//         int id;
//         double x, y;

//         Node(int id, double x, double y); //constructor
//         double distance(const Node& other) const; //this is the distance calculator
// };

// class NearestNeighbor 
// {
//     public:
//         NearestNeighbor(const std::string& filename); //reads in a filename to make an instance of that
//         void nearestNeighborAlgorithm(); //does the actual implementation of the algo
//         void printResult(); //prints duh

//     private:
//         std::vector<Node> nodes; //ur priv data members
//         std::vector<int> tour; //vector to store the order of visited nodes
//         double totalDistance;
// };

// #endif // NEARESTNEIGHBOR_HPP
//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 3
#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <limits>
#include <sstream>

class Node
{
public:
    int id;
    double x, y;

    Node(int id, double x, double y);
    double distance(const Node& other) const;
};

class NearestNeighbor
{
public:
    NearestNeighbor(const std::string& filename);
    void nearestNeighborAlgorithm();
    void printResult();

private:
    std::vector<Node> nodes;
    std::vector<int> tour;
    double totalDistance;
};

Node::Node(int id, double x, double y) : id(id), x(x), y(y) {}

double Node::distance(const Node& other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

NearestNeighbor::NearestNeighbor(const std::string& filename) : totalDistance(0.0)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    bool nodeCoordSection = false;

    while (std::getline(file, line))
    {
        if (line.find("NODE_COORD_SECTION") != std::string::npos)
        {
            nodeCoordSection = true;
            continue;
        }

        if (nodeCoordSection && line.find("EOF") == std::string::npos)
        {
            int id;
            double x, y;
            std::istringstream iss(line);
            iss >> id >> x >> y;
            nodes.emplace_back(id, x, y);
        }
    }

    file.close();
}

void NearestNeighbor::nearestNeighborAlgorithm()
{
    int n = nodes.size();
    tour.clear();
    totalDistance = 0.0;

    std::vector<bool> visited(n, false);
    tour.push_back(1);
    visited[0] = true;

    for (int i = 0; i < n - 1; ++i)
    {
        int currentCity = tour.back();
        int nearestNeighbor = -1;
        double minDistance = std::numeric_limits<double>::max();

        for (int j = 0; j < n; ++j)
        {
            if (!visited[j])
            {
                double distance = nodes[currentCity - 1].distance(nodes[j]);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    nearestNeighbor = j;
                }
            }
        }

        totalDistance += minDistance;
        tour.push_back(nearestNeighbor + 1);
        visited[nearestNeighbor] = true;
    }

    totalDistance += nodes[tour.back() - 1].distance(nodes[0]);
    tour.push_back(1);
}

void NearestNeighbor::printResult()
{
    std::cout << "Tour Order:";
    for (int city : tour)
    {
        std::cout << " " << city;
    }
    std::cout << std::endl;

    std::cout << "Total Distance: " << totalDistance << std::endl;
}

#endif // NEARESTNEIGHBOR_HPP
