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

int i = 0, j = 0; // Variáveis usadas no FOR ( I = Filmes ) ( J = Clientes )
int qtd_filmes = 0, qtd_clientes = 0; // Conta a quantidade de clientes ou filmes cadastrados.
int consulta; // Variável responsável por armazenar e comparar o identificador que é fornecido pelo usuário.
char cliente_consulta[40]; // Variável responsável por armazenar e comparar o nome do cliente que é fornecido pelo usuário no menu de atualização.
int escolha; // Variável responsável pelo controle das opções da navegação.
char *guardar; // Variável que armazena o que existe depois do @ dentro de uma string
char validar_email[1][30] = {"@gmail.com"}; // Variável criada para validar email do usuário <- 30 de tamanho para evitar erros de conflito com a variável email do struct filmes

//----- Variável globais -------//

struct st_filmes{ // Struct para armazenar os filmes



    int identificador;
    char titulo[40];
    int ano_de_producao;
    char genero[15];
} filmes[20]; // Inciializando o Struct com um vetor de 20 de tamanho, você só poderá cadastrar 20 filmes

struct st_clientes{ // Struct para armazenar os clientes


    char nome[40];
    char cpf[12]; // Tamanho extra para o terminador \0
    char email[30]


} clientes[20]; // Inciializando o Struct com um vetor de 20 de tamanho, você só poderá cadastrar 20 clientes

void f_cadastrar_filme(){ // Função para cadastrar os filmes


    printf("\n======Cadastro de filmes=======\n\n");


        printf("Diga-me o identificador do filme: ");
        setbuf(stdin,keyboard);                      // Tirando o lixo da entrada
        scanf("%d", &filmes[qtd_filmes].identificador);

        printf("Diga-me o título do filme: ");
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s",&filmes[qtd_filmes].titulo);        // Pegando o input da forma correta, sem o \n

        printf("Diga-me o ano de produção do filme: ");
        setbuf(stdin,keyboard);
        scanf("%d",&filmes[qtd_filmes].ano_de_producao);

        if(filmes[qtd_filmes].ano_de_producao > 2019 || filmes[qtd_filmes].ano_de_producao < 1895){     // Faz com que o usuário não digite um ano de produção que não exista.

            printf("\nAno de produção inválido! \n\n");
            system("pause");
            system("cls");
            f_cadastrar_filme(); // Se o ano de produção for inválido chama a função novamente!
        }
        printf("Diga-me o gênero do filme: ");
        setbuf(stdin,keyboard);
        scanf("%14[^\n]s",&filmes[i].genero);

        printf("\n\n");

++qtd_filmes; // Após o usuário cadastrar o filme essa variável é incrementada, fazendo que conte quantos filmes foram cadastrados.

    system("pause"); // Da uma pausa antes de executar a próxima linha de comando
    system("cls");   // Limpa o console
    menu_filme();    // Chamada de função

}


void f_cadastrar_cliente(){ // Função para cadastrar clientes

    printf("\n======Cadastro de cliente=======\n\n");

        printf("Diga-me o nome do cliente: ");
        setbuf(stdin,keyboard); // Usando o setbuf para tirar o lixo da entrada
        scanf("%39[^\n]s", clientes[qtd_clientes].nome); // Pegando o input do usuario

        printf("Diga-me o cpf do cliente(Sem pontuação): ");
        setbuf(stdin,keyboard);
        scanf("%11[^\n]s",clientes[qtd_clientes].cpf);

        if(strlen(clientes[qtd_clientes].cpf) != 11){  //Verifica se o CPF contêm 11 números, se não tiver a função é chamada novamente.


            printf("CPF Inválido! (Sem pontos ou traços) \n");
            system("pause");
            system("cls");
            f_cadastrar_cliente(); // Se o CPF for inválido chama a funão novamente!
        }

        printf("Diga-me o email do cliente: ");
        setbuf(stdin,keyboard);
        scanf("%29[^\n]s",clientes[qtd_clientes].email);

        guardar = strrchr(clientes[qtd_clientes].email,'@'); // Guarda a primeira ocorrência do @ na string

        if( strcmp(guardar,validar_email[0]) != 0 ){  // Se o usuário não digitar a formatação de um email correto o programa fecha.


            printf("Email inválido, Aceitamos somente o dominio gmail.com, também verifique o uso do '@' .\n");
            system("cls");
            f_cadastrar_cliente();
        }

        printf("\n\n");

++qtd_clientes; // Após o usuário cadastrar o cliente essa variável é incrementada, fazendo que conte quantos clientes foram cadastrados.

    system("pause"); // Da uma pausa para a próxima linha de comando
    system("cls");   // Limpa o console
    menu_cliente();  // Chama a função de menu dos clientes

}

void f_listar_filmes(){ // Função para listar os filmes



    printf("\n======Listar os filmes=======\n\n");


    for(i = 0 ; i < qtd_filmes ; i++){



        if(filmes[i].identificador == filmes[i+1].identificador){   // Condição para não mostrar o filme apagado.


            continue; // Se o filme existir na memória, então as linhas de baixo não são executadas.
        }
        printf("Título: [%s] \n", filmes[i].titulo);
        printf("Gênero: [%s] \n", filmes[i].genero);
        printf("Ano de produção: [%d]\n", filmes[i].ano_de_producao);
        printf("Identificador: [%d]\n", filmes[i].identificador);
        printf("\n\n");
    }

    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_filme();    // Chama a função novamente


}
void f_listar_clientes(){ // Função para listar os clientes



    printf("\n======Listar os clientes=======\n\n");


    for(j = 0 ; j < qtd_clientes ; j++){



        if( strcmp(clientes[j].cpf,clientes[j+1].cpf ) == 0){   // Condição para não mostrar o cliente apagado.


            continue; // Se o cliente existir na memória, então as linhas de baixo não são executadas.
        }
        printf("Nome [%s]:  \n",clientes[j].nome);
        printf("CPF: [%s] \n",  clientes[j].cpf);
        printf("Email: [%s] \n",clientes[j].email);
        printf("\n\n");
    }

    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_cliente();  // Chama a função novamente

}

void f_consultar_filmes(){ // Função para consultar os filmes



    printf("\n======Consultar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser consultado: ");
    scanf("%d",&consulta); // Armazena o identificador que o usuário digitou

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


            printf("O filme não existe em nosso catálogo. \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nConsultar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){ // Se ele digitar um a função de consultar filmes é chamada novamente


        system("pause");
        system("cls");
        f_consultar_filmes();
    }
    else if(escolha == 2){ // Se 2 ele é direcionado para o menu


        system("pause");
        system("cls");
        menu_filme();
    }
    else{ // Caso ele digita um número que não pertença as opções acima


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_filmes();

    }


}
void f_consultar_clientes(){ // Função para consultar os clientes



    printf("\n======Consultar os clientes=======\n\n");

    printf("Diga-me o nome do cliente a ser consultado: ");
    scanf("%s",&cliente_consulta); // Armazena o nome que o usuário digitou

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


            printf("Esse cliente não está cadastrado em nossa locadora. \n"); // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nConsultar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha);  // Armazena a escolha do usuário

    if(escolha == 1){ // Se ele digitar um a função de consultar clientes é chamada novamente


        system("pause");
        system("cls");
        f_consultar_clientes();
    }
    else if(escolha == 2){ // Se 2 ele é direcionado para o menu


        system("pause");
        system("cls");
        menu_cliente();
    }
    else{ // Caso ele digita um número que não pertença as opções acima


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_clientes();

    }


}
void f_visualizar_filme(){ // Função para visualizar o filme



    printf("\n======Visualizar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser visualizado: ");
    scanf("%d",&consulta); // Armazena o identificador que o usuário digitou

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
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){ //Só executará a ação quando o laço for terminar


            printf("Filme não encontrado. \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nVisualizar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){  // Se ele digitar um a função de consultar filmes é chamada novamente


        system("pause");
        system("cls");
        f_visualizar_filme();
    }
    else if(escolha == 2){ // Se 2 ele é direcionado para o menu


        system("pause");
        system("cls");
        menu_filme();
    }
    else{ // Caso ele digita um número que não pertença as opções acima


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_filme();
    }

}
void f_visualizar_clientes(){ // Função para visualizar o cliente



    printf("\n======Visualizar os clientes=======\n\n");

    printf("Diga-me o nome do cliente a ser visualizado: ");
    scanf("%s",cliente_consulta); // Armazena o nome que o usuário digitou

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){



        if(strcmp(cliente_consulta,clientes[j].nome) == 0){


            printf("Nome: [%s]:  \n",clientes[j].nome);
            printf("CPF: [%s] \n",  clientes[j].cpf);
            printf("Email: [%s] \n",clientes[j].email);
            printf("\n\n");
            break;

        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1 ){ //Só executará a ação quando o laço for terminar


            printf("Cliente não encontrado. \n"); // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nVisualizar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){ // Se ele digitar um a função de consultar clientes é chamada novamente


        system("pause");
        system("cls");
        f_visualizar_clientes();
    }
    else if(escolha == 2){ // Se 2 ele é direcionado para o menu



        system("pause");
        system("cls");
        menu_cliente();
    }
    else{ // Caso ele digita um número que não pertença as opções acima


        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_clientes();
    }

}
void f_editar_filme(){ // Função para editar o filme




    printf("\n======Editar os filmes=======\n\n");

    printf("O que você deseja? [1] - Atualizar filme | [2] - Excluir filme | [3] - Sair : ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){ // Se o número digitado for 1 então irá atualizar o filme



        printf("\nDiga-me o identificador do filme a ser atualizado: ");
        scanf("%d",&consulta);  // Armazena o filme que o usuário digitou
        printf("\n");
        for(i = 0 ; i < qtd_filmes ; i++){



            if(consulta == filmes[i].identificador){

            // Pedindo novas informações para atualização do filme

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
                    system("cls");
                    f_editar_filme(); // Se o ano de produção for inválido chama a função novamente!
                }

                printf("Diga-me o gênero do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%14[^\n]s",filmes[i].genero);
                printf("\nFilme atualizado com sucesso! \n");
                break;
            }
            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){


                printf("Filme não encontrado... \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            }
        }


        printf("\n\nAtualizar novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){ // Se ele digitar um a função de editar filmes é chamada novamente


            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){  // Se 2 ele é direcionado para o menu


            system("pause");
            system("cls");
            menu_filme();
        }
        else{ // Caso ele digita um número que não pertença as opções acima


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }
    }

    else if(escolha == 2){ // Se o número digitado for 2 então irá excluir o filme




        printf("Diga-me o identificador do filme a ser excluído: ");
        scanf("%d",&consulta); // Armazena o filme que o usuário digitou

        for(i = 0 ; i < qtd_filmes ; i++){



            if(consulta == filmes[i].identificador){                 // "Apagando" Os filmes da Random Acess Memory

                // Copia a posição x do vetor para a posição x+1
                strcpy(filmes[i].genero,filmes[i+1].genero);
                strcpy(filmes[i].titulo,filmes[i+1].titulo);
                filmes[i].ano_de_producao = filmes[i+1].ano_de_producao;
                filmes[i].identificador = filmes[i+1].identificador;
                printf("Filme excluído com sucesso! \n");
                break;
            }

            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){


                printf("Filme não encontrado... \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            }
        }


        printf("\n\nExcluir novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){ // Se ele digitar um a função de editar filmes é chamada novamente


            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){ // Se 2 ele é direcionado para o menu


            system("pause");
            system("cls");
            menu_filme();
        }
        else{ // Caso ele digita um número que não pertença as opções acima


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }

    }

    else if(escolha == 3){ // Se o número digitado for 3 então irá voltar para o menu


        system("cls");
        menu_filme();
    }

    else{ // Caso ele digita um número diferente de 1 2 ou 3.


        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_filme();
    }

}
void f_editar_clientes(){ //Função para editar os clientes




    printf("\n======Editar os clientes=======\n\n");

    printf("O que você deseja? [1] - Atualizar cliente | [2] - Excluir cliente | [3] - Sair : ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){ // Se o número digitado for 1 então irá atualizar o cliente



        printf("\nDiga-me o nome do cliente a ser atualizado: ");
        scanf("%s",&cliente_consulta); // Variável responsável por armazenar e comparar o nome que o usuário digitar
        printf("\n");
        for(j = 0 ; j < qtd_clientes ; j++){



            if(strcmp(cliente_consulta,clientes[j].nome) == 0){ // Se o nome que o usuário digitou consta no sistema então ele atualizará

            // Pedindo novas informações para atualização do cliente

                printf("Diga-me o novo nome do [%i] cliente: ", j+1);
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s", clientes[j].nome);

                printf("Diga-me o novo cpf do [%i] cliente(Sem pontuação): ", j+1);
                setbuf(stdin,keyboard);
                scanf("%11[^\n]s",clientes[j].cpf);

                if(strlen(clientes[j].cpf) != 11){


                    printf("CPF Inválido! (Sem pontos ou traços) \n");
                    system("pause");
                    system("cls");
                    f_editar_clientes(); // Se o CPF for inválido chama a função novamente!
                }

                printf("Diga-me o novo email do [%i] cliente: ", j+1);
                setbuf(stdin,keyboard);
                scanf("%29[^\n]s",clientes[j].email);

                guardar = strrchr(clientes[j].email,'@'); // Guarda a primeira ocorrência do @ na string do usuário

                if( strcmp(guardar,validar_email[0]) != 0 ){ // Se o usuário não digitar a formatação de um email correto o programa fecha.


                    printf("Email inválido, Aceitamos somente o dominio gmail.com, também verifique o uso do '@' .\n");
                    system("pause");
                    system("cls");
                    f_editar_clientes();
                }

                printf("\n\n");
                printf("\nCliente atualizado com sucesso! \n");
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){ // Só executará a ação quando o laço for terminar


                printf("Cliente não encontrado... \n"); // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            }
        }


        printf("\n\nAtualizar novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){  // Se ele digitar um a função de editar filmes é chamada novamente


            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){ // Se ele digitar dois é direcionado para o menu


            system("pause");
            system("cls");
            menu_cliente();
        }
        else{ // É executado somente se o usuário digitar um valor inválido


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }
    }

    else if(escolha == 2){ // Se o número digitado for 1 então irá excluir o cliente




        printf("Diga-me o nome do cliente a ser excluído: ");
        scanf("%s",cliente_consulta); // Armazena o nome do cliente

        for(j = 0 ; j < qtd_clientes ; j++){



            if(strcmp(cliente_consulta,clientes[j].nome) == 0){             // "Apagando" Os usuários da Random Acess Memory

                // Copia a posição x do vetor para a posição x+1
                strcpy(clientes[j].nome,clientes[j+1].nome);
                strcpy(clientes[j].cpf,clientes[j+1].cpf);
                strcpy(clientes[j].email,clientes[j+1].email);
                printf("Cliente excluído com sucesso! \n");
                break;
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1 ){ // Executa essa ação quando o laço for termina


                printf("Cliente não encontrado... \n"); // Se o nome que o usuário digitou não consta no sistema então exibirá essa mensagem
            }
        }


        printf("\n\nExcluir novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){ // Se ele digitar um a função de editar usuario é chamada novamente


            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){ // Se ele digitar dois é direcionado para o menu


            system("pause");
            system("cls");
            menu_cliente();
        }
        else{ // É executado somente se o usuário digitar um valor inválido


            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }

    }

    else if(escolha == 3){ // Se o usuário digitar 3 ele é direcionado para o menu


        system("cls");
        menu_cliente();
    }

    else{ // É executado somente se o usuário digitar um valor inválido


        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_clientes();
    }

}
void menu_filme(){ // Função do menu do filme


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

void menu_cliente(){ // Função do menu do cliente

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


int main(){ // Função principal


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
