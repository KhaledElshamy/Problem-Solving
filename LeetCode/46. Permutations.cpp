class Solution {
public:
    vector<vector<int> > permutaions;
    void permute(vector<int>& nums,int start,int end){
        
        if(start == end){
            permutaions.push_back(nums);
        }else{
            for(int i=start;i<=end;i++){
                swap(nums[start],nums[i]);
                
                permute(nums,start+1,end);
                
                swap(nums[start],nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size() - 1;
        permute(nums,0,size);
        return permutaions; 
    }
};
