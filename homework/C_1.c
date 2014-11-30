#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void vive(int *stroka, int razmer) {
    int w;
    for (w = razmer - 1; w != -1; w--) {
        if (stroka[w] > 9) {
            printf("%c", (char)(stroka[w] + 55));
        } else {
            printf("%i", stroka[w]);
        }
    }
}

void ten_in_q(int basis, int number) {
    int *si = malloc(sizeof(int));
    if (si != NULL) {
    int de = number, i;
    for (i = 0; de != 0; i++) {
        si = realloc(si, (i+1)*sizeof(int));           
        *(si + i) = de % basis;
        de /= basis;
    }
    vive(si,i); 
    free(si);
  }
}

int q_in_ten(char *number,int basis) {
    int se = 0, i;                  
    for (i = 0; i < strlen(number); i++) {{
        if (number[i] >= '0' && number[i] <= '9') 
            se += (((int)number[i]) - 48) * pow(basis, (strlen(number) - 1 - i));
        }
        if (number[i] >= 'A' && number[i] <= 'Z') {
            se += (((int)number[i]) - 55) * pow(basis, (strlen(number) - 1 - i));
        }
        if (number[i] >= 'a' && number[i] <= 'z') {
            se += (((int)number[i])-87) * pow(basis, (strlen(number) - 1 - i));
        }
    }
    return se; 
}

int check(int basis_start, int basis_end, char *number) { 
    if (strlen(number) == 1 && number[0] == '0') {
        printf("0");
        free(number);
        return 1;
    }
    if ((basis_start >= 2 && basis_start <= 36) == 0) {
        free(number);
        printf("[error]");
        return 1;
    }
    if ((basis_end >= 2 && basis_end <= 36) == 0) {
        printf("[error]");
        free(number);
        return 1;
    }
    int j;

   for (j = 0; j < strlen(number); j++) {
        if ((number[j] >= '0' && (number[j] <= '0' + (basis_start >= 10 ? 9 : basis_start-1)|| (basis_start > 10 ? (number[j] >= 'A' && number[j] < 'A' + basis_start - 10) : 0) || (basis_start > 10 ? (number[j] >= 'a' && number[j] < 'a' + basis_start - 10) : 0))) == 0 ) {
            printf("[error]");
            free(number);
            return 1;
        }
    }
    return 0;
}

int main() {
    int P, Q, i = 0;
    char *S = (char*)malloc(sizeof(char));
    if(S != NULL){
      if( scanf("%i %i", &P, &Q) == 2 ){
        char lol;
        do {
         lol = getchar();
         if (isdigit(lol)) {
           i++;
           S = realloc(S, i);
           *(S+i-1) = lol;
          }
        } while(lol != '\n'); 
         
        if ( check(P, Q, S) == 0 ) {
              ten_in_q(Q, q_in_ten(S, P));
              free(S);
        }
    }
  }
    return 0;
}
