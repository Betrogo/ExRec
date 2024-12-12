#include <stdio.h>

#define ALUNOS 100

// Função calcular média
float calcMedia(float notas[], int quantAlunos) {
  float soma = 0;
  for (int i = 0; i < quantAlunos; i++) {
    soma += notas[i];
  }
  return soma / quantAlunos;
}

// Função para encontrar a maior e a menor nota
void maiorMenor(float notas[], int quantAlunos, float *maior, float *menor) {
  *maior = *menor = notas[0];
  for (int i = 1; i < quantAlunos; i++) {
    if (notas[i] > *maior) {
      *maior = notas[i];
    }
    if (notas[i] < *menor) {
      *menor = notas[i];
    }
  }
}

// Função para contar as notas que estão acima da média
int acimaMedia(float notas[], int quantAlunos, float media) {
  int cont = 0;
  for (int i = 0; i < quantAlunos; i++) {
    if (notas[i] > media) {
      cont++;
    }
  }
  return cont;
}

// Função para ordenar notas
void ordenarNotas(float notas[], int quantAlunos) {
  int i, j;
  float temp;
  for (i = 0; i < quantAlunos - 1; i++) {
    for (j = 0; j < quantAlunos - i - 1; j++) {
      if (notas[j] > notas[j + 1]) {
        temp = notas[j];
        notas[j] = notas[j + 1];
        notas[j + 1] = temp;
      }
    }
  }
}

// Função para validar nota
float validarNota() {
  float nota;
  while (1) {
    printf("Informe a nota (0-10): ");
    scanf("%f", &nota);
    if (nota >= 0 && nota <= 10) {
      return nota;
    } else {
      printf("Nota inválida. Tente novamente.\n");
    }
  }
}

// Função principal
int main() {
  float notas[ALUNOS];
  int quantAlunos = 0;
  int opcao;

  do {
    printf("----------- Menu -----------\n");
    printf("1. Adicionar nota\n");
    printf("2. Calcular média\n");
    printf("3. Maior e menor nota\n");
    printf("4. Alunos com nota acima da média\n");
    printf("5. Ordenar notas\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (quantAlunos < ALUNOS) {
        notas[quantAlunos] = validarNota();
        quantAlunos++;
      } else {
        printf("Limite de alunos atingido.\n");
      }
      break;
    case 2:
      if (quantAlunos > 0) {
        float media = calcMedia(notas, quantAlunos);
        printf("Média: %.2f\n", media);
      } else {
        printf("Nenhuma nota adicionada.\n");
      }
      break;
    case 3:
      if (quantAlunos > 0) {
        float maior, menor;
        maiorMenor(notas, quantAlunos, &maior, &menor);
        printf("Maior nota: %.2f\n", maior);
        printf("Menor nota: %.2f\n", menor);
      } else {
        printf("Nenhuma nota adicionada.\n");
      }
      break;
    case 4:
      if (quantAlunos > 0) {
        float media = calcMedia(notas, quantAlunos);
        int acima = acimaMedia(notas, quantAlunos, media);
        printf("Alunos com nota acima da média: %d\n", acima);
      } else {
        printf("Nenhuma nota adicionada.\n");
      }
      break;
    case 5:
      if (quantAlunos > 0) {
        ordenarNotas(notas, quantAlunos);
        printf("Notas ordenadas:\n");
        for (int i = 0; i < quantAlunos; i++) {
          printf("%.2f ", notas[i]);
        }
        printf("\n");
      } else {
        printf("Nenhuma nota adicionada.\n");
      }
      break;
    case 6:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 6);

  return 0;
}