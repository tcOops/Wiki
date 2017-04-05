#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int getValue(vector<int> gifts, int n) {
        // write code here
        if(n == 0) return 0;
        
        int maxV = -1, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(cnt == 0) {
                maxV = gifts[i];
                cnt = 1;
            }
            else {
                if(gifts[i] == maxV) {
                    ++cnt;
                }
                else {
                    cnt--;
                    if(cnt == 0) {
                        maxV = -1;
                    }
                }
            }
        }
        
        if(cnt == 0 || maxV == -1) {
            return 0;
        }
        else {
            return maxV;
        }
}

int main() {
}