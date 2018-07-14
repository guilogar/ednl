#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/pilaenla.h"

template <typename tCoste>
matriz<tCoste> FloydModificado(const GrafoP<tCoste>& G,
                     matriz<typename GrafoP<tCoste>::vertice>& P)
// Calcula los caminos de coste mínimo entre cada
// par de vértices del grafo G. Devuelve una matriz
// de costes mínimos A de tamaño n x n, con n = G.numVert()
// y una matriz de vértices P de tamaño n x n, tal que
// P[i][j] es el vértice por el que pasa el camino de coste
// mínimo de i a j, si este vértice es i el camino es directo.
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   const size_t n = G.numVert();
   matriz<tCoste> A(n);   // matriz de costes mínimos

   // Iniciar A y P con caminos directos entre cada par de vértices.
   P = matriz<vertice>(n);
   for (vertice i = 0; i < n; i++) {
      A[i] = G[i];                    // copia costes del grafo
      //A[i][i] = 0;                    // diagonal a 0
      A[i][i] = GrafoP<tCoste>::INFINITO; // diagonal a INFINITO
      P[i] = vector<vertice>(n, i);   // caminos directos
   }
   // Calcular costes mínimos y caminos correspondientes
   // entre cualquier par de vértices i, j
   for (vertice k = 0; k < n; k++)
      for (vertice i = 0; i < n; i++)
         for (vertice j = 0; j < n; j++) {
            tCoste ikj = suma(A[i][k], A[k][j]);
            if (ikj < A[i][j]) {
               A[i][j] = ikj;
               P[i][j] = k;
            }
         }
   return A;
}

template <typename tCoste> bool grafoAciclico(const GrafoP<tCoste> G) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = G.numVert();
    matriz<vertice> m;
    
    matriz<tCoste> flo = FloydModificado(G, m);
    
    bool aciclico = true;
    
    for (size_t i = 0; i < n && aciclico; i++) {
        if(flo[i][i] != GrafoP<tCoste>::INFINITO)
            aciclico = false;
    }
    return aciclico;
}
