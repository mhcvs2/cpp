#include "stdafx.h"

static long hash = 100000007;

int FindString(int N, char *A, int M, char *B){

	int count = 0;
	if(N < M) return 0;
	
	long t = 1;
	for(int i=0; i<M; i++){
		t *= hash;
	}

	long wordHash = 0;
	long storyHash = 0;

	for(int i=0; i<M; i++) {
		wordHash = wordHash * hash + B[i];
		storyHash = storyHash * hash + A[i];
	}

	for(int i=0; i<=N-M; i++) {
		if (wordHash == storyHash){
			count++;
		}
		if(i+M < N) {
			storyHash = storyHash * hash + A[i+M] - A[i] * t;
		}
	}
return count;
}
