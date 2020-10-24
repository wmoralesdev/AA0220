#include <vector>
#include <iostream>
using namespace std;

template<class T>
void swap(T* a, T* b);

template<class T>
int partition(vector<T>* vct, int low, int high);

template<class T>
void quickSort(vector<T>* vct, int low, int high);

int main(void) {
    vector<int> vct = { 7,5,8,9,10,31,69,100,420,666 };

    quickSort(&vct, 0, vct.size() - 1);

    for(int i : vct)
        cout << i << "\t";

    cout << endl;
    return 0;
}

template<class T>
void swap(T* a, T* b) {
    T temp = a;
    *a = *b;
    *b = temp;
}

template<class T>
void quickSort(vector<T>* vct, int low, int high) {
    if(low < high) {
        int pivot = partition(vct, low, high);

        quickSort(vct, low, pivot - 1);
        quickSort(vct, pivot + 1, high);
    }
}

template<class T>
int partition(vector<T>* vct, int low, int high) {
    T pivot = vct->at(high);
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(vct->at(j) <= pivot) {
            i++;
            swap(vct->at(i), vct->at(j));
        }
    }

    // swap arr[i + 1] , arr[high]

    // i++
    // swap arr[i] , arr[high]
    // i = i + 1

    // i++
    // i = i + 1
    // swap arr[i] , arr[high]

    swap(vct->at(++i), vct->at(high));
    return i;
}