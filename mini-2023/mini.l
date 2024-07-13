%{
#include <stdlib.h>
#include "tac.h"
#include "y.tab.h"
%}

%option yylineno

%%

"int"  {  return INT;  }

"print"  {  return PRINT;  }

"return"  {  return RETURN;  }

"continue"  {  return CONTINUE;  }

"if"  {  return IF;  }

"then"  {  return THEN;  }

"else"  {  return ELSE;  }

"fi"  {  return FI;  }

"while"  {  return WHILE;  }

"do"  {  return DO;  }

"done"  {  return DONE;  }

"char"	{	return CHAR;	}

"for"  {  return FOR;  }

[A-Za-z]([A-Za-z]|[0-9])*  {  
	yylval.string = strdup(yytext); 
	return IDENTIFIER;
}

[0-9]*	{
	yylval.string = strdup(yytext); 
	return INTEGER;
}

\'[^\'\n\\]\'	{	
	yylval.string = strdup(yytext); 
	return CONST_CHAR;	
}

\'\\[\\\'\"\?abfnrtv]\'	{	
	yylval.string = strdup(yytext); 
	return ESCAPE_CHAR;	
}

\"[^\"]*\"  {
	yylval.string = strdup(yytext); 
	return TEXT;
}

"=="  {  return EQ;  }

"!="  {  return NE;  }

"<="  {  return LE;  }

"<"  {  return LT;  }

">="  {  return GE;  }

">"  {  return GT;  }

[ \t\r\n]|#.*

. 	{	return *yytext; }



%%

int yywrap()
{
	return 1;
}

