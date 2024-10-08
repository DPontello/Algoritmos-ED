/*
Considere o alfabeto S = {A,B,C} e a linguagem L = {AnCmBn | n > 0, m ≥ 0}, ou seja, as sequências  AAACBBB, ACCCB, AAABBB são todas pertencentes ao conjunto de sentenças válidas
de L. Essa linguagem pode ser utilizada para representar uma série de estruturas em computação, como parênteses aninhados. Faça um programa que, dada uma sequência w de caracteres A,
B e C, verifique se w faz parte ou não do conjunto de sentenças de L. Utilize uma pilha para fazer essa verificação. 
*/

#include <iostream>
using namespace std;

class Noh{
    private: 
    char mValor;
    Noh *mAnterior;

    public:
    Noh(char valor);
    char getValor(){return mValor;}
    void setAnterior(Noh *anterior);
    Noh *getAnterior(){return mAnterior;}
};

Noh::Noh(char mValor){
    this->mValor = mValor;
    mAnterior = NULL;
}

void Noh::setAnterior(Noh *mAnterior){
    this->mAnterior = mAnterior;
}

class Pilha{
    private:
    Noh *mTopo;
    unsigned tamanho;

    public:
    Pilha();
    ~Pilha();
    unsigned getTamanho(){return tamanho;}
    void empilha(char valor);
    bool estaVazia(){return (tamanho ==0);}
    char desempilha();
    void limparPilha();
};

Pilha::Pilha(){
    mTopo = NULL;
    tamanho = 0;
}

Pilha::~Pilha(){
    limparPilha();
}

void Pilha::empilha(char valor){
    Noh *novoNo = new Noh(valor);
    novoNo->setAnterior(mTopo);
    mTopo = novoNo;
    tamanho++;
}

char Pilha::desempilha(){
    char valor = mTopo->getValor();
    Noh *aux = mTopo;
    mTopo = aux->getAnterior();
    delete aux;
    tamanho--;
    return valor;
}

void Pilha::limparPilha(){
    while(!estaVazia()){
        desempilha();
    }
}

int main(){
    Pilha lista;
    string sequencia;
    cin >> sequencia;

    int i = 0;
    while (sequencia[i]){
        lista.empilha(sequencia[i]);
        i++;
    }

    int cont[2] = {0,0};
    while (not lista.estaVazia()){
        char letra = lista.desempilha();
        if (letra == 'B') cont[1]++;
        else if (letra =='A') cont[0]++;
    }

    if (cont[0] == cont[1]){
        cout << "Essa sequência é válida!!!" << endl;
    } else {
        cout << "Essa sequência não é válida!!!" << endl;
    }

    return 0;
}