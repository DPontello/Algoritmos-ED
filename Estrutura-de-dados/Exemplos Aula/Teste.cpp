/*Enunciado 1
Um curador de exposições fotográficas acumulou, ao longo de sua carreira, os dados de muitos artistas, muitos entusiastas (pessoas que adquirem as obras expostas) e contatos de mídia.
Ele está sendo convidado por uma grande rede de eventos para organizar novas exposições. Para essa finalidade, ele deseja agora separar esses dados. Para os artistas serão armazenados
o nome do artista, seu telefone de contato e o endereço de seu ateliê (ou estúdio). Para os entusiastas serão armazenados seu nome, o nome e o valor da última obra que ele adquiriu, 
seu e-mail de contato. Para os contatos de mídia, nome da mídia, nome do responsável por divulgar evento e valores acertados nos últimos contratos. Dessa forma, o curador poderá 
planejar a nova exposição, com informações básicas (nome e data da exposição) e com as obras de determinados artistas, os entusiastas convidados e o valor que poderá ser gasto com 
divulgação em mídias especializadas.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado (os métodos) de cada 
entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. 
*/

#include <iostream>
using namespace std;

class Artista{
    private:
    string nome;
    string telefone;
    string endereco;

    public: 
    
    Artista(){};

    void cadastroArtista(string nome, string telefone, string endereco){
        this->nome = nome;
        this->telefone = telefone;
        this->endereco = endereco;
    }

    string toString(){
        return "nome: " + nome + "\ntelefone: " + telefone + "\nendereço: " + endereco;
    }

};

class Entusiasta{
    private:
    string nome;
    string nomeUltimaObra;
    float valorUltimaObra;
    string email;

    public:
    
    Entusiasta(){};
    void cadastrarEntusiasta(string nome, string nomeUltimaObra, float valorUltimaObra, string email){
        this->nome = nome;
        this->nomeUltimaObra = nomeUltimaObra;
        this->valorUltimaObra = valorUltimaObra;
        this->email = email;
    }

    string toString(){
        return "nome: " + nome + "\nnomeUltimaObra: " + nomeUltimaObra + "\nvalorUltimaObra: " + to_string(valorUltimaObra) + "\nemail: " + email;
    }

};

class ContatoMedia{
    string nomeMidia;
    string nomeResponsavel;
    float valorContrato;

    public:

    ContatoMedia(){};

    void cadastrarContatoMedia(string nomeMidia, string nomeResponsavel, float valorContrato){
        this->nomeMidia = nomeMidia;
        this->nomeResponsavel = nomeResponsavel;
        this->valorContrato = valorContrato;
    }

    string toString(){
        return "nomeMidia: " + nomeMidia + "\nnomeResponsavel: " + nomeResponsavel + "\nvalorContrato: " + to_string(valorContrato);
    }

};

class Exposicao{
    private:
    string nomeExposicao;
    string dataExposicao;
    Artista *artistas;
    Entusiasta *entusiastas;
    ContatoMedia *contatosMedia;
    int tamArtistas, tamEntusiastas, tamContatos;
    int numArtistas = 0, numEntusiastas = 0, numContatos = 0;

    public: 
    
    Exposicao(int tamA, int tamE, int tamC){
        tamArtistas = tamA;
        tamEntusiastas = tamE; 
        tamContatos = tamC;
        artistas = new Artista[tamArtistas];
        entusiastas = new Entusiasta[tamEntusiastas];
        contatosMedia = new ContatoMedia[tamContatos];
    }

    ~Exposicao(){
        delete[] artistas;
        delete[] entusiastas;
        delete[] contatosMedia;
    }

    void setDadosExposicao(string nome, string data){
        nomeExposicao = nome;
        dataExposicao = data;
    }

    void adicionarArtista(Artista a){
        if(numArtistas < tamArtistas){
            artistas[numArtistas++] = a;
        } else {
            cout << "Capacidade de artistas atingida" << endl;
        }
    }

    void adicionarEntusiasta(Entusiasta e){
        if(numEntusiastas < tamEntusiastas){
            entusiastas[numEntusiastas++] = e;
        } else {
            cout << "Capacidade de entusiastas atingida" << endl;
        }
    }

    void adicionarContatoMedia(ContatoMedia cm){
        if(numContatos < tamContatos){
            contatosMedia[numContatos++] = cm;
        } else {
            cout << "Capacidade de contatos de mídia atingida" << endl;
        }
    }

    string toString(){
        string result = "Exposição: " + nomeExposicao + "\nData: " + dataExposicao + "\nArtistas: \n";
        for(int i = 0; i < numArtistas; i++){
            result += artistas[i].toString() + "\n";
        }

        result += "\nEntusiastas: \n";
        for(int i = 0; i < numEntusiastas; i++){
            result += entusiastas[i].toString() + "\n";
        }

        result += "\nContatos de mídia: \n";
        for(int i = 0; i < numContatos; i++){
            result += contatosMedia[i].toString() + "\n";
        }

        return result;
    }

};

int main(){
    Exposicao expo(2, 2, 2);

    expo.setDadosExposicao("Exposição de Arte Moderna", "10/10/2024");

    Artista a1;
    a1.cadastroArtista("Vincent van Gogh", "1234-5678", "Rua dos Pintores, 123");
    expo.adicionarArtista(a1);

    Entusiasta e1;
    e1.cadastrarEntusiasta("John Doe", "Starry Night", 1000000.0, "johndoe@example.com");
    expo.adicionarEntusiasta(e1);

    ContatoMedia c1;
    c1.cadastrarContatoMedia("Art News", "Jane Smith", 5000.0);
    expo.adicionarContatoMedia(c1);

    cout << expo.toString() << endl;

    return 0;
}