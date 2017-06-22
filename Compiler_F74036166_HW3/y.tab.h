#define SEM 257
#define PRINT 258
#define WHILE 259
#define INT 260
#define DOUBLE 261
#define LB 262
#define RB 263
#define STRING 264
#define ADD 265
#define SUB 266
#define MUL 267
#define DIV 268
#define ASSIGN 269
#define NUMBER 270
#define FLOATNUM 271
#define ID 272
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
    double double_val;
    int int_val;
    char str[100];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
