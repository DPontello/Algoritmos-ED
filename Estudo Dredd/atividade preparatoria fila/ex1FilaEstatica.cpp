/*
Implemente uma estrutura de dados fila, utilizando armazenamento em vetor, para implementar uma lista de processos para uma repartição pública, utilizando como base o código fornecido. A estrutura deve possibilitar, pelo menos, as seguintes ações: enfileiramento e desenfileiramento de itens, verificação do item no topo da pilha e limpeza de processos (remoção de todos os elementos da fila). O desenfileiramento deve escrever mensagem de erro na saída ("Erro: fila vazia!"), quando a fila já estiver vazia. O enfileiramento também deve gerar mensagem de erro ("Erro: fila cheia!"), quanto todas as posições do vetor estiverem ocupadas. Os itens da lista de processos possuem os seguintes atributos: assunto (uma string sem espaços), nome do interessado(uma string sem espaços), tipo (um único caracter) e numero do processo (um inteiro). Além disso, essa repartição tem capacidade para trabalhar com apenas seis processos por vez.

Entradas:

O programa deve aceitar os seguintes comandos:

i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de processos
r: para retirar um item da lista de processos
l: para limpar (remover todos) os itens da lista de processos
e: para espiar o topo da lista de processo (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da fila são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: fila vazia!
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon a 40
Erro: fila cheia!
r
Nome: processo1 Assunto: Joao Tipo: a Processo: 2
e
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
i processo7 Marlon a 40
f
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
Nome: processo3 Assunto: Severino Tipo: d Processo: 9
Nome: processo4 Assunto: Marcos Tipo: f Processo: 12
Nome: processo5 Assunto: Barnabe Tipo: a Processo: 10
Nome: processo6 Assunto: Tiao Tipo: z Processo: 22
Nome: processo7 Assunto: Marlon Tipo: a Processo: 40
*/

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
