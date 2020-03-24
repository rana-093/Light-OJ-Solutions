#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"
#define db(x) cout<<#x<<" ->"<<x<<endl
#define db2(x,y) cout<<#x<<"->"<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define db4(w,x,y,z) cout<<#w <<" -> " << w << " , " << #x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<< endl
#define IN freopen("input.txt","r",stdin)
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 1e5+5;

double dp[N];

double solve(int cur){
    if( cur == 1){ return 0.0; }
    double &ret = dp[cur];
    if(ret!=-1.00){ return ret;}
    ret = 0.0;
    int cnt = 0;
    for(int i = 1; i * i <= cur; i++){
        if(cur % i==0){
            ret+=solve(i);
            ++cnt;
            if( i * i != cur){
                ++cnt;
                ret+=solve(cur / i);
            }
        }
    }
    int sz = cnt;
    ret+=(double)sz;
    ret/=(double)sz-1;
    return ret;
}

int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    int cs = 0;
    int tc;
    cin >> tc;
    for(int i = 0; i < N; i++){
        dp[i] = -1.00;
    }
    while(tc--){
        int n;
        cin >> n;
        double ans = solve(n);
        cout << "Case " << ++cs << ": " << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
