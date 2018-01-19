#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

int visited[11][11],cnt;
char directions[] = {'N', 'E', 'S', 'W'};
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
bool flag1=false;
int steps[11][11];
int save;

void dfs(vector< string >& v,int n,int m,int row,int col){
	if(row<0||col<0||row>=n||col>=m){
		flag1=true;
		return;
	}
	else if(visited[row][col]){
		save=steps[row][col];
		save-=1;
		return;
	}
	else if(v[row][col]=='W'&&!visited[row][col]){
		cnt++;
		steps[row][col]=cnt;
		visited[row][col]=1;
		dfs(v,n,m,row+dr[2],col+dc[2]);
	}
	else if(v[row][col]=='N'&&!visited[row][col]){
		cnt++;
		steps[row][col]=cnt;
		visited[row][col]=1;
		dfs(v,n,m,row+dr[3],col+dc[3]);
	}
	else if(v[row][col]=='E'&&!visited[row][col]){
		cnt++;
		steps[row][col]=cnt;
		visited[row][col]=1;
		dfs(v,n,m,row+dr[0],col+dc[0]);
	}
	else if(v[row][col]=='S'&&!visited[row][col]){
		cnt++;
		steps[row][col]=cnt;
		visited[row][col]=1;
		dfs(v,n,m,row+dr[1],col+dc[1]);
	}
}

int main()
{
   int n,m,index;
   while(true){
	   cin>>n>>m>>index;
	   int row=0,col=index-1;
	   vector< string >v(n+1);
	   memset(steps,0,sizeof(steps));
	   memset(visited,0,sizeof(visited));
	   if(n==0&&m==0&&index==0)break;
	   for(int i=0;i<n;i++)cin>>v[i];
	   dfs(v,n,m,row,col);
	   if(flag1)cout<<cnt<<" "<<"step(s) to exit"<<endl;
	   else cout<<save<<" "<<"step(s) before a loop of"<<" "<<cnt-save<<" "<<"step(s)"<<endl;
	   v.clear();
	   flag1=false;
	   cnt=0;
   }
    return 0;
}
