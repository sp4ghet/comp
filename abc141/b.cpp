#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 1; i <= s.size(); i++)
    {
        char c = s.at(i - 1);
        if (c == 'U' || c == 'D')
        {
            continue;
        }
        if (i % 2 && c != 'R')
        {
            ok = false;
        }
        if (i % 2 == 0 && c != 'L')
        {
            ok = false;
        }
    }

    string ans = ok ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}