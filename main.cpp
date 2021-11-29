#include "path.hh"

#define SHOW_CITIES '1'
#define SHOW_CONNECTIONS '2'
#define FIND_CONNECTION '3'
#define QUIT '4'

#define OPTIONS 4

int Earth::City::n = 0;

using namespace std;
using namespace Earth;

int main(){

  //reading database
  Net net("data/database.txt");

  //array of options
  string menu[OPTIONS] = {"1. Lista miast", "2. Polaczenia bezposrednie", "3. Wyszukaj polaczenie", "4. Zakoncz program"};

  //main loop
  while(true){
    system("CLS");

    //printing options
    for(auto& option : menu)
      cout << option << endl;
      
    char choice = getch();

    string start, destination;

    switch(choice){
    case SHOW_CITIES:
      system("CLS");
      net.showCities();
      getch();
      break;
    case SHOW_CONNECTIONS:
      system("CLS");
      net.showConnections();
      getch();
      break;
    case FIND_CONNECTION:
    {
      system("CLS");
      cout << "Wylot: ";
      cin >> start;
      cout << "Przylot: ";
      cin >> destination;

      Path *path = new Path(net, start, destination);
      path->showConnections();
      cout << "Calkowita odleglosc: " << path->getTotalDistance() << endl;
      getch();
      delete path;
      break;
    }
    case QUIT:
      break;
    }
    if(choice == QUIT) break;
  }
  system("CLS");
}
