#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<list>
#include<cstring>
#include<cstdint>
#include<sstream>
#include<bitset>

#define pb push_back
#define all(p) begin(p),end(p)
#define rep(ind,sz) for(int (ind) = 0; (ind) < (sz); (ind)++)
#define vi vector<int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define ve vector
#define mp make_pair
#define PI 3.14159265358979323846
#define vs ve<string>
#define int long long
// #define double long double

using namespace std;

template <class T>
istream& operator >> (istream& in, pair<T, T>& v) { in >> v.first >> v.second; return in; }
template <class T>
istream& operator >> (istream& in, vector<T>& v) { for (auto& e : v) { in >> e; } return in; }

template <class T>
ostream& operator << (ostream& out, const pair<T, T>& v) { out << v.first << " " << v.second; return out; }
template <class T>
ostream& operator << (ostream& out, const vector<T>& v) { for (auto& e : v) { out << e << " "; } out << "\n"; return out; }

void fast() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

constexpr int N = 4e5;

void precalc() {
}

struct segtree {
    vi t;
    vi b;
    int size;
    segtree (int n) {
        size = 1;
        while (size < n) size *= 2;
        t.assign(2 * size - 1, 0ll);
        b.assign(2 * size - 1, 0ll);
    }

    void push(int x, int lx, int mid, int rx) {
        t[2 * x + 1] += b[x] * (mid - lx);
        b[2 * x + 1] += b[x];

        t[2 * x + 2] += b[x] * (rx - mid);
        b[2 * x + 2] += b[x];
        
        b[x] = 0;
    }

    void update(int x) {
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }

    void add(int x, int lx, int rx, int l, int r, int v) {
        if (l <= lx && rx <= r) {
            b[x] += v;
            t[x] += (rx - lx) * v;
            return;
        }
        if (r <= lx || rx <= l) return;
        int mid = (lx + rx) / 2;
        push(x, lx, mid, rx);
        add(2 * x + 1, lx, mid, l, r, v);
        add(2 * x + 2, mid, rx, l, r, v);
        update(x);
    }

    void add(int l, int r, int v) {
        add(0, 0, size, l, r, v);
    }

    int sum(int x, int lx, int rx, int l, int r) {
        if (l <= lx && rx <= r) return t[x];
        if (rx <= l || r <= lx) return 0;

        int mid = (lx + rx) / 2;
        push(x, lx, mid, rx);

        int s1 = sum(2 * x + 1, lx, mid, l, r);
        int s2 = sum(2 * x + 2, mid, rx, l, r);
        return s1 + s2;
    }

    int sum(int l, int r) {
        return sum(0, 0, size, l, r);
    }
};

void solve() {
    
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast(); 
    precalc();
    int t = 1;
    // cin >> t;
    rep(i, t) {
#ifdef LOCAL
        cout << "test case #" << i + 1 << ":\n";
#endif
        solve();
    }
    return 0;
}