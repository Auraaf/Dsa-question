#define ll long long 
 
ll int cnt ;

void merge(int l , int m , int r , vector<long long> &arr )
{
    int lf = m - l + 1 ;
    int rt = r - m    ;
    
    vector<long long> l_arr(lf) , r_arr(rt) ;
    
    for (int i = l ; i<= m ; i++)
    l_arr[i - l] = arr[i] ;
    
    for (int i = m + 1 ; i<= r ; i++)
    r_arr[i - (m + 1)] = arr[i] ;
    
    int i = 0 , j = 0 , k = l ;
    
    while (i < lf && j < rt ) 
    {
        if (l_arr[i] <= r_arr[j])
        {
            arr[k] = l_arr[i] ; 
            i += 1 ;
        }
        
        else
        {
            arr[k] = r_arr[j] ; 
            j+= 1 ; cnt += (lf - i ) ;
        }
        k += 1 ;
    }
    
    while (i < lf)
    {
       arr[k] = l_arr[i]; i++; k +=1;
    }
    
    while (j < rt)
    {
       arr[k] = r_arr[j]; j++; k+=1;
    }
    
    
       
}

void merge_srt(int l, int r, vector< long long > &arr)
{
    if (l < r  )
    {
        int m = ( r + l  ) / 2 ;
       // cout<<cnt;
        merge_srt (l , m , arr); 
        merge_srt(m +1 , r , arr );
        merge(l ,m ,  r , arr) ;
    } 
}

long long int inversionCount(long long arr[], long long N)
{
    cnt = 0 ;
    vector<ll > ar(N) ;
    for (int i = 0 ; i< N ;i++)
    ar[i] = arr[i] ;
    merge_srt(0 , N- 1 , ar);
    return cnt ;
}
