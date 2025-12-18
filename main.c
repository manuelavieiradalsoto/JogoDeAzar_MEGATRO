#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MIN 6
#define MAX 10
#define LIMITE 60

int num[MAX];
int quantidade;
int num_sorteado[6];
int num_acertado[6];
int cont = 0;
char esc;


void fun_Numeros_Aleatorios(){

    printf("\nDigite a quantidade de numeros a apostar (6 a 10): ");
    scanf("%d", &quantidade);

    while (quantidade < MIN || quantidade > MAX){
        printf("\nValor invalido! Digite entre 6 e 10: ");
        scanf("%d", &quantidade);
    }

    printf("\nDigite as dezenas (1 a 60):\n");

    for (int i=0;i<quantidade;i++){
        scanf("%d", &num[i]);

        while (num[i] < 1 || num[i] > LIMITE){
            printf("\nNumero invalido! Digite entre 1 e 60: ");
            scanf("%d", &num[i]);
        }

        // Verificar repetição
        for (int j=0;j<i;j++){
            if (num[i] == num[j]){
                printf("\nNumero repetido! Digite outro: ");
                i--;
                break;
            }
        }
    }

    // Ordenar números
    for (int i=0;i<quantidade-1; i++){
        for (int j=i+1;j<quantidade;j++){
            if (num[i] > num[j]) {
                int aux = num[i];
                num[i] = num[j];
                num[j] = aux;
            }
        }
    }

    printf("\nNumeros apostados:\n");
    for (int i=0; i<quantidade; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void fun_Sorteia_Numeros(){
    cont = 0;
    srand(time(NULL));

    for (int i=0;i<6;i++){
        int valido;
        do{
            valido=1;
            num_sorteado[i] = 1 + rand() % LIMITE;

            for (int j=0;j<i;j++){
                if (num_sorteado[i] == num_sorteado[j]){
                    valido = 0;
                    break;
                }
            }
        } while (!valido);
    }

    printf("\nNumeros sorteados:\n");
    for (int i= 0;i<6;i++) {
        printf("%d ", num_sorteado[i]);
    }
    printf("\n");

    // Verificar acertos
    for (int i=0;i<6;i++){
        for (int j=0; j<quantidade; j++){
            if (num_sorteado[i] == num[j]) {
                num_acertado[cont++] = num[j];
            }
        }
    }

    if (cont>0){
        printf("\nNumeros acertados:");
        for (int i=0;i<cont; i++) {
            printf("%d ", num_acertado[i]);
        }
        printf("\n");
    }

    switch (cont){
        case 1: 
        printf("Voce fez 1 acerto!\n"); 
        break;

        case 2: 
        printf("Voce fez 2 acertos!\n"); 
        break;

        case 3: 
        printf("Voce fez 3 acertos!\n"); 
        break;

        case 4: 
        printf("QUADRA!\n"); 
        break;

        case 5: 
        printf("QUINA!\n"); 
        break;

        case 6: 
        printf("SENA!\n"); 
        break;

        default: 
        printf("Nenhum acerto. Tente novamente!\n");
    }
}

int main() {

    char nome[100];

    printf("Bem-vindo ao MEGA-Trô!\n\n");
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    do {
        fun_Numeros_Aleatorios();
        fun_Sorteia_Numeros();

        printf("\nDeseja apostar novamente? (ESC para sair): ");
        esc = getch();
    } while (esc != 27);

    printf("\nPrograma encerrado.\n");
    printf("Feito por: Manuela Vieira Dalsoto - Turma 4223\n");

    return 0;
}
