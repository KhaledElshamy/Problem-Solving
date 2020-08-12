typedef pair<int,int> ii ;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,ii> > pq;
        set<ii> s;
        
        for(int i=0;i<(int)nums1.size();i++){
            for(int j=0;j<(int)nums2.size();j++){
                int sum = -nums1[i] + -nums2[j];
                pq.push(make_pair(sum,ii(nums1[i],nums2[j])));
            }
        }
        
        int size = k < pq.size() ? k : pq.size();
        vector<vector<int>> result(size,vector<int>(2)); 
        
        for(int i=0;i<size;i++){
            pair<int,ii> top = pq.top();
            pq.pop();
            ii Pair = top.second;
            result[i][0] = Pair.first;
            result[i][1] = Pair.second;
        }
        
        return result;
    }
};
