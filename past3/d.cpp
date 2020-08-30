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

string s[5];
using vstring = vector<string>;
using vvstring = vector<vstring>;
vvstring tbl = {
    {"###",
     "#.#",
     "#.#",
     "#.#",
     "###"},
    {".#.",
     "##.",
     ".#.",
     ".#.",
     "###"},
    {"###",
     "..#",
     "###",
     "#..",
     "###"},
    {"###",
     "..#",
     "###",
     "..#",
     "###"},
    {"#.#",
     "#.#",
     "###",
     "..#",
     "..#"},
    {"###",
     "#..",
     "###",
     "..#",
     "###"},
    {"###",
     "#..",
     "###",
     "#.#",
     "###"},
    {"###",
     "..#",
     "..#",
     "..#",
     "..#"},
    {"###",
     "#.#",
     "###",
     "#.#",
     "###"},
    {"###",
     "#.#",
     "###",
     "..#",
     "###"}};

int main()
{
    int n;
    cin >> n;
    rep(i, 5) cin >> s[i];

    map<vstring, int> m;
    // ### .#. ### ### #.# ### ### ### ### ###.
    // #.# ##. ..# ..# #.# #.. #.. ..# #.# #.#.
    // #.# .#. ### ### ### ### ### ..# ### ###.
    // #.# .#. #.. ..# ..# ..# #.# ..# #.# ..#.
    // ### ### ### ### ..# ### ### ..# ### ###.
    rep(i, 10)
    {
        m[tbl[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        vstring now(5);
        rep(y, 5) now[y] = s[y].substr(4 * i - 3, 3);
        // rep(y, 5) cout << now[y] << endl;
        cout << m[now];
    }
    cout << endl;

    return 0;
}
