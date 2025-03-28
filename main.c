#include <stdio.h>

#define POSTO 3


void multiplica_matrizes(double A[][POSTO], double B[][POSTO], double C[][POSTO]);
void multiplica_matriz_vetor(double A[][POSTO], double B[POSTO], double C[POSTO]);

void copia_matriz(double A[][POSTO], double C[][POSTO]);
void copia_vetor(double A[POSTO], double C[POSTO]);
void set_identidade(double M[][POSTO]);
void set_vetor_zero(double V[POSTO]);
void print_matriz(double A[][POSTO]);
void print_vetor(double A[POSTO]);

int main(int argc, const char* argv[]) {
    // double A[] = {4.0, 2.0, 1.0, 1.0, 5.0, 4.0, 2.0, 3.0, 6.0};  // Transposta pra ser mais eficiente acessar
    // // A matriz de fato é essa
    // // | 4  1  2 |
    // // | 2  5  3 |
    // // | 1  4  6 |


    double A[][POSTO] = {
        {4.0, 1.0, 2.0},
        {2.0, 5.0, 3.0},
        {1.0, 4.0, 6.0},
    };
    double temp_A[][POSTO] = {
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0},
    };
    double B[] = {7.0, 8.0, 9.0};
    double temp_B[] = {0.0, 0.0, 0.0};
    double M[][POSTO] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };

    for (int j = 0; j < POSTO - 1; j++) {
        for (int i = j + 1; i < POSTO; i++) {
            M[i][j] = -A[i][j] / A[j][j];
        }
        multiplica_matrizes(M, A, temp_A);
        multiplica_matriz_vetor(M, B, temp_B);

        copia_matriz(A, temp_A);
        copia_vetor(B, temp_B);
        set_identidade(M);
        print_matriz(A);

        print_vetor(B);
        printf("-------------------------\n");
    }

    
    set_vetor_zero(temp_B);

    temp_B[POSTO-1] = B[POSTO-1] / A[POSTO-1][POSTO-1];

    for (int i = POSTO - 2; i >= 0; i--) {
        temp_B[i] = B[i];
        for (int j = i + 1; j < POSTO; j++) {
            temp_B[i] -= A[i][j] *  temp_B[j];
        }
        temp_B[i] /= A[i][i];
    }

    print_vetor(temp_B);

    return 0;
}

void multiplica_matrizes(double A[][POSTO], double B[][POSTO], double C[][POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        for (int j = 0; j < POSTO; j++) {
            C[i][j] = 0;
            for (int k = 0; k < POSTO; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplica_matriz_vetor(double A[][POSTO], double B[POSTO], double C[POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        C[i] = 0;
        for (int k = 0; k < POSTO; k++) {
            C[i] += A[i][k] * B[k];
        }
    }
}

void copia_matriz(double A[][POSTO], double C[][POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        for (int j = 0; j < POSTO; j++) {
            A[i][j] = C[i][j];
        }
    }
}

void copia_vetor(double A[POSTO], double C[POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        A[i] = C[i];
    }
}


void set_identidade(double M[][POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        for (int j = 0; j < POSTO; j++) {
            if (i == j) {
                M[i][j] = 1;
            } else {
                M[i][j] = 0;
            }
        }
    }
}

void print_matriz(double A[][POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        for (int j = 0; j < POSTO; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

void print_vetor(double A[POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        printf("%f ", A[i]);
    }
    printf("\n");
}

void set_vetor_zero(double V[POSTO]) {
    for (int i = 0; i < POSTO; i++) {
        V[i] = 0;
    }
}