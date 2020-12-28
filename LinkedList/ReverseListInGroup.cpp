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



struct Node *reverse (struct Node *head, int k)
{ 
    
    struct Node *prv = NULL , *new_nx , *temp , *current ;
    struct Node *bl_h , * bl_t , *prv_h , * prv_t = NULL ;
    
    current = head ;
    
    int tk = k ;
    int cnt = tk  ;
    while (current != NULL) 
    {
        
        if (tk != 0 )
        {
            if (tk == k)
            bl_t = current ;
            if (prv_t != NULL)
            prv_t -> next = current ;
            tk -= 1 ;
            if (cnt > 0 )
            head = current;
            temp = current -> next ;
            current -> next = prv ;
            prv = current ;
            current = temp ;
            
            
        }
        
        if (tk == 0 )
        {
            prv_t = bl_t ;
            prv = NULL ;
            tk = k ;
        }
        cnt -= 1 ;
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
  
      head = reverse(head,k) ;
      print_list(head );
  
}
