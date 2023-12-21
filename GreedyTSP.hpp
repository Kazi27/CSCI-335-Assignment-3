// #ifndef GREEDY_TSP_HPP
// #define GREEDY_TSP_HPP

// #include <vector>
// #include <string>

// class GreedyTSP {
// public:
//     GreedyTSP(const std::string& filename);

//     // Function to perform the Greedy TSP algorithm
//     void greedyTSP();

// private:
//     // Node structure to represent cities
//     struct Node {
//         int id;
//         double x, y; // Coordinates of the city
//         bool visited;
//         std::vector<Node*> edges; // Nodes connected by edges
//     };

//     // Edge structure to represent connections between cities
//     struct Edge {
//         Node* from;
//         Node* to;
//         double weight;
//     };

//     // Function to calculate the distance between two cities
//     double calculateDistance(const Node& city1, const Node& city2);

//     // Function to add an edge to the tour
//     void addEdgeToTour(Edge& edge);

//     // Function to check if adding an edge creates a cycle
//     bool createsCycle(Edge& edge);

//     // Function to print the tour details
//     void printTour();

//     std::vector<Node> cities; // Vector to store information about cities
//     std::vector<Edge> edges;  // Vector to store information about edges
//     double totalDistance;     // Total distance traveled
// };

// #endif // GREEDY_TSP_HPP
