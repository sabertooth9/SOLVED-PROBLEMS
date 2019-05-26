#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
#define fbo find_by_order //k th index
#define ook order_of_key // strictly smaller than k
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define lead_zero(x) __builtin_clzll(x)
#define trail_zero(x) __builtin_ctzll(x)
#define total_1s(x) __builtin_popcountll(x)
#define first_1(x) __builtin_ffsll(x)
#define log2_(x) __builtin_clz(1) - __builtin_clz(x)
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define QUERY int test;scanf("%d", &test);for (int _T = 1; _T <= test; _T++)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define reunique(v) v.resize(std::unique(all(v)) - v.begin())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MERGE(v1, v2, v) merge(all(v1), all(v2), back_inserter(v))
#define MP make_pair
#define EB emplace_back
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define in_range(v, r, l) upper_bound(all(v), r) - lower_bound(all(v), l)
#define LCM(a,b) (a/__gcd(a,b))*b;
#define SEGTREE int mid=(st+en)/2,lt=node*2,rg=node*2+1
template<typename T1,typename T2>
ostream& operator<<(ostream &fout,const pair<T1,T2>&ps) {
    fout<<ps.ff<<" "<<ps.ss;
    return fout;
}
template<typename T1,typename T2>
ostream& operator<<(ostream &fout,const map<T1,T2>&mp) {
    for(pair<T1,T2> i:mp)
        fout<<i.first<<" : "<<i.second<<endl;
    return fout;
}
template<typename T>
ostream& operator<<(ostream& fout,const vector<T>&v) {
    for(T i:v)
        fout<<i<<"\n";
    return fout;
}
template<typename T>
ostream& operator<<(ostream& fout,const set<T>&v) {
    for(T i:v)
        fout<<i<<" ";
    return fout;
}
template<typename T>
ostream& operator<<(ostream& fout,const ordered_set<T>&v) {
    for(T i:v)
        fout<<i<<" ";
    return fout;
}
ll rdn(int y, int m, int d) {
    /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
/* Direction arrays */
/* int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1}; */                         // 4 Direction
/*int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};   */    // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */            // Hexagonal Direction
/* int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; */
pii v[3000];
double mp[3000];
int solve(int sz) {
    double val1,val2;
    int x1,y1,x2,y2;
    int ans=0;
    int szm=0;
    int xx=0;
    for(int i=0; i<sz; i++) {
        x1=v[i].ff;
        y1=v[i].ss;
        szm=0;
        xx=0;
        for(int j=i+1; j<sz; j++) {
            x2=v[j].ff;
            y2=v[j].ss;
            val1=x1-x2;
            val2=y1-y2;
            if(val2==0.0){
                xx++;
                continue;
            }
            mp[szm++]=val1/val2;
        }
        ans=max(ans,xx);
        sort(mp,mp+szm);
        int cnt=0;
        for(int j=0; j<szm; j++) {
            if(j==0){
                cnt=1;
                ans=max(ans,cnt);
                continue;
            }
            if(mp[j]!=mp[j-1])
                cnt=1;
            else
                cnt++;
            ans=max(ans,cnt);
        }
    }
    return ans;
}
int main() {
    QUERY{
        int n;
        scanf("%d",&n);
        int x,y;
        for(int i=0; i<n; i++)
            scanf("%d %d",&v[i].ff,&v[i].ss);
        int ans=solve(n);
        printf("%d\n",ans);
    }
}

