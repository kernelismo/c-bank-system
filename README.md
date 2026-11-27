# C Bank System

Sistema bancário de terminal desenvolvido em C puro. 

Este é o meu projeto laboratório: é onde eu concentro todo o meu aprendizado da linguagem C, aplicando na prática os conceitos que estudo diariamente.

## Funcionalidades (v3.0.0)
- Menu interativo com `switch-case`.
- Operação de Saque (com validação de saldo).
- Operação de Depósito (com validação de valor).
- Exibição automática do saldo no topo do menu.
- **Extrato de transações:** histórico das últimas 10 operações usando vetores e buffer circular.
- **Leitura segura de dados:** função customizada com `fgets` e `atoi` para evitar bugs de loop com entradas inválidas (letras).

## Tecnologias e Conceitos Aplicados
- Linguagem C
- Estruturas de decisão (`if/else`, `switch-case`)
- Laços de repetição (`while`, `for`)
- Vetores (arrays) e manipulação de índices
- **Structs:** Agrupamento dos dados da conta (`saldo`, `historico`, `qtd_transacoes`).
- **Modularização:** Separação da lógica em funções (`fazer_saque`, `fazer_deposito`, `mostrar_extrato`, `menu`).
- **Ponteiros e Passagem por Referência:** Uso de `Conta *c` para que as funções alterem os dados reais na memória.

## Como compilar e rodar
```bash
gcc -Wall -Wextra -pedantic -o banco banco.c
./banco