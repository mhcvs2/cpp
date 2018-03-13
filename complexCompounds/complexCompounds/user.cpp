#include "stdafx.h"

#define COMPOUND_SIZE 5
#define MAX_COMPOUNDS 500
#define MAX_N 25003
#define STR_L 11


typedef struct LinkedNode {
	char first[11];
	char second[11];
	char third[11];
	char fourth[11];
	char fifth[11];
	LinkedNode *next;
}LNode;

void listFirst(LNode *p){
	if(p == NULL){
		printf("null\n");
	} else {
		while(p){
			printf("p1: %s\n", p->first);
			p = p->next;
		}
		printf("end--------------------\n");
	
	}
}

int memId = 0;
LNode *hashTable[COMPOUND_SIZE][1009];
LNode memStore[MAX_N];

int getHash(char *str){
	int hash = 5381;
	int c;
	while(c = (int)(*str++)){
		hash=(((hash<<5) + hash) + c) % 1009;
	}
	if(hash < 0){
		hash = -hash;
	}
	return hash % 1009;
}

extern int CalculateRelation(char *src, char *dst);
extern int MyStrCmp(char *src, char *dst);
extern void MyStrCpy(char *src, char *dst);

LNode *newNode(SInfo info){
	LNode *p;
	memId = memId % MAX_N;
	p = &memStore[memId++];
	MyStrCpy(info.first, p->first);
	MyStrCpy(info.second, p->second);
	MyStrCpy(info.third, p->third);
	MyStrCpy(info.fourth, p->fourth);
	MyStrCpy(info.fifth, p->fifth);
	p->next = NULL;
	return p;
}


//----------------------------------------------------------

void init(){
	memId = 0;
	for(int i=0; i<COMPOUND_SIZE; i++){
		for(int j=0; j<1009; j++) {
			LNode *p = hashTable[i][j];
			while(p){
				for(int k=0; k<STR_L; k++) {
					p->first[k] = '\0';
					p->second[k] = '\0';
					p->third[k] = '\0';
					p->fourth[k] = '\0';
					p->fifth[k] = '\0';
				}
				p = p->next;
			}
			hashTable[i][j] = NULL;
		}
	}

}

void AddDB(SInfo info){
	for(int i=0; i<COMPOUND_SIZE; i++){
		int hash;
		switch(i)
		{
		case 0:
			hash = getHash(info.first);
			break;
		case 1:
			hash = getHash(info.second);
			break;
		case 2:
			hash  = getHash(info.third);
			break;
		case 3:
			hash = getHash(info.fourth);
			break;
		case 4:
			hash = getHash(info.fifth);
			break;
		}
		LNode *p = newNode(info);
		p->next = hashTable[i][hash];
		hashTable[i][hash] = p;
	}
}

int SearchBestCase(SInfo info){
	int big = 0;
	int tmp = 0;
	bool check = true;

	for(int i=0; i<COMPOUND_SIZE; i++){
		int hash;
		switch(i)
		{
		case 0:
			hash = getHash(info.first);
			break;
		case 1:
			hash = getHash(info.second);
			break;
		case 2:
			hash  = getHash(info.third);
			break;
		case 3:
			hash = getHash(info.fourth);
			break;
		case 4:
			hash = getHash(info.fifth);
			break;
		}
		LNode *p = hashTable[i][hash];
		
		while(p){
			//printf("p1: %s\n", p->first);
					check = true;
					switch(i)
						{
						case 0:
							if(MyStrCmp(info.first, p->first) == 0) check = false;
							break;
						case 1:
							if(MyStrCmp(info.second, p->second) == 0) check = false;
							break;
						case 2:
							if(MyStrCmp(info.third, p->third) == 0) check = false;
							break;
						case 3:
							if(MyStrCmp(info.fourth, p->fourth) == 0) check = false;
							break;
						case 4:
							if(MyStrCmp(info.fifth, p->fifth) == 0) check = false;
							break;
						}
						tmp = 0;
						if(check){
							tmp += CalculateRelation(info.first, p->first);
							if(big > 400 + tmp){
								p = p->next;
								continue;
							}
							tmp += CalculateRelation(info.second, p->second);
							if(big > 300 + tmp){
								p = p->next;
								continue;
							}
							tmp += CalculateRelation(info.third, p->third);
							if(big > 200 + tmp){
								p = p->next;
								continue;
							}
							tmp += CalculateRelation(info.fourth, p->fourth);
							if(big > 100 + tmp){
								p = p->next;
								continue;
							}
							tmp += CalculateRelation(info.fifth, p->fifth);
							if (tmp > big) big = tmp;
							if(big == 500) return 500;
						}
				p = p->next;
		}
	}
	return big;
}
