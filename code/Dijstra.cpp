#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define MAX 210
#define INF 100000

int dis[MAX][MAX];
int len[MAX];
bool visit[MAX];

int dijkstra(int b, int e, int n){
    memset(visit, 0, sizeof(visit));

    for(int i = 0; i < n; i++)
        len[i] = INF;

    len[b] = 0;
    for(int i = 0; i < n; i++){
        int min = INF;
        int v = b;
        for( int j = 0; j < n; j++)
            if(!visit[j] && len[j] < min){
                min = len[j];
                v = j;
            }
        visit[v] = true;
        for(int j = 0; j < n; j++)
            if(!visit[j] && len[v] + dis[v][j] < len[j])
                len[j] = len[v] + dis[v][j];
    }

    if( visit[e] ) return len[e];
    else return -1;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int N;
        cin >> N;

        map<string, int> sysu;
        int num = 0;
        int d;
        string s1, s2;

        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
                dis[i][j] = (i == j? 0:INF);

        for(int i = 0; i < N; i++){
            cin >> s1 >> s2 >> d; 
            if( !sysu.count(s1) ) sysu[s1] = num++;
            if( !sysu.count(s2) ) sysu[s2] = num++;
            dis[sysu[s1]][sysu[s2]] = dis[sysu[s2]][sysu[s1]] = d;
        }

        string b, e;
        cin >> b >> e;

        if(b == e) cout << 0 << endl;
        else if( !sysu.count(b) || !sysu.count(e) ) cout << -1 << endl;
        else cout << dijkstra(sysu[b], sysu[e], num) << endl;
    }
    return 0;
}
