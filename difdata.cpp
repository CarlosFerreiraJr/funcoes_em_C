/**************************************************************************
** Interface      : difdata
**
** Nome Arquivo   : difdata.cpp
**
** Sintaxe        : difdata 
**
** Descricao      : Programa que retorna difrança entre duas datas
*****************************************************************************************************/

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

/**************************************************************************
** Funcao          : fDiferencaHr()
**
** Descricao       : Retorna a diferenca entre duas DataHoras
** Parametros      : char *pszDtHrFim - ponteiro para o array com hora final
**                   char *pszDtHrIni - ponteiro para o array com hora inicial
**                   int format - formato desejado
** Valores Retorno : char *
** Outras Observ.  : formato:
**                    0    HHhor MMmin SSseg
**                    1    DDHHMMSS
** ---------------------------------------------------------------------------
**   11/10/2014 : Autor   : Carlos Ferreira  
**                Versao inicial        
******************************************************************************/
char* fDiferencaHr(char *pszDtHrFim, char *pszDtHrIni, int format) 
{
   struct tm sdDtHrIni, sdDtHrFim;     /* DtHr no formato tm */
   time_t tdDtHrIni, tdDtHrFim;        /* DtHr no formato time_t */
   long lSecDif;                       /* Diferenca entre DtHrs */
   static char Buffer[64];
   
   strcpy(Buffer, pszDtHrIni);
   sdDtHrIni.tm_sec  = atoi(Buffer+17);     Buffer[16] = '\0';
   sdDtHrIni.tm_min  = atoi(Buffer+14);     Buffer[13] = '\0';
   sdDtHrIni.tm_hour = atoi(Buffer+11);     Buffer[10] = '\0';
   sdDtHrIni.tm_year = atoi(Buffer+6 )-1900;Buffer[5 ] = '\0';
   sdDtHrIni.tm_mon  = atoi(Buffer+3 )-1;   Buffer[2 ] = '\0';
   sdDtHrIni.tm_mday = atoi(Buffer   );     
   sdDtHrIni.tm_isdst = -1;

   strcpy(Buffer, pszDtHrFim);
   sdDtHrFim.tm_sec  = atoi(Buffer+17);     Buffer[16] = '\0'; 
   sdDtHrFim.tm_min  = atoi(Buffer+14);     Buffer[13] = '\0'; 
   sdDtHrFim.tm_hour = atoi(Buffer+11);     Buffer[10] = '\0'; 
   sdDtHrFim.tm_year = atoi(Buffer+6 )-1900;Buffer[5 ] = '\0'; 
   sdDtHrFim.tm_mon  = atoi(Buffer+3 )-1;   Buffer[2 ] = '\0'; 
   sdDtHrFim.tm_mday = atoi(Buffer   );                        
   sdDtHrFim.tm_isdst = -1;                                    

   tdDtHrIni = mktime(&sdDtHrIni);
   tdDtHrFim = mktime(&sdDtHrFim);
   lSecDif = (long)difftime(tdDtHrFim, tdDtHrIni);

   if(format == 0)
   {
    snprintf(Buffer, sizeof(Buffer), "%02ld horas %02ld min %02ld seg",
         (lSecDif / 3600),
         (lSecDif / 60) % 60,
         lSecDif % 60);
   }
   else
   {
      snprintf(Buffer, sizeof(Buffer), "%02ld dias %02ld horas %02ld min %02ld seg",
         (lSecDif / 86400),
         (lSecDif / 3600) % 24,
         (lSecDif / 60) % 60,
         lSecDif % 60);
   }
   
   return Buffer;

}/* fDiferencaHr() */

int main(void)
{
    char* data_hora = NULL;
    char pszDtHrFim[20]; 
    char pszDtHrIni[20];
    int format;

    strcpy(pszDtHrFim, "21/08/2026 10:50:28");
    strcpy(pszDtHrIni, "02/08/2026 11:50:28");
    format = 1;

    data_hora = fDiferencaHr(pszDtHrFim, pszDtHrIni, format); 
    
    printf("Diferenca entre as datas: [%s]", data_hora);

    return 0;
}
