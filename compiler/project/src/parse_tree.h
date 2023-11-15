/*Enum for the different types of nodes in the parse tree.*/
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
    NodeType nodeType; // The type of the node.
    struct treeNode *children[3]; // Array of pointers to child nodes.
    char *lexeme; // Used only for nVar and nFator nodes.
} TreeNode;

/*Function for create a node to the parse tree*/
TreeNode *createNode(NodeType type, TreeNode *child1, TreeNode *child2, TreeNode *child3, char *lexeme);
// Function for free the memory allocated for a node and its children.
void freeNode(TreeNode *node);

// Function for printing the parse tree in a human-readable format.
void printNode(TreeNode *node, int level);