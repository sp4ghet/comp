#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

const int MAX_N = 5000;
int n, m;
char field[MAX_N][MAX_N];

void dfs(int x, int y)
{
    field[x][y] = '.';

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && field[nx][ny] == 'W')
            {
                dfs(nx, ny);
            }
        }
    }
}

void solve()
{
    int puddles = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                puddles++;
            }
        }
    }

    cout << puddles << endl;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> field[i][j];
        }
    }

    solve();
    return 0;
}
