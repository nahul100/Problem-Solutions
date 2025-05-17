#include <bits/stdc++.h>
#define pb push_back
using namespace std ;
const int N = 1e5+10 ;
vector<int>g[N] ;
vector<int>v;
bool vis[N] = {false} ;
int height[N] ;
void dfs(int node,int par){
        for(auto child : g[node]){
             if(child ==par)continue ;
                dfs(child,node) ;
                height[node] = max(height[node],height[child]+1) ;

        }

}
int main(){
         int tc;cin>>tc;
         while(tc--){
         int n,e;cin>>n ;
         for(int i = 1;i<=n;i++)g[i].clear() ;
         for(int i = 1;i<=n-1;i++){
            int x,y;cin>>x>>y ;
            g[x].pb(y) ;
            g[y].pb(x) ;
         }
         dfs(1,0) ;
         int cn = 0 ;
         for(int i = 1;i<=n;i++){
            if(height[i]==0)cn++ ;
         }
         cn++ ;
         cn+=(g[1].size()==1) ;
         cout<<cn/2<<endl ;
         for(int i = 1;i<=n;i++)height[i] = 0;
        }
}
