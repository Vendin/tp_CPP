#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void vive(int n,int *i){
    int w;
    for(w=n-1;w!=-1;w--){
    if(i[w]>9){
        printf("%c",(char)(i[w]+55));
          }
    else{
        printf("%i",i[w]);
        }
    }
        }
void ten_in_q(int q,int s){
    int *si=malloc(sizeof(int)*14);
    int de=s,i;
    for(i=0;de!=0;i++){
        
        si[i]=de%q;
        de/=q;
        }   
        vive(i,si);
        free(si);
    }
int q_in_ten(int p,char *s){
    int se=0,i;
    for(i=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9'){
        se+=(((int)s[i])-48)*pow(p,(strlen(s)-1-i));
        }
        if(s[i]>='A' && s[i]<='Z'){
            se+=(((int)s[i])-55)*pow(p,(strlen(s)-1-i));
        }
        if(s[i]>='a' && s[i]<='z'){
            se+=(((int)s[i])-87)*pow(p,(strlen(s)-1-i));
        }
      }
    return se;
        }
int check(int P,int Q,char *S){
    if(strlen(S)==1 && S[0]=='0'){
    	printf("0");
    	free(S);
    	return 1;
    	}
    if((P>=2 && P<=36)==0){
    free(S);
        printf("error");
        return 1;
    }
    if((Q>=2 && Q<=36)==0){
        printf("error");
        free(S);
        return 1;
    }
    int j;
    for(j=0;j<strlen(S);j++){
        if(((S[j]>='0' && S[j]<='0'+(P>=10?9:P-1))||(P>10?(S[j]>='A' && S[j]<'A'+P-10):0)||(P>10?(S[j]>='a' && S[j]<'a'+P-10):0))==0){
            printf("error");
            free(S);
            return 1;
        }
        }
        return 0;
}

int main(){
    int P,Q;
    char *S;
    S=malloc(sizeof(char)*10);
    scanf("%i %i %s",&P,&Q,S);
    if(check(P,Q,S)==0){
    ten_in_q(Q,q_in_ten(P,S));
       free(S);
    }
    return 0;
}
