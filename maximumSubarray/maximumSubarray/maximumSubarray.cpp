// maximumSubarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int M[200000];
int sum[200000];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/* 
	The freopen function below opens input.txt in read only mode and 
	sets your standard input to work with the opened file. 
	When you test your code with the sample data, you can use the function
	below to read in from the sample data file instead of the standard input.
	So. you can uncomment the following line for your local test. But you
	have to comment the following line when you submit for your scores.
	*/

	//freopen("input.txt", "r", stdin);
	cin>>T;

	/*
	   Read each test case from standard input.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			Please, implement your algorithm from this section.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		cin>>N;
		for (int n=0; n<N;n++){
			cin>>M[n];
		}
		sum[0] = M[0];
		for(int i=1; i<N;i++){
			sum[i] = sum[i-1] + M[i];
		}
		int maxSum = sum[0];
		int min = 0;
		for (int j=1; j<N; j++){
			if(sum[j-1]<min) min = sum[j-1];
			if(sum[j] - min > maxSum) maxSum = sum[j] - min;
		}

	/*
		int maxSum = M[0];
		int currSum;
		for(int i=0; i< N; i++){
			currSum = 0;
				for(int j=i; j<N; j++){
					currSum += M[j];
					if(currSum < maxSum) maxSum = currSum;
				}
		}*/
		cout << "#" << test_case << " " << maxSum << "\n";
	}
	return 0;//Your program should return 0 on normal termination.
}
