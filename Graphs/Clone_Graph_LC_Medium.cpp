/*

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

*/








/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


/*

Solution:-

1. we will perform basic BFS traversal, i.e. take out the first node from th queue, 
    
        - make their new copies and, then add them to the queue.

2. To solve for the neighbors list, every time we come across the unvisited/unmarked node of the parent node,
    we simply traverse it, and then whether it is marked or not, we add it to the cloned list of the parent node.

3. Finally as given in the question, that 1<=node->val<=100, therefore we return the least node, i.e. 1.
    by returning mp[1];

    here mp is (int,node) pair map, which is used to store the status/node of the nodes in the graph.


*/


class Solution {
public:
    Node* cloneGraph(Node* node) {
      
        if(node==NULL) {
            return nullptr;
        }
        
        unordered_map<int,Node*> mp;
        queue<Node*> q;
        
        mp[node->val]=new Node(node->val);
        
        q.push(node);
        
        while(q.size()!=0) {
            
            Node* r=q.front();
            q.pop();
            
            for(auto c:r->neighbors) {
                if(mp.find(c->val)==mp.end()) {
                    mp[c->val]=new Node(c->val);
                    q.push(c);
                }
                mp[r->val]->neighbors.push_back(mp[c->val]);
            }
            
        }
        
        return mp[1];
        
    }
};