/*
staring from the end, checking each index in one loop
in another loop storing the max count element that can be stored
such that it's greater then current element(as if it is greater then current element than all element after it will obivoulsy grater than this)
finally returning the max_element in storage array 
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size() ;
        
        vector<int> str(n , 1 ) ;
        
        str[n-1] = 1 ;
        for (int i = n-2 ; i>= 0 ; i--){
            for (int j = i+1 ; j< n ; j++)
                if (nums[i] < nums[j])
                str[i] = max(str[i] , str[j] + 1) ;
        }
        
        return *max_element(str.begin() , str.end()) ;
    }
};
