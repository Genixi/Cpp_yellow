#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse {
	int buses_count = 1;
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	int stops_count = 1;
	string bus;
	vector<pair<string, vector<string> > > stops_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	int buses_count = 1;
	map<string, vector<string> > buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

