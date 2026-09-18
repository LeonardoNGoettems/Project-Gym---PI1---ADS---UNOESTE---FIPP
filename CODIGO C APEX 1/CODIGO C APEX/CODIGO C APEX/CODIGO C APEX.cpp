#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define tf10 10
#define tf20 20

main(){
    int i,menu,pos;
    //Avaliacao
    int vLInst[tf20],codigoDigitado,qtdAva=0;
    char vLAluno[tf20][15],CPFdigitado[15],vLDataAval[tf20][11];;
    //Modalidade
    int vCodMod[tf10],vValorAula[tf10],totalMod=0,CodModDigitado,qtdMod=0 ;
    char vModalidade[tf10][100], nomeModalidade[50];
    //Aluno
    int vDiaVenc[tf20], vValorPlano[tf20],DiaHoje,qtdAlu=0,j=0,vetCPF[11],mult, n_mult,soma, resto, sub, d1, d2, n_mult2, soma2;
    char vNomeAluno[tf20][100], nomeAluno[50], vCPFAluno[tf20][15], nomeaux[50], cpfaux[15], dataaux[12], s[2];
    // Instrutor
    int vCodInst[tf10],qtdInst=0;
    char vInstrutor[tf10][100], nomeInstrutor[50];
    //tl usados
    int tl=0,tli=0,tla=0,tlm=0;

    //ENTRA LIDO
    printf("\n====================MENU==========================");
    printf("\nCadastrar Instrutor (1)");
    printf("\nCadastrar Aluno (2)");
    printf("\nCadastrar Modalidade (3)");
    printf("\nConsultar Instrutores (4)");
    printf("\nConsultar Alunos (5)");
    printf("\nConsultar Modalidades (6)");
    printf("\nExcluir Instrutor (7)");
    printf("\nExcluir Aluno (8)");
    printf("\nExcluir Modalidade (9)");
    printf("\nAvaliacao Fisica (10)");
    printf("\nRelatorio (11)");
    printf("\nSair (0)");
    printf("\nOpcao: ");
    fflush(stdin);
    scanf("%d", &menu);
//==================================================================================================================================================================================================
	
    while(menu!=0){
        switch(menu){
        	//CADASTRO DO INSTRUTOR
            case 1:
                printf("Nome Instrutor:"); //nome instrutor
                fflush(stdin); // limpeza buffer
                gets(nomeInstrutor); // salva nome do instrutor
                
                //verificar se instrutor ja esta cadastrado
                pos=0;
                while(pos<tli && stricmp(nomeInstrutor,vInstrutor[pos])!=0)
                    pos++;
                
                if(pos<tli){
                    // achou instrutor nao cadastra
                    printf("\n Instrutor ja cadastrado");
                }else{
                    //nao achou instrutor cadastrado
                    strcpy(vInstrutor[tli],nomeInstrutor); // NUM = NUM so que em string
                    printf("Codigo:"); // codigo do instrutor
                    scanf("%d",&vCodInst[tli]); // salva o codgio do instrutor
                    printf("\nInstrutor cadastrado com sucesso!!!");
                    qtdInst++;
                    tli++;
                }
                break; 

//==================================================================================================================================================================================================




		    // CADASTRO DO ALUNO
            case 2:
                printf("\nNome Aluno:"); //nome aluno
                fflush(stdin); // limpeza buffer
                gets(nomeAluno); // salva nome do aluno
                
                //verificar se aluno ja esta cadastrado
                pos=0;
                while(pos<tla && stricmp(nomeAluno,vNomeAluno[pos])!=0)
                    pos++;
                
                if(pos<tla){
                    //achou aluno ja cadastrado
                    printf("Aluno ja cadastrado");
                }else{
                    //nao achou aluno cadastrado
                    strcpy(vNomeAluno[tla],nomeAluno); // NUM = NUM so que em string
                    printf("CPF:"); // CPF do Aluno
                    fflush(stdin); // Limpa o buffer
                    gets(vCPFAluno[tla]); // Salva o CPF como string usando gets
                    
                    j = 0;
                    soma = 0;
                    soma2 = 0;
                    n_mult = 10;
                    n_mult2 = 11;
                    
                    for(i=0; i<14; i++){
                        if(vCPFAluno[tla][i] != '.' && vCPFAluno[tla][i] != '-'){
                            s[0]= vCPFAluno[tla][i];
                            s[1]= '\0';
                            vetCPF[j]= atoi(s);
                            j++;
                        }
                    }
                    
                    for(i=0; i<9; i++){
                        mult= vetCPF[i]* n_mult--;
                        soma= soma+ mult;
                    }
                    
                    resto= soma %11;
                    sub= 11- resto;
                    
                    if(sub== 10 || sub== 11)
                        d1= 0;
                    else
                        d1= sub;
                        
                    for(i=0; i<9; i++){
                        mult= vetCPF[i]* n_mult2--;
                        soma2= soma2+ mult;
                    }
                    
                    soma2= soma2+ d1*2;
                    resto= soma2 %11;
                    sub= 11- resto;
                    
                    if(sub== 10 || sub== 11)
                        d2= 0;
                    else
                        d2= sub;
                        
                    if(vetCPF[9]== d1 && vetCPF[10]== d2){
                        printf("\n\t CPF correto.\n");
                        // Validacao do dia usando se e menor que 1 e maior que 31
                        printf("Dia Vencimento Plano (1 a 31): ");
                        scanf("%d",&vDiaVenc[tla]);
                        
                        // Se o dia for menor que 1 OU maior que 31, entra no erro
                        if(vDiaVenc[tla] < 1 || vDiaVenc[tla] > 31) {
                            // Enquanto o usuario continuar digitando errado, o programa prende ele aqui
                            while(vDiaVenc[tla] < 1 || vDiaVenc[tla] > 31) {
                                printf("[ERRO] Dia invalido! O mes so tem ate 31 dias.\n");
                                printf("Digite novamente o Dia do Vencimento: ");
                                scanf("%d",&vDiaVenc[tla]);
                            }
                        } else {
                            // Se digitou certo de primeira, entra no else
                            printf("Dia aceito com sucesso!\n");
                        }
                        
                        //saber quais modalidades ja tem no sistema
                        if (tlm == 0) {
                            printf("\nNenhuma modalidade cadastrada no sistema!\n");
                            printf("Cadastre uma modalidade para continuar o cadastro do Aluno\n");
                        } else {
                            for(i=0;i<tlm;i++){
                                printf("\nModalidade:%s \nCodigo:%d \nValor da Aula:%d\n",vModalidade[i],vCodMod[i],vValorAula[i]);
                            }
                            
                            totalMod = 0;
                            printf("Codigo Modalidade (0 para encerrar): ");
                            scanf("%d", &CodModDigitado);
                            
                            while(CodModDigitado!=0){
                                pos=0;
                                while(pos<tlm && vCodMod[pos]!=CodModDigitado)
                                    pos++;
                                    
                                if(pos<tlm){
                                    //achou modalidade
                                    totalMod= totalMod+vValorAula[pos];
                                    for(i=0;i<tlm;i++){
                                        printf("\nModalidade:%s \nCodigo:%d \nValor:%d\n",vModalidade[i],vCodMod[i],vValorAula[i]);
                                    }
                                    printf("Proximo codigo de Modalidade (0 para encerrar): ");
                                    scanf("%d", &CodModDigitado);
                                }else{
                                    //nao achou modalidade
                                    printf("Modalidade nao encontrada!!!");
                                    printf("Tente novamente (0 para encerrar): ");
                                    scanf("%d", &CodModDigitado);
                                }
                            }
                            vValorPlano[tla] = totalMod;
                            printf("\nValor do Plano: %d", totalMod);
                            printf("\nAluno cadastrado com sucesso!!!");
                            qtdAlu++;
                            tla++;
                        }
                    } else {
                        printf("\n\t CPF incorreto.\n");
                    }
                }
                break;



 //==================================================================================================================================================================================================
            
			// CADASTRO MODALIDADE
            case 3:
                printf("\nModalidade:");
                fflush(stdin);
                gets(nomeModalidade);
                
                //verificar se aluno ja esta cadastrado
                pos=0;
                while(pos<tlm && stricmp(nomeModalidade,vModalidade[pos])!=0)
                    pos++;
                    
                if(pos<tlm){
                    printf("Modalidade ja cadastrada");
                }else{
                    strcpy(vModalidade[tlm],nomeModalidade);
                    printf("Codigo:");
                    scanf("%d",&vCodMod[tlm]);
                    printf("Valor Aula:");
                    scanf("%d",&vValorAula[tlm]);
                    printf("\nModalidade Cadastrada!!!");
                    qtdMod++;
                    tlm++;
                }
                break;



//==================================================================================================================================================================================================
			// CONSULTAR INSTRUTORES
            case 4:
                //Verifica se tem instrutores cadastrados
                if (tli == 0) {
                    printf("\nNenhum instrutor cadastrado no sistema!\n");
                } else {
                    for(i=0;i<tli;i++){
                        //ACHOU - MOSTRA O instrutor e o codigo
                        printf("\nNome Instrutor:%s \nCodigo:%d", vInstrutor[i],vCodInst[i]);
                    }
                }
                break;
				
				
				
				 
//==================================================================================================================================================================================================
			 // CONSULTAR ALUNOS
            case 5:
                // Verifica se tem alunos cadastrados usando IF e ELSE
                if (tla == 0) {
                    printf("\nNenhum aluno cadastrado no sistema!\n");
                } else {
                    for(i=0;i<tla;i++){
                        //ACHOU - MOSTRA O aluno, cpf, dia do vencimento do plano e o valor
                        printf("\nNome Aluno:%s \nCpf:%s \nDia Vencimento do plano:%d \nValor Plano:%d \n", vNomeAluno[i],vCPFAluno[i],vDiaVenc[i],vValorPlano[i]);
                    }
                }
                break;
                
                
                
                
//==================================================================================================================================================================================================
			// CONSULTAR MODALIDADE
            case 6:
                // Verifica se tem modalidades cadastradas usando
                if (tlm == 0) {
                    printf("\nNenhuma modalidade cadastrada no sistema!\n");
                } else {
                    for(i=0;i<tlm;i++){
                        printf("\nModalidade:%s \nCodigo:%d \nValor da Aula:%d\n",vModalidade[i],vCodMod[i],vValorAula[i]);
                    }
                }
                break; 
                
                
                
//==================================================================================================================================================================================================
			// EXCLUIR INSTRUTOR
            case 7:
                // Verifica se existe algum instrutor para ser excluido
                if (tli == 0) {
                    printf("\nNao ha nenhum instrutor cadastrado para excluir!\n");
                } else {
                    printf("Qual instrutor Excluir:");
                    fflush(stdin);
                    gets(nomeInstrutor);
                    pos=0;
                    while(pos<tli && stricmp(nomeInstrutor,vInstrutor[pos])!=0)
                        pos++;
                        
                    if(pos<tli){
                        //achou o instrutor e pode deletar
                        for(i=pos;i<tli-1;i++){
                            vCodInst[i]=vCodInst[i+1];
                            strcpy(vInstrutor[i],vInstrutor[i+1]);
                        }
                        printf("Instrutor Excluido");
                        tli--;
                        qtdInst--;
                    }else{
                        printf("Instrutor Nao Encontrado");
                    }
                }
                break; 
                
                
                
                
//==================================================================================================================================================================================================
			// EXCLUIR ALUNO
            case 8:
                printf("\nData de Hoje:");
                scanf("%d",&DiaHoje);
                if(DiaHoje < 1 || DiaHoje > 31){
                    while(DiaHoje < 1 || DiaHoje > 31){
                        printf("\n[ERRO] Dia invalido! O mes so tem ate 31 dias.\n");
                        printf("\nDigite novamente o Dia do Vencimento: ");
                        scanf("%d",&DiaHoje);
                    }
                }else{
                    //numero esta entre 31 dias do mes
                    printf("\n Dia Valido =)");
                }
                
                if(tla == 0){
                    printf("\nNao ha nenhum aluno cadastrado para excluir!\n");
                } else{
                    printf("\nQual Aluno Excluir: ");
                    fflush(stdin);
                    gets(nomeAluno);
                    pos=0;
                    while(pos<tla && stricmp(nomeAluno,vNomeAluno[pos])!=0)
                        pos++;
                        
                    if(pos<tla){
                        if(DiaHoje < vDiaVenc[pos]){
                            //verifica o dia atual e o dia de vencimento para dai ai sim excluir
                            printf("\nAluno nao pode ser excluido");
                        }else{
                            for(i=pos;i<tla-1;i++){
                                strcpy(vNomeAluno[i],vNomeAluno[i+1]);
                                // Copia a string do CPF para tras na exclusão
                                strcpy(vCPFAluno[i], vCPFAluno[i+1]);
                                vDiaVenc[i] = vDiaVenc[i+1];
                                vValorPlano[i] = vValorPlano[i+1];
                            }
                            printf("Aluno Excluido");
                            tla--;
                            qtdAlu--;
                        }
                    }else{
                        printf("Aluno nao Encontrado");
                    }
                }
                break; 
                
                
                
                
//==================================================================================================================================================================================================
			// EXCLUIR MODALDIADE
            case 9:
                //Verifica se existe alguma modalidade para ser excluida
                if (tlm == 0) {
                    printf("\nNao ha nenhuma modalidade cadastrada para excluir!\n");
                } else {
                    printf("Qual Modalidade Excluir:");
                    fflush(stdin);
                    gets(nomeModalidade);
                    pos=0;
                    while(pos<tlm && stricmp(nomeModalidade,vModalidade[pos])!=0)
                        pos++;
                        
                    if(pos<tlm){
                        for(i=pos;i<tlm-1;i++){
                            vCodMod[i]=vCodMod[i+1];
                            strcpy(vModalidade[i],vModalidade[i+1]);
                        }
                        printf("Modalidade Excluida");
                        tlm--;
                        qtdMod--;
                    }else{
                        printf("Modalidade nao Encontrada");
                    }
                }
                break; 
                
                
                
//==================================================================================================================================================================================================
			//AVALIACAO
            case 10:
                printf("Qual o codigo do Instrutor que realizara a avalicao:");
                scanf("%d",&codigoDigitado);
                pos=0;
                while( pos<tli && vCodInst[pos]!=codigoDigitado)
                    pos++;
                    
                if(pos<tli){
                    // achou codigo instrutor
                    //cpf do aluno
                    printf("Qual o cpf do Aluno que realizara a avalicao:");
                    fflush(stdin);
                    gets(CPFdigitado);
                    pos=0;
                    while(pos<tla && stricmp(CPFdigitado ,vCPFAluno[pos])!=0)
                        pos++;
                        
                    if(pos<tla){
                        //achou o cpf do aluno
                        printf("Data da Avaliacao:");
                        fflush(stdin);
                        gets(vLDataAval[tl]);
                        vLInst[tl]=codigoDigitado;
                        strcpy(vLAluno[tl],CPFdigitado);
                        tl++;
                        printf("Data de avaliacao Concluida!!!");
                        qtdAva++;
                    }else{
                        // nao achou cpf do aluno
                        printf("CPF do Aluno nao Encontrado!!!");
                    }
                }else{
                    //nao achou codigo instrutor
                    printf("Codigo do Instrutor nao Encontrado!!!");
                }
                break;
                
                
                
//==================================================================================================================================================================================================
			//RELATORIO
            case 11:
                printf("Quantidade de Instrutores no Sistema: %d\n",qtdInst);
                printf("Quantidade de Avaliacao Fisica no Sistema: %d\n",qtdAva);
                printf("Quantidade de Alunos no Sistema: %d\n",qtdAlu);
                printf("Quantidade de Modadelidade no Sistema: %d",qtdMod);
                break;

            case 0:
                break; // SAIR DO MENU

            default:
                printf("\nNumero Invalido");
        }
        
        
        
//==================================================================================================================================================================================================

        //SAI LIDO
        printf("\n====================MENU==========================");
        printf("\nCadastrar Instrutor (1)");
        printf("\nCadastrar Aluno (2)");
        printf("\nCadastrar Modalidade (3)");
        printf("\nConsultar Instrutore (4)");
        printf("\nConsultar Alunos (5) ");
        printf("\nConsultar Modalidade (6)");
        printf("\nExcluir Instrutor (7)");
        printf("\nExcluir Aluno (8)");
        printf("\nExcluir Modalidade (9)");
        printf("\nAvaliacao Fisica (10)");
        printf("\nRelatorio (11)");
        printf("\nSair (0)");
        printf("\nOpcao: ");
        fflush(stdin);
        scanf("%d", &menu);
    }
}


