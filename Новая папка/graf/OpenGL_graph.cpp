#include "Graph.h"

int GraphClass::num_vertices = 0;
vector<int> GraphClass::vertex_list_static;
vector<vector<int>> GraphClass::adjacency_matrix_static;

int main() {
    setlocale(LC_ALL, "RU");

    int amount_vertex, amount_edges, vertex, start_vertex, end_vertex, edge_weight;

    cout << "Введите количество вершин графа: ";
    cin >> amount_vertex;
    cout << "Введите количество рёбер графа: ";
    cin >> amount_edges;
    cout << endl;

    GraphClass graph = { 10 };

    for (int i = 0; i < amount_vertex; i++) {
        cout << "Значение вершины: ";
        cin >> vertex;

        graph.insert_vertex(vertex);
    }

    for (int i = 0; i < amount_edges; i++) {
        cout << "\nИсходная вершина: ";
        cin >> start_vertex;
        cout << "Конечная вершина: ";
        cin >> end_vertex;
        cout << "Вес ребра: ";
        cin >> edge_weight;
        cout << endl;

        graph.insert_edge(start_vertex, end_vertex, edge_weight);
    }

    graph.print();

    int A;
    int B;

    cout << "\nВведите какая вершина будет точкой А: ";
    cin >> A;
    cout << "Введите какая вершина будет точкой B: ";
    cin >> B;
    cout << "\n";

    graph.shortest_path(A, B);

    // Visualize the graph
    graph.visualize_graph();

    return 0;
}

/*  
    bool* visited_verts = new bool[20];
    fill(visited_verts, visited_verts + 20, false);

    cout << "\nВведите вершину, с которой начать обход: ";
    cin >> vertex; cout << endl;
    cout << "Обход в глубину:\n";
    graph.DFS(vertex, visited_verts);

    cout << "\nВведите вершину, с которой начать обход в ширину: ";
    cin >> vertex;
    cout << endl;
    fill(visited_verts, visited_verts + 20, false);
    cout << "Обход в ширину:\n";
    graph.BFS(vertex, visited_verts); 

    delete[] visited_verts;
*/

