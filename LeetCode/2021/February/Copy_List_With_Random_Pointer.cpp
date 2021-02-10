/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // if head is nullptr  , return the nullptr
        if(head == nullptr){
            return nullptr;
        }
        
        //we will just replicate the old list for only next pointer only
        
        
        Node* temp = head;          //temporary pointer for head of original list
        Node* head1 = new Node(temp->val);      //head1 is head for duplicate list
        Node* temp1 = head1 ;               //temp1 is the temporary pointer for head1(duplicate list)
        temp=temp->next;
        while(temp!=nullptr){
            Node* nn = new Node(temp->val);
            temp1->next = nn;
            temp1 = temp1->next;
            temp  = temp->next;
        }
        
        //so here , our duplication for the next pointer is completed so we can just copy random pointer now
        
        
        
        temp = head;
        temp1 = head1;
        
        while(temp!=nullptr){
            Node* MyTarget = temp->random;       //MyTarget node stores the random pointer of original list
            Node* temp_0 = head;                //now search for the target in original using next pointer and simultaneously move duplicate list's another pointer
            Node* temp1_0 = head1;                  //and make it point to the required node
            while(temp_0 != nullptr){
                if(temp_0 == MyTarget){
                    temp1->random = temp1_0;
                    break;
                }
                temp_0 = temp_0->next;
                temp1_0 = temp1_0->next;
            }
            
            temp = temp->next;
            temp1 = temp1->next;
        }
        
        return head1;                   //return the head for the duplicate node
    }
};