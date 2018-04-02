#include <iostream>
#include <climits>
using namespace std;

void merge(int num[], int begin, int mid, int end);
void merge_sort(int num[], int begin, int end);

int main() {
	int sizeofnum;
	cin >> sizeofnum;
	int *num =new int[sizeofnum];
	for (int i = 0; i < sizeofnum; i++) 
		cin >> num[i];
	merge_sort(num, 0, sizeofnum - 1);
	for(int i = 0; i < sizeofnum; i++)
		cout << num[i] << ' ';
	delete [] num;
	return 0;
}

void merge(int num[], int begin, int mid, int end) {
	int n1 = mid - begin + 1;
	int n2 = end - mid;
	int *left = new int[n1 + 1];
	int *right = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
		left[i] = num[begin + i];
	for (int j = 0; j < n2; j++)
		right[j] = num[mid + j + 1];
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	int i = 0, j = 0;
	for (int k = begin; k <= end; k++) {
		if (left[i] < right[j]) {
			num[k] = left[i];
			i++;
		} else {
			num[k] = right[j];
			j++;
		}
	}
	delete [] left;
	delete [] right;
}

void merge_sort(int num[], int begin, int end) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		merge_sort(num, begin, mid);
		merge_sort(num, mid + 1, end);
		merge(num, begin, mid, end);
	}
}