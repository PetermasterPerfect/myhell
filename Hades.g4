grammar Hades;

program:(blockContent | functionDefinition)* ; 

functionDefinition: FUNC ALPHANUMERIC codeBlock;

whileLoop: 'while' conditionBlock codeBlock;
ifStatement: 'if' conditionBlock codeBlock elseIfStatement* elseStatement?;
elseIfStatement: 'elseif' conditionBlock codeBlock;
elseStatement: 'else' codeBlock;

conditionBlock: NL* '[' NL* conditionContent* NL* ']' NL* ;

codeBlock: '{' NL* blockContent* '}' (NL* SEMI? NL*)  ;

blockContent: (sentences | whileLoop | ifStatement)+;
conditionContent: pipe|sentence;

sentences: (pipe|sentence) (SEMI? (pipe|sentence))* SEMI?;

pipe: sentence PIPE sentence (PIPE sentence)*;

sentence: word+;

//TODO: unlosed words action
word: ALPHANUMERIC | LESS | GREATER | RAW_STRING | QUOTED_STRING | UNCLOSED_QUOTED_STRING;

FUNC: 'func';

LESS: '<';
GREATER: '>';

WS: [ \t]+ -> channel(2);
SEMI: ';';
ASSIGN: '=';
PIPE: '|';

ALPHANUMERIC: [a-zA-Z][a-zA-Z0-9]+;
STRING_ESCAPE: '\\'.;

RAW_STRING: (STRING_ESCAPE | ~[ "'|\t\r\n;])+;
QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])* '\''
		| '"' (STRING_ESCAPE | ~[\\"])* '"';


UNCLOSED_QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])*
		| '"' (STRING_ESCAPE | ~[\\"])*;
NL: [\r\n];
