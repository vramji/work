#include <iostream>
#include <unordered_map>
#include <string>
#include "hiker.h"

using namespace std;

Hiker::Hiker(string hiker_name, int speed) {
    name = hiker_name;
    this->speed = speed;
}

/*
 * Computes the time taken to cross a single bridge.
 * The list of hikers includes the hikers who crossed
 * previous bridges as well as the new hikers who joined
 * in this bridge.
 * returns the total time taken to cross this bridge.
 */
static double ComputeFastestTime(double bridge_length, vector<Hiker *> hiker_list) {
   int no_hikers = 0, i;
   double total_time = 0.0;
   int fastest_hiker_index = 0, fastest_hiker_speed = 0;
   no_hikers = hiker_list.size();

   // If there are no hikers, nothing to do.
   if (no_hikers <= 0) {
       return 0;
   }

   // If there is only one hiker, one trip is sufficient.
   if (no_hikers == 1) {
       total_time += bridge_length / (hiker_list[0]->get_speed());
       return total_time;
   }

   for (i = 0; i < no_hikers; ++i) {
       if ((hiker_list[i]->get_speed()) > fastest_hiker_speed) {
           fastest_hiker_index = i;
           fastest_hiker_speed = (hiker_list[i]->get_speed());
       }
   }
   for (i = 0; i < no_hikers; ++i) {
       if (i != fastest_hiker_index) {
           total_time += bridge_length / (hiker_list[i]->get_speed());
       }
   }
   total_time += ((no_hikers - 2) * bridge_length / fastest_hiker_speed);
   return total_time;
}
/*
 * Computes the time taken to cross all bridges.
 * bridges is an sequence of bridges.
 * hikers[i] is an array of hiker names corresponding to bridges[i]
 * returns the total time taken to cross all the bridges.
 */
double ComputeFastestTime(vector<Bridge *>& bridges, vector<vector<Hiker *>>& hikers)
{
   int bridge_id, no_hikers = 0;
   vector<Hiker *> curr_hikers;
   double total_time = 0.0;
   int num_bridges = bridges.size();
   for (bridge_id = 0; bridge_id < num_bridges; ++bridge_id) {
       // Calculate time to cross 'i'th bridge of length bridges[i]
       // (n-1) roundtrips and 1 one-way trip
       // Include hikers in previous trips - hikers[i] includes hikers newly added in bridge i alone
       for (int j = 0; j < hikers[bridge_id].size(); ++j) {
           curr_hikers.push_back(hikers[bridge_id][j]);
       }
       total_time += ComputeFastestTime((double)(bridges[bridge_id]->get_length()), curr_hikers);
   }
   return total_time;
}

