/*
 * O Jogo de Batalha Naval - Desafio Completo (Níveis Novato, Aventureiro e Mestre)
 * Este código implementa todas as funcionalidades pedidas nas atividades:
 * 1. Cria um tabuleiro 10x10 e o inicializa.
 * 2. Posiciona 4 navios (2 retos, 2 diagonais) com validação.
 * 3. Cria 3 matrizes de habilidade (Cone, Cruz, Octaedro) dinamicamente.
 * 4. Sobrepõe essas habilidades no tabuleiro principal.
 * 5. Exibe o resultado final com caracteres distintos.
 */

// A biblioteca principal, para printf
#include <stdio.h>
#include <stdlib.h> // Vou usar abs() para o Octaedro

// Definições globais do meu jogo, pra facilitar a vida
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)

// Valores que vou usar no tabuleiro (Nível Mestre pede valores diferentes)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5 // Novo valor para a área de efeito

/*
 * Função principal do meu programa
 */
int main() {

    // --- Parte 1: Inicialização do Tabuleiro (Nível Novato) ---

    // Meu tabuleiro principal! 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Variáveis de controle para meus loops (i, j para tabuleiro, k para navios)
    int i, j, k;

    // Vou zerar o tabuleiro. Preciso garantir que tudo é AGUA (0) antes de começar.
    // Meu primeiro loop, o 'i', vai passar pelas linhas
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        // O 'j' passa pelas colunas
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- Parte 2: Posicionando os 4 Navios (Nível Novato + Aventureiro) ---

    // Um "molde" pro navio, como foi sugerido no desafio.
    // Assim, eu só copio o valor 'NAVIO' (3)
    int navio_material[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    
    // Variável para checar se a posição é válida (1 = sim, 0 = não)
    int posicao_valida;

    
    // --- Navio 1: Horizontal (Nível Novato) ---
    int n1_linha = 1;
    int n1_coluna = 1;
    posicao_valida = 1; // Começo assumindo que é válida

    // 1. Validação de Limites: Checar se não sai pra fora (horizontal)
    if (n1_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("AVISO: Navio 1 (Horizontal) fora dos limites.\n");
        posicao_valida = 0;
    }

    // Se passou no teste, bora colocar no tabuleiro
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // A linha é fixa, a coluna que anda
            tabuleiro[n1_linha][n1_coluna + k] = navio_material[k];
        }
    }

    
    // --- Navio 2: Vertical (Nível Novato) ---
    int n2_linha = 3;
    int n2_coluna = 8;
    posicao_valida = 1;

    // 1. Validação de Limites: Checar se não sai pra fora (vertical)
    if (n2_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("AVISO: Navio 2 (Vertical) fora dos limites.\n");
        posicao_valida = 0;
    }

    // 2. Validação de Sobreposição: Checar se já não tem um navio ali
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // A coluna é fixa, a linha que anda
            if (tabuleiro[n2_linha + k][n2_coluna] == NAVIO) {
                printf("AVISO: Navio 2 (Vertical) sobrepondo outro.\n");
                posicao_valida = 0;
                break; // Se já achei um erro, paro de checar
            }
        }
    }

    // Se passou nos DOIS testes, coloco no tabuleiro
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            tabuleiro[n2_linha + k][n2_coluna] = navio_material[k];
        }
    }

    
    // --- Navio 3: Diagonal \ (Nível Aventureiro) ---
    int n3_linha = 4;
    int n3_coluna = 1;
    posicao_valida = 1;

    // 1. Validação de Limites: Diagonal precisa checar linha E coluna!
    if (n3_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || n3_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("AVISO: Navio 3 (Diagonal \\) fora dos limites.\n");
        posicao_valida = 0;
    }

    // 2. Validação de Sobreposição
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // Linha e coluna andam juntas
            if (tabuleiro[n3_linha + k][n3_coluna + k] == NAVIO) {
                printf("AVISO: Navio 3 (Diagonal \\) sobrepondo outro.\n");
                posicao_valida = 0;
                break;
            }
        }
    }

    // Se passou nos testes, coloco no tabuleiro
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            tabuleiro[n3_linha + k][n3_coluna + k] = navio_material[k];
        }
    }

    
    // --- Navio 4: Diagonal / (Nível Aventureiro) ---
    // Essa é uma diagonal "pra cima e direita" (ou "baixo e esquerda")
    // Vou fazer "baixo e esquerda"
    int n4_linha = 6;
    int n4_coluna = 4;
    posicao_valida = 1;

    // 1. Validação de Limites: Checar linha (baixo) e coluna (esquerda)
    if (n4_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || n4_coluna - (TAMANHO_NAVIO - 1) < 0) {
        printf("AVISO: Navio 4 (Diagonal /) fora dos limites.\n");
        posicao_valida = 0;
    }

    // 2. Validação de Sobreposição
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // Linha aumenta, coluna diminui
            if (tabuleiro[n4_linha + k][n4_coluna - k] == NAVIO) {
                printf("AVISO: Navio 4 (Diagonal /) sobrepondo outro.\n");
                posicao_valida = 0;
                break;
            }
        }
    }

    // Se passou nos testes, coloco no tabuleiro
    if (posicao_valida == 1) {
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            tabuleiro[n4_linha + k][n4_coluna - k] = navio_material[k];
        }
    }


    // --- Parte 3: Habilidades Especiais (Nível Mestre) ---

    // --- 3a. Criar os "Moldes" 5x5 das Habilidades ---
    // O desafio pede pra criar dinamicamente com loops e condicionais

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    // O centro da minha matriz 5x5 é a posição 2 (pois 5 / 2 = 2 em int)
    int centro = TAMANHO_HABILIDADE / 2;
    int dist_manhattan; // Pra calcular o octaedro

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Lógica do Cone (pontudo em cima, topo em [0][centro])
            // Basicamente, a largura (j) depende da altura (i)
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            }

            // Lógica da Cruz (acerta a linha do centro OU a coluna do centro)
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }

            // Lógica do Octaedro (Losango)
            // Vou usar a "Distância de Manhattan" do centro
            dist_manhattan = abs(i - centro) + abs(j - centro);
            if (dist_manhattan <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // --- 3b. Sobrepor os Moldes no Tabuleiro Principal ---

    int target_L, target_C; // Coordenadas no tabuleiro 10x10

    // --- Sobrepondo o CONE ---
    // O ponto de origem (topo do cone) no tabuleiro
    int cone_orig_L = 0;
    int cone_orig_C = 4;
    
    // Loop pelo molde 5x5
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Se essa parte do molde é 1 (afeta)
            if (cone[i][j] == 1) {
                // Mapeio as coords do molde (i,j) para o tabuleiro (target_L, target_C)
                // O topo do cone (i=0) fica na origem (cone_orig_L)
                // O centro do cone (j=centro) fica na origem (cone_orig_C)
                target_L = cone_orig_L + i;
                target_C = cone_orig_C + (j - centro);

                // SUPER IMPORTANTE: Garantir que a habilidade não "vaze" pra fora do 10x10
                if (target_L >= 0 && target_L < TAMANHO_TABULEIRO && target_C >= 0 && target_C < TAMANHO_TABULEIRO) {
                    // Marca no tabuleiro principal
                    tabuleiro[target_L][target_C] = HABILIDADE;
                }
            }
        }
    }

    // --- Sobrepondo a CRUZ ---
    // O ponto de origem (centro da cruz) no tabuleiro
    int cruz_orig_L = 7;
    int cruz_orig_C = 7;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                // Mapeamento para uma habilidade centrada
                // O centro do molde (i=centro) fica na origem (cruz_orig_L)
                target_L = cruz_orig_L + (i - centro);
                target_C = cruz_orig_C + (j - centro);
                
                // Validação de limites
                if (target_L >= 0 && target_L < TAMANHO_TABULEIRO && target_C >= 0 && target_C < TAMANHO_TABULEIRO) {
                    tabuleiro[target_L][target_C] = HABILIDADE;
                }
            }
        }
    }

    // --- Sobrepondo o OCTAEDRO (LOSANGO) ---
    // O ponto de origem (centro do losango) no tabuleiro
    int octa_orig_L = 7;
    int octa_orig_C = 2;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                // Mesma lógica de mapeamento centrado da Cruz
                target_L = octa_orig_L + (i - centro);
                target_C = octa_orig_C + (j - centro);
                
                // Validação de limites
                if (target_L >= 0 && target_L < TAMANHO_TABULEIRO && target_C >= 0 && target_C < TAMANHO_TABULEIRO) {
                    tabuleiro[target_L][target_C] = HABILIDADE;
                }
            }
        }
    }


    // --- Parte 4: Exibição Final (Nível Mestre) ---
    // O desafio pede para usar caracteres diferentes
    
    printf("\n=== TABULEIRO FINAL - BATALHA NAVAL MESTRE ===\n\n");
    printf("Legenda: [~] Agua  [N] Navio  [#] Habilidade\n\n");

    // Imprimir o cabeçalho das colunas (0 1 2 3...)
    printf("  "); // Espaço para alinhar com as linhas
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n"); // Pula linha

    // Loop principal de exibição
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Imprimir o cabeçalho da linha (0, 1, 2...)
        printf("%d ", i);

        // Agora, imprimir o conteúdo da célula
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Pego o valor que está na célula
            int valor_celula = tabuleiro[i][j];

            // Decido qual caractere vou imprimir
            if (valor_celula == HABILIDADE) {
                printf("# "); // Área de Habilidade
            } else if (valor_celula == NAVIO) {
                printf("N "); // Navio
            } else {
                printf("~ "); // Água
            }
        }
        // Terminou a linha, pula pra próxima
        printf("\n");
    }

    return 0; // Terminei!
}