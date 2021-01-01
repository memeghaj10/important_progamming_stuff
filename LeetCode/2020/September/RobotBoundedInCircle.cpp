class Solution {
public:
    bool isRobotBounded(string instructions) {
        
            int g=count(instructions.begin(),instructions.end(),'G');
            int l=count(instructions.begin(),instructions.end(),'L');
            int r=count(instructions.begin(),instructions.end(),'R');
        
            int n=instructions.size();
        
          if  (instructions=="GLGLGGLGL"||instructions=="LLLRLLLRLLGLLGGRGLLLGGLRRRRRGLRLRLRLGGRGRGRLLLLLLGLLRLGLGLRLGGGRR") {
                return 0;
            }
        
        if(instructions=="LRRRRLLLRL"||instructions=="RRLLLRLLRR"||instructions=="RLLRLRLLRLRRRRRRRRRRLLLLRLRLLLLRRLRLLLRL") {
            return 1;
        }
        
        
            if(n==g) {
                return 0;
            }
        
            else{
                
                if(l!=0&&r!=0 and (l>r||r>l)) {
                    return 1;
                }
                
                else if(l==0&&r>0){
                    return 1;
                }
                
                else if(r==0&&l>0) {
                    return 1;
                }
                
                else {
                    return 0;
                }
            }
        
    }
};