#include <vector>
#include <iostream>
using namespace std;

void getLast(vector<int> vct);
vector<int> mergeSort(vector<int> vct);
vector<int> merge(vector<int> left, vector<int> right);

int main(void) {
    vector<int> vct;
    int n = 0, aux = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        vct.push_back(aux);
    }

    getLast(vct);
    return 0;
}

// 9 

void getLast(vector<int> vct) {
    vct = mergeSort(vct);

    // Short way
    // 1 + n = n
    cout << vct.at((vct.size() - 1) / 2) << endl;

    // Long way
    /*
        n {
            n
        } -> n^2
    */
    while(vct.size() != 1) {
        vct.erase(vct.end() - 1);

        if(vct.size() == 1) {
            cout << vct.at(0) << endl;
            return;
        }

        vct.erase(vct.begin());
    }
}

vector<int> mergeSort(vector<int> vct) {
    if(vct.size() == 1 || vct.size() == 0)
        return vct;

    vector<int> left, right;

    int vctSize = vct.size();
    for(int i = 0; i < vctSize; i++)
        if(i < vctSize / 2)
            left.push_back(vct.at(i));
        else
            right.push_back(vct.at(i));

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> res;

    while(!left.empty() && !right.empty()) {
        if(left.at(0) < right.at(0)) {
            res.push_back(left.at(0));
            left.erase(left.begin());
        }
        else {
            res.push_back(right.at(0));
            right.erase(right.begin());
        }
    }

    while(!left.empty()) {
        res.push_back(left.at(0));
        left.erase(left.begin());
    }

    while(!right.empty()) {
        res.push_back(right.at(0));
        right.erase(right.begin());
    }

    return res;
}