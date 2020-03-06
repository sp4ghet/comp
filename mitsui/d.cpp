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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i, 10) rep(j, 10) rep(k, 10)
    {
        bool first = false, second = false;
        rep(l, n)
        {
            if (!first && s.at(l) - '0' == i)
            {
                first = true;
                continue;
            }
            if (first && !second && s.at(l) - '0' == j)
            {
                second = true;
                continue;
            }
            if (second && s.at(l) - '0' == k)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}