#include "rock.hpp"

void mss::cumulative()
// Descricao: Computação do Cumulative array:
// Entrada: v -> vetor com os dados lidos
// Saida:
// cumulative_sum: vetor com a soma cumulativa dos dados da entrada
{
    cumulative_sum.push_back(v[0]);
    for (long unsigned i = 1; i < v.size(); i++)
        cumulative_sum.push_back(v[i] + cumulative_sum[i - 1]);
}

int mss::sum(int &x, int &y)
// Descricao: Essa função calcula a soma do intervalo (x,y) com x<=y;
// Entrada: (x,y) -> limites do intervalo
// Saida:
// sum: valor do intervalo (x,y)
{
    // Teste para verificar se x == 0, para não acessar a posição -1 do vetor cumulative_sum;
    int lower_bound = (x != 0) ? cumulative_sum[x - 1] : 0;
    return cumulative_sum[y] - lower_bound;
}

std::pair<int, int> mss::max_possibility(std::vector<std::pair<int, int>> &possibilites)
// Descricao: Função auxiliar que calcula o intervalo com maior soma, dado uma lista de intervalos 
// Entrada: possibilites -> pares (x,y) para serem comparados 
// Saida:
// par (x,y) com Maximum Subarray Sum dentre as possibilidades
{
    int ini, end;

    //  Número mágico que representa a nota mínima de um show 
    int max = -999999999;
    for (long unsigned i = 0; i < possibilites.size(); i++)
    // Para cada possibilidade, é perguntado se ela possui uma soma maior do que a maior soma já computada
    {
        int x = possibilites[i].first;
        int y = possibilites[i].second;
        int value = sum(x, y);
        // CASO 1: Intervalos de mesma soma devem ser desempatados pela quantidade de elementos presente neles.
        if (value == max)
        {
            if ((y - x) > (end - ini))
            {
                max = value;
                ini = x;
                end = y;
            }
        }
        // CASO 2: Foi encontrado um intervalo com maior soma.
        else if (value > max)
        {
            max = value;
            ini = x;
            end = y;
        }
    }
    return {ini, end};
}

std::pair<int, int> mss::middle(int ini, int m, int end)
// Descricao: Função que calcula o intervalo máximo que contém o m-ésimo elemento do vetor  
// Entrada: (ini,end)   -> intervalo a ser analisado;
//           m          -> (ini + end) / 2 
// Saida:
// par (x,y) com Maximum Subarray Sum dentre as possibilidades
{

    // Variaveis auxiliares
    int sum = 0, 
        start_left  = m,
        end_right   = m;
    //  Número mágico que representa a nota mínima de um show 
    int left_sum = -999999999;
    int right_sum = -999999999;


    // É procurado, iterativamente, o maior intervalo entre [ini,m]
    for (int i = m; i >= ini; i--) {
        sum = sum + v[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            start_left = i;
        }
    }

    sum = 0;
    // É procurado, iterativamente, o maior intervalo entre [m,end]
    for (int i = m; i <= end; i++) {
        sum = sum + v[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            end_right = i;
        }
    }

    // Possibilidades
    std::vector<std::pair<int, int>> possibilites = {
        {start_left, end_right},// Todo o intervalo, considerando o melhor da esquerda ao melhor da direita 
        {start_left, m},        // O intervalo à esquerda
        {m, end_right},};       // O intervalo à direita
    return max_possibility(possibilites);
}

std::pair<int, int> mss::resolve(int ini, int end)
// Descricao: Funçãoque calcula o intervalo máximo entre [ini,end]  
// Entrada: (ini,end)   -> intervalo a ser analisado;
// Saida:
// par (x,y) com Maximum Subarray Sum dentre as possibilidades
{

    // Caso base 1: intervalo vazio
    if (end < ini)
        return {end, end};

    // Caso base 2: intervalo com 1 elemento
    if (end == ini)
        return {ini, end};

    // Caso Recursivo:
    int M = (ini + end) / 2;
    std::pair<int, int> lpair = resolve(ini, M-1);
    std::pair<int, int> rpair = resolve(M + 1, end);
    std::pair<int, int> mpair = middle(ini, M, end);
    std::vector<std::pair<int, int>> possibilites = {
        lpair, // O intervalo à esquerda
        mpair, // O intervalo ao meio
        rpair};// O intervalo à direita
    return max_possibility(possibilites);
}