/**************************************************************************
** Interface      : obtem_data_corrente
**
** Nome Arquivo   : obtem_data_corrente.cpp
**
** Sintaxe        : obtem_data_corrente 
**
** Descricao      : Programa que retorna a data corrente em diferentes formatos
***************************************************************************/

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

#define YMDHMS   1
#define YMD_HMS  2
#define YMD      3
#define YM       4
#define DM       5
#define DMYHMScs 6
#define DMYcs    7
#define HMScs    8

void fFormDtCorrente(char *pszDtHr, int format) 
{
    time_t timer;
    struct tm *tblock;

    timer = time(NULL);
    tblock = localtime(&timer);
    switch (format ) 
    {
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

       case YM:
           sprintf (pszDtHr, "%04d%02d", 
                    tblock->tm_year+1900, 
                    tblock->tm_mon+1);
           break;

       case DM:
           sprintf (pszDtHr, "%02d%02d", 
                    tblock->tm_mday, 
                    tblock->tm_mon+1);
           break;

       case DMYHMScs:
           sprintf (pszDtHr, "%02d/%02d/%d %02d:%02d:%02d",
                    tblock->tm_mday, 
                    tblock->tm_mon+1, 
                    tblock->tm_year+1900,
                    tblock->tm_hour, 
                    tblock->tm_min, 
                    tblock->tm_sec);
           break;

       case DMYcs:
           sprintf (pszDtHr, "%02d/%02d/%d",
                    tblock->tm_mday, 
                    tblock->tm_mon+1, 
                    tblock->tm_year+1900);
           break;

       case HMScs:
           sprintf (pszDtHr, "%02d:%02d:%02d",
                    tblock->tm_hour, 
                    tblock->tm_min, 
                    tblock->tm_sec);
           break;
           
    }/*switch*/
}/* fFormDtCorrente() */

int main(void)
{    
    char psDtAtual[20];     
    
    fFormDtCorrente(psDtAtual, YMD); 
    
    printf("Data atual: [%s]\n", psDtAtual);

    return 0;
}
