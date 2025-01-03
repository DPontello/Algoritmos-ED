/*
*  Torneio

Um torneio é uma árvore estritamente binária na qual cada nó não folha contém uma cópia do maior elemento entre seus dois filhos. O conteúdo das folhas de um torneio determina o conteúdo de todos os seus nós. Um torneio com n folhas representa um conjunto de n elementos.

Implemente um torneio utilizando uma estratégia semelhante a um Heap. Note que normalmente um torneio é uma árvore estritamente binária, cheia. Como, neste problema, temos que o tamanho da entrada pode não ser uma potência de 2, será necessário fazer ajustes para trabalhar com o que costumamos chamar de torneio incompleto. Uma das abordagens possíveis é apresentada nos slides e vídeo do assunto, verifique.

O código fornecido é uma base que você pode utilizar. O aluno tem total liberdade em não utiliza-lo ou modifica-lo.

Faça um programa que funcione como um torneio.

A entrada deve conter o número de participantes (número inteiro) seguido dos participantes (números inteiros). A saída apresenta o valor base do participante campeão do torneio.
Entradas:

Quantidade de participantes
Identificação dos participantes
Saídas:

Valor base do campeão do torneio
Exemplo de Entrada:

8
2 7 4 1 3 9 6 8
Exemplo de Saída:

9
Exemplo de Entrada:

13
11 5 3 4 2 15 7 9 10 8 12 6 13
Exemplo de Saída:

15
*/
/*
*  Torneio
*
*  Realiza torneio simples de numeros inteiros
*
*  Made by Renato Ramos da Silva in 18/09/23
*
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int INVALIDO = -1;

class Torneio {
private:
    int *heap;  
    int tamanho; 
    int capacidade; // Quantidade de folhas (participantes)
    int inicioDados; // Índice onde começam as folhas

    inline int pai(int filho) { return (filho - 1) / 2; }
    inline int esquerda(int pai) { return 2 * pai + 1; }
    inline int direita(int pai) { return 2 * pai + 2; }
    void compete(int i);

public:
    Torneio(int vet[], int tam);
    ~Torneio();
    int campeao(); 
};

Torneio::Torneio(int vet[], int tam) {
    capacidade = tam;

    tamanho = 2 * capacidade - 1;
    heap = new int[tamanho];

    inicioDados = capacidade - 1;

    for (int i = 0; i < capacidade; i++) {
        heap[inicioDados + i] = vet[i];
    }

    for (int i = inicioDados - 1; i >= 0; i--) {
        compete(i);
    }
}

Torneio::~Torneio() {
    delete[] heap;
}

// Função para fazer a competição entre os elementos
void Torneio::compete(int i) {
    int esq = esquerda(i);
    int dir = direita(i);


    if (esq < tamanho && dir < tamanho) {
        heap[i] = max(heap[esq], heap[dir]);
    } else if (esq < tamanho) {
        heap[i] = heap[esq];
    } else if (dir < tamanho) {
        heap[i] = heap[dir];
    }
}


int Torneio::campeao() {
    return heap[0];
}

int main() {
    int tam;
    cin >> tam;

    int vet[tam];
    for (int i = 0; i < tam; i++) {
        cin >> vet[i];
    }

    Torneio participantes(vet, tam);
    cout << participantes.campeao() << endl;

    return 0;
}
