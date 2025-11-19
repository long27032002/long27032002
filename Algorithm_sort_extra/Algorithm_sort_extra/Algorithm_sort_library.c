#include "Algorithm_sort_library.h"

void print_arr(int* arr_src) {
	for (int i = 0; i < length; i++)
	{
		printf("%5d", arr_src[i]);
	}
	printf("\n");
};

void swap_int(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
};

void swap_index(int a, int b, int* arr_tmp) {
	int tmp = arr_tmp[a];
	arr_tmp[a] = arr_tmp[b];
	arr_tmp[b] = tmp;
}

int* Interchange_sort(int* arr_src) {
	printf("Interchange Sort: \n");
	int arr_t[21];
	int tmp;
	for (size_t i = 0; i < length; i++)
	{
		arr_t[i] = arr_src[i];
	}
	
	// Algorithm Interchange Sort
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr_t[i] > arr_t[j])
			{
				swap_int(arr_t+i, arr_t+j);
				//swap_index(i, j, arr_t);
			}
		}
	}

	return arr_t;
};

int* Selection_sort(int* arr_src) {
	printf("Selection Sort: \n");
	int arr_t[21];
	for (size_t i = 0; i < length; i++)
	{
		arr_t[i] = arr_src[i];
	}

	// Algoritm Selection Sort
	for (size_t i = 0; i < length; i++)
	{
		int min = arr_t[i];
		int index_t = i;
		for (size_t j = i; j < length; j++)
		{
			if (min > arr_t[j])
			{
				min = arr_t[j];
				index_t = j;
			}
		}
		//swap_int(arr_t+i, arr_t+index_t);
		swap_index(i, index_t, arr_t);
	}

	return arr_t;
};

int* Bubble_sort(int* arr_src) {
	printf("Buddle Sort: \n");
	int arr_t[21];
	for (size_t i = 0; i < length; i++)
	{
		arr_t[i] = arr_src[i];
	}

	// Algorithm Buddle Sort
	for (int i = 0; i < length; i++)
	{
		for (int j = (length-1); j > i; j--)
		{
			if (arr_t[j] < arr_t[j - 1])
			{
				swap_index(j, j - 1, arr_t);
			}
		}
	}

	return arr_t;
};

int* Insertion_sort(int* arr_src) {
	printf("Insertion Sort: \n");
	int arr_t[21];
	for (size_t i = 0; i < length; i++)
	{
		arr_t[i] = arr_src[i];
	}

	//Algorithm Insertion Sort
	for (size_t i = 1; i < length; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (arr_t[i] < arr_t[j])
			{
				int tmp = arr_t[i];
				for (size_t k = i; k > j; k--)
				{
					arr_t[k] = arr_t[k - 1];
				}
				arr_t[j] = tmp;
				break;
			}
		}
	}

	return arr_t;
};

int* Shell_sort(int* arr_src) {
	printf("Shell Sort: \n");
	int arr_t[21];
	for (size_t i = 0; i < length; i++)
	{
		arr_t[i] = arr_src[i];
	}

	// Algorithm Shell Sort
	for (size_t i = 1; i < length; i++)
	{
		if (arr_t[i] < arr_t[i - 1])
		{
			for (size_t j = i; j > 0; j--)
			{
				if (arr_t[j] < arr_t[j - 1])
				{
					swap_index(j, j - 1, arr_t);
				}
				else
				{
					break;
				}
			}
		}
	}

	return arr_t;
};



int* Heap_sort(int* arr_src) {
	printf("Heap Sort: \n");
	
};

void Quick(int* arr_t, int left, int right) {
	if (left >= right) return;
	int pivot = arr_t[(left + right) / 2];
	int i = left;
	int j = right;

	do
	{
		while (arr_t[i] < pivot) i++;
		while (arr_t[j] > pivot) j--;
		if (i <= j) {
			swap_index(i, j, arr_t);
			i++;
			j--;
		}
	} while (i < j);

	Quick(arr_t, left, j);
	Quick(arr_t, i, right);
};

int* Quick_sort(int* arr_src) {
	printf("Quick Sort: \n");
	int arr_t[21];
	for (size_t i = 0; i < length; i++)
	{
		arr_t[i] = arr_src[i];
	}
	Quick(arr_t, 0, length - 1);
	return arr_t;
}

int arr_t[21];         
void merge(int*, int, int, int);
void Merge_sort(int* arr_src, int left, int right) {
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		Merge_sort(arr_src, left, mid);
		Merge_sort(arr_src, mid + 1, right);
		merge(arr_src, left, mid, right);
	}
	else
	{
		return;
	}
};

void merge(int* arr_src_t, int left, int mid, int right) {
	int i, j, k;

	for (i = left, j = mid + 1, k = left; (i <= mid) && (j <= right); k++)
	{
		if (arr_src_t[i] <= arr_src_t[j])
		{
			arr_t[k] = arr_src_t[i++];
		}
		else {
			arr_t[k] = arr_src_t[j++];
		}
	}

	while (i <= mid)
	{
		arr_t[k++] = arr_src_t[i++];
	}

	while (j <= right)
	{
		arr_t[k++] = arr_src_t[j++];
	}

	for (i = left; i <= right; i++) {
		arr_src_t[i] = arr_t[i];
	};
};