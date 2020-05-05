class Solution {
public:
    
    int firstIndex(vector<int>& nums,int low,int high,int target,int size){
        if(high>=low){
            int mid = low + (high - low)/2;
            if((mid == 0 || nums[mid-1] < target) && nums[mid] == target)
                return mid;
            else if(target <= nums[mid])
                return firstIndex(nums,low,mid-1 ,target,size);
            else 
                return firstIndex(nums,mid+1,high,target,size);
        }
        return -1 ;
    }
    
    
    int lastIndex(vector<int>& nums,int low,int high,int target,int size){
        if(high>=low){
            int mid = low + (high - low)/2;
            if( (mid == size - 1 || nums[mid+1] > target) && nums[mid] == target)
                return mid;
            else if(target >= nums[mid])
                return lastIndex(nums,mid+1,high,target,size);
            else 
                return lastIndex(nums,low,mid-1,target,size);
        }
        return -1 ;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int startingPos =  firstIndex(nums,0,size-1,target,size);
        int endingPos = lastIndex(nums,0,size-1,target,size);
        vector<int> res;
        
        res.push_back(startingPos);
        res.push_back(endingPos);
        return res ;
    }
};
