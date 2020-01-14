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
    vector<int> p(n);
    vector<int> q(n);
    vector<int> fact(n + 1, 1);
    rep(i, n)
    {
        fact[i + 1] = (i + 1) * fact[i];
    }

    rep(i, n)
    {
        cin >> p[i];
    }
    rep(i, n)
    {
        cin >> q[i];
    }

    int np = 1, nq = 1;
    rep(i, n)
    {
        auto unused = vector<int>(p.begin() + i, p.end());
        sort(unused.begin(), unused.end());
        int order = distance(unused.begin(), find(unused.begin(), unused.end(), p[i]));
        np += fact[n - i - 1] * (order);

        auto uq = vector<int>(q.begin() + i, q.end());
        sort(uq.begin(), uq.end());
        int oq = distance(uq.begin(), find(uq.begin(), uq.end(), q[i]));
        nq += fact[n - i - 1] * oq;
    }

    cout << abs(np - nq) << endl;

    return 0;
}