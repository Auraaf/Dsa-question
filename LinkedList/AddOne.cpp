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


Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    Node* rev_head , *temp  ;
    rev_head = reverseList(head);
    
    temp = rev_head ;
    int cry= 0 ;
    temp->data += 1 ;
    
   
     if (temp->data == 10 )
       {
           temp->data = 0 ;
           cry = 1 ;
       }
       
     temp  = temp->next ;
    while (temp!=NULL)
    {
       
       if (temp->data == 9 && cry)
       {
           temp->data = 0 ;
           cry = 1 ;
       }
       else if (cry)
       {
           temp->data += 1 ;
           cry = 0 ;
       }
       else
       cry = 0 ;
       temp  = temp->next ;
    }
    
   
   
    head = reverseList(rev_head);
     if (cry)
    {
         head ->data += 10;
    }
    return head;
    
    
    
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
  int n;
  cin>>n ;
  Node *head = NULL ;
  int val;
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
  
      head = addOne(head) ;
      print_list(head );
  
}
