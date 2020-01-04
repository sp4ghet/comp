#include <bits/stdc++.h>
using namespace std;

long long gcd(long long A, long long B)
{
    if (A < B)
    {
        return gcd(B, A);
    }
    if (B == 0)
    {
        return A;
    }
    return gcd(B, A % B);
}

int main()
{
    unsigned long long int A, B;
    cin >> A >> B;

    unsigned long long int g = gcd(A, B);
    long long s = sqrt(g);

    ulong counter = 1;
    for (ulong i = 2; i <= s; i++)
    {
        if (g % i == 0)
            counter++;

        while (g % i == 0)
            g /= i;
    }
    if (g > 1)
        counter++;

    cout << counter;
    return 0;
}