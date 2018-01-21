#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

int n,m;
char land;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int floodfill(int index1,int index2,vector<string>&v){
	if(index2==m) index2=0; else if(index2==-1) index2=m-1;
	if (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n) return 0;
	if(v[index1][index2]!=land)return 0;
	int ans=1;
	v[index1][index2]='.';
	for(int i=0;i<4;i++)
		ans+=floodfill(index1+dr[i],index2+dc[i],v);
	return ans;
}

int main()
{
  int index1,index2,save;
  while(cin>>n>>m){
	  save=0;
	  vector<string>v(n);
	  v.clear();
	  for(int i=0;i<n;i++)cin>>v[i];
	  cin>>index1>>index2;
	  land=v[index1][index2];
	  int res=floodfill(index1,index2,v);
	  save=res;
	  for(int row=0;row<n;row++)
		  for(int col=0;col<m;col++)
			  if(v[row][col]==land){
				  res=floodfill(row,col,v);
				  if(res>save)save=res;
			  }
	  cout<<save<<endl;
  }
    return 0;
}
