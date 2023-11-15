#include "globals.h"


TreeNode *createNode(NodeType type, TreeNode *child1, TreeNode *child2, TreeNode *child3, char *lexeme) {
    TreeNode *node = malloc(sizeof(TreeNode)); // Allocate memory for the node
    if (node) { // If the allocation succeeds, initialize the node
        *node = (TreeNode){
            .nodeType = type,
            .children = {child1, child2, child3},
            .lexeme = lexeme ? strdup(lexeme) : NULL
        };
    }
    return node;
}

void freeNode(TreeNode *node) {
    // If the node is NULL, there is nothing to free, so return immediately.
    if (node == NULL) return;
    
    // If node->lexeme was dynamically allocated (e.g., with strdup),
    // then it needs to be freed. Otherwise, this line should be omitted.
    free(node->lexeme);

    // Recursively free all the child nodes of the current node.
    for (int i = 0; i < 3; ++i) {
        freeNode(node->children[i]);
    }

    // Free the node itself. After freeing, setting the pointer to NULL
    // is a good practice to avoid dangling pointer issues.
    free(node);
    node = NULL; // This only sets the local copy to NULL.
}


void printTree(TreeNode *node, int level) {
    if (node == NULL) return;
    
    // Print the current node with indentation based on its level in the tree.
    for (int i = 0; i < level; ++i) printf("  ");
    switch (node->nodeType) {
        case nPrograma: printf("Program\n"); break;
        case nDeclaracaoLista: printf("Declaration List\n"); break;
        case nVarDeclaracao: printf("Variable Declaration\n"); break;
        case nTipoEspecificador: printf("Type Specifier: %s\n", node->lexeme); break;
        case nFunDeclaracao: printf("Function Declaration\n"); break;
        case nParams: printf("Parameters\n"); break;
        case nParamLista: printf("Parameter List\n"); break;
        case nParam: printf("Parameter\n"); break;
        case nCompostoDecl: printf("Compound Declaration\n"); break;
        case nLocalDeclaracoes: printf("Local Declarations\n"); break;
        case nStatementLista: printf("Statement List\n"); break;
        case nStatement: printf("Statement\n"); break;
        case nExpressaoDecl: printf("Expression Declaration\n"); break;
        case nSelecaoDecl: printf("Selection Declaration\n"); break;
        case nIteracaoDecl: printf("Iteration Declaration\n"); break;
        case nRetornoDecl: printf("Return Declaration\n"); break;
        case nExpressao: printf("Expression\n"); break;
        case nVar: printf("Variable: %s\n", node->lexeme); break;
        case nSimplesExpressao: printf("Simple Expression\n"); break;
        case nRelacional: printf("Relational Operator: %s\n", node->lexeme); break;
        case nSomaExpressao: printf("Additive Expression\n"); break;
        case nTermo: printf("Term\n"); break;
        case nFator: printf("Factor: %s\n", node->lexeme); break;
        case nAtivacao: printf("Activation: %s\n", node->lexeme); break;
        case nArgs: printf("Arguments\n"); break;
        case nArgLista: printf("Argument List\n"); break;
        default: printf("Unknown Node Type\n"); break;
    }

    // Recursively print each child node, increasing the level of indentation.
    for (int i = 0; i < 3; ++i) {
        printTree(node->children[i], level + 1);
    }
}
