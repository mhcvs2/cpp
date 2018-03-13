#include "stdafx.h"

enum { 
	MAX_N = 100,
	CHILD_N = 4
};

static int myCell[MAX_N][MAX_N];

typedef struct Node{
	int infected;
	int x;
	int y;
	int s;
	Node *child[CHILD_N];
}Node;

Node memS[MAX_N * MAX_N * 4];
 int memId;
 int Num;

Node *newNode(int x, int y, int s)
{
	Node *node = &memS[memId++];
	node->x = x;
	node->y = y;
	node->s = s;
	node->infected = 0;
	for(int i=0; i<CHILD_N; i++)
	{
		node->child[i] = 0;
	}
	return node;
}

typedef struct
{
	int x;
	int y;
} Cell;

typedef struct
{
	int count;
	Cell cell[MAX_N];
} RESULT;

extern int observe(int top, int left, int size);

Node *que[MAX_N * MAX_N * 4];
int head;
int tail;

void initQue()
{
	head = tail = 0;
}

void enQue(Node *node)
{
	que[tail++] = node;
}

Node *deQue()
{
	return que[head++];
}

bool isEmptyQue()
{
	return head == tail;
}

void buildTree(int cell[MAX_N][MAX_N], Node *parent)
{
	initQue();
	enQue(parent);
	Node *node;
	Node *p;
	int sub;

	while(!isEmptyQue())
	{
		p = deQue();
		if(p->s != 1)
		{
			sub = p->s /2;
			int index = 0;

			node = newNode(p->x, p->y, sub);
			p->child[index++] = node;
			enQue(node);

			if(p->x+sub < Num)
			{
				node = newNode(p->x+sub, p->y, sub);
				p->child[index++] = node;
				enQue(node);
			}

			if(p->y+sub < Num)
			{
				node = newNode(p->x, p->y+sub, sub);
				p->child[index++] = node;
				enQue(node);
			}

			if(p->x+sub < Num && p->y+sub < Num)
			{
				node = newNode(p->x+sub, p->y+sub, sub);
				p->child[index++] = node;
				enQue(node);
			}
					
		}
		else
		{
			p->infected = cell[p->x][p->y];
		}


	}

	for(int i=tail-1; i>=0; i--)
	{
		for(int j=0; j<CHILD_N; j++)
		{
			if(!que[i]->child[j]) break;
			que[i]->infected += que[i]->child[j]->infected;
		}
	}

}

void getResult(RESULT *r)
{
	Node *root = &memS[0];
	initQue();
	enQue(root);

	Node *node;
	int newInfected;
	while(!isEmptyQue())
	{
		node = deQue();
		newInfected = observe(node->x, node->y, node->s);
		if(newInfected == node->infected) continue;
		else if(node->s == 1)
		{
			r->cell[r->count].x = node->y;
			r->cell[r->count].y = node->x;
			r->count++;
			myCell[node->x][node->y] = newInfected;
			node->infected = newInfected;
		}
		else
		{
			node->infected = newInfected;

			for(int i=0; i<CHILD_N; i++)
			{
				if(!node->child[i]) break;
				enQue(node->child[i]);
			}
		}
	}
}

void init(int cell[MAX_N][MAX_N], int N)
{
	memId = 0;
	Num = N;

	int i, j;
	for(i=0; i<Num; i++)
	{
		for(j=0; j<Num; j++)
		{
			myCell[i][j] = cell[i][j];
		}
	}

	int tmp = 1;

	while(tmp < N)
	{
		tmp *= 2;
	}
	Node *root = newNode(0, 0, tmp);
	buildTree(myCell, root);
}

RESULT infect()
{
	RESULT result;
	result.count = 0;
	getResult(&result);
	return result;
}

RESULT recover()
{
	RESULT result;
	result.count = 0;
	getResult(&result);
	return result;
}