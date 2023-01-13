#include<stdio.h>
#include<string.h>

int count=0 , option =0 , len;
char str[101];
char word[101];

void createData(){
    label1:
        printf("Input: ");
        scanf("%[^\n]",str);getchar();
        len = strlen(str);

        for(int i=0;i<len;i++){
            if(str[i]==' '){
                count+=1;
            }
        }

        if(count < 4 || count > 9){
            printf("kata harus diantara 5 dan 10\n");
            goto label1;
        }
        else{
            char strnew[101];
        strcpy(strnew,str);
        char * token = strtok(str, " ");
        printf( "%s\n", token ); //printing the token
        strncat(token, ".txt", 4);

        FILE *ptr;
        ptr = fopen(token, "a+");
         fprintf(ptr,"%s",strnew);
        if(ptr == NULL){
            printf("File telah dibuat!\nSilakan masukkan nama lain!\n");
        }
        else 
        {
            printf("File anda selesai dibuat\n");
        }
            fclose(ptr);
        }

        FILE *ptr;
        ptr = fopen("core.txt", "a+");
        fprintf(ptr, "%s\n",str);
        fclose(ptr);
    }


void checkFile(){
    FILE *ptr;
    char buf[100];
    int count = 0;

    ptr = fopen("core.txt", "r");

    while( fscanf(ptr, "%s", buf) != EOF )
		{
            count+=1;
		}
    printf("Existing file: %d\n",count);

    fclose(ptr);
    if(count >= 7){
        puts("\nFILE HAS ALREADY MAX") ;
    }
    else{
        createData();
    }
	fclose(ptr);
}

void searchData(char word[]){
    FILE *ptr;
    ptr = fopen("core.txt", "r");
    char buf[100];
    char buf2[100];

		while( fscanf(ptr, "%s", buf) != EOF )
		{
            FILE *ptr2;
            ptr2 = fopen(buf, "r");
            while( fscanf(ptr2, "%s", buf2) != EOF ){
                if(strcmp(buf2,word) == 0){
                    printf("the word [%s] exist in file [%s]\n",word,buf);
                }
		    }
            fclose(ptr2);
		}
	fclose(ptr);
}

int main(){
    printf("\n*****\tSELAMAT DATANG DI GUGEL BANTENG MERAH\t*****\n");
    printf("1. Insert Data (Max. 7 Files)\n2. Searching Data\n> ");
    scanf("%d",&option);getchar();

    if(option == 1){
        checkFile();
    }

    if(option == 2){
        printf("Search word (sensitive case): ");
        scanf("%s",word);getchar();
        searchData(word);
    }

    return 0;
}