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
    int q;
    cin >> q;
    bool ftb = true;
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ftb = !ftb;
            continue;
        }
        int f;
        char c;
        cin >> f >> c;
        int pos = ftb ? 0 : s.size();
        if (f == 2)
        {
            pos = ftb ? s.size() : 0;
        }

        s.insert(pos, 1, c);
    }

    if (!ftb)
    {
        reverse(s.begin(), s.end());
    }

    cout << s << endl;

    return 0;
}