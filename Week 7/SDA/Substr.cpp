#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct info {
    string p;

    info() {}
    info(string _p) : p(_p) {}

    bool operator<=(const info& right) {
        if(this->p.length() < right.p.length())
            return true;
        else if(this->p.length() == right.p.length()) {
            return p.compare(right.p) < 0;
        }
        else
            return false;
    }
};

template<class T>
void swap(T* a, T* b);

template<class T>
int partition(vector<T>* vct, int low, int high);

template<class T>
void quickSort(vector<T>* vct, int low, int high);

int main(void) {
    vector<info> vct = {
        info("frgh"),
        info("ab"),
        info("abc"),
        info("a"),
        info("abcab"),
    };

    quickSort(&vct, 0, vct.size() - 1);

    string s = "", ss = "";

    for(int i = 1; i < vct.size(); i++) {
        if(vct.at(i).p.find(vct.at(i - 1).p) == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
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

    swap(vct->at(++i), vct->at(high));
    return i;
}