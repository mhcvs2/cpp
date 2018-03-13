// lcs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAX_L 1025


inline int MyStrLen(char *str)
{
    int j = 0;
    while(str[j] != '\0') 
    {
        j++;
    }
    return j;
}

static int d[MAX_L][MAX_L];

int solve(char *A, char *B)
{
	int n = MyStrLen(A);
	int m = MyStrLen(B);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(A[i-1] == B[j-1]) d[i][j] = d[i-1][j-1] + 1;
			else d[i][j] = (d[i-1][j] > d[i][j-1]) ? d[i-1][j]:d[i][j-1];
		}
	}
	return d[n][m];
}

static char A[MAX_L] = {'0'};
static char B[MAX_L] = {'0'};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int result;

	freopen("sample_input.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	cin>>T;
	

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>A>>B;
		result = solve(A, B);
		cout<<"#"<<test_case<<" "<<result<<endl;
	}

	return 0;
}

