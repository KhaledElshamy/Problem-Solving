#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
#include <queue>
#include <stdlib.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;
typedef vector<char> vc;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};


bool flag = false ;

int floodFill(int minR,int minC, int maxR , int maxC, vector<vc> &grid ){
    if(minR<=0 || minC <= 0 || minR >= maxR || minC >= maxC ){
        if(grid[minR][minC] == '.')flag = true;
        return 0;
    }
    if(grid[minR][minC] == '*')return 0 ;
    grid[minR][minC] = '*';
    int ans = 1;
    for(int i=0;i<4;i++)ans+=floodFill(minR+dr[i],minC+dc[i],maxR,maxC,grid);
    return ans; 
}


bool cmp(int a,int b){
    return a > b;
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vc> grid(n,vc(m));
    vector<vc> saveGrid(n,vc(m));
    vector<vi> intGrid(n,vi(m));

    vector<pair<int,ii>  > numOflakes;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            saveGrid[i][j] = grid[i][j];
            intGrid[i][j] = 0;
        }
    }

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            int ans;
            if(grid[i][j] == '.'){
                ans = floodFill(i,j,n-1,m-1,grid);
                if(!flag)numOflakes.push_back(make_pair(ans,ii(i,j))),intGrid[i][j] = ans;
                flag = false;
            }
        }
    }

    //  cout<<"ssdsdsdsdsd"<<" "<<numOflakes.size()<<endl;

    sort(numOflakes.begin(),numOflakes.end()); 
    bool finish = false ;
    int total = 0;

    int size = numOflakes.size();
    for(int i=0;i<size - k;i++){
        total+= numOflakes[i].first;
        floodFill(numOflakes[i].second.first,numOflakes[i].second.second,n-1,m-1,saveGrid);
    }
    
    cout<<total<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<saveGrid[i][j];
        cout<<endl;
    }
    return 0;
}
