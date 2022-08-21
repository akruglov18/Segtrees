#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<regex>
#include<list>

#define pb push_back
#define all(p) (p).begin(),(p).end()
#define rep(ind,sz) for(int (ind) = 0; (ind) < (sz); (ind)++)
#define vi vector<int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define ve vector
#define mp make_pair
#define PI 3.14159265358979323846
#define int long long

using namespace std;

struct segtree {
    vi t;
    vi bonus;
    int size;
    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.assign(2 * size - 1, 0);
        bonus.assign(2 * size - 1, 0);
    }

    void add(int l, int r, int v) {
        add(v, 0, l, r, 0, size);
    }

    void add(int v, int x, int l, int r,  int lx, int rx) {
        if (rx == r && lx == l) {
            t[x] += (r - l) * v;
            bonus[x] += v;
            return;
        }
        if (rx <= l || lx >= r) {
            return;
        }
        int c = (lx + rx) / 2;
        push(x, c, lx, rx);
        if (l < c) {
            add(v, 2 * x + 1, l, min(r, c), lx, c);
        }
        if (r > c) {
            add(v, 2 * x + 2, max(l, c), r, c, rx);
        }
        update(x);
    }

    int getSum(int x, int l, int r, int lx, int rx) {
        if (r <= lx || l >= rx) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return t[x];
        }
        int c = (lx + rx) / 2;
        push(x, c, lx, rx);
        int res = 0;
        if (l < c) {
            res += getSum(2 * x + 1, l, min(r, c), lx, c);
        }
        if (r > c) {
            res += getSum(2 * x + 2, max(c, l), r, c, rx);
        }
        return res;
    }

    void push(int x, int c, int l, int r) {
        t[2 * x + 1] += bonus[x] * (c - l);
        t[2 * x + 2] += bonus[x] * (r - c);
        bonus[2 * x + 1] += bonus[x];
        bonus[2 * x + 2] += bonus[x];
        bonus[x] = 0;
    }

    void update(int x) {
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }

    int getSum(int l, int r) {
        return getSum(0, l, r, 0, size);
    }
};
