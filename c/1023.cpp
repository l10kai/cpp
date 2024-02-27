#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    double sum = 0.0;
    double num = 2.0;
    double dir = 1.0;

    for (int i = 1; i <= N; ++i) {
        sum += num / dir;

        double temp = num;
        num = num + dir;
        dir = temp;
    }

    cout << fixed << setprecision(2) << sum << endl;

    return 0;
}
