#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "hiker.h"

int ParseInput(string filename, vector < Bridge *> &bridges, vector < vector < Hiker *>> &hikers) {
  int listlevel = 0;
  int bridge_id = 0;
  Bridge *bridge = NULL;
  Hiker *hiker = NULL;
  vector < Hiker * > hiker_level;
  int num_bridges = 0;
  char line[256];
  fstream f_hdl;

  f_hdl.open(filename.c_str(), ios::in);
  if (!f_hdl.is_open()) {
      cout << "Error opening file " << filename << endl;
      return -1;
  }
  cout << "Reading Input from " << filename << endl;
  bridge = new Bridge(bridge_id, 0);
  while (f_hdl.good ())
    {
      f_hdl.getline(line, 256);
      string s2(line);
      std::smatch m, m1, m2;
      std::regex comment_val ("[ ]*#");
      std::regex list_val ("-[ ]+");
      std::regex map_val (":[ ]+");

      bool comment_found = (std::regex_search (s2, m2, comment_val));
      if (comment_found) {
          continue;
      }
      bool map_found = (std::regex_search (s2, m, map_val));
      bool list_found = (std::regex_search (s2, m1, list_val));
      string str;
      str = m.suffix ().str ();
      int p = str.find_first_not_of (" ");
      if ((str.length () <= 0) || (p < 0))
      {
          map_found = 0;
      }
      if (map_found)
	{
	  string hikername = "";
          str = m.prefix ().str ();
          p = str.find_first_not_of (" -");
	  hikername = str.substr (p, string::npos);
	  str = m.suffix ().str ();
	  p = str.find_first_not_of (" ");
	  int speed = stoi (str.substr (p, string::npos));
          if (list_found) {
	      listlevel = m1.prefix ().length ();
          } 
          if (hikername.compare("length") == 0) {
              if (bridge) {
                  bridge->set_length(speed);
                  bridges.push_back(bridge);
                  num_bridges++;
              }
              continue;
          }
          hiker = new Hiker(hikername, speed);
          hiker_level.push_back(hiker);
	}
      else if (list_found)
	{
	  if (m1.prefix ().length () < listlevel)
	    {
	      bridge_id++;
              hikers.push_back(hiker_level);
	      hiker_level.clear ();
              bridge = new Bridge(bridge_id, 0);
	    }
	  listlevel = m1.prefix ().length ();
	}
    }
    if (hiker_level.size() != 0) {
          hikers.push_back(hiker_level);
    }

    return 0;
}
int main(int argc, char *argv[]) {
    vector<Bridge *> bridges;
    vector<vector<Hiker *>> H;
    string filename = "input.yml";
    if (argc > 1) {
       filename = argv[1];
    }
    if (ParseInput(filename, bridges, H) < 0) {
        cout << "Cannot read Input file" << endl;
        return -1;
    }
    cout << "Time to cross the bridges is " << ComputeFastestTime(bridges, H) << endl;
    return 0;
}

