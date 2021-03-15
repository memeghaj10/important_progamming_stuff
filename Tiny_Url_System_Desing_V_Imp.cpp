class Solution {
public:

    unordered_map<string,string> short_to_long,long_to_short;
    
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long_to_short.count(longUrl)) {
            return long_to_short[longUrl];
        }
        
        string dict="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        
        string result="";
        
        while(result.size()) {
            for(int i=0;i<6;i++) {
                result+=(dict[rand()%dict.size()]);
            }
            if(short_to_long.count(result)) {
                result.clear();
            }
        }
        
        short_to_long[result]=longUrl;
        long_to_short[longUrl]=result;
        
        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));