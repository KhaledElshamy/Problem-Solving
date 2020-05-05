class Solution {
private: 
    void uniqueCombinations(vector<int>& candidates,int sum,vector<int>& v, vector<vector<int> >& res,int index ){
        
        if(sum<0)return ;
        
        if(sum == 0){
            res.push_back(v);
            return ;
        }
        
        while(index<candidates.size() && sum-candidates[index]>=0){
            v.push_back(candidates[index]);
            uniqueCombinations(candidates,sum-candidates[index],v,res,index);
            index++;
            v.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int> v;
        vector<vector<int> > res;
        uniqueCombinations(candidates,target,v,res,0);
            
        return res;
    }
};
