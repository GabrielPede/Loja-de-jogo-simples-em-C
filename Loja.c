#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 1000


typedef struct{
    char nome[50];
    int cpf;
    char email[50];
} cliente;

typedef struct {
    char nomej[50];
    int valor;
    int quant;
    int codigo;
} jogo;

typedef struct {
    int dias;
    int qjogos;
    int vjogos;
} alugar;


cliente sclientes[size];
int contc = 0;

jogo sjogos[size];
int contj = 0;

alugar salugar[size];
int conta = 0;

void MenuCadastro();
void Cadastrar();
void VisualizarCliente();
cliente ProcurarCliente();
void RemoverCliente();

void MenuProduto();
void Adicionar();
void VisualizarProduto();
jogo ProcurarProduto();
void RemoverProduto();

void MenuAluguel();
void Alugar();
void VisualizarAluguel();
alugar ProcurarAluguel();
void RemoverAluguel();

int main(){

    int opcao = 0;
        while(1)
        {
            printf("________________________________________________________\n");
            printf("\n                MENU DA LOJA DE JOGOS\n");
            printf("________________________________________________________\n");
            printf("0 - SAIR\n1 - CADASTRAR UM CLIENTE\n2 - ADICIONAR UM JOGO\n3 - ALUGAR\n");
            printf("________________________________________________________\n");
            printf("DIGITE SUA OPCAO: ");
            scanf("%d", &opcao);

            if (opcao == 0)
            {
                printf("________________________________________________________\n");
                printf("\n                TENHA UM BOM DIA !!!\n");
                printf("________________________________________________________\n");
                break;
            }

            if (opcao == 1)
            {
                MenuCadastro();
                continue;
            }

            if (opcao == 2)
            {
                MenuProduto();
                continue;
            }

            if (opcao == 3)
            {
                MenuAluguel();
                continue;
            }
        }    
}

void MenuCadastro(){

    int opcao1 = 0;
        while (1)
        {
            printf("________________________________________________________\n");
            printf("\n                MENU DE CADASTRO\n");
            printf("________________________________________________________\n");
            printf("0 - VOLTAR\n1 - CADASTRAR\n2 - VISUALIZAR\n3 - PROCURAR CLIENTE\n4 - REMOVER CLIENTE\n");
            printf("DIGITE SUA OPCAO: ");
            scanf("%d", &opcao1);

            if (opcao1 == 0)
                break;

            if (opcao1 == 1)
            {
                Cadastrar();
                continue;
            }
            
            if (opcao1 == 2)
            {
                VisualizarCliente();
                continue;
            }

            if (opcao1 == 3)
            {
                cliente procurado = ProcurarCliente();
                printf("________________________________________________________\n");
                printf("\nCPF procurado: %d\n", procurado.cpf);
                printf("Nome procurado: %s\n", procurado.nome);
                printf("Email procurado: %s\n",procurado.email);
                continue;
            }
            
            if (opcao1 == 4)
            {
                RemoverCliente();
                continue;
            }   
        }
}

void Cadastrar(){

    int cr = 0;
    while (1)
    {
        printf("Nome do cliente:");
        fflush(stdin);
        fgets(sclientes[contc].nome, 50, stdin);
        printf("CPF do cliente:");
        scanf("%d", &sclientes[contc].cpf);
        printf("Email do cliente:");
        fflush(stdin);
        fgets(sclientes[contc].email, 50, stdin);
        contc++;

        printf("Digite 0 para sair e 1 para cadastrar outro cliente: ");
        scanf("%d", &cr);
        if (cr == 0)
            break;
    }
    
}

void VisualizarCliente(){
    
    for (int i = 0; i < contc; i++)
    {
        printf("________________________________________________________\n");
        printf("Nome do cliente: %s\n",sclientes[i].nome);
        printf("CPF do cliente: %d\n",sclientes[i].cpf);
        printf("Email do cliente: %s\n",sclientes[i].email);
        printf("________________________________________________________\n");
    }                   
}

 cliente ProcurarCliente(){

    int procurar = 0;
    printf("Digite o CPF do cliente para procura-lo: ");
    scanf("%d" ,&procurar);

    for (int i = 0; i < contc; i++)
    {
        if(procurar == sclientes[i].cpf)
            return sclientes[i];
    }

    cliente clientevazio;
    printf("\nO cliente nao foi encontrando. DADOS INVALIDOS.\n");
    clientevazio.cpf = 0;
    strcpy(clientevazio.nome,"0");
    strcpy(clientevazio.email,"0");
    return clientevazio;
}

void RemoverCliente(){

    int i,j;
    int procurar = 0;
    printf("Digite o CPF do cliente para remove-lo: ");
    scanf("%d" ,&procurar);

    for ( i = 0; i < contc; i++)
    {
        if(procurar == sclientes[i].cpf)
        {
            for ( j = i; j < contc - 1; j++)
            {
                sclientes[j] = sclientes[j + 1];
            }
            printf("Cliente removido.\n");
            contc--;
        }
            
    }



}

void MenuProduto(){

    int opcao2 = 0;
        while (1)
        {
            printf("________________________________________________________\n");
            printf("\n                MENU DO PRODUTO\n");
            printf("________________________________________________________\n");
            printf("0 - VOLTAR\n1 - ADICIONAR\n2 - VISUALIZAR\n3 - PROCURAR JOGO\n4 - REMOVER JOGO\n");
            printf("DIGITE SUA OPCAO: ");
            scanf("%d", &opcao2);
                    
            if (opcao2 == 0)
                break;

            if (opcao2 == 1)
            {
                Adicionar();
                continue;
            }

            if (opcao2 == 2)
            {
                VisualizarProduto();
                continue;
            }

            if (opcao2 == 3)
            {
                jogo procurado = ProcurarProduto();
                printf("________________________________________________________\n");
                printf("Nome do jogo procurado: %s\n", procurado.nomej);
                printf("Codigo do jogo: %d\n", procurado.codigo);
                printf("Quantidade do jogo procurado: %d\n", procurado.quant);
                printf("Valor do jogo procurado: %d\n",procurado.valor);
                continue;
            }

            if (opcao2 == 4)
            {
                RemoverProduto();
                continue;
            }
        }
}

void Adicionar(){
    
    int cr = 0;
    while (1)
    {
        printf("Nome do jogo: ");
        fflush(stdin);
        fgets(sjogos[contj].nomej, 50, stdin);
        printf("Codigo do jogo: ");
        scanf("%d", &sjogos[contj].codigo);
        printf("Valor do jogo: ");
        scanf("%d", &sjogos[contj].valor);
        printf("Quantos jogos: ");
        scanf("%d", &sjogos[contj].quant);
        
        contj++;

        printf("Digite 0 para sair ou 1 para adicionar mais jogos: ");
        scanf("%d", &cr);
        if(cr == 0)
            break;
    }
    
}

void VisualizarProduto(){

    for (int i = 0; i < contj; i++)
    {
        printf("________________________________________________________\n");
        printf("Nome do jogo: %s\n",sjogos[i].nomej);
        printf("Codigo do jogo: %d\n",sjogos[i].codigo);
        printf("Valor do jogo: %d\n",sjogos[i].valor);
        printf("Quantos jogos: %d\n",sjogos[i].quant);
        printf("________________________________________________________\n");
    }      
}

jogo ProcurarProduto(){

    int procurar = 0;
    printf("Digite o codigo do jogo: ");
    scanf("%d", &procurar);
    for (int i = 0; i < contj; i++)
    {
        if (procurar == sjogos[i].codigo)
            return sjogos[i];
    }
    
    jogo clientevazio;
    printf("\nO jogo nao foi encontrando. DADOS INVALIDOS.\n");
    clientevazio.quant = 0;
    clientevazio.valor = 0;
    strcpy(clientevazio.nomej,"0");
    clientevazio.codigo = 0;
    return clientevazio;
}

void RemoverProduto(){

    int i,j;
    int procurar = 0;
    printf("Digite o codigo do jogo para remove-lo: ");
    scanf("%d" ,&procurar);

    for ( i = 0; i < contj; i++)
    {
        if(procurar == sjogos[i].codigo)
        {
            for ( j = i; j < contj - 1; j++)
            {
                sjogos[j] = sjogos[j + 1];
            }
            printf("Jogo removido.\n");
            contj--;
        }
            
    }
}

void MenuAluguel(){

    int opcao3 = 0;
        while (1)
        {
            printf("________________________________________________________\n");
            printf("\n                MENU DO ALUGUEL\n");
            printf("________________________________________________________\n");
            printf("0 - VOLTAR\n1 - ALUGAR JOGO\n2 - VISUALIZAR PRODUTO ALUGADO\n3 - PROCURAR REGISTRO DE ALUGUEL\n4 - REMOVER REGISTRO DE ALUGUEL\n");
            printf("DIGITE SUA OPCAO: ");
            scanf("%d", &opcao3);
                        
            if (opcao3 == 0)
                break;

            if (opcao3 == 1)
            {
                Alugar();
                continue;
            }

            if (opcao3 == 2)
            {
                VisualizarAluguel();
                continue;
            }
             
             if (opcao3 == 3)
            {   
                int total = 0;
                alugar procurado = ProcurarAluguel();
                total = procurado.qjogos * procurado.vjogos;
                printf("________________________________________________________\n");
                printf("Dias alugados: %d\n", procurado.dias);
                printf("Quantos jogos alugados: %d\n", procurado.qjogos);
                printf("Valor dos jogos alugados: %d\n", procurado.vjogos);
                printf("O valor todal do aluguel foi: %d\n" ,total);
            }
             if (opcao3 == 4)
            {
                RemoverAluguel();
                continue;
            }
        }
}

void Alugar(){
  
    int cr = 0;
    while (1)
    {
        printf("Quantos dias de aluguel: ");
        scanf("%d", &salugar[conta].dias);
        printf("Quantos jogos: ");
        scanf("%d", &salugar[conta].qjogos);
        printf("Valor dos jogos: ");
        scanf("%d", &salugar[conta].vjogos);
        conta++; 

        printf("Digite 0 para sair e 1 para fazer um novo registro de aluguel: ");
        scanf("%d", &cr);
        if (cr == 0)
        break;
    }    
}

void VisualizarAluguel(){

    int total[1000];
    
    for (int i = 0; i < conta; i++)
        total[i] = salugar[i].qjogos * salugar[i].vjogos;    
    
    for (int i = 0; i < conta; i++)
    {
        printf("________________________________________________________\n");
        printf("Dias alugados: %d\n", salugar[i].dias);
        printf("Quantos jogos: %d\n", salugar[i].qjogos);
        printf("Valor total: %d\n", total[i]);
        printf("________________________________________________________\n");
    }   
}

alugar ProcurarAluguel(){

    int procurar = 0;
    printf("Digite quantos dias foi alugado: ");
    scanf("%d", &procurar);

    for (int i = 0; i < conta; i++)
    {
        if (procurar == salugar[i].dias)
            return salugar[i];
    }
    
    alugar clientevazio;
    printf("\nO jogo nao foi encontrando. DADOS INVALIDOS.\n");
    clientevazio.dias = 0;
    clientevazio.qjogos = 0;
    clientevazio.vjogos = 0;
    return clientevazio;

}

void RemoverAluguel(){

    int i,j;
    int procurar = 0;
    printf("Digite os quantos dias de aluguel para remover o registro: ");
    scanf("%d" ,&procurar);

    for ( i = 0; i < conta; i++)
    {
        if(procurar == salugar[i].dias)
        {
            for ( j = i; j < conta - 1; j++)
            {
                salugar[j] = salugar[j + 1];
            }
            printf("Aluguel removido.\n");
            conta--;
        }
            
    }    
}