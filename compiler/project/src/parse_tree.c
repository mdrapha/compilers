#include "globals.h"



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

char *get_id_from_stack(){
    if (idStackIndex > 0) {
        return idStack[idStackIndex - 1];
    } else {
        return NULL;
    }
}

void put_id_in_stack(char *id){
    if (idStackIndex < MAX_ID_STACK_SIZE) {
        strcpy(idStack[idStackIndex], id);
        idStackIndex++;
    } else {
        printf("Error: idStack is full\n");
        exit(1);
    }
}

int get_num_from_stack(){
    if (numStackIndex > 0) {
        return *numStack[numStackIndex - 1];
    } else {
        return -1;
    }
}

void put_num_in_stack(int num){
    if (numStackIndex < MAX_ID_STACK_SIZE) {
        *numStack[numStackIndex] = num;
        numStackIndex++;
    } else {
        printf("Error: numStack is full\n");
        exit(1);
    }
}