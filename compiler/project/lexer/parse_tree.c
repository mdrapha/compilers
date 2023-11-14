#include "parse_tree.h"


TreeNode *createNode(NodeType type, TreeNode *child1, TreeNode *child2, TreeNode *child3, char *lexeme) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->nodeType = type;
    node->children[0] = child1;
    node->children[1] = child2;
    node->children[2] = child3;
    node->lexeme = lexeme ? strdup(lexeme) : NULL;
    return node;
}

void freeNode(TreeNode *node) {
    if (node == NULL) return;
    free(node->lexeme);
    for (int i = 0; i < 3; ++i) {
        if (node->children[i]) {
            freeNode(node->children[i]);
        }
    }
    free(node);
}

void printNode(TreeNode *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; ++i) printf("  ");
    switch (node->nodeType) {
        case nPrograma: printf("Programa\n"); break;
        case nDeclaracaoLista: printf("Lista de Declaração\n"); break;
        case nVarDeclaracao: printf("Declaração de Variável\n"); break;
        case nTipoEspecificador: printf("Especificador de Tipo: %s\n", node->lexeme); break;
        case nFunDeclaracao: printf("Declaração de Função\n"); break;
        case nParams: printf("Parâmetros\n"); break;
        case nParamLista: printf("Lista de Parâmetros\n"); break;
        case nParam: printf("Parâmetro\n"); break;
        case nCompostoDecl: printf("Declaração Composta\n"); break;
        case nLocalDeclaracoes: printf("Declarações Locais\n"); break;
        case nStatementLista: printf("Lista de Statements\n"); break;
        case nStatement: printf("Statement\n"); break;
        case nExpressaoDecl: printf("Declaração de Expressão\n"); break;
        case nSelecaoDecl: printf("Declaração de Seleção\n"); break;
        case nIteracaoDecl: printf("Declaração de Iteração\n"); break;
        case nRetornoDecl: printf("Declaração de Retorno\n"); break;
        case nExpressao: printf("Expressão\n"); break;
        case nVar: printf("Variável: %s\n", node->lexeme); break;
        case nSimplesExpressao: printf("Expressão Simples\n"); break;
        case nRelacional: printf("Operador Relacional: %s\n", node->lexeme); break;
        case nSomaExpressao: printf("Expressão de Soma\n"); break;
        case nTermo: printf("Termo\n"); break;
        case nFator: printf("Fator: %s\n", node->lexeme); break;
        case nAtivacao: printf("Ativação: %s\n", node->lexeme); break;
        case nArgs: printf("Argumentos\n"); break;
        case nArgLista: printf("Lista de Argumentos\n"); break;
        default: printf("Tipo de Nó Desconhecido\n"); break;
    }
    for (int i = 0; i < 3; ++i) {
        printNode(node->children[i], level + 1);
    }
}