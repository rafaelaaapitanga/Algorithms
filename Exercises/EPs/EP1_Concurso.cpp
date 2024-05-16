#include <iostream>
#include <cmath>
using namespace std;

struct Candidato {
    string nome;
    int nota;
    int idade;
    int id_inscricao;
};

static int idCount = 0;

void Merge(Candidato arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Candidato L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2) {
        if (L[i].nota > R[j].nota || (L[i].nota == R[j].nota && L[i].idade > R[j].idade) || L[i].nota == R[j].nota && L[i].idade == R[j].idade && L[i].id_inscricao < R[j].id_inscricao) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void MergeSort(Candidato arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

int main() {
    int c; // quantidade de cargos
    cin >> c;

    for (int j = 0; j < c; j++) {
        int i, v; // quantidade de inscritos e quantidade de vagas
        cin >> i >> v;
        
        Candidato candidatos[i];
        for (int k = 0; k < i; k++) {
            cin >> candidatos[k].nome >> candidatos[k].nota >> candidatos[k].idade;
            candidatos[k].id_inscricao = idCount++;
        }

        MergeSort(candidatos, 0, i - 1); // ordenando os candidatos

        cout << "cargo " << j+1 << ":" << endl;
        int classificados = min(i, v);
        for (int k = 0; k < classificados; k++) {
            cout << candidatos[k].nome << endl;
        }

        if (v > i) {
            int vagasNaoPreenchidas = v - i;
            for (int i = 0; i < vagasNaoPreenchidas; i++) {
                cout << "x" << endl; // vagas nao preenchidas
            }
        }
    }

    return 0;
}
