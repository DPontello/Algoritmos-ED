#include <iostream>
#include <vector>

using namespace std;

class Motociclista {
private:
    string nome;
    string marca;
    string modelo;
    int ano;
    string contato;

public:
    Motociclista(string n, string m, string mod, int a, string telefone);

    string getMarca() {
        return marca;
    }
};

// Construtor Motociclista
Motociclista::Motociclista(string n, string m, string mod, int a, string telefone)
    : nome(n), marca(m), modelo(mod), ano(a), contato(telefone) {}


class Oficina {
private:
    string nome;
    vector<string> marcasAtendidas;
    string tipoBeneficio;

public:
    Oficina(string n, string beneficio);
    bool atendeMarca(string marca);
    void adicionarMarcas(string marca);

    string getNome() {
        return nome;
    }

    string getBeneficio() {
        return tipoBeneficio;
    }
};

// Construtor Oficina
Oficina::Oficina(string n, string beneficio)
    : nome(n), tipoBeneficio(beneficio) {}

bool Oficina::atendeMarca(string marca) {
    for (string m : marcasAtendidas) {
        if (m == marca) {
            return true;
        }
    }
    return false;
}

void Oficina::adicionarMarcas(string marca) {
    marcasAtendidas.push_back(marca);
}

class Associacao {
private:
    vector<Motociclista> motociclistas;
    vector<Oficina> oficinas;

public:
    Associacao() {}

    void adicionarMotociclista(Motociclista novoMotociclista);
    void adicionarOficina(Oficina novaOficina);
    void consultarOficinasPorMarca(string marca);
};

// Adiciona um novo motociclista à associação
void Associacao::adicionarMotociclista(Motociclista novoMotociclista) {
    motociclistas.push_back(novoMotociclista);
}

// Adiciona uma nova oficina à associação
void Associacao::adicionarOficina(Oficina novaOficina) {
    oficinas.push_back(novaOficina);
}

// Consulta oficinas que atendem a uma determinada marca
void Associacao::consultarOficinasPorMarca(string marca) {
    cout << "Oficinas que atendem a marca " << marca << ":" << endl;
    for (Oficina o : oficinas) {
        if (o.atendeMarca(marca)) {
            cout << o.getNome() << " - Benefício: " << o.getBeneficio() << endl;
        }
    }
}

int main() {
    // Exemplo de uso
    Associacao associacao;

    Motociclista m1("João", "Honda", "CB500", 2021, "99999-9999");
    Motociclista m2("Carlos", "Yamaha", "YZF-R3", 2019, "88888-8888");

    Oficina o1("Oficina do Zé", "Desconto de 10%");
    o1.adicionarMarcas("Honda");
    o1.adicionarMarcas("Yamaha");

    Oficina o2("Oficina MotoMax", "Brinde após 5 serviços");
    o2.adicionarMarcas("Yamaha");

    associacao.adicionarMotociclista(m1);
    associacao.adicionarMotociclista(m2);
    associacao.adicionarOficina(o1);
    associacao.adicionarOficina(o2);

    associacao.consultarOficinasPorMarca("Honda");
    associacao.consultarOficinasPorMarca("Yamaha");

    return 0;
}


/*
PSEUDOCODIGO
class Motociclista{
    private:
    string nome;
    string marca;
    string modelo;
    int ano;
    string contato;

    public: 
    Motociclista(string n, string m, string mod, int a, string telefone);
    string getMarca();
};

Motociclista :: Motociclista(string n, string m, string mod, int a, string telefone){
    o contrutor da classe motociclista vai inicialziar os atributos
}

strint Motociclista :: getMarca(){
    vai retornar o nome da marca
}

class Oficina{
    private:
    string nome;
    vector<string> marcasAtendidas;
    string tipoBeneficio;

    public: 
    Oficina(string n, string beneficio);
    bool atendeMarca(string marca);
    void adicionarMarcas(string marca);
    string getNome();
    string getBeneficio();
};

Oficina :: Oficina(string n, string beneficio){
    o construtor da classe oficina vai inicializar os atributos
}

bool Oficina :: atendeMarca(string marca){
    vai verificar se a marca está na lista de marcas atendidas
}

void Oficina :: adicionarMarcas(string marca){
    vai adicionar a marca à lista de marcas atendidas
}

string Oficina :: getNome(){
    vai retornar o nome da oficina
}

string Oficina :: getBeneficio(){
    vai retornar o tipo de beneficio da oficina
}

class Associacao{
    private:
    vector<Motociclista> motociclistas;
    vector<Oficina> oficinas;

    public: 
    Associacao();
    ~Associacao();
    void adicionarMotociclista(Motociclista novoMotociclista);
    void adicionarOficina(Oficina novaOficina);
    void consultarOficinasPorMarca(string marca);

};

Associacao :: Associacao(){
    vai inicializar as listas de motociclistas e oficinas
}

Associacao :: ~Associacao(){
    vai destruir as listas de motociclistas e oficinas
}

void Associacao :: adicionarMotociclista(Motociclista novoMotociclista){
    vai adicionar um novo motociclista à lista de motociclistas
}

void Associacao :: adicionarOficina(Oficina novaOficina){
    vai adicionar uma nova oficina à lista de oficinas
}

void Associacao :: consultarOficinasPorMarca(string marca){
    vai imprimir as oficinas que atendem a uma determinada marca
}

*/