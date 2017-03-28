#pragma once

#include <iostream>
#include <map>

class MapNode {
private:
	std::string m_name; //Location name
	std::map<MapNode*, int> m_edges; //Edges and their distances
public:
	MapNode(std::string name, std::map<MapNode*, int> &edges); //Constructor, takes name of place and connected nodes
	MapNode(std::string name); //Constructor, defaults to no edges
	inline const std::string getName() { return m_name; } //Returns location name
	inline const std::map<MapNode*, int> getEdges() { return m_edges; } //Returns a map of connected nodes and their edges
	void addEdge(MapNode *node, int dist); //Adds a connected node and its distance
	void print(); //Prints the node and its edges in adjacency list form
};