#include <stdio.h>      // Biblioteca para entrada e saída de dados
#include <locale.h>     // Biblioteca para incluir regras da língua portuguesa em strings
#include <stdlib.h>     // Biblioteca para alocação de memória e controle de processos
#include <string.h>     // Biblioteca para realizar operações com string
#include <ctype.h>      // Biblioteca para manipulação de caracteres
#include <windows.h>    // Biblioteca para usar comandos exclusios do SO

char keyboard[BUFSIZ];  // Prótotipo de função para limpeza do buffer



//------ Documentação -------//

/**
*@author Eduardo José
*@version 1.0.0
*@since 22/10/19
*@see Program in STACK (LIFO)
*@link https://github.com/Duduxs
*/

//------ Documentação -------//

//-----------------------------------------------------Variáveis Globais-----------------------------------------------------------------//


int escolha;                                               // Variável responsável pelo controle das opções da navegação.
int i = 0, j = 0;                                          // Variáveis usadas no for ( I = Filmes ) ( J = Clientes )

int consulta;                                              // Armazena e compara o ID que é fornecido pelo usuário.
char cliente_consulta[40];                                 // Armazena e compara o nome que é fornecido pelo usuário.
char estoque_consulta[40];                                 // Armazena e compara o nome do estoque que é fornecido pelo usuário.

char *guardar;                                             // Variável que armazena o que existe depois do @ dentro de uma string
char validar_email[2][30] = {"@gmail.com","@hotmail.com"}; // Variável criada para validar email do usuário.

FILE *arq;                                                 // Criando um ponteiro para manipular arquivos

int qtd_filmes = 0;                                        // Controla o índice dos arrays e conta os filmes.
int qtd_clientes = 0;                                      // Controla o índice dos arrays e conta os clientes.
int qtd_estoque = 0;                                       // Controla o índice dos arrays e conta os estoques.
int qtd_aluguel = 0;                                       // Controla o índice dos arrays e conta os alugueis.

int estoque = 0;                                           // Usado para guardar a quantidade de filmes do estoque cadastrados


#define TAMANHO 100                                        // Define o tamanho de um vetor

//-----------------------------------------------------Variáveis Globais-----------------------------------------------------------------//


// Armazenamento dos dados
struct st_filmes{                                               // Struct para armazenar os filmes;







    int identificador;
    char titulo[40];
    int ano_de_producao;
    char genero[15];
} filmes[20]; // Inicializando o Struct com um vetor de 20 de tamanho, você só poderá cadastrar 20 filmes
struct st_clientes{                                            // Struct para armazenar os clientes;





    char nome[40];
    char cpf[12]; // Tamanho extra para o terminador \0
    char email[30]


} clientes[20]; // Inicializando o Struct com um vetor de 20 de tamanho, você só poderá cadastrar 20 clientes
struct st_estoque{                                            // Struct para estocar os filmes;



    char data_de_entrada[TAMANHO][10]; // Matriz com para armazenar 100 datas cada uma com 10 de tamanho

    char titulo_estoque[40];           // Guarda o titulo do cadastrar filme
    int ano_de_producao_estoque;       // Guarda o ano de produção do cadastrar filme
    char genero_estoque[15];           // Guarda o gênero do cadastrar filme
    int qtd_copias[TAMANHO];           // Guarda a qtd de cópias de um determinado filme que o usuário irá inserir.
    int soma_copias[TAMANHO];          // Guarda a soma das cópias que o usuário insere



} estoques[TAMANHO];                   // Inicializando o Struct com um vetor de 100 de tamanho, você só podera estocar 100 filmes
typedef struct {                                             // Struct para armazenar os alugueis;



    // ------- Clientes com cadastro ----------- //

    // Variáveis usadas para clientes com cadastro

    char data_de_aluguel_cliente[11];                  // Guarda a data de aluguel para o cliente
    char data_da_devolucao_cliente[11];                // Guarda a data de devolução para o cliente.

    char identificador_do_estoque_cliente[40];         // Guarda o nome do filme do estoque para o cliente
    int ano_de_producao_aluguel_cliente;               // Guarda o ano de produção do estoque para o cliente
    char genero_aluguel_cliente[15];                   // Guarda o genero do filme do estoque para o cliente
    int qtd_copias_aluguel_cliente[TAMANHO];           // Guarda a qtd de cópias do estoque para o cliente
    char data_de_entrada_aluguel_cliente[TAMANHO][10]; //  Guarda a data de entrada do estoque para o cliente

    // ------- Clientes com cadastro ----------- //


    // ------- Clientes sem cadastros ----------- //

    // Variáveis usadas para clientes sem cadastro

    char data_de_aluguel[11];                          // Guarda a a data de aluguel do filme
    char data_da_devolucao[11];                        // Guarda a data de devolução do filme

    char identificador_do_estoque[40];                 // Guarda o nome do filme do estoque
    int ano_de_producao_aluguel;                       // Guarda o ano de produção do estoque
    char genero_aluguel[15];                           // Guarda o ano de produção do estoque
    int qtd_copias_aluguel[TAMANHO];                   // Guarda a qtd de cópias do estoque
    char data_de_entrada_aluguel[TAMANHO][10];         //  Guarda a data de entrada do estoque

    // ------- Clientes sem cadastros ----------- //

}aluguel;                                              // Criando o tipo de dado do typedef

// Cadastro dos dados
void f_cadastrar_filme(){                                 // Função para cadastrar os filmes




    printf("\n\t\t\t==============\n");
    printf("\t\t\tCadastro filme");
    printf("\n\t\t\t==============           \n\n");

    if(qtd_filmes < 20){     // Habilitando o Limite de 20 filmes para cadastro


        printf("Diga-me o título do filme: ");
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s",&filmes[qtd_filmes].titulo);  // Pegando o input da forma correta, sem o \n

        printf("Diga-me o ano de produção do filme: ");
        setbuf(stdin,keyboard);
        scanf("%d",&filmes[qtd_filmes].ano_de_producao);

        // Verificação do ano de produção
        if(filmes[qtd_filmes].ano_de_producao > 2019 || filmes[qtd_filmes].ano_de_producao < 1895){  //Ano de produção > 2019 e < 1895



            printf("\nAno de produção inválido...(1895...2019)\n\n");
            system("pause");
            system("cls");
            f_cadastrar_filme();
        }
        printf("Diga-me o gênero do filme: ");
        setbuf(stdin,keyboard);
        scanf("%14[^\n]s",&filmes[i].genero);

        filmes[qtd_filmes].identificador = qtd_filmes; // Guarda o identificador de um filme a partir da qtd_filmes


        //Fazendo o banco de dados
        arq = fopen("Banco de dados filmes.txt","a");

        if(arq){     // Se o arquivo existir então irá documentar até 20 filmes descritos pelo usuário.

            if(qtd_filmes < 20){


                fprintf(arq,"\n\nIdentificador do filme %d: ",qtd_filmes); //Identificador
                fprintf(arq,"[%d]\n",filmes[qtd_filmes].identificador);

                fprintf(arq,"Título do filme %d: ",qtd_filmes);            // Título
                fprintf(arq,"[%s]\n",filmes[qtd_filmes].titulo);

                fprintf(arq,"Ano de produção do filme %d: ",qtd_filmes);   // Ano de produção
                fprintf(arq,"[%d]\n",filmes[qtd_filmes].ano_de_producao);

                fprintf(arq,"Gênero do filme %d: ",qtd_filmes);            // Gênero
                fprintf(arq,"[%s]\n",filmes[qtd_filmes].genero);

            }
        }
        else{

            printf("\nErro na abertura do arquivo... \n\n");
        }
        fclose(arq); //Fechando o arquivo após a manipulação




        ++qtd_filmes; // Após o usuário cadastrar o filme essa variável é incrementada, fazendo que conte quantos filmes foram cadastrados
        printf("\nCadastro realizado com sucesso!\n\n"); // Exibe uma mensagem ao finalizar um cadastro
        system("pause"); // Da uma pausa antes de executar a próxima linha de comando
        system("cls");   // Limpa o console
        menu_filme();    // Chamada de função

    }
    else{  // Caso ele já tenha cadastrado 20 filmes, então ele volta para o menu


        printf("\n\nVocê já cadastrou o número máximo de filmes... \n\n");
        system("pause");
        system("cls");
        menu_filme();
    }


}
void f_cadastrar_cliente(){                              // Função para cadastrar clientes




    char nomeador[20][40]; // Serve para armazenar o nome do cliente e comparar com nome da struct
    char cpfeador[20][12]; // Serve para armazenar o cpf do cliente e comparar com o cpf da struct
    char emaildor[20][30]; // Serve para armazenar o email do cliente e comparar com o cpf da struct
    int booleana = 0;      // Servirá para o controle do if/else da verificação de elementos cadastrados (0 false) - (1 - True)
    int e_digito = 0;      // Servirá para verificar se o CPF é digito ou não

    printf("\n\t\t\t================\n");
    printf("\t\t\tCadastro cliente");
    printf("\n\t\t\t================           \n\n");

    if(qtd_clientes < 20){    // Habilitando o limite de 20 clientes para cadastro



        printf("Diga-me o nome do cliente: ");
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s", &nomeador[qtd_clientes]);

        printf("Diga-me o cpf do cliente(Sem pontuação): ");
        setbuf(stdin,keyboard);
        scanf("%11[^\n]s", &cpfeador[qtd_clientes]);

        //Verificação do CPF
        for(int j = 0 ; j <= strlen(cpfeador[qtd_clientes]) ; j++){    // Laço percorre o tamanho da string




            if(isdigit(cpfeador[j])){  // Verifica se o cpf fornecido pelo usuário tem letras do alfabeto



                e_digito = 1; // Se tiver letras do alfabetos e_digito = 1
            }
            else{              // Se não tiver letras do alfabeto e_digito fica = 0



                e_digito = 0;
            }
        }
        //Verificação do CPF
        if(strlen(cpfeador[qtd_clientes]) != 11 || e_digito == 1 ){  // CPF conter números ou não tiver 11 digitos



            printf("\nCPF Inválido!(Sem pontos ou traços)...\n\n");
            system("pause");
            system("cls");
            f_cadastrar_cliente(); // Se o CPF for inválido chama a funão novamente!
        }

        printf("Diga-me o email do cliente: ");
        setbuf(stdin,keyboard);
        scanf("%29[^\n]s",&emaildor[qtd_clientes]);

        guardar = strrchr(emaildor[qtd_clientes],'@'); // Guarda a primeira ocorrência do @ na string

        //Verificação do email
        if( strcmp(guardar,validar_email[0]) != 0 && strcmp(guardar,validar_email[1]) != 0){

            // Se o usuário não digitar a formatação de um email correto então a função é retornada.


            printf("\nEmail inválido, Aceitamos somente o dominio gmail.com e hotmail.com, também verifique o uso do '@'...\n\n");
            system("pause");
            system("cls");
            f_cadastrar_cliente();
        }

        // Verificação de elementos iguais no cadastro
        for(j = 0 ; j < qtd_clientes ; j++){    // Laço para ver se existe os elementos igual a um que já está cadastrado no sistema



            if(strcmp(nomeador[qtd_clientes],clientes[j].nome) == 0 ||
                    strcmp(cpfeador[qtd_clientes],clientes[j].cpf) == 0 || strcmp(emaildor[qtd_clientes],clientes[j].email) == 0 ){


                /* Se os elementos que o usuário informar for igual a um os elementos da posição X do meu struct
                 *  então a booleana recebe 1 (TRUE), senão recebe 2 (FALSE)
                */
                booleana = 1;
            }
        }
        if(booleana == 1){    //Booleana == 1 elementos já existem no sistema.



            printf("\nElementos que você inseriu já estão cadastrados em outro cliente...\n\n");
            system("pause");
            system("cls");
            f_cadastrar_cliente();
        }
        else{

            // Elementos não existem no sistema, logo irei receber as informações que o usuário digitou.

            strcpy(clientes[qtd_clientes].nome,nomeador[qtd_clientes]); // Copia a 2 string na 1
            strcpy(clientes[qtd_clientes].cpf,cpfeador[qtd_clientes]);  // Copia a 2 string na 1
            strcpy(clientes[qtd_clientes].email,emaildor[qtd_clientes]); // Copia a 2 string na 1
            printf("\nCadastro realizado com sucesso!\n"); // Exibe uma mensagem ao finalizar o cadastro.
        }
    }
    else{     // Caso ele já tenha cadastrado 20 clientes, então ele volta para o menu



        printf("\n\nVocê já cadastrou o número máximo de clientes... \n\n");
        system("pause");
        system("cls");
        menu_cliente();
    }
    printf("\n\n");

    ++qtd_clientes;  // Após o usuário cadastrar o cliente essa variável é incrementada, fazendo que conte quantos clientes foram cadastrados.
    system("pause"); // Da uma pausa para a próxima linha de comando
    system("cls");   // Limpa o console
    menu_cliente();  // Chama a função de menu dos clientes

}
void f_cadastrar_estoque(){                             // Função para cadastrar filmes no estoque


    printf("\n\t\t\t================\n");
    printf("\t\t\tCadastro estoque");
    printf("\n\t\t\t================           \n\n");


    if(estoque < TAMANHO){    // O usuário só pode cadastrar 100 filmes no estoque



        printf("Diga-me o nome do filme para entrar no estoque: ");
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s",&estoques[qtd_estoque].titulo_estoque);


        for(i = 0 ; i < qtd_filmes ; i++){   // Conta de 0 até a quantidade de filmes já cadastrados no menu de filmes


            // Verificação de identificadores iguais
            if(strcmp(filmes[i].titulo,estoques[qtd_estoque].titulo_estoque) == 0){

                // Verifica se o identificador que o usuário cadastrou é igual aos filmes já cadastrados

                printf("\n");
                printf("Quantas copias deseja registrar?: ");
                setbuf(stdin,keyboard);
                scanf("%d",&estoques[i].qtd_copias[i]);

                estoques[i].soma_copias[i] += estoques[i].qtd_copias[i]; // Faz o aumento de cópias do filme no estoque

                printf("Diga-me a data de entrada desse filme no estoque (xx/xx/xxxx): ");
                setbuf(stdin,keyboard);
                scanf("%s",&estoques[i].data_de_entrada[i]);

                if(strlen(estoques[i].data_de_entrada[i]) != 10 ){   // Verifica se a data de entrega é válida



                    printf("\nData de entrada do estoque inválida (xx/xx/xxxx)...\n\n");
                    system("pause");
                    system("cls");
                    exit(1); // Se a data de entrega for inválida chama a função novamente!
                }
                printf("\nFilme cadastrado no estoque com sucesso! ");
                break;
            }

            else if(strcmp(filmes[i].titulo,estoques[qtd_estoque].titulo_estoque) != 0 && i == qtd_filmes-1){

                // Se o filme não estive cadastrado ainda, então o estoque dos filmes não é realizado.

                printf("\nO filme não existe no catálogo... \n\n");
                system("pause");
                system("cls");
                menu_estoque();
            }


        }

    }
    else{     // Caso ele já tenha cadastrado 100 filmes no estoque, então ele volta para o menu



        printf("\nVocê já fez o estoque do número máximo de filmes... \n\n");
        system("pause");
        system("cls");
        menu_estoque();
    }

    printf("\n\n");



    // Conseguindo os valores dos filmes e passando para o estoque
    strcpy(estoques[qtd_estoque].titulo_estoque,filmes[qtd_estoque].titulo);
    strcpy(estoques[qtd_estoque].genero_estoque,filmes[qtd_estoque].genero);
    estoques[qtd_estoque].ano_de_producao_estoque = filmes[qtd_estoque].ano_de_producao;


    //Fazendo o banco de dados
    arq = fopen("Banco de dados estoque.txt","a");

    if(arq){     // Se o arquivo existir então irá documentar até 100 filmes do estoque descritos pelo usuário

        if(estoque < TAMANHO){


            fprintf(arq,"\n\nTítulo do filme no estoque %d: ",qtd_estoque);        //Título
            fprintf(arq,"[%s]\n",estoques[qtd_estoque].titulo_estoque);

            fprintf(arq,"Gênero do filme no estoque %d: ",qtd_estoque);            // Gênero
            fprintf(arq,"[%s]\n",estoques[qtd_estoque].genero_estoque);

            fprintf(arq,"Ano de produção do filme no estoque %d: ",qtd_estoque);   // Ano de produção
            fprintf(arq,"[%d]\n",estoques[qtd_estoque].ano_de_producao_estoque);

            fprintf(arq,"Data de entrada do filme no estoque %d: ",qtd_estoque);   // Data de entrada
            fprintf(arq,"[%s]\n",estoques[qtd_estoque].data_de_entrada[qtd_estoque]);

            fprintf(arq,"Cópias do filme no estoque %d: ",qtd_estoque);            // Cópias
            fprintf(arq,"[%d]\n",estoques[qtd_estoque].soma_copias[qtd_estoque]);

        }
    }
    else{

        printf("\nErro na abertura do arquivo... \n\n");
    }
    fclose(arq); //Fechando o arquivo após a manipulação




    estoque += estoques[qtd_estoque].qtd_copias[qtd_estoque]; // Conta quantos filmes no estoque foram cadastrados
    ++qtd_estoque;    // Adicionado 1 a qtd de estoque sempre quando a função é finaliza com sucesso
    system("pause");  // Da uma pausa antes de executar a próxima linha de comando
    system("cls");    // Limpa o console
    menu_estoque();   // Chamada de função




}
void f_cadastar_aluguel_por_cliente(){                 // Função para cadastrar o aluguel por cliente

aluguel alugar[TAMANHO];

    printf("\n\t\t\t============================\n");
    printf("\t\t\tCadastro aluguel por cliente");
    printf("\n\t\t\t============================           \n\n");


    if(qtd_aluguel < TAMANHO && estoque !=0){    // O cliente pode alugar até 100 filmes e qnd o estoque for diferente de 0


        printf("Diga-me o nome do cliente: ");
        setbuf(stdin,keyboard);
        scanf("%39[^\n]s",&cliente_consulta);

        //Verificando do nome do cliente e atribuindo os dados.
        for(i = 0 ; i <= estoque ; i++){  // Conta de 0 até a quantidade de filmes cadastrados no estoque.


            if(strcmp(cliente_consulta,clientes[i].nome) == 0){


                printf("Diga-me o nome do filme: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s",&estoque_consulta);

                // Verificação do nome do filme.
                if(strcmp(estoque_consulta,estoques[i].titulo_estoque) == 0){


                    // Recebendo as informações do usuário.
                    strcpy(alugar[i].identificador_do_estoque_cliente,estoques[i].titulo_estoque); // nome do filme
                    strcpy(alugar[i].genero_aluguel_cliente,estoques[i].genero_estoque); // gênero do filme
                    strcpy(alugar[i].data_de_entrada_aluguel_cliente[i],estoques[i].data_de_entrada[i]); // data de entrada
                    alugar[i].ano_de_producao_aluguel_cliente = estoques[i].ano_de_producao_estoque; // aluguel do filme
                    alugar[i].qtd_copias_aluguel_cliente[i] += (estoques[i].soma_copias[i] - estoques[i].soma_copias[i]) + 1;// qtd cópias
                    --estoques[i].soma_copias[i]; // Remove uma cópia do estoque de um determinado filme
                }
                else if(strcmp(estoque_consulta,estoques[i].titulo_estoque) != 0){ // Só executará quando o for terminar


                    // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                    printf("\nEsse filme não está cadastrado em nossa locadora... \n\n");
                    system("pause");
                    system("cls");
                    menu_aluguel();
                }

                printf("Insira a data de aluguel desse filme (xx/xx/xxxx): ");
                setbuf(stdin,keyboard);
                scanf("%10[^\n]s",alugar[i].data_de_aluguel_cliente);

                printf("Insira a data de devolução desse filme (xx/xx/xxxx): ");
                setbuf(stdin,keyboard);
                scanf("%10[^\n]s",alugar[i].data_da_devolucao_cliente);

                printf("\nAluguel realizado com sucesso! "); // Exibe uma mensagem ao finalizar um cadastro
                break;
            }
            else if(strcmp(cliente_consulta,clientes[i].nome) != 0 && i == qtd_clientes-1){

                // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                printf("\nEsse cliente não está cadastrado em nossa locadora... \n\n");
                system("pause");
                system("cls");
                menu_aluguel();
            }
        }

    }
    else{  // Caso ele já tenha alugado 100 filmes OU não tenha cadastrado um filme ou cliente, então ele volta para o menu


        printf("\nVocê já alugou o número máximo de filmes! Ou ainda não cadastrou um cliente/filme na locadora... \n\n");
        system("pause");
        system("cls");
        menu_aluguel();
    }

    printf("\n\n");
    ++qtd_aluguel; // Conta a qtd de filmes alugados
    system("pause"); // Da uma pausa antes de executar a próxima linha de comando
    system("cls");   // Limpa o console
    menu_aluguel();    // Chamada de função


}
void f_cadastrar_aluguel(){                           // Função para cadastrar o aluguel

aluguel alugar[TAMANHO];

    printf("\n\t\t\t================\n");
    printf("\t\t\tCadastro aluguel");
    printf("\n\t\t\t================           \n\n");


    if(qtd_aluguel < TAMANHO && estoque !=0){    // O Usuário poderá cadastrar até 100 filmes e qnd o estoque for != 0


        //Verificando do nome do cliente e atribuindo os dados.
        for( i = 0 ; i <= estoque ; i++){  // Conta de 0 até a quantidade de filmes cadastrados no estoque.



            printf("Diga-me o identificador do filme: ");
            setbuf(stdin,keyboard);
            scanf("%d",&consulta);
            // Verificação do nome do filme.
            if(filmes[i].identificador == consulta){


                // Recebendo as informações do usuário.
                strcpy(alugar[i].identificador_do_estoque,estoques[i].titulo_estoque); // nome do filme
                strcpy(alugar[i].genero_aluguel,estoques[i].genero_estoque); //gênero do filme
                strcpy(alugar[i].data_de_entrada_aluguel[i],estoques[i].data_de_entrada[i]); //data de entrada
                alugar[i].ano_de_producao_aluguel = estoques[i].ano_de_producao_estoque; //aluguel do filme
                alugar[i].qtd_copias_aluguel[i] += (estoques[i].soma_copias[i] - estoques[i].soma_copias[i]) + 1; // copias do filme
                --estoques[i].soma_copias[i]; // Remove uma cópia do estoque de um determinado filme
            }
            else{

                // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                printf("\nEsse filme não está cadastrado em nossa locadora... \n\n");
                system("pause");
                system("cls");
                menu_aluguel();
            }

            printf("Insira a data de aluguel desse filme (xx/xx/xxxx): ");
            setbuf(stdin,keyboard);
            scanf("%10[^\n]s",alugar[i].data_de_aluguel);

            printf("Insira a data de devolução desse filme (xx/xx/xxxx): ");
            setbuf(stdin,keyboard);
            scanf("%10[^\n]s",alugar[i].data_da_devolucao);

            printf("\nAluguel realizado com sucesso!\n"); // Exibe uma mensagem ao finalizar um cadastro
            break;
        }
    }


    else{  // Caso ele já tenha alugado 100 filmes OU não tenha cadastrado um filme ou cliente, então ele volta para o menu


        printf("\nVocê já alugou o número máximo de filmes! Ou ainda não cadastrou um cliente/filme na locadora... \n\n");
        system("pause");
        system("cls");
        menu_aluguel();
    }

    printf("\n\n");
    ++qtd_aluguel; // Conta a qtd de filmes alugados
    system("pause"); // Da uma pausa antes de executar a próxima linha de comando
    system("cls");   // Limpa o console
    menu_aluguel();    // Chamada de função


}

// Listagem dos dados
void f_listar_filmes(){                            // Função para listar os filmes





    printf("\n\t\t\t============\n");
    printf("\t\t\tListar filme");
    printf("\n\t\t\t============           \n\n");

    printf(" Título                                       Gênero               Ano de produção   Identificador   \n");
    printf("|-------------------------------------------|--------------------|------------------|---------------|\n");
    for(i = 0 ; i < qtd_filmes ; i++){






        if(filmes[i].identificador == -1){      // Condição para não mostrar o filme apagado.


            continue; // Se o filme existir na memória, então as linhas de baixo não são executadas.
        }

        printf("|[%s]",filmes[i].titulo);
        printf("\t\t\t\t\t[%s]",filmes[i].genero);
        printf("\t\t[%d]",filmes[i].ano_de_producao);
        printf("\t\t[%d]\n",filmes[i].identificador);
        printf("|-------------------------------------------|--------------------|------------------|---------------|");
        printf("\n");


    }
    printf("\n");
    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_filme();    // Chama a função novamente


}
void f_listar_clientes(){                         // Função para listar os clientes





    printf("\n\t\t\t==============\n");
    printf("\t\t\tListar cliente");
    printf("\n\t\t\t==============           \n\n");

    printf(" Nome                                        CPF                              Email   \n");
    printf("|-------------------------------------------|--------------------|-------------------------------|\n");
    for(j = 0 ; j < qtd_clientes ; j++){






        if(strlen(clientes[j].nome) == 0){      // Condição para não mostrar o cliente apagado.





            continue; // Se o cliente existir na memória, então as linhas de baixo não são executadas.
        }
        printf("|[%s]",clientes[j].nome);
        printf("\t\t\t\t\t[%s]",clientes[j].cpf);
        printf("\t\t[%s]\n",clientes[j].email);
        printf("|-------------------------------------------|--------------------|-------------------------------|");
        printf("\n");
    }
    printf("\n");
    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_cliente();  // Chama a função novamente

}
void f_listar_estoque(){                         // Função para listar o estoque


    printf("\n\t\t\t==============\n");
    printf("\t\t\tListar estoque");
    printf("\n\t\t\t==============           \n\n");

    printf(" Título                                       Gênero               Ano de produção   Data de entrada Qtd de cópias \n");
    printf("|-------------------------------------------|--------------------|------------------|---------------|-------------|\n");
    for(i = 0 ; i <= estoque ; i++){



        if(strlen(estoques[i].titulo_estoque) == 0 || estoques[i].ano_de_producao_estoque == 0){  //não mostra o filme do estoque apagado.


            continue; // Se o filme existir na memória, então as linhas de baixo não são executadas.
        }

        printf("|[%s]",estoques[i].titulo_estoque);
        printf("\t\t\t\t\t[%s]",estoques[i].genero_estoque);
        printf("\t\t[%d]",estoques[i].ano_de_producao_estoque);
        printf("\t\t[%s]",estoques[i].data_de_entrada[i]);
        printf("\t[%d]\n",estoques[i].soma_copias[i]);
        printf("|-------------------------------------------|--------------------|------------------|---------------|-------------|");
        printf("\n");

    }
    printf("\n");
    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_estoque();  // Chama a função novamente


}
void f_listar_aluguel_por_cliente(){            // Função para listar o aluguel por cliente

aluguel alugar[TAMANHO];


    printf("\n\t\t\t====================================\n");
    printf("\t\t\tListar aluguel do filmes por cliente");
    printf("\n\t\t\t====================================          \n\n");


    printf("Diga-me o nome do cliente: ");
    setbuf(stdin,keyboard);
    scanf("%39[^\n]s",&cliente_consulta);

    //Verificando do nome do cliente.
    for(i = 0 ; i < qtd_aluguel ; i++){


        if(strcmp(cliente_consulta,clientes[i].nome) == 0){



            printf("\n");
            printf(" Título                                       Gênero               Ano de produção   Data de entrada Qtd de cópias \n");
            printf("|-------------------------------------------|--------------------|------------------|---------------|-------------|\n");

            if(alugar[i].ano_de_producao_aluguel_cliente == 0){      // Condição para não mostrar o filme do estoque apagado.


                continue; // Se o filme existir na memória, então as linhas de baixo não são executadas.
            }

            printf("|[%s]",alugar[i].identificador_do_estoque_cliente);
            printf("\t\t\t\t\t[%s]",alugar[i].genero_aluguel_cliente);
            printf("\t\t[%d]",alugar[i].ano_de_producao_aluguel_cliente);
            printf("\t\t[%s]",alugar[i].data_de_entrada_aluguel_cliente[i]);
            printf("\t[%d]\n",alugar[i].qtd_copias_aluguel_cliente[i]);
            printf("|-------------------------------------------|--------------------|------------------|---------------|-------------|");
            printf("\n");


            break; // Se o nome do cliente estiver correto, irá sair do for
        }
        else if(strcmp(cliente_consulta,clientes[i].nome) != 0 && i == qtd_aluguel-1){

            // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("\nEsse cliente ou filme não está cadastrado em nossa locadora... \n\n");
            system("pause");
            system("cls");
            menu_aluguel();
        }
    }



    printf("\n");
    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_aluguel();  // Chama a função novamente



}
void f_listar_aluguel(){                       // Função para listar o aluguel

aluguel alugar[TAMANHO];

    printf("\n\t\t\t==============\n");
    printf("\t\t\tListar aluguel");
    printf("\n\t\t\t==============          \n\n");

    //Verificando do nome do filme.
    for(i = 0 ; i < qtd_aluguel ; i++){


        printf("\n");
        printf(" Título                                       Gênero               Ano de produção   Data de entrada Qtd de cópias \n");
        printf("|-------------------------------------------|--------------------|------------------|---------------|-------------|\n");

        if(alugar[i].ano_de_producao_aluguel == 0){      // Condição para não mostrar o filme do estoque apagado.


            continue; // Se o filme existir na memória, então as linhas de baixo não são executadas.
        }
        printf("|[%s]",alugar[i].identificador_do_estoque);
        printf("\t\t\t\t\t[%s]",alugar[i].genero_aluguel);
        printf("\t\t[%d]",alugar[i].ano_de_producao_aluguel);
        printf("\t\t[%s]",alugar[i].data_de_entrada_aluguel[i]);
        printf("\t[%d]\n",alugar[i].qtd_copias_aluguel[i]);
        printf("|-------------------------------------------|--------------------|------------------|---------------|-------------|");
        printf("\n");
        break; // Se o nome do filme estiver correto, irá sair do for
    }
    printf("\n");
    system("pause"); // Da uma pausa antes da próxima linha de comando
    system("cls");   // Limpa o console
    menu_aluguel();  // Chama a função novamente

}

// Consulta dos dados
void f_consultar_filmes(){                  // Função para consultar os filmes





    printf("\n\t\t\t=================\n");
    printf("\t\t\tConsultar o filme");
    printf("\n\t\t\t=================           \n\n");

    printf("Diga-me o identificador do filme a ser consultado: ");
    scanf("%d",&consulta);
    printf("\n");

    for(i = 0 ; i < qtd_filmes ; i++){


        if(filmes[i].identificador == -1) {}    // Condição para não mostrar o filme apagado.

        if(consulta == filmes[i].identificador){



            printf("O filme existe em nosso catálogo! \n");
            break;
        }
        else if(consulta != filmes[i].identificador & i == qtd_filmes-1){

            // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("O filme não existe em nosso catálogo... \n");
        }
    }
    printf("\n\tConsultar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");

    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){    // Se ele digitar um a função de consultar filmes é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_consultar_filmes();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu





        system("cls");
        menu_filme();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_consultar_filmes();

    }


}
void f_consultar_clientes(){               // Função para consultar os clientes







    printf("\n\t\t\t===================\n");
    printf("\t\t\tConsultar o cliente");
    printf("\n\t\t\t===================           \n\n");

    printf("Diga-me o nome do cliente a ser consultado: ");
    scanf("%s",&cliente_consulta); // Armazena o nome que o usuário digitou

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){






        if(strlen(clientes[j].nome) == 0) {}

        if(strcmp(cliente_consulta,clientes[j].nome) == 0){





            printf("Esse cliente está cadastrado em nossa locadora. \n");
            break;
        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){      //Só executará a ação quando o laço for terminar




            // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("Esse cliente não está cadastrado em nossa locadora... \n");
        }
    }

    printf("\n\tConsultar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    scanf("%d",&escolha);  // Armazena a escolha do usuário

    if(escolha == 1){    // Se ele digitar um a função de consultar clientes é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_consultar_clientes();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu






        system("cls");
        menu_cliente();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n");
        system("pause");
        system("cls");
        f_consultar_clientes();

    }


}
void f_consultar_estoque(){               // Função para consultar o estoque


    printf("\n\t\t\t===================\n");
    printf("\t\t\tConsultar o estoque");
    printf("\n\t\t\t===================           \n\n");

    printf("Diga-me o nome do filme a ser consultado: ");
    scanf("%s",&estoque_consulta); // Armazena o nome do estoque que o usuário digitou

    printf("\n");

    for(i = 0 ; i <= estoque ; i++){





        //não mostra o filme do estoque apagado.
        if(strlen(estoques[i].titulo_estoque) == 0 || estoques[i].ano_de_producao_estoque == 0 ) {}

        if(strcmp(estoque_consulta,estoques[i].titulo_estoque) == 0){





            printf("O filme existe em nosso estoque! \n");
            break;
        }
        else if(strcmp(estoque_consulta,estoques[i].titulo_estoque) != 0 && i == estoque){




            // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("O filme não está em nosso estoque... \n");
        }
    }
    printf("\n\tConsultar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){    // Se ele digitar um a função de consultar estoque é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_consultar_estoque();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu





        system("cls");
        menu_estoque();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_consultar_estoque();

    }


}
void f_consultar_aluguel_por_cliente(){  // Função para consultar o aluguel por cliente

aluguel alugar[TAMANHO];
    printf("\n\t\t\t======================================\n");
    printf("\t\t\tConsultar aluguel do filme por cliente");
    printf("\n\t\t\t======================================           \n\n");

    printf("Diga-me o nome do cliente: ");
    setbuf(stdin,keyboard);
    scanf("%39[^\n]s",&cliente_consulta);  // Pegando o input da forma correta, sem o \n

    //Verificando do nome do cliente.
    for(i = 0 ; i < qtd_aluguel ; i++){


        if(strcmp(cliente_consulta,clientes[i].nome) == 0){


            if(alugar[i].ano_de_producao_aluguel_cliente == 0){

                continue;   // Condição para não mostra o filme apagado
            }
            printf("\n");
            printf("|--------------------------------------\n");
            printf("|Nº:        [%d]\n",i+1);
            printf("|Filme:     [%s]\n",alugar[i].identificador_do_estoque_cliente);
            printf("|Gênero:    [%s]\n",alugar[i].genero_aluguel_cliente);
            printf("|Ano de Produção: [%d]\n",alugar[i].ano_de_producao_aluguel_cliente);
            printf("|Data de entrada: [%s]\n",alugar[i].data_de_entrada_aluguel_cliente[i]);
            printf("|Cópias:    [%d]\n",alugar[i].qtd_copias_aluguel_cliente[i]);
            printf("|Aluguel:   [%s]\n",alugar[i].data_de_aluguel_cliente);
            printf("|Devolução: [%s]\n",alugar[i].data_da_devolucao_cliente);
            printf("|--------------------------------------");
            printf("\n");

            break; // Se o nome do cliente estiver correto, irá sair do for
        }
        else if(strcmp(cliente_consulta,clientes[i].nome) != 0 && i == qtd_aluguel-1){//Só executará a ação quando o laço for terminar

            // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("\nEsse cliente ou filme não está cadastrado em nossa locadora... \n\n");
            system("pause");
            system("cls");
            menu_aluguel();
        }
    }



    printf("\n\tConsultar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){    // Se ele digitar um a função de consultar aluguel é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_consultar_aluguel_por_cliente();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu



        system("cls");
        menu_aluguel();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_consultar_aluguel_por_cliente();

    }


}
void f_consultar_aluguel(){             // Função para consultar o aluguel

aluguel alugar[TAMANHO];
    printf("\n\t\t\t=================\n");
    printf("\t\t\tConsultar aluguel");
    printf("\n\t\t\t=================           \n\n");

    printf("Diga-me o identificador do filme: ");
    setbuf(stdin,keyboard);
    scanf("%d",&consulta);  // Pegando o input da forma correta, sem o \n

    //Verificando do nome do filme.
    for(i = 0 ; i < qtd_aluguel ; i++){


        if(filmes[i].identificador == consulta){


            if(alugar[i].ano_de_producao_aluguel == 0){

                continue;   // Condição para não mostra o filme apagado
            }
            printf("\n");
            printf("|--------------------------------------\n");
            printf("|Nº:        [%d]\n",i+1);
            printf("|Filme:     [%s]\n",alugar[i].identificador_do_estoque);
            printf("|Gênero:    [%s]\n",alugar[i].genero_aluguel);
            printf("|Ano de Produção: [%d]\n",alugar[i].ano_de_producao_aluguel);
            printf("|Data de entrada: [%s]\n",alugar[i].data_de_entrada_aluguel[i]);
            printf("|Cópias:    [%d]\n",alugar[i].qtd_copias_aluguel[i]);
            printf("|Aluguel:   [%s]\n",alugar[i].data_de_aluguel);
            printf("|Devolução: [%s]\n",alugar[i].data_da_devolucao);
            printf("|--------------------------------------");
            printf("\n");

            break; // Se o nome do filme estiver correto, irá sair do for
        }
        else{      //Só executará a ação quando o laço for terminar

            // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("\nEsse filme não está cadastrado em nossa locadora... \n\n");
            system("pause");
            system("cls");
            menu_aluguel();
        }
    }



    printf("\n\tConsultar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){    // Se ele digitar um a função de consultar aluguel é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_consultar_aluguel();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu





        system("cls");
        menu_aluguel();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_consultar_aluguel();

    }



}

// Visualização dos dados
void f_visualizar_filme(){           // Função para visualizar o filme





    printf("\n\t\t\t==================\n");
    printf("\t\t\tVisualizar o filme");
    printf("\n\t\t\t==================            \n\n");

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
        else if(consulta != filmes[i].identificador && i == qtd_filmes-1){    //Só executará a ação quando o laço for terminar




            // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("Filme não encontrado... \n");
        }
    }
    printf("\n\tVisualizar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){     // Se ele digitar um a função de visualizar filmes é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_visualizar_filme();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu





        system("cls");
        menu_filme();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_visualizar_filme();
    }

}
void f_visualizar_clientes(){       // Função para visualizar o cliente





    printf("\n\t\t\t====================\n");
    printf("\t\t\tVisualizar o cliente");
    printf("\n\t\t\t====================            \n\n");

    printf("Diga-me o nome do cliente a ser visualizado: ");
    scanf("%s",cliente_consulta); // Armazena o nome que o usuário digitou

    printf("\n");

    for(j = 0 ; j < qtd_clientes ; j++){





        //Mostra as informações se na comparação retornar true
        if(strcmp(cliente_consulta,clientes[j].nome) == 0 && strcmp(cliente_consulta,"") != 0){



            printf("Nome: [%s]:  \n",clientes[j].nome);
            printf("CPF: [%s] \n",  clientes[j].cpf);
            printf("Email: [%s] \n",clientes[j].email);
            printf("\n\n");
            break;

        }
        else if(strcmp(cliente_consulta,clientes[j].nome) != 0 & j == qtd_clientes-1){ //Só executará a ação quando o laço for terminar




            // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("Cliente não encontrado... \n");
        }
    }
    printf("\n\tVisualizar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){    // Se ele digitar um a função de visualizar clientes é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_visualizar_clientes();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu






        system("cls");
        menu_cliente();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_visualizar_clientes();
    }

}
void f_visualizar_estoque(){       // Função para visualizar item no estoque





    printf("\n\t\t\t====================\n");
    printf("\t\t\tVisualizar o estoque");
    printf("\n\t\t\t====================            \n\n");

    printf("Diga-me o nome do filme a ser visualizado: ");
    scanf("%s",estoque_consulta); // Armazena o nome do estoque que o usuário digitou

    printf("\n");

    for(i = 0 ; i <= estoque ; i++){



        if(strcmp(estoque_consulta,estoques[i].titulo_estoque) == 0 && strcmp(estoque_consulta,"") != 0){




            printf("Filme [%i]:  \n",i+1);
            printf("Título: [%s]\n",estoques[i].titulo_estoque);
            printf("Gênero: [%s]\n",estoques[i].genero_estoque);
            printf("Ano de produção: [%d]\n",estoques[i].ano_de_producao_estoque);
            printf("Data de entrada: [%s]\n",estoques[i].data_de_entrada[i]);
            printf("Quantidade de cópias: [%d]\n",estoques[i].soma_copias[i]);
            printf("\n\n");
            break;

        }
        else if(strcmp(estoque_consulta,estoques[i].titulo_estoque) != 0 && i == estoque){

            // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
            printf("Filme no estoque não encontrado... \n");
        }
    }
    printf("\n\tVisualizar novamente?\n\n");
    printf("\t\t[1] - Sim\n\n");
    printf("\t\t[2] - Não\n\n");
    printf("\t\tEscolha a opção: ");
    scanf("%d",&escolha); // Armazena a escolha do usuário

    if(escolha == 1){     // Se ele digitar um a função de visualizar o estoque é chamada novamente




        printf("\n");
        system("pause");
        system("cls");
        f_visualizar_estoque();
    }
    else if(escolha == 2){    // Se 2 ele é direcionado para o menu




        system("cls");
        menu_estoque();
    }
    else{    // Caso ele digita um número que não pertença as opções acima




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_visualizar_estoque();
    }

}

// Edição dos dados
void f_editar_filme(){          // Função para editar o filme


    printf("\n\t\t\t==============\n");
    printf("\t\t\tEditar o filme");
    printf("\n\t\t\t==============               \n\n");

    printf("\t\t[1] - Atualizar filme \n\n");
    printf("\t\t[2] - Excluir filme   \n\n");
    printf("\t\t[3] - Voltar                     \n\n");
    printf("Escolha a opção: ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){    // Se o número digitado for 1 então irá atualizar o filme






        printf("\nDiga-me o identificador do filme a ser atualizado: ");
        scanf("%d",&consulta);  // Armazena o filme que o usuário digitou
        printf("\n");
        for(i = 0 ; i < qtd_filmes ; i++){




            if(consulta == filmes[i].identificador){




                // Pedindo novas informações para atualização do filme


                printf("Diga-me o título do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s",filmes[i].titulo);

                printf("Diga-me o ano de produção do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%d",&filmes[i].ano_de_producao);

                if(filmes[i].ano_de_producao > 2019 || filmes[i].ano_de_producao < 1895){  // Ano 1895 > < 2019



                    printf("\nAno de produção inválido...(1895...2019)\n\n");
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
            else if(consulta != filmes[i].identificador && i == qtd_filmes-1){    // Só executará a ação quando o laço for terminar




                // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                printf("Filme não encontrado... \n");
            }
        }


        printf("\n\t\tAtualizar novamente?\n\n");
        printf("\t\t[1] - Sim\n\n");
        printf("\t\t[2] - Não\n\n");
        printf("\t\tEscolha a opção: ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){    // Se ele digitar um a função de editar filmes é chamada novamente




            printf("\n");
            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){     // Se 2 ele é direcionado para o menu





            system("cls");
            menu_filme();
        }
        else{    // Caso ele digita um número que não pertença as opções acima




            printf("\n");
            printf("Valor não reconhecido... \n\n");
            system("pause");
            system("cls");
            f_editar_filme();
        }
    }

    else if(escolha == 2){    // Se o número digitado for 2 então irá excluir o filme







        printf("Diga-me o identificador do filme a ser excluído: ");
        scanf("%d",&consulta); // Armazena o filme que o usuário digitou

        for(i = 0 ; i < qtd_filmes ; i++){






            if(consulta == filmes[i].identificador){  // "Apagando" Os filmes da Random Acess Memory




                // Faz com que o identificador fique nulo, assim parecendo que foi apagado da memória e não mostrando nos menus.
                filmes[i].identificador = 0;
                --qtd_filmes; // Remove um filme
                printf("\nFilme excluído com sucesso! \n");
                break;
            }

            else if(consulta != filmes[i].identificador && i == qtd_filmes-1 ){// Só executa a ação quando o laço for terminar




                // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                printf("Filme não encontrado... \n");
            }
        }


        printf("\n\tExcluir novamente?\n\n");
        printf("\t\t[1] - Sim\n\n");
        printf("\t\t[2] - Não\n\n");
        printf("\t\tEscolha a opção: ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){    // Se ele digitar um a função de editar filmes é chamada novamente




            printf("\n");
            system("pause");
            system("cls");
            f_editar_filme();
        }
        else if(escolha == 2){   // Se 2 ele é direcionado para o menu





            system("cls");
            menu_filme();
        }
        else{    // Caso ele digita um número que não pertença as opções acima




            printf("\n");
            printf("Valor não reconhecido... \n");
            system("pause");
            system("cls");
            f_editar_filme();
        }

    }

    else if(escolha == 3){    // Se o número digitado for 3 então irá voltar para o menu





        system("cls");
        menu_filme();
    }

    else{    // Caso ele digita um número diferente de 1 2 ou 3.




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_editar_filme();
    }

}
void f_editar_clientes(){      // Função para editar os clientes




    char nomeador[20][40]; // Serve para armazenar o nome do cliente e comparar com nome da struct
    char cpfeador[20][12]; // Serve para armazenar o cpf do cliente e comparar com o cpf da struct
    char emaildor[20][30]; // Serve para armazenar o email do cliente e comparar com o cpf da struct
    int booleana = 0; // Servirá para o controle do if/else da verificação de elementos cadastrados (0 false) - (1 - True)
    int e_digito = 0; // Servirá para verificar se o CPF é digito ou não

    printf("\n\t\t\t================\n");
    printf("\t\t\tEditar o cliente");
    printf("\n\t\t\t================               \n\n");

    printf("\t\t[1] - Atualizar cliente \n\n");
    printf("\t\t[2] - Excluir cliente   \n\n");
    printf("\t\t[3] - Voltar                     \n\n");
    printf("Escolha a opção: ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){    // Se o número digitado for 1 então irá atualizar o cliente






        printf("\nDiga-me o nome do cliente a ser atualizado: ");
        scanf("%s",&cliente_consulta); // Variável responsável por armazenar e comparar o nome que o usuário digitar
        printf("\n");
        for(j = 0 ; j < qtd_clientes ; j++){





            // Se o nome que o usuário digitou consta no sistema então ele atualizará
            if(strcmp(cliente_consulta,clientes[j].nome) == 0){




                // Pedindo novas informações para atualização do cliente

                printf("Diga-me o novo nome do cliente: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s", &nomeador[qtd_clientes]);

                printf("Diga-me o novo cpf do cliente(Sem pontuação): ");
                setbuf(stdin,keyboard);
                scanf("%11[^\n]s",&cpfeador[qtd_clientes]);

                //Verificação do CPF
                for(int j = 0 ; j <= strlen(cpfeador[qtd_clientes]) ; j++){    // Laço percorre o tamanho da string





                    if(isdigit(cpfeador[j])){    // Verifica se o cpf fornecido pelo usuário tem letras do alfabeto



                        e_digito = 1; // Se tiver letras do alfabetos e_digito = 1
                    }
                    else{    // Se não tiver letras do alfabeto e_digito fica = 0



                        e_digito = 0;
                    }
                }

                if(strlen(cpfeador[qtd_clientes]) != 11 || e_digito == 1){ // Cpf n pode ter letras ou != 11 numeros



                    printf("\nCPF Inválido!(Sem pontos ou traços)... \n\n");
                    system("pause");
                    exit(1);
                }

                printf("Diga-me o novo email do cliente: ");
                setbuf(stdin,keyboard);
                scanf("%29[^\n]s",&emaildor[qtd_clientes]);

                guardar = strrchr(emaildor[qtd_clientes],'@'); // Guarda a primeira ocorrência do @ na string

                if( strcmp(guardar,validar_email[0]) != 0 && strcmp(guardar,validar_email[1]) != 0){  // Valida o email




                    printf("\nEmail inválido, Aceitamos somente o dominio gmail.com e hotmail.com, também verifique o uso do '@'...\n\n");
                    system("pause");
                    exit(1);
                }

                // Verificação de elementos iguais
                for(int j = 0 ; j < qtd_clientes ; j++){

                    // Laço para ver se existe os elementos igual a um que já está cadastrado no sistema

                    // É criado uma nova variável para percorrer somente nesse for e não se intrometer nos demais
                    if(strcmp(nomeador[qtd_clientes],clientes[j].nome) == 0 || strcmp(cpfeador[qtd_clientes],clientes[j].cpf) == 0
                            || strcmp(emaildor[qtd_clientes],clientes[j].email) == 0 ){

                        // Se os elementos que o usuário informar for igual a um os elementos da posição X do meu struct
                        // Então a booleana recebe 1, senão n recebe

                        booleana = 1;
                    }
                }
                if(booleana == 1){    // Se a booleana for igual a 1 quer dizer que esses elementos já existe no sistema



                    printf("\nElementos que você inseriu já estão cadastrados em outro cliente...\n\n");
                    system("pause");
                    exit(1); // Se os elementos for inválido o programa é fechado
                }
                else{    // Se a booleana não for 1 então os elementos não existem no sistema, logo irei receber as informações



                    strcpy(clientes[j].nome,nomeador[qtd_clientes]); // Copia a 2 string na 1
                    strcpy(clientes[j].cpf,cpfeador[qtd_clientes]);  // Copia a 2 string na 1
                    strcpy(clientes[j].email,emaildor[qtd_clientes]); // Copia a 2 string na 1
                }

                printf("\n\n");
                printf("\nCliente atualizado com sucesso! \n");
                break;
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){

                // Só executará a ação quando o laço for terminar


                // Se o nome que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                printf("Cliente não encontrado... \n");
            }
        }


        printf("\n\t\tAtualizar novamente?\n\n");
        printf("\t\t[1] - Sim\n\n");
        printf("\t\t[2] - Não\n\n");
        printf("\t\tEscolha a opção: ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){     // Se ele digitar um a função de editar clientes é chamada novamente




            printf("\n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){    // Se ele digitar dois é direcionado para o menu





            system("cls");
            menu_cliente();
        }
        else{    // É executado somente se o usuário digitar um valor inválido




            printf("\n");
            printf("Valor não reconhecido... \n\n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }
    }

    else if(escolha == 2){    // Se o número digitado for 1 então irá excluir o cliente







        printf("\nDiga-me o nome do cliente a ser excluído: ");
        scanf("%s",cliente_consulta); // Armazena o nome do cliente

        for(j = 0 ; j < qtd_clientes ; j++){






            if(strcmp(cliente_consulta,clientes[j].nome) == 0){  // "Apagando" Os usuários da Random Acess Memory




                // Faz com que os elementos fiquem nulo assim parecendo que foi apagado da memória e não mostrrando nos menus.
                strcpy(clientes[j].nome,"");
                strcpy(clientes[j].cpf,"");
                strcpy(clientes[j].email,"");
                --qtd_clientes; // Remove um cliente
                printf("\nCliente excluído com sucesso! \n");
                break;
            }

            else if(strcmp(cliente_consulta,clientes[j].nome) != 0 && j == qtd_clientes-1){

                // Executa essa ação quando o laço for termina


                // Se o nome que o usuário digitou não consta no sistema então exibirá essa mensagem
                printf("\nCliente não encontrado... \n");
            }
        }


        printf("\n\tExcluir novamente?\n\n");
        printf("\t\t[1] - Sim\n\n");
        printf("\t\t[2] - Não\n\n");
        printf("\t\tEscolha a opção: ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){    // Se ele digitar um a função de editar cliente é chamada novamente




            printf("\n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }
        else if(escolha == 2){    // Se ele digitar dois é direcionado para o menu




            system("cls");
            menu_cliente();
        }
        else{    // É executado somente se o usuário digitar um valor inválido




            printf("\n");
            printf("Valor não reconhecido... \n\n");
            system("pause");
            system("cls");
            f_editar_clientes();
        }

    }

    else if(escolha == 3){    // Se o usuário digitar 3 ele é direcionado para o menu





        system("cls");
        menu_cliente();
    }

    else{    // É executado caso ele digite um número diferente de 1 2 ou 3




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_editar_clientes();
    }

}
void f_editar_estoque(){      // Função para editar o estoque




    int identificador; // Serve para armazenar o identificador do filme do estoque e comparar com o identificador da struct

    printf("\n\t\t\t================\n");
    printf("\t\t\tEditar o estoque");
    printf("\n\t\t\t================               \n\n");

    printf("\t\t[1] - Atualizar filme no estoque \n\n");
    printf("\t\t[2] - Excluir filme no estoque   \n\n");
    printf("\t\t[3] - Voltar                     \n\n");
    printf("Escolha a opção: ");
    scanf("%d",&escolha); // Armazena a opção do usuário

    if(escolha == 1){    // Se o número digitado for 1 então irá atualizar o filme no estoque



        printf("\nDiga-me o nome do filme a ser atualizado: ");
        scanf("%s",&estoque_consulta);  // Armazena o filme que o usuário digitou
        printf("\n");

        for(i = 0 ; i <= estoque ; i++){






            if(strcmp(estoque_consulta,estoques[i].titulo_estoque) == 0){




                // Pedindo novas informações para atualização do filme

                printf("Diga-me o título do novo filme do estoque: ");
                setbuf(stdin,keyboard);
                scanf("%39[^\n]s",estoques[i].titulo_estoque);

                printf("Diga-me a nova data de entrada desse filme no estoque (xx/xx/xxxx): ");
                setbuf(stdin,keyboard);
                scanf("%s",&estoques[i].data_de_entrada[i]);

                if(strlen(estoques[i].data_de_entrada[i]) != 10){   // Verifica se a data de entrega é válida



                    printf("\nData de entrada do estoque inválida (xx/xx/xxxx)...\n\n");
                    system("pause");
                    system("cls");
                    exit(1); // Se a data de entrega for inválida chama a função novamente!
                }

                printf("Diga-me o gênero do novo filme: ");
                setbuf(stdin,keyboard);
                scanf("%14[^\n]s",estoques[i].genero_estoque);
                printf("\nFilme atualizado com sucesso! \n");
                break;
            }
            else if(strcmp(estoque_consulta,estoques[i].titulo_estoque) != 0 && i == estoque){

                // Só executará a ação quando o laço for terminar


                // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensage
                printf("Filme no estoque não encontrado... \n");
            }
        }


        printf("\n\t\tAtualizar novamente?\n\n");
        printf("\t\t[1] - Sim\n\n");
        printf("\t\t[2] - Não\n\n");
        printf("\t\tEscolha a opção: ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){    // Se ele digitar um a função de editar estoques é chamada novamente




            printf("\n");
            system("pause");
            system("cls");
            f_editar_estoque();
        }
        else if(escolha == 2){     // Se 2 a função de editar estoques é chamada novamente




            printf("\n");
            system("pause");
            system("cls");
            f_editar_estoque();
        }
        else{    // Caso ele digita um número que não pertença as opções acima




            printf("\n");
            printf("Valor não reconhecido... \n\n");
            system("pause");
            system("cls");
            f_editar_estoque();
        }
    }

    else if(escolha == 2){    // Se o número digitado for 2 então irá excluir o filme do estoque







        printf("\nDiga-me o nome do filme a ser excluído: ");
        scanf("%s",&estoque_consulta); // Armazena o filme que o usuário digitou

        for(i = 0 ; i <= estoque ; i++){






            if(strcmp(estoque_consulta,estoques[i].titulo_estoque)== 0){  // "Apagando" Os filmes da Random Acess Memory




                // Faz com que o identificador fique nulo, assim parecendo que foi apagado da memória e não mostrrando nos menus.
                strcpy(estoques[i].titulo_estoque,"");
                estoque-= estoques[i].qtd_copias[i];// Remove as cópias do item do estoque
                qtd_estoque--; // Remove um item do estoque
                printf("\nFilme excluído com sucesso! \n");
                break;
            }

            else if(strcmp(estoque_consulta,estoques[i].titulo_estoque) != 0 && i == estoque){

                // Só executa a ação quando o laço for terminar


                // Se o identificador que o usuário digitou não foi igual ao que consta no sistema, então exibe essa mensagem.
                printf("\nFilme no estoque não encontrado... \n");
            }
        }


        printf("\n\tExcluir novamente?\n\n");
        printf("\t\t[1] - Sim\n\n");
        printf("\t\t[2] - Não\n\n");
        printf("\t\tEscolha a opção: ");
        scanf("%d",&escolha); // Armazena a escolha do usuário

        if(escolha == 1){    // Se ele digitar um a função de excluir filmes do estoque no estoque é chamada novamente


            printf("\n");
            system("pause");
            system("cls");
            f_editar_estoque();
        }
        else if(escolha == 2){    // Se 2 a função de estoque de filmes é chamada novamente


            printf("\n");
            system("pause");
            system("cls");
            f_editar_estoque();
        }
        else{    // Caso ele digita um número que não pertença as opções acima


            printf("\n");
            printf("Valor não reconhecido... \n\n");
            system("pause");
            system("cls");
            f_editar_estoque();
        }

    }

    else if(escolha == 3){    // Se o número digitado for 3 então irá voltar para o menu





        system("cls");
        menu_estoque();
    }

    else{    // Caso ele digita um número diferente de 1 2 ou 3.




        printf("\n");
        printf("Valor não reconhecido... \n\n");
        system("pause");
        system("cls");
        f_editar_estoque();
    }







}

// Menus
void menu_filme(){         // Função do menu do filme




    printf("\n\t\t\t==================\n");
    printf("\t\t\tCadastro de Filmes");
    printf("\n\t\t\t================== \n\n");
    printf("\t\t[1] - Cadastrar filme  \n\n");
    printf("\t\t[2] - Editar filme     \n\n");
    printf("\t\t[3] - Lista filme      \n\n");
    printf("\t\t[4] - Visualizar filme \n\n");
    printf("\t\t[5] - Consultar filme  \n\n");
    printf("\t\t[6] - Voltar para o menu principal \n\n");
    printf("\t\t[7] - Sair \n\n");
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
        printf("\nValor não reconhecido... \n\n");
        system("pause");
        system("cls");
        menu_filme();

    }
}
void menu_cliente(){      // Função do menu do cliente



    printf("\n\t\t\t====================\n");
    printf("\t\t\tCadastro de Clientes");
    printf("\n\t\t\t==================== \n\n");
    printf("\t\t[1] - Cadastrar cliente  \n\n");
    printf("\t\t[2] - Editar cliente     \n\n");
    printf("\t\t[3] - Listar cliente     \n\n");
    printf("\t\t[4] - Visualizar cliente \n\n");
    printf("\t\t[5] - Consultar cliente  \n\n");
    printf("\t\t[6] - Voltar para o menu principal \n\n");
    printf("\t\t[7] - Sair \n\n");
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
        printf("\nValor não reconhecido... \n\n");
        system("pause");
        system("cls");
        menu_cliente();

    }
}
void menu_estoque(){     // Função do menu do estoque


    printf("\n\t\t\t====================\n");
    printf("\t\t\tCadastro de Estoques");
    printf("\n\t\t\t====================           \n\n");
    printf("\t\t[1] - Cadastrar filme no estoque   \n\n");
    printf("\t\t[2] - Editar filme do estoque      \n\n");
    printf("\t\t[3] - Listar filmes do estoque     \n\n");
    printf("\t\t[4] - Visualizar filme do estoque  \n\n");
    printf("\t\t[5] - Consultar filme do estoque   \n\n");
    printf("\t\t[6] - Voltar para o menu principal \n\n");
    printf("\t\t[7] - Sair                         \n\n");
    printf("Diga-me a opção: ");
    scanf("%d",&escolha);

    switch(escolha){






    case 1:
        system("cls");
        f_cadastrar_estoque();
        break;
    case 2:
        system("cls");
        f_editar_estoque();
        break;
    case 3:
        system("cls");
        f_listar_estoque();
        break;
    case 4:
        system("cls");
        f_visualizar_estoque();
        break;
    case 5:
        system("cls");
        f_consultar_estoque();
        break;
    case 6:
        system("cls");
        main();
        break;
    case 7:
        exit(1); // Fecha o programa
    default:
        printf("\nValor não reconhecido... \n\n");
        system("pause");
        system("cls");
        menu_estoque();

    }

}
void menu_aluguel(){    // Função do menu do aluguel


    printf("\n\t\t\t=====================\n");
    printf("\t\t\tCadastro de Aluguéis");
    printf("\n\t\t\t=====================                   \n\n");
    printf("\t\t[1] - Alugar filme por cliente              \n\n");
    printf("\t\t[2] - Listar filmes alugados por cliente    \n\n");
    printf("\t\t[3] - Consultar filmes alugados por cliente \n\n");
    printf("\t\t[4] - Alugar filme                          \n\n");
    printf("\t\t[5] - Listar filmes alugados                \n\n");
    printf("\t\t[6] - Consultar aluguel                     \n\n");
    printf("\t\t[7] - Voltar para o menu principal          \n\n");
    printf("\t\t[8] - Sair                                  \n\n");
    printf("Diga-me a opção: ");
    scanf("%d",&escolha);

    switch(escolha){






    case 1:
        system("cls");
        f_cadastar_aluguel_por_cliente();
        break;
    case 2:
        system("cls");
        f_listar_aluguel_por_cliente();
        break;
    case 3:
        system("cls");
        f_consultar_aluguel_por_cliente();
        break;
    case 4:
        system("cls");
        f_cadastrar_aluguel();
        break;
    case 5:
        system("cls");
        f_listar_aluguel();
        break;
    case 6:
        system("cls");
        f_consultar_aluguel();
    case 7:
        system("cls");
        main();
        break;
    case 8:
        exit(1); // Fecha o programa
    default:
        printf("\nValor não reconhecido... \n\n");
        system("pause");
        system("cls");
        menu_aluguel();

    }


}
// Principal
int main(){          // Função principal


int muda_cor(int n){ // Função para mudar cor, recebe escolha como parâmetro


if(n == 666 ) // Escolha = 666 == Cor verde
    system("COLOR A");

else // Escolha != 666 == Cor default
    system("COLOR 0F");

return n;
}



    setlocale(LC_ALL,"Portuguese"); // Permite acentos e outras regras da língua portuguesa em strings.
    printf("\n\t\t\t=====================\n");
    printf("\t\t\tLocadora WannaCry.exe");
    printf("\n\t\t\t=====================        \n\n");
    printf("\t\t[1] - Entrar no menu da locadora \n\n");
    printf("\t\t[2] - Entrar no menu do cliente  \n\n");
    printf("\t\t[3] - Entrar no menu do estoque  \n\n");
    printf("\t\t[4] - Entrar no menu do aluguel  \n\n");
    printf("\t\t[5] - Apagar registros do banco  \n\n");
    printf("\t\t[6] - Sair                       \n\n");
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
        system("cls");
        menu_estoque();
        break;
    case 4:
        system("cls");
        menu_aluguel();
        break;
    case 5:
        fopen("Banco de dados filmes.txt","w");    // Apagando conteúdo do banco
        fopen("Banco de dados estoque.txt","w");  // Apagando o conteúdo do banco
        fclose(arq);                             // Fecha o arquivo
        printf("\nApagando dados...\n");
        Sleep(1000); // Tempo de 1 segundo para apagar os arquivos do banco
        printf("\nRegistros apagados!\n\n\n");
        system("pause");
        system("cls");
        main();                                // Retorna a main
        break;
    case 6:
        break;
    case 666: case 555: // Se o case for 666 ou 555
        muda_cor(escolha); // Chamo a função passando a escolha
        system("cls");
        main();
        break;
    default:
        printf("\nValor não reconhecido... \n\n");
        system("pause");
        system("cls");
        main();


    }


}
