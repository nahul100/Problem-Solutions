 #include<bits/stdc++.h>
 #define LL long long
 using namespace std;
 vector<int> nextGreaterElements(vector<int>& a) {
         int n = a.size() ;
         vector<int>v(2*n,-1) ;
         for(int i = 0;i<n;i++)a.push_back(a[i]) ;
         stack<int>st ;
         for(int i = 2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=a[i])st.pop() ;
            if(st.empty())v[i] = -1 ;
            else v[i] = st.top() ;
            st.push(a[i]) ;
         }
         v.resize(n) ;
         return v ;

 }
 int main(){
        int n,m;cin>>n ;
        vector<int>a(n) ;
        for(int &i : a)cin>>i ;
        vector<int>ans = nextGreaterElements(a) ;
        for(int i : ans)cout<<i<<" " ;
        cout<<endl ;

}
