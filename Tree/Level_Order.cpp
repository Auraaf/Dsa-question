/* A binary tree Node

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

//You are required to complete this method
vector<int> levelOrder(Node* node)
{
     deque<Node*> dq;
     
     Node* temp = node ;
     dq.push_back(temp) ;
     vector<int> ans ;
     while (dq.size() != 0)
     {
         temp= dq.front() ;
         ans.push_back(temp->data) ;
         
         dq.pop_front() ;
         if (temp->left != NULL)
         dq.push_back(temp->left) ;
          if (temp->right != NULL)
         dq.push_back(temp->right) ;
     }
     return ans ;
}
