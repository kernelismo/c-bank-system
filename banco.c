#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int saldo;
    int historico[10];
    int qtd_transacoes;
} Conta;

void menu(Conta *c);
int ler_numero();
void fazer_saque(Conta *c);
void fazer_deposito(Conta *c);
void mostrar_extrato(Conta *c);

int main(void) {
    Conta conta;
    conta.saldo = 0;
    conta.qtd_transacoes = 0;

    int opcao;
    
    while (true) {
        menu(&conta);

        opcao = ler_numero();

        switch (opcao) {
        case 1:
            fazer_saque(&conta);
            break;
        
        case 2:
            fazer_deposito(&conta);
            break;

        case 3:
            mostrar_extrato(&conta);
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

void menu(Conta *c) {
    printf("\n--- Bem vindo - C Bank ---\n");
    printf("\nSaldo da conta: R$%d\n", c->saldo);
    printf("\n1 - Saque\n");
    printf("2 - Depósito\n");
    printf("3 - Extrato\n");
    printf("4 - Sair\n");
    printf("\nAguardando sua resposta: ");
}

int ler_numero() {
    char texto[10];
    fgets(texto, 10, stdin);
    return atoi(texto);
}

void fazer_saque(Conta *c) {
    int valor_saque;

    printf("Digite o valor do saque: ");
    valor_saque = ler_numero();

    if (valor_saque <= c->saldo && valor_saque > 0) {
        c->saldo -= valor_saque;
        c->historico[c->qtd_transacoes % 10] = -valor_saque;
        c->qtd_transacoes++;
        printf("Saque realizado com sucesso!\n");
    }
    else {
        printf("Não é possível fazer o saque desse valor!\n");
    }
}

void fazer_deposito(Conta *c) {
    int valor_deposito;

    printf("Digite o valor do depósito: ");
    valor_deposito = ler_numero();

    if (valor_deposito > 0) {
        c->saldo += valor_deposito;
        c->historico[c->qtd_transacoes % 10] = valor_deposito;
        c->qtd_transacoes++;
        printf("Depósito realizado com sucesso!\n");
    }
    else {
        printf("Não é possível depositar esse valor!\n");
    }
}

void mostrar_extrato(Conta *c) {
    printf("\n--- EXTRATO ---\n");

    int inicio = 0;
    int fim = c->qtd_transacoes;

    if (c->qtd_transacoes > 10) {
        inicio = c->qtd_transacoes - 10;
    }

    for (int i = inicio; i < fim; i++) {
        printf("Transação %d: %d\n", i + 1, c->historico[i % 10]);
    }
}