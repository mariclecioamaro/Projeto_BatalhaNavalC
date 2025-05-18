#include <stdio.h>

// Constantes
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se pode posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }

    return 1;
}

// Verifica se pode posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }

    return 1;
}

// Verifica se pode posicionar navio na diagonal principal (↘)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != AGUA) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }

    return 1;
}

// Verifica se pode posicionar navio na diagonal secundária (↙)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != AGUA) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }

    return 1;
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos navios (coordenadas fixas e válidas)
    // 1. Navio horizontal
    if (!posicionarNavioHorizontal(tabuleiro, 0, 0)) {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }

    // 2. Navio vertical
    if (!posicionarNavioVertical(tabuleiro, 2, 5)) {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }

    // 3. Navio diagonal principal (↘)
    if (!posicionarNavioDiagonalPrincipal(tabuleiro, 4, 0)) {
        printf("Erro ao posicionar navio diagonal principal.\n");
        return 1;
    }

    // 4. Navio diagonal secundária (↙)
    if (!posicionarNavioDiagonalSecundaria(tabuleiro, 6, 9)) {
        printf("Erro ao posicionar navio diagonal secundária.\n");
        return 1;
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}