 #include<bits/stdc++.h>
 #define LL long long
 using namespace std;
 vector<int> answerQueries(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end()) ;
        vector<int>p(a.size()+1,0) ;
        vector<int>v ;
        for(int i = 0;i<a.size();i++)p[i+1] = p[i] + a[i] ;
        for(int i = 0;i<b.size();i++){
            int l = 0,h = a.size()-1,an = -1 ;
            while(l<=h){
                int m = (l+h)/2 ;
                if(p[m+1] <=b[i]){
                    an = m+1 ;
                    l = m+1 ;
                }
                else h = m-1 ;
            }
          if(an!=-1)v.push_back(an) ;
          else v.push_back(0) ;
        }
        return v ;
 }
 int main(){
        int n,m;cin>>n>>m ;
        vector<int>a(n),b(m) ;
        for(int &i : a)cin>>i ;
        for(int &i : b)cin>>i ;
        vector<int>ans = answerQueries(a,b) ;
        for(int i : ans)cout<<i<<" " ;
        cout<<endl ;

}
