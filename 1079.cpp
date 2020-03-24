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
const int N = 105;
int M[N];
double P[N];
double dp[N][N*100];
const double inf =(double)8;
double p;
double eps = (double)1e-6;

double solve(int cur, int money){
//    db2(cur,money);
    if(money == 0){ return 0.0 ; }
    if( cur < 1 ){ return inf;}
    double &ret = dp[cur][money];
    if(ret!=-1.00){ return ret ;}
    ret  = inf;
    ret = min(ret,solve(cur-1,money));
    if(money-M[cur] >= 0){
        ret = min(ret, (P[cur] + (1-P[cur])  * solve(cur-1,money-M[cur]) ) );
    }
    return ret;
}

int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
//    cout << fixed << setprecision(10) <<  eps << endl;
    int cs = 0;
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> p >>  n;
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j < N * 100 ; j++){ dp[i][j] = -1.00; }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> M[i] >> P[i];
            sum+=M[i];
        }
        int ans = 0;
        for(int i = sum; i >= 0; i--){
            double bal = solve(n,i);
            if( (bal + eps) <= p){
                ans = i;
                break;
            }
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}
