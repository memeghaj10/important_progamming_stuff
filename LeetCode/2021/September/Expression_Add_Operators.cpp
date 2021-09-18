class Solution {
public:
    vector<string> ValidExp;
    void calc(string &num,int index,long last,long &result,int &target,string &expression)
    {
        if(index==num.length())
        {
            if(result==target)
              ValidExp.push_back(expression);
            return;
        }
        for(int i=index;i<num.length();i++)
        {
            string subStr=num.substr(index,i-index+1);
            long val=stol(subStr);
            long newResult=result+val;
            expression+=index==0?subStr:"+"+subStr;
            calc(num,i+1,val,newResult,target,expression);
            index==0?expression.erase():expression.erase(expression.length()-(i-index+2)); 
            if(index!=0)
            {
                newResult=result-val;
                expression+="-"+subStr;
                calc(num,i+1,-1*val,newResult,target,expression);
                expression.erase(expression.length()-(i-index+2));
                newResult=result-last+last*val;
                expression+="*"+subStr;
                calc(num,i+1,last*val,newResult,target,expression);
                expression.erase(expression.length()-(i-index+2));
            }
            if(num[index]=='0')
                break;
        }
    }
    
    
    vector<string> addOperators(string num, int target) 
    {
        string exp;
        long result=0;
        calc(num,0,0,result,target,exp);
        return ValidExp;
    }
};