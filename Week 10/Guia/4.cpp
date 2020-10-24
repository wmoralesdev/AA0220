#include "../tree.h"

void mergeSort(int* array, int low, int high);
node* arrayToBST(int* array, int start, int end);
void merge(int* array, int low, int mid, int high);

int main(void) {
    int array[] = { 69, 19, 20, 7, 40, 19, 4, 18, 14, 666, 420 };
    int arrSize = sizeof(array) / sizeof(array[0]);
    
    mergeSort(array, 0, arrSize - 1);
    node* tree = arrayToBST(array, 0, arrSize - 1);

    inOrder(tree);
    cout << endl;
    preOrder(tree);
    return 0;
}

void mergeSort(int* array, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        merge(array, low, mid, high);
    }
}

void merge(int* array, int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int* left = new int[leftSize],* right = new int[rightSize];

    for(int i = 0; i < leftSize; i++)
        left[i] = array[low + i];

    for(int i = 0; i < rightSize; i++)
        right[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while(i < leftSize && j < rightSize) {
        if(left[i] <= right[j]) {
            array[k] = left[i++];
        }
        else {
            array[k] = right[j++];
        }
        k++;
    }

    while(i < leftSize) {
        array[k++] = left[i++];
    }

    while(j < rightSize) {
        array[k++] = right[j++];
    }
}

node* arrayToBST(int* array, int start, int end) {
    if(start > end)
        return NULL;

    int mid = (start + end) / 2;

    node* root = new node(array[mid]);

    root->left = arrayToBST(array, start, mid - 1);
    root->right = arrayToBST(array, mid + 1, end);

    return root;
}