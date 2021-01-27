void max_heapify(vector<int> &arr , int  i  )
{
	  if (i < arr.size())
	{   
	    //cout<<arr[i]<<" ";
		int l , r , sz;
		l = 2*i + 1 ;
		r = 2*i + 2 ;
		sz= arr.size() ;
		int large ;
		if (l < sz && arr[i] < arr[l])
		large = l ;
		else
		large = i ;
		if (r < sz && arr[large] < arr[r])
		large = r ;

		if (large != i)
		{
		    swap (arr[large] , arr[i]) ;
 			max_heapify(arr , large) ;
		}
	}
		
	
}

void build_heap(vector<int> &arr )
{
    int sz = arr.size() ;
	for(int i = (sz / 2) ; i >= 0 ; i--)
	max_heapify(arr , i) ;
}
