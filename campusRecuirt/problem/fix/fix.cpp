//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3334&konwledgeId=156
//sogou 2017

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e7 + 10;
bool isPrime[N];
int prime[N>>2], a[N>>2];
int cnt = 0;

void pre() {    
	memset(isPrime, false, sizeof(isPrime));    
	for(int i = 2; i * i < N; ++i) {        
		if(!isPrime[i]) {            
			for(int j = i*i; j < N; j +=i) {                
				isPrime[j] = true;            
			}        
		}    
	}      
	for(int i = 2; i < N; ++i) {        
		if(!isPrime[i]) {            
			prime[cnt++] = i;        
		}    
	}
}

int main() {    
	int n;    
	scanf("%d", &n);    
	for(int i = 0;  i < n; ++i) {        
		scanf("%d", &a[i]);    
	}      

	pre();  
	long long ans = 0;    
	for(int i = 0; i < cnt; ++i) {        
		if(prime[i] > a[n-1]) break;        
		int p1 = upper_bound(a, a+n, prime[i]) - a;        
		ans += (long long) (p1) * (n - p1);    
	}    
	
	printf("%lld\n", ans);    
	return 0;
}
