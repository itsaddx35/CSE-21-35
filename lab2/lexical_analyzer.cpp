%{
#include <stdio.h>
%}

%%
[0-9]+          { printf("Number: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Word: %s\n", yytext); }
[.,;!?]         { printf("Punctuation: %s\n", yytext); }
\n              { /* Ignore newline */ }
[ \t]+          { /* Ignore whitespaces */ }
.               { printf("Unknown token: %s\n", yytext); }

%%
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        yyin = file;
    }
    yylex(); // Run the lexer
    return 0;
}
