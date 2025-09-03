#include <stdio.h>
#define MAX 50000
int memo[MAX];

int achaMelhor(int receita[], int n){
    if(n==0){
        return 0;
    }
    if(memo[n]!=-1){
        return memo[n];
    }
    int maior=-1;
    for(int i=1;i<=n;i++){
        int atual = receita[i - 1] + achaMelhor(receita, n - i);
        if (atual > maior) {
            maior = atual;
        }
    }
    memo[n] = maior;
    return maior;
}

int main(){
	int receita[10] = {1,5,8,9,10,17,17,20,24,30};
    int n;
    printf("Tamanho de n: ");
    scanf("%d", &n);
    while(n<1 || n>10){
        printf("\nTamanho de n deve estar entre 1 e 10: ");
        scanf("%d", &n);
    }
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;//indica que o array que armazena resultados ainda não armazenou nada
    }
	printf("%d",achaMelhor(receita, n));
	return 0;
}