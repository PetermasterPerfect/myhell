parser grammar HadesParser;
options { tokenVocab=HadesLexer; }
program: sentences;//(blockContent | functionDefinition)*; 


functionDefinition: 'func' RAW_STRING ('()' | '(' ')') codeBlock;

whileLoop: 'while' conditionBlock codeBlock;
ifStatement: 'if' conditionBlock codeBlock;

conditionBlock: closedConditionBlock | unclosedConditionBlock;
closedConditionBlock: '[' conditionContent* ']';
unclosedConditionBlock: '[' conditionContent*;

codeBlock: closedCodeBlock | unclosedCodeBlock;
closedCodeBlock: '{' (blockContent)* '}';
unclosedCodeBlock: '{' (blockContent )*;

blockContent: sentences | whileLoop | ifStatement;
conditionContent: sentence | pipe;

sentences: (sentence | pipe) (SEPARATOR (sentence | pipe))* SEPARATOR?;

//TODO: unlosed pipe action
pipe: sentence PIPE sentence (PIPE sentence)*;

sentence: WS? words (WS words)* WS?
	| assignments;

assignments: (WS? assignment WS?)+;

//simpleSentence: simpleSentence SEMI
//	| word+;

unclosedPipe: word PIPE;
assignment: varName ASSIGN word+;// word+ or words???

varName: ALPHANUMERIC;

words: word+;

word: VAR | RAW_STRING | ALPHANUMERIC | QUOTED_STRING 
	| UNCLOSED_QUOTED_STRING #unclosedQuotedString
	;
