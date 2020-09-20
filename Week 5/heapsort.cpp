#include <vector>
#include <iostream>
using namespace std;

// Information data
struct person {
    string name, lastName;

    person() {}
    person(string _name, string _lastName) : name(_name), lastName(_lastName) {}

    bool operator<(const person& r) {
        return this->lastName.compare(r.lastName) == -1 ? true : false;
    }

    bool operator>(const person& r) {
        return this->lastName.compare(r.lastName) == 1 ? true : false;
    }

    // ostream operator overloading
    friend ostream& operator<<(ostream& os, const person& p) {
        os << (p.name + ", " + p.lastName);
        return os;
    }
};
typedef person P;

template <class T>
void swap(T* a, T* b);

template <class T>
void heapSort(vector<T>* vct, int n);

template <class T>
void heapify(vector<T>* vct, int n, int i);

int main(void) {
    // Vector with elements to be sorted
    vector<person> vct = { 
        P("Edith", "Lopez"),
        P("Xiomara", "Xiomara"),
        P("Jose", "Anaya"),
        P("Andrea", "Benitez"),
        P("Susana", "Distancia"),
        P("Aquiles", "Montolla"),
        P("Armando", "Paredes"),
        P("Miles", "Morales"),
        P("Aquiles", "Castro")
    };

    heapSort(&vct, vct.size());

    for(person i : vct) {
        cout << i << endl;
    }

    return 0;
}

template <class T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
void heapify(vector<T>* vct, int n, int i) {
    // First we assume that largest element is at root pos
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If either left or right is larger than largest, switch largest with LR pos
    if(left < n && vct->at(left) > vct->at(largest))
        largest = left;

    if(right < n && vct->at(right) > vct->at(largest))
        largest = right;

    // If largest is not root, swap root with largest and recurse
    if(largest != i) {
        swap(vct->at(i), vct->at(largest));
        heapify(vct, n, largest);
    }
}

template <class T>
void heapSort(vector<T>* vct, int n) {
    // First a maxheap must be made in order to sort elements
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(vct, n, i);

    for(int i = n - 1; i > 0; i--) {
        // root position must be swapped with last - 1 pos
        swap(vct->at(0), vct->at(i));

        // After swapping maxheap must be remade
        heapify(vct, i, 0);
    }
}