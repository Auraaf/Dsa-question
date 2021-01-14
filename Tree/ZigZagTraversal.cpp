/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return a vector containing the zig zag level order traversal of the given tree
vector<vector<int>> hgt ;

int ht_tr ;
void pre_order(Node* root ,int ht)
{
    hgt[ht].push_back(root->data) ;
    ht_tr = max (ht_tr , ht) ;
    if (root->left!=NULL)
    pre_order(root->left , ht + 1) ;
    
    if (root->right!=NULL)
    pre_order(root->right , ht + 1) ; 
}

vector <int> zigZagTraversal(Node* root)
{   
    vector<int> ans ;
    ht_tr = 0 ;
    hgt.assign(1e4+1 , ans);
    pre_order(root , 0 ) ;
    int k = 1 ;
    for (int i = 0 ; i <= ht_tr ; i++)
    {
        if (k)
        {
            k = 0 ;
            for (int j = 0 ; j< hgt[i].size() ; j++)
            ans.push_back(hgt[i][j]);
        }
        
        else
        {
            k = 1 ;
            for (int j = hgt[i].size() - 1  ; j > -1  ; j--)
            ans.push_back(hgt[i][j]);
        }
    }
    return ans ;
}
