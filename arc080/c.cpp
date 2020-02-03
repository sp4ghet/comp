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
    cin >> n;
    vector<int> a(n);
    int four = 0, two = 0, none = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a % 4 == 0)
        {
            four++;
        }
        else if (a % 2 == 0)
        {
            two++;
        }
        else
        {
            none++;
        }
    }
    string ans = "Yes";
    if (four < none)
    {
        ans = "No";
    }
    if (four + 1 >= none && two == 0)
    {
        ans = "Yes";
    }
    cout << ans << endl;

    return 0;
}