#include <iostream>
#include <string>
#include <regex>
#include "hiker.h"

#if 1
void ParseInput() {
  string s ("bridges: \n- bridge name:\n \
      - length: 2 \n\
      - Hiker 1: 4 \n \
        Hiker2: 2 \n \
  - bridge name: \n \
      - length: 4 \n \
      - Hiker3: 4 \n \
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
  while (s1.good ())
    {
      std::getline (s1, s2);
      std::smatch m;

      std::regex list_val ("-[ ]+");
      std::regex map_val (":[ ]+");

      if (std::regex_search (s2, m, map_val))
	{
	  cout << "map val found at " << m.prefix ().length () << m.
	    prefix () << endl;
	  std::cout << m.suffix ();
	  cout << endl;
	  string hikername = "";
	  string str = m.prefix ().str ();
	  int p = str.find_first_not_of (" -");
	  cout << "AT " << p << endl;
	  hikername = str.substr (p, string::npos);
	  cout << "hiker name is " << hikername << endl;
	  str = m.suffix ().str ();
	  p = str.find_first_not_of (" ");
	  cout << "speed string is " << str << endl;
	  if ((str.length () <= 0) || (p < 0))
	    {
	      continue;
	    }
	  int speed = stoi (str.substr (p, string::npos));
	  cout << "speed is " << speed << endl;
          if (hikername.compare("length") == 0) {
              if (bridge) {
                  bridge->set_length(speed);
              }
              continue;
          }
          hiker = new Hiker(hikername, speed);
          hiker_level.push_back(hiker);
	}
      else if (std::regex_search (s2, m, list_val))
	{
	  std::cout << m.suffix () << " ";
	  if (m.prefix ().length () < listlevel)
	    {
	      bridge_id++;
              hikers.push_back(hiker_level);
	      hiker_level.clear ();
              bridge = new Bridge(bridge_id, 0);
	    }
	  listlevel = m.prefix ().length ();
	  cout << "list found at " << m.prefix ().
	    length () << " " << listlevel << " id " << bridge_id << endl;
	  cout << endl;
	}
    }
}
#endif
int main() {
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

