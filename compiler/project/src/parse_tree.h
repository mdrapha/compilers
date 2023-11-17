#include <stdbool.h>
#define MAX_LEXEME_SIZE 64
#define TRUE 1
#define FALSE 0
#define MAX_CHILDREN 3

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
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
#endif


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

/*Structure for the tree node*/
typedef struct treeNode {
    yytoken_kind_t type; // The type of the node
    int lineNumber; // The line number where the node was found
    int level; // The level of the node in the parse tree
    NodeType nodeType; // The type of the node
    char lexeme[MAX_LEXEME_SIZE]; // The lexeme of the token
    struct treeNode *children[MAX_CHILDREN]; // Array of pointers to children nodes
    struct treeNode *sibling; // Pointer to the next sibling node
} TreeNode;

// Function declarations

//Funtion to create a new node
TreeNode* newNode();

//Function to add a node to the tree
void addNode(TreeNode **destination, TreeNode *newNode, int childIndex);

//Function to free the tree
void freeTree(TreeNode *node);

//Function to print the tree
void printTree(TreeNode *node, int level, bool isLast);

//Function to print the tree
void printLexeme(TreeNode *node);

//Function to get the node type name
const char* getNodeTypeName(NodeType type);