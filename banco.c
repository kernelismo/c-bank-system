#include <stdio.h>

int main(void) {
    int historico[10];
    int qtd_transacoes = 0;

    int inicio = 0;
    int fim = qtd_transacoes;

    int valor_saldo = 0;
    int valor_saque = 0;
    int valor_deposito = 0;

    int opcao;
    
    while (true) {
        printf("\n--- Bem vindo - C Bank ---\n");
        printf("\nSaldo da conta: %d\n", valor_saldo);
        printf("\n1 - Saque\n");
        printf("2 - Depósito\n");
        printf("3 - Extrato\n");
        printf("4 - Sair\n");
        printf("\nAguardando sua resposta: ");

        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o valor do saque: ");
            scanf("%i", &valor_saque);
            getchar();

            if (valor_saque <= valor_saldo && valor_saque > 0) {
                valor_saldo -= valor_saque;

                historico[qtd_transacoes % 10] = -valor_saque;
                qtd_transacoes++;
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

                historico[qtd_transacoes % 10] = valor_deposito;
                qtd_transacoes++;
                printf("Depósito realizado com sucesso!\n");
            }

            else {
                printf("Não é possível depositar esse valor!\n");
            }
            break;

        case 3:
            printf("\n--- EXTRATO ---\n");

            if (qtd_transacoes > 10) {
                inicio = qtd_transacoes - 10;
                fim = qtd_transacoes;
            }

            for (int i = inicio; i < fim; i++) {
                printf("Transação %d: %d\n", i + 1, historico[i % 10]);
            }
            break;

        case 4:
            printf("\nSaindo do Sistema...\n");
            return 0;

        default:
            printf("Entrada inválida! Tente novamente...\n");
            break;
        }
    }
}