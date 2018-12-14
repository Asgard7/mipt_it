/*
	Программа сделана на основе двусвязного спискаж
	Примечания:
		Файл должен называться input.txt и располагаться в корневой директории.
		Стенки в файле обозначаются '#', а пустая клетка '.';
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Coord {
	int x;
	int y;
}Coord;

typedef struct Node {
	Coord value;
	struct Node* next;
	struct Node* prev;
}Node;

Node* insert_after(Node* ptr_elem, Coord a); //Добавить новый элемент после данного
Node* tail(Node* list); //Возвращает указатель на конец списка

void print(Node* list); //Печатает список(для отладки)
void unshift(Node** plist, Coord a); //Добавляет новый элемент в начало списка
void dynamic_array_free(int **A, int N);

int push(Node** plist, Coord a); //Добавляет новый элемент в конец списка
int ** dynamic_array_alloc(int N, int M);

Coord shift(Node** plist); //Извлекает первый элемент списка

int main()
{
	int M, N;
	FILE *f;
	f = fopen("input.txt", "r");
	if (!f)
	{
		printf("error openning of file\n");
		return 1;
	}
	fscanf(f, "%d %d", &M, &N);
	char ch;

	int **z = dynamic_array_alloc(N, M);
	int **c = dynamic_array_alloc(N, M);
	Coord **p = (Coord **)malloc(M * sizeof(Coord *));
	for (int i = 0; i < M; i++)
	{
		p[i] = (Coord *)malloc(N * sizeof(Coord));
	}
	for (int l = 0; l < M; l++)
	{
		for (int k = 0; k < N; k += 0)
		{
			fscanf(f, "%c", &ch);
			if (ch == '#')
			{
				z[l][k] = 1;
				c[l][k] = 0;
				k++;
			}
			else if (ch == '.')
			{
				z[l][k] = 0;
				c[l][k] = 0;
				k++;
			}
			
		}
		fscanf(f, "%c", &ch);
	}
	fclose(f);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", z[i][j]);
		printf("\n");
	}
	Node* Q = NULL; //Создаем пустую очередь
	if (z[0][0] == 1 || z[M - 1][N - 1] == 1)
	{
		printf("NO\n");
		return 0;
	}
	c[0][0] = 1;
	Coord a = { 0,0 };
	Coord t;
	push(&Q, a); //Добавляем в очередь координаты вершины
	p[0][0].x = -1;
	p[0][0].y = -1;
	int i = 0, j = 0;
	while (Q != NULL)
	{
		t = shift(&Q); //Извлекаем из очереди первый элемент
		if ((t.x == M - 1) && (t.y == N - 1))
			break;
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
	Q = NULL;
	if ((t.x == M - 1) && (t.y == N - 1))
	{
		a = t;
		do
		{
			unshift(&Q, a);
			t = p[a.x][a.y];
			a = t;
		} while (a.x != -1);
		print(Q);
	}
	else
		printf("NO\n");
	dynamic_array_free(z, M);
	dynamic_array_free(c, M);
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
			return;
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

Coord shift(Node** plist)
{
	Coord t = { -1, -1 };
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