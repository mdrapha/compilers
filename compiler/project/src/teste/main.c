#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX_CHILDREN 3
#define BUFFER_SIZE 256
#define MAX_LEXEME_SIZE 64

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

  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_ID = 258,                    /* T_ID  */
    T_NUM = 259,                   /* T_NUM  */
    T_INT = 260,                   /* T_INT  */
    T_VOID = 261,                  /* T_VOID  */
    T_IF = 262,                    /* T_IF  */
    T_ELSE = 263,                  /* T_ELSE  */
    T_WHILE = 264,                 /* T_WHILE  */
    T_RETURN = 265,                /* T_RETURN  */
    T_PLUS = 266,                  /* T_PLUS  */
    T_MINUS = 267,                 /* T_MINUS  */
    T_MULT = 268,                  /* T_MULT  */
    T_DIV = 269,                   /* T_DIV  */
    T_ATRB = 270,                  /* T_ATRB  */
    T_EQ = 271,                    /* T_EQ  */
    T_NEQ = 272,                   /* T_NEQ  */
    T_LT = 273,                    /* T_LT  */
    T_GT = 274,                    /* T_GT  */
    T_LTE = 275,                   /* T_LTE  */
    T_GTE = 276,                   /* T_GTE  */
    T_LPAREN = 277,                /* T_LPAREN  */
    T_RPAREN = 278,                /* T_RPAREN  */
    T_LBRACE = 279,                /* T_LBRACE  */
    T_RBRACE = 280,                /* T_RBRACE  */
    T_LSQBRA = 281,                /* T_LSQBRA  */
    T_RSQBRA = 282,                /* T_RSQBRA  */
    T_SEMI = 283,                  /* T_SEMI  */
    T_COMMA = 284,                 /* T_COMMA  */
    LOWER_THAN_ELSE = 285          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;

typedef struct treeNode {
    yytoken_kind_t type; // The type of the node
    int lineNumber; // The line number where the node was found
    int level; // The level of the node in the parse tree
    NodeType nodeType; // The type of the node
    char lexeme[MAX_LEXEME_SIZE]; // The lexeme of the token
    struct treeNode *children[MAX_CHILDREN]; // Array of pointers to children nodes
    struct treeNode *sibling; // Pointer to the next sibling node
} TreeNode;


/**
 * Creates a new tree node and initializes its fields.
 *
 * @return A pointer to the newly created node.
 */

TreeNode* newNode() {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    node->type = YYUNDEF; // Initialize the type to undefined
    node->lineNumber = -1; // Or another default value
    node->lexeme[0] = '\0'; // Initialize as an empty string
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        node->children[i] = NULL;
    }
    node->sibling = NULL;
    return node;
}



/**
 * Adds a new node as one of the children or as a sibling to the destination node.
 *
 * @param destination A pointer to the pointer of the destination node.
 * @param newNode The new node to be added.
 * @param childIndex The index (0 to 2) of the child where the new node should be added. If this value is outside 0-2, the new node is added as a sibling.
 */
#include <string.h> // For strcpy

void addNode(TreeNode **destination, TreeNode *newNode, int childIndex) {
    if (destination == NULL || newNode == NULL) return;

    if (*destination == NULL) {
        *destination = newNode;
    } else if (childIndex >= 0 && childIndex < MAX_CHILDREN) {
        // Add as one of the children of the destination node
        if ((*destination)->children[childIndex] == NULL) {
            (*destination)->children[childIndex] = newNode;
        } else {
            fprintf(stderr, "Child at index %d already exists\n", childIndex);
        }
    } else {
        // Add as a sibling of the destination node
        TreeNode *current = *destination;
        while (current->sibling != NULL) {
            current = current->sibling;
        }
        current->sibling = newNode;
    }

}


/**
 * Frees the memory allocated for the tree nodes.
 * 
 * @param node The root node of the tree or subtree to be freed.
 */
void freeTree(TreeNode *node) {
    if (node == NULL) return;

    // First, free the memory allocated for each child node
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        freeTree(node->children[i]);
    }

    // Then free the memory allocated for the sibling node
    freeTree(node->sibling);

    // Finally, free the memory allocated for the node itself
    free(node);
}


/**
 * Prints the lexeme of a tree node if it exists.
 *
 * @param node Pointer to the node whose lexeme is to be printed.
 */
void printLexeme(TreeNode *node) {
    if (node->lexeme[0] != '\0') { // Verifica se o lexema não é uma string vazia
        printf(" (Lexeme: %s)", node->lexeme);
    }
}


/**
 * Retrieves the string representation of a node type.
 *
 * @param type NodeType enum value representing the type of a node.
 * @return The string representation of the node type.
 */
const char* getNodeTypeName(NodeType type) {
    switch (type) {
        case nPrograma: return "Program";
        case nDeclaracaoLista: return "Declaration List";
        case nVarDeclaracao: return "Variable Declaration";
        case nTipoEspecificador: return "Type Specifier";
        case nFunDeclaracao: return "Function Declaration";
        case nParams: return "Parameters";
        case nParamLista: return "Parameter List";
        case nParam: return "Parameter";
        case nCompostoDecl: return "Compound Declaration";
        case nLocalDeclaracoes: return "Local Declarations";
        case nStatementLista: return "Statement List";
        case nStatement: return "Statement";
        case nExpressaoDecl: return "Expression Declaration";
        case nSelecaoDecl: return "Selection Declaration";
        case nIteracaoDecl: return "Iteration Declaration";
        case nRetornoDecl: return "Return Declaration";
        case nExpressao: return "Expression";
        case nVar: return "Variable";
        case nSimplesExpressao: return "Simple Expression";
        case nRelacional: return "Relational Operator";
        case nSomaExpressao: return "Additive Expression";
        case nTermo: return "Term";
        case nFator: return "Factor";
        case nAtivacao: return "Activation";
        case nArgs: return "Arguments";
        case nArgLista: return "Argument List";
        default: return "Unknown";
    }
}

/**
 * Prints the tree structure starting from the given node at the given level.
 * It uses indentation to signify the hierarchy of nodes and marks the last
 * sibling node with a different connector.
 *
 * @param node Pointer to the current node to print.
 * @param level Current level of depth in the tree.
 * @param isLast Flag indicating if the node is the last child of its parent.
 */
void printTree(TreeNode *node, int level, bool isLast) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    
    if (level > 0 && isLast) {
        printf("\\-");
    } else if (level > 0) {
        printf("|-");
    }

    printf("%s: %s\n", getNodeTypeName(node->nodeType), node->lexeme);

    // Imprime todos os filhos exceto o último com a marca de que não são os últimos
    for (int i = 0; i < 3 && node->children[i] != NULL; ++i) {
        printTree(node->children[i], level + 1, node->children[i+1] == NULL);
    }

    // Irmãos devem ser impressos no mesmo nível e não como último, então passamos FALSE
    if (node->sibling) {
        printTree(node->sibling, level, FALSE);
    }
}

/**
 * Sets the level of each node in the tree, starting from a given node.
 * 
 * @param node The root node of the tree or subtree.
 * @param level The current level in the tree to be set for the node.
 */
void setNodeLevels(TreeNode *node, int level) {
    if (node == NULL) return;

    // Set the level of the current node.
    node->level = level; // Assuming 'level' is a valid field in TreeNode

    // Recursively set the level for each child node, increasing the level by 1.
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        setNodeLevels(node->children[i], level + 1);
    }

    // Recursively set the level for the sibling of the current node.
    setNodeLevels(node->sibling, level);
}




int main() {
    // Criar raiz da árvore
    TreeNode *root = newNode();
    root->nodeType = nPrograma;
    strcpy(root->lexeme, "RootProgram");

    // Criar nós filhos
    TreeNode *child1 = newNode();
    child1->nodeType = nVarDeclaracao;
    strcpy(child1->lexeme, "intVar");
    addNode(&root, child1, 0);

    TreeNode *child2 = newNode();
    child2->nodeType = nFunDeclaracao;
    strcpy(child2->lexeme, "myFunction");
    addNode(&root, child2, 1);

    // Adicionar irmãos para child1
    TreeNode *sibling1 = newNode();
    sibling1->nodeType = nVarDeclaracao;
    strcpy(sibling1->lexeme, "floatVar");
    addNode(&child1, sibling1, -1); // -1 para adicionar como irmão

    TreeNode *sibling2 = newNode();
    sibling2->nodeType = nVarDeclaracao;
    strcpy(sibling2->lexeme, "charVar");
    addNode(&child1, sibling2, -1); // Adicionar como irmão de child1

    // Adicionar filhos para child2 (Função)
    TreeNode *funcChild1 = newNode();
    funcChild1->nodeType = nParams;
    strcpy(funcChild1->lexeme, "Params");
    addNode(&child2, funcChild1, 0);

    TreeNode *funcChild2 = newNode();
    funcChild2->nodeType = nCompostoDecl;
    strcpy(funcChild2->lexeme, "Body");
    addNode(&child2, funcChild2, 1);

    // Adicionar filhos para funcChild2 (Corpo da função)
    TreeNode *statement1 = newNode();
    statement1->nodeType = nStatement;
    strcpy(statement1->lexeme, "Statement1");
    addNode(&funcChild2, statement1, 0);

    TreeNode *statement2 = newNode();
    statement2->nodeType = nStatement;
    strcpy(statement2->lexeme, "Statement2");
    addNode(&funcChild2, statement2, 1);

    // Definir níveis e imprimir a árvore
    setNodeLevels(root, 0);
    printTree(root, 0, TRUE);

    // Liberar a memória da árvore
    freeTree(root);
    return 0;
}
