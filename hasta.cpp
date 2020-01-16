#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int K;
static int i;
static int j;
static int Q;
static int* V;
static int* R;

void inizia(int N, int K, int V[], int R[])
{
}

int istiga(int l, int r)
{
    int count, output = 0;

    for (int i = 0; i < K; i++) {
        count = 0;
        for (int k = l; k <= r; k++)
            if (V[k] == i)
                count++;
        if (count == R[i])
            output += count;
    }

    return output;
}

// int main() 
// {
//     int Q, i, j;

//     std::cin >> N;
//     std::cin >> K;
//     V = new int[N];
//     R = new int[K];
//     for (int i = 0; i < N; i++)
//         fscanf(fr, "%d", &V[i]);
//     for (int i = 0; i < K; i++)
//         fscanf(fr, "%d", &R[i]);
//     inizia(N, K, V, R);

//     std::cin >> Q;
//     while (Q--) {
//         std::cin >> i;
//         std::cin >> j;
//         std::cout << istiga(i, j) << std::endl;
//     }

//     delete[] V;
//     delete[] R;

//     std::cin.get();
//     std::cin.get();
// }

//grader
int main() { 
    // fr = freopen("hasta.input0.txt", "r", stdin);
    // fw = freopen("hasta.output0.txt", "w", stdout);
    // fr = freopen("hasta.input1.txt", "r", stdin);
    // fw = freopen("hasta.output1.txt", "w", stdout);
    fr = freopen("hasta.input2.txt", "r", stdin);
    fw = freopen("hasta.output2.txt", "w", stdout);

	// Reading input
	fscanf(fr,"%d %d",&N,&K);
	V = (int*)malloc((N) * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %d", &V[i0]);
	}
	R = (int*)malloc((K) * sizeof(int));
	for (int i0 = 0; i0 < K; i0++) {
		fscanf(fr, " %d", &R[i0]);
	}

	// Calling functions
	inizia(N,K,V,R);
    fscanf(fr,"%d",&Q);
    // Writing output
	while (Q--) {
        fscanf(fr,"%d %d",&i,&j);
		fprintf(fw,"%d ",istiga(i,j));
	}
	fprintf(fw,"\n");

    fclose(fr);
    fclose(fw);
    return 0;
}
