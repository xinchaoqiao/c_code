#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    int count = 0;
    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            if (count % 2 == 0) {
                for (int k = 0; k < num; k++) {
                    matrix[i][j] = 0;
                    if (++j == N) {
                        j = 0;
                        i++;
                    }
                }
            } else {
                for (int k = 0; k < num; k++) {
                    matrix[i][j] = 1;
                    if (++j == N) {
                        j = 0;
                        i++;
                    }
                }
            }
            count++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
