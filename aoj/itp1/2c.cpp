#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto x = upper_bound(a.begin(), a.end(), 3);
    cout << x - a.begin() << endl;

    return 0;
}