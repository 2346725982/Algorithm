#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

int main(){
   int m[11] = {0, 10, 15, 22, 35, 12, 18, 20, 20, 25, 30};
   int t[8] = {0, 30, 22, 18, 25, 27, 35, 25};

   int dp[11][8] = {0};

   int sum[11] = {0};

   for(int i = 1; i <= 10; i++)
       sum[i] = sum[i-1] + m[i];

   for(int i = 1; i <= 7; i++)
       for(int j = 1; j <= 10; j++)

           for(int k = 0; k <= j - 1; j++)
                //dp[i][j] = min(dp[i][j], dp[i-1][k] + pow(max(sum[j] - sum[k] - m[i], 0), 4) + pow(max(m[i] - (sum[j] - sum[k]), 0), 4)); 
               dp[i][j] = min(dp[i][j], 10);

    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 10; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    
}
