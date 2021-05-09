
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hiker {
    string name;
    int    speed;
public:
    Hiker(string hiker_name, int speed);
    int get_speed() { return this->speed;}
    string get_name() { return this->name;}
};

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
};

double ComputeFastestTime(vector<Bridge *>& bridges, vector<vector<Hiker *>>& hikers);

