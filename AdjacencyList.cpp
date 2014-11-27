#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 205;
const int INF = 1000000;

int dis[MAXN];
int n;
bool visit[MAXN];



struct edge{
    int u;
    int v;
    int w;

    edge(int uu, int vv, int ww){
        u = uu;
        v = vv;
        w = ww;

    }
};

int dijkstra(int st, int ed, vector<edge> G[]){
    memset(visit, false, sizeof(visit));
    
    for(int i = 0; i < n; i++)
        dis[i] = INF;

    dis[st] = 0;
    
    for(int i = 0; i < n; i++){
        int min = INF;
        int minIndex = st;

        for(int j = 0; j < n; j++)
            if(!visit[j] && dis[j] < min){
                min = dis[j];
                minIndex = j;
            }

        visit[minIndex] = 1;

        for(int j = 0; j < G[minIndex].size(); j++){
            int y = G[minIndex][j].v;
            int w = G[minIndex][j].w;
        
            if(!visit[y] && dis[minIndex] + w < dis[y])
                dis[y] = dis[minIndex] + w;
        }
    }
    if(visit[ed]) return dis[ed];
    else return -1;


}


int main(){
    int t;
    cin >> t;

    while(t--){
        int e;
        cin >> e;

        string s1, s2;
        int w;
        n = 0;
        map<string, int> m;
        vector<edge> G[MAXN];

        for(int i = 0; i < e; i++){
            cin >> s1 >> s2 >> w;


            if(!m.count(s1)) m[s1] = n++;
            if(!m.count(s2)) m[s2] = n++;

            edge E1 = edge(m[s1], m[s2], w);
            edge E2 = edge(m[s2], m[s1], w);

            G[m[s1]].push_back(E1);
            G[m[s2]].push_back(E2);
        }

        string st, ed;
        cin >> st >> ed;
        
        if(st == ed)
            cout << 0 << endl;
        else if(!m.count(st) || !m.count(ed))
            cout << -1 << endl;
        else
            cout << dijkstra(m[st], m[ed], G) << endl;
    }
}

