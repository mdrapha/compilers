#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { 
    nPrograma, 
    nDeclaracaoLista, 
    nDeclaracao, 
    nVarDeclaracao, 
    nTipoEspecificador, 
    nFunDeclaracao, 
    nParams, 
    nParamLista, 
    nParam, 
    nCompostoDecl, 
    nLocalDeclaracoes, 
    nStatementLista, 
    nStatement, 
    nExpressaoDecl, 
    nSelecaoDecl, 
    nIteracaoDecl, 
    nRetornoDecl, 
    nExpressao, 
    nVar, 
    nSimplesExpressao, 
    nRelacional, 
    nSomaExpressao, 
    nTermo, 
    nFator, 
    nAtivacao, 
    nArgs, 
    nArgLista, 
} NodeType;

typedef struct treeNode {
    NodeType nodeType;
    struct treeNode *children[3]; // Ajuste conforme necessário
    char *lexeme;
} TreeNode;

TreeNode *createNode(NodeType type, TreeNode *child1, TreeNode *child2, TreeNode *child3, char *lexeme);
void freeNode(TreeNode *node);
void printNode(TreeNode *node, int level);