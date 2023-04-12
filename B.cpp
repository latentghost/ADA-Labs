using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>

#define ll long long

int mod = 1e9 + 7;


void color(int curr,ll dp[][2],vector<vector<int>> &adj,vector<int> &visited) {
    visited[curr-1] = 1;

    for(int child:adj[curr]){
        if(visited[child-1]==0){
            color(child,dp,adj,visited);

            dp[curr][0] *= (dp[child][0] + dp[child][1]);
            dp[curr][1] *= dp[child][0];
            dp[curr][0] %= mod;
            dp[curr][1] %= mod;
        }
    }
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adjl(n+1);
    vector<int> vis(n,0);
    ll dp[n+1][2];

    for(int i=0; i<=n; i++)
        dp[i][0] = dp[i][1] = 1;

    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    color(1,dp,adjl,vis);
    cout << (dp[1][0] + dp[1][1])%mod << endl;

    return 0;
}