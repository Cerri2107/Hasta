#include <stdio.h>
#include <iostream>

static int N, K, *V, *R;

void inizia(int N, int K, int V[], int R[])
{
    for (int i = 0; i < N; i++)
        scanf("%d", &V[i]);

    for (int i = 0; i < K; i++)
        scanf("%d", &R[i]);
}

int istiga(int l, int r)
{
    int *k = new int[K], output = 0;

    for (int i = 0; i < K; i++)
        k[i] = 0;

    for (int i = l; i <= r; i++)
        k[V[i]]++;

    for (int i = 0; i < K; i++)
        if (k[i] == R[i])
            output += k[i];
    
    delete[] k;

    return output;
}

int main() 
{
    int Q, i, j;

    std::cin >> N;
    std::cin >> K;
    V = new int[N];
    R = new int[K];
    inizia(N, K, V, R);

    std::cin >> Q;
    while (Q--) {
        std::cin >> i;
        std::cin >> j;
        std::cout << istiga(i, j) << std::endl;
    }

    delete[] V;
    delete[] R;

    std::cin.get();
    std::cin.get();
}