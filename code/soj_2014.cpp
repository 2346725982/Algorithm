#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){

    int v[10];
    int c[301];

    memset(v, 0, sizeof(v));
    memset(c, 0, sizeof(c));

    for(int i = 0; i < m; i++)
        cin >> v[i];

    c[0] = 1;
    
    for(int i = 0; i < m; i++)
        for(int j = v[i]; j <= n; j++)
            c[j] += c[j - v[i]];

    cout << c[n] << endl;
    }
}                          
