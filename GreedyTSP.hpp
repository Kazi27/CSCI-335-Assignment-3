#ifndef GREEDY_TSP_HPP
#define GREEDY_TSP_HPP

#include <vector>
#include <string>

class GreedyTSP 
{
public:
    GreedyTSP(const std::string& filename);
    void greedyTSP();
private:
    struct Node 
    {
        int id;
        double x, y; //city coords
        bool visited;
        std::vector<Node*> edges;
    };

    struct Edge 
    {
        Node* from;
        Node* to;
        double weight;
    };

    double calculateDistance(const Node& city1, const Node& city2);

    void addEdgeToTour(Edge& edge);

    bool createsCycle(Edge& edge);

    void printTour();

    std::vector<Node> cities; 
    std::vector<Edge> edges;  
    double totalDistance;   
};

#endif 
