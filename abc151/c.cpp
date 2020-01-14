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
    int n, m;
    cin >> n >> m;

    vector<int> ac(n, 0);
    vector<int> wa(n, 0);
    rep(i, m)
    {
        int q;
        string res;
        cin >> q >> res;
        q--;
        if (res == "AC")
        {
            ac[q] = 1;
        }
        else
        {
            wa[q] += ac[q] == 1 ? 0 : 1;
        }
    }

    int acs = 0, was = 0;
    rep(i, n)
    {
        acs += ac[i];
        if (ac[i])
        {
            was += wa[i];
        }
    }

    cout << acs << " " << was << endl;

    return 0;
}