/*
	José Luis Gallegos Cárdenas
	ACM-ICPC Gran Premio
	Problema: D - DPA01

	Explicación:
		Encontrar qué números son perfectos, deficientes o abundantes para un rango de 1 a 10^3
		Sólo es hacer un DP o usar la fórmula de Dirichlet
		La fórmula es útil para el M.
*/


#include <bits/stdc++.h>

#define MAXT 500
#define MAXN 1000

int *dp;//DP para los valores

int main(){
	int t, n, sum = 0;
	dp = new int[MAXN+1];//Inicializamos el dp
	for(int i = 2; i <= MAXN; ++i){
		for(int j = 1; j <= ceil(i/2); ++j){
			if( i % j == 0) sum+=j;//Hacemos la suma de cada valor (fuerza bruta, hay una fórmula mejor para el m)
		}
		if( sum == i ) dp[i] = 0; //0 es perfect
		else if( sum < i ) dp[i] = -1; // -1 es deficient
		else if( sum > i) dp[i] = 1; // 1 es abundant
		sum = 0;// reiniciamos la suma
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d", &n);
		//Accedemos al DP y listo.
		if( dp[n] == -1 ) printf("deficient\n");
		else if( dp[n] == 0 ) printf("perfect\n");
		else if( dp[n] == 1 ) printf("abundant\n");
	}
	return 0;
}
