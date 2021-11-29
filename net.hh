#ifndef NET_HH
#define NET_HH

#include "earth.hh"

/*
* This file contains information about class Net
* This class represents graph, where:
*   cities = vertices
*   connections = edges
*/
class Net{
protected:
  std::vector<Earth::City> cities;
  std::vector<Earth::Connection> connections;
public:
  /*
  * Prints all cities one by one
  */
  void showCities();
  /*
  * Prints all direct connections in the graph
  */
  void showConnections();

  //'get' type methods -  you can get the reference of a component
  std::vector<Earth::City>& getCities(){ return cities;}
  std::vector<Earth::Connection>& getConnections(){ return connections;}

  /*
  * This method finds a city in the graph and returns a pointer to it
  */
  Earth::City* findCity(const std::string& cityName);

  /*
  * This method finds all direct neighbors of a city called c_name
  */
  std::vector<Earth::Connection>* findConnections(const std::string& c_name);

  /*
  * Blank constructor
  */
  Net(){}

  /*
  * Constructor
  * It builds the graph by reading data from file called fileName
  */
  Net(std::string fileName);
};

#endif
