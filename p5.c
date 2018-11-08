/* p5.c */
/* Gabriel Cardoso Mendes de Ataide */
/* 11811ECP008 */
#include <stdio.h>
typedef
  unsigned long long int
Bytes8;
typedef
  struct LCG {Bytes8 a, c, m, rand_max, atual; }
LCG;

void semente(LCG * r, Bytes8 seed) {
  r->a = 0x5DEECE66DULL;
  r->c = 11ULL;
  r->m = (1ULL << 48);
  r->rand_max = r->m - 1;
  r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) {
  r->atual = (r->a * r->atual + r->c) % r->m;
  return r->atual;
}

double lcg_rand_01(LCG * r) {
  return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r){
  int i;
  for(i = 0; i < tam; i++){
    vetor[i] = (max-min) * lcg_rand_01(r) + min;
  }
}

float somatorio(float vet[], int n, float result){
  if(n<0){
    return result;
  }else{
    result+=vet[n];
    return somatorio(vet, n-1, result);
  }
}

float produtorio(float vet[], int n, float result){
  if(n<0){
    return result;
  }else{
    result*=vet[n];
    return produtorio(vet, n-1, result);
  }
}

int main(){
  LCG random;
  int qt = 50;
  semente(&random,123456);
  float vetor[50];
  int i;
  gera_numeros(vetor, 50, 0.5, 1.5, &random);
  scanf("%i",&i);getchar();
  printf("%f\n",(i==1)?somatorio(vetor,qt-1,0):produtorio(vetor,qt-1,1));
  return 0;
}
