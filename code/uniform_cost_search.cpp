#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define INF 100000

int dis[210][210];
int length[210];
bool visit[210];

int UniformCostSearch(int begin, int end, int n){
    memset(visit, false, sizeof(visit));
    
    for(int i = 0; i < n; i++)
        length[i] = INF;

    length[begin] = 0;

    for(int i = 0; i < n; i++){
        int min = INF;
        int minIndex = 0;

        for(int j = 0; j < n; j++)
            if(! visit[j] && length[j] < min){
                min = length[j];
                minIndex = j;
            }

        if(minIndex == end) return min;

        visit[minIndex] = 1;

        for(int j = 0; j < n; j++)
            if(!visit[j] && length[j] > length[minIndex] + dis[minIndex][j])
                length[j] = length[minIndex] + dis[minIndex][j];
                
    }

    if(visit[end]) return length[end];
    else return -1;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int num = 0;
        int d;
        string s1, s2;
        map<string, int> m;

        for(int i = 0; i < 210; i++)
            for(int j = 0; j < 210; j++)
                dis[i][j] = (i == j? 0:INF);


        for(int i = 0; i < n; i++){
            cin >> s1 >> s2 >> d;
            if(!m.count(s1)) m[s1] = num++;
            if(!m.count(s2)) m[s2] = num++;

            dis[m[s1]][m[s2]] = dis[m[s2]][m[s1]] = d;
        }

        cin >> s1 >> s2;

        if(s1 == s2) cout << 0 << endl;
        else if(! m.count(s1) || !m.count(s2)) cout << -1 << endl;
        else cout << UniformCostSearch(m[s1], m[s2], num) << endl;
    }
            
}


