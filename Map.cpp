#include "Map.h"

void Map::print() {
	std::cout << "Map:" << std::endl;
	for (auto const &val : m_nodes)
		((MapNode *)val)->print();
}

MapNode *const Map::getNode(std::string name) {
	for (auto const &val : m_nodes)
		if (((MapNode *)val)->getName() == name)
			return val;
	return NULL;
}

void Map::addEdge(std::string node1, std::string node2, int dist) {
	addEdge(node1, node2, dist, true);
}

void Map::addUEdge(std::string node1, std::string node2, int dist) {
	addEdge(node1, node2, dist, false);
}

void Map::addEdge(std::string node1, std::string node2, int dist, bool directed) {
	if (!directed) {
		getNode(node1)->addEdge(getNode(node2), dist);
		getNode(node2)->addEdge(getNode(node1), dist);
	} else
		getNode(node1)->addEdge(getNode(node2), dist);
}

std::vector<MapNode *> Map::shortestPath(std::string startNode, std::string endNode) {
	std::vector<MapNode *> unvisited;
	std::map<MapNode *, int> dist;
	std::map<MapNode *, MapNode *> prev;

	for (auto const &node : m_nodes) {
		dist[node] = INT_MAX;
		prev[node] = NULL;
		unvisited.push_back(node);
	}

	dist[getNode(startNode)] = 0;

	while (!unvisited.empty()) {
		MapNode *closest = unvisited[0];
		for (auto const &curNode : unvisited)
			if (dist[curNode] < dist[closest])
				closest = curNode;

		if (closest == getNode(endNode)) {
			std::vector<MapNode *> shortestPath;
			while (prev[closest] != NULL) {
				shortestPath.insert(shortestPath.begin(), closest);
				closest = prev[closest];
			}
			shortestPath.insert(shortestPath.begin(), closest);

			return shortestPath;
		}

		unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), closest), unvisited.end());

		for (auto const &neighbor : closest->getEdges()) {
			int alt = dist[closest] + neighbor.second;
			if (alt < dist[neighbor.first]) {
				dist[neighbor.first] = alt;
				prev[neighbor.first] = closest;
			}
		}
	}

	return std::vector<MapNode *>(0);
}

std::vector<std::string> Map::shortestPathS(std::string startNode, std::string endNode) {
	std::vector<MapNode *> unvisited;
	std::map<MapNode *, int> dist;
	std::map<MapNode *, MapNode *> prev;

	for (auto const &node : m_nodes) {
		dist[node] = INT_MAX;
		prev[node] = NULL;
		unvisited.push_back(node);
	}

	dist[getNode(startNode)] = 0;

	while (!unvisited.empty()) {
		MapNode *closest = unvisited[0];
		for (auto const &curNode : unvisited)
			if (dist[curNode] < dist[closest])
				closest = curNode;

		if (closest == getNode(endNode)) {
			std::vector<std::string> shortestPath;
			while (prev[closest] != NULL) {
				shortestPath.insert(shortestPath.begin(), closest->getName());
				closest = prev[closest];
			}
			shortestPath.insert(shortestPath.begin(), closest->getName());

			return shortestPath;
		}

		unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), closest), unvisited.end());

		for (auto const &neighbor : closest->getEdges()) {
			int alt = dist[closest] + neighbor.second;
			if (alt < dist[neighbor.first]) {
				dist[neighbor.first] = alt;
				prev[neighbor.first] = closest;
			}
		}
	}

	return std::vector<std::string>(0);
}

void Map::printShortestPath(std::string startNode, std::string endNode) {
	std::vector<std::string> path = shortestPathS(startNode, endNode);

	std::string pathString = "";
	for (auto const &name : path)
		pathString += name + ", ";

	std::cout << "Shortest path from \"" << startNode.c_str() << "\" to \"" << endNode.c_str() << "\":" << std::endl;
	std::cout << pathString.substr(0, pathString.length() - 2).c_str() << std::endl;
}