/*	PROJETO INTERDICIPLINAR 3 ~O~
	Data da ultima modificação: 06/06/2017	
	Ultimo a modificar: Wederson Cabral Domingues
	Descrição da modificação: 
		Inicio do programa, apenas foi criado algumas funções que serão utilizadas no decorrecor do projeto.			
		O que foi criado:
			As bibliotecas stdlib, stdio e time foram inseridas ao projeto.
			Struct Describe que guarda o inicio da arvore e diversos contadores que serão utilizados para armazenar as métricas.
			Struct Tree que guarda a arvore.
			Funcao Main que é o inicio do software e contem algumas estruturas para testar as demais funções criadas.
			Funcao sortOperation que sorteia uma operacao, tendenciando de forma linear crescente para inserção.
			Funcao sortNumber que sortei um numero aleatorio que esteja entre um determinado intervalo.
			Funcao startQTDS que inicializa os contadores em 0;
		O que foi removido:
			Nada c_c.
		O que foi modificado:
			Nadinha c_c.
*/
#include <stdlib.h>//Fornece diversas funções utilitarias da linguagem C.
#include <stdio.h>//Fornece funções de input e output.
#include <time.h>//Fornece as horas para que seja utilizada como semente da função rand.

struct Describe{
	struct Tree *start;//Begin of tree.
	int probOp;//Probability of operation insert be use.
	int qtdEInserted;//Number of elements inserted.
	int qtdERemoved;//Number of elements removed.
	int qtdENotRemoved;//Number of elements NOT removed.
	int qtdOInsert;//Number of time them insert operation be used.
	int qtdORemove;//Number of time them remove operation be used.
	int qtdSLRotation;//Number of simple left rotation.
	int qtdSRRotation;//Number of simple right rotation.
	int qtdDLRotation;//Number of double left rotation.
	int qtdDRRotation;//Number of double right rotation.
};

struct Tree{
	struct Tree *left;//Elemento a esquerda deste.
	struct Tree *right;//Elemento a direita deste.
};

int sortOperation(struct Describe *describe){
	int sortedN=rand()%9;
	if(sortedN%2==0 || sortedN<describe->probOp)
		return 1;
	describe->probOp++;
	return 0;

}

int sortNumber(int infNumber, int supNumber){
	return infNumber+(rand()%(1+supNumber - infNumber));
}

void startQTDS(struct Describe *describe){
	describe->probOp=0;
	describe->qtdEInserted=0;
	describe->qtdERemoved=0;
	describe->qtdENotRemoved=0;
	describe->qtdOInsert=0;
	describe->qtdORemove=0;
	describe->qtdSLRotation=0;	
	describe->qtdSRRotation=0;
	describe->qtdDLRotation=0;
	describe->qtdDRRotation=0;
}

int main(){
	srand(time(NULL));
	struct Describe describe;
	startQTDS(&describe);
	for (int i = 0; i < 9; i++){

		if(sortOperation(&describe))
			printf("Insercao c:");
		else
			printf("Remocao :c");
		printf("  -->%i\n",sortNumber(0, 1));
	}	
	return 0;
}