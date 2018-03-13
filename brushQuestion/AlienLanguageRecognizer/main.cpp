#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_PHONE_SIZE 32
#define MAX_WORD_SIZE 20000

#define WORD_LENGTH 6

#define cutline 90

extern void learnphone(int M, char phone[MAX_PHONE_SIZE]);
extern void learnword(int N, char word[MAX_WORD_SIZE][WORD_LENGTH]);
extern void recognize(char in[WORD_LENGTH], char out[WORD_LENGTH]);

static int totalquery;
static int correctword;
static int M;	// phone size
static int N;	// word size

static char phone[MAX_PHONE_SIZE];
static char word[MAX_WORD_SIZE][WORD_LENGTH];

static int seed;

static int pseudo_rand() {

    seed = seed * 214013 + 2531001;
    return (seed >> 16) & 0x7fff;
}

static void makephone() {
    int idx1, idx2;

    idx1 = 0;
    while (idx1 < M) {
        phone[idx1] = pseudo_rand() % 256;
        idx2 = 0;
        while (idx2 < idx1) {
            if (phone[idx1] == phone[idx2])
                break;
            ++idx2;
        }
        if (idx1 == idx2) ++idx1;
    }
}

static void makeword() {
    for (int idx1 = 0; idx1 < N; ++idx1)
        for (int idx2 = 0; idx2 < WORD_LENGTH; ++idx2)
            word[idx1][idx2] = phone[pseudo_rand() % M];
}

static bool issame(char in[WORD_LENGTH], char out[WORD_LENGTH]) {
    for (int idx = 0; idx < WORD_LENGTH; ++idx)
        if (in[idx] != out[idx])
            return false;
    return true;
}

static void run() {
    char in[WORD_LENGTH];
    char out[WORD_LENGTH];

    char t_phone[MAX_PHONE_SIZE];
    char t_word[MAX_WORD_SIZE][WORD_LENGTH];

    scanf("%d %d %d %d", &M, &N, &totalquery, &seed);

    makephone();

    for (int idx = 0; idx < M; ++idx)
        t_phone[idx] = phone[idx];

    learnphone(M, t_phone);

    makeword();

    for (int idx1 = 0; idx1 < N; ++idx1)
        for (int idx2 = 0; idx2 < WORD_LENGTH; ++idx2)
            t_word[idx1][idx2] = word[idx1][idx2];

    learnword(N, t_word);

    correctword = 0;
    for (int cnt = 0; cnt < totalquery; ++cnt) {
        int selected = pseudo_rand() % N;

        for (int idx1 = 0; idx1 < WORD_LENGTH; ++idx1) {
            in[idx1] = word[selected][idx1];
            int addnoise = pseudo_rand() % 2;
            if (addnoise)
                in[idx1] ^= 1 << (pseudo_rand() % 8);	//add noise
        }

        recognize(in, out);

        if (issame(word[selected], out))
            ++correctword;
    }
}

int main() {

    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    int score, curScore;

    score = 0;
    for (int test_case = 1; test_case <= T; test_case++) {

        run();

        curScore = correctword * 100 / totalquery;
        printf("#%d %d\n", test_case, curScore);
        score += curScore;

    }

    printf("Total Score = %d\n", score / T);
    return 0;
}
