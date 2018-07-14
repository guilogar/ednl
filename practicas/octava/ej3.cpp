#include <cassert>
#include <vector>           // para Dijkstra
#include "../grafos/grafoPMC.h"       // grafo ponderado
#include "../grafos/matriz.h"         // para Floyd
#include "../grafos/apo.h"            // para Prim y Kruskall
#include "../grafos/particion.h"      // para Kruskall

template <typename tCoste>
GrafoP<tCoste> KruskallMaximo(const GrafoP<tCoste>& G)
// Devuelve un árbol generador de coste maximo
// de un grafo no dirigido ponderado y conexo G.
{
   assert(!G.esDirigido());

   typedef typename GrafoP<tCoste>::vertice vertice;
   typedef typename GrafoP<tCoste>::arista arista;
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
   const size_t n = G.numVert();
   GrafoP<tCoste> g(n);   // Árbol generador de coste mínimo.
   Particion P(n);   // Partición inicial del conjunto de vértices de G.
   Apo<arista> A(n*n);    // Aristas de G ordenadas por costes.

   // Copiar aristas del grafo G en el APO A.
   for (vertice u = 0; u < n; u++)
      for (vertice v = u+1; v < n; v++)
         if (G[u][v] != INFINITO)
            A.insertar(arista(u, v, -G[u][v]));

   size_t i = 1;
   while (i <= n-1 && !A.vacio()) {   // Seleccionar n-1 aristas y !A.vacio() por si acaso pasa un grafo no conexo
      arista a = A.cima(); // arista de menor coste
      A.suprimir();
      vertice u = P.encontrar(a.orig);
      vertice v = P.encontrar(a.dest);
      if (u != v) { // Los extremos de a pertenecen a componentes distintas
         P.unir(u, v);
         // Incluir la arista a en el árbol g
         g[a.orig][a.dest] = g[a.dest][a.orig] = -a.coste;
         i++;
      }
   }
   return g;
}
