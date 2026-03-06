// setでイテレーションをとる方法 ABC430 D の回答コードから抜粋
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    ll ans = 0;
    vector<int> dist(n+2);
    set<pair<int,int>> st;
    st.emplace(0,0);
    st.emplace(2e9, n+1);
    dist[0]= 2e9;ans+=2e9;

    auto update = [&](int i, int d){
        ans -= dist[i];
        dist[i] = min(dist[i], d);
        ans += dist[i];
    };

    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        auto it = st.emplace(x, i).first;
        int dprev = x - prev(it)->first;
        int dnext = next(it)->first - x;
        dist[i] = min(dprev, dnext);
        ans+=dist[i];

        int pi = prev(it)->second;
        int ni = next(it)->second;
        update(pi, dprev);
        update(ni, dnext);

        cout<<ans<<endl;
    }
}
