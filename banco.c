#include <stdio.h>
#include <stdlib.h>

int ler_numero();

int main(void) {
    int valor_saldo = 0;
    int valor_saque = 0;
    int valor_deposito = 0;

    int opcao;

    int historico[10];
    int qtd_transacoes = 0;
    
    while (true) {
        printf("\n--- Bem vindo - C Bank ---\n");
        printf("\nSaldo da conta: %d\n", valor_saldo);
        printf("\n1 - Saque\n");
        printf("2 - Depósito\n");
        printf("3 - Extrato\n");
        printf("4 - Sair\n");
        printf("\nAguardando sua resposta: ");

        opcao = ler_numero();

        switch (opcao) {
        case 1:
            printf("Digite o valor do saque: ");
            valor_saque = ler_numero();

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
            valor_deposito = ler_numero();

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

            int inicio = 0;
            int fim = qtd_transacoes;

            if (qtd_transacoes > 10) {
                inicio = qtd_transacoes - 10;
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

int ler_numero() {
    char texto[10];
    fgets(texto, 10, stdin);
    return atoi(texto);
}