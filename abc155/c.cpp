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
    map<string, int> v;
    rep(i, n)
    {
        string s;
        cin >> s;
        v[s]++;
    }

    int vMax = 0;
    for (auto p : v)
    {
        if (p.second > vMax)
        {
            vMax = p.second;
        }
    }

    vector<string> b;
    for (auto p : v)
    {
        if (p.second == vMax)
        {
            b.push_back(p.first);
        }
    }
    sort(b.begin(), b.end());

    rep(i, b.size())
    {
        cout << b[i] << endl;
    }

    return 0;
}