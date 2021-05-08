typedef long long ll;

class Solution {
public:

    bool isPalindrome(ll num) {
        
        ll rev=0;
        ll temp=num;
        
        while(temp>0) {
            
            rev=rev*10+temp%10;
            temp/=10;
            
        }
        
        return rev==num;
        
        
    }
    
    ll createPalindrome(ll prefix,ll suffix) {
    
        while(suffix>0) {
            prefix=prefix*10+suffix%10;
            suffix/=10;
        }
        
        return prefix;
    
    }


    int superpalindromesInRange(string left, string right) {        
        int ans=0;
        ll l=stol(left);
        ll r=stol(right);
        
        ll sqrt_l=sqrt(l),sqrt_r=sqrt(r);
        ll num=0;
        
        for(ll i=1;num<=sqrt_r;i++) {
            num=createPalindrome(i,i);
            if(num>=sqrt_l&&num<=sqrt_r&&isPalindrome(num*num)) {
                ans++;
            }
            
            num=createPalindrome(i,i/10);
            if(num>=sqrt_l&&num<=sqrt_r&&isPalindrome(num*num)) {
                ans++;
            }            
        }
        
        return ans;        
    }
};