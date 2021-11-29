#include "earth.hh"

using namespace std;

Earth::City::City(){
  number=n;
  n++;
}

Earth::Connection::Connection(Earth::City a, Earth::City b){
  city_A = a;
  city_B = b;
  setDistance();
}

void Earth::Connection::setDistance(){
  double phi_1 = city_A.getPosition().width.value * M_PI/180;
  double phi_2 = city_B.getPosition().width.value * M_PI/180;
  double lambda_1 = city_A.getPosition().length.value * M_PI/180;
  double lambda_2 = city_B.getPosition().length.value * M_PI/180;

  if(city_A.getPosition().width.direction == S)
    phi_1 *= -1;
  if(city_B.getPosition().width.direction == S)
    phi_2 *= -1;
  if(city_A.getPosition().length.direction == W)
    lambda_1 *= -1;
  if(city_B.getPosition().length.direction == W)
    lambda_2 *= -1;

  double d_lambda = lambda_1 - lambda_2;

  d = RADIUS * acos(sin(phi_1)*sin(phi_2) + cos(phi_1)*cos(phi_2)*cos(d_lambda));
}

fstream& Earth::operator>>(fstream& file, Earth::Point& point){
  char help;
  file>>point.value;
  file>>help;
  switch(help){
  case 'N':
    point.direction = N;
    break;
  case 'S':
    point.direction = S;
    break;
  case 'E':
    point.direction = E;
    break;
  case 'W':
    point.direction = W;
    break;
  default:
    throw invalid_argument("Invalid geographical coordinates");
    break;
  }
  return file;
}

fstream& Earth::operator>>(fstream& file, Earth::Position& position){
  file >> position.width >> position.length;
  return file;
}

fstream& Earth::operator>>(fstream& file, Earth::City& city){
  file >> city.getName();
  file >> city.getPosition();
  return file;
}

fstream& Earth::operator>>(fstream& file, Earth::Connection& con){
  file>>con.getCity_A() >> con.getCity_B();
  return file;
}

ostream& Earth::operator << (ostream& screen, Earth::City& city){
  cout << city.getName() << " " << city.getPosition().width.value << " ";
  switch(city.getPosition().width.direction){
    case Earth::N:
    cout << "N ";
    break;
    case Earth::S:
    cout << "S";
    break;
    default:
    break;
  }
  cout << city.getPosition().length.value << " ";
  switch(city.getPosition().length.direction){
    case Earth::E:
    cout << "E";
    break;
    case Earth::W:
    cout << "W";
    break;
    default:
    break;
  }
  return screen;
}

ostream& Earth::operator << (ostream& screen, Earth::Connection& connection){
  cout << connection.getCity_A().getName() << " - " << connection.getCity_B().getName() << endl;
  cout << connection.distance();
  return screen;
}
