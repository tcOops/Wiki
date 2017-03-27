//平面最远点对
//凸包求解缩小点对数 O(sqrt(M))（M个点的话
//引入 旋转卡(qia)壳(ke) (Rotating calipers)
//将暴力的O(n^2)降到O(n)
//注意 ROtating Calipers的写法
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
double eps = 1e-10;
const int N = 50010;

double add(double a, double b) {
    if(abs(a+b) < eps*(abs(a) + abs(b))) {
        return 0;
    }
    return a + b;
}

struct P {
    double x, y;

    P() {}

    P(double x, double y) : x(x), y(y) {
    }

    P operator +(P p) {
        return P(add(x, p.x), add(y, p.y));
    }

    P operator -(P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }

    P operator *(double p) {
        return P(x*p, y*p);
    }

    double dot(P p) {
        return (x*p.x + y*p.y);
    }

    double det(P p) {
        return (x*p.y - y*p.x);
    }
};

bool cmp(const P &a, const P &b) {
    if(a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

vector<P> convex_hull(P *ps, int n) {
    sort(ps, ps+n, cmp);
    int cnt = 0;
    vector<P> ans(n*2);
    for(int i = 0; i < n; ++i) {
        while(cnt > 1 && (ans[cnt-1] - ans[cnt-2]).det(ps[i] - ans[cnt-1]) <= 0) {
            --cnt;
        }
        ans[cnt++] = ps[i];
    }

    for(int i = n - 2, t = cnt; i >= 0; --i) {
        while(cnt > t && (ans[cnt-1] - ans[cnt-2]).det(ps[i] - ans[cnt-1]) <= 0) {
            --cnt;
        }
        ans[cnt++] = ps[i];
    }
    if(n > 1) {
        ans.resize(cnt - 1);
    }
    return ans;
}

P ps[N];
double dist(P p, P q) {
    return (p-q).dot(p-q);
}

void solve(int n) {
    vector<P> ans = convex_hull(ps, n);
    /*
    double res = 0;
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            res = max(res, dist(ans[i], ans[j]));
        }
    }
    */

    int len = ans.size();

    //Rotating calipers
    double res = 0.0;
    ans[len] = ans[0];
    int q = 1;
    for(int p = 0; p < len; ++p) {
        while((ans[p+1] - ans[p]).det(ans[q+1] - ans[p]) > (ans[p+1] - ans[p]).det(ans[q] - ans[p])) {
            q = (q + 1) % len;
        }
        res = max(res, dist(ans[p], ans[q]));
    }
    printf("%.0lf\n", res);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lf %lf", &ps[i].x, &ps[i].y);
    }
    solve(n);
    return 0;
}