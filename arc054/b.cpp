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

double ans(double x, double p)
{
    return x + p / pow(2, x / 1.5);
}

int main()
{
    double p;
    cin >> p;

    double l = 0, r = p;
    int cnt = 1000;
    while (--cnt)
    {
        double c1 = (2 * l + r) / 3,
               c2 = (l + 2 * r) / 3;
        if (ans(c1, p) > ans(c2, p))
        {
            l = c1;
        }
        else
        {
            r = c2;
        }
    }

    cout.precision(28);
    cout << ans(l, p) << endl;

    return 0;
}