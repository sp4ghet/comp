#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    rep(i, n - 2)
    {
        if (s.at(i) == 'A' && s.at(i + 1) == 'B' && s.at(i + 2) == 'C')
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}