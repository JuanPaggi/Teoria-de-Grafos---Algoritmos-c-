#ifndef ALGORITMOSVARIOS_H
#define ALGORITMOSVARIOS_H

#include "Grafo.h"
#include "Recorridos.h"

class AlgoritmosVarios
{
    public:
        AlgoritmosVarios();
        ~AlgoritmosVarios();

        void longitudCaminos(Grafo &, int);
        void mostrarLongitudes();

        void bosque_topSort(Grafo &);
        void mostrarOrdenamiento();

        bool hayCiclo(Grafo &);

        void caminosMinimos_Vertice(Grafo &, int);

    private:
        int * estado, * descubierto, *padre, *distancia;
        list<int> vertices;
        int time, n;
        bool * visitados;

        void inicializar(Grafo & g)
        {
            vertices.clear();
            n = g.size();
            time = 0;
            estado = new int[n+1];
            descubierto = new int [n+1];
            for(int i = 1; i <= n; i++)
            {
                estado[i] = NO_VISITADO;
                descubierto[i] = -1;
            }
        }

        void caminos_dfs(Grafo & g, int u)
        {
        estado[u] = DESCUBIERTO;
        descubierto[u] = time;
        time++;
        list<Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
        {
            int v = it->devolverAdyacente();
            if(estado[v] == NO_VISITADO)
            {
                caminos_dfs(g, v);
            }
        }
        estado[u] = VISITADO;
        --time;
        }

        void topSort(Grafo & g, int u)
        {
            visitados[u] = true;
            list<Arco> adyacentes = g.devolverAdyacentes(u);
            for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
            {
                int v = it->devolverAdyacente();
                if(!visitados[v])
                {
                    topSort(g, v);
                }

            }
            vertices.push_front(u);
        }
};

#endif // ALGORITMOSVARIOS_H
