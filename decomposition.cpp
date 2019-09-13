#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string operation_code;
	is >> operation_code;

	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stop_number = 0;
		is >> stop_number;
		q.stops.resize(stop_number);
		for (auto& stop : q.stops) {
			is >> stop;
		}
	} else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	int buses_count = 1;
	vector<string> buses;
};

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

struct StopsForBusResponse {
	int stops_count = 1;
	string bus;
	vector<pair<string, vector<string>>> stops_buses;
};

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

struct AllBusesResponse {
	int buses_count = 1;
	map<string, vector<string>> buses_to_stops;
};

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

class BusManager {
public:

	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops.insert(make_pair(bus, stops));
		for (const auto& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse res;
		if (stops_to_buses.count(stop) == 0) {
			res.buses_count = 0;
		} else {
			res.buses = stops_to_buses.at(stop);
		}
		return res;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
			StopsForBusResponse res;
			vector<pair<string, vector<string>>> stops_buses;
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

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse res;
		if (buses_to_stops.size() == 0) {
			res.buses_count = 0;
		} else {
			res.buses_to_stops = buses_to_stops;
		}
		return res;
	}

private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;

};

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
	  cin >> q;
	  switch (q.type) {
	  case QueryType::NewBus:
	    bm.AddBus(q.bus, q.stops);
	    break;
	  case QueryType::BusesForStop:
	    cout << bm.GetBusesForStop(q.stop) << endl;
	    break;
	  case QueryType::StopsForBus:
	    cout << bm.GetStopsForBus(q.bus) << endl;
	    break;
	  case QueryType::AllBuses:
		cout << bm.GetAllBuses() << endl;
	    break;
	  }
	}

	return 0;
}