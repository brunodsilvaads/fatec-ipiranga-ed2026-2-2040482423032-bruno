#include <stdio.h>

#define TAMANHO_TURMA 5

// Constante simbólica,evita que o número 5 se espalhe pelo código
// Se o número da turma mudar de tamanho, só ajuste por aqui

void exibirCabecalho(void) {
printf("=================================\n");
printf(" SISTEMA DE NOTAS - TURMA ADS     \n");
printf("=================================\n");

}

void preencherNotas(float notas[], int tamanho){
int i;

// Laço "for", não recursivo: usa memória constante e é 
// uma forma direta de percorrer um vetor com índice e inicio e fim definidos.
// uma das formas mais comuns de percorrer um vetor em C, junto com o "while" e o "do while".
for(i = 0; i<tamanho; i++){
printf("Nota do aluno %d: ",i +1);
scanf ("%f", &notas[i]);

}

}

// Mesmo sem "*" na assinatura, o vetor é passado por referência: 
// em C, um array vira automaticamente um ponteiro para seu primeiro
// elemento ao ser passado como parâmetro ("array decay").

float calcularMedia(float vetor[], int tamanho){
int i;
float soma = 0.0;
for (i = 0; i<tamanho; i++){
soma += vetor[i];

}
return soma/tamanho;

}


//As alterações feitas na função simularAjuste não afetam a variável notaOriginal do main, pois ela é passada por valor.

void simularAjuste(float notaOriginal, float bonus){
float resultado = notaOriginal + bonus;

printf("Simulacao para o aluno 1: %.2f + %.2f = %.2f (nao aplicado ainda)\n",
           notaOriginal, bonus, resultado);

}

// Passagem por ponteiro: nota guarda o endereço de
// notas[i]. *nota acessa e altera o valor diretamente
// nesse endereço, então a mudança persiste depois que a função retorna.

void aplicarBonus(float *nota, float bonus){
    *nota = *nota + bonus;
}

void exibirNotas(float notas[], int tamanho){
int i;
//Laço "for", já usado antes no código.
for(i = 0; i<tamanho; i++){
printf("Aluno %d: %.2f\n", i+1, notas[i]);
}
}

int main(void){
float notas[TAMANHO_TURMA];
float bonus = 0.0;
int i=0;

exibirCabecalho();
preencherNotas(notas, TAMANHO_TURMA);
printf("Informe o valor do bonus a aplicar: ");
scanf ("%f", &bonus);
printf("\n--- Media da turma antes do ajuste ---\n");
printf("Media inicial: %.2f\n", calcularMedia(notas, TAMANHO_TURMA));



printf("\n--- Simulacao do ajuste (passagem por valor) ---\n");
simularAjuste(notas[0], bonus);
printf("Nota do aluno 1 apos a simulacao (inalterada): %.2f\n", notas[0]);

printf("\n--- Aplicacao real do bonus (passagem por referencia) ---\n");
for (i=0; i<TAMANHO_TURMA; i++){
    aplicarBonus(&notas[i],bonus);
}
printf("Bonus de %.2f aplicado a todas as notas da turma.\n",bonus);
printf("\n--- Notas finais da turma ---\n");
exibirNotas(notas, TAMANHO_TURMA);
printf("\n--- Media da turma apos o ajuste ---\n");
printf("Media final: %.2f\n", calcularMedia(notas, TAMANHO_TURMA)); 

return 0;
}

