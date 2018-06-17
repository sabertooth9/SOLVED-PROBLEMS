#include<bits/stdc++.h>
//#include<unordered_map>
//#include<unordered_set>
 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
/*
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
priority_queue<int, greater<int>, pairing_heap_tag> pq[1009];
#define fbo         find_by_order
#define ook         order_of_key
*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector< vector<ll> >matrix;
#define gcd(A,B)        __gcd(A,B)
#define PQ              priority_queue< ll,vector<ll>,greater<ll> >pq;
#define ii              int,int
#define pll             pair<ll,ll>
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define pii             pair<ii>
#define pb              push_back
#define sf(x)           scanf("%I64d",&x)
#define sff(x,y)        scanf("%I64d %I64d",&x,&y)
#define sl(x)           scanf("%lld",&x)
#define sll(x,y)        scanf("%lld %lld",&x,&y)
#define ff              first
#define ss              second
#define segtree         lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read            freopen("input.txt","r",stdin)
#define write           freopen("output.txt","w",stdout)
#define fast            ios_base::sync_with_stdio(0),cin.tie(0)
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define max_ull         18446744073709551615
#define max_ll          9223372036854775807;
#define set(N,cur)      N=(N|(1<<cur))
#define reset(N,cur)    N=(N&(~(1<<cur)))
#define check(N,cur)    ((N&(1<<cur))==0)
#define all(v)          v.begin(),v.end()
#define reunique(v)     v.resize(std::unique(all(v)) - v.begin())
#define loop            int test;scanf("%d",&test);for(int _T=1;_T<=test;_T++)
/*int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};   */// 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
const ll mod=10007;
ll c[4];
ll b[4];
matrix mul(matrix A,matrix B)
{
    matrix ans(4,vector<ll>(4));
    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
            for(int k=0;k<=3;k++)
                ans[i][j]=(ans[i][j]+A[i][k]*B[k][j])%mod;
    return ans;
}
matrix pow(matrix A,int p)
{
    if(p==1)
        return A;
    if(p%2==1)
        return mul(A,pow(A,p-1));
    matrix x=pow(A,p/2);
    return mul(x,x);
}
ll solve(int n)
{
    if(n<=2)
        return 0;
    matrix T(4,vector<ll>(4));
    T[1][0]=T[2][1]=T[3][3]=T[0][3]=1;
    T[0][0]=c[0],T[0][1]=0,T[0][2]=c[2];
    T=pow(T,n-2);
    ll res=0;
    for(int i=0;i<3;i++)
        res=(res+T[0][i]*b[i])%mod;
    res=(res+T[0][3]*c[3])%mod;
    return res;
}
int main()
{
    b[0]=b[1]=b[2]=0;
    loop
    {
        int n;
        scanf("%d",&n);
        sll(c[0],c[2]);
        scanf("%lld",&c[3]);
        printf("Case %d: %lld\n",_T,solve(n));
    }
}
 
