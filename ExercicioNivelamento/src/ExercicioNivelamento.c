/*
 ============================================================================
 Name        : ExercicioNivelamento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL); //Limpa a saída de vídeo

	char op;
	int valorMinimo,
	numero,
	num1, num2, result;

	do {
		printf("\nDigite sua  opção: ");
		//fflush(stdin); // Faz a limpeza do ponteiro de entrada
		scanf(" %c", &op); // Deixar um espaço antes do % também limpa o ponteiro de entrada mas depende da IDE.
		op = toupper(op); // Torna as letras maiúsculas (está na biblioteca "ctype")

//		if (op == 'A' || op == 'B' || op == 'C') {
		if (op >= 'A' && op <= 'C') { // Faz a pesquisa de acordo com a tabela ASCII (A = 65, B= 66, C = 67)
//			if (op == 'B') {
//				valorMinimo = 0;
//			} else {
//				valorMinimo =1;
//			}
//
			valorMinimo = (op == 'B') ?0 : 1;

					do {
						printf("\nDigite um número: ");
						scanf("%i", &numero);

						if (numero < valorMinimo) {
							printf("\nInválido");
						}
					} while (numero < valorMinimo);
		}


		switch (op) {
			case 'A':
				printf("\nExibir o %iº termo de Fibonacci.", numero);
				num1 = 0;
				num2 = 1;
				for (int i = 0; i < numero; i++) {
					result = num1 + num2;
					printf("\t%i", result); // "\t" da um tab/espaço na hora de imprimir
					num2 = num1;
					num1 = result;
				}
				break;
			case 'B':
				printf("\n%i!", numero);
				result = 1;
				if(numero != 0) { //Não permite que o 0 (zero) seja selecionado
					do {
						result *= numero; // "*=" conteúdo próprio x conteúdo que está vindo (result = result * numero;)
						numero--;
					}while (numero > 1);
				}
				printf("\t%i", result);
				break;
			case 'C':
				printf("\nSoma dos pares de 0 até %i = ", numero);
//				num1 = 2;
//				result = 0;
//				while (num1 <= numero) {
//					result += num1; //result = result + num1;
//					num1 += 2; // num1 = num1 + 2;
//				}

//				result = 0;
//				for (num1 = 2; num1 <= numero; num1++) {
//					if (num1 % 2 == 0) {
//						result += num1;
//					}
//				}

				result = 0;
				for (num1 = 2; num1 <= numero; num1+=2) {
						result += num1;
				}
				printf("\t%i", result);
				break;
			case 'D':
				printf("\nPrograma finalizado");
			default:
				printf("\nOpção inválida");
		}
	} while (op != 'D');

	return 0;
}
