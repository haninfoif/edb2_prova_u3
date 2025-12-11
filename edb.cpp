#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <chrono>
#include <random>

using namespace std;

void resolverEficiente(const vector<int>& A, const vector<int>& B) { //define a função que recebe dois vetores de inteiros (A e B) como referência constante (para evitar copiar os dados e gastar memória à toa).
    set<int> s; //cria um conjunto chamado s
    for (int x : A) s.insert(x); //para cada elemento x em A/B
    for (int x : B) s.insert(x); //inserir num set já ordena os numeros. basicamente ele pega cada elemento dos vetores A e B e insere no conjunto, já ordenando tudo.
    
    map<int, int> posicoes;
    int idx = 1;
    for (auto val : s) posicoes[val] = idx++; //para cada valor no conjunto s, o menor numero (o primeiro do conjunto) recebe idx = 1, pois eh a posição do primeiro inteiro. o segundo numero (o segundo menor) recebe indice 2, e assim por diante. basicamente tá numerando a partir de 1 em ordem crescente os elementos do conjunto por meio de um map.
    //isso seria tipo, supondo o conjunto {5, 6, 7}, posicoes5[] = 1, posicoes[6] = 2, etc
}

void resolverIneficiente(const vector<int>& A, const vector<int>& B) {
    vector<int> C = A; //cria uma copia do vetor A chamada C
    C.insert(C.end(), B.begin(), B.end()); //concatena o vetor B ao vetor C
    sort(C.begin(), C.end()); //ordena o vetor C

    int dummy = 0;
    for (int x : A) { //passa por cada numero de A
        for (int i = 0; i < C.size(); i++) { 
            if (C[i] == x) { dummy = i; break; }
            //pra descobrir qual o indice de cada num conjunto {5, 6, 7}, se C[0] == 5, o numero 0 vai pra dummy e o loop acaba. senao ela continua rodando o loop. busca linear
        }
    }
    for (int x : B) { //mesma coisa
        for (int i = 0; i < C.size(); i++) {
            if (C[i] == x) { dummy = i; break; }
        }
    }
}

int main() {
    cout << "N Tempo_Ineficiente_ms Tempo_Eficiente_ms" << endl;

    // varia N de 100 até 5000 (acima disso nao tenho coragem de testar no meu notebook kkkkk e alem disso como a função ineficiente é quadratica poderia demorar um boooooommmm tempo)
    for (int N = 100; N <= 5000; N += 100) { //teste começa com vetores de tamanho 100 e vai aumentando de 100 em 100 até chegar em 5000
        int M = N; // assumir M = N para o teste

        vector<int> A(N), B(M); //preenchendo os vetores
        int val = 1;
        for(int i=0; i<N; i++) { A[i] = val; val += 2; }
        val = 2;
        for(int i=0; i<M; i++) { B[i] = val; val += 2; }

        auto start = chrono::high_resolution_clock::now(); //horario antes de começar
        resolverIneficiente(A, B);
        auto end = chrono::high_resolution_clock::now(); //horario depois de terminar
        auto tempoIneficiente = chrono::duration_cast<chrono::microseconds>(end - start).count(); //subtrai pra saber quanto tempo levou

        start = chrono::high_resolution_clock::now();
        resolverEficiente(A, B);
        end = chrono::high_resolution_clock::now();
        auto tempoEficiente = chrono::duration_cast<chrono::microseconds>(end - start).count(); //mesma coisa com o eficiente

        cout << N << " " << tempoIneficiente << " " << tempoEficiente << endl; //printa o tamanho do vetor, o tempo ineficiente e o tempo eficiente. vou copiar esses numeros pro codigo python
    }

    return 0;
}
