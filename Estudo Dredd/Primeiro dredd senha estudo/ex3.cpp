/*
Faça um programa que receba três listas de strings. Cada lista representa um conjunto de elementos. Cada lista será digitada em uma linha específica. Será garantido que as duas primeiras listas serão diferentes.

Seu programa deverá exibir no dispositivo de saída padrão, para cada palavra da terceira lista, se a palavra em questão apareceu em nenhuma, uma ou nas duas listas iniciais.

Entradas:

Três listas de strings. Cada lista será fornecida em uma linha específica, com a quantidade de palavras no início.
Saídas:

Sequência de valores que denotam se cada palavra da terceira lista apareceu em nenhuma, uma ou nas duas listas iniciais.
Exemplo de Entrada:

4 bola garrafa pedra cachorro
3 cachorro pedra pato
5 bola garrafa pato cachorro pedra
Exemplo de Saída:

1 1 1 2 2
*/

#include <iostream>
using namespace std;

int main(){
   int tamA = 0, tamB = 0, tamC =0;
   int cont = 0;
   string *vetA;
   string *vetB;
   string *vetC;

   cin >> tamA;
   vetA = new string[tamA];

   for(int i = 0; i < tamA; i++){
        cin >> vetA[i];
   }

   cin >> tamB;
   vetB = new string[tamB];

   for(int i = 0; i < tamB; i++){
        cin >> vetB[i];
   }

    cin >> tamC;
    vetC = new string[tamC];

    for (int i = 0; i < tamC; i++){
        cin >> vetC[i];
    }

    for(int i = 0; i < tamC; i++){
        for(int j = 0; j < tamA; j++){
            if(vetC[i] == vetA[j]){
                cont++;
            }
        }
        for(int j = 0; j < tamB; j++){
            if(vetC[i] == vetB[j]){
                cont++;
            }
        }
        cout << cont << " ";
        cont = 0;
    }

    return 0;
}