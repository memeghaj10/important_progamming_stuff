/*

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note:

Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

*/


//Approach-1 Using Logarithmic Functions and Properties:



class Solution {
public:
    int divide(int dividend, int divisor) {
        
                if(dividend==0) {
                    return 0;
                }
        
                double t1=log(fabs(dividend));
                double t2=log(fabs(divisor));
        
                long long result=double(exp(t1-t2));
        
                if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)) {
                    result*=-1;
                }
        
                return result>INT_MAX? INT_MAX:result;
        
    }
};




//Approach-2 Using Bit Manipulation:


class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n=dividend, m=divisor;
        if(n <= INT_MIN && m == -1) return INT_MAX;

        int sign = (n < 0) ^ (m < 0) ? -1: 1;

        n=abs(n);
        m=abs(m);

        long long q=0, temp=0;

        for(int i=31; i>=0; i--){
            if(temp + (m << i) <= n){
                temp += m << i;
                    q += 1 << i;      
            }
        }
        return sign * q;
    }
};