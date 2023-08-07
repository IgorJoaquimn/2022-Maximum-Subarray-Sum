#ifndef OBJ
#define OBJ
#include <iostream>
#include <vector>
#include <set>


using namespace std;

class mss
// Descricao: Maximum Subarray Sum, uma classe composta por 2 dados:
// v: vetor com os dados da entrada
// cumulative_sum: vetor com a soma cumulativa dos dados da entrada
// Entrada: v
{
    public:
    std::vector<int> v; //vetor com os dados da entrada
    std::vector<int> cumulative_sum; //  vetor com a soma cumulativa dos dados da entrada

    // Funções que computam o Maximum Subarray Sum
    std::pair<int,int> resolve(int ini, int end);
    std::pair<int, int> middle(int ini, int m, int end);

    // Funções auxiliares
    void cumulative();
    int sum(int &x, int &y);
    std::pair<int, int> max_possibility(std::vector<std::pair<int, int>> &possibilites);


};
#endif
