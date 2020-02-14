#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
template <typename T>
void view(const std::vector<T> &v)
{
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        view(v);
    }
}
#pragma endregion

vector<vector<char>> grid(10, vector<char>(10));
vector<vector<char>> now(10, vector<char>(10));
bool dfs(P s, P t)
{
    if (s.first == t.first && s.second == t.second)
    {
        return true;
    }
    now[s.first][s.second] = 'x';
    bool valid = false;
    if (s.second < 9 && now[s.first][s.second + 1] == 'o')
    {
        valid = valid || dfs(P(s.first, s.second + 1), t);
    }
    if (s.second > 0 && now[s.first][s.second - 1] == 'o')
    {
        valid = valid || dfs(P(s.first, s.second - 1), t);
    }
    if (s.first < 9 && now[s.first + 1][s.second] == 'o')
    {
        valid = valid || dfs(P(s.first + 1, s.second), t);
    }
    if (s.first > 0 && now[s.first - 1][s.second] == 'o')
    {
        valid = valid || dfs(P(s.first - 1, s.second), t);
    }
    return valid;
}

bool check(int ny, int nx)
{
    bool valid = true;
    // bool oldValid = true;
    now = grid;
    now[ny][nx] = 'o';
    rep(y, 10) rep(x, 10)
    {
        if (now[y][x] == 'x')
        {
            continue;
        }
        // auto v = vector<vector<bool>>(10, vector<bool>(10));
        valid = valid && dfs(P(ny, nx), P(y, x));
        now = grid;
        now[ny][nx] = 'o';
        // oldValid = valid;
    }
    return valid;
}

int main()
{
    //
    string s;
    rep(i, 10)
    {
        cin >> s;
        rep(j, 10)
        {
            grid[i][j] = s.at(j);
        }
    }

    bool valid = false;
    rep(y, 10) rep(x, 10)
    {
        if (grid[y][x] == 'o')
        {
            continue;
        }
        if (check(y, x))
        {
            valid = true;
            break;
        }
    }

    string ans = valid ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}