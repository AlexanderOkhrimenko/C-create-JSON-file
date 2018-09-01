//  main.c
//  tojson
//
//  Created by Xander on 23.07.2018.
//  Copyright © 2018 Xander. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * createJSON (char* , char*, char* , char*, char* , char*, char* , char*) ;
int readProgressFile (void);

struct jsonData
{
    char *name;
    char *format;
    char *duration;
    char *bitrate;
    char *progress;
    char *name_ok;
    char *format_ok;
    char *duration_ok;
    
} jd;



int main(int argc, const char * argv[]) {
    
    jd.name = "Mark OH";
    jd.format = "wav";
    jd.duration = "00:10:20";
    jd.bitrate = "320";
    jd.progress = "30";
    jd.name_ok = "OKK";
    jd.format_ok = "OKK";
    jd.duration_ok = "OKK";
    
    
    while (1) {
        readProgressFile();
        //createJSON(jd.name, jd.format, jd.duration, jd.bitrate, jd.progress, jd.name_ok, jd.format_ok, jd.duration_ok);
    }

    return 0;
} //--------------------- main ----------------------------

// Функция создает строку JSON из переданных параметров.
char * createJSON (char* jname ,char* jformat, char* jduration, char* jbitrate, char* jprogress, char* jname_ok, char* jformat_ok , char* jduration_ok) {
    
    FILE *file;
    
    if ((file=fopen("3.json", "w"))==NULL)
        
    {
        printf("File error\n");
        //return 1;
    }

    int string_length = 256;
    
    char *name = (char*) malloc(string_length);// финальная строка JSON
    
    int i;
    for (i=0; i<string_length; i++) {  // очистка памяти
        name[i] = 0;
    }
    strcat(name, "{\n ");
    
    strcat(name, "\"name\": \"");
    strcat(name, jname);
    strcat(name, "\",\n");
    
    strcat(name, "\"format\": \"");
    strcat(name, jformat);
    strcat(name, "\",\n");
    
    strcat(name, "\"duration\": \"");
    strcat(name, jduration);
    strcat(name, "\",\n");
    
    strcat(name, "\"bitrate\": \"");
    strcat(name, jbitrate);
    strcat(name, "\",\n");
    
    strcat(name, "\"progress\": \"");
    strcat(name, jprogress);
    strcat(name, "\",\n");
    
    strcat(name, "\"name_ok\": \"");
    strcat(name, jname_ok);
    strcat(name, "\",\n");
    
    strcat(name, "\"format_ok\": \"");
    strcat(name, jformat_ok);
    strcat(name, "\",\n");
    
    strcat(name, "\"duration_ok\": \"");
    strcat(name, jduration_ok);
    strcat(name, "\"\n");
    
    strcat(name, "}\n");

    fputs(name, file);
    fclose(file);
    free(name);
    
    return name;
    
}

int readProgressFile (void)
{
    int string_length = 256;
    
    char *st = (char*) malloc(string_length);// финальная строка JSON
    //char *tt = (char*) malloc(string_length);// строка времени;
    
    int i;
    char buffer[16];
    for (i=0; i<string_length; i++) {  // очистка памяти
        st[i] = 0;
    }
    
    FILE *file;
    
    if ((file=fopen("block.txt", "r"))==NULL)
    {
        printf("File error\n");
        // return 1;
    }
    
    while (!feof(file)) {
        fgets(st, 100, file);

        fscanf(file, "%s", st);
        if (strstr(st, "out_time_ms=") != NULL)   {
           // if (strstr(st, "progress=end") == 1) break ;
    
            //printf(" tt len= %d\n", strlen(tt));
            memmove(st, st+12, 10); // отсекли "out_time_ms="
            strcat(st, "\0"); // допольнили цифры знаком окончания строки
            i = atoi(st);     // преобразование из строки в число
            printf("%d\n", i);
            sprintf(buffer, "%d" , i);  // преобразование числа в строку
            
            createJSON(jd.name, jd.format, jd.duration, jd.bitrate, buffer, jd.name_ok, jd.format_ok, jd.duration_ok); // запись progress в файл
            system("sleep 1");
        }
        
       // puts(tt);
    }
    
    fclose(file);
    free(st);
    
    return 0;
}
