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
    int n, k;
    cin >> n >> k;
    vector<int> pos;
    vector<int> neg;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a > 0)
        {
            pos.push_back(a);
        }
        else
        {
            neg.push_back(a);
        }
    }
    // sort(pos.begin(), pos.end());
    // sort(neg.begin(), neg.end());

    if (k < neg.size() * pos.size())
    {
        vector<int> a(neg.size() * pos.size());
        // np - k th smallest number
        int big = 0;
        rep(i, k)
        {
            rep(j, k)
            {
            
            }
        }
    }
    else
    {
        // some positive number
    }

    return 0;
}