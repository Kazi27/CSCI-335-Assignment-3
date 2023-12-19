// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 3
// #include "NearestNeighbor.hpp"

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
//             iss >> id >> x >> y; //extract the id x and y coords from the line
//             nodes.emplace_back(id, x, y);
//         }
//     }

//     file.close();
// }

// void NearestNeighbor::nearestNeighborAlgorithm() //remember tour is a vector to store the order of visited nodes
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