#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;
const int M = 2e5 ;
vector<vector<int>>g;
vector<int>v,p ;
int root ;
void dfs(vector<vector<int>>&g,int node,int par){
        bool f = true ;
        for(auto child : g[node]){
            if(child == par)continue ;
            dfs(g,child,node) ;
        }
        if(node!=root)v.pb(node);

}

int main(){
    std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      int tc;cin>>tc;
     while(tc--){
        int n;cin>>n ;
        g.resize(n+1) ;
        int a[n],mn = INT_MAX;
        root = -1;
        for(int i = 1,x;i<=n;i++){
            cin>>x;
            if(x<mn){
                mn = x ;
                root = i ;
            }
        }
        for(int i = 0;i<n-1;i++){
            int x,y;cin>>x>>y ;
            g[x].pb(y) ;
            g[y].pb(x) ;
        }
        dfs(g,root,-1) ;
        cout<<n-1<<'\n' ;
        for(auto x : v)cout<<x<<" ";cout<<'\n' ;
        g.clear() ;
        v.clear() ;


     }
    return 0;
}
