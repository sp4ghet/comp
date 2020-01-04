#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    double x = floor(n / 2.0);

    double prob = 0;
    if (n % 2 == 0)
    {
        prob = 0.5;
    }
    else
    {
        prob = (x + 1) / n;
    }

    cout << prob << endl;

    return 0;
}