#include <cstdio>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main() {
	for(int i = 0; i < 2; ++i) {
	//	fork();
	//	printf("-\n");//6个，无缓冲区
	//	printf("-");//8个，有缓冲区
	}

	int i = 2;
	printf("%d %d\n", ++i, ++i);
	return 0;
}