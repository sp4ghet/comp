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
    string s;
    cin >> s;
    int ans = 0;

    int scnt = 0;
    rep(i, s.size())
    {
        scnt += s.at(i) == 'S' ? 1 : 0;
        if (scnt == 0)
        {
            ans++;
            continue;
        }

        if (s.at(i) == 'T')
        {
            scnt -= 1;
            ans--;
        }
        else
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}