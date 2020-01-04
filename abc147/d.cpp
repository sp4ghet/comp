#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300000;
int n;
unsigned long long a[MAX_N];
const long long mod = 1000000007;

void solve()
{
    unsigned long long ans = 0;
    for (int i = 0; i < 60; i++)
    {
        unsigned long long bit = 1ULL << i;
        int oc = 0,
            zc = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % 2 == 0)
            {
                zc++;
            }
            else
            {
                oc++;
            }
            a[j] /= 2;
        }
        unsigned long long add = (bit % mod);
        add *= oc;
        add %= mod;
        add *= zc;
        add %= mod;
        ans = (ans + add) % mod;
    }
    cout << ans << endl;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve();
    return 0;
}
