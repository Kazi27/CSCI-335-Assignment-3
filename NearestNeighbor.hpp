#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <limits>

class Node {
public:
    int id;
    double x, y;

    Node(int id, double x, double y) : id(id), x(x), y(y) {}

    double dist(const Node& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

void nearestNeighbor(const std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file.\n";
        return;
    }

    std::vector<Node> nodes;
    std::string line;
    int id;
    double x, y;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> id >> x >> y)) {
            continue;
        }
        nodes.emplace_back(id, x, y);
    }

    if (nodes.empty()) {
        std::cout << "No nodes to process.\n";
        return;
    }

    std::vector<bool> visited(nodes.size(), false);
    std::vector<int> path;
    double totalDistance = 0.0;

    auto startTime = std::chrono::steady_clock::now();

    int current = 0;
    path.push_back(nodes[current].id);
    visited[current] = true;

    while (path.size() < nodes.size()) {
        double nearestDistance = std::numeric_limits<double>::max();
        int nearestNode = -1;

        for (size_t j = 0; j < nodes.size(); ++j) {
            if (!visited[j]) {
                double distance = nodes[current].dist(nodes[j]);
                if (distance < nearestDistance) {
                    nearestDistance = distance;
                    nearestNode = j;
                }
            }
        }

        if (nearestNode == -1) {
            std::cerr << "Error: Unable to find nearest node.\n";
            return;
        }

        visited[nearestNode] = true;
        path.push_back(nodes[nearestNode].id);
        totalDistance += nearestDistance;
        current = nearestNode;
    }

    totalDistance += nodes[current].dist(nodes[0]);
    path.push_back(nodes[0].id);

    auto endTime = std::chrono::steady_clock::now();

    for (const auto& nodeId : path) {
        std::cout << nodeId << " ";
    }
    std::cout << "\nTotal Distance: " << totalDistance << "\n";
    std::cout << "Execution Time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " milliseconds\n";
}