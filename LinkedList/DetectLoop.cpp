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



bool detectLoop(Node* head)
{
    
    Node *sl , *fs ;
    sl = head , fs = head ;
    
    while (sl != NULL && fs -> next != NULL)
    {
        sl = sl -> next ;
        fs = fs -> next -> next ;
        if (sl == fs)
        return true ;
        if (fs == NULL)
        break ;
    }
    
    
    return false ;
    
    
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
  cin>>n >>k;
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
  
      if (detectLoop(head))
      cout<<"Have Loop";
      else
      cout<<"No Loop" ;
  
}
