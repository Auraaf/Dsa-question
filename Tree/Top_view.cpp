//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
map<int,pair<int , int> > vpr ;
set<int> chk ;
void inorder(Node* root , int ht , int height)
{
   if (root != NULL)
   {
       if (chk.find(ht) == chk.end())
       {
           chk.insert(ht) ;
           vpr[ht] = make_pair(height , root->data) ;
       }
       else if ( vpr[ht].first > height )
           vpr[ht] = make_pair(height , root->data) ;
       
           
       
       inorder(root->left , ht - 1 , height + 1) ;
       inorder(root->right , ht+ 1 , height + 1) ;
   }
   
}

void topView(struct Node *root)
{
    chk.clear() ;
    vpr.clear() ;
    inorder(root , 0 , 0 ) ;
    
    for (auto k : vpr)
    cout<<k.second.second<<" ";
    
 
    return;
}

