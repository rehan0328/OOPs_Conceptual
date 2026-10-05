#include <iostream>
using namespace std;
class Search {
public:
    void search(int a[], int n, int key) {
        for(int i = 0; i < n; i++) {
            if(a[i] == key) {
                cout << "Integer found at position: " << i + 1 << endl;
                return;
            }
        }
        cout << "Integer not found" << endl;
    }

    void search(char a[], int n, char key) {
        for(int i = 0; i < n; i++) {
            if(a[i] == key) {
                cout << "Character found at position: " << i + 1 << endl;
                return;
            }
        }
        cout << "Character not found" << endl;
    }

    void search(int a[], int start, int end, int key) {
        for(int i = start; i <= end; i++) {
            if(a[i] == key) {
                cout << "Integer found at position: " << i + 1 << endl;
                return;
            }
        }
        cout << "Integer not found in range" << endl;
    }
};

int main() {
    Search s;

    int a[] = {10, 20, 30, 40, 50};
    char c[] = {'a', 'b', 'c', 'd'};

    s.search(a, 5, 30);
    s.search(c, 4, 'c');
    s.search(a, 1, 3, 40);

    return 0;
}