map<int,pair<int , int> > vpr ;
set<int> chk ;
void inorder(Node* root , int ht , int height)
{
   if (root != NULL)
   { 
       
       if (chk.find(ht) == chk.end() )
       {
          vpr[ht] = make_pair(height , root->data) ;
          chk.insert(ht) ; 
       }
       
       else if (vpr[ht].first <= height)
       vpr[ht] = make_pair(height , root->data) ;
       
       inorder(root->left , ht - 1 , height + 1) ;
       inorder(root->right , ht+ 1 , height + 1) ;
   }
   
}


vector <int> bottomView(Node *root)
{
    chk.clear() ;
    vpr.clear() ;
    inorder(root , 0 , 0 ) ;
    vector<int> ans ;
    for (auto k : vpr)
    ans.push_back(k.second.second);
    
 
    return ans;
}
