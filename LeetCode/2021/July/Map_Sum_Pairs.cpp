class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        int increament = val - _dict[key].first;
        _dict[key].first = val;
        for(int i = key.size() - 1; i > 0; i--)
            _dict[key.substr(0,i)].second += increament;
    }
    
    int sum(string prefix) {
        return _dict[prefix].first + _dict[prefix].second;
    }
    
private:
    unordered_map<string, pair<int, int> > _dict; // the value of _dict is a pair, stores current value and prefix-sum
};