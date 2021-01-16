/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

bool ans ;

int isBal(Node*root)
{
    if (root !=NULL)
    {
        int lt , rt ;
        lt = isBal(root->left) ;
        rt = isBal(root->right) ;
        if (abs(lt - rt) > 1)
        ans = false ;
        return max(lt, rt) + 1 ;
    }
    else return 0 ;
}

bool isBalanced(Node *root)
{
    ans = true ;
    isBal(root) ;
    return ans ;
}
