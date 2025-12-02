# Convex-Hull_Jarvis-Algorithm
Algoritmo de Jarvis em C++ para encontrar o Fecho Convexo (Convex Hull). Demonstração da lógica de orientação anti-horária.

Com certeza\! Um bom arquivo `README.md` no GitHub deve ser claro, informativo e estruturado.

Aqui está um texto completo e bem estruturado que você pode usar, com seções que explicam o algoritmo, como ele funciona e como executar o código.

-----

# 🤖 Algoritmo de Jarvis (Marcha do Embrulho de Presente)

## 📌 Visão Geral do Projeto

Este repositório contém uma implementação em C++ do **Algoritmo de Jarvis** (também conhecido como **Marcha de Jarvis** ou **Algoritmo do Embrulho de Presente** - *Gift Wrapping*), uma técnica clássica da geometria computacional para encontrar o **Fecho Convexo** (*Convex Hull*) de um conjunto de pontos 2D.

O **Fecho Convexo** é o menor polígono convexo que contém todos os pontos do conjunto de entrada.

## ✨ O Algoritmo de Jarvis

O algoritmo opera de forma intuitiva, simulando o "embrulho" de um conjunto de pontos com uma corda ou papel.

### Princípio de Funcionamento

1.  **Ponto Inicial:** O processo começa no ponto com a menor coordenada $X$ (o ponto mais à esquerda).
2.  **Marcha (Wrapping):** A partir do ponto atual $p$, o algoritmo procura o próximo ponto $q$ que forma o menor ângulo no **sentido anti-horário** com a horizontal.
3.  **Orientação Geométrica:** Para encontrar esse próximo ponto, ele testa todos os outros pontos $i$ do conjunto usando uma função de **orientação** (baseada no produto vetorial).
      * O ponto $q$ é aquele que garante que todos os outros pontos $i$ fiquem à sua direita ou colineares ao segmento $pq$.
4.  **Parada:** O processo se repete (a "marcha") até que o algoritmo retorne ao ponto inicial, fechando o polígono do Fecho Convexo.

### Complexidade de Tempo

A complexidade de tempo do Algoritmo de Jarvis é $O(n \cdot h)$, onde:

  * $n$ é o número total de pontos de entrada.
  * $h$ é o número de pontos que estão no Fecho Convexo (o número de vértices do polígono resultante).

Este algoritmo é particularmente eficiente quando o fecho convexo tem um número pequeno de vértices ($h \ll n$).

## ⚙️ Estrutura do Código

O código em C++ está organizado da seguinte forma:

1.  **`struct Point`:** Define a estrutura básica para representar as coordenadas $(x, y)$ de um ponto.
2.  **`int orientation(Point p, Point q, Point r)`:** Esta função crucial determina a orientação do trio de pontos. Retorna 0 (colinear), 1 (horário) ou 2 (anti-horário).
3.  **`void convexHull(Point points[], int n)`:** É a função principal que implementa a lógica do Algoritmo de Jarvis. Ela inicializa a busca no ponto mais à esquerda e executa o loop de "marcha".

## ▶️ Como Executar

Para compilar e executar o código, você precisará de um compilador C++ (como GCC ou G++).

1.  **Compile o arquivo:**
    ```bash
    g++ -o jarvis_hull jarvis_hull.cpp
    ```
2.  **Execute o programa:**
    ```bash
    ./jarvis_hull
    ```

O programa imprimirá as coordenadas dos pontos que compõem o Fecho Convexo.
