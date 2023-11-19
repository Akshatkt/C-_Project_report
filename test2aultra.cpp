// ##################################################################################
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Graph represented as an adjacency matrix
vector<vector<int>> graph;

// Number of nodes
int numNodes;

// Function to find the nearest unvisited neighbor from a given node
int findNearestNeighbor(int node, vector<bool>& visited) {
    int nearestNeighbor = -1;
    int minDistance = INF;

    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i] && graph[node][i] < minDistance) {
            nearestNeighbor = i;
            minDistance = graph[node][i];
        }
    }

    return nearestNeighbor;
}

// Function to solve TSPR using the Nearest Neighbor Algorithm
vector<int> tsprNearestNeighbor(int& totalDistance) {
    vector<bool> visited(numNodes, false);
    vector<int> tour;

    int startNode = 0; // Starting from node 0

    tour.push_back(startNode);
    visited[startNode] = true;

    totalDistance = 0; // Initialize total travel distance

    while (tour.size() < numNodes) {
        int currentNode = tour.back();
        int nearestNeighbor = findNearestNeighbor(currentNode, visited);

        if (nearestNeighbor != -1) {
            tour.push_back(nearestNeighbor);
            visited[nearestNeighbor] = true;
            totalDistance += graph[currentNode][nearestNeighbor]; // Add distance to total
        } else {
            // If no unvisited neighbors left, return to the starting node
            tour.push_back(startNode);
            totalDistance += graph[currentNode][startNode]; // Add distance to total
        }
    }

    return tour;
}

int main() {
    numNodes = 6;

    // Example graph represented as an adjacency matrix (INF for unreachable nodes)
    graph = {
        {0, 3, 1, 5, INF, INF},
    {3, 0, 2, INF, 10, INF}, // Changed from INF to 10
    {1, 2, 0, 4, 6, INF},
    {5, INF, 4, 0, INF, 2},
    {INF, 10, 6, INF, 0, 1}, // Updated from INF to 10
    {INF, INF, INF, 2, 1, 0}
    };

    int totalDistance;
    vector<int> tour = tsprNearestNeighbor(totalDistance);

    cout << "TSPR Tour: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;

    cout << "Total Travel Distance: " << totalDistance << endl;

    return 0;
}
