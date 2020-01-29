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
    string as, bs, cs;
    cin >> as >> bs >> cs;
    queue<char> a, b, c;
    rep(i, as.size()) a.push(as.at(i));
    rep(i, bs.size()) b.push(bs.at(i));
    rep(i, cs.size()) c.push(cs.at(i));
    char prev = ' ';
    char next = 'a';
    while (next)
    {
        prev = next;
        if (next == 'a')
        {
            next = a.front();
            a.pop();
        }
        else if (next == 'b')
        {
            next = b.front();
            b.pop();
        }
        else if (next == 'c')
        {
            next = c.front();
            c.pop();
        }
    }

    cout << (char)toupper(prev) << endl;

    return 0;
}