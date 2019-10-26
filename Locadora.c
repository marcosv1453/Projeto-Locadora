#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
char keyboard[BUFSIZ]; // Prótotipo de função para limpeza do buffer.

//------ Documentação -------//

/**
*@author ---
*@version ---
*@since ---
*/

//------ Documentação -------//

//------ Variável globais -------//

int qtd_filmes = 0, qtd_clientes = 0; //Aloca o tamanho do vetor.
int i = 0, j = 0; // Variáveis usadas no FOR ( I = Filmes ) ( J = Clientes )
int consulta; // Variável responsável por armazenar o identificador que é fornecido pelo usuário.
char cliente_consulta[40]; // Variável responsável por armazenar o nome do cliente que é fornecido pelo usuário.
int escolha; // Variável responsável pelo controle das opções da navegação.
int ja_cadastrou = 0, ja_cadastrou_cliente = 0; //Variáveis responsáveis por controlar o cadastro de filmes e clientes, você só poderá cadastrar uma vez.
char *guardar; // Variável que armazena o que existe depois do @ dentro de uma string
char validar_email[1][30] = {"@gmail.com"}; // Variável criada para validar email do usuário <- 30 de tamanho para evitar erros de conflito com a variável email

//----- Variável globais -------//

struct st_filmes{



    int identificador;
    char titulo[40];
    int ano_de_producao;
    char genero[15];
} filmes[0]; // Inicializando o vetor com 0 de tamanho

struct st_clientes{


    char nome[40];
    char cpf[12]; // Tamanho extra para o terminador \0
    char email[30]


} clientes[0];


void f_cadastrar_filme(){




    printf("Diga-me quantos filmes você deseja cadastrar na locadora: ");
    scanf("%d",&qtd_filmes);
    filmes[qtd_filmes]; // Alocando o tamanho do vetor

    printf("\n======Cadastro de filmes=======\n\n");

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

        if(filmes[i].ano_de_producao > 2019 || filmes[i].ano_de_producao < 1895){     // Faz com que o usuário não digite um ano de produção que não exista.


            printf("\nAno de produção inválido! \n\n");
            system("pause");
            system("cls");
            f_cadastrar_filme();
        }

        printf("Diga-me o gênero do [%i] filme: ", i+1);
        setbuf(stdin,keyboard);
        scanf("%14[^\n]s",filmes[i].genero);

        printf("\n\n");

    }
    for(i = 0 ; i < qtd_filmes ; i++){   //Segundo for para tratamento de erros



        if(filmes[i].identificador == filmes[i+1].identificador ){   // Se os identificadores forem iguais, encerre o programa.


            printf("Você inseriu filmes com identificadores iguais.\n");
            system("pause");
            system("cls");
            f_cadastrar_filme();
        }
    }


   ++ja_cadastrou;
    system("pause"); // Dar uma pausa antes de executar a próxima linha de comando
    system("cls");   // Limpa o console
    menu_filme();    // Chamada de função


}

void f_cadastrar_cliente(){


    printf("Diga-me quantos clientes você deseja cadastrar na locadora: ");
    scanf("%d",&qtd_clientes);
    clientes[qtd_clientes];

    printf("\n======Cadastro de cliente=======\n\n");

    for(j = 0 ; j < qtd_clientes ; j++){




        printf("Diga-me o nome do [%i] cliente: ", j+1);
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s", clientes[j].nome);

        printf("Diga-me o cpf do [%i] cliente(Sem pontuação): ", j+1);
        setbuf(stdin,keyboard);
        scanf("%11[^\n]s",clientes[j].cpf);

        if(strlen(clientes[j].cpf) != 11){  //Verifica se o CPF contêm 11 números


            printf("CPF Inválido! (Sem pontos ou traços) \n");
            system("pause");
            system("cls");
            f_cadastrar_cliente();
        }

        printf("Diga-me o email do [%i] cliente: ", j+1);
        setbuf(stdin,keyboard);
        scanf("%29[^\n]s",clientes[j].email);

        guardar = strrchr(clientes[j].email,'@');

        if( strcmp(guardar,validar_email[0]) != 0 ){  // Se o usuário não digitar a formatação de um email correto o programa fecha.


            printf("Email inválido, Aceitamos somente o dominio gmail.com, também verifique o uso do '@' .\n");
            system("cls");
            f_cadastrar_cliente();
        }

        printf("\n\n");

    }
    for(j = 0 ; j < qtd_clientes ; j++){



        if(strcmp(clientes[j].cpf,clientes[j+1].cpf) == 0 ){


            printf("Você inseriu clientes com cpf iguais.\n");
            system("cls");
            f_cadastrar_cliente();
        }
        else if(strcmp(clientes[j].email,clientes[j+1].email) == 0  ){

            printf("Você inseriu clientes com emails iguais.\n");
            system("cls");
            f_cadastrar_cliente();
        }

        else if(strcmp(clientes[j].nome,clientes[j+1].nome) == 0){

            printf("Você inseriu clientes com nomes iguais.\n");
            system("cls");
            f_cadastrar_cliente();
        }
    }


  ++ja_cadastrou_cliente;
    system("pause");
    system("cls");
    menu_cliente();


}

void f_listar_filmes(){



    printf("\n======Listar os filmes=======\n\n");


    for(i = 0 ; i < qtd_filmes ; i++){



        if(filmes[i].identificador == filmes[i+1].identificador){   // Condição para não mostrar o filme apagado.


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
    menu_filme();


}
void f_listar_clientes(){



    printf("\n======Listar os clientes=======\n\n");


    for(j = 0 ; j < qtd_clientes ; j++){



        if( strcmp(clientes[j].cpf,clientes[j+1].cpf ) == 0){   // Condição para não mostrar o cliente apagado.


            continue;
        }
        printf("Nome [%s]:  \n",clientes[j].nome);
        printf("CPF: [%s] \n",  clientes[j].cpf);
        printf("Email: [%s] \n",clientes[j].email);
        printf("\n\n");
    }

    system("pause");
    system("cls");
    menu_cliente();

}

void f_consultar_filmes(){



    printf("\n======Consultar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser consultado: ");
    scanf("%d",&consulta);

    printf("\n");

    for(i = 0 ; i < qtd_filmes ; i++){



        if(filmes[i].identificador == filmes[i+1].identificador){   // Condição para não mostrar o filme apagado.


            // Deixar sem nenhuma ação.
        }

        if(consulta == filmes[i].identificador){


            printf("O filme existe em nosso catálogo. \n");
            break;
        }
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1){   //Só executará a ação quando o laço for terminar


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
        menu_filme();
    }
    else{


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_filmes();

    }


}
void f_consultar_clientes(){



    printf("\n======Consultar os clientes=======\n\n");

    printf("Diga-me o nome do cliente a ser consultado: ");
    scanf("%s",cliente_consulta);

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){



        if(strcmp(cliente_consulta,clientes[j+1].nome) == 0){

            // Deixar sem nenhuma ação.
        }

        if(strcmp(cliente_consulta,clientes[j].nome) == 0){


            printf("Esse cliente está cadastrado em nossa locadora. \n");
            break;
        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){   //Só executará a ação quando o laço for terminar


            printf("Esse cliente não está cadastrado em nossa locadora. \n");
        }
    }
    printf("\n\nConsultar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha);

    if(escolha == 1){


        system("pause");
        system("cls");
        f_consultar_clientes();
    }
    else if(escolha == 2){


        system("pause");
        system("cls");
        menu_cliente();
    }
    else{


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_clientes();

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
        menu_filme();
    }
    else{


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_filme();
    }

}
void f_visualizar_clientes(){



    printf("\n======Visualizar os clientes=======\n\n");

    printf("Diga-me o nome do cliente a ser visualizado: ");
    scanf("%s",cliente_consulta);

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){



        if(strcmp(cliente_consulta,clientes[j].nome) == 0){


            printf("Nome: [%s]:  \n",clientes[j].nome);
            printf("CPF: [%s] \n",  clientes[j].cpf);
            printf("Email: [%s] \n",clientes[j].email);
            printf("\n\n");
            break;

        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1 ){


            printf("Cliente não encontrado. \n");
        }
    }
    printf("\n\nVisualizar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha);

    if(escolha == 1){


        system("pause");
        system("cls");
        f_visualizar_clientes();
    }
    else if(escolha == 2){


        system("pause");
        system("cls");
        menu_cliente();
    }
    else{


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_clientes();
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

                if(filmes[i].ano_de_producao > 2019 || filmes[i].ano_de_producao < 1895){     // Faz com que o usuário não digite um ano de produção que não exista.


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
            menu_filme();
        }
        else{


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }
    }

    else if(escolha == 2){




        printf("Diga-me o identificador do filme a ser excluído: ");
        scanf("%d",&consulta);

        for(i = 0 ; i < qtd_filmes ; i++){



            if(consulta == filmes[i].identificador){                 // "Apagando" Os filmes da Random Acess Memory


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
            menu_filme();
        }
        else{


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }

    }

    else if(escolha == 3){


        system("cls");
        menu_filme();
    }

    else{


        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_filme();
    }

}
void f_editar_clientes(){




    printf("\n======Editar os clientes=======\n\n");

    printf("O que você deseja? [1] - Atualizar cliente | [2] - Excluir cliente | [3] - Sair : ");
    scanf("%d",&escolha);

    if(escolha == 1){



        printf("\nDiga-me o nome do cliente a ser atualizado: ");
        scanf("%s",cliente_consulta);
        printf("\n");
        for(j = 0 ; j < qtd_clientes ; j++){



            if(strcmp(cliente_consulta,clientes[i].nome) == 0){



                printf("Diga-me o novo nome do [%i] cliente: ", j+1);
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s", clientes[j].nome);

                printf("Diga-me o novo cpf do [%i] cliente(Sem pontuação): ", j+1);
                setbuf(stdin,keyboard);
                scanf("%11[^\n]s",clientes[j].cpf);

                if(strlen(clientes[j].cpf) != 11){


                    printf("CPF Inválido! (Sem pontos ou traços) \n");
                    system("pause");
                    exit(1);
                }

                printf("Diga-me o novo email do [%i] cliente: ", j+1);
                setbuf(stdin,keyboard);
                scanf("%29[^\n]s",clientes[j].email);

                guardar = strrchr(clientes[j].email,'@');

                if( strcmp(guardar,validar_email[0]) != 0 ){


                    printf("Email inválido, Aceitamos somente o dominio gmail.com, também verifique o uso do '@' .\n");
                    system("pause");
                    exit(1);
                }

                printf("\n\n");
                printf("\nCliente atualizado com sucesso! \n");
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){


                printf("Cliente não encontrado... \n");
            }
        }


        printf("\n\nAtualizar novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha);

        if(escolha == 1){


            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){


            system("pause");
            system("cls");
            menu_cliente();
        }
        else{


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }
    }

    else if(escolha == 2){




        printf("Diga-me o nome do cliente a ser excluído: ");
        scanf("%s",cliente_consulta);

        for(j = 0 ; j < qtd_clientes ; j++){



            if(strcmp(cliente_consulta,clientes[j].nome) == 0){             // "Apagando" Os usuários da Random Acess Memory


                strcpy(clientes[j].nome,clientes[j+1].nome);
                strcpy(clientes[j].cpf,clientes[j+1].cpf);
                strcpy(clientes[j].email,clientes[j+1].email);
                printf("Cliente excluído com sucesso! \n");
                break;
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1 ){


                printf("Cliente não encontrado... \n");
            }
        }


        printf("\n\nExcluir novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha);

        if(escolha == 1){


            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){


            system("pause");
            system("cls");
            menu_cliente();
        }
        else{


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }

    }

    else if(escolha == 3){


        system("cls");
        menu_cliente();
    }

    else{


        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_clientes();
    }

}
void menu_filme(){



    if(ja_cadastrou == 0){


        printf("O que você deseja fazer? \n");
        printf("[1] - Cadastrar filme \n");
        printf("[2] - Editar filme    \n");
        printf("[3] - Listar filmes   \n");
        printf("[4] - Visualizar filme \n");
        printf("[5] - Consultar filme  \n");
        printf("[6] - Voltar para o menu principal \n");
        printf("[7] - Sair \n");
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
            system("cls");
            main();
            break;
        case 7:
            break;
        default:
            printf("Opção não reconhecida... \n");
            system("pause");
            system("cls");
            menu_filme();

        }
    }
    else{


        printf("O que você deseja fazer? \n");
        printf("[1] - Editar filme    \n");
        printf("[2] - Listar filmes   \n");
        printf("[3] - Visualizar filme \n");
        printf("[4] - Consultar filme  \n");
        printf("[5] - Voltar para o menu principal \n");
        printf("[6] - Sair \n");
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
            system("cls");
            main();
            break;
        case 6:
            break;
        default:
            printf("Opção não reconhecida... \n");
            system("pause");
            system("cls");
            menu_filme();
        }

        return 0;
    }

}

void menu_cliente(){



    if(ja_cadastrou_cliente == 0){


        printf("O que você deseja fazer? \n");
        printf("[1] - Cadastrar cliente \n");
        printf("[2] - Editar cliente    \n");
        printf("[3] - Listar clientes   \n");
        printf("[4] - Visualizar cliente \n");
        printf("[5] - Consultar cliente  \n");
        printf("[6] - Voltar para o menu principal \n");
        printf("[7] - Sair \n");
        printf("Diga-me a opção: ");
        scanf("%d",&escolha);

        switch(escolha){





        case 1:
            system("cls");
            f_cadastrar_cliente();
            break;
        case 2:
            system("cls");
            f_editar_clientes();
            break;
        case 3:
            system("cls");
            f_listar_clientes();
            break;
        case 4:
            system("cls");
            f_visualizar_clientes();
            break;
        case 5:
            system("cls");
            f_consultar_clientes();
            break;
        case 6:
            system("cls");
            main();
            break;
        case 7:
            break;
        default:
            printf("Opção não reconhecida... \n");
            system("pause");
            system("cls");
            menu_cliente();

        }
    }
    else{


        printf("O que você deseja fazer? \n");
        printf("[1] - Editar cliente    \n");
        printf("[2] - Listar clientes  \n");
        printf("[3] - Visualizar cliente \n");
        printf("[4] - Consultar cliente  \n");
        printf("[5] - Voltar para o menu principal \n");
        printf("[6] - Sair \n");
        printf("Diga-me a opção: ");
        scanf("%d",&escolha);

        switch(escolha){





        case 1:
            system("cls");
            f_editar_clientes();
            break;
        case 2:
            system("cls");
            f_listar_clientes();
            break;
        case 3:
            system("cls");
            f_visualizar_clientes();
            break;
        case 4:
            system("cls");
            f_consultar_clientes();
            break;
        case 5:
            system("cls");
            main();
            break;
        case 6:
            break;
        default:
            printf("Opção não reconhecida... \n");
            system("pause");
            system("cls");
            menu_cliente();
        }

        return 0;
    }

}


int main(){


    setlocale(LC_ALL,"Portuguese"); // Permite acentos e outras regras da língua portuguesa em strings.

    printf("O que você deseja fazer? \n");
    printf("[1] - Entrar no menu da locadora \n");
    printf("[2] - Entrar no menu do cliente \n");
    printf("[3] - Sair \n");
    printf("Escolha a opção: ");
    scanf("%d",&escolha);

    switch(escolha){


    case 1:
        system("cls");
        menu_filme();
        break;
    case 2:
        system("cls");
        menu_cliente();
        break;
    case 3:
        break;
    default:
        printf("Opção não reconhecida... \n");
        system("pause");
        system("cls");
        main();


    }


}
