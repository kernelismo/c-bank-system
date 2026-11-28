#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int saldo;
    int historico[10];
    int qtd_transacoes;

    char nome[50];
    char senha[20];
} Conta;

void menu_login(Conta contas[], int *total_contas);
void criar_conta(Conta contas[], int *total_contas);
int fazer_login(Conta contas[], int total_contas);
void menu_operacoes(Conta *c);
int ler_numero();
void fazer_saque(Conta *c);
void fazer_deposito(Conta *c);
void mostrar_extrato(Conta *c);

int main(void) {
    Conta contas[10];

    int total_contas = 0;
    int conta_logada = -1;

    int opcao;
    
    while (true) {
        if (conta_logada == -1) {
            menu_login(contas, &total_contas);

            opcao = ler_numero();

            switch (opcao) {
            case 1:
                criar_conta(contas, &total_contas);
                break;
            
            case 2:
                conta_logada = fazer_login(contas, total_contas);
                break;
            
            case 3:
                printf("\nSaindo do Sistema...\n");
                return 0;
            
            default:
                printf("Entrada inválida! Tente novamente...\n");
                break;
            }
        }
        else {
            menu_operacoes(&contas[conta_logada]);

            opcao = ler_numero();

            switch (opcao) {
            case 1:
                fazer_saque(&contas[conta_logada]);
                break;
        
            case 2:
                fazer_deposito(&contas[conta_logada]);
                break;

            case 3:
                mostrar_extrato(&contas[conta_logada]);
                break;

            case 4:
                printf("\nFazendo logout...\n");
                conta_logada = -1;
                break;
            
            case 5:
                printf("\nSaindo do sistema...\n");
                return 0;

            default:
                printf("Entrada inválida! Tente novamente...\n");
                break;
            }
        }
    }
}

void menu_login(Conta contas[], int *total_contas) {
    printf("\n--- Menu de Login - C Bank ---\n");
    printf("\n1 - Criar Conta\n");
    printf("2 - Login\n");
    printf("3 - Sair\n");
    printf("\nAguardando sua resposta: ");
}

void criar_conta(Conta contas[], int *total_contas) {
    printf("Digite seu nome: ");
    fgets(contas[*total_contas].nome, 50, stdin);
    contas[*total_contas].nome[strcspn(contas[*total_contas].nome, "\n")] = '\0';

    printf("Digite a senha: ");
    fgets(contas[*total_contas].senha, 20, stdin);
    contas[*total_contas].senha[strcspn(contas[*total_contas].senha, "\n")] = '\0';

    contas[*total_contas].saldo = 0;
    contas[*total_contas].qtd_transacoes = 0;
    (*total_contas)++;

    printf("Sua conta foi criada!\n");
}

int fazer_login(Conta contas[], int total_contas) {
    char nome_digitado[50];
    char senha_digitada[20];

    printf("Digite seu nome: ");
    fgets(nome_digitado, 50, stdin);
    nome_digitado[strcspn(nome_digitado, "\n")] = '\0';

    printf("Digite a senha: ");
    fgets(senha_digitada, 20, stdin);
    senha_digitada[strcspn(senha_digitada, "\n")] = '\0';

    for (int i = 0; i < total_contas; i++) {
        if (strcmp(nome_digitado, contas[i].nome) == 0 && strcmp(senha_digitada, contas[i].senha) == 0) {
            printf("\nLogin realizado!\n");
            return i;
        }
    }
    return -1;
}

void menu_operacoes(Conta *c) {
    printf("\n--- Menu de Operações - C Bank ---\n");
    printf("\nSaldo da conta: R$%d\n", c->saldo);
    printf("\n1 - Saque\n");
    printf("2 - Depósito\n");
    printf("3 - Extrato\n");
    printf("4 - Logout\n");
    printf("5 - Sair\n");
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