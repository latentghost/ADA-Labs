using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>


#define pb emplace_back
#define ll long long


int djikstra(vector<vector<pair<int,pair<int,int>>>> &adj){
    vector<int> lens(adj.size(),INT_MAX);
    lens[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int a = pq.top().second;
        if(a==adj.size()){
            return pq.top().first;
        }
        pq.pop();

        for(int i=0; i<adj[a-1].size(); i++){
            int w = 0;
            int f = (int) sqrt(adj[a-1][i].second.second);
            if(lens[a-1]>=f)
                w = adj[a-1][i].second.first + (adj[a-1][i].second.second/(1 + lens[a-1]));
            
            else
                w = f - lens[a-1] + adj[a-1][i].second.first + adj[a-1][i].second.second/(1 + f);
            
            if(lens[a-1] + w < lens[adj[a-1][i].first-1]){
                lens[adj[a-1][i].first-1] = lens[a-1] + w;
                pq.push({lens[adj[a-1][i].first-1],adj[a-1][i].first});
            }
        }
    }

    return lens[adj.size()-1];
}


int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> inds(n,vector<int>(n,-1));
    vector<vector<pair<int,pair<int,int>>>> adjl(n);

    for(int i=0; i<m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        if(inds[a-1][b-1]==-1){
            adjl[a-1].pb(b,make_pair(c,d));
            adjl[b-1].pb(a,make_pair(c,d));
            inds[a-1][b-1] = adjl[a-1].size()-1;
            inds[b-1][a-1] = adjl[b-1].size()-1;
        }
        else{
            if(c+d < adjl[a-1][inds[a-1][b-1]].second.first + adjl[a-1][inds[a-1][b-1]].second.second){
                adjl[a-1][inds[a-1][b-1]].second = {c,d};
                adjl[b-1][inds[b-1][a-1]].second = {c,d};
            }
        }
    }

    cout << djikstra(adjl) << endl;
}