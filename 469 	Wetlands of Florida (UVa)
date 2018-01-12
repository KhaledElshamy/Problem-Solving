#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;
typedef vector< vector<int> > v;

int n;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

char grid[100][100];

int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 || r >= n || c < 0 || c >= n) return 0;
	if (grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for (int d = 0; d < 8; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}

int main()
{
	int TC, row, col;
	char str[105];
	scanf("%d ", &TC);

	while(TC--) {
		memset(grid, 0, sizeof(grid));
		n=0;
		while(gets(str)&&strlen(str)>0) {
			if(str[0] != 'W' && str[0] != 'L') {
				sscanf(str,"%d %d", &row, &col);
				int res=floodfill(row-1, col-1,'W','.');
				printf("%d\n",res);
			}
			else {
				sscanf(str,"%s", grid[n]);
				n++;
			}
		}
		if(TC)puts("");
	}
	return 0;
}
