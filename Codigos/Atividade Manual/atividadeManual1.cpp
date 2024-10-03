/*
Enunciado 2
Os motociclistas da região decidiram se reunir em uma associação para estabelecer parcerias com oficinas mecânicas especializadas e fornecedores de peças e acessórios de modo a 
conseguir vantagens para todos: os serviços em preço mais em conta e a fidelização dos clientes para as oficinas e lojas. A primeira atitude foi realizar o levantamento de todos 
que gostariam de participar da associação registrando seu nome, marca, modelo e ano da motocicleta, e telefone para contato. A partir desse primeiro cadastro, os dirigentes da 
associação buscaram por oficinas especializadas e lojas de peças e acessórios das marcas identificadas no cadastro inicial.
A associação precisa realizar o cadastro das oficinas e lojas, registrar os acordos de parceria identificando o nome da oficina ou loja, as marcas atendidas por ela e o tipo de 
benefício que será dado (desconto por serviço, brinde ou revisão gratuita após 5 serviços realizados). A associação também poderá, sempre que solicitado, consultar o nome das 
oficinas ou lojas que atendem  uma determinada marca.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado (os métodos) 
de cada entidade.
*/
#include <iostream>
using namespace std;

class Motociclista {
private:
    string nome;
    string marca;
    string modelo;
    int anoMotocicleta;
    string contato;

public:
    Motociclista() {};

    void cadastrarMotocicleta(string nome, string marca, string modelo, int ano, string contato) {
        this->nome = nome;
        this->marca = marca;
        this->modelo = modelo;
        this->anoMotocicleta = ano;
        this->contato = contato;
    }

    string toString() {
        return "\nNome: " + nome + "\nMarca: " + marca + "\nModelo: " + modelo + "\nAno: " + to_string(anoMotocicleta) + ", \nContato: " + contato + "\n";
    }
};

class Oficina {
private:
    string nome;
    string marcasAtendidas;
    string tipoBeneficio;

public:
    Oficina() {}; 

    void cadastrarOficina(string nome, string marcasAtendidas, string tipoBeneficio) {
        this->nome = nome;
        this->marcasAtendidas = marcasAtendidas;
        this->tipoBeneficio = tipoBeneficio;
    }

    string getMarcasAtendidas() {
        return marcasAtendidas;
    }

    string toString() {
        return "\nNome: " + nome + "\nMarcas atendidas: " + marcasAtendidas + "\nBenefício: " + tipoBeneficio + "\n";
    }
};

class Associacao {
private:
    Motociclista* motociclistas;
    Oficina* oficinas;
    int tamMotociclistas;
    int tamOficinas;
    int numMotociclistas = 0;
    int numOficinas = 0;

public:
    Associacao(int tamMotociclistas, int tamOficinas) {
        this->tamMotociclistas = tamMotociclistas;
        this->tamOficinas = tamOficinas;
        this->motociclistas = new Motociclista[tamMotociclistas];
        this->oficinas = new Oficina[tamOficinas];
    }

    ~Associacao() {
        delete[] motociclistas;
        delete[] oficinas;
    }

    void adicionarMotociclista(Motociclista a) {
        if (numMotociclistas < tamMotociclistas) {
            motociclistas[numMotociclistas] = a; // 
            numMotociclistas++;
        } else {
            cout << "Capacidade máxima de motociclistas atingida!" << endl;
        }
    }

    void adicionarOficina(Oficina a) {
        if (numOficinas < tamOficinas) {
            oficinas[numOficinas] = a; // Corrigido para usar numOficinas
            numOficinas++;
        } else {
            cout << "Capacidade máxima de oficinas atingida!" << endl;
        }
    }

    void consultarOficina(string marca) {
        bool found = false; // Variável para verificar se alguma oficina foi encontrada
        for (int i = 0; i < numOficinas; i++) {
            if (oficinas[i].getMarcasAtendidas().find(marca) != string::npos) { // Verifica se a marca está presente
                cout << oficinas[i].toString();
                found = true;
            }
        }
        if (!found) {
            cout << "Nenhuma oficina encontrada para a marca " << marca << endl; // Mensagem correta se não encontrar
        }
    }
};

int main() {
   
    return 0;
}




/* PSEUDOCODIGO

class Motociclista{
    private:
    string nome;
    string marca;
    string modelo;
    int ano;
    string contato;

    public: 
    Motociclista(string nome, string marca, string modelo, int ano, string contato);
    void Motociclista:: cadastrarMotociclista()
    string toString();
};

Motociclista :: Motociclista(){
    o contrutor da classe motociclista vai inicialziar os atributos
}

void Motociclista:: cadastrarMotociclista(){
    vai cadastrar os dados do motociclista
    }


string Motociclista :: toString(){
    vai retornar uma string com todos os dados do motociclista
}

class Oficina{
    private:
    string nome;
    string marcasAtendidas;
    string tipoBeneficio;

    public: 
    Oficina();
    void cadastrarOficina(string nome, string marcasAtendidas, string tipoBeneficio);
    string getMarcasAtendidas();
    string toString();
    string getBeneficio();
};

Oficina :: Oficina(){
    o construtor da classe oficina vai inicializar os atributos
}

void Oficina :: cadastrarOficina(string n, string marcas, string beneficio){
    vai ser feito o cadastro da oficina
}

string Oficina :: getMarcasAtendidas(){
    vai retornar a lista de marcas atendidas
}

string Oficina :: toString(){
    vai retornar uma string com todos os dados da oficina
}

string Oficina :: getBeneficio(){
    vai retornar o tipo de beneficio da oficina
}



class Associacao{
    private:
        Motociclistas *motociclistas;
        Oficinas *oficinas;
        int tamMotociclistas;
        int tamOficinas;
        int numMotociclistas = 0;
        int numOficinas = 0;

    public: 
    Associacao(int tamMotociclistas, int tamOficinas);
    ~Associacao();
    void adicionarMotociclista(Motociclista a);
    void adicionarOficina(Oficina a);
    void consultarOficinasPorMarca(string marca);
};

Associacao :: Associacao(){
    vai inicializar as listas de motociclistas e oficinas
}

Associacao :: ~Associacao(){
    vai destruir as listas de motociclistas e oficinas
}

void Associacao :: adicionarMotociclista(Motociclista novoMotociclista){
    vai adicionar um novo motociclista à lista de motociclistas e caso numero de motociclistas seja igual a capacidade vai exibir uma mensagem de vetor lotado;
}

void Associacao :: adicionarOficina(Oficina novaOficina){
   vai adicionar uma nova oficina à lista de oficinas e caso numero de oficinas seja igual a capacidade vai exibir uma mensagem de vetor lotado;
}

void Associacao :: consultarOficinasPorMarca(string marca){
    vai imprimir as oficinas que atendem a uma determinada marca por meio de um for que percorre o vetor de marcasAtendidas e um bool found que procura se a marca faz parte do vetor
    e em caso negativo vai exibir uma mensagem de que a oficina não atende tal marca;
}

*/