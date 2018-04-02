#include <iostream>

using namespace std;
void insertion_sort(int num[], int sizeofnum);

int main() {
    int sizeofnum;
    cin >> sizeofnum;

    int *num = new int[sizeofnum];
    for(int i = 0; i < sizeofnum; i++)
        cin >> num[i];
    insertion_sort(num, sizeofnum);
    for (int i = 0; i < sizeofnum; i++)
        cout << num[i] << ' ';
	delete [] num;
    return 0;
}

void insertion_sort(int num[], int sizeofnum) {
    for (int i = 1; i < sizeofnum; i++) {
        int key = num[i];
        int j = i - 1;
        while (j >= 0 && num[j] > key) {
            num[j+1] = num[j];
            j--;
        };
        num[j+1] = key;
    }
}

