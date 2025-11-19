#include "Queue.h"

enum {
	fail,
	success,
};

void queue_init(static unsigned int count) {
	item_t.ptr_que = (int*)calloc(count, sizeof(int));
	item_t.count_t = 0;
	item_t.bot = item_t.top = 0;
};

bool is_full() {
	return (item_t.count_t < item_t.max_size) ? false : true;
};

bool is_empty() {
	return (item_t.count_t == 0) ? true : false;
};

bool queue_push(static int tmp) {
	if (!is_full())
	{
		item_t.ptr_que[++item_t.count_t] = tmp;
		return success;
	}
	else
	{
		return fail;
	}
};

void queue_load() {
		int data;
		char c;
		while (true)
		{
			if (_kbhit())
			{
				printf("Enter value: ");
				scanf_s("%d", &data);
				if (!queue_push(data))
				{
					printf("Queue is full!!!");
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
		printf("Complete load queue...\n");
};


void delete_top() {
	
};

void delete_bot() {
	
};