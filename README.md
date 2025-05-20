# Árvore AVL - Trabalho de Grafos

Este projeto se trata da construção de um código de uma árvore AVL com todas sua funcionalidades, além da criação de um arquivo .json para consulmo de outrso projetos. Feito como atividade para a matéria de Introdução a Grafos ministrada pelo professor [https://github.com/emmanuelXavier](Emmanuel Xavier) na graduação de Ciência da Computação no Instituto Federal de Educação, Ciência e Tecnologia do Maranhão - Campus Imperatriz (IFMA).

## Setup

É necessário que tenha instalado em sua máquina algu compilador C, utilizamos preferêncialmente o GCC tanto para Windown como para Linux.

**Clone do repositório**
Clone Repositório
```sh
git clone https://github.com/NathanAlbuquerque/avl-tree.git
```

**Compilação**
```sh
gcc main.c avl_Tree.c -o output/main.exe
```

## Descrição das funções:

Atualizar o campo fb (fator de balanceamento).
Detectar desbalanceamento após inserção.
Fazer as 4 rotações AVL:
Rotação simples à direita (LL)
Rotação simples à esquerda (RR)
Rotação dupla à direita (LR)
Rotação dupla à esquerda (RL)