#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_len 30
#define len 15

typedef struct Record
{
	char name[max_len];
	char number[len];
}Record;

typedef struct Node
{
	Record value;
	struct Node* next;
	struct Node* prev;
}Node;

Node* insert_after(Node* ptr_elem, Record a);
Node* find(Node* list, char* familya, int* pIsFind);

void print(Node* list);
void FIND(Node* list, char* familya);
void unshift(Node** plist, Record a);
void INSERT(Node** plist, char* familya, char* nomer);

int main()
{
	int k;
	char familya[max_len];
	char nomer[len];
	Node* p = (Node*)malloc(sizeof(Node));
	Node** plist = &p;
	*plist = NULL;
	while (1)
	{
		printf("\n         Vibirite punct menu:\n\n");
		printf("1) Insert person \n");
		printf("2) Find person \n");
		printf("3) Print all notebook \n");
		printf("4) Exit \n");
		printf("\n");
		scanf("%d", &k);
		printf("\n");
		switch (k)
		{
		case 1:
			printf("Enter name and phone number \n");
			scanf("%s %s", familya, nomer);
			INSERT(plist, familya, nomer);
			break;

		case 2:
			printf("Enter name of person \n");
			scanf("%s", familya);
			FIND(*plist, familya);
			break;
		case 3:
			print(*plist);
			break;

		case 4:
			return 0;
		default:
			printf("wrong number \n");
			break;
		}
	}

	return 0;
}

Node* insert_after(Node* ptr_elem, Record a)
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

Node* find(Node* list, char* familya, int* pIsFind)
{
	*pIsFind = 0;
	Node* pt = list, *qt = NULL;
	while (pt != NULL)
	{
		if (strcmp(pt->value.name, familya) < 0)
		{
			qt = pt;
			pt = pt->next;
		}
		else
			if (strcmp(pt->value.name, familya) == 0)
			{
				*pIsFind = 1;
				return pt;
			}
			else
				return qt;
	}
	return qt;
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
			printf("%s\t%s  \n", ptr->value.name, ptr->value.number);
			ptr = ptr->next;
		}
		else
		{
			printf("%s\t%s \n ", ptr->value.name, ptr->value.number);
			break;
		}
	}

}

void FIND(Node* list, char* familya)
{
	int* pIsFind = (int*)malloc(sizeof(int));
	Node* q = find(list, familya, pIsFind);
	if (*pIsFind == 1)
		printf("FIND %s it's phone %s\n", familya, q->value.number);
	else
		printf("NO\n\n", familya);
}

void unshift(Node** plist, Record a)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = *plist;
	p->prev = NULL;
	if (*plist != NULL)
		(*plist)->prev = p;
	p->value = a;
	*plist = p;
}

void INSERT(Node** plist, char* familya, char* nomer)
{
	int* pIsFind = (int*)malloc(sizeof(int));
	Node* q = find(*plist, familya, pIsFind);
	if (*pIsFind == 1)
	{
		printf("Changed. Old value = %s\n", q->value.number);
		strcpy(q->value.number, nomer);
	}
	else
	{
		Record a;
		strcpy(a.name, familya);
		strcpy(a.number, nomer);
		if (q == NULL)
			unshift(plist, a);
		else
			insert_after(q, a);
	}
}
