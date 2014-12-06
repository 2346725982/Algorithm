#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAXN = 520;
const int MAXM = 125020;

int p[MAXN];
int u[MAXM], v[MAXM], w[MAXM];
int r[MAXM];

int cmp(const int i, const int j){
    return w[i] < w[j];
}

int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}

int Kruskal(const int n, const int m){
    for(int i = 0; i < n; i++){
        p[i] = i;
        
    }
    for(int i = 0; i < m; i++)
        r[i] = i;

    sort(r, r + m, cmp);

    int cnt = 0;
    int e;
    for(int i = 0; i < m; i++){
        e = r[i];
        int x = find(u[e]);
        int y = find(v[e]);

        if(x != y){
            p[x] = y;
            cnt++;

            if(cnt == n - 1)
                return w[e];
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int m = 0;
        int weight;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> weight;
                if(j > i){
                    u[m] = i;
                    v[m] = j;
                    w[m] = weight;
                    m++;
                }
            }

        cout << Kruskal(n, m) << endl;
        if(t) cout << endl;
    }
    
}

