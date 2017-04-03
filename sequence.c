/*
	José Luis Gallegos Cárdenas
	ACM-ICPC Gran Premio
	Problema: C - Secuencia

	Explicación:
		Problema de álgebra, sólo es tomar el último valor y el primero, racionalizar
		cada uno por separado y sumarlos. En base a eso surge una ecuación

			S = sqrt(n+1) - 1

		Por lo que aplicamos álgebra y nos queda:

			(S+1)^2 = n+1
			S^2 + 2*S + 1 = n+1
			S^2 + 2*S = n
			S*(S+2) = n

		Entonces sólo es usar el valor de S y ya.
*/

#include <math.h>
#include <stdio.h>

#define MAXN 1000000000

int main(){
	int t;
	long s;
	scanf("%d", &t);
	while(t--){
		scanf("%ld", &s);
		printf("%ld\n", (long) s*(s+2)); //Sólo es usar una fórmula
	}
	return 0;
}
