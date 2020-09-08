#include <stdio.h>
#include <string.h>

void rev(char i[]) {
    char a;
    int len = strlen(i);
    for (int k = 0; k < len/2; ++k) {
        a = i[k];
        i[k] = i[len-k-1];
        i[len-k-1]=a;

    }
}
int main(int argc, char **argv){
    if (argc == 1) return 0;

    FILE *f_in = fopen(argv[1],"r");
    FILE *f_out = fopen("output.txt","wt");

    char s1[128];
    fgets(s1, 126, f_in);
    //char s1[] = "    df     dfgdfg      df    asd    df     .       ";

    char *words[128];
    int i = 0;

    //using strtok()
    char *w = strtok(s1," .");
    while (w != NULL){
        words[i] = w;
        w = strtok(NULL, " .");
        printf("%s\n", s1);

        i++;
    }


    //own function by one selector
    char *a = s1;
    int isEmpty = 1;
    int len = strlen(s1);
    for (int k = 0; k < len; ++k) {

        if (*a != ' ' && *a != '.'){
            if (isEmpty){
                isEmpty = 0;
                words[i] = a;
            }
        } else if (!isEmpty){
            isEmpty = 1;
            i++;
            *a = '\0';
        }
        a++;
    }

    for (int j = 0; j < i; ++j) {
        if (strcmp(words[i-1], words[j])){
            fwrite(words[j], 1, strlen(words[j])+2, f_out);
            printf("%s ", words[j]);
            rev(words[j]);
            printf("%s ", words[j]);
            fwrite(words[j], 1, strlen(words[j])+2, f_out);

        }
    }
    fclose(f_in);
    fclose(f_out);
    return 0;
}


// Created by amano on 19.11.2019.
//

