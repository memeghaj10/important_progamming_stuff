class Solution {
public:
    Node* flatten(Node* head) {
        Node *ptr = head, *tmp_next, *runner;
        
        while (ptr) {
            if (ptr->child) {
                
                // Save the current next and connect the child to next
                tmp_next = ptr->next;
                ptr->next = ptr->child;
                ptr->next->prev = ptr;
                ptr->child = NULL;
                
                // Run till the end of the current list and connect last node to saved next
                runner = ptr->next;
                while (runner->next) runner = runner->next;
                runner->next = tmp_next;
                if (runner->next) runner->next->prev = runner;
            }
            
            ptr = ptr->next;
        }
        
        return head;
    }
};