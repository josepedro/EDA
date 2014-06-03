#include <stdio.h>
#include <stdlib.h>

/*definir estrutura para nós da arvore*/
typedef struct no{
	int info;
	struct no *esquerda;
	struct no *direita;
}Raiz;



/*definir estrutura para a árvore*/
typedef struct arvore{
	Raiz *raiz;
}Arvore;

/*cria um nó de da tipo Raiz para adicionar no struct*/
Raiz* adiciona(int elemento) {
	Raiz *adiciona;
	adiciona = (Raiz*) malloc(sizeof(Raiz));
	adiciona->info = elemento;
	adiciona->esquerda = NULL;
	adiciona->direita = NULL;
	return adiciona;
}

/*inseri um elemento na arvore*/
void inserir(Raiz **raiz, int elemento) {

	if(*raiz == NULL) {
		*raiz = adiciona(elemento);
		printf("Nó inicial da arvore");	
	}else {
		if(elemento < (*raiz)->info){
			inserir(&((*raiz)->esquerda), elemento);
			printf("Inserido a esquerda");		
	}else if 
		(elemento > (*raiz)->info) {
		inserir(&((*raiz)->direita), elemento);
		printf("Inserido a direita");		
		}
	}
}

/*mostrar arvore em preOrdem*/
void preOrdem(Raiz *raiz) {
	if(raiz != NULL) {
		printf("%d ", raiz->info);
		preOrdem(raiz->esquerda);
		preOrdem(raiz->direita);
	}
}

/*mostrar arvore em Ordem*/
void emOrdem(Raiz *raiz) {
	if(raiz != NULL) {
		emOrdem(raiz->esquerda);
		printf("%d ", raiz->info);
		emOrdem(raiz->direita);
	}
}	

/*mostrar arvore em posOrdem*/
void posOrdem(Raiz *raiz) {
	if(raiz != NULL) {
		posOrdem(raiz->esquerda);
		posOrdem(raiz->direita);
		printf("%d ", raiz->info);
	}
}


int Altura (Raiz*  pNodo){
	
	int Alt_Esq, Alt_Dir;
	if (pNodo == NULL) return 0;
	else
	{ 
	  Alt_Esq = Altura (pNodo->esquerda);
	  Alt_Dir = Altura (pNodo->direita);
		if (Alt_Esq > Alt_Dir){
		return (1 + Alt_Esq);
		}
	else{
		return (1 + Alt_Dir);}}
}

int profundidade(Raiz *raiz) {
	int esquerda, direita;

	if(raiz == NULL) {
		return 0;
	}else {
		esquerda = 1+ profundidade(raiz->esquerda);
		direita = 1+ profundidade(raiz->direita);
		return esquerda>direita ? esquerda : direita;}
}

int contarFolhas(Raiz *raiz) {
	if(raiz == NULL) {
		return 0;
	}
	else {
		contarFolhas(raiz->direita);
		contarFolhas(raiz->esquerda);
		if(raiz->esquerda == NULL && raiz->direita == NULL) 
			return 1 + contarFolhas(raiz->direita) + contarFolhas(raiz->esquerda);
		else
			return contarFolhas(raiz->direita) + contarFolhas(raiz->esquerda);
	}
}
void mostrarFolhas(Raiz *raiz) {
	if(raiz != NULL) {
		mostrarFolhas(raiz->esquerda);
		mostrarFolhas(raiz->direita);
		if(raiz->direita == NULL && raiz->esquerda == NULL)
			printf("%d ", raiz->info);
	}
}

/**
typedef struct tnode* tnodePtr;
typedef struct tnode{
          tnodePtr esq, dir;
          int fb;
          char * info;
        } tnode;

*/

Raiz* rotacao_esquerda(Raiz* N1)
{
       Raiz* N2= N1->direita;
       if(N2->esquerda) N1->direita= N2->esquerda;
       else N1->direita=NULL;
       N2->esquerda=N1;
       return N2;
}





//Rotação simples a esquerda
void RotacaoSimples(Raiz *b){
  Raiz *a = b->esquerda;
  Raiz *t2 = a->direita;
  a->direita = b;
  b->esquerda = t2;
}
/**
//Rotação Simples a direita
tnodePtr RR(tnodePtr b){
  tnodePtr a = b->dir;
  tnodePtr t2 = a->esq;
  a->esq = b;
  b->dir = t2;
  return a;
}

//Rotação dupla esqueda direita
tnodePtr LR(tnodePtr c){
  tnodePtr b = c->esq;
  tnodePtr a = b->dir;
  tnodePtr t2 = a->dir;
  tnodePtr t3 = a->esq;
  c->esq = t2;
  b->dir = t3;
  a->dir = c;
  a->esq = b;
  return a;
}

*/



int main (void){
    int op;
    Raiz  *raiz ;	
    int valor;
   
    while(1){
      //  system ("cls");
        printf ("\nMenu");
        printf ("\n\n 1. Insere");
        printf ("\n 2. Exibe Altura");
        printf ("\n 3. Exibe Arvore em PreOrdem");
        printf ("\n 4. Exibe Arvore em PosOrdem");
        printf ("\n 5. Exibe Arvore em EmOrdem");
        printf ("\n 6. Rotação a esquerda");
	printf ("\n 7. Saber a Profundidade");
        printf ("\n 8. Contar as Folhas");
        printf ("\n 9. Mostrar as folhas");
        printf ("\n 10. Sair");        
	printf ("\n\n Entre a sua opcao: ");
        scanf ("%d",&op);
        fflush(stdin);
        switch (op) {
            case 1 : 
		
			printf("Informe o valor a ser inserido:");
			scanf("%d",&valor);				
			inserir(&raiz, valor);
                     break;
            case 2 : 
		    printf("Altura da  %d",Altura(raiz));
                     puts("\n\n");
                     //system("pause");
                     break;
            case 3 : preOrdem(raiz);
                     //system("pause");
                     break;
            case 4 : posOrdem(raiz);
                    // system("pause");
                     break;
            case 5 : 
	             emOrdem(raiz);
                     //system("pause");
                     break;
            case 6:
		rotacao_esquerda(raiz);
	    	break;
	    case 7:
		profundidade(raiz);
	    	break;
            case 8:
		contarFolhas(raiz);
	    	break;	
	    case 9:
		mostrarFolhas(raiz);
	    	break;





	    case 10 : exit(0);
            default: printf ("\nOpcao errada");
                    // system ("pause");
                     break;
        }
   }
}
