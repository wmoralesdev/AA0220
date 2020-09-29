#include <vector>
#include <iostream>
using namespace std;

struct laptop {
    int p, q;

    laptop() {}
    laptop(int _p, int _q) : p(_p), q(_q) {}

    bool operator>(const laptop& r) {
        return this->p > r.p;
    }
};

void swap(laptop* lp1, laptop* lp2);
void heapSort(vector<laptop>* vct, int n);
void heapify(vector<laptop>* vct, int n, int i);

/*
    p   q
    1   2
    2   1
*/

int main(void) {
    vector<laptop> vct;
    int n = 0, aux1 = 0, aux2 = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> aux1 >> aux2;
        vct.push_back(laptop(aux1, aux2));
    }

    heapSort(&vct, vct.size());

    for(auto it = vct.begin(); it != vct.end() - 1; it++)
        if(it->q > (it + 1)->q) {
            cout << "Happy Alex" << endl;
            return 0;
        }

    cout << "Poor Alex" << endl;
    return 0;
}

void swap(laptop* lp1, laptop* lp2) {
    laptop temp = *lp1;
    *lp1 = *lp2;
    *lp2 = temp;
}

void heapify(vector<laptop>* vct, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && vct->at(left) > vct->at(largest))
        largest = left;

    if(right < n && vct->at(right) > vct->at(largest))
        largest = right;

    if(largest != i) {
        swap(vct->at(i), vct->at(largest));
        heapify(vct, n, largest);
    }
}

void heapSort(vector<laptop>* vct, int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(vct, n, i);

    for(int i = n - 1; i > 0; i--) {
        swap(vct->at(0), vct->at(i));
        heapify(vct, i, 0);
    }
}