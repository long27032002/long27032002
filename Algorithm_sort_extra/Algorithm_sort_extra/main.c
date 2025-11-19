#include "Algorithm_sort_library.h"
#include "Queue.h"
#include "Stack.h"
#include "linked_list.h"
#include "tree.h"

int arr_int[] = { 27, 12, 2, 7, -3, 5, -7, -19, 15, 9, -8, 33, -16, 12, 7, 22, 0, -11, 44, 23 };


int main() {
	int selection;
	printf("---------- Data Structures and Algorithm ----------\n");
	printf("1. Sort.\n");
	printf("2. Stack.\n");
	printf("3. Queue.\n");
	printf("Enter selection: ");
	scanf_s("%d", &selection);

	switch (selection) {
	case 1: {
		printf("Default Array: \n");
		print_arr(arr_int);

		print_arr(Interchange_sort(arr_int));
		print_arr(Selection_sort(arr_int));
		print_arr(Bubble_sort(arr_int));
		print_arr(Insertion_sort(arr_int));
		print_arr(Shell_sort(arr_int));
		print_arr(Quick_sort(arr_int));

		printf("Merge Sort:\n");
		Merge_sort(arr_int, 0, length - 1);
		print_arr(arr_int);
		break;
	}

	case 2: {
		int maxsize;
		printf("Enter max size of stack: ");
		scanf_s("%d", &maxsize);
		stack_init(maxsize);
		load_stack();
		stack_push(16);
		print_stack();
		stack_delete();
		break;
	}
	case 3: {

		break;
	}
	}
}