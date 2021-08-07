/*



*/


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    
     int n=0;
     int m=0;
     
     Node* h1=head1;
     Node* h2=head2;
     
     while(h1) {
         n++;
         h1=h1->next;
     }
     
     while(h2) {
         m++;
         h2=h2->next;
     }
     
     int diff=abs(m-n);
     
     Node* t1=head1;
     Node* t2=head2;
     
     if(n>m) {
         while(diff--) {
             t1=t1->next;
         }
     }
     
     if(m>n) {
         while(diff--) {
             t2=t2->next;
         }
     }
     
     while(t1->next!=t2->next) {
         t1=t1->next;
         t2=t2->next;
     }
     
     if(t2) {
         return t2->next->data;
     }
     
     return -1;
    
}
