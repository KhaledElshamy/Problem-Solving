int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

class Solution {
public:
    int floodFill(int r,int c,int R,int C,vector<vector<char>>& grid){
        if(r<0 || c<0 || r>=R||c>= C)return 0;
        if(grid[r][c]=='0')return 0;
        grid[r][c] = '0';
        int ans = 1;
        for(int i=0;i<4;i++) ans+=floodFill(r+dr[i],c+dc[i],R,C,grid);
        return ans;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0 ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j] == '1')floodFill(i,j,grid.size(),grid[i].size(),grid),count++;
        }
        
        return count;
    }
};
