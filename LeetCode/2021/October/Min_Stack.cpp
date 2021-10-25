class MinStack {
public:
    stack<int> st;
   int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
       st.push(val);
        mini=min(mini,val);
    }
    
    void pop() {
        st.pop();
        vector<int> v;
        mini=INT_MAX;
        while(st.size()!=0) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++) {
            mini=min(mini,v[i]);
            st.push(v[i]);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */