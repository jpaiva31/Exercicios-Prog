#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // para usar getch(), getche()
#include <locale.h>// para setar linguagem.
#include <string.h>// para usar fun�oes de strings ex:strcmp()

typedef struct elemento ELEMENTO;// elemento � um apelido, ELEMENTO � nome do tipo que ser� usado no programa.
struct elemento{
    char nome[30];
    char sigla[3];
    int grupo;
    int periodo;
    int numero_atomico;
    double massa_atomica;
};

/* void nome_do_programa();
 * acao:        limpa a tela e printa um cabe�alho do programa
 * entrada:     nenhuma
 * saida:       nenhuma
 * suposicoes:  nenhuma
 * algoritmo:   imprime instru�oes na tela.
 */
void nome_do_programa();

/* void input_elemento();
 * acao:        acrescenta elemento na tabela peri�dica.
 * entrada:     nenhuma
 * saida:       nenhuma
 * suposicoes:  nenhuma
 * algoritmo:   abre arquivo em modo append, atraves de estrutura de repeti�ao "do" recebe entradas do usuario e escreve no arquivo.
 */
void input_elemento();

//fun��o para listar tabela de elementos.
void print_tabela();

//fun��o para excluir elementos.
void excluir_elemento();

//fun��o para calcular mols de substancia.
void calculadora_mols_para_gramas();

//fun��o para calcular gramas de substancia.
void calculadora_gramas_para_mols();

//fun��o para distribui��o eletr�nica.
void distribuicao_eletronica();

//fun��o que pesquisa elemento pela sigla e retorna double com sua massa atomica.
double pesquisar_massa_por_sigla(char sigla[]);

//fun��o que pesquisa elemento pela sigla e retorna double com seu n�mero at�mico.
int pesquisar_numeroatomico_por_sigla(char sigla[]);

//fun��o de pesquisa do menu por nome.
int pesquisar_nome(char pesquisa[], char categoria_da_pesquisa[]);

//fun��o de pesquisa do menu por grupo e periodo.
int pesquisar_g_p(int pesquisa, char categoria_da_pesquisa[]);

//fun��o principal.
int main(){
    setlocale(LC_ALL,"Portuguese");//linha do codigo que seta a l�ngua, resolvendo problemas de acentua��o.
    int opcao;//salva a escolha que usuario der de entrada.

    //Menu com estrutura de repeti��o.
    do{
        fflush(stdin);
        nome_do_programa();
        printf("[1] _ Inserir Elemento\n");
        printf("[2] _ Pesquisar Elemento\n");
        printf("[3] _ Pesquisar Elemento por Grupo\n");
        printf("[4] _ Pesquisar Elemento por Per�odo\n");
        printf("[5] _ Tabela de elementos\n");
        printf("[6] _ Excluir elemento\n");
        printf("[7] _ Calculadora mols para gramas\n");
        printf("[8] _ Calculadora gramas para mols\n");
        printf("[9] _ Distribui��o Eletr�nica\n");
        printf("[0] _ Sair\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);//linha do codigo que pega a entrada do usuario.

        //escopo de op��es com switch case, cada case tem seu break.
        switch(opcao){
        case 1:
            input_elemento();//caso digite 1 chama a fun��o de inserir.
            break;

        case 2:{
            nome_do_programa();
            char tipo_de_pesquisa[]="nome";
            char nome[30];
            fflush(stdin);
            printf("Digite o nome de elementos a pesquisar: ");
            gets(nome);
            pesquisar_nome(nome, tipo_de_pesquisa);
            system("pause");
            break;
        }

        case 3:{
            nome_do_programa();
            char tipo_de_pesquisa[]="grupo";
            int grupo;
            fflush(stdin);
            printf("Digite o grupo de elementos a pesquisar: ");
            scanf("%d", &grupo);
            pesquisar_g_p(grupo, tipo_de_pesquisa);
            system("pause");
            break;
        }

        case 4:{
            nome_do_programa();
            char tipo_de_pesquisa[]="periodo";
            int periodo;
            fflush(stdin);
            printf("Digite o per�odo de elementos a pesquisar: ");
            scanf("%d", &periodo);
            pesquisar_g_p(periodo, tipo_de_pesquisa);
            system("pause");
            break;
        }

        case 5:
            print_tabela();//caso digite 5 chama fun��o q lista a tabela.
            break;

        case 6:
            excluir_elemento();//caso digite 6 chama fun��o para excluir elemento.
            break;

        case 7:
            calculadora_mols_para_gramas();//caso digite 7 chama fun��o da calculadora mols para gramas.
            break;

        case 8:
            calculadora_gramas_para_mols();//caso digite 8 chama fun��o da calculadora mols para gramas.
            break;

        case 9:
            distribuicao_eletronica();//caso digite 9 chama fun��o de distribui��o eletr�nica.
            break;

        case 0:
            nome_do_programa();
            printf("CR�DITOS...\n\n");
            printf("_______________________________________________________________________________________________\n\n");
            printf("Colaboradores:\n\n");
            printf("Vitor Augusto Philippsen Bohn\n");
            printf("Jo�o Paulo Paiva\n");
            printf("Gustavo Zanatta\n");
            printf("Rafael Susin\n");
            printf("Lucas Meneguetti Gaias\n\n\n");
            printf("   ______ _          _                 _            \n");
            printf("  |  __  | |        (_)               | |       _   \n");
            printf("  | |  | | |__  _ __ _  __ _  __ _  __| | ___  | |  \n");
            printf("  | |  | | '_ || '__| || _` |/ _` |/ _` || _ | | |  \n");
            printf("  | |__| | |_) | |  | | (_| | (_| | (_| | (_)| |_|  \n");
            printf("  |______|_.__/|_|  |_||__, ||__,_||__,_||___|  _   \n");
            printf("                        __/ |                  |_|  \n");
            printf("                       |___/                        \n");
            printf("_______________________________________________________________________________________________\n\n");
            getch();//fica esperando entrada.
            break;

        default:
            printf("Op��o Inv�lida!\n");//caso o usuario digite uma op��o diferente.
            getch();//fica esperando entrada pra continuar rodando.
            break;
        }
       }while(opcao!=0);//condi��o de saida da estrutura de repeti��o do menu.
return 0;
}

void nome_do_programa(){
    system("cls");//limpa a tela.
    printf("_______________________________________________________________________________________________\n\n");
    printf(" _____     _        _         _____        _        _ _           ______ _      _ _         _  \n");
    printf("|_   _|   | |      | |       | ___ |      (_)      | (_)          |  _  (_)    (_) |       | | \n");
    printf("  | | __ _| |__ ___| | __ _  | |_/ /_ _ __ _ ___ __| |_ ___ __ _  | | | |_ __ _ _| |_  __ _| | \n");
    printf("  | || _` | '_ | _ | |/ _` | |  __/_ | '__| | _ | _` | | __/ _` | | | | | | _` | | __|/ _` | | \n");
    printf("  | ||(_| | |_)| __/ ||(_| | | | | __/ |  | |(_)|(_| | |(__|(_| | | |/ /| |(_| | | |_ |(_| | | \n");
    printf("  |_||__,_|_.__/___|_||__,_| |_| |___|_|  |_|___|__,_|_|___|__,_| |___/ |_|__, |_|___||__,_|_| \n");
    printf("                                                                            _/ |               \n");
    printf("                                                                           |___/               \n");
    printf("_______________________________________________________________________________________________\n\n");
}

void input_elemento(){
    FILE*arquivo;//ponteiro pra arquivo.
    ELEMENTO elm;//referencia de ELEMENTO.

    arquivo=fopen("elementos.txt", "ab");// abre para acr�scimo se j� existe e cria se nao existir, arquivo bin�rio modo append

//pode haver falha na hora de abrir o arquivo.
//logo testamos se n�o ocorrer� problemas verificando se a vari�vel nao esta vazia.
    if(arquivo==NULL){
        printf("Falha na leitura do arquivo!!!\n");// caso vari�vel esteja vazia mostra mensagem na tela.
    }
    else{
        //estrutura de repeti��o para inserir dados do elemento.
        do{
            nome_do_programa();//limpa o menu da tela e mostra o cabe�alho.
            printf("_______________________________________________________________________________________________\n\n");
            printf("CADASTRANDO ELEMENTO...\n");
            printf("Digite o n�mero at�mico: ");
            scanf("%d", &elm.numero_atomico); //scanf pq recebe valor no tipo int

            fflush(stdin);
            printf("Digite a sigla do elemento: ");
            gets(elm.sigla);

            fflush(stdin);//limpa o buffer do teclado, porque ser�o usadas strings.
            printf("Digite o nome do elemento: ");
            gets(elm.nome);//recebe no formato do ELEMENTO, gets porque � vetor de char.

            printf("Digite a massa at�mica: ");
            scanf("%lf", &elm.massa_atomica);//scanf pq recebe valor no tipo double

            printf("Digite o grupo do elemento: ");
            scanf("%d", &elm.grupo); //scanf pq recebe valor no tipo int

            printf("Digite o per�odo do elemento: ");
            scanf("%d", &elm.periodo); //scanf pq recebe valor no tipo int

            printf("_______________________________________________________________________________________________\n\n");

            fwrite(&elm, sizeof(ELEMENTO), 1, arquivo);//grava no arquivo a referencia elm de elemento, tamanho de ELEMENTO, 1 linha, no arquivo.
            fflush(stdin);
            printf("Deseja continuar? (s/n)");

        }while(getche() == 's');//roda a estrutura de repeti��o ate que o usuario digite o caractere 's'.
        fclose(arquivo);//fecha o arquivo.
    }
}

void print_tabela(){
    FILE*arquivo;//ponteiro pra arquivo.
    ELEMENTO elm;//referencia de ELEMENTO.

    arquivo=fopen("elementos.txt", "rb");// abre para leitura, arquivo bin�rio modo read

    nome_do_programa();//mostra cabe�alho.

//pode haver falha na hora de abrir o arquivo.
//logo testamos se n�o ocorrer� problemas verificando se a vari�vel nao esta vazia.
    if(arquivo==NULL){
        printf("Falha na leitura do arquivo!!!\n");// caso vari�vel esteja vazia mostra mensagem na tela.
    }
    else{
        printf("_______________________________________________________________________________________________\n\n");
        while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){ //enquanto fread conseguir me retornar 1 linha, "==1" significa que ele conseguiu ler alinha do arquivo, entao nao chegou no final ainda.
            printf("N�mero at�mico: %d\n", elm.numero_atomico);
            printf("Sigla do elemento: %s\n", elm.sigla);
            printf("Nome do elemento: %s\n", elm.nome);
            printf("Massa at�mica: %.3lf\n", elm.massa_atomica);
            printf("Grupo do elemento: %d\n", elm.grupo);
            printf("per�odo do elemento: %d\n", elm.periodo);
            printf("__________________________________________\n\n");
        }
    }
    fclose(arquivo);// fecha arquivo.
    getch();//necessario para os prints permanecerem na tela ate nova entrada.
}

void excluir_elemento(){
    FILE *arquivo, *arquivo_temp;//ponteiro para arquivo e arquivo temporario.
    ELEMENTO elm;//referencia da struct ELEMENTO.
    char nome[30];//variavel para receber entrada do usuario.

    arquivo=fopen("elementos.txt", "r+b");// abre para leitura e escrita, arquivo bin�rio, apartir do inicio o arquivo deve existir.
    arquivo_temp=fopen("temporario.txt", "wb");// cria arquivo vazio para escrita, se ele j� existia � perdido.

//pode haver falha na hora de abrir o arquivo.
//logo testamos se n�o ocorrer� problemas verificando se a vari�vel nao esta vazia.
    if(arquivo==NULL||arquivo_temp==NULL){
        printf("\nFalha na leitura do arquivo!!!\n");// caso vari�vel esteja vazia mostra mensagem na tela.
    }
    else{
        nome_do_programa();//limpa o menu da tela e mostra o cabe�alho.
        printf("_______________________________________________________________________________________________\n\n");
        fflush(stdin);//limpa o buffer do teclado, porque ser�o usadas strings.
        printf("Digite o nome do elemento que deseja excluir: ");
        gets(nome);//recebe e salva na variavel nome, gets porque � vetor de char.

        while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){//enquanto fread conseguir me retornar 1 linha, "==1", significa que ele conseguiu ler a linha do arquivo, entao nao chegou no final ainda.
            if(strcmp(nome, elm.nome)!=0){ //compara se o nome do elmento for diferente do que eo usuario deseja excluir
                fwrite(&elm, sizeof(ELEMENTO), 1, arquivo_temp);//escreve a struct do elemento no arquivo temporario
                }
        }
    }
    if(ferror(arquivo_temp)){//caso arquivo apresente erro.
        printf("_______________________________________________________________________________________________\n\n");
        printf("\nERRO AO EXCLUIR!!!\n");//printa mensagem para o usu�rio de erro.
        printf("_______________________________________________________________________________________________\n\n");
    }
    else{
        printf("_______________________________________________________________________________________________\n\n");
        printf("\nEXCLLUIDO COM SUCESSO!!!\n");//printa mensagem para o usu�rio de sucesso.
        printf("_______________________________________________________________________________________________\n\n");
    }
    fclose(arquivo);//fecha uarquivo.
    fclose(arquivo_temp);//fecha arquivo temporario.
    remove("elementos.txt");//exclui arquivo elemento.txt.
    rename("temporario.txt", "elementos.txt");//renomeia temporario.txt para elemento.txt.
    system("pause");//pausa programa esperando entrada do usuario
}

void calculadora_mols_para_gramas(){
    char substancia[30];//variavel que recebe a substancia entrada do usu�rio.
    char *elementos[10];// variavel que recebe a string substancia dividida por elementos.
    char *elementos_atomos[2];//variavel que recebe os elementos separados do numero de atomos. posi��o[0]sigla\\posi��o[1]atomos
    int i=0, j=0;//variaveis auxiliares
    int contador_de_elementos=0;//salvar o numero total de elementos da substancia
    double massa_total;//variavel que armazena os valores da massa atomica dos elementos enquanto estao sendo calculados.
    double numero_moleculas;//variavel que recebe o n�mero de mol�culas entrada do usu�rio.

    nome_do_programa();//limpa o menu da tela e mostra o cabe�alho.
    fflush(stdin);//limpa o buffer do teclado, porque ser�o usadas strings.
    printf("Insira a substancia separando elementos com espa�os e atomos por elemento com v�rgula(Ex: Na S O,4): ");
    gets(substancia);//recebe a entrada.
//fun��o strtok ultlizada para separar strings.
    elementos[i] = strtok(substancia," ");//separa a string substancia pelo caractere "\0" e salva pela primeira vez.
    while (elementos[i] != NULL){ //enquanto o indice for diferente de nulo.
        elementos[++i] = strtok(NULL," ");//incrementa o indice e roda a fun��o strtok novamente continuando de onde parou.
        contador_de_elementos++;//conta quantos elementos foram separados pela fun��o.
    }
    for(j=0; j<contador_de_elementos; j++){ //la�o for que percorre o vetor aonde foram salvos os elementos separados pela fun��o strtok.
        int k=0;//variavel auxiliar, valor retorna a 0 a cada repeti��o do la�o.
//fun��o strtok ultlizada para separar strings.
        elementos_atomos[k] = strtok(elementos[j],",");//separa cada elemento do seu numero de atomos pelo caractere",".
        while (elementos_atomos[k] != NULL){//enquanto o indice for diferente de nulo.
            elementos_atomos[++k] = strtok(NULL,",");//incrementa o indice e roda a fun��o strtok novamente continuando de onde parou.
        }
        printf("_______________________________________________________________________________________________\n\n");
        printf("\n%s\n", elementos_atomos[0]);//printa o elemento
        printf("Massa at�mica: %.3lf\n", pesquisar_massa_por_sigla(elementos_atomos[0]));//chama a fun��o e printa o valor da massa atomica pesquisando pela sigla no arquivo.

        if(elementos_atomos[1]==NULL){ //caso o elemento tenha valor nulo de atomos como entrada.
            elementos_atomos[1]="1";//iguala o valor a um_atomo, resolvido de maneira a continuar sendo char.
            printf("N�mero de atomos do elemento: %s\n", elementos_atomos[1]);//printa o valor.
        }
        else{//caso o valor nao seja nulo.
            printf("N�mero de atomos do elemento: %s\n", elementos_atomos[1]);//printa o valor.
        }
//atribui valor a massa total, usando a fun��o que retorna o numero da massa atomica do elemento.
//multiplicadndo esse valor pelo valor do numero de atomos do elemento.
//ultiliza��o da fun��o atoi para converter char em int.
//observe como o valor da massa atomica � double sera convertido automaticamente para o maior.
        massa_total+=(pesquisar_massa_por_sigla(elementos_atomos[0])*atol(elementos_atomos[1]));
        printf("_______________________________________________________________________________________________\n\n");
    }//final do la�o
    printf("_______________________________________________________________________________________________\n\n");
    printf("\nDigite o n�mero de mol�culas da subst�ncia: \n");//pede entrada do usu�rio.
    scanf("%lf", &numero_moleculas);
    printf("\nMassa At�mica: %.3lf g/mol\n\n", massa_total);
    printf("\nValor em gramas de %.lf mol�culas da subst�ncia: %.3lf g\n", numero_moleculas, massa_total*numero_moleculas);//retorna o resultado, multiplicando a massa atomica total pelo numero de moleculas.
    printf("_______________________________________________________________________________________________\n\n");
    system("pause");//pausa programa esperando entrada do usuario.
}

void calculadora_gramas_para_mols(){
    char substancia[30];//variavel que recebe a substancia entrada do usu�rio.
    char *elementos[10];// variavel que recebe a string substancia dividida por elementos.
    char *elementos_atomos[2];//variavel que recebe os elementos separados do numero de atomos. posi��o[0]sigla\\posi��o[1]atomos
    int i=0, j=0;//variaveis auxiliares
    int contador_de_elementos=0;//salvar o numero total de elementos da substancia
    double massa_total;//variavel que armazena os valores da massa atomica dos elementos enquanto estao sendo calculados.
    double peso_substancia;

    nome_do_programa();//limpa o menu da tela e mostra o cabe�alho.
    fflush(stdin);//limpa o buffer do teclado, porque ser�o usadas strings.
    printf("Insira a substancia separando elementos com espa�os e atomos por elemento com v�rgula(Ex: Na S O,4): ");
    gets(substancia);//recebe a entrada.
//fun��o strtok ultlizada para separar strings.
    elementos[i] = strtok(substancia," ");//separa a string substancia pelo caractere "\0" e salva pela primeira vez.
    while (elementos[i] != NULL){ //enquanto o indice for diferente de nulo.
        elementos[++i] = strtok(NULL," ");//incrementa o indice e roda a fun��o strtok novamente continuando de onde parou.
        contador_de_elementos++;//conta quantos elementos foram separados pela fun��o.
    }
    for(j=0; j<contador_de_elementos; j++){ //la�o for que percorre o vetor aonde foram salvos os elementos separados pela fun��o strtok.
        int k=0;//variavel auxiliar, valor retorna a 0 a cada repeti��o do la�o.

        //fun��o strtok ultlizada para separar strings.
        elementos_atomos[k] = strtok(elementos[j],",");//separa cada elemento do seu numero de atomos pelo caractere",".
        while (elementos_atomos[k] != NULL){//enquanto o indice for diferente de nulo.
            elementos_atomos[++k] = strtok(NULL,",");//incrementa o indice e roda a fun��o strtok novamente continuando de onde parou.
        }
        printf("_______________________________________________________________________________________________\n\n");
        printf("\n%s\n", elementos_atomos[0]);//printa o elemento
        printf("Massa at�mica: %.3lf\n", pesquisar_massa_por_sigla(elementos_atomos[0]));//chama a fun��o e printa o valor da massa atomica pesquisando pela sigla no arquivo.

        if(elementos_atomos[1]==NULL){ //caso o elemento tenha valor nulo de atomos como entrada.
            elementos_atomos[1]="1";//iguala o valor a um_atomo, resolvido de maneira a continuar sendo char.
            printf("N�mero de atomos do elemento: %s\n", elementos_atomos[1]);//printa o valor.
        }
        else{//caso o valor nao seja nulo.
            printf("N�mero de atomos do elemento: %s\n", elementos_atomos[1]);//printa o valor.
        }
//atribui valor a massa total, usando a fun��o que retorna o numero da massa atomica do elemento.
//multiplicando esse valor pelo valor do numero de atomos do elemento.
//ultiliza��o da fun��o atoi para converter char em int.
//observe como o valor da massa atomica � double sera convertido automaticamente para o maior.
        massa_total+=(pesquisar_massa_por_sigla(elementos_atomos[0])*atol(elementos_atomos[1]));
        printf("_______________________________________________________________________________________________\n\n");
    }//final do la�o
        printf("_______________________________________________________________________________________________\n\n");
        printf("\nDigite o peso em gramas da subst�ncia: \n");//pede entrada do usu�rio.
        scanf("%lf", &peso_substancia);
        printf("\nMassa At�mica: %.3lf g/mol\n\n", massa_total);
        printf("\nN�mero de mols em %.3lf gramas da subt�ncia: %lf\n",peso_substancia, peso_substancia/massa_total);//retorna o resultado, multiplicando a massa atomica total pelo numero de moleculas.
        printf("_______________________________________________________________________________________________\n\n");
        system("pause");//pausa programa esperando entrada do usuario.
}

void distribuicao_eletronica(){
    int i=0, numero_atomico=0;//variaveis auxiliares
    int K=0, L=0, M=0, N=0, O=0, P=0, Q=0;//declara��o de inteiros para as camadas
    int v[18];//vetor de inteiros numero de atomos por subnivel
    char *sb[18];//vetor de char para as subniveis
    char sigla[3];
    nome_do_programa();
    fflush(stdin);
    printf("Digite a sigla do elemento.(Ex:C�dmio --> Sigla:Cd): ");
    gets(sigla);
    numero_atomico=pesquisar_numeroatomico_por_sigla(sigla);
//inicializando valores no vetor de subniveis
    v[0]=2;//1s2
    v[1]=2;//2s2
    v[2]=6;//2p6
    v[3]=2;//3s2
    v[4]=6;//3p6
    v[5]=2;//4s2
    v[6]=10;//3d10
    v[7]=6;//4p6
    v[8]=2;//5s2
    v[9]=10;//4d10
    v[10]=6;//5p6
    v[11]=2;//6s2
    v[12]=10;//5d10
    v[13]=6;//6p6
    v[14]=2;//7s2
    v[15]=14;//5f14
    v[16]=10;//6d10
    v[17]=6;//7p6
//inicializando valores no vetor de camadas
    sb[0]="1s";
    sb[1]="2s";
    sb[2]="2p";
    sb[3]="3s";
    sb[4]="3p";
    sb[5]="4s";
    sb[6]="3d";
    sb[7]="4p";
    sb[8]="5s";
    sb[9]="4d";
    sb[10]="5p";
    sb[11]="6s";
    sb[12]="5d";
    sb[13]="6p";
    sb[14]="7s";
    sb[15]="5s";
    sb[16]="6s";
    sb[17]="7s";
    printf("\n\n_______________________________________________________________________________________________\n\n");
    printf("Distribuicao eletronica por subniveis:\n\n");

    if (numero_atomico==24)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s1  3d5");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 12\nN = 1\nO = 0\nP = 0\nQ = 0\n");
        getch();
    }else

    if (numero_atomico==29)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s1  3d10");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 18\nN = 1\nO = 0\nP = 0\nQ = 0\n");
        getch();
    }else

    if (numero_atomico==41)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s2  3d10  4p6 5s1  4d4");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 18\nN = 11\nO = 2\nP = 0\nQ = 0\n");
        getch();

    }else

    if (numero_atomico==44)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s2  3d10  4p6 5s1  4d7");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 18\nN = 14\nO = 2\nP = 0\nQ = 0\n");
        getch();

    }else

    if (numero_atomico==45)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s2  3d10  4p6 5s1  4d8");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 18\nN = 15\nO = 2\nP = 0\nQ = 0\n");
        getch();
    }else

    if (numero_atomico==46)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s2  3d10  4p6 4d10");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 18\nN = 16\nO = 2\nP = 0\nQ = 0\n");
        getch();
    }else

    if (numero_atomico==47)
    {
        printf("1s2  2s2  2p6  3s2 3p6  4s2  3d10  4p6 5s1  4d10");
        printf("\n\n_______________________________________________________________________________________________\n\n");
        printf("Distribuicao eletronica por camadas: \n\n");
        printf("K = 2\nL = 8\nM = 18\nN = 17\nO = 2\nP = 0\nQ = 0\n");
        getch();
    }
         else
    {
    for (i=0; i<18; i++){//la�o que percorre subniveis.
        if (numero_atomico>=v[i]){//se o subnivel tiver valor menor que o n�mero at�mico.
            printf("%s%d ", sb[i], v[i]);
            if (strstr(sb[i], "1")!=NULL){//verifica se est� na camada K.
                K+=v[i];
            }
            if (strstr(sb[i], "2")!=NULL){//verifica se est� na camada L.
                L+=v[i];
            }
            if (strstr(sb[i], "3")!=NULL){//verifica se est� na camada M.
                M+=v[i];
            }
            if (strstr(sb[i], "4")!=NULL){//verifica se est� na camada N.
                N+=v[i];
            }
            if (strstr(sb[i], "5")!=NULL){//verifica se est� na camada O.
                O+=v[i];
            }
            if (strstr(sb[i], "6")!=NULL){//verifica se est� na camada P.
                P+=v[i];
            }
            if (strstr(sb[i], "7")!=NULL){//verifica se est� na camada Q.
                Q+=v[i];
            }
            numero_atomico-=v[i];
        }
        else
            if(numero_atomico!=0){
                printf("%s%d ", sb[i], numero_atomico);
                if (strstr(sb[i], "1")!=NULL){//verifica se est� na camada K.
                    K+=numero_atomico;
                }
                if (strstr(sb[i], "2")!=NULL){////verifica se est� na camada L.
                    L+=numero_atomico;
                }
                if (strstr(sb[i], "3")!=NULL){////verifica se est� na camada M.
                    M+=numero_atomico;
                }
                if (strstr(sb[i], "4")!=NULL){////verifica se est� na camada N.
                    N+=numero_atomico;
                }
                if (strstr(sb[i], "5")!=NULL){////verifica se est� na camada O.
                    O+=numero_atomico;
                }
                if (strstr(sb[i], "6")!=NULL){////verifica se est� na camada P.
                    P+=numero_atomico;
                }
                if (strstr(sb[i], "7")!=NULL){////verifica se est� na camada Q.
                    Q+=numero_atomico;
                }
                break;
        }   }

    printf("\n\n_______________________________________________________________________________________________\n\n");
    printf("Distribuicao eletronica por camadas: \n\n");
    printf("K = %d\nL = %d\nM = %d\nN = %d\nO = %d\nP = %d\nQ = %d\n", K, L, M, N, O, P, Q);//printa as camadas.
    printf("_______________________________________________________________________________________________\n\n");
    system("pause");
    }
}

//fun��o double de suporte para calculadora conseguir buscar valor da massa atomica do elemento dentro da struct no arquivo.
double pesquisar_massa_por_sigla(char sigla[]){//recebe uma variavel double e um vetor de char com a string da sigla a ser pesquisada.
    double massa;
    FILE*arquivo;//ponteiro pra arquivo.
    ELEMENTO elm;//declara��o da referencia da struct Elemento.

    arquivo=fopen("elementos.txt", "rb");//abre arquivo bin�rio pra leitura.

    if(arquivo==NULL){//caso o arquivo de um valor nulo.
        printf("Falha na leitura do arquivo!!!\n");//avisa usu�rio sobre falha.
    }
    else{//caso nao falhe prossegue.
        while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){//enquanto fread conseguir me retornar 1 linha, "==1" significa que ele conseguiu ler alinha do arquivo, entao nao chegou no final ainda.
            if(strcmp(sigla, elm.sigla)==0){ //compara o parametro de sigla recebido com as siglas das structs no arquivo, caso seja igual, "==0".
                    massa=elm.massa_atomica;//copia valor para variavel recebida como parametro.
            }
        }
    }
    fclose(arquivo);//fecha arquivo.
    return massa;//retorna valor da massa atomica do elemento pesquisado pela sigla.
}

int pesquisar_numeroatomico_por_sigla(char sigla[]){//recebe uma variavel double e um vetor de char com a string da sigla a ser pesquisada.
    int numero_atomico;
    FILE*arquivo;//ponteiro pra arquivo.
    ELEMENTO elm;//declara��o da referencia da struct Elemento.

    arquivo=fopen("elementos.txt", "rb");//abre arquivo bin�rio pra leitura.

    if(arquivo==NULL){//caso o arquivo de um valor nulo.
        printf("Falha na leitura do arquivo!!!\n");//avisa usu�rio sobre falha.
    }
    else{//caso nao falhe prossegue.
        while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){//enquanto fread conseguir me retornar 1 linha, "==1" significa que ele conseguiu ler alinha do arquivo, entao nao chegou no final ainda.
            if(strcmp(sigla, elm.sigla)==0){ //compara o parametro de sigla recebido com as siglas das structs no arquivo, caso seja igual, "==0".
                numero_atomico=elm.numero_atomico;
            }
        }
    }
    fclose(arquivo);//fecha arquivo.
    return numero_atomico;//retorna valor da massa atomica do elemento pesquisado pela sigla.
}

int pesquisar_nome(char pesquisa[], char categoria_da_pesquisa[]){
    ELEMENTO elm;
    FILE*arquivo;
    arquivo=fopen("elementos.txt", "rb");

    if(arquivo==NULL){
        printf("Falha na leitura do arquivo!!!\n");
    }
    else{
        if(strcmp(categoria_da_pesquisa, "nome")==0){
            while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){
                if(strcmp(pesquisa, elm.nome)==0){
                    printf("N�mero at�mico: %d\n", elm.numero_atomico);
                    printf("Sigla do elemento: %s\n", elm.sigla);
                    printf("Nome do elemento: %s\n", elm.nome);
                    printf("Massa at�mica: %.3lf\n", elm.massa_atomica);
                    printf("Grupo do elemento: %d\n", elm.grupo);
                    printf("per�odo do elemento: %d\n", elm.periodo);
                    printf("__________________________________________\n\n");
                }
            }
        }
    }
    fclose(arquivo);
    return 0;
}

int pesquisar_g_p(int pesquisa, char categoria_da_pesquisa[]){
    ELEMENTO elm;
    FILE*arquivo;
    arquivo=fopen("elementos.txt", "rb");

    if(arquivo==NULL){
        printf("Falha na leitura do arquivo!!!\n");
    }
    else{
        if(strcmp(categoria_da_pesquisa, "grupo")==0){
            while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){
                if(pesquisa==elm.grupo){
                    printf("N�mero at�mico: %d\n", elm.numero_atomico);
                    printf("Sigla do elemento: %s\n", elm.sigla);
                    printf("Nome do elemento: %s\n", elm.nome);
                    printf("Massa at�mica: %.3lf\n", elm.massa_atomica);
                    printf("Grupo do elemento: %d\n", elm.grupo);
                    printf("per�odo do elemento: %d\n", elm.periodo);
                    printf("__________________________________________\n\n");
                }
            }
        }
        else{
            while(fread(&elm, sizeof(ELEMENTO), 1, arquivo)==1){
                if(pesquisa==elm.periodo){
                    printf("N�mero at�mico: %d\n", elm.numero_atomico);
                    printf("Sigla do elemento: %s\n", elm.sigla);
                    printf("Nome do elemento: %s\n", elm.nome);
                    printf("Massa at�mica: %.3lf\n", elm.massa_atomica);
                    printf("Grupo do elemento: %d\n", elm.grupo);
                    printf("per�odo do elemento: %d\n", elm.periodo);
                    printf("__________________________________________\n\n");
                }
            }
        }
    }
    fclose(arquivo);
    return 0;
}
