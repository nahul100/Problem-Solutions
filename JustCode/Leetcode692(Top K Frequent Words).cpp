#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7 ;
int cmp(pair<int,string>&p1,pair<int,string>&p2){
    if(p1.first!=p2.first)return p1.first > p2.first ;
    return p1.second<=p2.second ;
}
vector<string> topKFrequent(vector<string>& v, int k) {
        map<string,int>m;
        vector<string>ans ;
            for(auto u : v)m[u]++ ;
            vector<pair<int,string>>c ;
            for(auto [x,y] : m)c.push_back({y,x}) ;
           // sort(c.rbegin(),c.rend()) ;

            sort(c.begin(),c.end(),cmp) ;
              while(c.size()>k)c.pop_back() ;
            for(int i = 0;i<k;i++){
               ans.push_back(c[i].second) ;
            }
            return ans ;
    }
int main() {
        int n,k;cin>>n>>k ;
        vector<string>a(n) ;
        for(string &i : a)cin>>i ;
        vector<string>vs = topKFrequent(a,k) ;
        for(auto x : vs)cout<<x<<" " ;
        cout<<endl ;

    return 0;
}
