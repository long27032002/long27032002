#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

static struct {
	int top;
	int bot;
	unsigned int max_size;
	int count_t;
	int* ptr_que;
} item_t;

void queue_init(static unsigned int);
bool is_full();
bool is_empty();
void queue_load();
bool queue_push(static int);
void delete_top();
void delete_bot();