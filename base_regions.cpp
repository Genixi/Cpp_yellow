int FindMaxRepetitionCount(const vector<Region>& regions){
	int max = 1;
	int count = 1;
	if (regions.size() == 0) {
		return 0;
	}
	for(auto& x : regions) {
		count = 0;
		for(auto& y : regions) {
			if(y.std_name == x.std_name && y.parent_std_name == x.parent_std_name && y.population == x.population){
				if(y.names.at(Lang::DE) == x.names.at(Lang::DE) && y.names.at(Lang::FR) == x.names.at(Lang::FR) && y.names.at(Lang::IT) == x.names.at(Lang::IT)) {
					count++;
				}
			}
		}
		if(count > max) {
			max = count;
		}
	}
	return max;
}
