#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int w[101], v[101];
    int c[1001];
    int c2[1001];

    memset(c, 0, sizeof(c));
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));

    for(int i = 1; i <= m; i++)
        cin >> w[i] >> v[i];

    for(int i = 1; i <= m; i++)
        for(int j = n; j >= w[i]; j--)
            c[j] = max(c[j], c[j - w[i]] + v[i]);

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
            if(i >= w[j])
                c2[i] = max(c2[i], c2[i - w[j]] + v[j]);
            else
                c2[i] = c2[j];

    cout << c2[n] << endl; 
}

