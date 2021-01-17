/* A binary tree node
struct Node
{   
    int data;
    Node* left, * right;
}; */
    
vector<vector<int>> mtx ;
int htr ; 
void diag(Node*root , int ht )
{
    if (root != NULL)
    {
        htr = max(ht , htr ) ;
        mtx[ht].push_back(root->data) ;
        diag(root->left , ht+1) ;
        diag(root->right , ht) ;
    }
}

vector<int> diagonal(Node *root)
{   
    
    vector<int> ans ;
    htr = 0 ; 
    mtx.assign(1e5 + 1 , ans ) ;
    diag(root , 0 ) ;
    for (int i = 0 ; i<= htr ;i++)
    for (int a : mtx[i])
    ans.push_back(a);
    return ans ;
}   
