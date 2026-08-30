#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float>& bucket) {

    for (int i = 1; i < bucket.size(); i++) {

        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(vector<float>& arr) {

    const int bucketCount = 10;

    vector<float> buckets[10];

    // Put elements into buckets
    for (float x : arr) {

        int index = x * 10;

        if (index == 10)
            index = 9;

        buckets[index].push_back(x);
    }

    // Sort each bucket
    for (int i = 0; i < 10; i++) {
        insertionSort(buckets[i]);
    }

    // Concatenate buckets
    int k = 0;

    for (int i = 0; i < 10; i++) {

        for (float x : buckets[i]) {
            arr[k] = x;
            k++;
        }
    }
}

int main() {

    vector<float> arr = {0.00, 0.70, 0.25, 0.05};

    bucketSort(arr);

    cout << "Sorted Array: ";

    for (float x : arr) {
        cout << x << " ";
    }

    return 0;
}