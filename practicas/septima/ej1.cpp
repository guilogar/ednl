#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

#ifndef EJ1
#define EJ1

template <typename tCoste>
vector<tCoste> DijkstraInvOpuesto(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice destino,
                           vector<typename GrafoP<tCoste>::vertice>& P)
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   vertice v, w;
   const size_t n = G.numVert();
   vector<bool> S(n, false);                  // Conjunto de vértices vacío.
   vector<tCoste> D;                          // Costes mínimos hasta destino.
   
   // Iniciar D y P con caminos directos hasta el vértice destino.
   D = vector<tCoste> (n, -GrafoP<tCoste>::INFINITO);
   D[destino] = 0;                             // Coste destino-destino es 0.
   P = vector<vertice>(n, destino);
   
   // Calcular caminos de coste mínimo desde cada vértice.
   S[destino] = true;                          // Incluir vértice destino en S.
   
   for (size_t i = 1; i <= n-2; i++) {
      // Seleccionar vértice w no incluido en S
      // con menor coste hasta destino.
      
      tCoste costeMax = -GrafoP<tCoste>::INFINITO;
      for (v = 0; v < n; v++) {
          if (!S[v] && D[v] >= costeMax) {
             costeMax = D[v];
             w = v;
          }
      }
      S[w] = true;                          // Incluir vértice w en S.
      
      // Recalcular coste hasta cada v no incluido en S a través de w.
      for (v = 0; v < n; v++) {
          if (!S[v]) {
             tCoste Dwv;
             if(D[w] != -GrafoP<tCoste>::INFINITO) Dwv = suma(G[v][w], D[w]);
             else Dwv = G[v][destino];
             
             if (Dwv >= D[v] && Dwv != GrafoP<tCoste>::INFINITO) {
                D[v] = Dwv;
                P[v] = (D[w] != GrafoP<tCoste>::INFINITO) ? w : v;
             }
          }
      }
   }
   for (size_t i = 0; i < n; i++) {
       if(D[i] == -GrafoP<tCoste>::INFINITO) D[i] = -D[i];
   }
   return D;
}

template <typename tCoste> vector<tCoste> DijkstraOpuesto(const GrafoP<tCoste>& G,
                                    typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P)
// Calcula los caminos de coste mínimo entre origen y todos los
// vértices del grafo G. En el vector D de tamaño G.numVert()
// devuelve estos costes mínimos y P es un vector de tamaño
// G.numVert() tal que P[i] es el último vértice del camino
// de origen a i.
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   vertice v, w;
   const size_t n = G.numVert();
   vector<bool> S(n, false);                  // Conjunto de vértices vacío.
   vector<tCoste> D;                          // Costes mínimos desde origen.
    
   // Iniciar D y P con caminos directos desde el vértice origen.
   D = G[origen];
   D[origen] = 0;                             // Coste origen-origen es 0.
   P = vector<vertice>(n, origen);
    
   // Calcular caminos de coste mínimo hasta cada vértice.
   S[origen] = true;                          // Incluir vértice origen en S.
   for (size_t i = 1; i <= n-2; i++) {
      // Seleccionar vértice w no incluido en S
      // con menor coste desde origen.
      tCoste costeMax = -GrafoP<tCoste>::INFINITO;
      for (v = 0; v < n; v++)
         if (!S[v] && D[v] >= costeMax && D[v] != GrafoP<tCoste>::INFINITO) {
            costeMax = D[v];
            w = v;
         }
      S[w] = true;                          // Incluir vértice w en S.
      // Recalcular coste hasta cada v no incluido en S a través de w.
      for (v = 0; v < n; v++)
         if (!S[v]) {
            tCoste Owv = suma(D[w], G[w][v]);
            if (Owv >= D[v] && Owv != GrafoP<tCoste>::INFINITO) {
               D[v] = Owv;
               P[v] = w;
            }
         }
   }
   return D;
}

#endif
