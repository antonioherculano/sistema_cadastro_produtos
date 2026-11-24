#include <stdio.h>


int main(){
    struct Produto {
     int id_produto;
    char nome[50];
    float preco;
    int quantidade;
};

    struct Produto produtos[100];
    int total = 0;

    printf("==========================\n");
    printf("  CADASTRO DE PRODUTOS\n");
    printf("==========================\n\n");
    
    int opcao;
    do{
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
            case 1:
            printf("\nCadastrar produto\n");
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

            if (produtos[total].nome[0] == '\n' || produtos[total].nome[0] == ' '){
                printf("Erro! O nome não pode estar vazio!\n");}

            } while(produtos[total].nome[0] == '\n' || produtos[total].nome[0] == ' ');
            
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
        printf("================================");
        printf("Produto cadastrado com sucesso!");
        printf("================================");

            total++;
            }
        

            break;
            
            case 2:
            printf("\nListar produto\n");break;

            case 3:
            printf("\nBuscar produto\n");break;

            case 4:
            printf("\nAtualizar produto\n");break;

            case 5:
            printf("\nRemover produto\n"); break;

            case 6:
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