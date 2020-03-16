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
    cin >> n;
    vector<int> p(n), q(n), r(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    rep(i, n) r[i] = i + 1;

    int a = 0;
    int b = 0;
    int x = 1;
    do
    {
        bool aok = true, bok = true;
        rep(i, n)
        {
            if (r[i] != p[i])
            {
                aok = false;
            }
            if (r[i] != q[i])
            {
                bok = false;
            }
        }
        if (aok)
        {
            a = x;
        }
        if (bok)
        {
            b = x;
        }
        x++;
    } while (next_permutation(r.begin(), r.end()));

    cout << abs(a - b) << endl;

    return 0;
}