#include "MapNode.h"

MapNode::MapNode(std::string name, std::map<MapNode*, int> &edges)
	: m_name(name), m_edges(edges){ }

MapNode::MapNode(std::string name) 
	: m_name(name){ }

void MapNode::addEdge(MapNode *node, int dist) {
	m_edges[node] = dist;
}

void MapNode::print() {
	std::cout << "Node \"" << getName().c_str() << "\": " << std::endl;
	for (auto const &ent : m_edges)
		std::cout << "    To Node \"" << ((MapNode*) ent.first)->getName().c_str() << "\" Distance: " << ent.second << std::endl;
}