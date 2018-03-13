#define MAX_PHONE_SIZE 32
#define MAX_WORD_SIZE 20000

#define WORD_LENGTH 6

#define HASHSIZE 40000

static char phone_store[MAX_PHONE_SIZE];
static char phone_poss[WORD_LENGTH][MAX_PHONE_SIZE];
static int phone_poss_num[WORD_LENGTH];
static bool is_used[HASHSIZE];
static int num[HASHSIZE];
static char word_store[HASHSIZE][WORD_LENGTH];
static int phone_num;
static int word_num;


bool compare(char s[], char t[]) {

    for (int i = 0; i < WORD_LENGTH; ++i)
        if (s[i] != t[i])
            return false;

    return true;
}

void copy(char s[], char t[]) {

    for (int i = 0; i < WORD_LENGTH; ++i)
        s[i] = t[i];
}

int distance(char s, char t) {

    int p = 0;
    unsigned char diff = s ^ t;

    while (diff) {

        diff = diff & (diff - 1);
        ++p;
    }

    return p;
}

int hash_produce(char word[]) {

    int s = 0;

    for (int i = 0; i < WORD_LENGTH; i++)
        s = s * 31 + word[i];
    s = (s & 0x7fff) % 39989;

    while (is_used[s] && !compare(word, word_store[s])) {

        s = (++s) % 40000;
    }

    if (!is_used[s]) {
        copy(word_store[s], word);
        is_used[s] = true;
    }
    num[s]++;

    return s;
}

int hash_search(char word[]) {

    int s = 0;

    for (int i = 0; i < WORD_LENGTH; i++)
        s = s * 31 + word[i];
    s = (s & 0x7fff) % 39989;

    while (is_used[s] && !compare(word, word_store[s])) {

        s = (++s) % 40000;
    }

    if (is_used[s])
        return s;
    else
        return -1;
}


void learnphone(int M, char phone[MAX_PHONE_SIZE]) {

    phone_num = M;
    for (int i = 0; i < phone_num; i++)
        phone_store[i] = phone[i];

}

void learnword(int N, char word[MAX_WORD_SIZE][WORD_LENGTH]) {

    word_num = N;
    for (int i = 0; i < 40000; ++i) {

        is_used[i] = false;
        num[i] = 0;
    }


    for (int i = 0; i < word_num; ++i) {

        hash_produce(word[i]);
    }


}

void recognize(char in[WORD_LENGTH], char out[WORD_LENGTH]) {

    int s, max;
    char temp[WORD_LENGTH];

    for (int i = 0; i < WORD_LENGTH; ++i) {

        phone_poss_num[i] = 0;

        for (int j = 0; j < phone_num; j++)
            if (distance(phone_store[j], in[i]) <= 1) {
                phone_poss[i][phone_poss_num[i]] = phone_store[j];
                phone_poss_num[i]++;
            }
    }

    max = 0;
    for (int i = 0; i < phone_poss_num[0]; i++) {
        temp[0] = phone_poss[0][i];
        for (int j = 0; j < phone_poss_num[1]; j++) {
            temp[1] = phone_poss[1][j];
            for (int k = 0; k < phone_poss_num[2]; k++) {
                temp[2] = phone_poss[2][k];
                for (int p = 0; p < phone_poss_num[3]; p++) {
                    temp[3] = phone_poss[3][p];
                    for (int q = 0; q < phone_poss_num[4]; q++) {
                        temp[4] = phone_poss[4][q];
                        for (int l = 0; l < phone_poss_num[5]; l++)
                        {
                            temp[5] = phone_poss[5][l];

                            s = hash_search(temp);
                            if (s == -1)
                                continue;
                            if (num[s] > max) {
                                max = num[s];
                                copy(out, temp);
                            }
                        }
                    }
                }
            }
        }
    }
}

