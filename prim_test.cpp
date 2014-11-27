#include <iostream>
#include <cstring>
using namespace std;

int dis[500][500];
bool visit[500];
int cost[500];
int prev[500];

int MST_prim(int n){
    memset(visit, false, sizeof(visit));
    visit[0] = true;

    for(int i = 0; i < n; i++)
        cost[i] = dis[0][i];

    for(int i = 0; i < n; i++)
        prev[i] = -1;
    prev[0] = 0;

    int max = 0;
    for(int i = 1; i < n; i++){
        int min = 65537;
        int minIndex = 0;

        for(int j = 0; j < n; j++)
            if(!visit[j] && cost[j] < min){
                min = cost[j];
                minIndex = j;
            }

        visit[minIndex] = true;

        if(min > max) max = min;

        for(int j = 0; j < n; j++){
            if(!visit[j] && dis[minIndex][j] < cost[j]){
                cost[j] = dis[minIndex][j];
                prev[j] = minIndex;
            }
        }

    }

    return max;

    


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

        cout << MST_prim(n) << endl;
        if(t) cout << endl;
    }
}

