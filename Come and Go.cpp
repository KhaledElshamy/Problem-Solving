#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vc> vvc;
typedef vector<vii> vvii;

int visited[100000];
int dfs_num[100000], dfs_low[100000];
int counter;
int numOfPathsConnected;

void SCCTarjan(int parent , vector<vi> &adjList){
    dfs_num[parent] = dfs_low[parent] = counter++;
    visited[parent] = 1;
    for(int i=0;i<(int) adjList[parent].size();i++){
        int child = adjList[parent][i];
        if(!visited[child])SCCTarjan(child,adjList);
        if(visited[child])dfs_low[parent] = min(dfs_low[child],dfs_low[parent]);
    }

    if(dfs_low[parent] == dfs_num[parent]){
        numOfPathsConnected++;
    }
    
}


int main(){

   int n,m;
   while(scanf("%d %d",&n,&m) && (n||m)){
       vector<vi>adjList(n+1);
       memset(visited,0,sizeof(visited));
       memset(dfs_num,0,sizeof(dfs_num));
       memset(dfs_low,0,sizeof(dfs_low));

       adjList.erase(adjList.begin(),adjList.end());
       counter = 0 ,numOfPathsConnected = 0;

       while(m--){
           int w,v,p;
           cin>>w>>v>>p;
           adjList[w].push_back(v);
           if(p==2)adjList[v].push_back(w);
       }
       SCCTarjan(1,adjList);
       for(int i=1;i<=n;i++){
           if(!visited[i]){
               SCCTarjan(i,adjList);
           }
       }

       int res = numOfPathsConnected == 1 ? 1: 0;
       cout<<res<<endl;
       
   }
    return 0;
}
