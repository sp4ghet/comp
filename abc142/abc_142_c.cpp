#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> c(N);
    for(int i=1; i<N+1; i++){
        int a;
        cin >> a;
        c[a-1] = i;
    }

    for(int i=0; i<N; i++){
        cout << c[i] << " ";
    }
    // cout << endl;
    return 0;
}