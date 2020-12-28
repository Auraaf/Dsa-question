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



Node * removeDuplicates( Node *head) 
{
 vector<int> ch(1e4+1 , 0 ) ;
 
 Node *temp , *prv ;
 temp =head ;
 while (temp != NULL)
 {   
     if (ch[temp->data] ==0)
     { 
       prv = temp ;
       ch[temp->data]= 1 ;
         
     }
     else
     prv -> next  = temp->next ;
     temp = temp->next ;
         
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
  int n,k ;
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
  
      head = removeDuplicates(head) ;
      print_list(head );
  
}
