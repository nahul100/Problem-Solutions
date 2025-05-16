#include <bits/stdc++.h>
using namespace std;
long long continuousSubarrays(vector<int>&a) {
        int n = a.size() ;
        priority_queue<pair<int,int>>pq ;
            set<pair<int,int>>s ;
            long long cnt = 0,prev = 0,l = 0;
            for(int i = 0;i<n;i++){
                    pq.push({a[i],i}) ;
                    s.insert({a[i],i}) ;
                pair<int,int>x = pq.top() ;
                auto y = (*s.begin()) ;
                if(x.first-y.first > 2){
                    long long len = i-l ;
                    len = (len*(len+1LL))/2 ;
                    len -=(i-l) ;
                    cnt+=len ;
                    cnt-=prev ;
                    if(x.second > y.second){
                      while(!s.empty()&&(*s.begin()).first == y.first){
                        l = (*s.begin()).second ;
                        s.erase(s.begin()) ;
                      }
                      l++ ;
                      s.clear() ;
                      int xl = l ;
                      while(xl<=i)s.insert({a[xl],xl++}) ;
                    }
                    else {
                        l = x.second ;
                        l++ ;
                        while(!pq.empty())pq.pop() ;
                        int xl = l ;
                        while(xl<=i)pq.push({a[xl],xl++}) ;
                    }
                    prev = i - l ;
                    prev = (prev*(prev+1))/2 ;
                    prev-=(i-l) ;
                }

            }
            long long len = n - l ;
            len = (len*(len+1))/2 ;
            len-=(n-l) ;
            cnt+=len ;
            cnt-=prev ;
            return (cnt+n);
    }

int main() {
        int n;cin>>n ;
        vector<int>a(n) ;
        for(int &i : a)cin>>i ;
        cout<<continuousSubarrays(a)<<endl ;

    return 0;
}
