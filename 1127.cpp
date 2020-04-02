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

const int N = (int)1e5+5;
vector< ll > V;

int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    int tc;
    cin >> tc;
    int cs = 0;
    while(tc--){
        V.clear();
        int n ;
        ll w;
        cin >> n >> w;
        vector< ll > A , B;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            V.push_back(x);
        }
        int sz = V.size();
        int cur = (sz+1) / 2;
        int rem = sz - cur;
        for(int i = 0; i < (1<<cur); i++){
            ll sum = 0LL;
            for(int j = 0; j < cur; j++){
                if(i&(1<<j)){
                    sum+=V[j];
                }
            }
            A.push_back(sum);
        }
        for(int i = 0; i < (1<<rem); i++){
            ll sum = 0LL;
            for(int j = 0; j < rem; j++){
                if(i&(1<<j)){
                    sum+=V[cur+j];
                }
            }
            B.push_back(sum);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        ll ans  = 0LL;
        for(int i = 0; i < A.size(); i++){
            ll rem = w - A[i];
            if(rem < 0){ continue ; }
            ans+=upper_bound(B.begin(),B.end(),rem) - B.begin();
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}
