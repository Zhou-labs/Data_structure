#include<iostream>
using namespace std;

const int MAXSIZE = 100;
typedef int ElemType;
typedef int status;

//--------线性表的静态链表存储结构------------
typedef struct {
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

//将整个数组空间初始化为一个链表
void InitSpace(SLinkList& space)
{
	for (int i = 0; i < MAXSIZE-1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
}

//从备用空间获得节点
int Malloc(SLinkList& space)
{
	int i = space[0].cur;
	if (i)
	{
		space[0].cur = space[i].cur;
		return i;
	}
	else 
	{
		exit(OVERFLOW);
	}
}

//回收备用节点
void Freeing(SLinkList& space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//(A-B)U(B-A)
void difference(SLinkList& space, int& s)
{
	InitSpace(space);
	s = Malloc(space);
	int r = s;
	int m;
	int n;
	cout << "intput the size of arry A and B" << endl;
	cin >> m >> n;
	for (int j = 1; j <= m; j++)
	{
		int i = Malloc(space);
		cout << "A de suoyi   " <<i<< endl;
		cin >> space[i].data;
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
	for (int j = 1; j <= n; j++)
	{
		int b;
		cin >> b;
		int p = s;
		int k = space[s].cur;
		while (k != space[r].cur && space[k].data != b)
		{
			p = k;
			k = space[k].cur;
		}
		if (k == space[r].cur)
		{
			int i = Malloc(space);
			cout << "B de suoyin " << i << endl;
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
			cout << space[r].cur << endl;
		}
		else
		{
			space[p].cur = space[k].cur;
			Freeing(space, k);
			if (r == k)r = p;
		}
	}
}


int main()
{
	SLinkList am;
	int s;
	difference(am, s);
	cout << "shoudizhi:"<<s<<endl;
	int m = am[s].cur;
	while (m)
	{
		cout << am[m].data << endl;
		m = am[m].cur;
	}

	return 0;
}