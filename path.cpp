#include "path.hh"

using namespace std;
using namespace Earth;

#define INF 42000
#define END_OF_PATH -1

QNode getMin(std::vector<QNode>& q){
  QNode min = q[0];
  unsigned int  index;
  for(unsigned int i=0; i<q.size(); i++){
    if(min.total_distance > q[i].total_distance){
      min = q[i];
      index = i;
    }
  }
  q.erase(q.begin()+index);
  return min;
}



Path::Path(Net& net, const string& start, const string& destination){
  City *city_A = net.findCity(start);
  City *city_B = net.findCity(destination);

  if(city_A == nullptr)
    cout << "There is no city called " << start << " in the database" << endl;
  else if(city_B == nullptr)
    cout << "There is no city called " << destination << " in the database" << endl;
  else{
    unsigned int length = net.getCities().size();
    double *ArrayOfDistance = new double[length];
    vector<QNode> q(length);
    vector<int> previous(length);
    for(unsigned int i=0; i<length; i++)
      previous[i] = END_OF_PATH;
    
    //Dijkstra's algorithm
 
    for(unsigned int i=0; i<length; i++){
       ArrayOfDistance[i] = INF;
    }
    ArrayOfDistance[city_A->getNumber()] = 0;
    
    for(unsigned int i=0; i<length; i++){
      q[i].vertice = net.getCities()[i];
      q[i].total_distance = ArrayOfDistance[i];
    }
  
    while(q.size() != 0){
      QNode currentNode = getMin(q);
      vector<Connection> *pNeighbors = new vector<Connection>;
      pNeighbors = net.findConnections(currentNode.vertice.getName());

      if(pNeighbors != nullptr){
        vector<Connection> neighbors = *pNeighbors;
        for(auto& neighbor : neighbors){
	        if(ArrayOfDistance[neighbor.getCity_B().getNumber()] > ArrayOfDistance[currentNode.vertice.getNumber()] + neighbor.distance()){
            ArrayOfDistance[neighbor.getCity_B().getNumber()] = ArrayOfDistance[currentNode.vertice.getNumber()] + neighbor.distance();
            previous[neighbor.getCity_B().getNumber()] = currentNode.vertice.getNumber();
          }
        }
      }
      delete pNeighbors;
    }
  
    //setting the shortest distance from A to B
    totalDistance = ArrayOfDistance[city_B->getNumber()];
    delete[] ArrayOfDistance;

    int index = city_B->getNumber();

    do{
      for(auto& city : net.getCities()){
        if(city.getNumber() == index){
          cities.insert(cities.begin(), city);
          index = previous[index];
          break;
        }
      }
    }while(index != END_OF_PATH);
    
    //connecting cities
    for(unsigned int i=0; i<cities.size()-1; i++){
      Connection *c = new Connection(cities[i], cities[i+1]);
      connections.push_back(*c);
      delete c;
    }
  }
}
