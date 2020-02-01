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
    string s;
    cin >> s;

    map<char, int> counts;
    for (char c : s)
    {
        counts[c]++;
    }

    int ans = INT32_MAX;
    for (auto i : counts)
    {
        char c = i.first;
        int now = 0;
        string s2;
        s2.assign(s.data());

        while (s2 != string(s2.size(), c))
        {
            now++;
            rep(i, s2.size() - 1)
            {
                if (s2.at(i) != c && s2.at(i + 1) == c)
                {
                    s2[i] = c;
                }
            }
            s2.pop_back();
        }
        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}