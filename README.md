### Retirar espaço a direita de variáveis string

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void RightTrim( char *STR )
  {
    int cont;

    cont = strlen( STR );
    cont--;

    while( (!isalnum(STR[cont])) && (cont>-1) )
      {
        cont--;
      }

    STR[cont+1] = '\0';
  } /* RightTrim */
```

### Retirar espaço a esquerda de variáveis string

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void LeftTrim( char *STR )
  {
    char *NEW;
    int cont, i, j;

    cont = strlen( STR );
    NEW = (char*) malloc ((cont+1)*sizeof(char));
    i=0;

    while ( (i<cont) && (STR[i]==' ') )
      i++;

    j=0;

    for (; i<cont; i++ )
      {
        NEW[j] = STR[i];
        j++;
      }

    NEW[j] = '\0';
    strcpy( STR, NEW );
    free( NEW );
  } /* LeftTrim */
```

### Retirar espaço entre as palavras de variáveis string

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void MiddleTrim( char *STR )
  {
    char *NEW;
    int cont, i, j;

    cont = strlen( STR );
    NEW = (char*) malloc ((cont+1)*sizeof(char));
    j = 0;

    for ( i=0; i<cont; i++ )
      {
        NEW[j] = STR[i];
        while ( (i<cont) && (STR[i]==' ') && (STR[i+1]==' ') )
          i++;
        j++;
      }

    NEW[j] = '\0';
    strcpy( STR, NEW );
    free( NEW );
  } /* MiddleTrim */
```

### Pega a data corrente e colocando no formato informado

```
/**************************************************************************
** Descricao       : Pega a data corrente e colocando no formato informado
** Parametros      : char *pszDtHr - ponteiro para o array onde sera retornada a data formatada
**                   int format - formato desejado
** Outras Observ.  : formato:
**                    YMDHMS        1          yyyymmddhh24mmss
**                    YMD_HMS       2          yyyymmdd_hh24mmss
**                    YMD           3          yyyymmdd
**************************************************************************/
void fFormDtCorrente(char *pszDtHr, int format) {
    time_t timer;
    struct tm *tblock;

    timer = time(NULL);
    tblock = localtime(&timer);
    switch (format ) {
       case YMDHMS:
           sprintf (pszDtHr, "%04d%02d%02d%02d%02d%02d", 
                    tblock->tm_year+1900,
                    tblock->tm_mon+1, 
                    tblock->tm_mday, 
                    tblock->tm_hour,
                    tblock->tm_min, 
                    tblock->tm_sec);
           break;

       case YMD_HMS:
           sprintf (pszDtHr, "%04d%02d%02d_%02d%02d%02d", 
                    tblock->tm_year+1900,
                    tblock->tm_mon+1, 
                    tblock->tm_mday, 
                    tblock->tm_hour,
                    tblock->tm_min, 
                    tblock->tm_sec);
           break;

       case YMD:
           sprintf (pszDtHr, "%04d%02d%02d",
                    tblock->tm_year+1900, 
                    tblock->tm_mon+1, 
                    tblock->tm_mday);
           break;
     }
     
}/* fFormDtCorrente() */
```

### Executa um comando no UNIX/DOS e armazena e retorna o resultado

```
void ExecutaComando(char *strComando, char *strResultado)
{		  
  FILE *fp;
  char strAuxResultado[1000];  
   
  fp = popen(strComando, "r");
  if (fp == NULL) {
    printf("\nErro ao executar o comando %s\n", strComando);
    pclose(fp);    
    exit;
  }
  
  if (fgets(strAuxResultado, sizeof(strAuxResultado), fp) == NULL) {
  	printf("\nErro ao executar o comando %s\n", strComando);
  	pclose(fp);    
    exit;
  }  
  
  RightTrim(strAuxResultado);
  strcpy(strResultado, strAuxResultado);
  
  pclose(fp);    
}
```
