typedef vector<int> vi;
typedef vector<vector<int> > vii;

int dr[] = {1,0,-1,0,1,-1,1,-1};
int dc[] = {0,1,0,-1,1,-1,-1,1};

class Solution {
private: 
    void floodFill(int r,int c, int maxR, int maxC,vii &board,vii &grid){
        
        int numOfDeadCells = 0;
        int numOfLiveCells = 0 ;
        
        for(int i=0;i<8;i++){
            int nextRow = r + dr[i], nextCol = c+ dc[i];
            if(nextRow<0 || nextRow>=maxR || nextCol<0 || nextCol>=maxC)continue;
            if(grid[nextRow][nextCol] == 1) numOfLiveCells++;
            else if (grid[nextRow][nextCol] == 0)numOfDeadCells++;
        }
        
        if(board[r][c] == 1){
            if(numOfLiveCells < 2 || numOfLiveCells > 3) board[r][c] = 0 ;
        }else if(board[r][c] == 0 ){
            if(numOfLiveCells == 3) board[r][c] = 1;
        }
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();
        
        vii grid(rowSize,vi(colSize));
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++)grid[i][j] = board[i][j];
        }
        
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                floodFill(i,j,rowSize,colSize,board,grid);
            }
        }
    }
};
