//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 3
#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP //like we learned in 260 these are include guards that the precompiler processes

#include <string>
#include <vector>
#include <iostream> //input output 
#include <fstream> //for reading the file
#include <cmath> //math stuff
#include <ctime> //to time
#include <limits>
#include <sstream>  //sstream for iss

class Node //so this class is ur point with an id and x and y coords
{
    public:
        int id;
        double x, y;

        Node(int id, double x, double y); //constructor
        double distance(const Node& other) const; //this is the distance calculator
};

class NearestNeighbor 
{
    public:
        NearestNeighbor(const std::string& filename); //reads in a filename to make an instance of that
        void nearestNeighborAlgorithm(); //does the actual implementation of the algo
        void printResult(); //prints duh

    private:
        std::vector<Node> nodes; //ur priv data members
        std::vector<int> tour; //vector to store the order of visited nodes
        double totalDistance;
};

#endif // NEARESTNEIGHBOR_HPP