class Solution {
public:
    
    int max(int a , int b) {return a > b ? a : b ;} 
    int max(int a , int b, int c) {return max(max(a,b) , c) ;}
    
    // MARK -- return the maximum sum of leftSubArray and rightSubArray
    int maxCrossingSum(vector<int>& numbers , int start , int mid , int end) {
        
        int sum = 0 ;
        int leftSum = INT_MIN ;
        
        for(int i=mid ; i>= start ; i--){
            sum += numbers[i];
            if(sum > leftSum){
                leftSum = sum ; 
            }
        }
        
        sum = 0 ;
        int rightSum = INT_MIN ;
        
        for(int i=mid+1 ; i<= end ; i++){
            sum += numbers[i];
            if(sum > rightSum){
                rightSum = sum ; 
            }
        }
        
        return leftSum + rightSum ;
    }
    
    // MARK -- return the maximum sum of a subarray
    int maxSubArraySum(vector<int>& numbers , int start , int end){
        if(start == end){
            return numbers[start];
        }
        
        int mid = (start+end) / 2 ;
        
        return max(maxSubArraySum(numbers,start , mid), maxSubArraySum(numbers,mid+1 , end),maxCrossingSum(numbers , start , mid , end));
        
    }
    
    int maxSubArray(vector<int>& nums) {
       
        int start = 0 ;
        int end = nums.size() - 1 ;
        int max_sum = maxSubArraySum(nums, start, end); 
        return max_sum ; 
    }
};
