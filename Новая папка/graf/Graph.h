#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <string>
#include <string.h>

using namespace std;

class GraphClass {
private:
    vector<int> vertex_list;
    vector<vector<int>> adjacency_matrix;
    int max_size;
    int vertex_count;
    static int num_vertices; 
    static vector<int> vertex_list_static; 
    static vector<vector<int>> adjacency_matrix_static; 

public:
    GraphClass(int size) : max_size(size), vertex_count(0) {
        adjacency_matrix = vector<vector<int>>(size, vector<int>(size, 0));
    }
    bool is_full() {
        return vertex_count == max_size;
    }
    bool is_empty() {
        return vertex_count == 0;
    }
    void insert_vertex(int vertex) {
        if (!is_full()) {
            vertex_list.push_back(vertex);
            vertex_count++;
        }
        else {
            cout << "Невозможно добавить вершину\n";
        }
    }
    int get_vertex_position(int vertex) {
        for (int i = 0; i < vertex_count; i++) {
            if (vertex_list[i] == vertex) {
                return i;
            }
        }
        return -1;
    }
    int get_amount_vertex() {
        return vertex_count; // Возвращаем vertex_count
    }
    int get_weight(int v1, int v2) {
        int v1_pos = get_vertex_position(v1);
        int v2_pos = get_vertex_position(v2);
        if (v1_pos == -1 || v2_pos == -1) {
            cout << "Одной из узлов в графе не существует\n";
            return 0;
        }
        return adjacency_matrix[v1_pos][v2_pos];
    }
    vector<int> get_neighbours(int vertex) {
        vector<int> neighbours_list;
        int pos = get_vertex_position(vertex);
        if (pos != -1) {
            for (int i = 0; i < vertex_count; ++i) {
                if (adjacency_matrix[pos][i] != 0) {
                    neighbours_list.push_back(vertex_list[i]);
                }
            }
        }
        return neighbours_list;
    }
    void insert_edge(int vertex_1, int vertex_2, int weight = 1) {
        int vertex_pos_1 = get_vertex_position(vertex_1);
        int vertex_pos_2 = get_vertex_position(vertex_2);

        if (vertex_pos_1 == -1 || vertex_pos_2 == -1) {
            cout << "Обеих вершин (или одной из них) нет в графе\n";
            return;
        }

        if (adjacency_matrix[vertex_pos_1][vertex_pos_2] == 0 && adjacency_matrix[vertex_pos_2][vertex_pos_1] == 0) {
            adjacency_matrix[vertex_pos_1][vertex_pos_2] = weight;
            adjacency_matrix[vertex_pos_2][vertex_pos_1] = weight;
        }
        else {
            cout << "Ребро между вершинами уже есть\n";
        }
    }
    void print() {
        if (!is_empty()) {
            cout << "Матрица смежности графа:\n";

            cout << "   ";
            for (int i = 0; i < vertex_count; i++) {
                cout << " " << vertex_list[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < vertex_count; i++) {
                cout << " " << vertex_list[i] << " ";
                for (int j = 0; j < vertex_count; j++) {
                    cout << " " << adjacency_matrix[i][j] << " ";
                }
                cout << endl; // Добавляем перевод строки после каждой строки матрицы
            }
        }
        else {
            cout << "Граф пуст\n";
        }
    }
    int get_amount_edges() {
        int amount = 0;
        for (int i = 0; i < vertex_count; i++) {
            for (int j = i; j < vertex_count; j++) {
                if (adjacency_matrix[i][j] != 0) {
                    amount++;
                }
            }
        }
        return amount;
    }
    void DFS(int start_vertex, bool* visited_vertex) {
        cout << "Вершина " << start_vertex << " пройдена\n";
        visited_vertex[get_vertex_position(start_vertex)] = true;
        vector<int> neighbours = get_neighbours(start_vertex);
        for (int i = 0; i < neighbours.size(); i++) {
            if (!visited_vertex[get_vertex_position(neighbours[i])]) {
                DFS(neighbours[i], visited_vertex);
            }
        }
    }
    void BFS(int start_vertex, bool* visited_vertex) {
        queue<int> queue;
        visited_vertex[get_vertex_position(start_vertex)] = true;
        queue.push(start_vertex);

        while (!queue.empty()) {
            int current_vertex = queue.front();
            queue.pop();
            cout << "Вершина " << current_vertex << " пройдена\n";

            vector<int> neighbours = get_neighbours(current_vertex);
            for (int i = 0; i < neighbours.size(); i++) {
                int neighbour_vertex = neighbours[i];
                int neighbour_pos = get_vertex_position(neighbour_vertex);
                if (!visited_vertex[neighbour_pos]) {
                    visited_vertex[neighbour_pos] = true;
                    queue.push(neighbour_vertex);
                }
            }
        }
    }
    int shortest_path(int start_vertex, int end_vertex) {
        vector<int> distance(vertex_count, numeric_limits<int>::max());
        distance[get_vertex_position(start_vertex)] = 0;

        vector<int> previous(vertex_count, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start_vertex });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            vector<int> neighbours = get_neighbours(u);
            for (int i = 0; i < neighbours.size(); i++) {
                int v = neighbours[i];
                int weight = get_weight(u, v);
                if (distance[get_vertex_position(v)] > distance[get_vertex_position(u)] + weight) {
                    distance[get_vertex_position(v)] = distance[get_vertex_position(u)] + weight;
                    previous[get_vertex_position(v)] = u;
                    pq.push({ distance[get_vertex_position(v)], v });
                }
            }
        }

        // Вывод пути
        cout << "Кратчайший путь от " << start_vertex << " к " << end_vertex << " проходит через следующие вершины ";
        stack<int> path;
        int current_vertex = end_vertex;
        while (current_vertex != -1) {
            path.push(current_vertex);
            current_vertex = previous[get_vertex_position(current_vertex)];
        }
        while (!path.empty()) {
            if (path.size() == 1) {
                cout << path.top();
            }
            else {
                cout << path.top() << "->";
            }
            path.pop();
        }
        cout << " и равен " << distance[get_vertex_position(end_vertex)];
        cout << endl;

        return distance[get_vertex_position(end_vertex)];
    }
    void visualize_graph() { // Function to visualize the graph using OpenGL
        num_vertices = vertex_count; // Set the number of vertices
        vertex_list_static = vertex_list; // Set the vertex list
        adjacency_matrix_static = adjacency_matrix; // Set the adjacency matrix

        int argc = 0;
        char* argv = nullptr;
        glutInit(&argc, &argv);

        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Graph Visualization");

        glutDisplayFunc(display);
        glOrtho(0.0, 800.0, 600.0, 0.0, -1.0, 1.0);

        glutMainLoop();
    }
private:
    static void display() { // OpenGL display function
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0f, 0.0f, 0.0f); // Black color for lines

        double angle = 2 * 3.1415 / num_vertices; // Angle between each vertex

        // Draw vertices
        double min_dimension = min(800.0, 600.0); // Минимальная из размеров экрана
        double radius = min_dimension / 3; // Радиус окружности - 1/3 минимального размера
        for (int i = 0; i < num_vertices; ++i) {
            double x = 400 + radius * cos(i * angle);
            double y = 300 + radius * sin(i * angle);
            draw_circle(x, y, 30); // Радиус окружности вершины
            // Draw text showing vertex value
            draw_text(x - 5, y + 5, to_string(vertex_list_static[i]), 16); // Larger font size
        }

        // Draw edges
        for (int i = 0; i < num_vertices; ++i) {
            for (int j = i + 1; j < num_vertices; ++j) {
                if (adjacency_matrix_static[i][j] != 0) {
                    double mid_x = (400 + radius * cos(i * angle) + 400 + radius * cos(j * angle)) / 2;
                    double mid_y = (300 + radius * sin(i * angle) + 300 + radius * sin(j * angle)) / 2;
                    draw_line(400 + radius * cos(i * angle), 300 + radius * sin(i * angle),
                        400 + radius * cos(j * angle), 300 + radius * sin(j * angle));
                    // Draw text showing edge weight
                    draw_text(mid_x - 5, mid_y + 5, to_string(adjacency_matrix_static[i][j]), 12); // Decreased font size
                }
            }
        }

        glFlush();
        glutSwapBuffers();
    }
    static void draw_circle(double x, double y, double radius) {  // Function to draw a circle
        const int num_segments = 100;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7f, 0.7f, 0.7f); // Серый цвет для заполнения окружности
        glVertex2d(x, y); // Центр окружности
        for (int i = 0; i <= num_segments; ++i) {
            double angle = 2.0 * 3.1415 * i / num_segments;
            double dx = radius * cos(angle);
            double dy = radius * sin(angle);
            glColor3f(0.0f, 0.0f, 0.0f); // Черный цвет для границы окружности
            glVertex2d(x + dx, y + dy);
        }
        glEnd();
    }
    static void draw_line(double x1, double y1, double x2, double y2) {  // Function to draw a line
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
    }
    static void draw_text(double x, double y, const string& text, int size) {  // Function to draw text
        glColor3f(0.0f, 0.0f, 0.0f); // Black color
        glRasterPos2d(x, y);
        for (char c : text) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c); // Increased font size
        }
    }
};