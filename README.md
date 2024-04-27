#          <p align="center">GAME WITH MINILIBX</p>
<div align = center>
  <img src="https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExa2MwcHNoYzEweHRyNDhtZzdkaHpyN3BzYmw4OXJicmx4cnczYTh2YSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/RARktcGlEpOnv9nMhc/source.gif">
</div>

# So_long

So_long é um mini jogo desenvolvido em C usando a biblioteca gráfica minilibx. O jogo consiste em um labirinto onde o jogador deve coletar todos os itens colecionáveis (C) e chegar à saída (E) para vencer. No entanto, se o jogador for pego por um inimigo (black hole), o jogo termina.

## Funcionalidades

O projeto So_long utiliza as seguintes funcionalidades:

- Minilibx: Biblioteca gráfica utilizada para renderizar gráficos na tela.
- Makefile: Arquivo de script utilizado para compilar o código fonte e criar o executável do jogo.
- Arquivo de mapa (.ber): Contém uma matriz retangular que define o layout do labirinto, onde os caracteres representam diferentes elementos do jogo:
  - `1`: Paredes, que bloqueiam o movimento do jogador.
  - `0`: Espaços vazios onde o jogador pode transitar.
  - `C`: Itens colecionáveis que o jogador precisa coletar.
  - `P`: Jogador, que é controlado pelo usuário.
  - `E`: Saída, que o jogador deve alcançar para vencer.
  - `B`: Inimigos (black holes), que terminam o jogo se o jogador entrar em contato com eles.

## Compilando e Executando

Para compilar o projeto, você precisa primeiro baixar e compilar a biblioteca minilibx. Você pode fazer isso executando o comando `make minilibx` no terminal no diretório do projeto.

Após compilar a minilibx, você pode compilar o jogo executando o comando `make`. Isso irá criar o executável `so_long`.

Para jogar, você pode executar o jogo passando o arquivo de mapa como argumento:

```bash
./so_long [mapa.ber]
```
Substitua [mapa.ber] pelo caminho para o arquivo de mapa que deseja usar.
