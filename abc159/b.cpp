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

bool palindrome(string s)
{
    bool ok = true;
    rep(i, s.size() / 2)
    {
        ok = ok && s.at(i) == s.at(s.size() - i - 1);
        if (!ok)
            break;
    }
    return ok;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size(), k = (n + 3) / 2 - 1;
    string f = s.substr(0, (n - 1) / 2),
           b = s.substr(k, n - k);

    bool ans = palindrome(s) && palindrome(f) && palindrome(b);

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}