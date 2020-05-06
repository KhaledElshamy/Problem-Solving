class Solution {
private: 
    vector<vector<int> > permutations;
    set<vector<int> > s;
    
    void permute(vector<int>& nums,int start,int end){
        
        if(start == end){
            if(s.find(nums) == s.end())permutations.push_back(nums),s.insert(nums);
        }
        
        
        for(int i = start;i<=end;i++){
            
            swap(nums[start],nums[i]);
            
            permute(nums,start+1,end);
            
            swap(nums[start],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size() - 1;
        permute(nums,0,size);
        return permutations;
    }
};
