class UndergroundSystem {
public:
    
    map<int,pair<string,int>> checkInfo;
    map<string,map<string,vector<int>>> time_table;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(checkInfo.find(id)==checkInfo.end()) {
            checkInfo[id]={stationName,t};
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        auto startInfo=checkInfo[id];
        int travel_time=t-startInfo.second;
        time_table[startInfo.first][stationName].push_back(travel_time);
        checkInfo.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        auto values=time_table[startStation][endStation];
        auto total=accumulate(values.begin(),values.end(),0);
        
        return (double)total/(double)values.size();
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */