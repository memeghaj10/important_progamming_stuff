class MyCircularQueue {
public:
    vector<int> v;
    int size=0;
    
    
    MyCircularQueue(int k) {
       size=k;
    }
    
    bool enQueue(int value) {
        if(v.size()<size) {
            v.push_back(value);
            return true;
        }
        return 0;
   }
    
    bool deQueue() {
        
        if(v.size()==0) {
            return 0;
        }
      
         vector<int> r=v;
           reverse(r.begin(),r.end());
           r.pop_back();
           reverse(r.begin(),r.end());
           v=r;
       
        return 1;
    }
    
    int Front() {
        if(v.size()==0) {
            return -1;
        }
        return v[0];
    }
    
    int Rear() {
        if(v.size()==0) {
            return -1;
        }
        
        int x=v[v.size()-1];
        cout<<x<<endl;
        return x;
        
    }
    
    bool isEmpty() {
        if(v.size()==0) {
            return 1;
        }
        return 0;
    }
    
    bool isFull() {
        if(v.size()==size) {
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */