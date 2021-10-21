class RandomizedSet {
public:
    set<int> st;
    /** Initialize your data structure here. */
    RandomizedSet() {
        st.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      if(st.find(val)==st.end()) {
          st.insert(val);
          return true;
      }  
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(st.find(val)!=st.end()) {
            st.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int num=rand()%st.size();
        auto it=st.begin();
        while(num--) {
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */