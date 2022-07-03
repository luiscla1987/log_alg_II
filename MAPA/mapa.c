#include <stdio.h>
#include <stdlib.h> //Utiliza o comando para limapar tela S.O Windows 'system("cls");' S.O baseado em UNIX system("clear");
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define max 3  //número máximo de cadastros

bool VerificarIgualdadeCPF(char cpfBusca[], char cpfCadastro[]);

int codigo = 0;

typedef struct dados{
    char nome[60], cpf[15], vacina[30], data[10];
    int lote;
} cadastro;

cadastro Dados[max]; 

int MenuOpcao(){
    
    int menu;

    system("clear");

    printf("====================\n"); 
    printf("SELECIONE UMA OPÇÃO\n");
    printf("====================\n");
    printf("1 - CADASTRAR VACINA\n");
    printf("2 - LISTAR APLICAÇÕES\n");
    printf("3 - CONSULTAR POR CPF\n");
    printf("4 - SAIR\n");
    printf("====================\n");
    printf("DIGITE UMA OPÇÃO:\n");

    scanf("%d", &menu);
    getchar();
    fflush(stdin);
    return menu;
}

void CadastrarVacina(){

    codigo = codigo + 1;

    system("clear");

    printf("CÓDIGO: %d", codigo);
    printf("\n======================\n\n");
    
    printf("DIGITE O NOME:\n");
    scanf("%60[^\n]", Dados[codigo].nome);
    getchar();
    fflush(stdin);
    printf("DIGITE O CPF (###.###.###-##):\n");
    scanf("%15[^\n]", Dados[codigo].cpf);
    getchar();
    fflush(stdin);
    printf("DIGITE A VACINA:\n");
    scanf("%30[^\n]", Dados[codigo].vacina);
    getchar();
    fflush(stdin);
    printf("DIGITE A DATA APLICAÇÃO(DD/MM/AAAA):\n");
    scanf("%10[^\n]", Dados[codigo].data);
    getchar();
    fflush(stdin);
    printf("DIGITE O LOTE (SOMENTE NUMEROS):\n");
    scanf("%d", &Dados[codigo].lote);
    getchar();
    fflush(stdin);
    printf("Cadastrado com sucesso.");
    
}

void ListarAplicacoes(){
    system("clear");
    printf(" \n ** LISTAR APLICAÇÕES ** \n\n");

    for (int i=1; i < max; i++){
        if((strlen(Dados[i].nome) != 0) && (strlen(Dados[i].cpf) != 0) && (strlen(Dados[i].vacina) != 0) && (strlen(Dados[i].data) != 0)){
            printf("CÓDIGO: %d\n", i);
            printf("NOME: %s\n", Dados[i].nome);
            printf("CPF: %s\n", Dados[i].cpf);
            printf("VACINA: %s\n", Dados[i].vacina);
            printf("DATA: %s\n", Dados[i].data);
            printf("LOTE: %d\n", Dados[i].lote);
            printf("==================================\n");
        }
    }
}

void ConsultarCPF(){
    system("clear");
    char cpfBusca[15];
    bool cpcfEncontrado = false;

    printf("DIGITE O CPF (###.###.###-##):\n");
    scanf("%15[^\n]", cpfBusca);
    getchar();
    fflush(stdin);

    for (int i=1; i < max; i++){
        if(VerificarIgualdadeCPF(cpfBusca, Dados[i].cpf)){
            system("clear");
            printf("CÓDIGO: %d\n", i);
            printf("NOME: %s\n", Dados[i].nome);
            printf("CPF: %s\n", Dados[i].cpf);
            printf("VACINA: %s\n", Dados[i].vacina);
            printf("DATA: %s\n", Dados[i].data);
            printf("LOTE: %d\n", Dados[i].lote);
            cpcfEncontrado = true;
        }
    }
    if(!cpcfEncontrado){
        system("clear");
        printf("CPF NÃO ENCONTRADO \n");
    }
    
}

bool VerificarIgualdadeCPF(char cpfBusca[], char cpfCadastro[]){

    if(sizeof(cpfCadastro) != sizeof(cpfBusca)){
        return false;
    }
    for(int i = 0; i < 15; i++){
        if(cpfBusca[i] != cpfCadastro[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]){
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    int opcao = MenuOpcao();

    while(opcao < 4 && opcao > 0){

        switch(opcao){
            case 1:
            {   
                CadastrarVacina();
                getchar();
                break;
            }
            case 2:
            {   
                ListarAplicacoes();
                getchar();
                break;
            }
            case 3:
            {
                ConsultarCPF();   
                getchar();
                break;
            }
        }
        opcao = MenuOpcao();
    }

    getchar();
    return(0);
} 
    

