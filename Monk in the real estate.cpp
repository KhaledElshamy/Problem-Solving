#include<iostream>
#include<vector>
#include<set>
#include<string.h>

using namespace std ;


typedef vector<int> v;
typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;
typedef vector<vector<int> > vI;

bool visited[10000] = {false} ;
vI adjlist(10000) ;
set<int> cities;


int count = 0 ;


//void dfs(int parent){
//	::count++;
//	//cout<<::count<<endl;
//	visited[parent] = true ;
//	for(int i=0 ; i<adjlist[parent].size(); i++){
//		int child = adjlist[parent][i];
//		if(!visited[child]){
//			dfs(child);
//		}
//	}
//}

int main(){

    int t , e , x, y ;
    cin>>t;

    //int count = 0;

    while(t--){
    	cin>>e;

    	adjlist.erase(adjlist.begin(),adjlist.end());
    	cities.erase(cities.begin(),cities.end());
     	memset(visited, false, sizeof(visited));

    	::count = 0;
    	//cout<<"<<<"<<::count<<endl;

    	while(e--){
    		cin>>x>>y;
    		cities.insert(x);
    		cities.insert(y);
    		adjlist[x].push_back(y);
    	}
    	//cout<<"******"<<cities.size()<<endl;

    	cout<<cities.size()<<endl;
    }
    return 0 ;
}
