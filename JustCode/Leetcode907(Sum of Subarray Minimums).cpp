#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7 ;
int sumSubarrayMins(vector<int>& a) {
        int n = a.size() ;
        stack<int>st ;
        vector<int>nsec(n) ;
        for(int i = n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] >a[i]){
            st.pop() ;
        }
        nsec[i] = st.empty()?n:st.top() ;
        st.push(i) ;
        }
        while(!st.empty())st.pop() ;
        vector<int>psec(n) ;
        for(int i = 0;i<n;i++){
        while(!st.empty() && a[st.top()] >=a[i]){
            st.pop() ;
        }
        psec[i] = st.empty()?-1:st.top() ;
        st.push(i) ;
        }
      long long tot = 0;
       for(int i = 0;i<n;i++){
           long long left = i - psec[i] ;
           long long right = nsec[i] - i ;
           tot = (tot + (left*right*1LL*a[i])%mod)%mod ;
          // tot%=mod ;
       }
       return tot ;
    }
int main() {
        int n;cin>>n ;
        vector<int>a(n) ;
        for(int &i : a)cin>>i ;
        cout<<sumSubarrayMins(a)<<endl ;

    return 0;
}
