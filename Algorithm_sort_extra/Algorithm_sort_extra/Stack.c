#include "Stack.h"

enum {
	fail,
	success
};

void stack_init(int size_max) {
	item.ptr_stk = (int*)malloc(size_max * sizeof(int));
	item.max_size = size_max;
	item.top = -1;
}

bool is_Empty() {
	if (item.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
};

bool is_Full() {
	if (item.top + 1 == item.max_size)
	{
		return true;
	}
	else
	{
		return false;
	}
};

bool stack_push(int tmp) {
	if (!is_Full())
	{
		item.ptr_stk[++item.top] = tmp;
		return success;
	}
	else
	{
		return fail;
	}
};

int peek() {
	if (!is_Empty())
	{
		return *(item.ptr_stk + item.top);
	}
};


bool stack_pop() {
	if (!is_Empty())
	{
		item.top--;
		return success;
	}
	else
	{
		return fail;
	}
};

void load_stack() {
	char c;
	int data;
	while (true)
	{
		if (_kbhit())
		{
			printf("Enter value: ");
			scanf_s("%d", &data);
			if (!stack_push(data))
			{
				printf("Stack is full!!!");
				break;
			}

			fflush(stdin);
			printf("Press \"q\" to exit or Enter to continue...");
			c = getch();
			if (c == 'q')
			{
				break;
			}
		}
	}
	printf("Complete load stack...\n");
};

void print_stack() {
	int i;
	for ( i = 0; i <= item.top; i++)
	{
		printf("%4d", *(item.ptr_stk + i));
	}
	printf("\n");
};

void stack_delete() {
	free(item.ptr_stk);
	item.max_size = 0;
	item.top = -1;
}