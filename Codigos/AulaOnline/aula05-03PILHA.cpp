#include <iostream>
using namespace std;

class Noh{
    friend class Pilha;  // Indica que a classe Pilha pode acessar os membros privados do Noh. Acesso feito por meio de um ponteiro para Noh.
    private:
        int mValor;
        Noh *mProximo;
        
    public:
        Noh(int valor);
};

Noh::Noh(int valor){
    mValor = valor;
    mProximo = NULL;

}

class Pilha{
    private: 
        Noh *mTopo;
        unsigned mTamanho;
    public: 
        Pilha();
        ~Pilha();  // Destrutor de Pilha, responsável por liberar a memória alocada nos nós.
        void empilha(int valor);
        int desempilha();
        bool vazia();  
        int tamanho();  
        void limpaPilha();
};

Pilha::Pilha(){
    mTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha(){
    limpaPilha();
}
void Pilha::empilha(int dado){
    Noh *novoNoh = new Noh(dado);
    novoNoh->mProximo = mTopo; 
    mTopo = novoNoh;
    mTamanho++;  // Incrementa o tamanho da pilha após empilhar um novo elemento.
}

int Pilha::desempilha(){
    int valor = mTopo->mValor;
    Noh *aux = mTopo;
    mTopo = mTopo->mProximo;
    delete aux;
    mTamanho--;  // Decrementa o tamanho da pilha após desempilhar um elemento.
    return valor;
}

bool Pilha::vazia(){
    return (mTamanho == 0);
}

void Pilha::limpaPilha(){
    while(mTamanho > 0){
        desempilha();
    }
}

int Pilha::tamanho(){
    return mTamanho;
}

int main(){
    Pilha p1;
    int num;
    cin >> num;

    while(num >= 0){
        p1.empilha(num);
        cin >> num;
    }
    
    cout << "tamanho: " << p1.tamanho()  << endl;
    cout << "elementos: ";

    while (not p1.vazia()){
        cout << p1.desempilha() << " ";
    }
    
    cout << endl;

    return 0;
}