/*
Enunciado 2

Os motociclistas da região decidiram se reunir em uma associação para estabelecer parcerias com oficinas mecânicas especializadas e fornecedores de peças e acessórios de
modo a conseguir vantagens para todos: os serviços em preço mais em conta e a fidelização dos clientes para as oficinas e lojas. A primeira atitude foi realizar o levantamento
de todos que gostariam de participar da associação registrando seu nome, marca, modelo e ano da motocicleta, e telefone para contato. A partir desse primeiro cadastro, os
dirigentes da associação buscaram por oficinas especializadas e lojas de peças e acessórios das marcas identificadas no cadastro inicial.

A associação precisa realizar o cadastro das oficinas e lojas, registrar os acordos de parceria identificando o nome da oficina ou loja, as marcas atendidas por ela e o tipo
de benefício que será dado (desconto por serviço, brinde ou revisão gratuita após 5 serviços realizados). A associação também poderá, sempre que solicitado, consultar o nome
das oficinas ou lojas que atendem  uma determinada marca. Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de
cada uma delas e qual o comportamento esperado (os métodos) de cada entidade.
*/
#include <iostream>
#include <vector>

using namespace std;

class motociclista{
    private: 
        string nome;
        string marca;
        string modelo;
        int ano;
        string contato;

    public: 
        motociclista(string n, string m, string mod, int a, string telefone);
        
        string getMarca(){
            return marca;
        }
};

motociclista :: motociclista(string n, string m, string mod, int a, string telefone) : 
nome(n),marca(m),modelo(mod),ano(a),contato(telefone){};

class oficina{
    private: 
        string nome;
        vector<string> marcasAtendidas;
        string tipoBeneficio;

    public:
        oficina(string n, string beneficio);
        bool atendeMarca(string marca);

        string getNome(){
            return nome;
        }

        string getBeneficio(){
            return tipoBeneficio;
        }
};

//Construtor
oficina :: oficina(string n, string beneficio) :
nome(n),tipoBeneficio(beneficio){};


bool oficina :: atendeMarca(string marca){
    for(string m : marcasAtendidas){
        if (m == marca){
            return true;
        }
    }
    return false;
}