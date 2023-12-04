/**
 * @file parse_tree.c
 * @brief Implementation file for the parse tree functions.
 *
 * This file contains the implementation of functions related to the creation, manipulation, and printing of a parse tree.
 * The parse tree is represented using a TreeNode structure, which contains fields for the node type, variable type, line number, lexeme, children, and sibling.
 * The functions in this file include creating a new tree node, adding a node as a child or sibling, freeing the memory allocated for the tree nodes, printing the lexeme of a node, retrieving the string representation of a node type, printing the tree structure, setting the level of each node in the tree, and analyzing the nodes to determine the variable type.
 */
#include "../include/globals.h"
#include <string.h> 


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
    node->varType = YYUNDEF; // Initialize the variable type to undefined
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
void addNode(TreeNode **destination, TreeNode *newNode, int childIndex) {
    if (destination == NULL || newNode == NULL){ 
        return;
    }

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
        case nVarArrDecl: return "Array Variable Declaration";
        case nTipoEspecificador: return "Type Specifier";
        case nFunDeclaracao: return "Function Declaration";
        case nFunCall: return "Function Call";
        case nParams: return "Parameters";
        case nParamLista: return "Parameter List";
        case nParam: return "Parameter";
        case nCompostoDecl: return "Compound Declaration";
        case nLocalDeclaracoes: return "Local Declarations";
        case nStatementLista: return "Statement List";
        case nStatement: return "Statement";
        case nAtrb: return "Attribution";
        case nExpressaoDecl: return "Expression Declaration";
        case nSelecaoDecl: return "Selection Declaration";
        case nIteracaoDecl: return "Iteration Declaration";
        case nRetornoDecl: return "Return Declaration";
        case nExpressao: return "Expression";
        case nVar: return "Variable";
        case nVarArr: return "Array Variable";
        case nValue: return "Value";
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
        //Setting printf color to light blue
        printf("\033[1;32m");
        printf("\\-");
        printf("\033[0m");
    } else if (level > 0) {
        //Setting printf color to light green
        printf("\033[1;32m");
        printf("|-");
        printf("\033[0m");
    }
    //Setting printf color to blue
    printf("\033[1;34m");
    printf("%s: ", getNodeTypeName(node->nodeType));
    printf("\033[0m");

    printf("%s\n", node->lexeme);

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

/**
 * Retrieves the identifier from the stack.
 *
 * @return The identifier from the stack.
 */
char *get_id_from_stack(){
    if (idStackIndex > 0 && idStack[idStackIndex - 1] != NULL) {
        return idStack[idStackIndex - 1];
    } else {
        return NULL;
    }
}

/**
 * Puts the identifier in the stack.
 *
 * @param id The identifier to be put in the stack.
 */
void put_id_in_stack(char *id){
    if (idStackIndex < MAX_ID_STACK_SIZE) {
        strcpy(idStack[idStackIndex], id);
        idStackIndex++;
    } else {
        printf("Error: idStack is full\n");
        exit(1);
    }
}

/**
 * Retrieves the number from the stack.
 *
 * @return The number from the stack.
 */
int get_num_from_stack() {
    if (numStackIndex < 0) {
        printf("ERROR: Stack is empty\n");
        return -1;
    }

    return *numStack[numStackIndex - 1];
}

/**
 * Puts the number in the stack.
 *
 * @param num The number to be put in the stack.
 */
void put_num_in_stack(int num){
    if (numStackIndex < MAX_ID_STACK_SIZE) {
        *numStack[numStackIndex] = num;
        numStackIndex++;
    } else {
        printf("Error: numStack is full\n");
        exit(1);
    }
}

/**
 * Prints the identifier stack.
 */
void print_id_stack(){
    if (idStackIndex < 0 || idStackIndex > 1024) {
        fprintf(stderr, "Error: invalid idStackIndex %d\n", idStackIndex);
        exit(1);
    }

    printf("idStack: ");
    for (int i = 0; i < idStackIndex; ++i) {
        if (idStack[i] == NULL) {
            fprintf(stderr, "Error: invalid idStack[%d]\n", i);
            exit(1);
        }
        printf("%s ", idStack[i]);
    }
    printf("\n");
}
/**
 * @brief Analyses the nodes of a parse tree and updates the varType of T_ID nodes based on the currentType.
 * 
 * This function recursively traverses the parse tree starting from the given node. It updates the varType of T_ID nodes
 * to the currentType if the currentType is T_INT or T_VOID. The currentType is updated if the node's type is T_INT or T_VOID.
 * 
 * @param node The root node of the parse tree.
 * @param parentType The type of the parent node.
 */

void analyzeNodes(TreeNode *node, yytoken_kind_t parentType) {
    if (node == NULL) return;

    //printf("Analyzing node %s %s\n", node->lexeme,getNodeTypeName(node->nodeType));

    //If a nodeType == nFunDeclaracao; print his children, siblings and his last sibling
    if(node->nodeType == nFunDeclaracao){
        //printf("Node %s %s has children: ", node->lexeme,getNodeTypeName(node->nodeType));
        for (int i = 0; i < MAX_CHILDREN; ++i) {
            if(node->children[i] != NULL){
                //printf("%s %s, ", node->children[i]->lexeme,getNodeTypeName(node->children[i]->nodeType));
            }
        }
        //printf("and siblings: ");
        if(node->sibling != NULL){
            printf("%s %s, ", node->sibling->lexeme,getNodeTypeName(node->sibling->nodeType));
        }
        if(node->children[2] != NULL){
            printf("%s %s\n", node->children[2]->lexeme,getNodeTypeName(node->children[2]->nodeType));
        }
    }

    yytoken_kind_t currentType = parentType;
    if (node->type == T_INT || node->type == T_VOID) {
        currentType = node->type; // Atualiza o tipo atual se o nó for T_INT ou T_VOID
    }

    if ((node->type == T_ID || node->nodeType==nFunDeclaracao) && (currentType == T_INT || currentType == T_VOID) ) {
        node->varType = currentType; // Define o varType para T_INT ou T_VOID se o nó atual for T_ID
        //printf("Setting of %s varType of T_ID node to %s\n",node->lexeme ,get_token_name(currentType));
    }

    // Chama a função recursivamente para cada filho
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        analyzeNodes(node->children[i], currentType);
    }

    // Chama a função recursivamente para o irmão, mas mantém o parentType original
    analyzeNodes(node->sibling, parentType);
}

void printFunDeclaracaoDetails(TreeNode *root, TreeNode *previousSibling) {
    if (root == NULL) return;

    // Verifica se o type do nó é T_INT ou T_VOID e imprime detalhes
    if (root->type == T_INT || root->type == T_VOID) {
        printf("Node Type: %s\n", (root->type == T_INT) ? "int" : "void");
        printf("Lexeme: %s\n", root->lexeme);
        printf("Line Number: %d\n", root->lineNumber);

        // Imprime os filhos do nó
        printf("Children:\n");
        for (int i = 0; i < MAX_CHILDREN; ++i) {
            if (root->children[i] != NULL) {
                printf("  Child %d: %s\n", i, root->children[i]->lexeme);
            }
        }

        // Imprime os irmãos do nó
        printf("Siblings:\n");
        TreeNode *sibling = root->sibling;
        while (sibling != NULL) {
            printf("  Sibling: %s\n", sibling->lexeme);
            sibling = sibling->sibling;
        }

        // Imprime o irmão anterior ao nó atual, se existir
        if (previousSibling != NULL) {
            printf("Previous Sibling: %s\n", previousSibling->lexeme);
        } else {
            printf("No previous sibling.\n");
        }
    }

    // Continua a percorrer a árvore para os filhos do nó atual
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        printFunDeclaracaoDetails(root->children[i], NULL); // Filhos não têm irmãos anteriores
    }

    // Continua a percorrer a árvore para o irmão do nó atual
    printFunDeclaracaoDetails(root->sibling, root);
}

