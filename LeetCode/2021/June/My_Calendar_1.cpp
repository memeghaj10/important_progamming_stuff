class MyCalendar {
public:
    
    set<pair<int,int>> st;
    
    MyCalendar() {
        st.clear();
    }
    
    bool book(int start, int end) {
        
        int f=0;
        
        for(auto x:st) {
            
            if(x.first>start&&x.first<end) {
                f=1;
            }
            
            if(x.second>start&&x.second<end) {
                f=1;
            }
            
            if(x.second<=end&&x.first>=start) {
                f=1;
            }
            
            if(x.second>=end&&x.first<=start) {
                f=1;
            }
            
        }
        
        if(!f) {
            st.insert(make_pair(start,end));
            return 1;
        }
        
        return 0;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */