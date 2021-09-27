class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;
        for(auto & email:emails)
        {
            int pos = email.find('@');
            string domain = email.substr(pos);
            string local_name=email.substr(0,pos);
            if((pos=local_name.find('+'))!=string::npos)
               local_name.erase(pos);
            pos=-1;
            while((pos=local_name.find('.',pos+1))!=string::npos)
               local_name.erase(pos,1);
            unique_emails.insert(local_name+domain);
        }
        return unique_emails.size();
        
    }
};