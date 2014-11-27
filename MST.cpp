#include <iostream>
using namespace std;

#define MAX 500
#define INF 65536
int dis[MAX][MAX];
int tmp[MAX];

int min(int n){
    int min = INF;
    int result;

    for(int i = 0; i < n; i++)
        if(tmp[i] > 0 && tmp[i] < min){
            result = i;
            min = tmp[i];
        }

    return result;
}

int MST_Prim(int n){
    int re = 0;
    int k;
    for(int i = 0; i < n; i++)
        tmp[i] = dis[0][i];

    for(int i = 1; i < n; i++){
        k = min(n);
        re = tmp[k] > re? tmp[k] : re;
        tmp[k] = 0;

        for(int j = 0; j < n; j++)
            if(dis[k][j] < tmp[j])
                tmp[j] = dis[k][j];
    }

    return re;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> dis[i][j];


        cout << MST_Prim(n) << endl;
        if(t) cout << endl;
    }
}
