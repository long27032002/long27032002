#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

static struct {
	int top;
	int max_size;
	int* ptr_stk;
} item;

void stack_init(int);
bool stack_push(int);
int peek();
bool is_Empty();
bool is_Full();
bool stack_pop();
void load_stack();
void print_stack();
void stack_delete();