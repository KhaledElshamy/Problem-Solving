class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int numOfRows = grid.size();
        int numOfCol = grid[0].size();
        
        
        vector<int> iGroup;
        vector<int> jGroup;
        
        iGroup.assign(numOfRows,0);
        jGroup.assign(numOfCol,0);
        
        for(int i=0;i<(int)numOfRows;i++){
            for(int j=0;j<(int)numOfCol;j++){
                if(grid[i][j] == 1){
                    iGroup[i]++;
                    jGroup[j]++;
                }
            }
        }
        
        int count = 0 ;
        for(int i=0;i<numOfRows;i++){
            for(int j=0;j<numOfCol;j++){
                if(grid[i][j] == 1 && (iGroup[i]>1 || jGroup[j]>1)){
                    count++;
                }
            }
        }
        
        return count;
    }
};
