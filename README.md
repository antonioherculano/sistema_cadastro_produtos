
# Sistema de Cadastro de Produtos (SGP)

## Sobre o projeto

Desenvolvi este projeto como parte da disciplina de Algoritmos e Programação I do curso de Ciência da Computação.

O objetivo é criar um sistema de cadastro de produtos utilizando a linguagem C e aplicar os conhecimentos adquiridos durante a disciplina.

## Funcionalidades

- Cadastrar produtos;
- Listar produtos cadastrados;
- Buscar produtos pelo ID;
- Atualizar produtos;
- Remover produtos.

## Conhecimentos aplicados

- Variáveis e tipos de dados;
- Estruturas condicionais (if, else e switch);
- Estruturas de repetição (for, while e do-while);
- Vetores;
- Struct;
- Manipulação de strings;
- Validação de dados.

## Regras do sistema

- Limite de 100 produtos cadastrados;
- ID único, inteiro e positivo;
- Nome não pode ser vazio;
- Preço maior que zero;
- Quantidade inteira e não negativa.

## Como executar

Compile o arquivo main.c:

    gcc main.c -o sgp

Execute o programa:

    ./sgp

## Limitações

Atualmente, os dados são armazenados na memória e são perdidos quando o programa é encerrado.

O sistema também possui limitações no tratamento de entradas excepcionais.

## Aprendizado

Durante o desenvolvimento deste projeto, pude praticar lógica de programação, manipulação de vetores, utilização de structs e implementação das operações de um CRUD.

Também aprendi sobre validação de entradas e tratamento do buffer utilizando scanf, fgets e getchar.
