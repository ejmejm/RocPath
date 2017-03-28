#include "Map.h"

int main(int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;

	Map map;
	map.addNode(new MapNode("Rush Rhees"));
	map.addNode(new MapNode("Morey"));
	map.addNode(new MapNode("Lattimore"));
	map.addNode(new MapNode("Strong"));
	map.addNode(new MapNode("Schlegel"));
	map.addNode(new MapNode("Dewey"));
	map.addNode(new MapNode("Hoyt"));
	map.addNode(new MapNode("B&L"));
	map.addNode(new MapNode("Meliora"));
	map.addNode(new MapNode("Wilco"));
	map.addNode(new MapNode("Douglass"));

	map.addUEdge("Rush Rhees", "Morey", 77);
	map.addUEdge("Rush Rhees", "B&L", 65);
	map.addUEdge("Rush Rhees", "Douglass", 103);
	map.addUEdge("Rush Rhees", "Wilco", 136);
	map.addUEdge("Rush Rhees", "Meliora", 110);
		   
	map.addUEdge("Morey", "B&L", 77);
	map.addUEdge("Morey", "Douglass", 140);
	map.addUEdge("Morey", "Wilco", 109);
	map.addUEdge("Morey", "Hoyt", 92);
	map.addUEdge("Morey", "Dewey", 133);
	map.addUEdge("Morey", "Lattimore", 105);
		   
	map.addUEdge("Lattimore", "B&L", 122);
	map.addUEdge("Lattimore", "Strong", 94);
	map.addUEdge("Lattimore", "Schlegel", 100);
	map.addUEdge("Lattimore", "Dewey", 71);
	map.addUEdge("Lattimore", "Hoyt", 101);
		   
	map.addUEdge("Strong", "Schlegel", 90);
	map.addUEdge("Strong", "Dewey", 123);
		   
	map.addUEdge("Schlegel", "Dewey", 118);
		 
	map.addUEdge("Dewey", "Hoyt", 75);
	map.addUEdge("Dewey", "B&L", 118);
		   
	map.addUEdge("Hoyt", "B&L", 52);
		   
	map.addUEdge("B&L", "Meliora", 144);

	map.print();

	map.printShortestPath("Douglass", "Hoyt");

	std::cin.get();
}