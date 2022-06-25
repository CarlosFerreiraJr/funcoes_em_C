### Retirar espaço de variáveis string

```
void rtrim(char *string)
{
    int i;
    for(i=strlen(string)-1;string[i]==' '&&i>=0;string[i--]='\0');
}
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
