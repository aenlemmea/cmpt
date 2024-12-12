#include<set>
#include<map>
#include<deque>
#include<stack>
#include<queue>
#include<time.h>
#include<math.h>
#include<cctype>
#include<vector>
#include<random>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>

//#include<bits/stdc++.h>

#define ll                                    long long
#define lowbit(x) (x & -x)



using namespace std;
mt19937 rnd(time(0));
const ll mod = 998244353;
const int32_t inf = 1e9 + 10;
const ll INF = 9223372036854775807;
const ll MMOD = 1e9 + 7;

ll power(ll x, unsigned ll y) {
    // returns  x^y % p
    ll res = 1;
    x = x % MMOD;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % MMOD;
        y = y>>1;
        x = (x*x) % MMOD;
    }
    return res;
}

ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
void fio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {

}

int main()
{
    fio();

    #ifndef ONLINE_JUDGE
        freopen("test.in", "r", stdin);
    #endif

    ll t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
