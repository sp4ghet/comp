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
    double n;
    cin >> n;
    // finding length
    double length = n / 3;

    n -= length;

    // finding breadth
    double breadth = n / 2;

    // finding height
    double height = n - breadth;

    double ans = length * breadth * height;

    cout.precision(24);
    cout << ans << endl;

    return 0;
}