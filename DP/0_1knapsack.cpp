	#include<bits/stdc++.h>
	using namespace std;
        #define ll long long
    
	vector<long long int> str ;
        vector<int> val , wat ;
        vector<pair<int, int >> vpr ;
        
         int wt_mx ( int wt , int i , int n  )
         {
             if ( wt > 0 && i < n && vpr[i].first <= wt )
		return max ( vpr[i].second + wt_mx ( wt - vpr[i].first , i+ 1 , n  ) , wt_mx ( wt , i + 1 , n ) ) ;
                 
             else 
		return 0  ;    
         }
         
         
	int main()
	{
		ifstream fin ;
		fin.open("input.txt") ;
		
		int n , w ; 
		fin>>n>>w ;
		
		val.assign( n , 0 ) , wat.assign(n , 0 ) ;
		
		for ( int i =  0 ; i< n; i++ )
		fin>>val[i] ;
		
		for ( int i =  0 ; i< n; i++ )
		fin>>wat[i] ;
		
		for ( int i = 0 ; i< n ; i++ )
		vpr.push_back( make_pair(wat[i] , val[i]) ) ;
		
		sort(vpr.begin() , vpr.end() ) ;
		
		cout<<wt_mx(w , 0 , n) <<endl;
	}
