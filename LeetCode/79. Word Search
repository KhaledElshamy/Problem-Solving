int dr[] = {1,0,-1,0};
int dc[] = {0,-1,0,1};
# define MAX_SIZE 100000

class Solution {
private: 
    bool visited[256][256];
    
    bool floodFill(int r,int c,int index,vector<vector<char>>& board,string &word){
        
        if(index == word.size()) return true;
        if(r<0||c<0||r>=board.size()||c>=board[0].size())return false ;
        if(visited[r][c] || board[r][c]!= word[index])return false;
        
        visited[r][c] = true;
        
        bool res; 
        for(int i=0;i<4;i++){
            res = floodFill(r+dr[i],c+dc[i],index+1,board,word);
            if(res) return true;
        }
        
        visited[r][c] = false;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
               
        for(int i=0;i<(int)board.size();i++){
            for(int j=0;j<(int)board[0].size();j++){
                if(board[i][j] == word[0] && floodFill(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
