/*
Implemente uma estrutura de dados pilha, utilizando encadeamento de nós,
para implementar um inventário de itens em um jogo digital. A estrutura deve
possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens,
verificação do item no topoPilha da pilha e limpeza do inventário (remoção de todos os elementos da pilha).
O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"),
quando a pilha já estiver vazia. Os itens do inventários possuem os seguintes atributos:
nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

    i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
    r: para retirar um item do inventário
    l: para limpar (remover todos) os itens do inventário
    e: para espiar o topoPilha do inventário (escreve o topoPilha sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido.
Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1
*/

#include <iostream>
using namespace std;

struct Item {
    string nome;
    char tipo;
    int valor;
};

class Noh{
    friend class Pilha;
    private: 
    Item item;
    Noh *mAnterior;

    public:
    Noh(Item item){
        this->item = item;
        mAnterior = NULL;
    }

};

class Pilha{
    private:
    Noh *mTopo;
    int mTamanho;
    public:
    Pilha(){
        mTopo = NULL;
        mTamanho = 0;
    }
    ~Pilha(){
        while(!vazia()){
            desempilha();
        }
    }
    bool vazia(){
        return (mTopo == NULL);
    }
    void empilha(Item item){
        Noh *novoNoh = new Noh(item);
        novoNoh->mAnterior = mTopo;
        mTopo = novoNoh;
        mTamanho++;
    }
    void desempilha(){
        if(vazia()){
            cout << "Erro: pilha vazia!" << endl;
            return;
        }
        Noh *aux = mTopo;
        mTopo = mTopo->mAnterior;
        delete aux;
        mTamanho--;
    }
    void espiarTopo(){
        if(vazia()){
            cout << "Erro: pilha vazia!" << endl;
            return;
        }
        cout << "Nome: " << mTopo->item.nome << " Tipo: " << mTopo->item.tipo << " Valor: " << mTopo->item.valor << endl;
    }

    void limparPilha(){
        while(!vazia()){
            desempilha();
            espiarTopo();
        }
    }
};

int main(){
    
    Pilha pilha;
    Item item;
    char comando;
    bool sexo = false;
    while (sexo == false) {
        cin >> comando;

        if (comando == 'i') {
            // Comando para inserir um item
            cin >> item.nome >> item.tipo >> item.valor;
            pilha.empilha(item);
        }
        else if (comando == 'r') {
            // Comando para remover/desempilhar o item do topo
            pilha.espiarTopo();
            pilha.desempilha();
        }
        else if (comando == 'e') {
            // Comando para espiar o topo da pilha sem remover
            pilha.espiarTopo();
        }
        else if (comando == 'l') {
            // Comando para limpar a pilha (remover todos os elementos)
            pilha.limparPilha();
        }
        else if (comando == 'f') {
            // Comando para finalizar o programa, imprimindo todos os elementos restantes
            pilha.limparPilha(); 
            sexo = true;
            }
        }

    return 0;
}