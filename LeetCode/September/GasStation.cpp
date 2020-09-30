class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> b;
        
        for(int i=0;i<gas.size();i++) {
            if(gas[i]>=cost[i]) {
                b.push_back(i);
            }
        }
        
        if(b.size()==0) {
            return -1;
        }
        
        else {
            for(int i=0;i<b.size();i++) {
                
                int t=b[i];
                
                vector<int> g,c;
                
                g.push_back(gas[t]);
                c.push_back(cost[t]);
                
                for(int j=t+1;j<gas.size();j++) {
                    g.push_back(gas[j]);
                    c.push_back(cost[j]);
                }
                
                for(int j=0;j<t;j++) {
                    g.push_back(gas[j]);
                    c.push_back(cost[j]);
                }
                
                g.push_back(gas[t]);
                c.push_back(cost[t]);
                
                
                int y=g[0];
                    
                int f=0;
                
                for(int j=0;j<g.size()-1;j++) {
                    if(y-c[j]>=0) {
                        y=y-c[j]+g[j+1];
                      
                    }
                    
                    else {
                        f=1;
                        break;
                    }
                }
                
                if(f==1) {
                    continue;
                }
                
                else {
                    return t;
                }
                
            }
            
            
            return -1;
        }
        
        
    }
};