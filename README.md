# programas_em_C
Programas e Funções em C

<br>#função para remover espaçoes a direita de uma cadeia variável caracter
<br>
<br>void rtrim(char *string) 
<br>{
<br>    int i;
<br>    for(i=strlen(string)-1;string[i]==' '&&i>=0;string[i--]='\0');
<br>}
