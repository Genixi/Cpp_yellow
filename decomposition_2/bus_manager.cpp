#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	buses_to_stops.insert(make_pair(bus, stops));
	for (const auto& stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	BusesForStopResponse res;
	if (stops_to_buses.count(stop) == 0) {
		res.buses_count = 0;
	} else {
		res.buses = stops_to_buses.at(stop);
	}
	return res;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	StopsForBusResponse res;
	vector<pair<string, vector<string> > > stops_buses;
	res.bus = bus;
	if (buses_to_stops.count(bus) == 0) {
		res.stops_count = 0;
	} else {
		for (const string& stop : buses_to_stops.at(bus)) {
			stops_buses.push_back(make_pair(stop, stops_to_buses.at(stop)));
		}
	}
	res.stops_buses = stops_buses;
	return res;
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse res;
	if (buses_to_stops.size() == 0) {
		res.buses_count = 0;
	} else {
		res.buses_to_stops = buses_to_stops;
	}
	return res;
}
