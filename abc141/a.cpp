#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;

    cin >> s;

    if (s == "Sunny")
    {
        cout << "Cloudy" << endl;
    }
    else if (s == "Cloudy")
    {
        cout << "Rainy" << endl;
    }
    else if (s == "Rainy")
    {
        cout << "Sunny" << endl;
    }

    return 0;
}