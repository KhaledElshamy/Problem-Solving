class Solution {
private:
    vector<int>tree;
    
    int buildTree(int start, int end, int p){ 
        if(start == end) return tree[p] = 1; 
        int mid = (start+end) / 2;
        return tree[p] = buildTree(start,mid,2*p + 1) + buildTree(mid+1,end,2*p + 2);
    }
    
    static bool cmp(vector<int> &a,vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    void getIndex(int start, int end, int value, int p, int &index) {
        
        if(start > end) return;
        
        if(start == end){
            tree[p]--;
            index = start;
            return ;
        }
        
        int mid = (start+end) / 2;
        if(tree[2*p+1] - value > 0){
            tree[p]--;
            getIndex(start,mid,value,2*p+1,index);
        }else {
            tree[p]--;
            value -= tree[2*p+1];
            getIndex(mid+1,end,value,2*p+2,index);
        }
        return ;
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       
        sort(people.begin(),people.end(),cmp);
        
        int n = people.size();
        int size=1;
        
        while(size<n)
            size*=2;
        int arrsize = size-1;
        size*=2;
        tree.resize(size, 0);
        
        buildTree(0,n-1,0);
        vector<vector<int>>res(n);
            
        for(int i=0; i< n; i++) {
            int index = 0;
            getIndex(0,n-1,people[i][1],0,index);
            res[index].push_back(people[i][0]) ;
            res[index].push_back(people[i][1]);
        }
        return res;
    }
};
