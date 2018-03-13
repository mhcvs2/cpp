// complexCompounds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
#define MAX_DATA_SIZE 5000
#define WORD_LEN 10
#define MIN_WORD_LEN 3

static char testdata[500][WORD_LEN];
static SInfo gMainData[MAX_DATA_SIZE];
static int gvisited[MAX_DATA_SIZE][WORD_LEN];
static int N, U, Q, U1;
static SInfo gNewData[10];

extern void init();
extern void AddDB(SInfo info);
extern int SearchBestCase(SInfo info);
void MyStrCpy(char *src, char *dst)
{
	int i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}
int MyStrCmp(char *src, char *dst)
{
	int i = 0;
	while (src[i] && dst[i])
	{
		if (src[i] != dst[i])
			return 0;
		i++;
	}
	if (src[i] == 0 && dst[i] == 0)
		return 1;
	return 0;
}
int CalculateRelation(char *src, char *dst)
{
	int i = 0, relation = 0;
	if (MyStrCmp(src, dst) == 1)
		return 100;
	for (i = 0; src[i] && dst[i]; i++)
	{
		relation += src[i] - 'a' + dst[i] - 'a';
	}
	if (relation > 99)
		relation = 99;
	return relation;
}

int main()
{
	clock_t start, end;
	start = clock();
	SInfo tmptest;
	int T, i, j, k, test_case, t1, t2, t3, t4, query, result, ans, score;
	std::ifstream in("sample_input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	//std::ofstream out("sample_output.txt");
	//	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	//	std::cout.rdbuf(out.rdbuf()); //redirect std::cin to in.txt!
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> Q;
		score = 100;
		for (i = 0; i < N; i++)
		{
			cin >> gMainData[i].first >> gMainData[i].second >> gMainData[i].third >> gMainData[i].fourth >> gMainData[i].fifth;
		}
		init();
		for (i = 0; i < N; i++)
			AddDB(gMainData[i]);
		for (query = 0; query < Q; query++)
		{
			cin >> tmptest.first >> tmptest.second >> tmptest.third >> tmptest.fourth >> tmptest.fifth;
			result = SearchBestCase(tmptest);
			cin >> ans;
			//printf("result: %d,   ans: %d\n", result, ans);
			if (ans != result)
				score = 0;
		}
		cout <<"#"<<test_case<<": "<< score << endl;
	}
	end = clock();
	printf("Total time--------------------------------------------------: %d ms\n", end-start);
	return 0;
}

