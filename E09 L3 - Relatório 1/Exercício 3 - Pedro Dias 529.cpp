#include <iostream>
using namespace std;

// Função que recebe um vetor de 5 números e identifica quantos são pares, ímpares, positivos e negativos
void identificador(int numeros[]) {
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    // Percorre os 5 números do vetor
    for (int i = 0; i < 5; i++) {
        // Verifica se o número é par ou ímpar
        if (numeros[i] % 2 == 0) {
            pares += 1;
        } else {
            impares += 1;
        }

        // Verifica se o número é positivo ou negativo
        if (numeros[i] >= 0) {
            positivos += 1;
        } else {
            negativos += 1;
        }
    }

    // Exibe os resultados
    cout << "Quantidade de numeros pares: " << pares << endl;
    cout << "Quantidade de numeros impares: " << impares << endl;
    cout << "Quantidade de numeros positivos: " << positivos << endl;
    cout << "Quantidade de numeros negativos: " << negativos << endl;
}

int main() {
    int n; // Número de conjuntos de 5 números a serem lidos
    cin >> n; // Lê a quantidade de testes

    // Loop para ler cada teste de 5 números
    for (int i = 0; i < n; i++) {
        int numeros[5]; // vetor para armazenar 5 números

        // Lendo 5 números
        for (int j = 0; j < 5; j++) {
            cin >> numeros[j];
        }

        // Chama a função identificador para classificar os números
        identificador(numeros);
    }

    return 0;
}
