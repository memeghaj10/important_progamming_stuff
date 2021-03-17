class Solution {
public:
    double r,x,y;
    
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    double random() {
        return (double)rand()/RAND_MAX;
    }
    
    vector<double> randPoint() {
        vector<double> random_p(2);
        
        double len=sqrt(random())*r;
        double deg=2*M_PI*random();
        
        random_p[0]=x+len*cos(deg);
        random_p[1]=y+len*sin(deg);
        
        
        return random_p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */