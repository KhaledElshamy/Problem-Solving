#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;
typedef vector< vector<int> > v;

 
int dr [] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};
 
int n;
char mat [100 + 5] [100 + 5];
 
void dfs (int p, int q)
{
    if ( p < 0 || p == n || q < 0 || q == n || mat [p] [q] == '.' ) return;
 
    mat [p] [q] = '.';
 
    for ( int i = 0; i < 8; i += 2 )
        dfs (p + dr [i], q + dc [i]);
}
 
int main ()
{
    int testCase; scanf ("%d", &testCase);
    int cases = 0;
 
    while ( testCase-- ) {
        scanf ("%d", &n);
 
        for ( int i = 0; i < n; i++ ) scanf ("%s", mat [i]);
 
        int cnt = 0;
 
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( mat [i] [j] == 'x' ) { cnt++;  dfs (i, j); }
            }
        }
 
        printf ("Case %d: %d\n", ++cases, cnt);
    }
 
    return 0;
}
