using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>


#define pb push_back
#define ll long long


vector<int> djikstra(vector<vector<pair<int,pair<int,int>>>> &adj){
    int n = adj.size();
    vector<int> lens(n,INT_MAX);
    lens[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int curr = pq.top().second;
        if(curr==n){
            return lens;
        }
        pq.pop();

        for(auto &v: adj[curr-1]){
            int w = 0;
            int f = (int) sqrt(v.second.second);
            if(lens[curr-1]>=f)
                w = v.second.first + (v.second.second/(1 + lens[curr-1]));
            
            else
                w = f - lens[curr-1] + v.second.first + v.second.second/(1 + f);
            
            if(lens[curr-1] + w < lens[v.first-1]){
                lens[v.first-1] = lens[curr-1] + w;
                pq.push({lens[v.first-1],v.first});
            }
        }
    }

    return lens;
}


int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,pair<int,int>>>> wts(n,vector<pair<int,pair<int,int>>>(n,{-1,{INT_MAX,INT_MAX}}));
    vector<vector<pair<int,pair<int,int>>>> adjl(n);

    for(int i=0; i<m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        if(wts[a-1][b-1].second.first==INT_MAX){
            adjl[a-1].pb({b,{c,d}});
            adjl[b-1].pb({a,{c,d}});
            wts[a-1][b-1] = {adjl[a-1].size()-1,{c,d}};
            wts[b-1][a-1] = {adjl[b-1].size()-1,{c,d}};
        }
        else{
            if(c+d < wts[a-1][b-1].second.first + wts[a-1][b-1].second.second){
                adjl[a-1][wts[a-1][b-1].first].second = {c,d};
                adjl[b-1][wts[b-1][a-1].first].second = {c,d};
                wts[a-1][b-1].second = wts[b-1][a-1].second = {c,d};
            }
        }
    }

    vector<int> times = djikstra(adjl);

    cout << times[n-1] << endl;
}