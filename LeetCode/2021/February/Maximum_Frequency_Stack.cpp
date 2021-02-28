class FreqStack {
    
    map<int,int> mp;
    map<int,stack<int>> group;
    int max_freq;
    
public:
    FreqStack() {
        mp.clear();
        group.clear();
        max_freq=0;
    }
    
    void push(int x) {
        mp[x]++;
        max_freq=max(max_freq,mp[x]);
        group[mp[x]].push(x);
    }
    
    
    int pop() {
        int x=group[max_freq].top();
        group[max_freq].pop();
        mp[x]--;
        if(group[max_freq].size()==0) {
            max_freq--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */