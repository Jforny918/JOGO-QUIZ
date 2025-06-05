#include <stdio.h> //biblioteca basica para entrada e saida
#include <stdlib.h> //biblioteca para manipulação do sistema
#include <string.h> //biblioteca para manipulação de strings  
#include <time.h> //biblioteca para manipulação de data( usada para embaralhar
typedef struct{  //define uma estrutura chamada Placar 
int acertos; //campo para armazenar acertos do jogador  
char nome[50];//campo para armazenar o nome do jogarf ate 49 caracteres 
}placar; 


void salvarPlacar(placar p){ 
 FILE*arquivo = fopen("placar.txt", "a"); // abre (ou cria) o arquivo.txt no modo append 
  
 if(arquivo==NULL){ //verifica se houve erro na abertura 
 printf("Erro na abertura");   
 return; 
 } 
 
 fprintf(arquivo, "%d|%s\n", p.acertos,p.nome); 
  
 fclose(arquivo); //fecha o arquivo 
} 
 
void listarPlacar(){ 
    FILE*arquivo = fopen("placar.txt", "r"); // abre (ou cria) o arquivo.txt no modo read
    placar p; 
 
    if (arquivo == NULL) { //verifica se houve erro na abertura ou se o arquivo esta vazio
        printf("Sem placares por enquanto.\n"); 
        return; 
    } 
 
    printf("\nQUADRO DE PLACAR\n"); 
 
    while (fscanf(arquivo, "%d|%49[^\n]\n", &p.acertos, p.nome) == 2) { 
        printf("JOGADOR: %s | PONTUAÇÃO: %d\n", p.nome, p.acertos); 
    } 
 
    fclose(arquivo); //fecha o aquivo
} 
 
int main(){ 
 
 int opcao, decisao;   
    char resposta[50];  
    placar p; 
    p.acertos = 0; 
 
 printf("            ????????\n"); 
 printf("          ????????????\n"); 
 printf("         ???????????????\n"); 
 printf("       ??????       ??????\n"); 
 printf("     ??????           ???????\n"); 
 printf("       ???              ???????\n"); 
 printf("         ??              ??????\n"); 
 printf("                         ??????\n"); 
 printf("                        ?????\n"); 
 printf("                      ?????\n"); 
 printf("                    ??????\n"); 
 printf("                  ???????\n"); 
 printf("                ???????\n"); 
 printf("               ???????\n"); 
 printf("               ??????\n"); 
 printf("               ?????\n"); 
 printf("\n"); 
 printf("\n"); 
 printf("              ?????\n"); 
 printf("             ???????\n"); 
 printf("             ???????\n"); 
 printf("              ?????\n"); 
 printf("\n"); 
  
 printf("BEM VINDO AO EXTRAORDINARIO JOGO DE PERGUNTAS E RESPOSTAS!\n"); 
 printf("       Pressione ENTER para avancar \n"); 
 getchar(); 
   
 system("cls"); 
   

 printf("Antes de comecarmos como voce gostaria de ser chamado?\n"); 
 scanf("%s", p.nome);  
   system("cls"); 
do { 
 printf("\n \\\=====MENU=====/\n"); 
 printf("1. Escolher materias\n"); 
 printf("2. Ver placar\n"); 
 printf("3. Creditos\n"); 
 printf("4. regras\n"); 
 printf("5. Sair\n");  
 scanf("%d", &opcao); 
  
 switch(opcao){ 
  case 1: 
    system("cls"); 
    printf("==Materias==\n1 - Historia\n2 - Geografia\n3 - Ciencias\n4 - Portugues\n5 - Matematica\n"); 
    printf("Ola %s, escolha uma materia", p.nome); 
       scanf("%d", &decisao);  
        
            if(decisao == 1){ // História  
         
       char perguntas[20][256] = {  
               "Quem foi o primeiro presidente do Brasil?",  
               "Em que pais ocorreu a Revolução Francesa?",  
               "Qual era o império liderado por Cesar?",  
               "Quem descobriu o Brasil?",  
               "Em que continente ocorreu a Primeira Guerra Mundial?",  
               "Quem proclamou a independência do Brasil?",  
               "Qual pais foi invadido pela Alemanha para iniciar a Segunda Guerra?",  
               "Quem foi o lider da independência da india?",  
               "Que civilização criou a democracia?",  
               "Qual foi o ultimo imperador do Brasil?",  
               "Quem assinou a Lei Aurea?",  
               "Em que cidade ocorreu a Revolucao Russa?",  
               "Qual tratado encerrou a Primeira Guerra Mundial?",  
               "Quem foi o primeiro imperador romano?",  
               "Qual civilizacao foi rival de Roma nas Guerras Punicas?",  
               "Qual era o nome da ideologia racista adotada pelo nazismo?",  
               "Qual era a capital do Imperio Bizantino?",  
               "Quem liderou os aliados na Segunda Guerra Mundial?",  
               "Quem descobriu as americas?",  
               "Qual era o nome da navegação portuguesa no seculo XV?"  
           };  
     
           char respostas[20][50] = {  
               "Deodoro", "Franca", "Roma", "Cabral", "Europa",  
               "Pedro", "Polonia", "Gandhi", "Atenas", "Pedro",  
               "Isabel", "Petrogrado", "Versalhes", "Augusto", "Cartago",  
               "Arianismo", "Constantinopla", "Churchill", "Cristovao", "Caravela"  
           };  
        int difOrdem[20], embar, ale;  
        int i;  
          
        p.acertos = 0; 
        for(i = 0; i < 20; i++){  
         difOrdem[i] = i;  
     }  
       
     srand(time(NULL));  
       
     for(i = 0; i < 20; i++){  
      ale = rand() % 20;  
      embar = difOrdem[i];  
      difOrdem[i] = difOrdem[ale];  
      difOrdem[ale] = embar;  
     }  
       
     int cont;  
       
     for(cont = 0; cont < 10; cont++){  
      int numList = difOrdem[cont];  
      printf("\nPergunta %d - %s \n", cont + 1, perguntas[numList]);  
      scanf(" %s", &resposta);  
        
       if(strcmp(resposta, respostas[numList]) == 0){  
           printf("Resposta Certa!\n");  
           p.acertos++;  
       } else {  
           printf("Errou! A Resposta Certa era: %s\n", respostas[numList]);  
       }  
     }  
       
     printf("\nParabens, %s. Você acertou %d de 10 perguntas.\n", p.nome, p.acertos);  
     salvarPlacar(p); 
             
    }  
    else if(decisao == 2){ // Geografia  
     char perguntas[20][256] = {  
               "Qual o maior oceano do mundo?",  
               "Qual e o maior pais do mundo em extensao territorial?",  
               "Qual pais tem a maior floresta tropical do mundo?",  
               "Qual e a capital da Franca?",  
               "Qual e o deserto mais seco do mundo??",  
               "Em qual continente esta o Egito?",  
               "Qual e o menor pais do mundo?",  
               "Qual pais africano tem a maior populacao?",   
               "Qual lago e o mais profundo do mundo?",  
               "Qual e a capital do Cazaquistao?",  
               "Qual e o deserto mais frio do mundo?",  
               "Qual ilha abriga tres paises diferentes?",  
               "Qual pais tem mais ilhas no mundo?",  
               "Qual e a capital da Australia?",  
               "Qual montanha e a mais alta do mundo?",  
               "Qual pais e conhecido como “Terra do Sol Nascente?",  
               "Qual e o maior rio da Africa?",  
               "Qual pais faz fronteira com o maior numero de paises?",  
               "Qual e a capital do Canadá?",  
               "Qual e o ponto mais baixo da Terra em terra firme?"  
           };  
     
           char respostas[20][50] = {  
               "Pacifico", "Russia", "Brasil", "Paris", "Atacama",  
               "Africa", "Vaticano", "Nigeria", "Baikal", "Astana",  
               "Antartico", "Borneu", "Suecia", "Camberra", "Everest",  
               "Japao", "Nilo", "China", "Ottawa", "Mar"  
           };  
      
        int difOrdem[20], embar, ale;  
        int i;  
        p.acertos = 0; 
        for(i = 0; i < 20; i++){  
         difOrdem[i] = i;  
     }  
       
     srand(time(NULL));  
       
     for(i = 0; i < 20; i++){  
      ale = rand() % 20;  
      embar = difOrdem[i];  
      difOrdem[i] = difOrdem[ale];  
      difOrdem[ale] = embar;  
     }  
       
     int cont;  
        
     for(cont = 0; cont < 10; cont++){  
      int numList = difOrdem[cont];  
      printf("\nPergunta %d - %s \n", cont + 1, perguntas[numList]);  
      scanf(" %s", &resposta);  
        
       if(strcmp(resposta, respostas[numList]) == 0){  
           printf("Resposta Certa!\n");  
           p.acertos++;  
       } else {  
           printf("Errou! A Resposta Certa era: %s\n", respostas[numList]);  
       }  
     }  
       
     printf("\nParabens, %s. Você acertou %d de 10 perguntas.\n", p.nome, p.acertos); 
     salvarPlacar(p);  
    }  
    else if(decisao == 3){ // Ciências  
     char perguntas[20][256] = {  
               "Qual e o estado fisico da agua em temperatura ambiente?",  
               "Qual e o planeta mais proximo do Sol?",  
               "Qual e o gas essencial para a respiracao humana?",  
               "Que parte do corpo e responsavel pelo bombeamento do sangue?",  
               "Qual e a principal fonte de energia para as plantas?",  
               "Qual e o nome do processo pelo qual as plantas produzem seu proprio alimento?",  
               "Qual e o maior osso do corpo humano?",  
               "Que nome se da a mudança do estado liquido para o gasoso?",  
               "Como e chamado o movimento rotatorio da Terra?",  
               "Que tipo de celula não possui nucleo definido?",  
               "Qual e o metal liquido à temperatura ambiente?",  
               "Qual e o nome do acido presente no estomago humano?",  
               "Qual particula subatomica tem carga negativa?",  
               "Como e chamado o processo de divisao celular das celulas sexuais?",  
               "Qual e o nome do fenomeno que explica a propagação da luz em meios diferentes?",  
               "Qual e o nome do hormonio responsavel pela regulação do acucar no sangue?",  
               "Qual e o nome da estrutura celular responsavel pela producao de energia?",  
               "Como e chamado o tipo de reacao quimica que libera calor?",  
               "Qual e o nome da propriedade da materia que mede sua resistencia a variacao de movimento?",  
               "Que orgao os humanos usam para pensar?"  
           };  
     
           char respostas[20][50] = {  
               "Liquido", "Mercurio", "Oxigenio", "Coracao", "Luz",  
               "Fotossintese", "Femur", "Evaporacao", "Rotacao", "Procarionte",  
               "Mercurio", "Cloridrico", "Eletron", "Meiose", "Refracao",  
               "Insulina", "Mitocondria", "Exotermica", "Inercia", "Cerebro"  
           };  
      
     int difOrdem[20], embar, ale;  
        int i;  
        p.acertos = 0; 
        for(i = 0; i < 20; i++){  
         difOrdem[i] = i;  
     }  
       
     srand(time(NULL));  
       
     for(i = 0; i < 20; i++){  
      ale = rand() % 20;  
      embar = difOrdem[i];  
      difOrdem[i] = difOrdem[ale];  
      difOrdem[ale] = embar;  
     }  
       
     int cont;  
       
     for(cont = 0; cont < 10; cont++){  
      int numList = difOrdem[cont];  
    printf("\nPergunta %d - %s \n", cont + 1, perguntas[numList]);  
      scanf(" %s", &resposta);  
        
       if(strcmp(resposta, respostas[numList]) == 0){  
           printf("Resposta Certa!\n");  
           p.acertos++;  
       } else {  
           printf("Errou! A Resposta Certa era: %s\n", respostas[numList]);  
       }  
     }  
       
     printf("\nParabens, %s. Você acertou %d de 10 perguntas.\n", p.nome, p.acertos);  
     salvarPlacar(p); 
    }  
    else if(decisao == 4){ // Português  
     char perguntas[20][256] = {  
               "Qual e o antonimo da palavra 'bom'?",  
               "Como se chama o sinal usado no final de uma pergunta?",  
               "Qual e o plural da palavra “flor”?",  
               "Como se chama a palavra que indica uma acao?",  
               "Qual e a forma correta: “excessao” ou “excecao”?",  
               "Qual e a classe gramatical da palavra 'feliz'?",  
               "Qual figura de linguagem consiste em comparar duas ideias usando 'como'?",  
               "Qual e o aumentativo de 'casa'?",  
               "Qual e o termo usado para descrever um erro de linguagem que se torna comum e aceitavel?",  
               "Como se chama o trecho de uma palavra retirado do final para formar um apelido ou termo informal, como em 'prof' de 'professor'?",  
               "Qual e o termo que indica a relacao de causa, consequencia, tempo etc., como “porque” e “quando”?",  
               "Como se chama o estudo da origem das palavras?",  
               "Qual e a forma correta: “mas” ou “mais” para indicar oposicao?",  
               "Qual e o nome do sinal grafico usado para indicar a omissao de letras, como em “esta” e “’ta”?",  
               "Como se chama a figura de linguagem que atribui caracteristicas humanas a seres inanimados?",  
               "Qual e a palavra que designa a repeticao de um som no final dos versos?",  
               "Como e chamada a parte da gramatica que estuda a estrutura das palavras?",  
               "Qual e o nome dado a troca de letras ou sons entre palavras, como “grande” virando “glande”?",  
               "Como se chama o uso exagerado de palavras para expressar uma ideia?",  
               "Qual e a palavra que indica uma ambiguidade ou duplo sentido proposital?"  
           };  
     
           char respostas[20][50] = {  
               "Ruim", "Interrogacao", "Flores", "Verbo", "Excecao",  
               "Adjetivo", "Comparacao", "Casarao", "Vicio", "Abreviacao",  
               "Conjuncao", "Etimologia", "Mas", "Apostrofo", "Personificacao",  
               "Rima", "Morfologia", "Metatese", "Pleonasmo", "Ambiguidade"  
           };  
      
     int difOrdem[20], embar, ale;  
        int i;  
        p.acertos = 0;  
        for(i = 0; i < 20; i++){  
         difOrdem[i] = i;  
     }  
       
     srand(time(NULL));  
       
     for(i = 0; i < 20; i++){  
      ale = rand() % 20;  
      embar = difOrdem[i];  
      difOrdem[i] = difOrdem[ale];  
      difOrdem[ale] = embar;  
     }  
       
     int cont;  
       
     for(cont = 0; cont < 10; cont++){  
      int numList = difOrdem[cont];  
      printf("\nPergunta %d - %s \n", cont + 1, perguntas[numList]);  
      scanf(" %s", &resposta);  
        
       if(strcmp(resposta, respostas[numList]) == 0){  
           printf("Resposta Certa!\n");  
           p.acertos++;  
       } else {  
           printf("Errou! A Resposta Certa era: %s\n", respostas[numList]);  
       }  
     }  
       
     printf("\nParabens, %s. Você acertou %d de 10 perguntas.\n", p.nome, p.acertos);  
     salvarPlacar(p); 
    }  
    else if(decisao == 5){ // Matemática  
     char perguntas[20][256] = {  
               "Qual e a operacao contraria da multiplicacao?",  
               "Como se chama o resultado de uma adicao?",  
               "Como se chama o número que representa nada?",  
               "Qual e a forma geometrica com tres lados?",  
               "Qual e o nome da linha que divide uma figura ao meio igualmente?",  
               "Qual e a operacao usada para descobrir a diferença entre dois numeros?",  
               "Qual e o nome da figura com quatro lados iguais e angulos retos?",  
               "Como se chama o numero que nao é par?",  
               "Qual e o nome do valor que representa uma quantidade desconhecida em uma equacao?",  
               "Como se chama a parte de cima de uma fracao?",  
               "Qual e o nome do numero que divide exatamente outro numero?",  
               "Como se chama a comparacao entre dois numeros, como em fracoes ou porcentagens?",  
               "Qual e o nome do ponto onde duas retas se cruzam?",  
               "Qual e o nome do numero que multiplica uma variavel em uma equacao algebrica?",  
               "Qual e o nome do espaço delimitado por curvas ou linhas em um grafico?",  
               "Qual e o nome da relacao entre dois conjuntos onde cada elemento de um se relaciona a um unico do outro?",  
               "Como se chama a parte da matematica que estuda formas no espaco?",  
               "Qual e o nome da quantidade que aparece com maior frequencia em um conjunto de dados?",  
               "Qual e o termo usado para indicar um valor que aparece no meio de um conjunto ordenado?",  
               "Qual e o nome da transformacao que gira uma figura em torno de um ponto fixo?"  
           };  
      
           char respostas[20][50] = {  
               "Divisao", "Soma", "Zero", "Triangulo", "Simetria",  
               "Subtracao", "Quadrado", "Impar", "Icognita", "Numerador",  
               "Divisor", "Razao", "Intersecao", "Coeficiente", "Area",  
               "Funcao", "Geometria", "Moda", "Mediana", "Rotacao"  
           };  
      
     int difOrdem[20], embar, ale;  
        int i;  
        p.acertos = 0; 
        for(i = 0; i < 20; i++){  
         difOrdem[i] = i;  
     }  
       
     srand(time(NULL));  
       
     for(i = 0; i < 20; i++){  
      ale = rand() % 20;  
      embar = difOrdem[i];  
      difOrdem[i] = difOrdem[ale];  
      difOrdem[ale] = embar;  
     }  
       
     int cont;  
       
     for(cont = 0; cont < 10; cont++){  
      int numList = difOrdem[cont];  
      printf("\nPergunta %d - %s \n", cont + 1, perguntas[numList]);  
      scanf(" %s", &resposta);  
        
       if(strcmp(resposta, respostas[numList]) == 0){  
           printf("Resposta Certa!\n");  
           p.acertos++;  
       } else {  
           printf("Errou! A Resposta Certa era: %s\n", respostas[numList]);  
       }  
     }  
       
     printf("\nParabens, %s. Você acertou %d de 10 perguntas.\n", p.nome, p.acertos);  
     salvarPlacar(p); 
    }  
    else{  
     printf("Escolha Inválida!");  
    }  
   break; 
  
  case 2: 
   listarPlacar(); 
  break; 
  
  case 3: 
   system("cls"); 
   printf("Creditos\n"); 
   printf("Participantes:\n\n"); 
   printf("Victor  Hugo Borba Da Silva Bento N°: 202503229325\n"); 
   printf("Eduardo Gomes De Moura Martins N°: 202502645686\n"); 
   printf("Carlos Eduardo Borba Da Silva Bento N°: 202503725632\n\n"); 
   printf("Agradecimentos especiais: \nAgradecemos a todos que contribuiram direta ou indiretamente " 
    "para a realizacao deste projeto, incluindo colegas, familiares e amigos que ofereceram suporte e "  
    "feedback ao longo do desenvolvimento.\nAdjunto a isso, somos gratos ao professor jorge varela"  
    "por nos instruir por esse caminho."); 
  break; 
   
  case 4: 
   system("cls"); 
    printf("REGRAS:\n");
	printf("Escreva as respostas sempre com a primeira letra em maiuscolo e sem acentos nem espacos.");
	printf("Se divirta!");
  break; 
  
  case 5:
  	system("cls");
    printf("Obrigado por jogar, volte sempre"); 
  break;
   
  default: 
   printf("Opcao nao reconhecida"); 
 } 
} while (opcao !=5);
}  