#include <iostream>
using namespace std;

//
// ---------------------- PARTE A - RECURSIVIDADE ----------------------
//

// Função 1: fatorial
int f1(int n) {
    if (n == 0) return 1;
    else return n * f1(n - 1);
}

// Função 2: função recursiva customizada
int f2(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    else return f2(n - 1) + 2 * f2(n - 2);
}

// Função 3: impressão recursiva
int f3(int n) {
    if (n == 0) {
        cout << "Zero ";
    } else {
        cout << n << " ";
        cout << n << " ";
        f3(n - 1);
    }
    return 0;
}

// Questão 2: soma de pares até N
int somaPares(int n) {
    if (n < 0) return 0;
    if (n % 2 != 0) n--; // garante que seja par
    if (n == 0) return 0;
    return n + somaPares(n - 2);
}

// Questão 3: produto a * b
int produto(int a, int b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    return a + produto(a, b - 1);
}

// --------------------------------------------------------------------
// ---------------------- PARTE B - LISTA ENCADEADA -------------------
// --------------------------------------------------------------------

struct No {
    int info;
    No* prox;
};

// Criar lista vazia
No* criarLista() {
    return NULL;
}

// Inserir elemento no início
No* inserirInicio(No* lista, int valor) {
    No* novo = new No;
    novo->info = valor;
    novo->prox = lista;
    return novo;
}

// Percorrer a lista
void imprimirLista(No* lista) {
    No* aux = lista;
    while (aux != NULL) {
        cout << aux->info << " -> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

// Buscar elemento
bool buscar(No* lista, int valor) {
    No* aux = lista;
    while (aux != NULL) {
        if (aux->info == valor) return true;
        aux = aux->prox;
    }
    return false;
}

// Retornar número de elementos
int contar(No* lista) {
    if (lista == NULL) return 0;
    return 1 + contar(lista->prox);
}

// --------------------------------------------------------------------
// ---------------------- PILHA ---------------------------------------
// --------------------------------------------------------------------

struct TipoPilha {
    No* topo;
    int tamanho;
};

// Inicializar pilha
TipoPilha* criarPilha() {
    TipoPilha* p = new TipoPilha;
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

// Inserir elemento (push)
void push(TipoPilha* p, int valor) {
    No* novo = new No;
    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

// Remover elemento (pop)
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

// Listar elementos da pilha
void imprimirPilha(TipoPilha* p) {
    No* aux = p->topo;
    while (aux != NULL) {
        cout << aux->info << " -> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

// Verificar se elemento está na pilha
bool buscarPilha(TipoPilha* p, int valor) {
    No* aux = p->topo;
    while (aux != NULL) {
        if (aux->info == valor) return true;
        aux = aux->prox;
    }
    return false;
}

// --------------------------------------------------------------------
// ---------------------- LISTA DUPLAMENTE ENCADEADA ------------------
// --------------------------------------------------------------------

struct NoDuplo {
    int info;
    NoDuplo* prox;
    NoDuplo* ant;
};

// Inserir no início da lista duplamente encadeada
NoDuplo* inserirInicioDuplo(NoDuplo* inicio, int valor) {
    // Impede duplicados
    NoDuplo* aux = inicio;
    while (aux != NULL) {
        if (aux->info == valor) {
            cout << "Elemento já existe!\n";
            return inicio;
        }
        aux = aux->prox;
    }

    NoDuplo* novo = new NoDuplo;
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = inicio;

    if (inicio != NULL) inicio->ant = novo;

    return novo;
}

// Impressão da lista duplamente encadeada
void imprimirDuplo(NoDuplo* inicio) {
    NoDuplo* aux = inicio;
    while (aux != NULL) {
        cout << aux->info << " <-> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

// Buscar elemento
bool buscarDuplo(NoDuplo* inicio, int valor) {
    NoDuplo* aux = inicio;
    while (aux != NULL) {
        if (aux->info == valor) return true;
        aux = aux->prox;
    }
    return false;
}

// Excluir elemento
NoDuplo* excluirDuplo(NoDuplo* inicio, int valor) {
    NoDuplo* aux = inicio;
    while (aux != NULL && aux->info != valor) {
        aux = aux->prox;
    }
    if (aux == NULL) return inicio;

    if (aux->ant != NULL) aux->ant->prox = aux->prox;
    else inicio = aux->prox;

    if (aux->prox != NULL) aux->prox->ant = aux->ant;

    delete aux;
    return inicio;
}

// --------------------------------------------------------------------
// ---------------------- MAIN ----------------------------------------
// --------------------------------------------------------------------

int main() {
    cout << "=== PARTE A ===\n";
    cout << "f1(5) = " << f1(5) << endl;
    cout << "f2(5) = " << f2(5) << endl;
    cout << "f3(3): "; f3(3); cout << endl;
    cout << "Soma pares ate 9: " << somaPares(9) << endl;
    cout << "Produto 4*3 = " << produto(4, 3) << endl;

    cout << "\n=== LISTA SIMPLES ===\n";
    No* lista = criarLista();
    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 30);
    imprimirLista(lista);
    cout << "Buscar 20: " << buscar(lista, 20) << endl;
    cout << "Numero de elementos: " << contar(lista) << endl;

    cout << "\n=== PILHA ===\n";
    TipoPilha* pilha = criarPilha();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    imprimirPilha(pilha);
    cout << "Pop: " << pop(pilha) << endl;
    imprimirPilha(pilha);
    cout << "Buscar 2 na pilha: " << buscarPilha(pilha, 2) << endl;

    cout << "\n=== LISTA DUPLAMENTE ENCADEADA ===\n";
    NoDuplo* lista2 = NULL;
    lista2 = inserirInicioDuplo(lista2, 5);
    lista2 = inserirInicioDuplo(lista2, 10);
    lista2 = inserirInicioDuplo(lista2, 15);
    imprimirDuplo(lista2);
    lista2 = excluirDuplo(lista2, 10);
    imprimirDuplo(lista2);

    return 0;
}

