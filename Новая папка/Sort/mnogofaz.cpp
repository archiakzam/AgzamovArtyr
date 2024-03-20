#include <iostream>
#include <ctime>

using namespace std;

const int Array__Size = 30;

void bubbleSort(int array[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void multiPhaseMergeSort(int array[], int n) {
    int phase_size = 1;
    while (phase_size < n) {
        for (int i = 0; i < n; i += 2 * phase_size) {
            int start = i;
            int mid = min(i + phase_size, n);
            int end = min(i + 2 * phase_size, n);
            int * temp = new int[end - start];
            
            int left = start, right = mid, index = 0;
            while (left < mid && right < end) {
                if (array[left] <= array[right]) {
                    temp[index++] = array[left++];
                } else {
                    temp[index++] = array[right++];
                }
            }
            while (left < mid) {
                temp[index++] = array[left++];
            }
            while (right < end) {
                temp[index++] = array[right++];
            }
            
            for (int k = 0; k < index; k++) {
                array[start + k] = temp[k];
            }
        }
        phase_size *= 2;
    }
}

int main() {
    srand(time(NULL));

    int array[Array__Size];

    cout << "\nStarting array:\n";
    for (int i = 0; i < Array__Size; i++) {
        array[i] = rand() % 101 - 50;
        cout << array[i] << " ";
    }
    multiPhaseMergeSort(array, Array__Size);

    cout << "\nEnding array:\n";
    for (int i = 0; i < Array__Size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}