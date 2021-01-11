/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<vector<int>> hgt ;
int ht_tr  ;

void pre_order(Node* root ,int ht)
{
    hgt[ht].push_back(root->data) ;
    ht_tr =  max(ht_tr , ht) ;
    
    if (root->left!=NULL)
    pre_order(root->left , ht + 1) ;
    
    if (root->right!=NULL)
    pre_order(root->right , ht + 1) ; 
}

vector<int> reverseLevelOrder(Node *root)
{   
    vector<int> ans ;
    ht_tr = 0 ;
    hgt.assign(1e4+1 , ans);
    pre_order(root , 0 ) ;
    for (int i = ht_tr ; i > -1 ; i--)
    for (int j : hgt[i])
    ans.push_back(j) ;
    return ans ;
}
