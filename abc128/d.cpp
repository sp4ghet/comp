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
#pragma region chminmax
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion
int dp[105][4];

int main()
{
    int n, k;
    cin >> n >> k;
    vint a(n), b(n);
    rep(i, n) cin >> a[i];
    b = a;
    reverse(b.begin(), b.end());

    int ans = 0;
    int r = min(n, k);
    rep(i, r + 1)
    {
        int now = 0;
        priority_queue<int> q;
        rep(j, i)
        {
            q.push(a[j]);
            now += a[j];
            priority_queue<int> p = q;
            rep(l, i - j)
            {
                q.push(b[l]);
                now += b[l];
            }
        }
        for (int m = 0; m < k - i && q.size(); m++)
        {
            int next = q.top();
            q.pop();
            if (next > 0)
                break;

            now -= next;
        }
        chmax(ans, now);
    }

    cout << ans << endl;

    return 0;
}