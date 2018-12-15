#include<stdio.h>
#include<stdlib.h>

typedef struct Coord
{
	int x;
	int y;
}Coord;

typedef struct Node
{
	Coord value;
	struct Node* next;
	struct Node* prev;
}Node;

Node* insert_after(Node* ptr_elem, Coord a);
Node* tail(Node* list);

void print(Node* list);
void unshift(Node** plist, Coord a);
void dynamic_array_free(int **A, int N);

Coord shift(Node** plist);

int push(Node** plist, Coord a);
int path(int flag, Coord A, Coord* pB, int** z, int** s, int** c, Coord** p, int M, int N);
int ** dynamic_array_alloc(int N, int M);

int main()
{
	int M, N;
	int i, j;
	FILE *f;
	f = fopen("input.txt", "r");
	if (!f)
	{
		printf("error openning of file\n");
		return 1;
	}
	fscanf(f, "%d%d", &M, &N);
	printf("M=%d ,N=%d \n", M, N);
	char ch;
	int** z, **c, **s;
	z = dynamic_array_alloc(N, M);
	c = dynamic_array_alloc(N, M);
	s = dynamic_array_alloc(N, M);
	Coord** p = (Coord**)malloc(M * sizeof(Coord*));
	for (i = 0; i < M; i++)
		p[i] = (Coord*)malloc(N * sizeof(Coord));

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N;)
		{
			fscanf(f, "%c", &ch);
			switch (ch)
			{
			case '#':
			{
				z[i][j] = 1;
				s[i][j] = 0;
				j++;
			}
			break;
			case'.':
			{
				z[i][j] = 0;
				s[i][j] = 0;
				j++;
			}
			break;
			case '*':
			{
				z[i][j] = 0;
				s[i][j] = 1;
				j++;
			}
			break;
			}
		}

	}
	fclose(f);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			if (s[i][j] == 1)
				printf("* ");
			else
				printf("%d ", z[i][j]);
		printf("\n");
	}

	if (z[0][0] == 1 || z[M - 1][N - 1] == 1)
	{
		printf("NO\n");
		return 0;
	}
	Coord A = { 0,0 };
	Coord* pB = (Coord*)malloc(sizeof(Coord));
	if (!path(0, A, pB, z, s, c, p, M, N))
	{
		printf("NO\n");
		return 0;
	}
	while (path(1, A, pB, z, s, c, p, M, N))
	{
		A = *pB;
	}
	path(0, A, pB, z, s, c, p, M, N);
	dynamic_array_free(c, M);
	dynamic_array_free(z, M);
	dynamic_array_free(s, M);
	for (int i = 0; i < N; i++) {
		free(p[i]);
	}
	free(p);
	return 0;
}

Node* insert_after(Node* ptr_elem, Coord a)
{

	Node* q = (Node*)malloc(sizeof(Node));
	q->value = a;
	if (ptr_elem == NULL)
	{
		q->next = NULL;
		q->prev = NULL;
		return q;
	}
	else
	{
		q->next = ptr_elem->next;
		q->prev = ptr_elem;
		if (ptr_elem->next != NULL)
			ptr_elem->next->prev = q;
		ptr_elem->next = q;
		return q;
	}
}

Node* tail(Node* list)
{
	if (list == NULL)
		return NULL;
	Node* ptr = list, *qtr;
	do
	{
		qtr = ptr;
		ptr = ptr->next;
	} while (ptr != NULL);
	return qtr;
}

void print(Node* list)
{
	Node* ptr = list;
	if (list == NULL)
		printf("list is empty.\n");
	while (ptr != NULL)
	{
		if (ptr->next != NULL)
		{
			printf("(%d,%d) -> ", ptr->value.x, ptr->value.y);
			ptr = ptr->next;
		}
		else
		{
			printf("(%d %d) ;\n", ptr->value.x, ptr->value.y);
			break;
		}
	}

}

void unshift(Node** plist, Coord a)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = *plist;
	p->prev = NULL;
	if (*plist != NULL)
		(*plist)->prev = p;
	p->value = a;
	*plist = p;
}

void dynamic_array_free(int **A, int N)
{
	for (int i = 0; i < N; i++) {
		free(A[i]);
	}
	free(A);
}

Coord shift(Node** plist)
{
	Coord t = { -1,-1 };
	if ((*plist) == NULL)
		return t;
	Node* p = *plist;
	t = p->value;
	*plist = p->next;
	if (*plist != NULL)
		(*plist)->prev = NULL;
	free(p);

	return t;
}

int ** dynamic_array_alloc(int N, int M)
{
	int **A = (int **)malloc(M * sizeof(int *));
	for (int i = 0; i < M; i++) {
		A[i] = (int *)malloc(N * sizeof(int));
	}
	return A;
}

int push(Node** plist, Coord a)
{
	Node* t = tail(*plist);
	Node* q = insert_after(t, a);
	if (t == NULL)
	{
		*plist = q;
		return 0;
	}
	else
		return 1;
}

//����  flag=0 ���� ������� �� ����� A �� ������ �� ���������. ���������� 1, ���� ����� ����, ����� 0.
//���� flag =1 ���� ���������� ������� �� ����� A �� ������ �� ����������. ���� �������� ����, ���������� 
//�������� 1, ���� ���, ���������� 0. ���������� ��������� ������ �� ���������� ��� *pB  .
int path(int flag, Coord A, Coord* pB, int** z, int** s, int** c, Coord** p, int M, int N)
{

	int i, j, i0, j0;
	//������� ����� ����
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			c[i][j] = 0;
	i0 = A.x;
	j0 = A.y;
	Node* Q = NULL;
	c[i0][j0] = 1;
	Coord a = { i0,j0 };
	Coord t;
	push(&Q, a);
	p[i0][j0].x = -1;//������� ���
	p[i0][j0].y = -1;
	while (Q != NULL)
	{
		t = shift(&Q);
		if (flag)
		{
			if (s[t.x][t.y] == 1)
			{
				s[t.x][t.y] = 0;
				pB->x = t.x;
				pB->y = t.y;
				Q = NULL;
				a = t;
				do
				{
					unshift(&Q, a);
					t = p[a.x][a.y];
					a = t;
				} while (a.x != -1);
				print(Q);
				return 1;
			}
		}
		else
			if ((t.x == M - 1) && (t.y == N - 1))
				if (A.x == 0 && A.y == 0)
					return 1;
				else
				{
					Q = NULL;
					a = t;
					do
					{
						unshift(&Q, a);
						t = p[a.x][a.y];
						a = t;
					} while (a.x != -1);
					print(Q);
					return 1;
				}

		i = t.x;
		j = t.y;
		if (((i - 1) >= 0) && (z[i - 1][j] == 0) && (c[i - 1][j] == 0))
		{
			c[i - 1][j] = 1;
			p[i - 1][j].x = i;
			p[i - 1][j].y = j;
			t.x = i - 1;
			t.y = j;
			push(&Q, t);
		}
		if (((i + 1) < M) && (z[i + 1][j] == 0) && (c[i + 1][j] == 0))
		{
			c[i + 1][j] = 1;
			p[i + 1][j].x = i;
			p[i + 1][j].y = j;
			t.x = i + 1;
			t.y = j;
			push(&Q, t);
		}
		if (((j - 1) >= 0) && (z[i][j - 1] == 0) && (c[i][j - 1] == 0))
		{
			c[i][j - 1] = 1;
			p[i][j - 1].x = i;
			p[i][j - 1].y = j;
			t.x = i;
			t.y = j - 1;
			push(&Q, t);
		}
		if (((j + 1) < N) && (z[i][j + 1] == 0) && (c[i][j + 1] == 0))
		{
			c[i][j + 1] = 1;
			p[i][j + 1].x = i;
			p[i][j + 1].y = j;
			t.x = i;
			t.y = j + 1;
			push(&Q, t);
		}

	}
	return 0;
}