# Revisão de POO
Revisitaremos dois pilares importantíssimos da programação Orientada a Objetos para esse curso.

## Abstração
Representação de uma entidade do mundo real, com seu comportamento e características. Para fazermos uso da abstração, utilizamos:
- Objetos
  É um conceito do mundo real aplicável ao mundo computacional. Cada objeto é uma instância única de uma classe (responsável por definir as diretrizes gerais de funcionamento desse objeto).
  
- Classes
  Tipo abstrato de dados ([TAD](Tipos Abstratos de Dados)) que reúne objetos com características semelhantes. Em C++, `struct`'s são classes com todos os seus atributos e métodos públicos por padrão.

- Atributos
  Ditam as características de objetos reunidos em uma classe. Para a classe `Estudante`, por exemplo, podemos lidar com os atributos `idade`, `altura`, `nome`, `matricula`, etc. Para além de tipos simples como *int*, *string* e *float*, podemos criar atributos que utilizam-se de objetos de outras classes (exemplo: classe `Disciplina` com um atributo chamado `alunos` do tipo `Estudante`).
  
  ![Imagem 1](anexo/Imagem%201.png)

- Métodos
  Ditam os comportamentos de objetos reunidos em uma classe. Para a classe `Professor`, por exemplo, podemos lidar com os atributos `passarAvaliacao()`, `corrigirExercicios()`, `ministrarAula()`, etc.
  
  ![Imagem 2](anexo/Imagem%202.png)
  
  No exemplo acima, `inicializarDados()` pode ser considerado como um exemplo de construtor (apesar de não seguir a sintaxe exata de um).

## Encapsulamento
As classes possuem como característica o controle de visibilidade, que pode ser:
- Público
  Qualquer elemento do sistema tenha acesso aos atributos/métodos dessa classe.
  
- Privado
  Somente elementos dessa mesma classe têm acesso aos seus atributos/métodos.

- Protegido
  Elementos dessa mesma classe (ou [classes filhas](https://pt.wikipedia.org/wiki/Heran%C3%A7a_(programa%C3%A7%C3%A3o_orientada_a_objetos))) têm acesso aos seus atributos/métodos.
  
A função geral do encapsulamento é a ocultação de dados para melhor funcionamento do software, facilitando o entendimento, reuso e manutenção do programa. Além disso, ele provê segurança, independência entre classes, aumenta o grau de abstração para o leitor do código e minimiza o acoplamento entre elas.
Em C++, podemos romper esse encapsulamento com o uso da diretiva `friend` portanto, devemos usá-la com cuidado.

--- 

## Mais conceitos de POO...
### Construtores e Destrutores
Um **construtor** é um método especial que **inicializa um objeto para um estado adequado no momento da sua criação**. Ele garante uma configuração correta de seus atributos (sendo eles tipos simples ou mesmo outros objetos).

Já um **destrutor** é um método destinado a liberar a memória ocupada por um determinado objeto, sendo geralmente chamados quando termina esse chega ao fim de seu tempo de vida. Em algumas linguagens, como C++, são essenciais devido à necessidade de desalocação de memória (por não terem um *garbage collector*).
O destrutor, diferentemente do construtor, é precedido por um `~`.

```cpp
class Foo { 

    ...
    
public:  
    Foo() {  
      n = 0;
      c = 'a';
      f = 0;
      s = "a";
      vet = new int[10];    
    }  
    
    ~Foo() {
      delete[] vet;  
    }
    
    ...
    
};
```

Por padrão, o C++ oferece:
- Construtor padrão (sem parâmetros) - apenas aloca espaço na memória para valores estáticos.

- Construtor de cópia - faz cópia do objeto, copiando apenas valores estáticos utilizando o operador de atribuição (`=`).

#### Inicialização de atributos em construtores
Atributos em classes são inicializados geralmente de duas maneiras: 
- Inicialização direta
  Na inicialização direta, os valores dos atributos são definidos diretamente no corpo do construtor.

- Inicialização em lista (repasse ao construtor do atributo)
  Na inicialização em lista, os valores dos atributos são definidos diretamente na chamada do construtor. A depender do compilador, essa inicialização pode ser a mais rápida.

```cpp
class myClass  
{  
  public:  
    myClass(float f, char a, bool b, int i);  
    
  private:  
    float mFloat;  
    char mCharacter;  
    bool mBoolean;  
    int mInteger;  
};

myClass::myClass(float f, char a,   
    bool b, int i) :
      // Inicialização em lista  
      mFloat( f ), mBoolean( true )  
{  
    // inicialização direta  
    mCharacter = a;  
    mInteger = 0;  
}
```

**OBS**: 
- Atributos constantes ou referências só podem ser inicializados em listas.
- Vetores ou EDs sem construtores só podem ser inicializados diretamente.

#### Construtor de cópia personalizado
Quando você usa atributos que são alocados dinamicamente (por exemplo, usando `new`), você precisa gerenciar manualmente a memória. Isso implica em garantir que a memória alocada seja liberada corretamente para evitar vazamentos de memória. Os ponteiros que apontam para esse novo endereço na memória são variáveis estáticas, contendo unicamente o endereço do elemento (onde está uma variável dinâmica).

Quando um objeto é copiado, o C++ realiza, através do construtor de cópia padrão, uma **cópia superficial**. Isso significa que se o objeto contém ponteiros para memória alocada dinamicamente, **apenas os endereços de memória serão copiados.** Assim, **tanto o objeto original quanto o novo objeto apontarão para a mesma área de memória**. 

Se um dos objetos for destruído (o que acontece automaticamente quando o tempo de vida de um deles chega ao fim), **a memória apontada será liberada, deixando o outro objeto com um ponteiro "pendurado" (*dangling pointer*)**, que **pode causar comportamento indefinido**, por não apontar para uma localização válida de memória. Geralmente, isso gera um erro de segmentação durante a compilação.

Uma forma de evitar problemas na hora de lidar com construtores em atributos alocados dinamicamente é criar um construtor de cópia personalizado:
```cpp
// Exemplo de construtor personalizado
Vetor(const vetor& vet) {
	cout << "Construtor de cópia personalizado!" << endl;
	tam = vet.tam;
	vetor = new int[tam];
	memcpy(vetor, vet.vetor, tam);
}
```

Quando você passa um objeto existente da mesma classe como argumento ao construtor, o compilador detecta que o construtor com o parâmetro `const Vetor&` deve ser chamado e, portanto, que se trata de uma construção de uma cópia do elemento original.
```cpp
Vetor v1;         // Chama o construtor padrão
Vetor v2 = v1;   // Chama o construtor de cópia padrão ou personalizado
```
Nesse caso, `v2` é uma cópia de `v1`, e a memória é gerida de forma que cada objeto tenha seu próprio conjunto de dados ao invés de `v2` apenas apontar para o endereço de memória de `v1` (o que é o padrão).

**OBS:**
- Parâmetro deve ser recebido como referência (para evitar cópia, chamada recursiva).
- Recomenda-se o uso de `const`, para evitar alterar os dados do objeto recebido como parâmetro.

```cpp
// Exemplo de assinatura:
Vetor(const Vetor& vet)
```

Além disso, precisamos também lidar com a sobrecarga do operador de atribuição, para evitar que um objeto existente, ao ser atribuído a outro objeto também já existente, aponte para a mesma região de memória do segundo. Veremos isso logo adiante na seção de sobrecarga de métodos.

### Sobrecarga de métodos
Em C++, podemos ter vários métodos com o mesmo nome, desde que sua assinatura (isto é, seus **parâmetros**) sejam diferentes umas das outras.

```cpp
// Exemplos de sobrecarga:
int foo(int x);  
float foo(float f);  
int foo(char c);  
float foo(float f, char c, int b);
```

Construtores também podem ser sobrecarregados, havendo diversas maneiras de se inicializar um objeto.

#### Sobrecarga de operadores
Além de podermos sobrecarregar métodos, em C++ também podemos sobrecarregar operadores, visando ditar o que cada um deles representa ao lidar com dois objetos da mesma classe. Nesse sentido, ao lidarmos com objetos alocados dinamicamente, por exemplo, é recomendável sobrecarregar o operador de atribuição, a fim de evitar que dois objetos da mesma classe partilhem o mesmo endereço de memória (que gera problemáticas já explicadas durante a explicação do construtor de cópia).

```cpp
// Sobrecarga do operador de atribuição

Vetor& Vetor::operator=(const Vetor& outro) {
	// Checa se estamos tentando atribuir o objeto a si mesmo (autoatribuição)
	if (this != &outro) { // Verifica se os endereços de memória são diferentes
		delete[] vetor; // Libera a memória antiga
		tam = outro.tam; // Atualiza o tamanho do vetor para o tamanho do objeto 'outro'
		vetor = new int[tam]; // Aloca memória suficiente para o novo tamanho
		memcpy(vetor, outro.vetor, tam * sizeof(int)); // Copia os elementos do vetor "outro" para o vetor atual
	}

	// Uso de * para desreferenciação
	return *this; // Retorna a referência para o objeto atual
}
```

**OBS:** `this`, em C++, é um ponteiro para o objeto atual (instância que está chamando o método). Como `this` é um ponteiro, ao usarmos `*this` estamos desreferenciando esse ponteiro, entrando em contato com seus valores propriamente ditos.

Em C++, a sobrecarga de operadores pode ser implementada de duas maneiras principais: como métodos de classe (funções internas/*inline*) ou como funções externas (geralmente declaradas como "amigas" da classe). A escolha entre essas abordagens depende do contexto e das necessidades específicas do desenvolvedor.
```cpp
// Sobrecarga como função interna
operator+(Vetor&  vetorA, Vetor& vetorB)

// Sobrecarga como função externa
Vetor::operator+(Vetor& vetorB)
```
