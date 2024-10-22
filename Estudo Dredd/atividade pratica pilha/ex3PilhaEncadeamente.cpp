/*
Implemente uma função que realize a remoção dos jogos com valores inferiores a um valor informado, denominada remoção especial. Você poderá utilizar somente como estrutura auxiliar outra pilha. Os demais valores da pilha devem permanecer na posição original. Os valores removidos devem ser impressos no momento da remoção.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Pilha com encadeamento - Inventário de itens de jogo" como base.

Entradas:

Com essa finalidade, você deverá adicionar mais um comando, como segue:

x: seguido de um inteiro: para remover (e imprimir) todos os elementos com valor inferiores ao informado
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção especial. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i dez j 10
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
x 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1
f
Nome: sete Tipo: g Valor: 7
Nome: quatro Tipo: d Valor: 4
Nome: dez Tipo: j Valor: 10

*/


#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado {
    string nome;
    char tipo;
    int valor;
};

// Imprime as informações de um dado qualquer
void imprimir_dado(const Dado& umDado) {
    cout << "Nome: " << umDado.nome << " Tipo: " << umDado.tipo << " Valor: " << umDado.valor << endl;
}

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variável
        Noh* mProx;
    public:
        Noh(Dado v) {
            mDado = v;
            mProx = NULL;
        }        
};

class Pilha {
    public:
        // Constrói pilha vazia.
        Pilha();
        // Destrutor que desaloca memória.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se não for possível desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha.
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Imprime o valor que está no mPtTopo sem desempilhar.
        inline void Topo();
        // Informa se a pilha está Vazia.
        inline bool Vazia();
        void remocaoEspecial(int valor);
    private:
        Noh* mTopo;
};

Pilha::Pilha() {
    mTopo = NULL;
}

Pilha::~Pilha() {
    LimparTudo();
}

Dado Pilha::Desempilhar() {
    if (this->Vazia()) throw runtime_error("Erro: pilha vazia!");
    // completar com o código, caso não esteja vazia
    Dado apagado = mTopo->mDado;
    Noh *aux = mTopo;
    mTopo = mTopo->mProx;
    aux->mProx = NULL;
    delete aux;
    return apagado;
}

void Pilha::Empilhar(const Dado& d) {
   Noh *novo = new Noh(d);
   novo->mProx = mTopo;
   mTopo = novo;
}

void Pilha::LimparTudo() {
    while(mTopo != NULL){
        Desempilhar();
    }
}

void Pilha::Topo() {
    if (this->Vazia()) throw runtime_error("Erro: pilha vazia!");
    // completar com o código, caso não esteja vazia
    imprimir_dado(mTopo->mDado); // Imprime o primeiro item da pilha
}

bool Pilha::Vazia() {
    return (mTopo == NULL);
}

void Pilha::remocaoEspecial(int valor){
    Pilha aux;

    while(!this->Vazia()){
        Dado d = mTopo->mDado;
        if(d.valor < valor){
            imprimir_dado(Desempilhar());
        } else {
            aux.Empilhar(d);
            this->Desempilhar();
        }
    }
    while(!aux.Vazia()){
        this->Empilhar(aux.mTopo->mDado);
        aux.Desempilhar();
    }
    
}


int main() {
    Pilha pilha;
    Dado info;
    char comando;
    do {
        try{
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nome >> info.tipo >> info.valor;
                    pilha.Empilhar(info);
                    break;
                case 'r': // remover
                    imprimir_dado(pilha.Desempilhar());
                    break;
                case 'l': // limpar tudo
                    pilha.LimparTudo();
                    break;
                case 'e': // espiar                
                    pilha.Topo();
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                case 'x': // remoção especial
                int valor;
                    cin >> valor;
                    pilha.remocaoEspecial(valor);
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    while (not pilha.Vazia()) {
        imprimir_dado(pilha.Desempilhar());
    }
    cout << endl;
    return 0;
}