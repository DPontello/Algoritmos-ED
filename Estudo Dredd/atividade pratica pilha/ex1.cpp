#include <iostream>
using namespace std;

struct Item {
    string nome;
    char tipo;
    int valor;
};

class Noh {
    friend class Pilha;
private:
    Item item;
    Noh *mProximo;

public:
    Noh(Item item) {
        this->item = item;
        mProximo = NULL;
    }
};

class Pilha {
private:
    Noh *mTopo;
    int mTamanho;

public:
    Pilha() {
        mTopo = NULL;
        mTamanho = 0;
    }

    ~Pilha() {
        limpaPilha();
    }

    void limpaPilha() {
        while (!(isEmpty())) {
            pop();
        }
    }

    bool isEmpty() {
        return (mTopo == NULL);
    }

    void pop() {
        if (isEmpty()) {
            cout << ("Erro: pilha vazia!") << endl;
        } else {
            Noh *aux = mTopo;
            Item itemRemovido = aux->item;
            mTopo = mTopo->mProximo;
            aux->mProximo = NULL;
            delete aux;
            mTamanho--;
            cout << "Nome: " << itemRemovido.nome << " " << "Tipo: " << itemRemovido.tipo << " " << "Valor: " << itemRemovido.valor << endl;
        }
    }

    void push(Item item) {
        Noh *novo = new Noh(item);
        novo->mProximo = mTopo;
        mTopo = novo;
        mTamanho++;
    }

    void espiar() {
        if (isEmpty()) {
            cout << "Erro: pilha vazia!" << endl;
        } else {
            Item itemNoTopo = mTopo->item;
            cout << "Nome: " << itemNoTopo.nome << " " << "Tipo: " << itemNoTopo.tipo << " " << "Valor: " << itemNoTopo.valor << endl;
        }
    }
};

int main() {
    Item item;
    Pilha p1;
    string comando;
    while (cin >> comando) {
        if (comando == "i") {
            cin >> item.nome >> item.tipo >> item.valor;
            p1.push(item);
        } else if (comando == "r") {
            p1.pop();
        } else if (comando == "l") {
            p1.limpaPilha();
        } else if (comando == "e") {
            p1.espiar();  
        } else if (comando == "f") {  
            while (!p1.isEmpty()) {
                p1.pop();
            }
            break;
        }
    }

    return 0;
}