#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

char rally[105][105], floor;
int main()
{
    int n, m, sl, tc, kk=1, stx, sty, nx, ny;
    string s;
    while(cin>>n>>m>>sl && n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>rally[i][j];
                if(rally[i][j]=='N' || rally[i][j]=='S' || rally[i][j]=='L' || rally[i][j]=='O') stx=i, sty=j, floor=rally[i][j];
            }
        cin>>s;

        
        int cnt=0;
        for(int i=0;i<sl;i++)
        {
            if(s[i]=='D')
            {
                if(floor=='N') floor='L';
                else if(floor=='L') floor='S';
                else if(floor=='S') floor='O';
                else if(floor=='O') floor='N';
            }
            else if(s[i]=='E')
            {
                if(floor=='L') floor='N';
                else if(floor=='S') floor='L';
                else if(floor=='O') floor='S';
                else if(floor=='N') floor='O';
            }
            else
            {
                nx=stx, ny=sty;
                if(floor=='N') nx=stx-1;
                else if(floor=='L') ny=sty+1;
                else if(floor=='S') nx=stx+1;
                else if(floor=='O') ny=sty-1;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {

                    if(rally[nx][ny]!='#')
                    {
                        if(rally[nx][ny]=='*')
                        {
                            cnt++;
                            rally[nx][ny]='.';
                        }
                        stx=nx, sty=ny;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
return 0;
}
