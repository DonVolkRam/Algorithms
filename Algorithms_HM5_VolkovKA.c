#include <stdio.h>
#include <malloc.h>
#define T char
// Опишем структуру узла списка

struct TNode
{
	T value;
	struct TNode * next;
};
typedef struct TNode Node;

struct Stack
{
	Node * head;
	int size;
	int maxSize;
};
struct Stack Stack;

void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("Error stack size");
		return;
	}
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}

T pop()
{
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// Временный указатель
	Node * next = NULL;
	// Значение "наверху" списка
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
	Stack.size--;
	return value;
}

void PrintStack()
{
	Node * current = Stack.head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

int main(int argc, char * argv[])
{
	Stack.maxSize = 100;
	Stack.head = NULL;
	int a=0;
	printf("Input decimal number and I convert it to binary number\n");
	scanf("%d", &a);
	int temp;
	while(a>0)
	  {
	    temp=a%2;
	    push(temp);
	    a=a/2;
	  }

	PrintStack();

	printf("\n========================================================\n");
	char c[1000];
	int i=0;
	char b;
	int countR=0, countS=0, countF=0;
	printf("Continue...\n");
	scanf("%c",&b);
	puts("Input equation ");
	fgets(c,1000,stdin);

	while(c[i])
	{
	    if(c[i]=='(')
	      countR++;
	    else if(c[i]==')')
	      countR--;
	    else if(c[i]=='{')
	      countF++;
	    else if(c[i]=='}')
	      countF--;
	    else if(c[i]=='[')
	      countS++;
	    else if(c[i]==']')
	      countS--;
	  i++;
	}
	if(!countF && !countR && !countS )
	  puts("All Correct");
	else
	  puts("incorrect scobe number");

	return 0;
}
