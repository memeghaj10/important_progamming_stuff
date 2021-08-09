/*

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.

*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string ans="";
        int carry=0;
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int i,j;
        
        for(i=0,j=0;i<num1.size()&&j<num2.size();i++,j++) {
            int sum=num1[i]-'0';
            sum+=num2[j]-'0';
            sum+=carry;
            
            ans+=('0'+sum%10);
            carry=sum/10;
        }
        
        while(i<num1.size()) {
            int sum=num1[i]-'0';
            sum+=carry;
            ans+=('0'+sum%10);
            carry=sum/10;
            i++;
        }
        
        while(j<num2.size()) {
            int sum=num2[j]-'0';
            sum+=carry;
            ans+=('0'+sum%10);
            carry=sum/10;
            j++;
        }
        
        if(carry) {
            ans+=('0'+carry);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};