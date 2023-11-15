#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>


typedef struct Lista{
    int id;
    int dado;
    struct Lista* proximo;
}Lista;

int _id = 0;

void inserir(int conteudo, Lista **p);
Lista * buscaPorId (int id, Lista *p);

int main() {
    setlocale(LC_ALL, "");

    Lista *p = NULL;

    char resposta;

    do{
        printf("Deseja inserir um numero?(s/n)");
        fflush(stdin);
        scanf("%c", &resposta);
        if (resposta=='s'){
            int num;
            printf("Escreva um numero: ");
            fflush(stdin);
            scanf("%i", &num);

            inserir(num, &p);
        }
        else if(resposta!='s' && resposta!='n'){
            printf("Reposta errada!\n");
        }


    }while(resposta!='n');

//    lista *novo;
//    novo = malloc(sizeof (Lista));
//    int id = 2;
//    int *t=&id;
//    printf("%p\n",t);
//    printf("%p\n",&id);

//    printf("Escreva o nome: ");
//
//    struct Lista lista;
//    scanf("%s", lista.nome);
//
//    printf("O nome é %s", lista.nome);

    printf("Digite um id para ser buscado: ");
    fflush(stdin);
    int respId;
    scanf("%i", &respId);

    if(buscaPorId(respId, p) == NULL){
        printf("Id nao encontrado");
    }
    else{
        printf("O numero eh %d", p->dado);
    }

    printf("\nObrigado por usar nosso sistema!");

    return 0;
}


void inserir(int conteudo, Lista **p) {
    Lista *novo = malloc(sizeof(Lista));
    Lista *ultimo = *p; 
    novo->dado = conteudo;
    _id++;
    novo->id = _id;
    novo->proximo = NULL; // Novo nó será o último, então próximo é NULL

    // Se a lista estiver vazia, o novo nó será o primeiro nó
    if (*p == NULL) {
        *p = novo;
        return;
    }

    // Caso contrário, percorre a lista até o final
    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }

    // Insere o novo nó no final da lista
    ultimo->proximo = novo;
    printf("Inserido com sucesso!\n");
}


Lista * buscaPorId (int id, Lista *p){
   Lista *atual = p;
   while(atual != NULL){
       if(atual->id == id){
           return atual;
       }
       atual = atual -> proximo;
   }
   return NULL;
}