class Solution {
private: 
    set<vector<int> > s;
    void uniqueCombinations(vector<int>& candidates,int sum,int start,vector<int>& v, vector<vector<int> >& res){
        
        if(sum<0)return ;
        
        if(sum == 0){
            if(s.find(v) == s.end())res.push_back(v),s.insert(v);
            return ;
        }
        
        for(int index=start;index<candidates.size();index++){
            if(candidates[index]>sum)return ;
            v.push_back(candidates[index]);
            uniqueCombinations(candidates,sum-candidates[index],index+1,v,res);
            v.pop_back();
            while(index<candidates.size()-1 && candidates[index]==candidates[index+1])index++;
        }
        // while(index<candidates.size() && sum-candidates[index]>=0){
        //     v.push_back(candidates[index]);
        //     uniqueCombinations(candidates,sum-candidates[index],v,res,index);
        //     index++;
        //     v.pop_back();
        // }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int> v;
        vector<vector<int> > res;
        uniqueCombinations(candidates,target,0,v,res);
            
        return res;
    }
};
