class Solution {
public:
    string intToRoman(int num) {
        
        map<int,string> mp;
        
        mp[1]="I";
        mp[5]="V";
        mp[10]="X";
        mp[50]="L";
        mp[100]="C";
        mp[500]="D";
        mp[1000]="M";
        mp[4]="IV";
        mp[9]="IX";
        mp[90]="XC";
        mp[40]="XL";
        mp[400]="CD";
        mp[900]="CM";
        
        vector<int> v;
        v={1,4,5,10,50,500,1000,9,40,400,900,100,90};
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        string s="";
        
        for(int i=0;i<v.size();i++) {
            while(num>=v[i]) {
                s+=mp[v[i]];
                num-=v[i];
            }
        }
        
        return s;
        
    }
};