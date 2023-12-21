// Name: Kazi Sameen Anwar
// CSCI - 335 Assignment 3
#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP //like we learned in 260 these are include guards that the precompiler processes

#include <string>
#include <vector>
#include <iostream> //input output 
#include <fstream> //for reading the file
#include <cmath> //math stuff
#include <ctime> //to time
#include <limits>
#include <sstream>

class Node //so this class is ur point with an id and x and y coords
{
    public:
        int id;
        double x, y;

        Node(int id, double x, double y) : id(id), x(x), y(y) {}; //constructor with initializer list
        double distance(const Node& other) const
        {
            return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        } //this is the distance calculator
};

void nearestNeighbor(const std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: can't open file" << std::endl; //copied from proj 2 jus modified a bit to not return a -1
        return;
    }

    std::vector<Node> nodesVect; //vect to store node objs
    std::string line; ////will store each line
    int id;
    double x, y;

    //read file line by line and fill up the  vector
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        if (!(iss >> id >> x >> y))
        {
            continue;
        }
        nodesVect.emplace_back(id, x, y); //this is from stack overflow and it abscially add elements to the end of a container so for us node objects at the end of the vector
    }

    if (nodesVect.empty())
    {
        std::cout << "No nodes" << std::endl; //if ur here than vector is empty and no nodes are in the file
        return;
    }

    std::vector<bool> visitedVect(nodesVect.size(), false); //vect to track visited nodes
    std::vector<int> tourVect;  //vector to store path of VISITED nodes
    double totalDist = 0.0; //total distance of the path

    auto start = std::chrono::steady_clock::now(); //no need to epxlain

    int currentNode = 0;  //keep track of the current node
    tourVect.push_back(nodesVect[currentNode].id); //add starting node to path
    visitedVect[currentNode] = true; //mark da starting node visited

    while (tourVect.size() < nodesVect.size()) //construct path by finding nearest neighbor for each node
    {
        double nearestDist = std::numeric_limits<double>::max(); //initialize variable to max value
        int nearestNode = -1; //-1 stored into nearestNode

        for (size_t k = 0; k < nodesVect.size(); ++k) //iterate thru and find nearest unvisited node
        {
            if (!visitedVect[k]) //if u havent visited this node before
            {
                double distance = nodesVect[currentNode].distance(nodesVect[k]); //calc ur distance
                if (distance < nearestDist) //if this distance is smaller than the distance u have rn, initially distance set to inifintiy according to vid btw
                {
                    nearestDist = distance; //update dat
                    nearestNode = k;
                }
            }
        }

        if (nearestNode == -1) //this is when u cant find the nearest node
        {
            std::cerr << "Error: can't find nearest node" << std::endl; 
            return;
        }

        visitedVect[nearestNode] = true; //mark nearest node visited
        tourVect.push_back(nodesVect[nearestNode].id); //add nearest neighbor to the tour
        totalDist += nearestDist; //add up all distance
        currentNode = nearestNode;  //update current node for the next iter
    }

    totalDist += nodesVect[currentNode].distance(nodesVect[0]); //update distance travelled
    tourVect.push_back(nodesVect[0].id); //add node to tour

    auto end = std::chrono::steady_clock::now(); //SIMPLE 

    //jus printing 
    std::cout << "Tour Order: ";
    for (const auto &nodeId : tourVect)
    {
        std::cout << nodeId << " ";
    }
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "\nTotal Distance: " << totalDist << "\n" << "Execution Time: " << duration << " milliseconds\n";
}
#endif

// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 3

// working version when this was just hpp locally but not on gradescope for some reason
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

//#endif 

//DOES NOT WORK ON GRADESCOPE BUT WORKS LOCALLY
// class NearestNeighbor
// {
// public:
//     NearestNeighbor(const std::string& filename); //reads in a filename to make an instance of that
//     void nearestNeighborAlgorithm(); //does the actual implementation of the algo
//     void printResult(); //prints duh

// private:
//     std::vector<Node> nodes; //ur priv data members
//     std::vector<int> tour; //vector to store the order of visited nodes
//     double totalDistance;
// };

// Node::Node(int id, double x, double y) : id(id), x(x), y(y) {} //instead of setting the stuff ur self, just use an initializer list fr

// double Node::distance(const Node& other) const
// {
//     return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2)); //THE DISTANCE FORMULA, subtract endpoints raise it to power of 2, add them and sqrt whole thing
// }

// NearestNeighbor::NearestNeighbor(const std::string& filename) : totalDistance(0.0) //takes in the file and also initialzies total distance to start at 0
// {
//     std::ifstream file(filename);
//     if (!file.is_open())
//     {
//         std::cerr << "Error opening file: " << filename << std::endl; //copied from proj 2 jus modified a bit to not return a -1
//         exit(EXIT_FAILURE);
//     }

//     std::string line; //will store each line
//     bool nodeCoordSection = false;

//     while (std::getline(file, line))
//     {
//         if (line.find("NODE_COORD_SECTION") != std::string::npos) //so all files have the string "NODE_COORD_SECTION" so u wanna find that to signal that alr next lines are the coords
//         {
//             nodeCoordSection = true;
//             continue;
//         }

//         if (nodeCoordSection && line.find("EOF") == std::string::npos)
//         {
//             int id;
//             double x, y;
//             std::istringstream iss(line);
//             iss >> id >> x >> y;  //extract the id x and y coords from the line
//             nodes.emplace_back(id, x, y);
//         }
//     }

//     file.close();
// }

// void NearestNeighbor::nearestNeighborAlgorithm()  //remember tour is a vector to store the order of visited nodes
// {
//     int n = nodes.size();
//     tour.clear();
//     totalDistance = 0.0;

//     std::vector<bool> visited(n, false); //this vector keeps track of if the node is visited or not
//     tour.push_back(1); //start from node 1
//     visited[0] = true;

//     for (int i = 0; i < n - 1; ++i) //terate thru all nodes except the last one
//     {
//         int currentCity = tour.back();
//         int nearestNeighbor = -1;
//         double minDistance = std::numeric_limits<double>::max(); //these just insiitalize

//         for (int j = 0; j < n; ++j) //iteratre thru all nodes to find nearest neighbor now
//         {
//             if (!visited[j]) //if u havent visited this node before
//             {
//                 double distance = nodes[currentCity - 1].distance(nodes[j]); //calc ur distance
//                 if (distance < minDistance) //if this distance is smaller than the distance u have rn, initially distance set to inifintiy according to vid btw
//                 {
//                     minDistance = distance; //update that
//                     nearestNeighbor = j;
//                 }
//             }
//         }

//         totalDistance += minDistance; //add up all distance
//         tour.push_back(nearestNeighbor + 1); //add nearest neighbor to the tour
//         visited[nearestNeighbor] = true; //u visited it so mark that
//     }

//     totalDistance += nodes[tour.back() - 1].distance(nodes[0]); //update distance travelled
//     tour.push_back(1); //add ndoe to tour
// }

// void NearestNeighbor::printResult() //pretty self explanatory
// {
//     std::cout << "Tour Order:";
//     for (int city : tour)
//     {
//         std::cout << " " << city;
//     }
//     std::cout << std::endl;

//     std::cout << "Total Distance: " << totalDistance << std::endl;
// }
//#endif