#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){
    struct Produto {
     int id_produto;
    char nome[50];
    float preco;
    int quantidade;
};

    struct Produto produtos[100];
    int total = 0;
    system("clear");
    printf("==========================\n");
    printf("  CADASTRO DE PRODUTOS\n");
    printf("==========================\n\n");
    
    int opcao;
    do{
        system("clear");
        printf("1- Cadastrar produto\n");
        printf("2- Listar produto\n");
        printf("3- Buscar produto\n");
        printf("4- Atualizar produto\n");
        printf("5- Remover produto\n");
        printf("6- Sair\n");
        printf("Escolha uma opcao: \n");
        if (scanf("%i", &opcao) != 1) {
            opcao = 7;
            while(getchar()!='\n');
        }        
        printf("\n");
        switch (opcao){

            case 1: {
                system("clear");
                printf("================================\n");
                printf("        Cadastrar produto       \n");
                printf("================================\n");
                if (total >= 100){
                    printf("Capacidade maxima!");}
                else{
                    int duplicado;
                    int leitura;

                    do{
                        duplicado = 0;
                        int entrada_invalida;
                        do{
                            entrada_invalida = 0;

                            printf("Digite o ID: ");
                            leitura = scanf("%d", &produtos[total].id_produto);
                            int caractere;
                            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                                if (caractere != ' ') {
                                    entrada_invalida = 1;
                                }
                            }

                            if (leitura != 1 || entrada_invalida == 1) {
                                printf("Erro! o ID precisa ser inteiro!\n");
                            } else {
                                if(produtos[total].id_produto <= 0) {
                                    printf("Erro! o ID deve ser positivo\n");}
                            } 
                        } while (leitura != 1 || entrada_invalida == 1 || produtos[total].id_produto <= 0);

                    
                        for (int i = 0; i < total; i++){
                            if(produtos[i].id_produto == produtos[total].id_produto) {
                                duplicado = 1;
                                break;
                            }
                        }
                        if (duplicado == 1) {
                            printf("Erro: Este Id já está cadastrado! Tente novamente!\n");
                        }
                    } while(duplicado == 1);

                    do{
                        printf("Digite o nome: ");

                        fgets(produtos[total].nome, sizeof(produtos[total].nome),stdin);
                        produtos[total].nome[strcspn(produtos[total].nome, "\n")] = '\0';

                        if (produtos[total].nome[0] == '\0' || produtos[total].nome[0] == ' ') {
                            printf("Erro! O nome não pode estar vazio!\n");
                        }

                    } while (produtos[total].nome[0] == '\0' || produtos[total].nome[0] == ' ');            
            
                    int leitura_preco;
                    int entrada_invalida_preco;
                    do{
                        entrada_invalida_preco = 0;
                        printf("Digite o valor unitario: ");

                        leitura_preco = scanf("%f", &produtos[total].preco);

                        int caractere;
                        while ((caractere = getchar()) != '\n' && caractere != EOF) {
                            if (caractere != ' ') {
                            entrada_invalida_preco = 1;
                            }
                        }

                        if (leitura_preco != 1 || entrada_invalida_preco == 1) {
                            printf("O valor precisa ser numerico!\n");
                        } else {
                                if(produtos[total].preco <= 0){
                                    printf("O valor precisa ser positivo!\n");}}

                    } while (leitura_preco != 1 || entrada_invalida_preco == 1 || produtos[total].preco <= 0);
            
                    int leitura_qtd;
                    int entrada_invalida_qtd;
                    do{
                        entrada_invalida_qtd = 0;
                        printf("Digite a quantidade: ");
                        leitura_qtd = scanf("%d", &produtos[total].quantidade);
                        int caractere;
                        while ((caractere = getchar()) != '\n' && caractere != EOF) {
                            if (caractere != ' ') {
                                entrada_invalida_qtd = 1;
                            }
                        }
                        if (leitura_qtd != 1 || entrada_invalida_qtd == 1) {
                            printf("A quantidade precisa ser do tipo inteiro!\n");
                        }else {
                            if(produtos[total].quantidade < 0){
                                printf("A quantidade n~ao pode ser negativa!\n");}
                        }
                    } while (leitura_qtd != 1 || entrada_invalida_qtd == 1 || produtos[total].quantidade < 0);
                    printf("================================\n");
                    printf("Produto cadastrado com sucesso!\n");
                    printf("================================\n\n");

                    total++;
                    printf("Pressione ENTER para voltar ao menu");
                    getchar();
                }   
                    break; 
            }

            case 2: {
                system("clear");
                printf("\nListar produtos\n");
                if (total == 0) {
                    printf("Nenhum produto cadastrado!\n");
                } else {
                    printf("===============================\n");
                    printf("       Lista de produtos       \n");
                    printf("===============================\n");

                    for (int i = 0; i < total; i++){
                        printf("ID: %d\n", produtos[i].id_produto);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Preco: R$ %.2f\n", produtos[i].preco);
                        printf("Quantidade: %d\n", produtos[i].quantidade);
                        printf("------------------------------------------------------------------\n");
                    }
                    printf("Total de produtos: %d\n", total);
                }   
                printf("\nPressione ENTER para voltar ao menu");
                getchar();
                getchar();
                break;
            }

            case 3: {
                system("clear");
                printf("===============================\n");
                printf("         Buscar produto        \n");
                printf("===============================\n");
            
                int id_busca;
                int encontrado = 0;
                int leitura_busca;
                int entrada_invalida_busca;
                int caractere;

                if (total == 0) {
                    printf("Nenhum produto cadastrado!\n");
                    while ((caractere = getchar()) != '\n' && caractere != EOF) {}
                } else {
                    do{
                        entrada_invalida_busca = 0;
                        printf("Digite o ID do produto: ");
                        leitura_busca = scanf("%d", &id_busca);
                        while ((caractere = getchar()) != '\n' && caractere != EOF) {
                            if (caractere != ' ') {
                            entrada_invalida_busca = 1;
                            }
                        }
                        if (leitura_busca != 1 || entrada_invalida_busca == 1) {
                            printf("Erro! O ID precisa ser inteiro!\n");
                        } else {
                                if (id_busca <= 0) {
                                printf("Erro! O ID precisa ser positivo!\n");
                                }
                            }
                    } while (leitura_busca != 1 || entrada_invalida_busca == 1 || id_busca <= 0);

                    for (int i = 0; i < total; i++) {
                        if (produtos[i].id_produto == id_busca) {
                            encontrado = 1;
                            printf("\nProduto encontrado!\n");
                            printf("ID: %d\n", produtos[i].id_produto);
                            printf("Nome: %s\n", produtos[i].nome);
                            printf("Preco: R$ %.2f\n", produtos[i].preco);
                            printf("Quantidade: %d\n", produtos[i].quantidade);
                            printf("======================================\n");
                            break;
                        }
                    }
                    if (encontrado == 0) {
                        printf("Produto nao encontrado!\n");
                    }
                }
                printf("\nPressione ENTER para voltar ao menu");
                getchar();
                break; 
            }

            case 4: {
                system("clear");

                printf("================================\n");
                printf("       Atualizar produto        \n");
                printf("================================\n");

                int id_atualizar;
                int encontrado = 0;
                int posicao = -1;
                int leitura;
                int entrada_invalida;
                int caractere;

                if (total == 0) {
                    printf("Nenhum produto cadastrado!\n");

                while ((caractere = getchar()) != '\n' && caractere != EOF) {}

                } else {
                    do {
                        entrada_invalida = 0;

                        printf("Digite o ID do produto: ");
                        leitura = scanf("%d", &id_atualizar);

                        while ((caractere = getchar()) != '\n' && caractere != EOF) {
                        if (caractere != ' ') {
                            entrada_invalida = 1;
                        }
                        }

                        if (leitura != 1 || entrada_invalida == 1) {
                            printf("Erro! O ID precisa ser inteiro!\n");
                        } else {
                            if (id_atualizar <= 0) {
                                printf("Erro! O ID precisa ser positivo!\n");
                            }
                        }           

                    } while (leitura != 1 || entrada_invalida == 1 || id_atualizar <= 0);

                    for (int i = 0; i < total; i++) {
                        if (produtos[i].id_produto == id_atualizar) {
                            encontrado = 1;
                            posicao = i;
                            break;
                        }
                    }

                    if (encontrado == 0) {
                        printf("Produto nao encontrado!\n");
                    } else {

                        printf("\nProduto encontrado!\n");
                        printf("ID: %d\n", produtos[posicao].id_produto);
                        printf("Nome atual: %s\n", produtos[posicao].nome);
                        printf("Preco atual: R$ %.2f\n", produtos[posicao].preco);
                        printf("Quantidade atual: %d\n", produtos[posicao].quantidade);

                        struct Produto atualizado = produtos[posicao];
                        do {
                            printf("\nDigite o novo nome: ");

                             if (fgets(atualizado.nome, sizeof(atualizado.nome), stdin) == NULL) {
                                printf("Erro na leitura do nome!\n");
                                break;
                            }

                            atualizado.nome[strcspn(atualizado.nome, "\n")] = '\0';

                            if (atualizado.nome[0] == '\0' || atualizado.nome[0] == ' ') {
                            printf("Erro! O nome nao pode estar vazio!\n");
                            }

                        } while (atualizado.nome[0] == '\0' || atualizado.nome[0] == ' ');
                        do {
                            entrada_invalida = 0;

                            printf("Digite o novo preco: ");
                            leitura = scanf("%f", &atualizado.preco);

                            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                            if (caractere != ' ') {
                                entrada_invalida = 1;
                            }
                            }

                            if (leitura != 1 || entrada_invalida == 1) {
                                printf("Erro! O preco precisa ser numerico!\n");
                            } else {
                                if (atualizado.preco <= 0) {
                                    printf("Erro! O preco precisa ser positivo!\n");
                                }
                            }

                        } while (leitura != 1 || entrada_invalida == 1 || atualizado.preco <= 0);
                        do {
                            entrada_invalida = 0;

                            printf("Digite a nova quantidade: ");
                            leitura = scanf("%d", &atualizado.quantidade);

                            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                            if (caractere != ' ') {
                                entrada_invalida = 1;
                            }
                            }

                            if (leitura != 1 || entrada_invalida == 1) {
                                printf("Erro! A quantidade precisa ser inteira!\n");
                            } else {
                                if (atualizado.quantidade < 0) {
                                    printf("Erro! A quantidade nao pode ser negativa!\n");
                                }
                            }

                        } while (leitura != 1 || entrada_invalida == 1 || atualizado.quantidade < 0);

                        produtos[posicao] = atualizado;

                        printf("================================\n");
                        printf("Produto atualizado com sucesso!\n");
                        printf("================================\n");
                    }
                }

                printf("\nPressione ENTER para voltar ao menu");
                getchar();
                break;
            }
            case 5:
            system("clear");
            printf("\nRemover produto\n"); break;

            case 6:
            system("clear");
            printf("Sair\n\n");
            printf("==========================\n");
            printf("    Finalizando APP       \n");
            printf("==========================\n");break;
            
            default:
            printf("Opcao invalida! Selecione uma opcao disponivel!\n");
        }
    } while(opcao != 6);

    return 0;
}