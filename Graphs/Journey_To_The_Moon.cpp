/*

    The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example



There are  astronauts numbered  through . Astronauts grouped by country are  and . There are  pairs to choose from:  and .

Function Description

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

int n: the number of astronauts
int astronaut[p][2]: each element  is a  element array that represents the ID's of two astronauts from the same country
Returns
- int: the number of valid pairs

Input Format

The first line contains two integers  and , the number of astronauts and the number of pairs.
Each of the next  lines contains  space-separated integers denoting astronaut ID's of two who share the same nationality.

Constraints

Sample Input 0

5 3
0 1
2 3
0 4
Sample Output 0

6
Explanation 0

Persons numbered  belong to one country, and those numbered  belong to another. 


Sample Input 1

4 1
0 2
Sample Output 1

5
Explanation 1

Persons numbered  belong to the same country, but persons  and  don't share countries with anyone else. 

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

void dfs(int node,vector<int>& vis,vector<int> adj[],int &c) {
    
    vis[node]=1;
    c++;
    
    for(auto x:adj[node]) {
        if(!vis[x]) {
            dfs(x,vis,adj,c);
        }
    }
    
}


int64_t journeyToMoon(int n, vector<vector<int>> astronaut) {
    
    vector<int> adj[n+1];
    
    for(int i=0;i<astronaut.size();i++) {
        adj[astronaut[i][0]+1].push_back(astronaut[i][1]+1);
        adj[astronaut[i][1]+1].push_back(astronaut[i][0]+1);
    }
    
    vector<int> vis(n+1,0);
    vector<int> counts;
    
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            int c=0;
            dfs(i,vis,adj,c);
            counts.push_back(c);
        }
    }

    int64_t ans=0;
    
    vector<int64_t> suffix(counts.size());
    
    suffix[counts.size()-1]=counts[counts.size()-1];
    
    for(int i=counts.size()-2;i>=0;i--) {
        suffix[i]=counts[i]+suffix[i+1];
    }

    
    for(int i=0;i<counts.size();i++) {
        int64_t y=counts[i];
        if(i+1!=counts.size()) {
            ans+=(y*suffix[i+1]);
        }
    }
    
    return ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int64_t result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
 
