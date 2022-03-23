# include<bits/stdc++.h>
using namespace std ;
// Checking the changes
//*0. is subset with given sum sn exist
vector<int> subSm(vector<int> arr , int sn , int n){

    vector<int> num(sn+1 , 0 ) ;
    vector<vector<int>> t( n+1 ,num) ;

    for (int i =0 ; i<= n ; i++)
    t[i][0] = 1 ;
    for (int j = 1  ; j<= sn ; j++)
    t[0][j] = 0 ;

    for (int i = 1 ; i<= n ;i++){

        for (int j = 1 ; j <= sn ; j++){
            if ( j - arr[ i -1 ] >= 0 )
            t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            else
            t[i][j] = t[i-1][j] ;
        }
    }

    vector<int> req;
    
    for (int  k : t[n]) {
        cout<<k<<" ";
    req.push_back(k) ;
    }
    
    return req ;

}


/*1 . recursion of Cnt subset Sum 
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.
Example:

Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}
*/
int cntSubSm(vector<int> arr , int sn ,int n ){
      //cout<<sn<<endl;
      if ( n < 0 ) return 0 ;
      if (sn < 0 ) return  0 ;

      else if (sn == 0 ) 
         return 1 ;

// using arr[n-1] and without using arr[n-1] total subset formed
      else if (sn - arr[ n -1 ] >= 0){
             return (cntSubSm( arr , sn - arr[n-1] , n-1) + cntSubSm(arr , sn , n -1 )) ;
      }

      else
      return cntSubSm(arr , sn , n-1) ;
 // tabulatio real dp  
 /*
 Intitlaize   t[n+1][sn+1] ;
  -> i = 0 t[i][j] = 0 ;
  -> j = 0 t[i][j] = 1 ;
  i = 1 -> n , j  = 1 -> sn // inclusive
for (int i = 1 ; i<=n ; i++)
            for (int j =1 ; j<=sm ; j++){
               
                if ( j - nums[i-1] >= 0 )
                     t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
 */
}


/*
2 . Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
*/

int mnDifSm(vector<int> arr , int n , int s1 , int s2){
     if (n == 0){
         cout<<s1<<" "<<s2<<endl;
          return abs(s1 - s2 ) ;
          }
   
    
        int dif1 = mnDifSm( arr , n - 1 , s1+ arr[n-1] , s2 ) ;
        int dif2 = mnDifSm(arr , n -1 , s1 , s2 + arr[n-1]) ;
        
        return min (dif1 , dif2 ) ;
    
}
// another approach using range 
int mnmDifSm (vector<int> arr , int n , int sn){
   
  // using subset sum for this soln. only last row required expl in copy 

   vector<int> req = subSm(arr, sn , n ) ;
    for (int k : req)
    cout<<k<<" ";
    cout<<endl;
   int ans = INT_MAX ;

   // looking for acheivable max subset sm, i.e. to minmize Range - 2*s1. 
   //I used sbsm last row to check if it's 1 it means this index (which refer sum of subset) exist.
   for (int i = 0 ; i<= (sn/2) + 1 ; i++ )
   if (req[i] == 1)
   ans = min ( ans , sn - 2*i) ;

   return ans;
  
}

int main(){
     int n ;
     ifstream fin;
     fin.open("input.txt");
     fin>>n;
     vector<int> arr(n , 0) ;


     for (int &a : arr)
     fin>>a;

for (int a : arr) cout<<a<<" ";
     int k ; fin>>k ;
     cout<< mnmDifSm(arr, n ,  accumulate(arr.begin() , arr.end() , 0 )  ) ;    
     
}
