#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;

int dr[] = {1,0,-1,0,1,-1,1,-1};
int dc[] = {0,1,0,-1,1,-1,-1,1};

int floodFill(int r, int c, int R, int C, vector<vector<char> >& grid) {
    if(r<0 || c < 0 || r>=R || c>=C) return 0 ;
    if(grid[r][c] == '0') return 0;
    grid[r][c] = '0';
    int ans = 1; 
    for(int i=0;i<8;i++)ans += floodFill(r+dr[i],c+dc[i],R,C,grid);
    return ans ; 
}

int main(){

    int n, numberOfImage = 1, count;
	while(cin>>n && n){
        count = 0 ;
        vector<vector<char> > image(n,vector<char>(n));
        // image.erase(image.begin(),image.end());
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>image[i][j];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(image[i][j] == '1'){
                    floodFill(i,j,n,n,image);
                    count++;
                }
            }
        }

        cout<<"Image number "<< numberOfImage << " contains " << count << " war eagles."<<endl; 
        numberOfImage++;
    }
    return 0;
}
