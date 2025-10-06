// AGENT CODE
// P3683 - [CERC2016] 地理哈希网格 Geohash Grid
// GitHub Copilot - 2025-10-06 15:00:00
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Z-order编码：交替编码x和y的二进制位
ll geohash(ll x, ll y, int n) {
    ll hash = 0;
    for (int i = n - 1; i >= 0; i--) {
        // 先编码x的第i位
        hash = (hash << 1) | ((x >> i) & 1);
        // 再编码y的第i位
        hash = (hash << 1) | ((y >> i) & 1);
    }
    return hash;
}

// 判断点(px, py)是否在多边形内（射线法）
bool pointInPolygon(ll px, ll py, vector<pair<ll, ll>>& poly) {
    int n = poly.size();
    bool inside = false;
    
    for (int i = 0, j = n - 1; i < n; j = i++) {
        ll xi = poly[i].first, yi = poly[i].second;
        ll xj = poly[j].first, yj = poly[j].second;
        
        if (((yi > py) != (yj > py)) &&
            (px < (xj - xi) * (py - yi) / (yj - yi) + xi)) {
            inside = !inside;
        }
    }
    return inside;
}

// 计算多边形面积（用于验证）
ll polygonArea(vector<pair<ll, ll>>& poly) {
    ll area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += poly[i].first * poly[j].second;
        area -= poly[j].first * poly[i].second;
    }
    return abs(area) / 2;
}

// 获取多边形内所有格子的哈希值
vector<ll> getGridsInPolygon(vector<pair<ll, ll>>& poly, int n) {
    set<ll> hashSet;
    
    // 找边界框
    ll minX = LLONG_MAX, maxX = LLONG_MIN;
    ll minY = LLONG_MAX, maxY = LLONG_MIN;
    for (auto& p : poly) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }
    
    // 检查边界框内的每个格子
    for (ll x = max(0LL, minX); x < min((1LL << n), maxX); x++) {
        for (ll y = max(0LL, minY); y < min((1LL << n), maxY); y++) {
            // 检查格子中心点(x+0.5, y+0.5)是否在多边形内
            // 使用整数运算：检查(2*x+1, 2*y+1)相对于放大2倍的多边形
            bool inside = false;
            int pn = poly.size();
            for (int i = 0, j = pn - 1; i < pn; j = i++) {
                ll xi = 2 * poly[i].first, yi = 2 * poly[i].second;
                ll xj = 2 * poly[j].first, yj = 2 * poly[j].second;
                ll px = 2 * x + 1, py = 2 * y + 1;
                
                if (((yi > py) != (yj > py)) &&
                    (px < (xj - xi) * (py - yi) / (yj - yi) + xi)) {
                    inside = !inside;
                }
            }
            
            if (inside) {
                hashSet.insert(geohash(x, y, n));
            }
        }
    }
    
    vector<ll> hashes(hashSet.begin(), hashSet.end());
    return hashes;
}

// 动态规划求最优t区间覆盖
ll minCoverArea(vector<ll>& hashes, int t) {
    int sz = hashes.size();
    if (sz == 0) return 0;
    if (t >= sz) return sz;
    
    // dp[i][j] = 用i个区间覆盖前j个点的最小面积
    vector<vector<ll>> dp(t + 1, vector<ll>(sz + 1, LLONG_MAX));
    dp[0][0] = 0;
    
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= sz; j++) {
            // 尝试用第i个区间覆盖[k+1, j]
            for (int k = i - 1; k < j; k++) {
                if (dp[i-1][k] == LLONG_MAX) continue;
                ll area = hashes[j-1] - hashes[k] + 1;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + area);
            }
        }
    }
    
    return dp[t][sz];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> polygon(m);
    for (int i = 0; i < m; i++) {
        cin >> polygon[i].first >> polygon[i].second;
    }
    // 获取多边形内的所有格子
    vector<ll> hashes = getGridsInPolygon(polygon, n);

    // 读取剩余所有整数（q和t1...tq）
    vector<int> tlist;
    int tmp;
    while (cin >> tmp) tlist.push_back(tmp);
    int q = tlist[0];
    vector<int> t(tlist.begin()+1, tlist.end());

    for (int i = 0; i < q; i++) {
        cout << minCoverArea(hashes, t[i]) << "\n";
    }
    return 0;
}