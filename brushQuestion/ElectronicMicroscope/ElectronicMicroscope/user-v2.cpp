#include "stdafx.h"

enum { 
	MAX_N = 100,
	CHILD_N = 4
};

static int myCell[MAX_N][MAX_N];

//////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////
void buildTree(int cell[MAX_N][MAX_N], Node *parent)
{
	if(parent->s == 1){
		parent->infected = cell[parent->x][parent->y];
		return;
	}

	int s = parent->s;
	int x = parent->x;
	int y = parent->y; 

	int sub = s / 2;
	Node *node;
	int index = 0;

	node = newNode(x, y, sub);
	parent->child[index++] = node;
	buildTree(cell, node);

	if(x+sub < Num)
	{
		node = newNode(x+sub, y, sub);
		parent->child[index++] = node;
		buildTree(cell, node);
	}

	if(y+sub < Num)
	{
		node = newNode(x, y+sub, sub);
		parent->child[index++] = node;
		buildTree(cell, node);
	}

	if(x+sub < Num && y+sub < Num)
	{
		node = newNode(x+sub, y+sub, sub);
		parent->child[index++] = node;
		buildTree(cell, node);
	}
}

////////////////////////////////////////////////////////////////
void updateTree(Node *parent)
{
	initQue();
	enQue(parent);
	Node *node;
	while(!isEmptyQue())
	{
		node = deQue();
		for(int i=0; i<CHILD_N; i++)
		{
			if(!node->child[i] || node->s == 1) continue;
			enQue(node->child[i]);
		}
	}

	for(int i=tail-1; i>=0; i--)
	{
		for(int j=0; j<CHILD_N; j++)
		{
			if(!que[i]->child[j]) continue;
			que[i]->infected += que[i]->child[j]->infected;
		}
	}

}
////////////////////////////////////////////////////////////////
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
				if(!node->child[i]) continue;
				enQue(node->child[i]);
			}
		}
	}
}
///////////////////////////////////////////////////////////////
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
	updateTree(root);

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