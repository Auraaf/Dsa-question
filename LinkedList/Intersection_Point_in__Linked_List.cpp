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

int fin_size(Node*head)
   {
       int cnt = 0 ;
       
       while (head != NULL)
       {
           cnt += 1 ;
           head = head -> next ;
       }
       return cnt ;
   }
   
int intersectPoint(Node* head1, Node* head2)
{
    
    int sz1 , sz2 ;
    sz1 = fin_size(head1);
    sz2= fin_size(head2);
    if (sz1 > sz2)
     while (sz1 != sz2)
        {
          sz1 -= 1 ;
          head1 = head1 -> next ;
        }
    else 
     while (sz1 != sz2)
        {
          sz2 -= 1 ;
          head2 = head2 -> next ;
        }
    
    while (head1 != head2)
    {
       head1 = head1 -> next ;
       head2 = head2 -> next ;
    }
    return head1->data;   
}
Node* input_list(int size)
{
   int data;
   Node*head =NULL ;
   for (int i = 0 ; i< size ;i++)
   {   cin>>data;
       Node*temp = new Node(data);
      
       temp ->next = head ;
       head = temp ;
    }
    return head ;
}
int main()
{
  int n , m , k ;
  cin>>n;
  Node* head1 = input_list(n) ;
  cin>>m;
  Node* head2 = input_list(m) ;
  cin>>k ;
  Node* common = input_list(k) ;
  Node* temp ;
  temp = head1 ;
  while (temp ->next != NULL)
  temp = temp->next ;
  temp->next = common;
  temp = head2 ;
  while (temp ->next != NULL)
  temp = temp->next ;
  temp->next = common;
  cout<<intersectPoint( head1, head2);
}
