#include <iostream>
#include <stdexcept>

using namespace std;

const int FILAVAZIA = -1;
const int CAPACIDADE_FILA = 6;

struct Dado {
    string nome;
    string assunto;
    char tipo;
    int nProcesso;
};

// Função que imprime informações de um dado.
void imprimir_dado(const Dado& umDado) {
    cout << "Nome: " << umDado.nome << " Assunto: " << umDado.assunto 
         << " Tipo: " << umDado.tipo << " Processo: " << umDado.nProcesso << endl;
}

class Fila {
private:
    Dado mDado[CAPACIDADE_FILA]; // Vetor para armazenar os dados
    int inicio, fim; // Índices de início e fim da fila
    int tamanho; // Número de elementos na fila

public:
    // Constrói fila vazia.
    Fila();
    // Destrutor que desaloca memória.
    ~Fila();
    // Retira e retorna o elemento que estiver na primeira posição.
    Dado Desenfileirar(); 
    // Insere um elemento na fila.
    void Enfileirar(const Dado& d);
    // Apaga todos os dados da fila.
    void LimparTudo();
    // Imprime o primeiro elemento da fila sem removê-lo.
    void PrimeiroDaFila();
    // Informa se a fila está vazia.
    bool Vazia();
    // Informa se a fila está cheia.
    bool Cheia();
};

// Construtor da Fila
Fila::Fila() {
    inicio = 0;
    fim = -1;
    tamanho = 0;
}

// Destrutor da Fila
Fila::~Fila() {
    LimparTudo();
}

// Função para remover um item da fila (desenfileirar)
Dado Fila::Desenfileirar() {
    if (this->Vazia()) throw runtime_error("Erro: fila vazia!");
    
    Dado apagado = mDado[inicio]; // Armazena o item a ser removido
    inicio = (inicio + 1) % CAPACIDADE_FILA; // Avança o início
    tamanho--; // Reduz o tamanho da fila
    return apagado;
}

// Função para adicionar um item na fila (enfileirar)
void Fila::Enfileirar(const Dado& d) {
    if (this->Cheia()) throw runtime_error("Erro: fila cheia!");

    fim = (fim + 1) % CAPACIDADE_FILA; // Avança o fim
    mDado[fim] = d; // Insere o novo item
    tamanho++; // Aumenta o tamanho da fila
}

// Função para limpar todos os itens da fila
void Fila::LimparTudo() {
    while (!Vazia()) {
        imprimir_dado(Desenfileirar()); // Imprime e remove cada item da fila
    }
}

// Função para mostrar o primeiro item da fila sem removê-lo
void Fila::PrimeiroDaFila() {
    if (this->Vazia()) throw runtime_error("Erro: fila vazia!");
    imprimir_dado(mDado[inicio]); // Imprime o primeiro item da fila
}

// Verifica se a fila está vazia
bool Fila::Vazia() {
    return (tamanho == 0);
}

// Verifica se a fila está cheia
bool Fila::Cheia() {
    return (tamanho == CAPACIDADE_FILA);
}

int main() {
    Fila fila;
    Dado info;
    char comando;

    // Loop principal do programa
    while (cin >> comando) {
        try {
            switch (comando) {
            case 'i': // Inserir um item
                cin >> info.nome >> info.assunto >> info.tipo >> info.nProcesso;
                fila.Enfileirar(info);
                break;
            case 'r': // Remover um item
                imprimir_dado(fila.Desenfileirar());
                break;
            case 'l': // Limpar todos os itens
                fila.LimparTudo();
                break;
            case 'e': // Mostrar o primeiro item
                fila.PrimeiroDaFila();
                break;
            case 'f': // Finalizar o programa
                fila.LimparTudo();
                return 0;
            default:
                cerr << "Comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl; // Exibe mensagens de erro
        }
    }
    return 0;
}
