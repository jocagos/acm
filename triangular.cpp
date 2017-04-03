/*
    José Luis Gallegos Cárdenas
    ACM-ICPC Gran Premio Primera Fecha
    Problema: H - Triangular

    Explicación:
        Básicamente es notar que, si ordenas de 0 a n-1 los puntos, te da que los puntos
        donde n = k^2 para cualquier k entero, las coordenadas siguen un patrón.
        Luego, como son colineales (esto es, hay una línea que atraviesa ambos), pasar de
        uno a otro es fácil (sólo cambia el x), y para el otro, cambia el y también y es
        lo problemático. La fórmula es:

        f(n) = { si n = 0, devuelve (0,0) 
                de otro modo, devuelve (sqrt(n) + k1, -floor(sqrt(n)/2) + k2)}

        Las k se calculan dependiendo, de un cuadrado par a uno impar (ejemplo 4 a 9), k2 es 0
        pero en el otro caso, varía en el rango [-floor(sqrt(n)), floor(sqrt(n))]
        Y en cambio, k1 varía dado un delta que es la posición que nos piden. Delta es:

            delta = n - floor(sqrt(n))*floor(sqrt(n))

        Por lo que delta es entero, y sólo se suma o resta dependiendo la dirección.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000000

//Estructura pareja para las coordenadas
typedef struct{
    int a;
    int b;
}pair;

void f(long long n, pair *p){//Función que calcula el valor
    if( n == 0){
        p->a = p->b = 0;//Si es 0, devolvemos una pareja de (0,0), caso base
        return;
    }
    double s = sqrt(n);//Si no, raíz de n para cálculo sencillo
    double fl = floor(s);//piso de la raíz
    int delta = (int)(n-fl*fl);//Obtenemos delta
    if( delta == 0 ) // si es un cuadrado perfecto
    {
        p->a = (int) (n % 2 == 0 ? s : -s);//Dependiendo si es par o impar, será la "dirección"
        p->b = (int) -(floor(s/2)); // Este es invariante pues todos los cuadrados están debajo del eje X
    }
    else{ //En caso que no sea cuadrado perfecto
        if((int)(fl) % 2 == 0){ //Convertimos piso de la raíz y verificamos si es par o impar
            p->a = (int) fl - delta; // Retrocede la coordenada X
            p->b = (int) -(floor(fl/2)); //Y la coordenada Y es constante
        }
        else{ //Cuando es un punto impar
            p->a = -fl + delta; // Vamos avanzando la coordenada X
            if( delta > (int)fl) //De esto depende el valor en el rango
                delta -= 2*(delta - (int)fl); //Pequeña forma de hacer que el delta sea correcto siempre,
                                                //hay un pequeño caso porque el rango sube y baja por lo que
                                                //no puede mapearse directamente, así que esto lo resuelve.
            p->b = -(floor(fl/2)) + delta;//Avanza la coordenada Y o retrocede de forma acorde
        }
    }
}

int main(){
    int T;//Casos
    long long N;//Valor a recibir, long long lo aguanta bien
    scanf("%d", &T);
    pair *p = (pair*) malloc(sizeof(pair)); //Hacemos espacio para nuestra pareja
    while(T--){
        scanf("%ld", &N);
        f(N-1, p);// Mandamos N-1 porque contamos de 0 a n-1, para facilitar el cálculo
        printf("%d %d\n", p->a, p->b);// Imprimimos
    }
    return 0;
}