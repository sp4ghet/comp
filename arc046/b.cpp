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
    int n, a, b;
    cin >> n >> a >> b;

    if (a > b || n <= a)
    {
        cout << "Takahashi" << endl;
        return 0;
    }
    else if (b > a)
    {
        cout << "Aoki" << endl;
        return 0;
    }

    // a == b && n > a
    int rem = n % (a + 1);
    if (rem == 0)
    {
        cout << "Aoki" << endl;
    }
    else
    {
        cout << "Takahashi" << endl;
    }

    return 0;
}