#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 205;
const int INF = 1000000;

int dis[MAXN];
int n;
typedef pair<int, int> pii;

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
    priority_queue<pii> q;
    for(int i = 0; i < n; i++)
        dis[i] = (i == st? 0 : INF);

    q.push(make_pair(dis[st], st));

    while(!q.empty()){
        pii u = q.top();
        q.pop();
        int x = u.second;
        if(u.first != dis[x]) continue;

        for(int i = 0; i < G[x].size(); i++){
            int y = G[x][i].v;
            int w = G[x][i].w;
            if(dis[y] > dis[x] + w){
                dis[y] = dis[x] + w;
                q.push(make_pair(dis[y], y));
            }
        }
    }
    if(dis[ed] == INF)
        return -1;
    else return dis[ed];
}
int main(){
    int t, w;
    string u, v;

    cin >> t;
    while(t--){
        n = 0;
        int e;
        cin >> e;
        map<string, int> M;
        vector<edge> G[MAXN];
        for(int i = 0; i < e; i++){
            cin >> u >> v >> w;
            if(!M.count(u))
                M.insert(make_pair(u, n++));
            if(!M.count(v))
                M.insert(make_pair(v, n++));

            edge E1(M[u], M[v], w);
            edge E2(M[v], M[u], w);
            G[M[u]].push_back(E1);
            G[M[v]].push_back(E2);
        }
        string st, ed;
        cin >> st >> ed;
        if(st == ed)
            cout << 0 << endl;
        else if(!M.count(st) || !M.count(ed))
            cout << -1 << endl;
        else
            cout << dijkstra(M[st], M[ed], G) << endl;
    }
}
