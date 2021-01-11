/*struct Node
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
class Solution{
    public:
    int height(struct Node* node){
        if (node != NULL)
        {
            return max (height(node->left) + 1 , height(node->right) + 1 ) ;
        }
        return 0 ;
    }
};
