/*
Na matemática a união de dois conjuntos A e B é representada por A ∪ B e é formada por todos os elementos pertencentes a A ou B. Por exemplo, seja A = {1, 2, 3} e B = {4, 5}, então a união destes dois conjuntos será A ∪ B = {1, 2, 3, 4, 5}, porém caso um elemento esteja em ambos os conjuntos ele não irá aparecer duas vezes no conjunto união, por exemplo, seja A = {1, 2, 3} e B = {1, 2, 4}, assim a união será A ∪ B = {1, 2, 3, 4}.

Utilizando os conceitos de conjunto faça um programa que leia dois vetores A e B e determine a união. O tamanho de cada vetor será informado pelo usuário.

Obs.: Considere que não existirão vetores vazios.

Obs.2: Os vetores devem ser alocados dinamicamente.

Entradas:

Tamanho do vetor A.
Elementos do vetor A.
Tamanho do vetor B.
Elementos do vetor B.
Saídas:

Vetor C representado a união dos vetores A e B.
Exemplo de Entrada:

3
1 2 3
2
2 4
Exemplo de Saída:

1 2 3 4
*/




#include <iostream>
using namespace std;

bool existeNoVetor(int *vetor, int tamanho, int valor){
    for (int i = 0; i < tamanho; i++){
        if(vetor[i] == valor){
            return true; // se o valor já existe
        }
    }
    return false; // valor é novo
}


int main(){
    int tamVetorA;
    cout << "Tamanho do vetor a ? " << endl;
    cin >> tamVetorA;
    
    int *vetorA = new int[tamVetorA];
    
    cout << "digite os valores do vetor A" << endl;
    for(int i = 0; i < tamVetorA; i++){
        cin >> vetorA[i];
    }


    int tamVetorB;
    cout << "Tamanho vetor b? " << endl;
    cin >> tamVetorB;
    
    int *vetorB = new int[tamVetorB];

    cout << "Digite os valores do vetor B" << endl;
    for(int i = 0; i < tamVetorB; i++){
        cin >> vetorB[i];
    }

    // tamanho maximo do vetor C
    int tamVetorC = tamVetorA + tamVetorB;
    int *vetorC = new int[tamVetorC];
    int contador = 0;

    //Inserir os elementos do vetor A no vetor C
    for(int i = 0; i < tamVetorA; i++){
        vetorC[i] = vetorA[i];
        contador++;
    }

    //inserir os elementos do vetor B no vetor C sem duplicatas
    for(int i = 0; i < tamVetorB; i++){
        if(!existeNoVetor(vetorC, tamVetorC, vetorB[i])){
            vetorC[contador] = vetorB[i];
            contador++;
        }
    }

    //exibir vetor C
    for (int i = 0; i < contador; i++){
        cout << vetorC[i] << " ";
    }
    cout << endl;

    delete[] vetorA;
    delete[] vetorB;
    delete[] vetorC;

    return 0;
}