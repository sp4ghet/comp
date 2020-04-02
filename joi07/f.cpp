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

ll INF = (1LL << 40);

void printAns(ll d)
{
    if (d == INF)
        cout << -1 << endl;
    else
        cout << d << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vvint g(n, vint(n, INT32_MAX));

    vvll d(n, vll(n, INF));
    rep(i, n) d[i][i] = 0;

    vvint input(k, vint(4));
    rep(i, k)
    {
        int type, f, t, c = INF;
        cin >> type >> f >> t;
        f--;
        t--;
        if (type)
            cin >> c;

        input[i] = {type, f, t, c};
    }

    rep(i, k)
    {
        int type = input[i][0];
        if (type)
        {
            int f = input[i][1], t = input[i][2], c = input[i][3];

            bool updated = false;
            updated = chmin(g[f][t], c) || updated;
            updated = chmin(g[t][f], c) || updated;
            if (updated)
            {
                rep(j, n) rep(l, n)
                {
                    d[j][l] = INF;
                }
            }
            continue;
        }

        int f = input[i][1], t = input[i][2];
        if (d[f][f] == 0)
        {
            printAns(d[f][t]);
            continue;
        }

        priority_queue<int> q;
        q.push(f);
        d[f][f] = 0;
        while (q.size())
        {
            int nv = q.top();
            q.pop();
            rep(j, n)
            {
                if (g[nv][j] == INT32_MAX)
                    continue;

                bool update = chmin(d[f][j], d[f][nv] + g[nv][j]);
                if (update)
                {
                    q.push(j);
                }
            }
        }

        printAns(d[f][t]);
    }

    return 0;
}