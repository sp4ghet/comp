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

int main()
{
    vector<vector<int>> a(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> a[i][j];
    int n;
    cin >> n;
    rep(i, n)
    {
        int b;
        cin >> b;
        rep(y, 3) rep(x, 3)
        {
            if (a[y][x] == b)
            {
                a[y][x] = 0;
            }
        }
    }

    bool bingo = false;

    bool diag = true;
    bool backdiag = true;

    rep(i, 3)
    {
        bool lat = true;
        bool vert = true;

        diag = diag && a[i][i] == 0;
        backdiag = backdiag && a[2 - i][i] == 0;
        rep(j, 3)
        {
            lat = lat && a[i][j] == 0;
            vert = vert && a[j][i] == 0;
        }
        bingo = bingo || lat || vert;
    }

    bingo = bingo || diag || backdiag;
    string ans = bingo ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}