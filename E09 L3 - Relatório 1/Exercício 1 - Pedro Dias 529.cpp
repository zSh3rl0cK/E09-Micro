#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int quantidade; // Variável para armazenar a quantidade de itens comprados
    float preco;    // Variável para armazenar o preço total da compra

    cin >> quantidade; // Lê a quantidade de itens do usuário

    // Verifica se a quantidade comprada é maior ou igual a 12
    if (quantidade >= 12) {
        preco = quantidade * 0.65; // Preço reduzido para 0.65 se comprar 12 ou mais
    } else {
        preco = quantidade * 0.8;  // Preço unitário normal de 0.80 se comprar menos de 12
    }

    // Configura a saída para mostrar 2 casas decimais
    cout << fixed << setprecision(2);

    // Exibe o preço total da compra
    cout << "Preco total: " << preco << endl;

    return 0;
}