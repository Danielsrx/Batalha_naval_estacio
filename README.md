🚢 **Batalha Naval - Desafio Completo em C**

Este meu projeto acadêmico implementa um tabuleiro de Batalha Naval em C, construído em três estágios de complexidade (Novato, Aventureiro e Mestre).

O programa cria um tabuleiro 10x10, posiciona quatro navios com diferentes orientações (horizontal, vertical e diagonais) e, por fim, demonstra um sistema de habilidades especiais (Cone, Cruz e Octaedro), calculando e sobrepondo suas áreas de efeito no tabuleiro final.

🎯 **Funcionalidades Implementadas**

O código batalha_naval_completo.c inclui todas as funcionalidades dos três níveis:

Tabuleiro 10x10: O jogo é baseado em uma matriz (array bidimensional) 10x10, inicializada com AGUA.

Posicionamento de 4 Navios:

Navios Retos: 1 navio horizontal e 1 vertical (Nível Novato).

Navios Diagonais: 2 navios diagonais (\ e /) (Nível Aventureiro).

Validação Robusta de Posição: O script verifica se os navios estão dentro dos limites (0-9) do tabuleiro e se não há sobreposição com navios já posicionados.

Habilidades Especiais Dinâmicas:

Cria "moldes" 5x5 para 3 habilidades (Cone, Cruz, Octaedro) usando loops aninhados e condicionais, sem "hardcoding" da forma (Nível Mestre).

Lógica de Sobreposição (Overlay): O programa calcula como as áreas de efeito das habilidades se sobrepõem ao tabuleiro principal de 10x10, marcando as células afetadas, mesmo que a origem seja perto da borda.

Visualização Clara: A saída final no console usa caracteres distintos para representar cada elemento, facilitando a visualização:

"~" : Água

"N" : Navio

"#" : Área de Efeito de Habilidade

🖥️ **Exemplo de Saída Final**

O resultado final do programa é o tabuleiro 10x10 com todos os navios posicionados e as áreas de habilidade sobrepostas.

=== TABULEIRO FINAL - BATALHA NAVAL MESTRE ===

Legenda: [~] Agua  [N] Navio  [#] Habilidade

🚀 **Como Compilar e Executar**

Este programa foi escrito em C padrão e pode ser compilado com gcc (GNU C Compiler) ou qualquer compilador C compatível.

Clone o Repositório (Se você já tem os arquivos, pule esta etapa.)

Abra o Terminal Navegue até a pasta onde o arquivo batalha_naval_completo.c está localizado.

Compile o Programa Execute o seguinte comando no seu terminal para compilar o código. Isso criará um arquivo executável chamado batalha_naval.

Bash

gcc batalha_naval_completo.c -o batalha_naval

Execute o Programa Após a compilação, execute o programa:

No Linux ou macOS:

Bash

./batalha_naval

No Windows:

Bash

batalha_naval.exe

O programa não requer nenhuma entrada do usuário; ele executará todos os passos e imprimirá o tabuleiro final automaticamente.

🔧 **Lógica do Código**

Para atender aos requisitos dos desafios, o código foi estruturado da seguinte forma:

1. Posicionamento de Navios (Níveis Novato e Aventureiro)

Cada navio tem suas coordenadas iniciais definidas.

Uma flag (variável posicao_valida) é usada para rastrear se o posicionamento é legal.

Validação de Limites: O programa primeiro verifica se a posição final do navio (coordenada_inicial + TAMANHO_NAVIO) excede os limites do tabuleiro (0-9).

Validação de Sobreposição: Se estiver dentro dos limites, um segundo loop varre as células-alvo no tabuleiro. Se qualquer célula-alvo já for NAVIO, a flag é desativada e o navio não é posicionado.

2. Criação das Habilidades (Nível Mestre)

As matrizes de habilidade 5x5 são geradas dinamicamente usando lógica condicional, com base na posição do centro (int centro = 2):

Cone: A área é ativada se a coluna (j) estiver dentro do "alcance" da linha (i). A fórmula j >= centro - i && j <= centro + i cria um triângulo que se expande para baixo.

Cruz: A área é ativada se a célula estiver na linha central (i == centro) OU na coluna central (j == centro).

Octaedro (Losango): A área é ativada usando a "Distância de Manhattan" do centro. A fórmula abs(i - centro) + abs(j - centro) <= centro cria um formato de losango perfeito.

3. Sobreposição das Habilidades (Nível Mestre)

Para cada habilidade, um ponto de origem (ex: cruz_orig_L, cruz_orig_C) é definido no tabuleiro 10x10.

O programa percorre a matriz da habilidade 5x5.

Para cada célula [i][j] ativada na habilidade, ele calcula a coordenada-alvo no tabuleiro 10x10.

O cálculo target_L = cruz_orig_L + (i - centro) faz o "mapeamento", garantindo que o centro da habilidade pouse na origem definida no tabuleiro.

Uma verificação final de limites garante que a habilidade não tente escrever fora da matriz 10x10 (ex: target_L >= 0 && target_L < 10).

*Feito por: Daniel Rodrigues.*
