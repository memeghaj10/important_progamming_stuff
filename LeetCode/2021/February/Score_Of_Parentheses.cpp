class Solution {
public:
    int scoreOfParentheses(string S) {
        // push mode or pop mode 
        // Add multiplier
        
        int res = 0; 
        int multiplier=1;
        bool push=false; // assuming before "(" is false 
        for (int i=0; i<S.size(); i++) {
            if (S[i] == '(' && !push) { // first "(" and "(" after a ")"
                push = true; 
            }
            else if (S[i] == '(' && push) { // weights increase
                multiplier *= 2; 
            }
            else if (S[i] == ')' && push) { // start calculating contribution 
                // start to pop
                res += multiplier; 
                push = false; 
            }
            
            else { // S[i] == ')' ; decreasing contribution to result by 2 for future "("
                multiplier /= 2; 
            }
            
        }
        
        return res; 
        
    }
};