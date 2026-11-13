#include <stdio.h>

int main(void) {
    int valor_saldo = 0;
    int valor_saque = 0;
    int valor_deposito = 0;

    char menu;
    
    while (true) {
        printf("\n### MENU - C Bank ###\n");
        printf("S - Saque\n");
        printf("D - Depósito\n");
        printf("V - Saldo\n");
        printf("N - Sair\n");
        printf("Aguardando sua resposta: ");

        scanf(" %c", &menu);

        switch (menu) {
        case 's':
        case 'S':
            printf("Digite o valor do saque: ");
            scanf("%i", &valor_saque);
            getchar();

            if (valor_saque <= valor_saldo && valor_saque > 0) {
                valor_saldo -= valor_saque;
                printf("Seu saldo agora é: R$%i\n", valor_saldo);
            }

            else {
                printf("Não é possível fazer o saque desse valor!\n");
            }
            break;
        
        case 'd':
        case 'D':
            printf("Digite o valor do depósito: ");
            scanf("%i", &valor_deposito);
            getchar();

            if (valor_deposito > 0) {
                valor_saldo += valor_deposito;
                printf("Depósito realizado! Seu saldo é: R$%i\n", valor_saldo);
            }

            else {
                printf("Não é possível depositar esse valor!\n");
            }
            break;

        case 'v':
        case 'V':
            printf("O seu saldo é R$: %i\n", valor_saldo);
            break;
        
        case 'n':
        case 'N':
            printf("Saindo do Sistema...\n");
            return 0;

        default:
            printf("Entrada inválida! Tente novamente...\n");
            break;
        }
    }
}