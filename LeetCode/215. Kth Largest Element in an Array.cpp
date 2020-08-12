class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i=0;i<k;i++)pq.push(-nums[i]);
        
        for(int i=k;i<(int)nums.size();i++){
            if(-nums[i]<pq.top()){
                pq.pop();
                pq.push(-nums[i]);
            }
        }
        
        int peek = -pq.top();
        return peek;
    }
};
