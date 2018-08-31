//  main.c
//  C_M4
//  формирование JSON файла

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    FILE *file;
    char mystrin[1024] = " "; // финальная строка JSON
    
    char in[4]="{\n";   // начало JSON
    char out[4]="\n}";  // окончание JSON
    
    char name[256]="\"name\": \"";
    char nametext[128]="MaurkOH\", \n";
    strcat(name, nametext);
    
    char *format;
    char *duration;
    char *bitrate;
    char *progress;
    char *name_ok;
    char *format_ok;
    char *duration_ok;
    
    
    strcat(mystrin, in);
    strcat(mystrin, name);
    strcat(mystrin, out);
    
    
    if ((file=fopen("3.json", "w"))==NULL)
   
    {
        printf("File error\n");
        return 101;
    }
    
    //fprintf(file, "{ \n");
    fputs(mystrin, file);
    
    fclose(file);
    //puts(mystring);
    //printf(" = %s\n",mystring);  // вывод результата
    return 0;

        
        
    return 0;
}
