#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
//#include<unordered_map>
typedef long long ll;
typedef unsigned long long ull;
//#define gcd(A,B)    __gcd(A,B)
#define PQ 			priority_queue
#define ii 			int,int
#define pll         pair<ll,ll>
#define PI          2*acos(0.0)
#define all(v)      v.begin(),v.end()
#define pii 		pair<ii>
#define sf(x) 		scanf("%I64d",&x)
#define sff(x,y) 	scanf("%I64d %I64d",&x,&y)
#define sl(x)   	scanf("%lld",&x)
#define sll(x,y)   	scanf("%lld %lld",&x,&y)
#define ff          first
#define ss          second
#define segtree     lt=2*par,rg=2*par+1,mid=(st+en)/2
#define read        freopen("input.txt","r",stdin)
#define write       freopen("output.txt","w",stdout)
using namespace std;
const ll mod=100000007;
ll dp[10000+2];
int ara[109];
int n,k;
int main()
{
    int test;
    scanf("%d",&test);
    for(int T=1; T<=test; T++)
    {
        memset(dp,0,sizeof dp);
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%d",ara+i);
        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=ara[i];j<=k;j++)
            {
                dp[j]+=dp[j-ara[i]];
                dp[j]%=mod;
            }
        }
        printf("Case %d: %lld\n",T,dp[k]);
    }
}
