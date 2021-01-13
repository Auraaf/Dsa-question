vector<int> ht , ans  ;
void inorder(Node* root , int hgt)
{
    if (root != NULL)
    {
        if (!ht[hgt])
        ans.push_back(root->data) ;
        ht[hgt] = 1  ;
        
        inorder(root->right , hgt + 1) ;
        inorder(root->left , hgt + 1) ;
    }
}


// Should return  right view of tree
vector<int> rightView(Node *root)
{
   ht.assign(101 , 0 ) ;
    ans.clear() ;
    inorder(root , 0) ;
    return ans;
}

