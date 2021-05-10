
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Maintains information on a single Hiker (name and speed).
class Hiker {
    string name;
    int    speed;
public:
    Hiker(string hiker_name, int speed);
    int get_speed() { return this->speed;}
    string get_name() { return this->name;}
};

// Maintains information on a single Bridge (index and length of the Bridge).
class Bridge {
    int Bridge_idx;
    int length;
public:
    Bridge(int idx, int l) {
        Bridge_idx = idx;
        length = l;
    }
    int get_length() {
        return length;
    }
    void set_length(int len) {
        this->length = len;
    }
    int get_id() {
        return Bridge_idx;
    }
};

double ComputeFastestTime(vector<Bridge *>& bridges,
                          vector<vector<Hiker *>>& hikers);

