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

Node* addOne(Node *head , int cry) 
{
    // Your Code here
    // return head of list after adding one
    Node* rev_head , *temp  ;
    rev_head = head;
    
    temp = rev_head ;
    if (cry)
    temp->data += 1 ;
    
   
     if (temp->data == 10 )
       {
           temp->data = 0 ;
           cry = 1 ;
       }
      else cry = 0; 
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
         temp = new Node(1) ;
         temp->next = head ;
         head = temp ;
    }
    return head;
    
    
    
}

Node* addTwoLists( Node* first,  Node* second)
{
    Node *temp =NULL  ,*nd ;
    
    first = reverseList(first ) ;
    second = reverseList(second ) ;
    int cry = 0 , dt ;
    
    
    while (first != NULL && second != NULL)
    {
        dt = first->data + second->data  + cry ;
        
        if (dt > 9)
        {
             cry = dt / 10 ;
             dt = (dt % 10);   
             
        }
       else
             cry = 0 ;
          
       nd = new Node(dt) ;
       
       nd -> next = temp ;
       temp = nd ;
        
       first = first ->next ;
       second = second -> next ;
    }
    
    if (second != NULL)
    temp = second ;
    else if (first != NULL)
    temp = first;
    else 
    {
       if (cry)
       {
           temp = new Node(1) ;
           temp -> next = nd ;
           return temp ;
       }
       else
       return nd ;
    }
  /*  while (first != NULL )
    {
        cout<<first->data<<" ";
        first = first ->next ;
    }
    cout<<endl;*/
    temp = addOne(temp , cry ) ;
    first = temp ;
   
    while (temp->next != NULL)
    temp = temp ->next ;
    temp->next = nd ;
    return first ;
    
    
   
    
    
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
  int n , m ;
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
  first = head ;
  head= NULL ;
  
  cin>>m ;
  for (int i =0 ; i< m ;i++)
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
      second = head ;
      head = addTwoLists( Node* first,  Node* second)
      print_list(head );
  
}

   

