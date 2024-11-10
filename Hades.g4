grammar Hades;
program:(blockContent | functionDefinition)* ; 

functionDefinition: WS? FUNC WS? ALPHANUMERIC WS? codeBlock;

whileLoop: WS? 'while ' conditionBlock codeBlock;
ifStatement: WS? 'if ' conditionBlock codeBlock elseIfStatement* elseStatement?;
elseIfStatement: WS? 'elseif ' conditionBlock codeBlock;
elseStatement: WS? 'else ' codeBlock;

conditionBlock: WS? '[' WS? conditionContent* WS? ']' WS?;

codeBlock: NL? WS? '{' WS? blockContent (WS | NL)* '}' WS? SEPARATOR? NL?;

blockContent: (NL? (sentences | whileLoop | ifStatement))+;
conditionContent: pipe|sentence;

sentences: (pipe|sentence) (SEPARATOR+ (pipe|sentence))* SEPARATOR*;

pipe: sentence PIPE sentence (PIPE sentence)*;

sentence: (WS? words WS?)+
	| assignments;

assignments: (WS? assignment WS?)+;

unclosedPipe: word PIPE;
assignment: varName ASSIGN word+;
varName: ALPHANUMERIC;

//TODO: unlosed words action
words: word+
	| (LESS|GREATER) WS? word+;

word: (VAR | RAW_STRING | ALPHANUMERIC | QUOTED_STRING) #closedString
	| UNCLOSED_QUOTED_STRING #unclosedQuotedString
	;

FUNC: 'func ';

LESS: '<';
GREATER: '>';

BRACKETS: '(' WS? ')';
WS: [ \t]+;
fragment SEMI: ';';
NL: [\r\n]+;
DOLLAR: '$';
SEPARATOR: SEMI | NL;
ASSIGN: '=';
PIPE: '|';
ALPHANUMERIC: [a-zA-Z0-9]+;
VAR: DOLLAR ALPHANUMERIC;

RAW_STRING: (STRING_ESCAPE | ~[ <>()$=|\t\r\n'";])+;
STRING_ESCAPE: '\\'.;

QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])* '\''
		| '"' (STRING_ESCAPE | ~[\\"])* '"';


UNCLOSED_QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])*
		| '"' (STRING_ESCAPE | ~[\\"])*;
