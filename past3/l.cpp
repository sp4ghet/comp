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
    int n;
    cin >> n;
    vector<deque<int>> t(n);

    map<int, int> keys;
    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int tj;
            cin >> tj;
            t[i].push_back(tj);
            keys[tj] = i;
        }
    }

    set<int> s1, s2;
    rep(i, n)
    {
        int first = t[i].front();
        t[i].pop_front();
        if (t[i].size())
        {
            int second = t[i].front();
            s2.emplace(second);
        }
        t[i].push_front(first);
        s1.emplace(first);
    }

    int m;
    cin >> m;

    rep(_, m)
    {
        int a;
        cin >> a;
        a--;

        int rem = *(s1.rbegin());
        if (a && !s2.empty())
        {
            rem = max(rem, *(s2.rbegin()));
        }
        printf("%d\n", rem);
        int i = keys[rem];
        int sz = t[i].size();
        int fst = t[i].front();
        t[i].pop_front();

        if (sz < 2)
        {
            s1.erase(fst);
        }
        else if (sz < 3)
        {
            int snd = t[i].front();
            s2.erase(snd);
            if (rem == fst)
            {
                s1.erase(fst);
                s1.emplace(snd);
            }
            else
            {
                t[i].pop_front();
                t[i].push_front(fst);
            }
        }
        else
        {
            int snd = t[i].front();
            t[i].pop_front();
            int thd = t[i].front();
            if (rem == fst)
            {
                s1.erase(fst);
                s1.emplace(snd);
                s2.erase(snd);
                s2.emplace(thd);
                t[i].push_front(snd);
            }
            else
            {
                s2.erase(snd);
                s2.emplace(thd);
                t[i].push_front(fst);
            }
        }
    }

    return 0;
}