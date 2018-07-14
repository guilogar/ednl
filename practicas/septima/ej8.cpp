#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

template <typename tCoste> tCoste soloUnTransbordo(GrafoP<tCoste> tren, GrafoP<tCoste> autobus,
                                                           typename GrafoP<tCoste>::vertice origen,
                                                           typename GrafoP<tCoste>::vertice destino)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = tren.numVert();
    
    vertice ciudadTransbordo;
    tCoste tarifaMinima = GrafoP<tCoste>::INFINITO;
    
    for (size_t i = 0; i < n; i++) {
        vector<vertice> dijAutobus;
        vector<vertice> dijTren;
        vector<tCoste> autobusHastaTransbordo = DijkstraInv(autobus, i, dijAutobus);
        vector<tCoste> trenHastaTransbordo = DijkstraInv(tren, i, dijTren);
        vector<tCoste> autobusHastaFinal = Dijkstra(autobus, i, dijAutobus);
        vector<tCoste> trenHastaFinal = Dijkstra(tren, i, dijTren);
        tCoste tarifaMin = GrafoP<tCoste>::INFINITO;
        
        if(autobusHastaTransbordo[origen] > trenHastaTransbordo[origen]) {
            if(autobusHastaFinal[destino] > trenHastaFinal[destino]) {
                tarifaMin = suma(trenHastaTransbordo[origen], trenHastaFinal[destino]);
            } else {
                tarifaMin = suma(trenHastaTransbordo[origen], autobusHastaFinal[destino]);
            }
        } else {
            if(autobusHastaFinal[destino] > trenHastaFinal[destino]) {
                tarifaMin = suma(autobusHastaTransbordo[origen], trenHastaFinal[destino]);
            } else {
                tarifaMin = suma(autobusHastaTransbordo[origen], autobusHastaFinal[destino]);
            }
        }
        if(tarifaMin < tarifaMinima) tarifaMinima = tarifaMin;
    }
    return tarifaMinima;
}
