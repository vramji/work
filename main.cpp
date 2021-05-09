#include <iostream>
#include <string>
#include <regex>
#include "hiker.h"

#if 1
void ParseInput() {
  string s ("bridges: \n  - bridge name:\n \
      - length: 2 \n\
      - Hiker 1: 4 \n \
        Hiker2: 2 \n \
  - bridge name: \n \
      - length: 4 \n \
      - Hiker3: 4 \n \
        Hiker5: 5 \n \
        Hiker4: 2");
  istringstream s1 (s);
  string s2;
  int listlevel = 0;
  int bridge_id = 0;
  Bridge *bridge = NULL;
  Hiker *hiker = NULL;
  vector < Bridge *> bridges;
  vector < vector < Hiker *>> hikers;
  vector < Hiker * > hiker_level;
  int num_bridges = 0;
  bridge = new Bridge(bridge_id, 0);
  while (s1.good ())
    {
      std::getline (s1, s2);
      std::smatch m, m1;
      cout << "line is " << s2 << endl;
      std::regex list_val ("-[ ]+");
      std::regex map_val (":[ ]+");

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
	  cout << "MAP val found at " << 
                 m.prefix ().length () << m.prefix () << endl;
	  std::cout << m.suffix ();
	  cout << endl;
	  string hikername = "";
          str = m.prefix ().str ();
          p = str.find_first_not_of (" -");
	  cout << "AT " << p << endl;
	  hikername = str.substr (p, string::npos);
	  cout << "hiker name is " << hikername << endl;
	  str = m.suffix ().str ();
	  p = str.find_first_not_of (" ");
	  cout << "speed string is " << str << endl;
	  int speed = stoi (str.substr (p, string::npos));
	  //cout << "speed is " << speed << endl;
          if (list_found) {
	      listlevel = m1.prefix ().length ();
          } 
          if (hikername.compare("length") == 0) {
              if (bridge) {
                  bridge->set_length(speed);
                  bridges.push_back(bridge);
                  num_bridges++;
                  cout << "inserted bridge " << bridge->get_id() << " " << speed << endl;
              }
              continue;
          }
          cout << "hiker name is NOT LENGTH " << "|" << hikername << "|" << endl;
          hiker = new Hiker(hikername, speed);
          hiker_level.push_back(hiker);
	}
      else if (list_found)
	{
	  std::cout << "FOUND list " << listlevel << " prefix length " << m1.prefix().length() << endl;
	  if (m1.prefix ().length () < listlevel)
	    {
	      bridge_id++;
              hikers.push_back(hiker_level);
	      hiker_level.clear ();
              bridge = new Bridge(bridge_id, 0);
              cout << "new list created bridge " << bridge->get_id() << endl;
	    }
	  listlevel = m1.prefix ().length ();
	  cout << "list found at " << m1.prefix ().
	  length () << " " << listlevel << " id " << bridge_id << endl;
	  cout << endl;
	}
        cout << "list level is now " << listlevel << endl << endl << endl;
    }
    if (hiker_level.size() != 0) {
          hikers.push_back(hiker_level);
    }

#if 1
    // Print
    cout << "bridges " << num_bridges << endl << "-------------" << endl;
    for (int i = 0; i < num_bridges; ++i) {
        cout << bridges[i]->get_id() << " " <<  bridges[i]->get_length() << " ";
    }
    cout << endl;
    cout << " hikers " << endl << "-----------------" << endl;
    for (int i = 0; i < hikers.size(); ++i) {
        cout << "Hiker at Bridge " << i << endl;
        for (int j = 0; j < hikers[i].size(); ++j) {
            cout << hikers[i][j]->get_name() << " " << hikers[i][j]->get_speed() << endl;
        }
    }
#endif
}
#endif
int main() {
    ParseInput();
    string s = "ramji";
    Hiker hik(s, 20);
    string s1 = "r";
    Hiker hik1(s1, 2);
    string s2 = "r1";
    Hiker hik2(s2, 1);
    vector<Bridge *> bridges;
    Bridge a1(0, 40);
    Bridge a2(0, 20);
    bridges.push_back(&a1);
    bridges.push_back(&a2);
    vector<vector<Hiker *>> H;
    vector<Hiker *> H1, H2;
    H1.push_back(&hik);
    H2.push_back(&hik1);
    H2.push_back(&hik2);
    H.push_back(H1);
    H.push_back(H2);
    cout << ComputeFastestTime(bridges, H) << endl;
    cout << "done" << endl;
    return 0;
}

