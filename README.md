# C Bank System

Sistema bancário de terminal desenvolvido em C puro. 

Este é o meu projeto laboratório: é onde eu concentro todo o meu aprendizado da linguagem C, aplicando na prática os conceitos que estudo diariamente.

## Funcionalidades (v4.0.0)
- **Sistema de Login e Cadastro:** Criação de contas com nome e senha, e autenticação segura.
- **Múltiplas Contas:** Suporte para até 10 contas independentes, com dados isolados.
- **Menu de Operações:** Interface interativa para realizar transações bancárias.
- **Saque e Depósito:** Operações com validação de saldo e valor.
- **Extrato de Transações:** Histórico das últimas 10 operações usando buffer circular.
- **Leitura Segura:** Função customizada para evitar loops infinitos com entradas inválidas (letras).

## Tecnologias e Conceitos Aplicados
- Linguagem C
- Estruturas de decisão (`if/else`, `switch-case`)
- Laços de repetição (`while`, `for`)
- **Vetores e Arrays de Structs:** Gerenciamento de múltiplos usuários.
- **Structs:** Agrupamento de dados (`saldo`, `historico`, `qtd_transacoes`, `nome`, `senha`).
- **Modularização:** Código dividido em funções para facilitar a manutenção.
- **Ponteiros e Passagem por Referência:** Uso de `&` e `*` para alterar dados reais na memória.
- **Manipulação de Strings:** Uso de `fgets`, `strcspn` e `strcmp` para segurança e comparação de textos.

## Como compilar e rodar
```bash
gcc -Wall -Wextra -pedantic -o banco banco.c
./banco