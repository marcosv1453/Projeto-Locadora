#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
char keyboard[BUFSIZ]; // Prótotipo de função para limpeza do buffer.

//------ Variável globais -------/
int qtd_filmes = 0, i = 0; //Variáveis globais para poderem serem acessadas por qualquer função
int consulta; // Variável responsável por armazenar o identificador que é fornecido pelo usuário.
int escolha; // Variável responsável pelo controle de opções da navegação.
int ja_cadastrou = 0; //Variável responsável por controla o cadastro de filmes, você só poderá cadastrar os filmes uma vez.
//----- Variável globais -------/

struct st_filmes{


    int identificador;
    char titulo[40];
    int ano_de_producao;
    char genero[15];
} filmes[0]; // Inicializando o vetor com 0 de tamanho




void f_cadastrar_filme(){



    printf("Diga-me quantos filmes você deseja cadastrar na locadora: ");
    scanf("%d",&qtd_filmes);
    filmes[qtd_filmes]; // Alocando o tamanho do vetor

    printf("\n======Cadastro de filmes=======\n\n");
    ++ja_cadastrou;
    for(i = 0 ; i < qtd_filmes ; i++){



        printf("Diga-me o identificador do [%i] filme: ", i+1);
        setbuf(stdin,keyboard);                      // Tirando o lixo da entrada
        scanf("%d", &filmes[i].identificador);

        printf("Diga-me o título do [%i] filme: ", i+1);
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s",filmes[i].titulo);        // Pegando o input da forma correta, sem o \n

        printf("Diga-me o ano de produção do [%i] filme: ", i+1);
        setbuf(stdin,keyboard);
        scanf("%d",&filmes[i].ano_de_producao);

        if(filmes[i].ano_de_producao > 2019 || filmes[i].ano_de_producao < 1895){  // Faz com que o usuário não digite um ano de produção que não exista.

            printf("\nAno de produção inválido! \n\n");
            system("pause");
            exit(1);
        }

        printf("Diga-me o gênero do [%i] filme: ", i+1);
        setbuf(stdin,keyboard);
        scanf("%14[^\n]s",filmes[i].genero);

        printf("\n\n");

    }
    for(i = 0 ; i < qtd_filmes ; i++){  //Segundo for para tratamento de erros


        if(filmes[i].identificador == filmes[i+1].identificador ){  // Se os identificadores forem iguais encerra o programa.

            printf("Você inseriu filmes com identificadores iguais.\n");
            system("pause");
            exit(1);
        }
    }



    system("pause"); // Dar uma pausa antes de executar a próxima linha de comando
    system("cls");   // Limpa o console
    main();          // Chamada de função


}
void f_listar_filmes(){


    printf("\n======Listar os filmes=======\n\n");


    for(i = 0 ; i < qtd_filmes ; i++){


        if(filmes[i].identificador == filmes[i+1].identificador){  // Condição para não mostrar o filme apagado.

            continue;
        }
        printf("Filme [%i]:  \n",i+1);
        printf("Título: [%s] \n", filmes[i].titulo);
        printf("Gênero: [%s] \n", filmes[i].genero);
        printf("Ano de produção: [%d]\n", filmes[i].ano_de_producao);
        printf("Identificador: [%d]\n", filmes[i].identificador);
        printf("\n\n");
    }

    system("pause");
    system("cls");
    main();

}

void f_consultar_filmes(){


    printf("\n======Consultar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser consultado: ");
    scanf("%d",&consulta);

    printf("\n");

    for(i = 0 ; i < qtd_filmes ; i++){


        if(filmes[i].identificador == filmes[i+1].identificador){  

            // Deixar sem nenhuma ação.
        }

        if(consulta == filmes[i].identificador){

            printf("O filme existe em nosso catálogo. \n");
            break;
        }
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1){  //Só executará a ação quando o laço for terminar

            printf("O filme não existe em nosso catálogo. \n");
        }
    }
    printf("\n\nConsultar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha);

    if(escolha == 1){

        system("pause");
        system("cls");
        f_consultar_filmes();
    }
    else if(escolha == 2){

        system("pause");
        system("cls");
        main();
    }
    else{

        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_filmes();

    }


}

void f_visualizar_filme(){


    printf("\n======Visualizar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser visualizado: ");
    scanf("%d",&consulta);

    printf("\n");

    for(i = 0 ; i < qtd_filmes ; i++){


        if(consulta == filmes[i].identificador){

            printf("Filme [%i]:  \n",i+1);
            printf("Título: [%s] \n", filmes[i].titulo);
            printf("Gênero: [%s] \n", filmes[i].genero);
            printf("Ano de produção: [%d]\n", filmes[i].ano_de_producao);
            printf("Identificador: [%d]\n", filmes[i].identificador);
            printf("\n\n");
            break;

        }
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){

            printf("Filme não encontrado. \n");
        }
    }
    printf("\n\nVisualizar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha);

    if(escolha == 1){

        system("pause");
        system("cls");
        f_visualizar_filme();
    }
    else if(escolha == 2){

        system("pause");
        system("cls");
        main();
    }
    else{

        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_filme();
    }

}

void f_editar_filme(){



    printf("\n======Editar os filmes=======\n\n");

    printf("O que você deseja? [1] - Atualizar filme | [2] - Excluir filme | [3] - Sair : ");
    scanf("%d",&escolha);

    if(escolha == 1){


        printf("\nDiga-me o identificador do filme a ser atualizado: ");
        scanf("%d",&consulta);
        printf("\n");
        for(i = 0 ; i < qtd_filmes ; i++){


            if(consulta == filmes[i].identificador){


                printf("Diga-me o identificador do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%d", &filmes[i].identificador);

                printf("Diga-me o título do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s",filmes[i].titulo);

                printf("Diga-me o ano de produção do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%d",&filmes[i].ano_de_producao);

                if(filmes[i].ano_de_producao > 2019 || filmes[i].ano_de_producao < 1895){    

                    printf("\nAno de produção inválido! \n\n");
                    system("pause");
                    exit(1);
                }

                printf("Diga-me o gênero do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%14[^\n]s",filmes[i].genero);
                printf("\nFilme atualizado com sucesso! \n");
                break;
            }
            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){

                printf("Filme não encontrado... \n");
            }
        }


        printf("\n\nAtualizar novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha);

        if(escolha == 1){

            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){

            system("pause");
            system("cls");
            main();
        }
        else{

            printf("Valor não reconhecido... \n");
            exit(1);
        }
    }

    else if(escolha == 2){



        printf("Diga-me o identificador do filme a ser excluído: ");
        scanf("%d",&consulta);

        for(i = 0 ; i < qtd_filmes ; i++){


            if(consulta == filmes[i].identificador){                // "Apagando" Os filmes da Random Acess Memory

                strcpy(filmes[i].genero,filmes[i+1].genero);
                strcpy(filmes[i].titulo,filmes[i+1].titulo);
                filmes[i].ano_de_producao = filmes[i+1].ano_de_producao;
                filmes[i].identificador = filmes[i+1].identificador;
                printf("Filme excluído com sucesso! \n");
                break;
            }

            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){

                printf("Filme não encontrado... \n");
            }
        }


        printf("\n\nExcluir novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha);

        if(escolha == 1){

            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){

            system("pause");
            system("cls");
            main();
        }
        else{

            printf("Valor não reconhecido... \n");
            exit(1);
        }

    }

    else if(escolha == 3){

        system("cls");
        main();
    }

    else{

        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_filme();
    }

}



int main(){


    setlocale(LC_ALL,"Portuguese"); // Permite acentos e outras regras da língua portuguesa em strings.

    if(ja_cadastrou == 0){ //Se o usuário ainda não tiver cadastrado o filme, o primeiro menu aparece.

        printf("O que você deseja fazer? \n");
        printf("[1] - Cadastrar filme \n");
        printf("[2] - Editar filme    \n");
        printf("[3] - Listar filmes   \n");
        printf("[4] - Visualizar filme \n");
        printf("[5] - Consultar filme  \n");
        printf("[6] - Sair \n");
        printf("Diga-me a opção: ");
        scanf("%d",&escolha);

        switch(escolha){




        case 1:
            system("cls");
            f_cadastrar_filme();
            break;
        case 2:
            system("cls");
            f_editar_filme();
            break;
        case 3:
            system("cls");
            f_listar_filmes();
            break;
        case 4:
            system("cls");
            f_visualizar_filme();
            break;
        case 5:
            system("cls");
            f_consultar_filmes();
            break;
        case 6:
            break;
        default:
            printf("Opção não reconhecida... \n");
            system("pause");
            system("cls");
            main();

        }
    }
    else{ //Senão o segundo menu entra em ação.

        printf("O que você deseja fazer? \n");
        printf("[1] - Editar filme    \n");
        printf("[2] - Listar filmes   \n");
        printf("[3] - Visualizar filme \n");
        printf("[4] - Consultar filme  \n");
        printf("[5] - Sair \n");
        printf("Diga-me a opção: ");
        scanf("%d",&escolha);

        switch(escolha){




        case 1:
            system("cls");
            f_editar_filme();
            break;
        case 2:
            system("cls");
            f_listar_filmes();
            break;
        case 3:
            system("cls");
            f_visualizar_filme();
            break;
        case 4:
            system("cls");
            f_consultar_filmes();
            break;
        case 5:
            break;
        default:
            printf("Opção não reconhecida... \n");
            system("pause");
            system("cls");
            main();
        }

        return 0;
    }
}
