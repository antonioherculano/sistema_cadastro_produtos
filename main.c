#include <stdio.h>

int main(){
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
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
}        
        printf("\n");
    
        switch (opcao){
            case 1:
            printf("\nCadastrar produto\n");break;
            
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