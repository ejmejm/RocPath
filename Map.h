#pragma once

#include <map>
#include <vector>
#include <algorithm>
#include "MapNode.h"

class Map {
private:
	std::vector<MapNode *> m_nodes; //All location nodes
public:
	inline Map() { }; //Constructor, defaults to no nodes
	inline Map(std::vector<MapNode *> nodes) : m_nodes(nodes) { }
	inline void addNode(MapNode *node) { m_nodes.push_back(node); } //Adds a new node to the map
	inline const std::vector<MapNode *> &getNodes() { return m_nodes; } //Returns a vector of all the maps' nodes
	MapNode *const getNode(std::string name); //Get a node by name
	void addEdge(std::string node1, std::string node2, int dist); //Assumes the edge is directed
	void addUEdge(std::string node1, std::string node2, int dist); //Assumes the edge is undirected
	void addEdge(std::string node1, std::string node2, int dist, bool directed); //Add an edge to the graph
	std::vector<MapNode *> shortestPath(std::string startNode, std::string endNode); //Returns a vector of the shortest path as nodes
	std::vector<std::string> shortestPathS(std::string startNode, std::string endNode); //Returns a vector of the shortest path as location names
	int shortestDist(std::string startNode, std::string endNode); //Number of steps in the shortest path
	void printShortestPath(std::string startNode, std::string endNode); //Prints the shortest path from startNode to endNode
	void print(); //Prints all the maps nodes and connections
};