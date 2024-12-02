#include <iostream>
#include <exception>

using namespace std;

struct dado {
    string assunto; 
    string nomeInteressado;
    char tipo;
    int numeroProcesso;
};

// Operadores para comparar dados
bool operator==(const dado& d1, const dado& d2) {
    return (d1.nomeInteressado == d2.nomeInteressado);
}

bool operator!=(const dado& d1, const dado& d2) {
    return !(d1 == d2);
}

// Constantes para definir estados especiais
const int UMPRIMO = 13;
const dado INVALIDO = {"", "", '1', -1};
const dado REMOVIDO = {"", "", '2', -2};
const int POSINVALIDA = -1;

class hashEA {
private:
    unsigned posicao(const string& chave);
    int buscarChave(const string& chave);
    dado* vetDados;
    unsigned capacidade;
    unsigned tamanho;

public:
    hashEA(unsigned cap = 50);
    ~hashEA();
    void imprimir();
    void inserir(const string& assunto, const string& interessado, const char& tipo, const int& valor);
    void remover(const string& chave);
    int consultar(const string& chave);
};

hashEA::hashEA(unsigned cap) {
    capacidade = cap;
    vetDados = new dado[cap]; 
    for (unsigned i = 0; i < cap; i++) 
        vetDados[i] = INVALIDO;
    tamanho = 0;
}

hashEA::~hashEA() {
    delete[] vetDados;
}

unsigned hashEA::posicao(const string& chave) {
    unsigned pos = 1;
    for (unsigned i = 0; i < chave.size(); i++)
        pos = UMPRIMO * pos + chave[i];
    return pos % capacidade;    
}

int hashEA::buscarChave(const string& chave) {
    unsigned pos = posicao(chave);
    unsigned posFinal = pos;
    dado umDado;

    do {
        umDado = vetDados[pos];
        if (umDado == INVALIDO) return POSINVALIDA; 
        if (umDado.nomeInteressado == chave) return pos;
        pos = (pos + 1) % capacidade;
    } while (pos != posFinal); 

    return POSINVALIDA;
}

void hashEA::inserir(const string& assunto, const string& interessado, const char& tipo, const int& valor) {
    if (interessado.empty()) 
        throw invalid_argument("Chave inválida.");
    if (tamanho == capacidade) {
        cout << "Erro: hash cheia!" << endl;
        return;
    }

    if (buscarChave(interessado) != POSINVALIDA) {
        cout << "Erro: chave já existente!" << endl;
        return;
    }

    unsigned pos = posicao(interessado);
    while ((vetDados[pos] != INVALIDO) and (vetDados[pos] != REMOVIDO))
        pos = (pos + 1) % capacidade;

    vetDados[pos].assunto = assunto;
    vetDados[pos].nomeInteressado = interessado;
    vetDados[pos].tipo = tipo;
    vetDados[pos].numeroProcesso = valor;
    tamanho++;
}

void hashEA::imprimir() {
    for (unsigned i = 0; i < capacidade; ++i) {
        cout << '[' << i << ":";
        if (vetDados[i] != INVALIDO) {
            if (vetDados[i] == REMOVIDO)
                cout << "REMOVIDO";
            else
                cout << vetDados[i].nomeInteressado << '/' << vetDados[i].numeroProcesso;
        }
        cout << "] ";
    }
    cout << endl;
}

void hashEA::remover(const string& chave) {
    if (tamanho == 0) {
        cout << "Erro: hash vazia!" << endl;
        return;
    }
    
    int pos = buscarChave(chave);
    if (pos == POSINVALIDA) {
        cout << "Elemento inexistente!" << endl;
        return;
    }

    vetDados[pos] = REMOVIDO;
    tamanho--;
}

int hashEA::consultar(const string& chave) {
    if (tamanho == 0) {
        cout << "Erro: hash vazia!" << endl;
        return POSINVALIDA;
    }

    int pos = buscarChave(chave);
    if (pos == POSINVALIDA) {
        cout << "Elemento inexistente!" << endl;
        return POSINVALIDA;
    }

    return vetDados[pos].numeroProcesso;
}

int main() {
    hashEA tabela(6);
    char operacao;

    string assunto, interessado;
    char tipo;
    int valor;
    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // inserir
                    cin >> assunto >> interessado >> tipo >> valor;
                    tabela.inserir(assunto, interessado, tipo, valor);
                    break;
                case 'r': // remover
                    cin >> interessado;
                    tabela.remover(interessado);
                    break;
                case 'l': // consultar
                    cin >> interessado;
                    valor = tabela.consultar(interessado);
                    if (valor != POSINVALIDA)
                        cout << valor << endl;
                    break;
                case 'p': // imprimir estrutura
                    tabela.imprimir();
                    break;
                case 'f': // finalizar
                    break;
                default:
                    cerr << "Operação inválida" << endl;
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    } while (operacao != 'f'); 
    tabela.imprimir();
    return 0;
}
