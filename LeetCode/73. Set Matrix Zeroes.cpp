class Solution {
public:
    
    void nullifyRows(vector<vector<int>>& matrix,int row){
        for(int j=0;j<(int)matrix[0].size();j++)matrix[row][j] = 0;
    }
        
        
    void nullifyColumns(vector<vector<int>>& matrix,int column){
        for(int i=0;i<(int)matrix.size();i++) matrix[i][column] = 0;
    }
    
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool firstRowHasZero  = false; 
        bool firstColHasZero = false ;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0] == 0 ){firstColHasZero = true ;break;} 
        }
        
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j] == 0 ){firstRowHasZero = true; break; }
        }
        
        
         
        for(int i=0;i<(int)matrix.size();i++){
            for(int j=0;j<(int)matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
        for(int i=1;i<(int)matrix.size();i++){
            if(matrix[i][0] == 0)nullifyRows(matrix,i);
        }
        
        
        for(int j=1;j<(int)matrix[0].size();j++){
            if(matrix[0][j] == 0)nullifyColumns(matrix,j);
        }
        
        if(firstRowHasZero)nullifyRows(matrix,0);
        if(firstColHasZero)nullifyColumns(matrix,0);
        
    }
};
