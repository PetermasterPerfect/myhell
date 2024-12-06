grammar Hades;

program:(blockContent | functionDefinition)* ; 

functionDefinition: FUNC ALPHANUMERIC codeBlock;

whileLoop: 'while' conditionBlock codeBlock;
ifStatement: 'if' conditionBlock codeBlock elseIfStatement* elseStatement?;
elseIfStatement: 'elseif' conditionBlock codeBlock;
elseStatement: 'else' codeBlock;

conditionBlock: NL* LEFTBRACKET NL* conditionContent* NL* RIGHTBRACKET NL* ;

codeBlock: NL* LEFTCURLYBRACKET NL* blockContent* NL* RIGHTCURLYBRACKET (NL* SEMI? NL*)  ;

blockContent: (sentences | whileLoop | ifStatement)+;
conditionContent: sentence;

sentences: (sentence SEMI? NL*)+;

sentence: sentence PIPE NL*? sentence
	| words PIPE NL*? words
	| words;

words: word+;
word: ALPHANUMERIC | LESS | GREATER | RAW_STRING | QUOTED_STRING | UNCLOSED_QUOTED_STRING;

FUNC: 'func';

LEFTBRACKET: '[';
RIGHTBRACKET: ']';
LEFTCURLYBRACKET: '{';
RIGHTCURLYBRACKET: '}';

LESS: '<';
GREATER: '>';

WS: [ \t]+ -> channel(2);
SEMI: ';';
ASSIGN: '=';
PIPE: '|';

ALPHANUMERIC: [a-zA-Z][a-zA-Z0-9]*;
STRING_ESCAPE: '\\'.;

RAW_STRING: (STRING_ESCAPE | ~[ \\"'`|\t\r\n;])+;
QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])* '\''
		| '"' (STRING_ESCAPE | ~[\\"])* '"'
		| '`' (STRING_ESCAPE | ~[\\`])* '`';


UNCLOSED_QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])*
		| '"' (STRING_ESCAPE | ~[\\"])*
		| '`' (STRING_ESCAPE | ~[\\`])*;
NL: [\r\n];// -> channel(2);
