%{
#include <stdio.h>
#undef yywrap
int lineCount = 1, wordCount = 0;
%}

%%
[ \t]*
[a-zA-Z]+	++wordCount;	
\n				++lineCount;
.
%%

int yywrap() { return 1; }

void main() {
	yylex();
	printf("%d words and %d lines\n", wordCount, lineCount);
}
