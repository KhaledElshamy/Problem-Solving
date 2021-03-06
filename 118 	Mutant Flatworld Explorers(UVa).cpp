#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

char directions[] = {'N', 'E', 'S', 'W'};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};


int main()
{
    int xSize, ySize;
    cin >> xSize >> ySize;

    vector<vector<bool> > v(ySize + 1, vector<bool> (xSize + 1, false));

    int x, y;
    char startDirection;
    string orders;

    while (cin >> x >> y >> startDirection >> orders)
    {
        int direction;

        for (int i = 0; i < 4; ++i)
            if (startDirection == directions[i])
                direction = i;

        bool lost = false;


        for (int i = 0; i < orders.size(); ++i)
        {

            if (orders[i] == 'R')
                direction = (direction + 1) % 4;

            else if (orders[i] == 'L')
                direction = (direction + 3) % 4;

            else
            {
                if (x + xChange[direction] == -1 || x + xChange[direction] == xSize + 1 || y + yChange[direction] == -1 || y + yChange[direction] == ySize + 1)
                {
                    if (!v[y][x])
                    {
                        v[y][x] = true;
                        lost = true;
                        break;
                    }
                }

                else
                {
                    x += xChange[direction];
                    y += yChange[direction];
                }
            }
        }

        cout << x << ' ' << y << ' ' << directions[direction] << (lost ? " LOST" : "") << '\n';
}
    return 0;
}
