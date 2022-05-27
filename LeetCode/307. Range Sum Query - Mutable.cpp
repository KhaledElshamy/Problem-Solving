class NumArray {
private:
    vector<int> interval;
    int size = 0;
    
    int buildTree(vector<int>& arr, int start, int end, int p){ 
        if(start == end) return interval[p] = arr[start]; 
        int mid = (start+end) / 2;
        return interval[p] = buildTree(arr,start,mid,2*p + 1) + buildTree(arr,mid+1,end,2*p + 2);
    }
    
    void updateKthElement(int kth, int val, int start, int end, int p) {
        if(start == end && kth == start) {
            interval[p] = val; 
            return;
        }
        
        if(end<kth || start > kth)
            return ;
        
        int mid = (start + end) /2;
        updateKthElement(kth,val,start,mid,2*p+1) ;
        updateKthElement(kth,val,mid + 1,end,2*p+2);
        interval[p] = interval[2*p+1] + interval[2*p+2];
        return;
    }
    
    int getSumRange(int left, int right, int start, int end, int p) {
        if(start >= left && end <= right) return interval[p];
        
        if(start > right || end < left) return 0;
        
        int mid = (start+end) / 2 ;
        return getSumRange(left,right,start,mid,2*p+1) + getSumRange(left,right,mid + 1,end,2*p+2);
    }
    
public:
    NumArray(vector<int>& nums) {
        size = nums.size(); 
        interval.resize(4*size);
        buildTree(nums,0,size-1,0);
    }
    
    void update(int index, int val) {
        updateKthElement(index, val, 0, size-1, 0);
    }
    
    int sumRange(int left, int right) {
        return getSumRange(left, right, 0, size-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
