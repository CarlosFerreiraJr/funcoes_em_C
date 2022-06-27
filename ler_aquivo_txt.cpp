#include <stdio.h>
#include <String.h>
#include <FileAccess.h>
#include <iostream.h>
#include <locale.h>

int main(int argc, char *argv[]) 
{
    char          diretorio[100];
    char          nome_arquivo[200];    
    FILE          * p_arquivo_txt = NULL;      
    char          str_registros[1000];
    time_t        now;
    struct tm     ts;
    char          buf[20];
    char          sdtProcessa[20];

    // Obtêm a data corrente
    time(&now);     	
    // Formata a data e hora
    ts = *localtime(&now);        
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", &ts);    	 
    strcpy(sdtProcessa,buf);	     	 
    printf("Data/Hora do Início do Processo: %s\n", sdtProcessa);

    printf("Iniciando a leitura do arquivo...\n");
    
    /* Configura o nome do arquivo que será lido */    
    strcpy(diretorio, "/opt/arbor/t3cafrj/teste/");      
    sprintf(nome_arquivo, "%s%s", diretorio, "dados.txt"); 
    
    /* Abre o arquivo para leitura */
	  p_arquivo_txt = fopen(nome_arquivo, "r");
    if(! p_arquivo_txt)    	
		  printf("Erro na abertura do arquivo [%s]\n", nome_arquivo);
    
    /* Loop de leitura do arquivo */
    while(!feof(p_arquivo_txt))
    {      	
     	fgets(str_registros, sizeof(str_registros), p_arquivo_txt);
      printf("%s", str_registros);
    }	
    fclose(p_arquivo_txt);
    
    printf("Fim da leitura do arquivo...\n");
     
     // Obtêm a data corrente
    time(&now);     	
    // Formata a data e hora
    ts = *localtime(&now);        
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", &ts);    	 
    strcpy(sdtProcessa,buf);	     	 
    printf("Data/Hora do Fim do Processo: %s\n", sdtProcessa);

	return 0;
}