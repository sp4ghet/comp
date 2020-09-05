#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

template <typename T>

void view(const std::vector<T> &v)
{
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
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
    int n = s.size();
    vint a(n);
    int no = 0, ne = 0;
    rep(i, n)
    {
        if (s[i] == 'R')
        {
            no += i % 2;
            ne += (i + 1) % 2;
        }
        else
        {
            if (i % 2)
            {
                a[i] += no;
                a[i - 1] += ne;
            }
            else
            {
                a[i] += ne;
                a[i - 1] += no;
            }
            no = 0;
            ne = 0;
        }
    }
    reverse(s.begin(), s.end());
    reverse(a.begin(), a.end());
    rep(i, n)
    {
        if (s[i] == 'L')
        {
            no += i % 2;
            ne += (i + 1) % 2;
        }
        else
        {
            if (i % 2)
            {
                a[i] += no;
                a[i - 1] += ne;
            }
            else
            {
                a[i] += ne;
                a[i - 1] += no;
            }
            no = 0;
            ne = 0;
        }
    }
    reverse(a.begin(), a.end());

    rep(i, n) cout << a[i] << " ";
    cout << endl;

    return 0;
}