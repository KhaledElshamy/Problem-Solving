#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

int grid[100][100];
int solution[2];
int r, c, m, n, x,M,N;
int shift[]={1,-1};

int valid(int ROW,int COL){
	return ROW>=0&&ROW<r&&COL>=0&&COL<c&&grid[ROW][COL]!=-1;
}

void dfs(int row, int col) {
	
	grid[row][col]=1;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			M=row+(m*shift[i]),N=col+(n*shift[j]);
			if(valid(M,N)){
				grid[row][col]++;
				if(grid[M][N]==0)dfs(M,N);
			}
			M=row+(n*shift[i]),N=col+(m*shift[j]);
			if(valid(M,N)){
				grid[row][col]++;
				if(grid[M][N]==0)dfs(M,N);
			}
		}

	solution[grid[row][col] & 1]++;
}

int main() {
	int TC;
	cin >> TC;
	for (int k = 1; k <= TC; k++) {
		cin >> r >> c >> m >> n;
		memset(grid, 0, sizeof(grid));
		cin>>x;
		while (x--){
			int a, b;
			cin >> a >> b;
			grid[a][b] = -1;
		}
		memset(solution, 0, sizeof(solution));
		dfs(0, 0);
		printf("Case %d: %d %d\n", k, solution[1], solution[0]);
	}
	return 0;
}
