#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses_count == 0) {
		os << "No stop" << endl;
	} else {
		for (const string& bus : r.buses) {
			os << bus << " ";
		}
		os << endl;
	}
	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops_count == 0) {
		os << "No bus" << endl;
	} else {
		for (const auto& stop_bus : r.stops_buses) {
			os << "Stop " << stop_bus.first << ": ";
			if (stop_bus.second.size() == 1) {
				os << "no interchange";
			} else {
				for (const auto& other_bus : stop_bus.second) {
					if (other_bus != r.bus) {
						os << other_bus << " ";
					}
				}
			}
			os << endl;
		}
	}
	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_count == 0) {
		os << "No buses" << endl;
	} else {
		for (const auto& bus_item : r.buses_to_stops) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	return os;
}


