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

int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    int cs = 0;
    int tc;
    cin >> tc;
    while(tc--){
        double bal = 0.0;
        double lol = 1.00;
        int ans = 0;
        int n;
        cin >> n;
        int balamar = n;
        while( bal < 0.5 ){
            lol*=(double)(balamar) / (double) n;
            bal = 1 - lol;
            --balamar;
            ++ans;
        }
        cout << "Case " << ++cs << ": "<< ans - 1  << endl;
    }
    return 0;
}
