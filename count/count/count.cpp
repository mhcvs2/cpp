// count.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

const int MAXN = 500000;
const int MAXM = 100000;

extern int FindString(int N, char *A, int M, char *B);

char A[MAXN + 5];
char B[MAXM + 5];

int main(void) {
	/*
	struct timeval dwStart;
    struct timeval dwEnd;
    gettimeofday(&dwStart, NULL);
	*/
	clock_t start, end;
	start = clock();


	setbuf(stdout, NULL);

	//freopen("single.txt", "r", stdin);
	freopen("sample_input.txt", "r", stdin);

	int TestCase; 
	scanf("%d", &TestCase);
	for (; TestCase--;) {

		scanf("%s", A);
		scanf("%s", B);

		//N = Length of A, M = Length of B
		int N = 0, M = 0;
		for (; A[N]; N++);
		for (; B[M]; M++);

		int answer = FindString(N, A, M, B);

		static int tc = 0;
		printf("#%d %d\n", ++tc, answer);
	}
	/*
	gettimeofday(&dwEnd, NULL);
    unsigned long dwTime=0;
    dwTime=1000000*(dwEnd.tv_sec-dwStart.tv_sec)+(dwEnd.tv_usec-dwStart.tv_usec);
    printf("%ld\n", dwTime);
	*/
	end = clock();
	printf("Total time: %d ms\n", end-start);
	return 0;
}
