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
    int k;
    cin >> k;
    vector<int> b(8), a(8, -1);
    rep(i, 8) b[i] = i;
    rep(i, k)
    {
        int y, x;
        cin >> y >> x;
        a[y] = x;
    }
    do
    {
        bool valid = true;
        rep(i, 8)
        {
            if (a[i] != -1 && a[i] != b[i])
            {
                valid = false;
            }
        }
        rep(i, 8)
        {
            rep(j, 8)
            {
                if (i == j)
                    continue;
                int x1 = b[i] + (j - i);
                int x2 = b[i] - (j - i);
                if (x1 > -1 && x1 < 8 && b[j] == x1)
                {
                    valid = false;
                }
                if (x2 > -1 && x2 < 8 && b[j] == x2)
                {
                    valid = false;
                }
            }
        }

        if (valid)
        {
            rep(i, 8)
            {
                rep(j, 8)
                {
                    if (j == b[i])
                    {
                        cout << "Q";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
                cout << endl;
            }
        }

    } while (next_permutation(b.begin(), b.end()));

    return 0;
}