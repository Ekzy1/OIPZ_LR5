#include <iostream>
#include <fstream>
using namespace std;

// Функція для обчислення значення y в залежності від x та n
double calculateY(double x, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Parameter 'n' must be greater than zero.");
    }
    if (x < 0) {
        double sum = 0;
        for (int i = 1; i <= n - 1; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum += (j) / (j * j + j);
            }
        }
        return sum;
    }
    else {
        double sum = 0;
        for (int i = 1; i <= n - 1; ++i) {
            sum += i;
        }
        return x - sum;
    }
}

int main() {
    double a, b, h;
    int n;
    char saveToFile;

    setlocale(LC_ALL, "Ukrainian");

    cout << "Введіть інтервал (a, b): ";
    cin >> a >> b;
    cout << "Введіть крок h: ";
    cin >> h;
    cout << "Введіть значення n: ";
    cin >> n;
    cout << "Чи хочете зберегти результати у файл? (y/n): ";
    cin >> saveToFile;

    ofstream outFile;
    if (saveToFile == 'y') {
        outFile.open("results.txt");
        if (!outFile) {
            cerr << "Помилка відкриття файлу для запису!" << endl;
        }
    }

    // Обчислення функції y для кожного значення x
    for (double x = a; x <= b; x += h) {
        double y = calculateY(x, n);
        cout << "x = " << x << ", y = " << y << endl;
        if (outFile) {
            outFile << "x = " << x << ", y = " << y << endl;
        }
    }
    if (outFile) {
        outFile.close();
        cout << "Результати записані у файл 'results.txt'" << endl;
    }

    return 0;
}