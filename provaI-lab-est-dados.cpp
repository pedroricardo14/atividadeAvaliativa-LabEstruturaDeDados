#include <iostream>
using namespace std;

// ============================================================================
// ---------------------- PARTE A - RECURSIVIDADE -----------------------------
// ============================================================================

// Função 1: fatorial
/*
 * Calcula o fatorial de um número n usando recursão.
 * Exemplo: f1(5) = 5 * 4 * 3 * 2 * 1 = 120
 */
int f1(int n) {
    if (n == 0)
        return 1; // caso base: 0! = 1
    else
        return n * f1(n - 1); // passo recursivo
}

// Função 2: função recursiva customizada
/*
 * Gera uma sequência numérica baseada na relação:
 * f(n) = f(n - 1) + 2 * f(n - 2)
 * com f(0) = 1 e f(1) = 1
 */
int f2(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    else return f2(n - 1) + 2 * f2(n - 2);
}

// Função 3: impressão recursiva
/*
 * Imprime os números de n até 0, repetindo cada número duas vezes.
 * Exemplo: f3(3) → 3 3 2 2 1 1 Zero
 */
int f3(int n) {
    if (n == 0) {
        cout << "Zero ";
    } else {
        cout << n << " ";
        cout << n << " ";
        f3(n - 1); // chamada recursiva para n - 1
    }
    return 0;
}

// Questão 2: soma de pares até N
/*
 * Soma todos os números pares de 0 até n.
 * Exemplo: somaPares(9) = 8 + 6 + 4 + 2 = 20
 */
int somaPares(int n) {
    if (n < 0) return 0;
    if (n % 2 != 0) n--; // garante que o número seja par
    if (n == 0) return 0; // caso base
    return n + somaPares(n - 2); // soma recursiva
}

// Questão 3: produto a * b
/*
 * Simula a multiplicação de a por b usando apenas somas.
 * Exemplo: produto(4,3) = 4 + 4 + 4 = 12
 */
int produto(int a, int b) {
    if (b == 0) return 0; // caso base
    if (b == 1) return a; // caso base
    return a + produto(a, b - 1); // soma recursiva
}

// ============================================================================
// ---------------------- PARTE B - LISTA ENCADEADA SIMPLES -------------------
// ============================================================================

// Estrutura básica de um nó de lista encadeada
struct No {
    int info;   // valor armazenado
    No* prox;   // ponteiro para o próximo nó
};

// Criar lista vazia
No* criarLista() {
    return NULL; // lista vazia apontando para NULL
}

// Inserir elemento no início da lista
No* inserirInicio(No* lista, int valor) {
    No* novo = new No;
    novo->info = valor;
    novo->prox = lista;
    return novo;
}

// Percorrer e imprimir a lista
void imprimirLista(No* lista) {
    No* aux = lista;
    while (aux != NULL) {
        cout << aux->info << " -> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

// Buscar elemento na lista
bool buscar(No* lista, int valor) {
    No* aux = lista;
    while (aux != NULL) {
        if (aux->info == valor) return true;
        aux = aux->prox;
    }
    return false;
}

// Contar número de elementos na lista (recursivo)
int contar(No* lista) {
    if (lista == NULL) return 0; // caso base
    return 1 + contar(lista->prox); // soma 1 e chama o próximo
}

// ============================================================================
// ---------------------- PILHA (LIFO - Last In First Out) --------------------
// ============================================================================

struct TipoPilha {
    No* topo;    // ponteiro para o topo da pilha
    int tamanho; // contador de elementos
};

// Inicializar pilha
TipoPilha* criarPilha() {
    TipoPilha* p = new TipoPilha;
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

// Inserir elemento na pilha (push)
void push(TipoPilha* p, int valor) {
    No* novo = new No;
    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

// Remover elemento do topo da pilha (pop)
int pop(TipoPilha* p) {
    if (p->topo == NULL) {
        cout << "Pilha vazia!\n";
        return -1;
    }
    No* temp = p->topo;
    int valor = temp->info;
    p->topo = temp->prox;
    delete temp;
    p->tamanho--;
    return valor;
}

// Imprimir pilha
void imprimirPilha(TipoPilha* p) {
    No* aux = p->topo;
    while (aux != NULL) {
        cout << aux->info << " -> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

// Buscar elemento na pilha
bool buscarPilha(TipoPilha* p, int valor) {
    No* aux = p->topo;
    while (aux != NULL) {
        if (aux->info == valor) return true;
        aux = aux->prox;
    }
    return false;
}

// ============================================================================
// ---------------------- LISTA DUPLAMENTE ENCADEADA --------------------------
// ============================================================================

struct NoDuplo {
    int info;
    NoDuplo* prox;
    NoDuplo* ant;
};

// Inserir no início da lista duplamente encadeada
NoDuplo* inserirInicioDuplo(NoDuplo* inicio, int valor) {
    // Verifica se o elemento já existe
    NoDuplo* aux = inicio;
    while (aux != NULL) {
        if (aux->info == valor) {
            cout << "Elemento já existe!\n";
            return inicio;
        }
        aux = aux->prox;
    }

    // Cria um novo nó
    NoDuplo* novo = new NoDuplo;
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = inicio;

    if (inicio != NULL)
        inicio->ant = novo;

    return novo;
}

// Imprimir lista duplamente encadeada
void imprimirDuplo(NoDuplo* inicio) {
    NoDuplo* aux = inicio;
    while (aux != NULL) {
        cout << aux->info << " <-> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

// Buscar elemento na lista duplamente encadeada
bool buscarDuplo(NoDuplo* inicio, int valor) {
    NoDuplo* aux = inicio;
    while (aux != NULL) {
        if (aux->info == valor) return true;
        aux = aux->prox;
    }
    return false;
}

// Excluir elemento da lista duplamente encadeada
NoDuplo* excluirDuplo(NoDuplo* inicio, int valor) {
    NoDuplo* aux = inicio;

    while (aux != NULL && aux->info != valor) {
        aux = aux->prox;
    }

    if (aux == NULL) return inicio;

    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;
    else
        inicio = aux->prox;

    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;

    delete aux;
    return inicio;
}

// ============================================================================
// ---------------------- MAIN -----------------------------------------------
// ============================================================================

int main() {
    int n, a, b, valor;

    cout << "=== PARTE A ===\n";
    cout << "Digite um numero para f1 (fatorial): ";
    cin >> n;
    cout << "f1(" << n << ") = " << f1(n) << endl;

    cout << "\nDigite um numero para f2 (sequencia personalizada): ";
    cin >> n;
    cout << "f2(" << n << ") = " << f2(n) << endl;

    cout << "\nDigite um numero para f3 (impressao recursiva): ";
    cin >> n;
    cout << "f3(" << n << "): ";
    f3(n);
    cout << endl;

    cout << "\nDigite um numero para soma de pares: ";
    cin >> n;
    cout << "Soma pares ate " << n << ": " << somaPares(n) << endl;

    cout << "\nDigite dois numeros para o produto (a * b):\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Produto " << a << " * " << b << " = " << produto(a, b) << endl;

    // --------------------------------------------------------------------
    cout << "\n=== LISTA SIMPLES ===\n";
    No* lista = criarLista();
    int qtd;
    cout << "Quantos elementos deseja inserir na lista? ";
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> valor;
        lista = inserirInicio(lista, valor);
    }
    imprimirLista(lista);

    cout << "Digite um valor para buscar na lista: ";
    cin >> valor;
    cout << (buscar(lista, valor) ? "Valor encontrado!\n" : "Valor nao encontrado!\n");
    cout << "Numero de elementos: " << contar(lista) << endl;

    // --------------------------------------------------------------------
    cout << "\n=== PILHA ===\n";
    TipoPilha* pilha = criarPilha();
    cout << "Quantos elementos deseja empilhar? ";
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> valor;
        push(pilha, valor);
    }
    imprimirPilha(pilha);

    cout << "Deseja remover (pop) um elemento da pilha? (1=sim / 0=nao): ";
    cin >> valor;
    if (valor == 1) {
        cout << "Elemento removido: " << pop(pilha) << endl;
        imprimirPilha(pilha);
    }

    cout << "Digite um valor para buscar na pilha: ";
    cin >> valor;
    cout << (buscarPilha(pilha, valor) ? "Encontrado!\n" : "Nao encontrado!\n");

    // --------------------------------------------------------------------
    cout << "\n=== LISTA DUPLAMENTE ENCADEADA ===\n";
    NoDuplo* lista2 = NULL;
    cout << "Quantos elementos deseja inserir? ";
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> valor;
        lista2 = inserirInicioDuplo(lista2, valor);
    }
    imprimirDuplo(lista2);

    cout << "Digite um valor para excluir da lista duplamente encadeada: ";
    cin >> valor;
    lista2 = excluirDuplo(lista2, valor);
    imprimirDuplo(lista2);

    return 0;
}
