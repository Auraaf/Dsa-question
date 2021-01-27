//Removing nums[0](i.e. ith max) every time till k - 1 nodes removes than current max at nums[0] is kth max.

void max_heapify(vector<int> &arr , int  i  , int sz )
{
	  if (i < sz)
	{   
	    //cout<<arr[i]<<" ";
		int l , r ;
		l = 2*i + 1 ;
		r = 2*i + 2 ;
		
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
 			max_heapify(arr , large , sz) ;
		}
	}
		
	
}


void build_heap(vector<int> &arr , int sz )
{
    
	for(int i = (sz / 2) ; i >= 0 ; i--)
	max_heapify(arr , i , sz) ;
}
    

    int findKthLargest(vector<int>& nums, int k) 
    {
     
        build_heap(nums , nums.size()) ;
        int i = 0 ;
        int n = nums.size() ;
        //Removing nums[0](i.e. ith max) every time till k - 1 nodes removes than current max at nums[0] is kth max.

        for (int i = 1 ;i <= k- 1; i++)
        {   swap (nums[0] , nums[n - i]);
            max_heapify(nums ,0,n - i ) ;
        }
        return nums[0] ;
    }
};
