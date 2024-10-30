/*
Uma nova copiadora irá abrir na sua cidade. Você foi contratado para fazer o programa que gerencia as senhas de utilização dos serviços. As instruções passadas a você são: existem dois tipos de senha, as prioritárias e as normais; as senhas são chamadas de modo a serem chamadas 3 prioritárias para então uma normal. Não havendo prioridades, as pessoas com senha normal podem ser atendidas normalmente. Sempre que um atendimento normal for realizado, os próximos três devem ser prioritários, se possível. Se estiver na hora de realizar um atendimento de cliente normal mas não houver nenhum cliente normal, deve ser chamado um nome do atendimento preferencial, se houver.

Este é um problema de uso de fila. Você deverá usar uma estrutura de dados do tipo fila, sendo que a classe fila não deve conter nenhum método que tenha características do problema. Em outras palavras, a classe fila não pode ter mecanismos indevidos de acessos a seus dados. Também não é permitido o uso da STL ou similares.

O programa deve ler comandos representados por palavras e seus respectivos argumentos assim:

O comando "normal" seguido de um nome (sem espaços) representa retirada de uma senha normal.
O comando "prioridade" seguido de um nome (sem espaços) representa retirada de uma senha prioritária.
O comando "atender" representa uma senha sendo chamada.
O comando "fim" solicita o fim da execução do programa.
Para cada comando de atendimento, o programa deverá escrever o nome da pessoa que deve ser atendida, de acordo com as regras de atendimento vistas. Caso não haja cliente a ser chamado, o programa deve escrever "AGUARDE" (letras maiúsculas). A cada atendimento normal, a contagem para prioritários deve ser reiniciada.



Você pode usar o código base disponível no final do enunciado

Entradas:

Sequência de comandos, seguindo as instruções acima.
Saídas:

Somente o comando "atender" gera saída, conforme instruções acima.
Exemplo de Entrada:

normal Abner
prioridade Ackson
normal Adilson
normal Adriana
normal Adriano
normal Adriel
prioridade Adrielle
atender
atender
atender
atender
prioridade Adriene
prioridade Adson
prioridade Afonso
prioridade Agatha
atender
atender
atender
atender
atender
fim

Exemplo de Saída:

Ackson
Adrielle
Abner
Adilson
Adriene
Adson
Afonso
Adriana
Agatha

Exemplo de Entrada:
prioridade aline
prioridade alice
atender
atender
atender
fim
Exemplo de Saída:
aline
alice
AGUARDE
*/

#include <iostream>
#include <stdexcept>
using namespace std;

struct dado {
    string nome = "vazio";
    string tipo;
    dado* proximo;
};

class fila {
private:
    dado* inicio;
    dado* fim;

public:
    fila() : inicio(nullptr), fim(nullptr) {}

    void enfileirar(dado entrada) {
        dado* novo = new dado;
        *novo = entrada;
        novo->proximo = nullptr;
        if (fim != nullptr)
            fim->proximo = novo;
        else
            inicio = novo;
        fim = novo;
    }

    dado desenfileirar() {
        if (inicio == nullptr) throw runtime_error("Fila vazia!");
        dado retornado = *inicio;
        dado* removido = inicio;
        inicio = inicio->proximo;
        if (inicio == nullptr) fim = nullptr;
        delete removido;
        return retornado;
    }

    bool vazia() const {
        return inicio == nullptr;
    }
};


void atendimento(fila& normais, fila& prioritarios, int& contPrioridade) {
    if (!prioritarios.vazia() && contPrioridade < 3) {
        cout << prioritarios.desenfileirar().nome << endl;
        contPrioridade++;
    } else if (!normais.vazia()) {
        cout << normais.desenfileirar().nome << endl;
        contPrioridade = 0;  
    } else if (!prioritarios.vazia()) {
        cout << prioritarios.desenfileirar().nome << endl;
        contPrioridade++;
    } else {
        cout << "AGUARDE" << endl;
    }
}

int main() {
    fila normais;
    fila prioritarios;
    string comando;
    dado entrada;
    int contPrioridade = 0;

    cin >> comando;
    while (comando != "fim") {
        if (comando == "normal") {
            cin >> entrada.nome;
            entrada.tipo = "normal";
            normais.enfileirar(entrada);
        } else if (comando == "prioridade") {
            cin >> entrada.nome;
            entrada.tipo = "prioridade";
            prioritarios.enfileirar(entrada);
        } else if (comando == "atender") {
            atendimento(normais, prioritarios, contPrioridade);
        }
        cin >> comando;
    }

    return 0;
}



















