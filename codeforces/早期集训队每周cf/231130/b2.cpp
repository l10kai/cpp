#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> cream(n);
        for (int i = 0; i < n; ++i) {
            cin >> cream[i];
        }

        vector<int> result(n, 0);

        int maxCream = 0;
        for (int i = n - 1; i >= 0; --i) {
            maxCream = max(maxCream, cream[i]);
            if (maxCream > 0) {
                result[i] = 1;
                maxCream--;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
