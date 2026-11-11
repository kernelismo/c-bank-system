#include <stdio.h>

int main(void)
{
    int valor_saldo = 0;
    int valor_saque = 0;
    int valor_deposito = 0;

    char menu;
    
    while (true)
    {
        printf("\n### MENU ###\n");
        printf("Y - Saque\n");
        printf("D - Depósito\n");
        printf("S - Sair\n");
        printf("Aguardando sua resposta: ");

        scanf(" %c", &menu);

        if (menu == 'y' || menu == 'Y') 
        {
            printf("Digite o valor do saque: ");
            scanf("%i", &valor_saque);
            getchar();

            if (valor_saque <= valor_saldo && valor_saque > 0)
            {
                valor_saldo -= valor_saque;
                printf("Seu saldo agora é: R$%i\n", valor_saldo);
            }

            else
            {
                printf("Não é possível fazer o saque desse valor!\n");
            }

        }

        else if (menu == 'd' || menu == 'D')
        {
            printf("Digite o valor do depósito: ");
            scanf("%i", &valor_deposito);
            getchar();

            if (valor_deposito > 0)
            {
                valor_saldo += valor_deposito;
                printf("Depósito realizado! Seu saldo é: R$%i\n", valor_saldo);
            }

            else
            {
                printf("Não é possível depositar esse valor!\n");
            }
        }

        else if (menu == 's' || menu == 'S')
        {
            printf("Saindo do Sistema...\n");
            break;
        }

        else
        {
            printf("Entrada inválida!\n");
        }
    }

    return 0;
}