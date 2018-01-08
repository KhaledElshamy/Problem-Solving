#include <bits/stdc++.h>
using namespace std;

typedef vector<int> v;
typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;
typedef vector< vector<int> > vI;


bool visited[30];

vI adjlist(30);

void dfs(int x){
	
	visited[x]=true;
	for(int j=0;j<(int)adjlist[x].size();j++){
		int child=adjlist[x][j];
		if(!visited[child])
			dfs(child);
	}
}

int main()
{
	int TC, V,count=0;
		char c, a, b;
		char input[10];

		scanf("%d", &TC);
		while(TC--)
		{
			memset(visited, false, sizeof(visited));
			cin >> c;
			V = c -'A'+1;
			while(getchar() != '\n');
			while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2){
				int u, v;
				u = a - 'A'+1;
				v = b - 'A'+1;
				adjlist[u].push_back(v);
				adjlist[v].push_back(u);
			}

			for(int i=1;i<=V;i++){
				if(!visited[i])count++;
				dfs(i);
			}

			cout<<count<<endl;
			adjlist.clear();
			if(TC)cout<<endl;
	}
		return 0;
}

