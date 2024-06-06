#include <iostream>
#include <vector>
using namespace std;

struct aresta {//estrutura armazenar os vertices das arestas
    int primeiroVertice;
    int segundoVertice;
};
/*
struct valorVertice {//estrutura para fazer grafos com valores de vertices nao ordenado
    int posiçaoVertice;
    int ValorVertice;
};
*/
class grafo {
public:
    int V;
    vector<aresta> arestas;
    vector<int> vertices;

    grafo(int vertices) : V(vertices) {}

    void addVertice(int u) {
        vertices.push_back(u);
    }

    void addAresta(int A, int B) {
        arestas.push_back({A, B});
    }

    void imprimirMatriz() {
        vector<vector<int>> matriz(V, vector<int>(V, 0));

        for (const aresta& a : arestas) {
            int u = a.primeiroVertice - 1; 
            int v = a.segundoVertice - 1;
            matriz[u][v] = matriz[v][u] = 1;
        }

        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << matriz[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    bool saoVizinhos(int A, int B) {
        for (const aresta& i : arestas) {
            if ((i.primeiroVertice == A && i.segundoVertice == B) ||
                (i.primeiroVertice == B && i.segundoVertice == A)) {
                return true;
            }
        }
        return false; 
    }


    vector<int> listarVizinhos(int u) {
        vector<int> vizinhosDeU; 

        for (const aresta& i : arestas) {
            if (i.primeiroVertice == u) {
                vizinhosDeU.push_back(i.segundoVertice);
            } else if (i.segundoVertice == u) {
                vizinhosDeU.push_back(i.primeiroVertice);
            }
        }

        return vizinhosDeU;
    }
};



int main() {
       grafo g(5);
    for (int i = 1; i <= 5; ++i) {
        g.addVertice(i);
    };

    g.addAresta(1, 2);
    g.addAresta(1, 5);
    g.addAresta(2, 5);
    g.addAresta(3, 2);
    g.addAresta(3, 4);
    g.addAresta(4, 2);
    g.addAresta(4, 5);

    cout << "Vertices 3 e 5 sao vizinhos? " << (g.saoVizinhos(3, 5) ? "Sim" : "Nao") << endl;


    g.imprimirMatriz();

   vector<int> vizinhosDe3 = g.listarVizinhos(3);
    cout << "Vizinhos do vertice 3: ";
    for (int vizinho : vizinhosDe3) {
        cout << vizinho << ' ';
    }
    cout << endl;

return 0;

}