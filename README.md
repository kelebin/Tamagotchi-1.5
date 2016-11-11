Requisitos tamagotchi 1.5
- Estrutura de status  --- OK
- Menu interativo      --- OK
- Função Brincar       --- OK
- Função Dar Remédio   --- OK
- Função Doente        --- OK	
- Representação visual --- OK
- Mostrar Status       --- OK 
- Função Conversar     --- FALTA	
- Morte                --- OK
- Evoluir              --- FALTA
- Estrutura Comida     --- FALTA
- Salvar Progresso     --- FALTA



#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
int global=0;
typedef struct processos {
	int id;
	int prioridade;
	float t_duracao;
	float t_execucao;
	float t_espera;
} t_processo;

typedef struct no {
	t_processo dado;
	struct no *prox;
} t_no;

typedef struct fila {
	t_no* inicio;
	int quant_element;
	t_no* final;
} t_fila;


t_processo iniciar(int id);
t_fila * criaCabeca ();
int isVazia (t_fila * fila);
int inserir (t_fila *fila, t_processo valor);
t_processo remover (t_fila *fila);
t_no * criaNo();
int compara(t_processo dado1,t_processo dado2);
void exibir(t_fila * fila);
void JSF(t_fila fila);



int main (void) {
	t_fila*fila;
	fila=criaCabeca();
	int op,opp;
	
	do{

		printf("1->Adicionar processo\n");
		printf("2->Visualizar fila\n");
		printf("3->JSF\n");
		printf("4->Executar\n");
		printf("Opcao: ");
		scanf("%i",&op);
		
		switch(op){
			case 1:{printf("informe a quantidade de processos a serem adicionados");
				scanf("%d",&opp);
				global++;
				t_processo processo=iniciar((global));
				int teste=inserir(fila,processo);
				if(teste)
				printf("inserido na fila\n");
				else
				printf("error!!!!\n");
				system("pause");
				system("cls");
				break;
			}
			case 2:{
				system("cls");
				printf("fila:Pronto");
				exibir(fila);
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				JSF(*fila);
				exibir(fila);
				system("pause");
				system("cls");
				break;
			}
			case 4:{
					while(fila->inicio!=NULL){
						printf("a ser execultado\n");
						exibir(fila);
						printf("Executando  o Processo de ID: %i\n",fila->inicio->dado.id);
						//Sleep(fila->inicio->dado.t_duracao*1000);
						fila->inicio=fila->inicio->prox;
					}				
				system("pause");
				system("cls");
				break;
			}
			default:{
				printf("opcao invalida!!! \n");
				system("pause");
				system("cls");
				break;
			}
		}
		
	}while(op!=5);		

	system("pause");
}

t_processo iniciar(int id){
	t_processo proc;
	proc.id=id;
	proc.prioridade=rand()%10+1;
	proc.t_duracao=((float)rand()/(float)(RAND_MAX)) *11;
	printf("duracao:=%f\n\n",proc.t_duracao);
	proc.t_execucao=((float)rand()/(float)(RAND_MAX)) *11;
	printf("execucao:=%f\n\n",proc.t_execucao);
	proc.t_espera=0.0;
	return proc;
}

t_fila * criaCabeca () {
	t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

	if (fila) {
		fila->inicio = fila->final = NULL;
		fila->quant_element=0;
	}

	return fila;
}

t_no * criaNo() {
	t_no * no = (t_no*) malloc(sizeof(t_no));
	if (no)
		no->prox = NULL;

	return no;
}

int isVazia (t_fila * fila) {
	return (fila->quant_element == 0);
}

int inserir (t_fila *fila, t_processo valor) {
	t_no *novo;
	novo = criaNo();
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	if (isVazia(fila))
		fila->inicio = novo;
	else
		(fila->final)->prox = novo;
	fila->final = novo;
	fila->quant_element++;
	return 1;
}

t_processo remover (t_fila *fila) {
	t_no *aux;
	t_processo valor;
	if (isVazia(fila))
		return valor;
	valor = (fila->inicio)->dado;
	if (fila->inicio == fila->final)
		fila->final = NULL;
	aux = fila->inicio;
	fila->inicio = (fila->inicio)->prox;
	free(aux);
	fila->quant_element--;
	return valor;
}

int compara(t_processo dado1,t_processo dado2){
	if(dado1.t_duracao<dado2.t_duracao)
		return 1;
	else
		return 0;	
}

void exibir(t_fila * fila) {
	t_no*tmp=fila->inicio;
    int i;
    if (isVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("\nExibindo fila:\n");
	while(tmp!=NULL){
    	printf("Processo:ID:%i|	Prioridade:%i|	Tempo duracao:%.2f|	Tempo Espera:%.2f \n",tmp->dado.id,tmp->dado.prioridade,tmp->dado.t_duracao,tmp->dado.t_espera);
		if(tmp->prox==NULL)
			break;
		else
			tmp=tmp->prox;
}
}

void JSF(t_fila fila){
	t_processo aux;
	t_no* aux3=fila.inicio;
	t_no* aux2=fila.inicio;
	t_no* aux4=NULL;

	while(aux3!=NULL)
	{
		while(aux2!=NULL){
			if(aux3->dado.t_duracao>aux2->dado.t_duracao){
				aux=aux3->dado;
				aux3->dado=aux2->dado;
				aux2->dado=aux;
			
			}else{
			if(aux2->prox!=NULL)	
			aux2=aux2->prox;
			else
			break;
			}
		}
		if(aux3->prox!=NULL)
		aux3=aux3->prox;
		else
		break;
	}
}
