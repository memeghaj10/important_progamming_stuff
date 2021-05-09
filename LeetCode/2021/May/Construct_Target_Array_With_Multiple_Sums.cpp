class Solution {
public:
    bool isPossible(vector<int>& t) {
        
        priority_queue<int> q(cbegin(t),cend(t));
        
        auto sum=accumulate(cbegin(t),cend(t),(long long )(0));
        
        while(q.top()>1) {
                
            const auto current_sum=q.top();
            q.pop();
            auto sum_before=sum-current_sum;
            if(sum_before==1) {
                return true;
            }
            if(sum_before==0) {
                return false;
            }
            const auto new_val=current_sum%sum_before;
            
            if(new_val>=current_sum||new_val<=0) {
                return false;
            }
            
            q.push(new_val);
            sum=sum_before+new_val;
            
        }
        
        return true;
        
    }
};