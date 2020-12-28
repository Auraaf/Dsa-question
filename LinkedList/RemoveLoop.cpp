
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



void removeLoop(Node* head)
{
    if (isLoop(head))
    {
       Node *fs  , *sl ;
   
       fs = head ;  sl = head ;
       int cnt  = 0 ;
      while (fs != NULL && fs->next != NULL)
       {   
             
            fs = fs ->next->next ; 
            sl = sl -> next;
            if (fs == sl )
            break ;
            
           
       }
       sl = head ;
       while (fs != sl)
       {
           fs = fs -> next ;
           sl = sl -> next ;
       }
       
      sl = sl->next ;
      
      while (sl -> next != fs)
      sl = sl->next ;
        
        sl -> next = NULL;
    
       
        }

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
  
      head = removeLoop(head) ;
      print_list(head );
  
}
