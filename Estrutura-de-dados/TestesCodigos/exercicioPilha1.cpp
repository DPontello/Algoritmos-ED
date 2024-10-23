/*
Considere o alfabeto S = {A,B,C} e a linguagem L = {AnCmBn | n > 0, m ≥ 0}, ou seja, as sequências  AAACBBB, ACCCB, AAABBB são todas pertencentes ao conjunto de sentenças válidas
de L. Essa linguagem pode ser utilizada para representar uma série de estruturas em computação, como parênteses aninhados. Faça um programa que, dada uma sequência w de caracteres A,
B e C, verifique se w faz parte ou não do conjunto de sentenças de L. Utilize uma pilha para fazer essa verificação. 
*/

#include <iostream>
using namespace std;

class Noh{
    friend class Pilha;
    private: 
        char letra;
        Noh *mProximo; 
    
    public: 
        Noh(char letra){
            this->letra = letra;
            mProximo = NULL;
        }    

};
   
class Pilha{
    private: 
        Noh *mTopo;
        unsigned mTamanho;
    
    public:
        Pilha(){
            mTopo = NULL;
            mTamanho = 0;
        }
        
        ~Pilha(){
            limpaPilha();
        }

        void push(char letra){
            Noh *novoNoh = new Noh(letra);
            novoNoh->mProximo = mTopo; 
            mTopo = novoNoh;
            mTamanho++;
        }

        void limpaPilha(){
            while(mTamanho > 0){
                pop();
            }
        }

        int pop(){
            int valor = mTopo->letra;
            Noh *aux = mTopo;
            mTopo = mTopo->mProximo;
            delete aux;
            mTamanho--;
            return valor;

        }

        bool isEmpty(){
            return (mTopo == NULL);
        }
        
};