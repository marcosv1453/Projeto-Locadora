#include <stdio.h> // Biblioteca para entrada e saída de dados
#include <locale.h> // Biblioteca para incluir regras da língua portuguesa em strings
#include <stdlib.h> // Biblioteca para alocação de memória e controle de processos
#include <string.h> // Biblioteca para realizar operações com string
#include <ctype.h>  // Biblioteca para manipulação de caracteres

char keyboard[BUFSIZ]; // Prótotipo de função para limpeza do buffer

//------ Documentação -------//

/**
*@author ---
*@version ---
*@since ---
*/

//------ Documentação -------//

//------ Variável globais -------//

int i = 0, j = 0; // Variáveis usadas no FOR ( I = Filmes ) ( J = Clientes )

int qtd_filmes = 0, qtd_clientes = 0; // Controla a ação dos for, é usado para controle de indice dentro de array

int filme = 0, cliente = 0;// Usado para contar a quantidade de clientes ou filmes cadastrados

int consulta; // Variável responsável por armazenar e comparar o identificador que é fornecido pelo usuário.
char cliente_consulta[40]; // Variável responsável por armazenar e comparar o nome do cliente que é fornecido pelo usuário no menu de atualização.

int escolha; // Variável responsável pelo controle das opções da navegação.

char *guardar; // Variável que armazena o que existe depois do @ dentro de uma string
char validar_email[2][30] = {"@gmail.com","@hotmail.com"}; // Variável criada para validar email do usuário <- 30 de tamanho para evitar erros de conflito com a variável email do struct filmes

//----- Variável globais -------//

struct st_filmes{  // Struct para armazenar os filmes;




    int identificador;
    char titulo[40];
    int ano_de_producao;
    char genero[15];
} filmes[20]; // Inciializando o Struct com um vetor de 20 de tamanho, você só poderá cadastrar 20 filmes

struct st_clientes{  // Struct para armazenar os clientes;



    char nome[40];
    char cpf[12]; // Tamanho extra para o terminador \0
    char email[30]


} clientes[20]; // Inciializando o Struct com um vetor de 20 de tamanho, você só poderá cadastrar 20 clientes

void f_cadastrar_filme(){  // Função para cadastrar os filmes



    printf("\n======Cadastro de filmes=======\n\n");

    int identificador; // Serve para armazenar o identificador do filme e comparar com o identificador da struct
    int booleana = 0; // Servirá para o controle do if/else da verificação de identificadores cadastrados (0 false) - (1 - True)

    printf("Diga-me o identificador do filme: ");
    setbuf(stdin,keyboard);                      // Tirando o lixo da entrada
    scanf("%d", &identificador);
    // Identificador menor que zero
    if(identificador <= 0){  // Se o identificador for negativo então, a função é chamada novamente

        printf("\n\nInforme um identificador positivo ou não nulo! \n");
        system("pause");
        system("cls");
        f_cadastrar_filme();
    }
    // Verificação de identificadores iguais
    if(filme < 20){  // O usuário só pode cadastrar 20 filmes, a verificação só ocorrerrá se o usuário ainda não tiver preenchido 20 filmes


        for(i = 0 ; i < qtd_filmes ; i++){  // Laço para ver se existe um identificador igual a um que já está cadastrado no sistema

            if(identificador == filmes[i].identificador) // Se o identificador que o usuário informar for igual a um identificador em uma posição X do meu struct
                booleana = 1; // Então a booleana recebe 1 ( True )
        }
        if(booleana == 1){  // Se a booleana for igual a 1 quer dizer que esse identificador já existe no sistema

            printf("Filme já cadastrado!\n");
            system("pause");
            system("cls");
            f_cadastrar_filme(); // Se o identificador for inválido chama a função novamente!
        }
        else{  // Se a booleana não for 1 então o identificador não existe no sistema, o meu struct st_filmes na variável identificador, recebe o identificador que o usuário informou.

            filmes[qtd_filmes].identificador = identificador;
        }
    }
    else{   // Caso ele já tenha cadastrado 20 filmes, então ele volta para o menu

        printf("\n\nVocê já cadastrou o número máximo de filmes! \n");
        system("pause");
        system("cls");
        menu_filme();
    }

    printf("Diga-me o título do filme: ");
    setbuf(stdin,keyboard);
    scanf("%39[^\n]s",&filmes[qtd_filmes].titulo);        // Pegando o input da forma correta, sem o \n

    printf("Diga-me o ano de produção do filme: ");
    setbuf(stdin,keyboard);
    scanf("%d",&filmes[qtd_filmes].ano_de_producao);

    if(filmes[qtd_filmes].ano_de_producao > 2019 || filmes[qtd_filmes].ano_de_producao < 1895){      // Faz com que o usuário não digite um ano de produção que não exista.


        printf("\nAno de produção inválido! \n\n"); // Se o ano de produção for menor que 1895 irei chamar a função novamente, porém com alguns detalhes...
        system("pause");
        system("cls");
        f_cadastrar_filme();
    }
    printf("Diga-me o gênero do filme: ");
    setbuf(stdin,keyboard);
    scanf("%14[^\n]s",&filmes[i].genero);

    printf("\n\n");
    ++qtd_filmes; // Após o usuário cadastrar o filme essa variável é incrementada, fazendo que conte quantos filmes foram cadastrados.
    ++filme; // Conta quantos filmes foram cadastrados é a partir disso vê se o limite de filmes cadastrados passou da meta, ou não.
    system("pause"); // Da uma pausa antes de executar a próxima linha de comando
    system("cls");   // Limpa o console
    menu_filme();    // Chamada de função

}


void f_cadastrar_cliente(){  // Função para cadastrar clientes


    char nomeador[20][40]; // Serve para armazenar o nome do cliente e comparar com nome da struct
    char cpfeador[20][12]; // Serve para armazenar o cpf do cliente e comparar com o cpf da struct
    char emaildor[20][30]; // Serve para armazenar o email do cliente e comparar com o cpf da struct
    int booleana = 0; // Servirá para o controle do if/else da verificação de elementos cadastrados (0 false) - (1 - True)
    int e_digito = 0; // Servirá para verificar se o CPF é digito ou não

    printf("\n======Cadastro de cliente=======\n\n");

    if(cliente < 20){  // O usuário só pode cadastrar 20 clientes, a verificação só ocorrerrá se o usuário ainda não tiver preenchido 20 clientes.

        printf("Diga-me o nome do cliente: ");
        setbuf(stdin,keyboard); // Usando o setbuf para tirar o lixo da entrada
        scanf("%39[^\n]s", &nomeador[qtd_clientes]); // Pegando o input do usuario

        printf("Diga-me o cpf do cliente(Sem pontuação): ");
        setbuf(stdin,keyboard);
        scanf("%11[^\n]s", &cpfeador[qtd_clientes]);
        //Verificação do CPF
        for(int j = 0 ; j <= strlen(cpfeador[qtd_clientes]) ; j++){  // Laço percorre o tamanho da string


            if(isdigit(cpfeador[j])){  // Verifica se o cpf fornecido pelo usuário tem letras do alfabeto

                e_digito = 1; // Se tiver letras do alfabetos e_digito = 1
            }
            else{  // Se não tiver letras do alfabeto e_digito fica = 0

                e_digito = 0;
            }
        }

        if(strlen(cpfeador[qtd_clientes]) != 11 || e_digito == 1){   //Verifica se o CPF contêm 11 números, se não tiver a função é chamada novamente.

            printf("CPF Inválido!(Sem pontos ou traços)!/Somente números! \n");
            system("pause");
            system("cls");
            f_cadastrar_cliente(); // Se o CPF for inválido chama a funão novamente!
        }

        printf("Diga-me o email do cliente: ");
        setbuf(stdin,keyboard);
        scanf("%29[^\n]s",&emaildor[qtd_clientes]);

        guardar = strrchr(emaildor[qtd_clientes],'@'); // Guarda a primeira ocorrência do @ na string

        if( strcmp(guardar,validar_email[0]) != 0 && strcmp(guardar,validar_email[1]) != 0){   // Se o usuário não digitar a formatação de um email correto então a função é retornada.


            printf("Email inválido, Aceitamos somente o dominio gmail.com e hotmail.com, também verifique o uso do '@' .\n");
            system("pause");
            system("cls");
            f_cadastrar_cliente();
        }

        // Verificação de elementos iguais
        for(j = 0 ; j < qtd_clientes ; j++){  // Laço para ver se existe os elementos igual a um que já está cadastrado no sistema

            if(strcmp(nomeador[qtd_clientes],clientes[j].nome) == 0 || strcmp(cpfeador[qtd_clientes],clientes[j].cpf) == 0 || strcmp(emaildor[qtd_clientes],clientes[j].email) == 0 ){  // Se os elementos que o usuário informar for igual a um os elementos da posição X do meu struct

                booleana = 1; // Então a booleana recebe 1 ( True )
            }
        }
        if(booleana == 1){  // Se a booleana for igual a 1 quer dizer que esses elementos já existe no sistema

            printf("Elementos que você inseriu já estão cadastrados em outro cliente!\n");
            system("pause");
            system("cls");
            f_cadastrar_cliente(); // Se os elementos for inválido chama a função novamente!
        }
        else{  // Se a booleana não for 1 então os elementos não existem no sistema, o meu struct st_cliente nas três variáveis, receberá as informações que o usuário digitou.

            strcpy(clientes[qtd_clientes].nome,nomeador[qtd_clientes]); // Copia a 2 string na 1
            strcpy(clientes[qtd_clientes].cpf,cpfeador[qtd_clientes]);  // Copia a 2 string na 1
            strcpy(clientes[qtd_clientes].email,emaildor[qtd_clientes]); // Copia a 2 string na 1
        }
    }
    else{   // Caso ele já tenha cadastrado 20 clientes, então ele volta para o menu

        printf("\n\nVocê já cadastrou o número máximo de clientes! \n");
        system("pause");
        system("cls");
        menu_cliente();
    }
    printf("\n\n");

    ++qtd_clientes; // Após o usuário cadastrar o cliente essa variável é incrementada, fazendo que conte quantos clientes foram cadastrados.
    ++cliente; // Conta quantos clientes foram cadastrados é a partir disso vê se o limite de clientes cadastrados passou da meta, ou não.
    system("pause"); // Da uma pausa para a próxima linha de comando
    system("cls");   // Limpa o console
    menu_cliente();  // Chama a função de menu dos clientes

}

void f_listar_filmes(){  // Função para listar os filmes




    printf("\n======Listar os filmes=======\n\n");

    printf(" Título                                       Gênero               Ano de produção   Identificador   \n");
    printf("|-------------------------------------------|--------------------|------------------|---------------|\n");
    for(i = 0 ; i < qtd_filmes ; i++){




        if(filmes[i].identificador == filmes[i+1].identificador || filmes[i].identificador == 0 ){    // Condição para não mostrar o filme apagado.



            continue; // Se o filme existir na memória, então as linhas de baixo não são executadas.
        }
        printf("|[%s]",filmes[i].titulo);
        printf("\t\t\t\t\t[%s]",filmes[i].genero);
        printf("\t\t[%d]",filmes[i].ano_de_producao);
        printf("\t\t[%d]\n",filmes[i].identificador);
        printf("|-------------------------------------------|--------------------|------------------|---------------|");
        printf("\n");


    }

    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_filme();    // Chama a função novamente


}
void f_listar_clientes(){  // Função para listar os clientes




    printf("\n======Listar os clientes=======\n\n");

    printf(" Nome                                        CPF                              Email   \n");
    printf("|-------------------------------------------|--------------------|-------------------------------|\n");
    for(j = 0 ; j < qtd_clientes ; j++){




        if( strcmp(clientes[j].cpf,clientes[j+1].cpf ) == 0 || strlen(clientes[j].nome) == 0){    // Condição para não mostrar o cliente apagado.



            continue; // Se o cliente existir na memória, então as linhas de baixo não são executadas.
        }
        printf("|[%s]",clientes[j].nome);
        printf("\t\t\t\t\t[%s]",clientes[j].cpf);
        printf("\t\t[%s]\n",clientes[j].email);
        printf("|-------------------------------------------|--------------------|-------------------------------|");
        printf("\n");
    }

    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_cliente();  // Chama a função novamente

}

void f_consultar_filmes(){  // Função para consultar os filmes




    printf("\n======Consultar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser consultado: ");
    scanf("%d",&consulta); // Armazena o identificador que o usuário digitou

    printf("\n");

    for(i = 0 ; i < qtd_filmes ; i++){




        if(filmes[i].identificador == filmes[i+1].identificador || filmes[i].identificador == 0){    // Condição para não mostrar o filme apagado.



            // Deixar sem nenhuma ação.
        }

        if(consulta == filmes[i].identificador && consulta != 0){



            printf("O filme existe em nosso catálogo. \n");
            break;
        }
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){    //Só executará a ação quando o laço for terminar



            printf("O filme não existe em nosso catálogo. \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nConsultar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){  // Se ele digitar um a função de consultar filmes é chamada novamente



        system("pause");
        system("cls");
        f_consultar_filmes();
    }
    else if(escolha == 2){  // Se 2 ele é direcionado para o menu



        system("pause");
        system("cls");
        menu_filme();
    }
    else{  // Caso ele digita um número que não pertença as opções acima



        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_filmes();

    }


}
void f_consultar_clientes(){  // Função para consultar os clientes




    printf("\n======Consultar os clientes=======\n\n");

    printf("Diga-me o nome do cliente a ser consultado: ");
    scanf("%s",&cliente_consulta); // Armazena o nome que o usuário digitou

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){




        if(strcmp(cliente_consulta,clientes[j+1].nome) == 0 || strlen(clientes[j].nome) == 0){


            // Deixar sem nenhuma ação.
        }

        if(strcmp(cliente_consulta,clientes[j].nome) == 0){



            printf("Esse cliente está cadastrado em nossa locadora. \n");
            break;
        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){    //Só executará a ação quando o laço for terminar



            printf("Esse cliente não está cadastrado em nossa locadora. \n"); // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nConsultar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha);  // Armazena a escolha do usuário

    if(escolha == 1){  // Se ele digitar um a função de consultar clientes é chamada novamente



        system("pause");
        system("cls");
        f_consultar_clientes();
    }
    else if(escolha == 2){  // Se 2 ele é direcionado para o menu



        system("pause");
        system("cls");
        menu_cliente();
    }
    else{  // Caso ele digita um número que não pertença as opções acima



        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_clientes();

    }


}
void f_visualizar_filme(){  // Função para visualizar o filme




    printf("\n======Visualizar os filmes=======\n\n");

    printf("Diga-me o identificador do filme a ser visualizado: ");
    scanf("%d",&consulta); // Armazena o identificador que o usuário digitou

    printf("\n");

    for(i = 0 ; i < qtd_filmes ; i++){




        if(consulta == filmes[i].identificador && consulta != 0){  // Faz com que não mostre o lixo da memória!



            printf("Filme [%i]:  \n",i+1);
            printf("Título: [%s] \n", filmes[i].titulo);
            printf("Gênero: [%s] \n", filmes[i].genero);
            printf("Ano de produção: [%d]\n", filmes[i].ano_de_producao);
            printf("Identificador: [%d]\n", filmes[i].identificador);
            printf("\n\n");
            break;

        }
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1 || consulta == 0){  //Só executará a ação quando o laço for terminar



            printf("Filme não encontrado. \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nVisualizar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){   // Se ele digitar um a função de consultar filmes é chamada novamente



        system("pause");
        system("cls");
        f_visualizar_filme();
    }
    else if(escolha == 2){  // Se 2 ele é direcionado para o menu



        system("pause");
        system("cls");
        menu_filme();
    }
    else{  // Caso ele digita um número que não pertença as opções acima



        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_filme();
    }

}
void f_visualizar_clientes(){  // Função para visualizar o cliente




    printf("\n======Visualizar os clientes=======\n\n");

    printf("Diga-me o nome do cliente a ser visualizado: ");
    scanf("%s",cliente_consulta); // Armazena o nome que o usuário digitou

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){




        if(strcmp(cliente_consulta,clientes[j].nome) == 0 && strcmp(cliente_consulta,"") != 0){  //Mostra as informações se na comparação retornar true



            printf("Nome: [%s]:  \n",clientes[j].nome);
            printf("CPF: [%s] \n",  clientes[j].cpf);
            printf("Email: [%s] \n",clientes[j].email);
            printf("\n\n");
            break;

        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1 ){  //Só executará a ação quando o laço for terminar



            printf("Cliente não encontrado. \n"); // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
        }
    }
    printf("\n\nVisualizar novamente? [1] - S | [2] - N : ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){  // Se ele digitar um a função de consultar clientes é chamada novamente



        system("pause");
        system("cls");
        f_visualizar_clientes();
    }
    else if(escolha == 2){  // Se 2 ele é direcionado para o menu




        system("pause");
        system("cls");
        menu_cliente();
    }
    else{  // Caso ele digita um número que não pertença as opções acima



        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_visualizar_clientes();
    }

}
void f_editar_filme(){  // Função para editar o filme



    int identificador; // Serve para armazenar o identificador do filme e comparar com o identificador da struct
    int booleana = 0; // Servirá para o controle do if/else da verificação de identificadores cadastrados (0 false) - (1 - True)

    printf("\n======Editar os filmes=======\n\n");

    printf("O que você deseja? [1] - Atualizar filme | [2] - Excluir filme | [3] - Sair : ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){  // Se o número digitado for 1 então irá atualizar o filme




        printf("\nDiga-me o identificador do filme a ser atualizado: ");
        scanf("%d",&consulta);  // Armazena o filme que o usuário digitou
        printf("\n");
        for(i = 0 ; i < qtd_filmes ; i++){




            if(consulta == filmes[i].identificador){


                // Pedindo novas informações para atualização do filme

                printf("Diga-me o identificador do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%d", &identificador);


                if(identificador <= 0){  // Se o identificador for negativo então, a função é chamada novamente

                    printf("\n\nInforme um identificador positivo ou não nulo! \n");
                    system("pause");
                    system("cls");
                    f_editar_filme();
                }

                for(int i = 0 ; i < qtd_filmes ; i++){  // Laço para ver se existe um identificador igual a um que já está cadastrado no sistema

                    // É criado um novo "i" para percorrer somente nesse for e não se intrometer nos demais.
                    if(identificador == filmes[i].identificador) // Se o identificador que o usuário informar for igual a um identificador em uma posição X do meu struct
                        booleana = 1; // Então a booleana recebe 1 ( True )
                }
                if(booleana == 1){  // Se a booleana for igual a 1 quer dizer que esse identificador já existe no sistema

                    printf("Identificador do filme já está cadastrado no sistema!\n\n");
                    system("pause");
                    exit(1);
                }
                else{  // Se a booleana não for 1 então o identificador não existe no sistema, o meu struct st_filmes na variável identificador, recebe o identificador que o usuário informou.

                    filmes[i].identificador = identificador;
                }


                printf("Diga-me o título do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s",filmes[i].titulo);

                printf("Diga-me o ano de produção do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%d",&filmes[i].ano_de_producao);

                if(filmes[i].ano_de_producao > 2019 || filmes[i].ano_de_producao < 1895){      // Faz com que o usuário não digite um ano de produção que não exista.



                    printf("\nAno de produção inválido! \n\n");
                    system("pause");
                    system("cls");
                    exit(1); // Se o ano de produção for inválido o programa é fechado!
                }

                printf("Diga-me o gênero do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%14[^\n]s",filmes[i].genero);
                printf("\nFilme atualizado com sucesso! \n");
                break;
            }
            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){  // Só executará a ação quando o laço for terminar



                printf("Filme não encontrado... \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            }
        }


        printf("\n\nAtualizar novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){  // Se ele digitar um a função de editar filmes é chamada novamente



            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){   // Se 2 ele é direcionado para o menu



            system("pause");
            system("cls");
            menu_filme();
        }
        else{  // Caso ele digita um número que não pertença as opções acima



            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }
    }

    else if(escolha == 2){  // Se o número digitado for 2 então irá excluir o filme





        printf("Diga-me o identificador do filme a ser excluído: ");
        scanf("%d",&consulta); // Armazena o filme que o usuário digitou

        for(i = 0 ; i < qtd_filmes ; i++){




            if(consulta == filmes[i].identificador){                  // "Apagando" Os filmes da Random Acess Memory


                // Faz com que o identificador fique nulo, assim parecendo que foi apagado da memória e não mostrrando nos menus.
                filmes[i].identificador = 0;
                --filme; // Remove um filme
                printf("Filme excluído com sucesso! \n");
                break;
            }

            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){ // Só executa a ação quando o laço for terminar



                printf("Filme não encontrado... \n"); // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            }
        }


        printf("\n\nExcluir novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){  // Se ele digitar um a função de editar filmes é chamada novamente



            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){  // Se 2 ele é direcionado para o menu



            system("pause");
            system("cls");
            menu_filme();
        }
        else{  // Caso ele digita um número que não pertença as opções acima



            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }

    }

    else if(escolha == 3){  // Se o número digitado for 3 então irá voltar para o menu



        system("cls");
        menu_filme();
    }

    else{  // Caso ele digita um número diferente de 1 2 ou 3.



        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_filme();
    }

}
void f_editar_clientes(){  //Função para editar os clientes


    char nomeador[20][40]; // Serve para armazenar o nome do cliente e comparar com nome da struct
    char cpfeador[20][12]; // Serve para armazenar o cpf do cliente e comparar com o cpf da struct
    char emaildor[20][30]; // Serve para armazenar o email do cliente e comparar com o cpf da struct
    int booleana = 0; // Servirá para o controle do if/else da verificação de elementos cadastrados (0 false) - (1 - True)
    int e_digito = 0; // Servirá para verificar se o CPF é digito ou não


    printf("\n======Editar os clientes=======\n\n");

    printf("O que você deseja? [1] - Atualizar cliente | [2] - Excluir cliente | [3] - Sair : ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){  // Se o número digitado for 1 então irá atualizar o cliente




        printf("\nDiga-me o nome do cliente a ser atualizado: ");
        scanf("%s",&cliente_consulta); // Variável responsável por armazenar e comparar o nome que o usuário digitar
        printf("\n");
        for(j = 0 ; j < qtd_clientes ; j++){




            if(strcmp(cliente_consulta,clientes[j].nome) == 0){  // Se o nome que o usuário digitou consta no sistema então ele atualizará


                // Pedindo novas informações para atualização do cliente

                printf("Diga-me o novo nome do cliente: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s", &nomeador[qtd_clientes]);

                printf("Diga-me o novo cpf do cliente(Sem pontuação): ");
                setbuf(stdin,keyboard);
                scanf("%11[^\n]s",&cpfeador[qtd_clientes]);

                //Verificação do CPF
                for(int j = 0 ; j <= strlen(cpfeador[qtd_clientes]) ; j++){  // Laço percorre o tamanho da string



                    if(isdigit(cpfeador[j])){  // Verifica se o cpf fornecido pelo usuário tem letras do alfabeto

                        e_digito = 1; // Se tiver letras do alfabetos e_digito = 1
                    }
                    else{  // Se não tiver letras do alfabeto e_digito fica = 0

                        e_digito = 0;
                    }
                }

                if(strlen(cpfeador[qtd_clientes]) != 11 || e_digito == 1){   //Verifica se o CPF contêm 11 números, se não tiver a função é chamada novamente.

                    printf("CPF Inválido!(Sem pontos ou traços)!/Somente números! \n");
                    system("pause");
                    exit(1);
                }

                printf("Diga-me o novo email do cliente: ");
                setbuf(stdin,keyboard);
                scanf("%29[^\n]s",&emaildor[qtd_clientes]);

                guardar = strrchr(emaildor[qtd_clientes],'@'); // Guarda a primeira ocorrência do @ na string

                if( strcmp(guardar,validar_email[0]) != 0 && strcmp(guardar,validar_email[1]) != 0){   // Se o usuário não digitar a formatação de um email correto então a função é retornada.


                    printf("Email inválido, Aceitamos somente o dominio gmail.com e hotmail.com, também verifique o uso do '@' .\n");
                    system("pause");
                    exit(1);
                }

                // Verificação de elementos iguais
                for(int j = 0 ; j < qtd_clientes ; j++){  // Laço para ver se existe os elementos igual a um que já está cadastrado no sistema

                    // É criado uma nova variável para percorrer somente nesse for e não se intrometer nos demais
                    if(strcmp(nomeador[qtd_clientes],clientes[j].nome) == 0 || strcmp(cpfeador[qtd_clientes],clientes[j].cpf) == 0 || strcmp(emaildor[qtd_clientes],clientes[j].email) == 0 ){  // Se os elementos que o usuário informar for igual a um os elementos da posição X do meu struct

                        booleana = 1; // Então a booleana recebe 1 ( True )
                    }
                }
                if(booleana == 1){  // Se a booleana for igual a 1 quer dizer que esses elementos já existe no sistema

                    printf("Elementos que você inseriu já estão cadastrados em outro cliente!\n");
                    system("pause");
                    exit(1); // Se os elementos for inválido o programa é fechado
                }
                else{  // Se a booleana não for 1 então os elementos não existem no sistema, o meu struct st_cliente nas três variáveis, receberá as informações que o usuário digitou.

                    strcpy(clientes[j].nome,nomeador[qtd_clientes]); // Copia a 2 string na 1
                    strcpy(clientes[j].cpf,cpfeador[qtd_clientes]);  // Copia a 2 string na 1
                    strcpy(clientes[j].email,emaildor[qtd_clientes]); // Copia a 2 string na 1
                }

                printf("\n\n");
                printf("\nCliente atualizado com sucesso! \n");
                break;
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){  // Só executará a ação quando o laço for terminar



                printf("Cliente não encontrado... \n"); // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            }
        }


        printf("\n\nAtualizar novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){   // Se ele digitar um a função de editar filmes é chamada novamente



            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){  // Se ele digitar dois é direcionado para o menu



            system("pause");
            system("cls");
            menu_cliente();
        }
        else{  // É executado somente se o usuário digitar um valor inválido



            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }
    }

    else if(escolha == 2){  // Se o número digitado for 1 então irá excluir o cliente





        printf("Diga-me o nome do cliente a ser excluído: ");
        scanf("%s",cliente_consulta); // Armazena o nome do cliente

        for(j = 0 ; j < qtd_clientes ; j++){




            if(strcmp(cliente_consulta,clientes[j].nome) == 0){              // "Apagando" Os usuários da Random Acess Memory


                // Faz com que os elementos fiquem nulo assim parecendo que foi apagado da memória e não mostrrando nos menus.
                strcpy(clientes[j].nome,"");
                strcpy(clientes[j].cpf,"");
                strcpy(clientes[j].email,"");
                --cliente; // Remove um cliente
                printf("Cliente excluído com sucesso! \n");
                break;
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1 ){  // Executa essa ação quando o laço for termina



                printf("Cliente não encontrado... \n"); // Se o nome que o usuário digitou não consta no sistema então exibirá essa mensagem
            }
        }


        printf("\n\nExcluir novamente? [1] - S | [2] - N : ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){  // Se ele digitar um a função de editar usuario é chamada novamente



            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){  // Se ele digitar dois é direcionado para o menu



            system("pause");
            system("cls");
            menu_cliente();
        }
        else{  // É executado somente se o usuário digitar um valor inválido



            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }

    }

    else if(escolha == 3){  // Se o usuário digitar 3 ele é direcionado para o menu



        system("cls");
        menu_cliente();
    }

    else{  // É executado caso ele digite um número diferente de 1 2 ou 3



        printf("Valor inválido! \n");
        system("pause");
        system("cls");
        f_editar_clientes();
    }

}
void menu_filme(){  // Função do menu do filme



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
        exit(1); // Fecha o programa
    default:
        printf("Opção não reconhecida... \n");
        system("pause");
        system("cls");
        menu_filme();

    }
}

void menu_cliente(){  // Função do menu do cliente


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
        exit(1); // Fecha o programa
    default:
        printf("Opção não reconhecida... \n");
        system("pause");
        system("cls");
        menu_cliente();

    }
}


int main(){  // Função principal



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
