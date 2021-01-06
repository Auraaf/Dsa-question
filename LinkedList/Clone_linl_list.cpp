Node *copyList(Node *head) 
{
      Node *temp , *nd ,*cur;
      temp = head ;
      
      while (temp != NULL )
      {    
           cur= temp->next ;
           nd = new Node(temp->data) ;
           nd -> next = cur ;
           temp->next = nd ;
           
           
           temp = cur ;
        }
        
     cur = head ;
    /* while (cur!=NULL)
     {
        cout<<cur->data<<" ";
     cur = cur->next; 
     }*/
     cur = head;
     Node* n_head = NULL ;
     
     while (cur != NULL)
     {   
         temp = cur->next ;
         //cout<<cur->data<<" ";
         nd = temp->next ;
         if (n_head==NULL)
         n_head = temp ;
         if (nd!=NULL)
         temp->next = nd->next ;
         if (cur->arb != NULL)
         temp->arb = cur->arb->next ;
         cur = nd ;
         
     }
     
     cur = n_head ;
    /* while (cur != NULL)
     {
         cout<<cur->data<<" ";
         if (cur->arb != NULL)
         cout<<cur->arb->data<<" ";
         cur = cur->next;
     }*/
     return n_head;
}
