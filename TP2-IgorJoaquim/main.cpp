#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"
using namespace std;

// Linha para otimizar leitura
#define _                           \
  ios_base::sync_with_stdio(false); \
  std::cin.tie(0);

int main()
// Descricao: leitura da entrada
// Entrada: entrada padrão
// Saida: Par {i,j} onde {i,j} representa o intervalo de maior soma
{
  _ double input;
  int N, M;

  while (cin >> N >> M)
  {
    // Enquanto existir entrada e ela não for (0,0)
    if (N == 0 && M == 0)
      break;

    // Objeto Maximum Subarray Sum, usado para resolver o problema
    mss obj;
    std::vector<int> v(M, 0);

    // Leitura da entrada
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
      {
        if (i == 0)
          obj.v.push_back(0);
        cin >> input;
        obj.v[j] += input * 1000; // Multiplicado por 1000 para não lidar com ponto flutuante
      }


    pair<int, int> pair;
    obj.cumulative(); // Função auxiliar usada para calcular a solução
    pair = obj.resolve(0, M - 1);
    cout << pair.first + 1 << " " << pair.second + 1 << endl;
  }
  return (0);
}
