class Trie {
public:
set<string> data;
Trie() {

}

void insert(string word) {
    data.insert(word);
}

bool search(string word) {
    if(data.find(word)!=data.end())
        return true;
    return false;
}

bool startsWith(string prefix) {
    set<string> :: iterator it;
    for(it=data.begin();it!=data.end();it++)
    {
        int i=0,x=0;
        while(i<prefix.size()){
        if((*it)[i]==prefix[i]) 
        {
            x++;
        }
        else 
            break;
            if(x==prefix.size())
                return true;
            i++;
        }
    }
    return false;
}
};