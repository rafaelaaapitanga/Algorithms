// Escreva um programa em linguagem C++ que solicita ao usuário a quantidade de alunos de uma turma e aloca um matriz de notas
// (números reais). Depois de ler as notas, imprime a média aritmética de cada turma. Obs: não deve ocorrer desperdício de
// memória; e após ser utilizada, a memória deve ser devolvida.

#include <iostream>
using namespace std;

float calcularMedia(float *notas, int numAlunos) {
    float soma = 0.0;
    for (int i = 0; i < numAlunos; i++) {
        soma += notas[i];
    }
    return (soma/numAlunos);
}

int main() {
    int numAlunos;
    cout << "Quantidade de alunos: ";
    cin >> numAlunos;

    float *notas = new float[numAlunos]; // aloca memómria p matriz de notas

    cout << "Notas dos alunos" << endl;
    for (int i = 0; i < numAlunos; i++) { // preenche a matriz de notas
        cout << "Nota do aluno " << i+1 << ": ";
        cin >> notas[i];
    }

    float media = calcularMedia(notas, numAlunos);
    cout << "Media aritmetica da turma: " << media << endl;

    delete[] notas;

    return 0;
}