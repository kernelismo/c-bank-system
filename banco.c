#include <stdio.h>

int main(void) {
    int valor_saldo = 0;
    int valor_saque = 0;
    int valor_deposito = 0;

    int opcao;
    
    while (true) {
        printf("\n--- Bem vindo - C Bank ---\n");
        printf("\nSaldo da conta: %d\n", valor_saldo);
        printf("\n1 - Saque\n");
        printf("2 - Depósito\n");
        printf("3 - Sair\n");
        printf("\nAguardando sua resposta: ");

        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o valor do saque: ");
            scanf("%i", &valor_saque);
            getchar();

            if (valor_saque <= valor_saldo && valor_saque > 0) {
                valor_saldo -= valor_saque;
                printf("Saque realizado com sucesso!\n");
            }

            else {
                printf("Não é possível fazer o saque desse valor!\n");
            }
            break;
        
        case 2:
            printf("Digite o valor do depósito: ");
            scanf("%i", &valor_deposito);
            getchar();

            if (valor_deposito > 0) {
                valor_saldo += valor_deposito;
                printf("Depósito realizado com sucesso!\n");
            }

            else {
                printf("Não é possível depositar esse valor!\n");
            }
            break;
        
        case 3:
            printf("\nSaindo do Sistema...\n");
            return 0;

        default:
            printf("Entrada inválida! Tente novamente...\n");
            break;
        }
    }
}