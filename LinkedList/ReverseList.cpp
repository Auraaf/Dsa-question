#include<bits/stdc++.h>
using namespace std ;

struct Node
{
   int data ;
   struct Node *next ;
   Node(int x )
   {
   data = x ;
   next = NULL ;
   }
};

 Node* reverseList( Node *head)
{
   Node  *temp ;
   Node *prv =NULL , *current;
   current = head ;
		   
   while (current != NULL )
   {    
       head = current ;
       temp = current->next;
       current -> next = prv;
       prv = current;
       current = temp ;

   }
   return head ;
   
}
void print_list(Node* head )
{
    while (head != NULL)
    {
       cout << head ->data<<" " ;
       head = head -> next ;
    }
    cout<<endl;
}

int main()
{
  int n ;
  cin>>n ;
  Node *head = NULL ;
  int val ;
  for (int i =0 ; i< n ;i++)
  {
      cin>>val ;
      Node *temp ;
      if (head == NULL)
      {
         head = new Node(val) ;
         temp = head ;  
      }
      
      else
      {
         temp->next = new Node(val);
         temp = temp->next ;
      }
      
  }
      print_list(head );
      head = reverseList(head) ;
      print_list(head );
  
}
