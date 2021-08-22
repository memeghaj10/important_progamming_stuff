class Solution {
public:
    
    // TIME COMPLEXITY:- O(N^3)
    // SPACE COMPLEXITY:- O(N^2)
    
    #define ll long long
    #define MOD 1000000007
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> x,y;ll ans = 0;
        for(auto v:rectangles){
            x.insert(v[0]);x.insert(v[2]); // store all unique x coordinates
            y.insert(v[1]);y.insert(v[3]); // store all unique y coordinates
        }
        int index = 0; 
        unordered_map<int,int> coord_x,coord_y;
        for(auto it:x){
            coord_x[it] = index++; // assigning all unique x --> index
        }
        index = 0;
        for(auto it:y){
            coord_y[it] = index++; // assigning all unique x --> index
        }
        vector<int> x_val(x.begin(),x.end()); // store x coordinates in a vector
        vector<int> y_val(y.begin(),y.end()); // store y coordinates in a vector
        vector<vector<bool>> vis(x.size(),vector<bool>(y.size(),false));
        for(auto v:rectangles){
            for(auto start_x=coord_x[v[0]];start_x<coord_x[v[2]];start_x++){
                for(auto start_y=coord_y[v[1]];start_y<coord_y[v[3]];start_y++){
                    if(!vis[start_x][start_y]){ // if current state hasn't been visited
                        ll width = x_val[start_x+1] - x_val[start_x];
                        ll height = y_val[start_y+1] - y_val[start_y];;
                        ans = (ans + (width*height)%MOD)%MOD;
                    }
                    vis[start_x][start_y] = true;
                }
            }
        }
        return ans;
    }
};