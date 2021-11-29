#include "net.hh"

using namespace std;
using namespace Earth;

void Net::showCities(){
  for(auto& city : cities)
    cout << city << endl;
}

void Net::showConnections(){
  for(auto& connection : connections)
    cout << connection << endl;
}

City* Net::findCity(const std::string& cityName){
  for(auto& city : cities){
    if(city.getName() == cityName)
      return &city;
  }
  return nullptr;
}

vector<Connection>* Net::findConnections(const string& c_name){
  vector<Connection> *vecConnections = new vector<Connection>;
  Connection *n_con;
  for(auto& connection : connections){
    if(c_name == connection.getCity_A().getName()){
      n_con = new Connection(connection.getCity_A(), connection.getCity_B());
      vecConnections->push_back(*n_con);
      delete n_con;
    }else if(c_name == connection.getCity_B().getName()){
      n_con = new Connection(connection.getCity_B(), connection.getCity_A());
      vecConnections->push_back(*n_con);
      delete n_con;
    }
  }
  if(vecConnections->size() == 0) return nullptr;
  return vecConnections;
}

Net::Net(string fileName){
  fstream file;
  char help = '#';
  string start, destination;
  file.open(fileName, ios::in);
  if(!file.good())
    throw invalid_argument("File does not exist");

  while(help == '#'){
    file >> help;
    if(help == '#'){
      City *c = new City;
      file >> *c;
      cities.push_back(*c);
      delete c;
    }
  }

 

  if(help == '.'){
    help = '#';
    while(help == '#'){
      file >> help;
      if(help == '#'){
	      file >> start >> destination;
	      City* c_start = findCity(start);
	      City* c_destination = findCity(destination);
        Connection* con = new Connection(*c_start, *c_destination);
        connections.push_back(*con);
        delete con;
      }
    }
  }
}


