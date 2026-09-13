#include <iostream>
using namespace std;

int main() {
    int vec[] = {45, 37, 11, 91, 4};
    int n = 5;
    cout<<"Suru: \n";
    for(int i = 0; i<5; i++) cout<<vec[i]<<" ";
    cout<<endl;

    cout<<"Sorting: \n";
    // Equivalent sorting logic from the assembly code
    for (int si = 0; si < 5; si++) {
        cout<<"outer loope: "<<si<<endl;
        for (int bx = 0; bx < 5; bx++) {
            cout<<"inner loope: "<<bx<<endl;
            if (vec[si] < vec[bx]) {
                swap(vec[si], vec[bx]);
            }
            for(int i = 0; i<5; i++) cout<<vec[i]<<" ";
            cout<<endl;
        }
    }

    cout << "SORTED ARRAY: ";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << ' ';
    }
    cout<<endl;

    return 0;
}