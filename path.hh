#ifndef PATH_HH
#define PATH_HH

#include "net.hh"

/*
* This file contains information about class Path
*/

/*
* struct QNode - it required for creating a priority queue in Path's constructor
*/
struct QNode{
  Earth::City vertice;
  double total_distance;
};

/*
* Class Path
* This class is used to create the shortest Path from one city to another
* It inherits from class Net because a path in a graph is topologically another graph
*/
class Path : public Net{
private:
  using Net::showCities; //we don't need to use that for this class
  double totalDistance; //total length of path
public:
  //gets the total distance
  double& getTotalDistance(){ return totalDistance;}

  /*
  * Constructor
  * It uses Dijkstra's algorithm to find the shortest path between start and destination
  * Start and destination are names of two cities that belong to net
  */
  Path(Net& net, const std::string& start, const std::string& destination); 

  /*
  * Blank constructor
  */
  Path(){}
};

#endif
