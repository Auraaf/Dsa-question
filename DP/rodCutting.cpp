   
/*
 this is top down approach, always  have an eyes on infinite recursion due to wrong param passing.
 login here is : you cut one piece than let rest of the rod give recursively maximum  profit,
                  finally you will return max 
                  profit = max (profit , recCall (rod - i ) + costPr[i] ) ;
*/   
vector<int> szPr , memoz ;
    int szN ;

    int recCut(int n ){
          //cout<<"1\n" ;
          if (n > 0){
              //cout<<"in\n" ;
              int cost = 0 ;
              
              for (int i = 1 ; i <= n ; i++ ) 
              {
                  if (memoz[n-i] == -1)
                      memoz[n-i] = recCut(n-i) ;
                  
                  cost = max ( cost , szPr[i -1] + memoz[n-i]) ; 
              }
              
              return cost ;
          }
        else return 0  ;
    }

    int cutRod(vector<int> &price, int n)
    {
        szPr.assign(n , 0) ;
        memoz.assign(n , -1) ;
        
        szPr = price ;
        szN = n ;
        return recCut(n) ;
    }

