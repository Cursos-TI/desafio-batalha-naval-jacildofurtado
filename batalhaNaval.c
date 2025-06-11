#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // Nível Novato - Posicionamento dos Navios

    // 1. Criar o tabuleiro do jogo.

    int tabuleiro [10] [10]; // Matriz para simular um tabuleiro 10 x 10.

    // Este loop aninhado preenche a matriz do tabuleiro com o valor 0 em todos os índices representando água.
    for (int i = 0; i < 10; i++) { // Conta as linhas.

        for (int j = 0; j < 10; j++) { // Conta as colunas.
            tabuleiro[i][j] = 0;
        }

    }

    // 2. Posicionamento dos navios.

    // Definição de vetores com comprimento 3 para representar os navios.
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};

    // Coordenadas navio 1 - Horizontal.
    int linha1 = 9;
    int colunaInicial1 = 5;
    int podePosicionar1 = 1;

    // Coordenadas do navio 2 - Vertical.
    int coluna2 = 9;
    int linhaInicial2 = 7;
    int podePosicionar2 = 1;

    // Coordenadas do navio 3 - Diagonal
    int linhaInicial3 = 0;
    int colunaInicial3 = 0;
    int podePosicionar3 = 1;

    // Coordenadas do navio 4 - Diagonal
    int linhaInicial4 = 0;
    int colunaInicial4 = 9;
    int podePosicionar4 = 1;

    // Verifica se o navio 1 cabe no tabuleiro.
    if (colunaInicial1 + 3 <= 10 && linha1 <= 10) { // Verifica se o navio cabe na horizontal sem ultrapassar as bordas do tabuleiro.

        for (int i = 0; i < 3; i++) { // Verifica se as posições onde o navio será colocado já estão ocupadas.

            if(tabuleiro[linha1][colunaInicial1 + i] != 0){
                podePosicionar1 = 0;
                break;
            }

        }

    } else {

        podePosicionar1 = 0;

    }

    // Posicionamento do navio 1 na horizontal se ele puder ser posicionado.
    if (podePosicionar1 == 1) {

        for(int i = 0; i < 3; i++) {

            tabuleiro[linha1][colunaInicial1 + i] = navio1[i]; // A linha é fixa e o loop percorre a coluna substituindo o valor no tabuleiro pelo navio.

        }

    } else {

        printf("Erro: navio 1 fora dos limites ou sobreposição!\n");

    }

    // Verifica se o navio 2 cabe no tabuleiro.
    if (linhaInicial2 + 3 <= 10 && coluna2 <= 10) { // Verifica se o navio cabe na vertical sem ultrapassar as bordas do tabuleiro.

        for (int i = 0; i < 3; i++) { // Verifica se as posições onde o navio será colocado já estão ocupadas.

            if (tabuleiro[linhaInicial2 + i][coluna2] != 0) {
                podePosicionar2 = 0;
                break;
            }

        }

    } else {

        podePosicionar2 = 0;

    }

    // Posionamento do navio 2 se ele puder ser posicionado
    if (podePosicionar2 == 1) {

        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaInicial2 + i][coluna2] = navio2[i]; // A coluna é fixa e o loop percorre a linha substituindo o valor no tabuleiro pelo navio.
        }

    } else {

        printf("Erro: navio 2 fora dos limites ou sobreposição!\n");

    }

    // Verifica se o navio 3 cabe no tabuleiro.
    if (linhaInicial3 + 3 <= 10 && colunaInicial3 + 3 <= 10) { // Verifica se o navio cabe partindo da diagonal superior esquerda sem ultrapassar as bordas do tabuleiro.

        for (int i = 0; i < 3; i++) { // Verifica se as posições onde o navio será colocado já estão ocupadas.
            for (int j = 0; j < 3; j++) {
                if(tabuleiro[linhaInicial3 + i][colunaInicial3 + j] != 0){
                    podePosicionar3 = 0;
                    break;
                }
            }
        }

    } else {

        podePosicionar3 = 0;

    }

    
    // Posionamento do navio 3 se ele puder ser posicionado
    if (podePosicionar3 == 1) {

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {

                // Verifica se o índice da linha + i é igual o da coluna + j, se for então marca a posição, senão continua 0.
                if (linhaInicial3 + i == colunaInicial3 + j) {
                    tabuleiro[linhaInicial3 + i][colunaInicial3 + j] = navio3[i];
                } else {
                    tabuleiro[linhaInicial3 + i][colunaInicial3 + j] = 0;
                }

            }

        }

    } else {

        printf("Erro: navio 3 fora dos limites ou sobreposição!\n");

    }

    // Verifica se o navio 4 cabe no tabuleiro.
    if (linhaInicial4 + 3 <= 10 && (colunaInicial4 <= 10 && colunaInicial4 - 3 >= 0)) { // Verifica se o navio cabe partindo da diagonal superior direita sem ultrapassar as bordas do tabuleiro.

        for (int i = 0; i < 3; i++) { // Verifica se as posições onde o navio será colocado já estão ocupadas.
            for (int j = 0; j < 3; j++) {
                if(tabuleiro[linhaInicial4 + i][colunaInicial4 - j] != 0){
                    podePosicionar4 = 0;
                    break;
                }
            }
        }

    } else {

        podePosicionar4 = 0;

    }

    // Posionamento do navio 4 se ele puder ser posicionado
    if (podePosicionar4 == 1) {

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {

                // Verifica se a soma da linhaInicial4 + i com a colunaInicial4 - j é igual a soma da linhaInicial4 com a colunaInicial4, então marca a posição, senão continua 0.
                if ((linhaInicial4 + i) + (colunaInicial4 - j) == linhaInicial4 + colunaInicial4) {
                    tabuleiro[linhaInicial4 + i][colunaInicial4 - j] = navio4[i];  
                } else {
                    tabuleiro[linhaInicial4 + i][colunaInicial4 - j] = 0;
                }

            }

        }

    } else {

        printf("Erro: navio 4 fora dos limites ou sobreposição!\n");

    }

    // 3. Habilidades especiais

    // Matrizes de habilidade
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // este loop inicializa todas as matrizes de habilidade com 5;
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            cone[i][j] = 5;
            cruz[i][j] = 5;
            octaedro[i][j] = 5;
        }

    }

    // coodenadas das habilidades (a coordenada inicial da habilidade é o seu centro).

    // coordenada inicial do cone
    int coneLinhaOrigem = 1;
    int coneColunaOrigem = 4;
    int habilidadePodePosicionar1 = 1;

    // coordenada inicial da cruz
    int cruzLinhaOrigem = 5;
    int cruzColunaOrigem = 7;
    int habilidadePodePosicionar2 = 1;

    // coordenada inicial do octaedro
    int octaedroLinhaOrigem = 8;
    int octaedroColunaOrigem = 2;
    int habilidadePodePosicionar3 = 1;

    // verifica se o cone está dentro do limite do tabuleiro
    if ((coneLinhaOrigem + 1 < 10 && coneLinhaOrigem - 1 >= 0) && (coneColunaOrigem + 2 < 10 && coneColunaOrigem - 2 >= 0)) {
        // este loop imprime a habilidade de cone no tabuleiro
        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {
                // origem da habilidade (centro)
                if (coneLinhaOrigem == i && coneColunaOrigem == j){
                    tabuleiro[coneLinhaOrigem][coneColunaOrigem] = cone[i][j];
                    tabuleiro[coneLinhaOrigem][coneColunaOrigem - 1] = cone[i][j];
                    tabuleiro[coneLinhaOrigem][coneColunaOrigem + 1] = cone[i][j];
                }
                // topo do cone
                if (coneLinhaOrigem - 1 == i && coneColunaOrigem == j) {
                    tabuleiro[coneLinhaOrigem - 1][coneColunaOrigem] = cone[i][j];
                }
                // base do cone
                if (coneLinhaOrigem + 1 == i && coneColunaOrigem == j) {
                    tabuleiro[coneLinhaOrigem + 1][coneColunaOrigem] = cone[i][j];
                    tabuleiro[coneLinhaOrigem + 1][coneColunaOrigem - 1] = cone[i][j];
                    tabuleiro[coneLinhaOrigem + 1][coneColunaOrigem - 2] = cone[i][j];
                    tabuleiro[coneLinhaOrigem + 1][coneColunaOrigem + 1] = cone[i][j];
                    tabuleiro[coneLinhaOrigem + 1][coneColunaOrigem + 2] = cone[i][j];                     
                }
            }

        }

    } else {
        printf("Habilidade de cone fora dos limites do tabuleiro!\n");
    }

    // verifica se a cruz está dentro do limite do tabuleiro
    if ((cruzLinhaOrigem + 1 < 10 && cruzLinhaOrigem - 1 >= 0) && (cruzColunaOrigem + 2 < 10 && cruzColunaOrigem - 2 >= 0)) {
        // este loop imprime a habilidade de cruz no tabuleiro
        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {
                // origem da habilidade (centro)
                if (cruzLinhaOrigem == cruzLinhaOrigem + i && cruzColunaOrigem == cruzColunaOrigem + j){
                    tabuleiro[cruzLinhaOrigem][cruzColunaOrigem - 2] = cruz[i][j];
                    tabuleiro[cruzLinhaOrigem][cruzColunaOrigem - 1] = cruz[i][j];
                    tabuleiro[cruzLinhaOrigem][cruzColunaOrigem] = cruz[i][j];
                    tabuleiro[cruzLinhaOrigem][cruzColunaOrigem + 1] = cruz[i][j];
                    tabuleiro[cruzLinhaOrigem][cruzColunaOrigem + 2] = cruz[i][j];
                }
                // topo da cruz
                if (cruzLinhaOrigem - 1 == cruzLinhaOrigem - i && cruzColunaOrigem == cruzColunaOrigem + j) {
                    tabuleiro[cruzLinhaOrigem - 1][cruzColunaOrigem] = cruz[i][j];
                }
                // base da cruz
                if (cruzLinhaOrigem + 1 == cruzLinhaOrigem + i && cruzColunaOrigem == cruzColunaOrigem + j) {
                    tabuleiro[cruzLinhaOrigem + 1][cruzColunaOrigem] = cruz[i][j];
                }
            }

        }

    } else {
        printf("Habilidade de cruz fora dos limites do tabuleiro!\n");
    }

    // verifica se o octaedro está dentro do limite do tabuleiro
    if ((cruzLinhaOrigem + 1 < 10 && cruzLinhaOrigem - 1 >= 0) && (cruzColunaOrigem + 2 < 10 && cruzColunaOrigem - 2 >= 0)) {
        // este loop imprime a habilidade de octaedro no tabuleiro
        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {
                // origem da habilidade (centro)
                if (octaedroLinhaOrigem == octaedroLinhaOrigem + i && octaedroColunaOrigem == octaedroColunaOrigem + j) {
                    tabuleiro[octaedroLinhaOrigem][octaedroColunaOrigem - 1] = octaedro[i][j];
                    tabuleiro[octaedroLinhaOrigem][octaedroColunaOrigem] = octaedro[i][j];
                    tabuleiro[octaedroLinhaOrigem][octaedroColunaOrigem + 1] = octaedro[i][j];
                }
                // top do octaedro
                if (octaedroLinhaOrigem - 1 == octaedroLinhaOrigem - i && octaedroColunaOrigem == octaedroColunaOrigem + j) {
                    tabuleiro[octaedroLinhaOrigem - 1][octaedroColunaOrigem] = octaedro[i][j];
                }
                // base do octaedro
                if (octaedroLinhaOrigem + 1 == octaedroLinhaOrigem + i && octaedroColunaOrigem == octaedroColunaOrigem + j) {
                    tabuleiro[octaedroLinhaOrigem + 1][octaedroColunaOrigem] = octaedro[i][j];
                }
            }

        }

    } else {
        printf("Habilidade de octaedro fora dos limites do tabuleiro!\n");
    }

    // 4. Exibição do tabuleiro do jogo

    if (podePosicionar1 == 1 && podePosicionar2 == 1 && podePosicionar3 == 1 && podePosicionar4 == 1) {

        printf("***** TABULEIRO BATALHA NAVAL *****\n");

        printf("\n"); // Deixa uma linha vazia.

        printf("    "); // Adiciona um espaçamento para alinhar a linha das letras com o tabuleiro.

        // Coloca uma linha de letras no tabuleiro.
        for (char letra = 'A'; letra <= 'J'; letra++) {

            printf("%c ", letra);

        }

        printf("\n"); // Quebra a linha das letras.
        

        // Coloca uma coluna numerada.
        for (int i = 0; i < 10; i++) {

            printf("%2d  ", i + 1);

            for (int j = 0; j < 10; j++) { // Esse loop controla a linha
                printf("%d ", tabuleiro[i][j]);  
            }

            printf("\n"); // Quebra uma linha no fim de cada coluna.
            
        }

    } else {

        printf("Erro: Verifique o posicionamento dos navios!\n");

    }

    return 0;
}
