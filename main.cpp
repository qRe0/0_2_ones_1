#include <iostream>
#include <vector>

using namespace std;

// Константа MOD используется для вычисления остатков при делении.
const int MOD = 1000000007;

// Функция countBinaryStrings принимает два аргумента: n и k, и возвращает количество бинарных строк.
int countBinaryStrings(int n, int k) {
    // Создаем двумерный вектор dp для хранения промежуточных результатов.
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Инициализируем базовые значения dp.
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Вычисляем количество бинарных строк.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // Для каждой комбинации i и j, используем формулу для dp.
            // dp[i][j] равно сумме dp[i - 1][j] и dp[i - 1][j - 1], с учетом MOD.
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    // Возвращаем результат, который хранится в dp[n][k].
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    // Вызываем функцию countBinaryStrings и выводим результат.
    cout << countBinaryStrings(n, k) << endl;

    return 0;
}


