#include <iostream>
#include <vector>
#include <algorithm>
#include "Time.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int n;
    while (true) {
        cout << "Введіть кількість об'єктів часу: ";
        if (cin >> n && n > 0) break;
        cout << "❌ Помилка! Введіть додатнє ціле число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<Time> arr(n);
    cout << "\n--- Введення часу ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nЧас #" << i + 1 << endl;
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](const Time& a, const Time& b) {
        return a > b;
    });

    cout << "\nВідсортований масив (за спаданням):\n";
    for (auto& t : arr)
        cout << t << endl;

    int k;
    while (true) {
        cout << "\nВведіть кількість секунд, на яку зменшити кожен час: ";
        if (cin >> k && k >= 0) break;

        cout << "❌ Помилка! Кількість секунд має бути невід’ємним числом.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    for (auto& t : arr)
        t -= k;

    cout << "\nМасив після зменшення:\n";
    for (auto& t : arr)
        cout << t << endl;

    return 0;
}
