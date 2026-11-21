# C Bank System

Sistema bancário de terminal desenvolvido em C puro. 

Este é o meu projeto laboratório: é onde eu concentro todo o meu aprendizado da linguagem C, aplicando na prática os conceitos que estudo diariamente.

## Funcionalidades (v1.2.1)
- Menu interativo com `switch-case` (opções numéricas).
- Operação de Saque (com validação de saldo e valor).
- Operação de Depósito (com validação de valor).
- Exibição automática do saldo no topo do menu.
- Extrato de transações: histórico das últimas 10 operações usando vetores e buffer circular.
- Leitura segura de dados: função customizada com `fgets` e `atoi` para evitar bugs de loop com entradas inválidas (letras).

## Como compilar e rodar
```bash
gcc -Wall -Wextra -pedantic -o banco banco.c
./banco