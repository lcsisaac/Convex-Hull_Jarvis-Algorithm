#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // Embora não estritamente necessário aqui, é comum em geometria

using namespace std;

struct Point
{
    int x, y;
};

// ----------------------------------------------------------------------
// FUNÇÃO CHAVE: ORIENTAÇÃO (Produto Vetorial Bidimensional)
// ----------------------------------------------------------------------

// Para encontrar a orientação do trio ordenado (p, q, r).
// O cálculo se baseia no sinal do produto vetorial bidimensional.
//
// Retorna:
// 0 --> p, q e r são colineares (na mesma linha)
// 1 --> Sentido Horário (Clockwise, val > 0)
// 2 --> Sentido Anti-horário (Counterclockwise, val < 0)
int orientation(Point p, Point q, Point r)
{
    // O valor representa (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)
    // que é o dobro da área com sinal do triângulo pqr.
    long long val = (long long)(q.y - p.y) * (r.x - q.x) -
                    (long long)(q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;       // Colinear
    return (val > 0) ? 1 : 2;    // 1 para Horário, 2 para Anti-horário
}

// ----------------------------------------------------------------------
// ALGORITMO DE JARVIS (Marcha de Jarvis ou Gift Wrapping)
// ----------------------------------------------------------------------

// Imprime o fecho convexo de um conjunto de n pontos.
// Complexidade: O(n*h), onde h é o número de pontos no fecho.
void convexHull(const Point points[], int n)
{
    // Deve haver pelo menos 3 pontos para formar um fecho convexo.
    if (n < 3) return;

    // Inicializar o vetor que armazenará os pontos do fecho (hull)
    vector<Point> hull;

    // 1. Encontrar o ponto inicial (l): o ponto mais à esquerda (menor x).
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // 2. Iniciar a "Marcha" (Envolvimento) a partir do ponto mais à esquerda.
    // O loop continua movendo-se no sentido anti-horário até retornar ao ponto inicial 'l'.
    int p = l, q;
    do
    {
        // Adicionar o ponto atual 'p' ao resultado
        hull.push_back(points[p]);

        // Encontrar o ponto 'q' mais anti-horário em relação a 'p'.
        // Inicializa q como o próximo ponto no array para começar a busca.
        q = (p + 1) % n;

        // Itera sobre todos os pontos 'i' para encontrar o 'q' que forma a
        // curva mais à esquerda (Anti-horário = 2) com 'p'.
        for (int i = 0; i < n; i++)
        {
           // Se a orientação (p, i, q) for Anti-horário (2),
           // significa que 'i' está mais à esquerda do que o 'q' atual.
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }

        // 'q' é agora o ponto mais anti-horário. Ele se torna o novo 'p' para a próxima iteração.
        p = q;

    } while (p != l); // Parar quando o loop retornar ao ponto inicial

    // 3. Imprimir o Resultado
    cout << "Fecho Convexo (Jarvis's March):\n";
    for (size_t i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
}

// Programa principal para testar as funções
int main()
{
    // Conjunto de pontos de entrada (inclui pontos internos)
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    convexHull(points, n);

    return 0;
}
