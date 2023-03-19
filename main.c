#include<stdio.h>
#include<stdlib.h>
long file_size(FILE* file );
char* file_contents(char* path);
void print_usage(char** argv );

long file_size(FILE* file ){
    fpos_t pos ;
    long size;
    if(fgetpos(file,&pos)!=0){
        fprintf(stderr,"Could not determine positon in file");
        exit(1);
    }
    fseek(file, 0L, SEEK_END);
    size=ftell(file);
    if(fsetpos(file,&pos)!=0){
        fprintf(stderr, "Could not set file postion");
        exit(1);
    }
    return size;
}
char* file_contents(char* path){
    FILE* file =fopen(path,"r");
    if(!file){
        printf("Unable to open file at: %s ", path);
        exit(1);
    }
    long size= file_size(file);
}

void print_usage(char** argv ){
    printf("Usage: %s <path_to_file_to_compile>\n", argv[0]);
}
int main (int argc, char** argv){
    long size;
    FILE* file= fopen(argv[1],"r");
    if (argc<2){
        print_usage(argv);
        exit(0);
    }
    size= file_size(file);
    fclose(file);
    printf("%ld", size);
}
