#ifndef EARTH_HH
#define EARTH_HH

#define _USE_MATH_DEFINES

#include<iostream>
#include<string>
#include<math.h>
#include<fstream>
#include<conio.h>
#include<stdexcept>
#include<vector>

/*
* This file contains information about namespace Earth
*/

namespace Earth{
  const double RADIUS = 6371; //average radius of planet Earth

  enum Direction{N, S, W, E}; //geographical directions
  
  //One geographical coordinate - value and direction
  struct Point{
    Direction direction;
    double value; //in degrees
  };

  //Position on the spere
  struct Position{
    Point width;
    Point length;
  };
  
  /*
  * Class City
  */
  class City{
  private:
    std::string name;
    Position position;
    int number; //unique number for identification
  public:
    static int n; //for setting number
    //'get' type methods - you can get the reference of a component
    std::string& getName(){return name;}
    Position& getPosition(){return position;}
    int& getNumber(){ return number;}

    /*
    * Constructor
    * Sets unique of the city
    */
    City();
  };

  /*
  * Class Connection
  * It defines connection between 2 cities
  */
  class Connection{
  private:
    City city_A;
    City city_B;
    double d; //distance between two cities

    /*
    * This method calculates the shortest route between 2 cities
    * It uses the formula for ortodrome's length
    */
    void setDistance();
  public:
    //'get' type methods - you can get the reference of a component
    double& distance(){ return d;}
    City& getCity_A(){return city_A;}
    City& getCity_B(){return city_B;}

    /*
    * Constructor
    * It takes two arguments - know cities a and b
    * Calculates the distance by calling setDistance()
    */
    Connection(City a, City b);

    /*
    * Blank constructor
    * Sometimes useful
    */
    Connection(){}
  };

  /*
  * Overloads of operator >> for fstream and members of namespace Earth
  */
  std::fstream& operator>>(std::fstream& file, Point& point);
  std::fstream& operator>>(std::fstream& file, Position& position);
  std::fstream& operator>>(std::fstream& file, City& city);
  std::fstream& operator>>(std::fstream& file, Connection& con);


  /*
  * Overloads of operator << for ostream and City/Connection
  */
  std::ostream& operator<<(std::ostream& screen, City& city);
  std::ostream& operator<<(std::ostream& screen, Connection& connection);
}


#endif
