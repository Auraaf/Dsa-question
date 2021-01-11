/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */

int  ans ;

int dia_fin(Node*root)
{
    if (root != NULL)
    {
        int lt , rt ;
        lt = dia_fin(root->left) ;
        rt= dia_fin(root->right) ;
        //cout<<root->data<<" "<<lt<<" "<<rt<<endl;
        ans = max (ans , lt + rt + 1) ;
        return (max (lt, rt) + 1) ;
        
    }
    return 0 ;
}
int diameter(Node* root) 
{
    ans = 0 ; 
    dia_fin(root) ;
    return ans;
}
