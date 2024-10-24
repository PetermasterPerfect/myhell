lexer grammar HadesLexer;

WS: [ \t]+;// -> skip;
fragment SEMI: ';';
fragment NL: [\r\n];
DOLLAR: '$';
SEPARATOR: SEMI | NL;
ASSIGN: '=';// -> pushMode(VAR_ASSIGNMENT);
PIPE: '|';
ALPHA: [a-zA-Z]*;
ALPHANUMERIC: ALPHA [a-zA-Z0-9]*;
VAR: DOLLAR (ALPHA | ALPHANUMERIC);
RAW_STRING: ~[$=|\t\r\n'";]+;


fragment NEWLINE_ESCAPE: '\\'[\r\n];
fragment STRING_ESCAPE: '\\'. | NEWLINE_ESCAPE;

QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])* '\''
		| '"' (STRING_ESCAPE | ~[\\"])* '"';


UNCLOSED_QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])*
		| '"' (STRING_ESCAPE | ~[\\"])*;

