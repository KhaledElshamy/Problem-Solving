#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;
typedef vector< vector<int> > v;

void dfs(int i,int j,int size,vector<string>& image,vector< vector<bool> >& visited){
	for(int i1=i-1;i1<i+2;i1++){
		for(int j1=j-1;j1<j+2;j1++)
		{
			if(i1>=0&&j1>=0&&i1<size&&j1<size&&!visited[i1][j1]&&image[i1][j1]=='1')
			{
				visited[i1][j1]=true;
				dfs(i1,j1,size,image,visited);
			}
		}
	}
}

int main()
{
	int n,count1,count2=1;
	while(cin>>n && n){
		vector<string>image(n);
		count1=0;
		image.clear();
		for(int i=0;i<n;i++)cin>>image[i];
		vector< vector<bool> >visited(n,vector<bool>(n,false));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(image[i][j]=='1'&&!visited[i][j]){
					count1++;
					visited[i][j]=true;
					dfs(i,j,n,image,visited);
				}
			}
		}
		 cout << "Image number " << count2 << " contains " << count1 << " war eagles.\n";
		 count2++;
	}
	return 0;
}

