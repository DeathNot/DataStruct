#include <iostream>

using namespace std;

void quick_sort(int num[], int begin, int end);
int partition(int num[], int begin, int end);
void swap(int *a, int *b);

int main() {
	int sizeofnum;
	cin >> sizeofnum;
	int *num = new int[sizeofnum];
	for (int i = 0; i < sizeofnum; i++)
		cin >> num[i];
	quick_sort(num, 0, sizeofnum-1);
	for (int i = 0; i < sizeofnum; i++)
		cout << num[i] << ' ';
	delete [] num;
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int num[], int begin, int end) {
	int tag = num[end];
	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (num[j] <= tag) {
			i = i + 1;
			swap(&num[i], &num[j]);
		}
	}
	swap(&num[i+1], &num[end]);
	return i+1;
}

void quick_sort(int num[], int begin, int end) {
	if (begin < end) {
		int q = partition(num, begin, end);
		quick_sort(num, begin, q-1);
		quick_sort(num, q + 1, end);
	}
}