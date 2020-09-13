class Solution {
public:
    
    void rotateImage(vector<vector<int>>& matrix){
        for(int i=0;i<(int)matrix.size();i++){
            for(int j = i;j<(int)matrix.size();j++)swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        rotateImage(matrix);
        
        if(matrix.size() != matrix[0].size())return ;
        
        int start = 0 ;
        int end = matrix.size() - 1 ;
        
        while(start < end){
            for(int i=0;i<(int)matrix.size();i++){
                swap(matrix[i][start], matrix[i][end]);
            }
            start++;
            end--;
        }
    }
};
