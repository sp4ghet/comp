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
    vector<int> xs(n);
    rep(i, n) cin >> xs[i];
    int sml = min_element(xs.begin(), xs.end())[0];
    int max = max_element(xs.begin(), xs.end())[0];

    int best = INT32_MAX;
    for (int i = sml; i <= max; ++i)
    {
        int score = 0;
        for (auto x : xs)
        {
            score += (x - i) * (x - i);
        }
        best = min(best, score);
    }

    cout << best << endl;

    return 0;
}