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
    rep(i, n) cin >> a[i];

    vector<int> s(1 << n);
    rep(i, 1 << n)
    {
        rep(k, n)
        {
            if (i & (1 << k))
            {
                s[i] += a[k];
            }
        }
    }
    sort(s.begin(), s.end());

    int q;
    cin >> q;
    rep(i, q)
    {
        int m;
        cin >> m;
        bool ans = binary_search(s.begin(), s.end(), m);

        if (ans)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}