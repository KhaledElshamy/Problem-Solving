#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<cstring>
#include<cmath>
#include<math.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vc> vvc;
typedef vector<ll> vll;

int dfs_num[100001];
int dfs_low[100001];
int parent[100001];
int articulation_vertex[100001];
int dfsNumberCounter ;


bool comp(pair<int,int> &node1 , pair<int,int> &node2){
	if(node1.first == node2.first) return node1.second < node2.second;
	else return node1.first > node2.first;
}

void findArticulationPoints(int u,vector<vi> &adjList){
	dfs_num[u] = dfs_low[u] = ++dfsNumberCounter;

	for(int i=0;i<(int)adjList[u].size();i++){
		int child = adjList[u][i];
		if(!dfs_num[child]){
			parent[child] = u ;
			
			findArticulationPoints(child,adjList);

			if(dfs_low[child]>=dfs_num[u]){
				++articulation_vertex[u];
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[child]);
		}else if(child!=parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[child]);
		}else if(child == parent[u]){
			++articulation_vertex[u];
		}
}}

int main(){
	int n,m;

	while (scanf("%d %d",&n,&m) && n!=0)
	{
		vector<vi> adjList(n);
		vii nodes;
		int node1,node2;

		adjList.erase(adjList.begin(),adjList.end());
		nodes.erase(nodes.begin(),nodes.end());
		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(articulation_vertex,0,sizeof(articulation_vertex));

		dfsNumberCounter = 0;
		
		while (scanf("%d %d",&node1,&node2)&& node1!= -1)
		{
			adjList[node1].push_back(node2);
			adjList[node2].push_back(node1);
		}

		for(int i=0;i<n;i++){
			if(!dfs_num[i]){
				findArticulationPoints(i,adjList);
			}
		}
		for(int i=0;i<n;i++){
			nodes.push_back(ii(articulation_vertex[i],i));
		}

		sort(nodes.begin(),nodes.end(),comp);
		for(int i=0;i<m;i++){
			printf("%d %d\n",nodes[i].second,nodes[i].first);
		}
		printf("\n");
	}
	return 0 ;
}
