#include <iostream>
using namespace std;

int main() {
    int num; // Variável para armazenar o número inteiro fornecido

    cin >> num; // lendo o numero

    // Loop que percorre todos os números do seu antecessor até 1
    for (int i = num - 1; i > 0; i--) {
        // Exibe o resto da divisão do número inserido por cada um de seus antecessores
        cout << "Resto da divisao de " << num << " por " << i << " " << num % i << endl;
    }

    return 0;
}