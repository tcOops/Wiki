//POJ 2676
//搜索 -> 弱剪枝

#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10;
int sk[N][N];
char ssk[N];
int r[N], c[N], t[N];

int cal(int x, int y) {
    return (x / 3 * 3) + y / 3;
}

bool solve(int x, int y) {
    if(x >= 9) return true;
    int newx = x, newy = y + 1;
    if(newy == 9) {
        newx += 1;
        newy = 0;
    }
    
    if(sk[x][y] == 0) {
        for(int i = 1; i <= 9; ++i) {
            if(r[x] & (1<<i)) continue;
            if(c[y] & (1<<i)) continue;
            if(t[cal(x, y)] & (1<<i)) continue;
            r[x] |= (1<<i);
            c[y] |= (1<<i);
            t[cal(x, y)] |= (1<<i);
            sk[x][y] = i;
            if(solve(newx, newy)) {
                return true;
            }
            sk[x][y] = 0;
            r[x] &= ~(1<<i);
            c[y] &= ~(1<<i);
            t[cal(x, y)] &= ~(1<<i);
        }
        return false;
    }
    else {
        return solve(newx, newy);
    }
}

int main() {
    for(int i = 0; i < 9; ++i) {
        scanf("%s", ssk);
        for(int j = 0; j < 9; ++j) {
            sk[i][j] = ssk[j] - '0';
            if(sk[i][j] == 0) continue;
            r[i] |= (1<<sk[i][j]);
            c[j] |= (1<<sk[i][j]);
            t[cal(i, j)] |= (1<<sk[i][j]);
        }
    }

    solve(0, 0);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            printf("%d", sk[i][j]);
        }
        puts("");
    }
    return 0;
}
