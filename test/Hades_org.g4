grammar Hades;

program: complexString+;//(blockContent | functionDefinition)*; 
/*
functionDefinition: 'func' RAW_STRING ('()' | '(' ')') codeBlock;

whileLoop: 'while' conditionBlock codeBlock; 

ifStatement: 'if' conditionBlock codeBlock;

conditionBlock: closedConditionBlock | unclosedConditionBlock;
closedConditionBlock: '[' conditionContent* ']';
unclosedConditionBlock: '[' conditionContent*;

codeBlock: closedCodeBlock | unclosedCodeBlock;
closedCodeBlock: '{' (blockContent)* '}';
unclosedCodeBlock: '{' (blockContent )* ;

blockContent: complexString | whileLoop | ifStatement;
conditionContent: 
	| string PIPE string
	| unclosedPipe;
*/

complexString: string+;/*
	| string SEMI
	| string PIPE string
	| unclosedPipe;*/

unclosedPipe: string PIPE;
assignment: string ASSIGN string;

string: (RAW_STRING | QUOTED_STRING | unclosedQuotedString);
unclosedQuotedString: UNCLOSED_QUOTED_STRING;
ASSIGN: '=';
PIPE: '|';
SEMI: ';';
RAW_STRING: ~[\\ |=\t\r\n'";];
//ID: [a-zA-Z][a-zA-Z0-9]*;

fragment NEWLINE_ESCAPE: '\\'[\r\n];
fragment STRING_ESCAPE: '\\'. | NEWLINE_ESCAPE;

QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])* '\''
		| '"' (STRING_ESCAPE | ~[\\"])* '"';


UNCLOSED_QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])*
		| '"' (STRING_ESCAPE | ~[\\"])*;

END_MARK: SEMI; //???

