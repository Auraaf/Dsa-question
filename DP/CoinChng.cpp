long long int count( int S[], int m, int n )
    {
       
        vector<int> cns(m , 0 ) ;
	    
	    for (int i =0  ; i< m ; i++)
	    cns[i] = S[i] ;
	    sort(cns.begin() , cns.end()) ;
	    vector<ll int> row(n + 1 , 0 ) ;
	    vector<vector<ll int>> mtx ( m  , row ) ;
	    
	   
	    
	    for (int i = 0 ; i<= n ; i++)
	     {
	      
	     if ( i % cns[0] == 0 ) 
	        mtx[0][i] = 1; 
	      else  mtx[0][i] = 0 ; 
	      
	     }
	     
	     
	     for (int i = 0 ; i < m ; i++)
	      mtx[i][0] = 1 ;
	     
	    /* for (int i = 0  ; i < m ; i++)
	    {
	      for (int j = 0 ; j<= n ; j++)
	      cout<<mtx[i][j]<<" ";
	      cout<<endl;
	    }
	     cout<<endl;*/
	     for (int i = 1  ; i < m ; i++)
	     for (int j = 1 ; j<= n ; j++)
	     {
	          if ( j - cns[i] >=0 )
	              {
	                 mtx[i][j] = mtx[i - 1][j] + mtx[i][j - cns[i]] ;
	                 
	              }
	              else
	              mtx[i][j] = mtx[i - 1][j] ;
	     }
	   /* for (int i = 0  ; i < m ; i++)
	    {
	      for (int j = 0 ; j<= n ; j++)
	      cout<<mtx[i][j]<<" ";
	      cout<<endl;
	    }*/
	      
	    return mtx[m-1][n] ;
    }
