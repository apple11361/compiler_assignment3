#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 5 "Compiler_F74036166_HW2.y"
    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    #define RED "\x1b[31m"
    #define ORIGIN "\x1b[0m" 

    typedef struct _SYMBOL{
        int index;
        char id[100];
        char type[10];
        double val;
        struct _SYMBOL *list_next;
        struct _SYMBOL *hash_next;
    }symbol;

    void yyerror(char *);
    void create_symbol();
    void insert_symbol(char *s, char *type);
    void symbol_assign(char *sym, double data);
    double lookup_symbol(char *sym);
    void dump_symbol();


    extern int yylineno;
    extern int yylex();
    extern int type_flag;           /*declaration in *.l    default:0, int:1, double:2*/
    extern int pre_type_flag;       /*declaration in *.l    default:0, int:1, double:2*/
    extern int symbol_num;          /*number of symbol*/

    int sym_num;            /*number of symbol*/
    bool is_err = false;    /*is there error*/
    char error_msg[100];    /*error message*/
    FILE *file;             /*fprintf to output.j*/
    int err_flag = 0;       /*0 mean success*/
    int index_temp;         /*for store local variable*/

    symbol *symbol_list_head;   /*for dumping*/
    symbol **symbol_hash;       /*for insertion, retrieval*/
    symbol *temp;

#line 56 "Compiler_F74036166_HW2.y"
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
#line 76 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    2,    2,    9,    9,
    3,    4,    4,    4,    8,    8,    8,    5,    5,    5,
    5,    6,    6,    7,
};
static const short yylen[] = {                            2,
    0,    2,    2,    2,    2,    2,    2,    4,    1,    1,
    3,    1,    3,    3,    1,    3,    3,    1,    1,    1,
    1,    2,    4,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    9,   10,    0,   19,   20,    0,    2,    0,
    0,    0,   15,    0,   18,    0,    0,    0,   22,   21,
    0,    0,    3,    4,    6,    0,    0,    5,    0,    0,
    0,    0,   24,    0,    0,    0,   16,   17,    0,   23,
    0,
};
static const short yydgoto[] = {                          1,
    9,   10,   11,   21,   13,   14,   15,   16,   17,
};
static const short yysindex[] = {                         0,
 -257, -253,    0,    0, -260,    0,    0, -246,    0, -225,
 -217, -215,    0, -211,    0, -261, -223, -242,    0,    0,
 -239, -260,    0,    0,    0, -260, -260,    0, -260, -260,
 -213, -206,    0, -229, -261, -261,    0,    0, -260,    0,
 -229,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0, -249,    0,    0,
    0,    0,    0,    0,    0, -232,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -199,    0,    0, -198, -222, -218,    0,    0,    0,    0,
 -197,
};
static const short yygindex[] = {                         0,
    0,    0,    0,   -1,   23,    0,   59,   28,    0,
};
#define YYTABLESIZE 61
static const short yytable[] = {                         12,
    2,    5,    3,    4,    5,   29,   30,   21,   18,    6,
    7,   20,    6,    7,    8,   21,   21,   21,   21,    5,
   34,   32,   22,   33,   12,   26,   27,    6,    7,   20,
   12,   23,   12,   12,   13,   26,   27,   41,   14,   24,
   13,   25,   13,   13,   14,   28,   14,   14,   31,   26,
   27,   37,   38,   35,   36,   39,   40,    7,   11,    8,
   19,
};
static const short yycheck[] = {                          1,
  258,  262,  260,  261,  262,  267,  268,  257,  262,  270,
  271,  272,  270,  271,  272,  265,  266,  267,  268,  262,
   22,  264,  269,  263,  257,  265,  266,  270,  271,  272,
  263,  257,  265,  266,  257,  265,  266,   39,  257,  257,
  263,  257,  265,  266,  263,  257,  265,  266,  272,  265,
  266,   29,   30,   26,   27,  269,  263,  257,  257,  257,
    2,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SEM","PRINT","WHILE","INT",
"DOUBLE","LB","RB","STRING","ADD","SUB","MUL","DIV","ASSIGN","NUMBER",
"FLOATNUM","ID","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : lines",
"lines :",
"lines : lines Stmt",
"Stmt : Decl SEM",
"Stmt : Assign SEM",
"Stmt : Print SEM",
"Stmt : Arith SEM",
"Decl : Type ID",
"Decl : Type ID ASSIGN Arith",
"Type : INT",
"Type : DOUBLE",
"Assign : ID ASSIGN Arith",
"Arith : Rhs",
"Arith : Arith ADD Rhs",
"Arith : Arith SUB Rhs",
"Rhs : Term",
"Rhs : Rhs MUL Term",
"Rhs : Rhs DIV Term",
"Term : Parentheses",
"Term : NUMBER",
"Term : FLOATNUM",
"Term : ID",
"Print : PRINT Parentheses",
"Print : PRINT LB STRING RB",
"Parentheses : LB Arith RB",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 240 "Compiler_F74036166_HW2.y"

 /*******************Auxiliary procedures******************/

int main(int argc, char *argv[])
{
    /**********************************************/
    file = fopen("Computer.j","w");

    fprintf(file,   ".class public main\n"
                    ".super java/lang/Object\n"
                    ".method public static main([Ljava/lang/String;)V\n"
                    ".limit stack %d\n"
                    ".limit locals %d\n",10,10);    
    /**********************************************/

    yylineno = 1;
    sym_num = 0;
    create_symbol();
    yyparse();

    /**********************************************/
    if(!err_flag)
    {
        fprintf(file,   "ldc \"Compile Success!\"\n"
                        "getstatic java/lang/System/out Ljava/io/PrintStream;\n"
                        "swap\n"
                        "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
    }
    else
    {
        fprintf(file,   "ldc \"Compile Failure!\"\n"
                        "getstatic java/lang/System/out Ljava/io/PrintStream;\n"
                        "swap\n"
                        "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        fprintf(file,   "ldc \"Exist %d errors\"\n"
                        "getstatic java/lang/System/out Ljava/io/PrintStream;\n"
                        "swap\n"
                        "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", err_flag);
    }
    fprintf(file,   "return\n"
                    ".end method\n");
    
    fclose(file);
    /**********************************************/

    printf("\nTotal lines: %d\n\n", yylineno);
    dump_symbol();

    printf("Generated: %s\n","Computer.j"); 
   
    return 0;
}

void yyerror(char *s)
{
    err_flag++;
    printf(RED);
    printf("<ERROR> %s (line %d)\n", s, yylineno);
    printf(ORIGIN);
    is_err = true;
}

void create_symbol()
{
    symbol_hash = (symbol **)malloc(sizeof(symbol *)*26);
    printf("Create symbol table\n\n");
}

void insert_symbol(char *s, char *type)
{
    temp = (symbol *)malloc(sizeof(symbol));
    temp->index = symbol_num++;
    strcpy(temp->id, s);
    strcpy(temp->type, type);
    temp->val = 0;

    if(!symbol_list_head)
    {
        symbol_list_head = temp;
    }
    else
    {
        symbol* i;
        for(i=symbol_list_head;i->list_next;i=i->list_next);
        i->list_next = temp;
    }
    if('a'<=s[0]<='z')
    {
        if(!symbol_hash[s[0]-'a'])
        {
            symbol_hash[s[0]-'a'] = temp;
        }
        else
        {
            temp->hash_next = symbol_hash[s[0]-'a'];
            symbol_hash[s[0]='a'] = temp;
        }
    }
    else
    {
        if(!symbol_hash[s[0]-'A'])
        {
            symbol_hash[s[0]-'A'] = temp;
        }
        else
        {
            temp->hash_next = symbol_hash[s[0]-'A'];
            symbol_hash[s[0]='A'] = temp;
        }
    }
    printf("Insert symbol: %s\n", s);
}

double lookup_symbol(char *sym)
{
    if('a'<=sym[0] && sym[0]<='z')
    {
        if(!symbol_hash[sym[0]-'a'])
        {
            return -1;
        }
        else
        {
            symbol *i;
            for(i=symbol_hash[sym[0]-'a'];i!=NULL;i=i->hash_next)
            {
                if(!strcmp(sym, i->id))
                {
                    return i->val;
                }
            }
            return -1;
        }
    }
    else
    {
        if(!symbol_hash[sym[0]-'A'])
        {
            return -1;
        }
        else
        {
            symbol *i;
            for(i=symbol_hash[sym[0]-'A'];i!=NULL;i=i->hash_next)
            {
                if(!strcmp(sym, i->id))
                {
                    return i->val;
                }
            }
            return -1;
        }
    }
}

void dump_symbol()
{
    if(symbol_num)
    {
        printf("The symbol table :\n\n");
        printf("ID\t\tType\t\tData\n");
        while(symbol_list_head)
        {
            printf("%s\t\t%s\t\t%g\n", symbol_list_head->id, symbol_list_head->type, symbol_list_head->val);

            symbol_list_head = symbol_list_head->list_next;
        }
    }
    else
    {
        printf("The symbol table is empty\n\n");
    }
}

void symbol_assign(char *sym, double data)
{
    if('a'<=sym[0]<='z')
    {
        symbol *i;
        for(i=symbol_hash[sym[0]-'a'];i!=NULL;i=i->hash_next)
        {
            if(!strcmp(sym, i->id))
            {
                i->val = data;
                index_temp = i->index;
                return;
            }
        }
    }
    else
    {
        symbol *i;
        for(i=symbol_hash[sym[0]-'A'];i!=NULL;i=i->hash_next)
        {
            if(!strcmp(sym, i->id))
            {
                i->val = data;
                index_temp = i->index;
                return;
            }
        }
    }
}




#line 471 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 70 "Compiler_F74036166_HW2.y"
	{}
break;
case 3:
#line 75 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[-1].double_val; is_err=false;}
break;
case 4:
#line 76 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[-1].double_val; is_err=false;}
break;
case 5:
#line 77 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[-1].double_val; is_err=false;}
break;
case 6:
#line 78 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[-1].double_val; is_err=false;}
break;
case 7:
#line 82 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                if(lookup_symbol(yystack.l_mark[0].str)!=-1)
                {
                    sprintf(error_msg, "re-declaration for variable %s", yystack.l_mark[0].str);
                    yyerror(error_msg);
                }
                else
                {
                    insert_symbol(yystack.l_mark[0].str, yystack.l_mark[-1].str);
                    fprintf(file,"ldc 0.0\n");
                    fprintf(file,"fstore %d\n",symbol_num-1);
                }
            }
        }
break;
case 8:
#line 99 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                if(lookup_symbol(yystack.l_mark[-2].str)!=-1)
                {
                    sprintf(error_msg, "re-declaration for variable %s", yystack.l_mark[-2].str);
                    yyerror(error_msg);
                }
                else
                {
                    insert_symbol(yystack.l_mark[-2].str, yystack.l_mark[-3].str);
                    symbol_assign(yystack.l_mark[-2].str, yystack.l_mark[0].double_val);
                    /*fprintf(file,"ldc %lf\n", $4);*/
                    fprintf(file,"fstore %d\n", symbol_num-1);
                }
            }
        }
break;
case 9:
#line 118 "Compiler_F74036166_HW2.y"
	{if(!is_err)strcpy(yyval.str, "int");}
break;
case 10:
#line 119 "Compiler_F74036166_HW2.y"
	{if(!is_err)strcpy(yyval.str, "double");}
break;
case 11:
#line 123 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                printf("ASSIGN\n");
                if(lookup_symbol(yystack.l_mark[-2].str)==-1)
                {
                    sprintf(error_msg, "cannot find the variable %s", yystack.l_mark[-2].str);
                    yyerror(error_msg);
                }
                else
                {
                    symbol_assign(yystack.l_mark[-2].str, yystack.l_mark[0].double_val);
                    fprintf(file, "fstore %d\n", index_temp);
                }
            }
        }
break;
case 12:
#line 141 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[0].double_val;}
break;
case 13:
#line 143 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                printf("ADD\n");
                yyval.double_val = yystack.l_mark[-2].double_val + yystack.l_mark[0].double_val;
                fprintf(file,"fadd \n");
            }
        }
break;
case 14:
#line 152 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                printf("SUB\n");
                yyval.double_val = yystack.l_mark[-2].double_val - yystack.l_mark[0].double_val;
                fprintf(file,"fsub \n");
            }
        }
break;
case 15:
#line 162 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[0].double_val;}
break;
case 16:
#line 164 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                printf("MUL\n");
                yyval.double_val = yystack.l_mark[-2].double_val * yystack.l_mark[0].double_val;
                fprintf(file,"fmul \n");
            }
        }
break;
case 17:
#line 173 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                if(yystack.l_mark[0].double_val==0)
                {
                    sprintf(error_msg, "The divisor can not be 0");
                    yyerror(error_msg);
                }
                else
                {
                    printf("DIV\n");
                    yyval.double_val = yystack.l_mark[-2].double_val / yystack.l_mark[0].double_val;
                    fprintf(file,"fdiv \n");
                }
            }
        }
break;
case 18:
#line 191 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[0].double_val;fprintf(file,"ldc %lf\n" , yystack.l_mark[0].double_val);}
break;
case 19:
#line 192 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[0].double_val;fprintf(file,"ldc %lf\n" , yystack.l_mark[0].double_val);}
break;
case 20:
#line 193 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[0].double_val;fprintf(file,"ldc %lf\n" , yystack.l_mark[0].double_val);}
break;
case 21:
#line 195 "Compiler_F74036166_HW2.y"
	{
            double temp;
            if(!is_err)
            {
                temp = lookup_symbol(yystack.l_mark[0].str);
                if(temp==-1)
                {
                    sprintf(error_msg, "cannot find the variable %s", yystack.l_mark[0].str);
                    yyerror(error_msg);
                }
                else
                {
                    yyval.double_val = temp;
                    fprintf(file,"ldc %lf\n" , temp);
                }
            }
        }
break;
case 22:
#line 215 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                printf("Print : %g\n", yystack.l_mark[0].double_val);
                fprintf(file,   "getstatic java/lang/System/out Ljava/io/PrintStream;\n"
                                "swap\n"
                                "invokevirtual java/io/PrintStream/println(F)V\n");
            }
        }
break;
case 23:
#line 225 "Compiler_F74036166_HW2.y"
	{
            if(!is_err)
            {
                printf("Print : %s\n", yystack.l_mark[-1].str);
                fprintf(file,   "ldc \"%s\"\n", yystack.l_mark[-1].str);
                fprintf(file,   "getstatic java/lang/System/out Ljava/io/PrintStream;\n"
                                "swap\n"
                                "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
            }
        }
break;
case 24:
#line 237 "Compiler_F74036166_HW2.y"
	{if(!is_err)yyval.double_val=yystack.l_mark[-1].double_val;}
break;
#line 880 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
