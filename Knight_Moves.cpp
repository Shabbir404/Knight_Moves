#include <bits/stdc++.h>
using namespace std;

int knx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int kny[] = {-1, 1, 1, -1, 2, -2, 2, -2};

int main()
{

    int a;
    cin >> a;
    while (a--)
    {
        int c, d;
        cin >> c >> d;

        int kx, ky, qx, qy;

        cin >> kx >> ky >> qx >> qy;

        bool vis[1000][1000] = {false};

        bool flag = false;

        queue<pair<int, int>> q;

        queue<int> s;

        q.push({kx, ky});
        s.push(0);

        vis[kx][ky] = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            int st = s.front();
            q.pop();
            s.pop();

            if (x == qx && y == qy)
            {
                cout << st << endl;
                flag = true;
                break;
            }

            for (int i = 0; i < 8; i++)
            {
                int xx = x + knx[i];
                int yy = y + kny[i];

                if (xx >= 0 && xx < c && yy >= 0 && yy < d && !vis[xx][yy])
                {
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                    s.push(st + 1);
                }
            }
        }
        if (!flag)
            cout << -1 << endl;
    }

    return 0;
}
