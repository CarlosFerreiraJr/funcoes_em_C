/**********************************************************************************
** Interface      : trocapalavra
**
** Nome Arquivo   : trocapalavra.cpp
**
** Sintaxe        : trocapalavra 

** Descricao      : Programa que altera uma palavra por outra dentro de uma frase
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdarg.h>
#include <malloc.h>

using namespace std;

#define FALSE 0;
#define TRUE 1;

/**************************************************************************
** Funcao          : fStrSubst()
**
** Descricao       : Substitui uma substring por outra
** Parametros      : szFrase  - Frase a ser pesquisada e alterada.
**                   szAntigo - Substring a ser substituida.
**                   szNovo   - Substring a ser inserida sobre a antiga
** Valores Retorno : TRUE  - Se a substituicao foi com sucesso.
**                   FALSE - Se szAntigo nao foi encontrada em szFrase.
** ---------------------------------------------------------------------------
**   11/10/2014 : Autor   : Carlos Ferreira  
**                Versao inicial        
******************************************************************************/
int fStrSubst(char *szFrase, const char *szAntigo, const char *szNovo)
{
    int iErro = FALSE;
    char *pszRef;
    size_t lenAntigo, lenNovo, lenResto;

    /* Procurando o conteudo a ser substituido */
    pszRef = strstr(szFrase, szAntigo);
    if (pszRef != NULL)
    {
        lenAntigo = strlen(szAntigo);
        lenNovo   = strlen(szNovo);
        
        // Tamanho da parte restante da frase APÓS a palavra antiga (incluindo o '\0')
        lenResto  = strlen(pszRef + lenAntigo) + 1;

        /* Move a cauda da string para abrir ou fechar espaco */
        memmove(pszRef + lenNovo, pszRef + lenAntigo, lenResto);

        /* Copia a nova palavra para o local correto */
        memcpy(pszRef, szNovo, lenNovo);
    }
    else
    {
        iErro = TRUE;
    }

    return iErro;
}

int main(void)
{
    char sFrase[100]; /* Frase a ser pesquisada e alterada. */
    char sAntigo[10]; /* Substring a ser substituida. */
    char sNovo[10];   /* Substring a ser inserida sobre a antiga */    

    strcpy(sFrase,  "Carlos Alberto Ferreira Junior");
    strcpy(sAntigo, "Junior");
    strcpy(sNovo,   "Neto");

    printf("Frase antiga: [%s]\n", sFrase);
    fStrSubst(sFrase, sAntigo, sNovo); 
    printf("Nova frase: [%s]", sFrase);

    return 0;
}
