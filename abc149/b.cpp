#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll subB = max(k - a, 0LL);

    a -= min(a, k);
    b -= min(b, subB);

    printf("%lld %lld\n", a, b);

    return 0;
}