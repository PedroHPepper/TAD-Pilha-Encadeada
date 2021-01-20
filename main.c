#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{

    int elemento; /* componente da pilha */

    struct pilha *proximo; /* Aponta para a proxima posicao de mémoria*/

}pilha;

pilha *primeiro, *topo, *Novapilha, *LiberaMemoria; /* Variaveis de manipulacao da pilha*/

void pop();
void Criapilha();
void Imprimir();
void push();

int main(){

    int opcao;
    do{

        printf("1------------Inserir Elemento na pilha\n");
        printf("2-----------Imprimir Elementos da pilha\n");
        printf("3------------Exlcuir Elemento do topo da pilha \n");
        printf("4------------Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){


            case 1:

                push();
                break;

            case 2:

                Imprimir();
                break;

            case 3:

                pop();
                break;

            case 4:

                return 0;

        }

    }while(opcao != 4);

    return 0;
}


void pop(){


	if(primeiro==NULL){
        	printf("pilha vazia\n\n");
	}else{
        	topo = primeiro;
        	primeiro = primeiro->proximo;
        	free(topo);
	}
}

void Criapilha(){
    if(primeiro==NULL){
        primeiro=(struct pilha *)malloc(sizeof(pilha)); /* Cria um n� na pilha*/
	primeiro->proximo = NULL;
    }else{
        printf("pilha ja criada. \n\n");
    }
}

void Imprimir(){

     if(primeiro==NULL){

        printf(" pilha vazia\n");
    }else{

        topo=primeiro;
        printf("Elementos Inseridos na pilha\n\n");

        while(topo!=NULL){
            printf("%d", topo->elemento);
            printf("\n\n");
            topo=topo->proximo;
        }
    }

}

void push(){
    int i;
    topo=primeiro;


    do{
        if(topo==NULL){
            Criapilha();
            topo=primeiro;
            printf("Insira um elemento na pilha: \t");
            scanf("%d", &topo->elemento);
        }else{
            topo = (struct pilha *)malloc(sizeof(pilha));
            printf("Insira um elemento na pilha: \t");
            scanf("%d", &topo->elemento);
            topo->proximo = primeiro;
            primeiro = topo;
        }

        printf("\n");
        printf("deseja inserir outro elemento na pilha 1/0:  \t");
        scanf("%d", &i);

        printf("\n");


    }while(i!=0);
}
