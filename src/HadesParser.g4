parser grammar Hades;
options { tokenVocab=HadesLexer; }

program1:(blockContent | functionDefinition)* ; 

functionDefinition: FUNC ALPHANUMERIC codeBlock;

whileLoop: WHILE conditionBlock codeBlock;
ifStatement: IF conditionBlock codeBlock elseIfStatement* elseStatement?;
elseIfStatement: ELSEIF conditionBlock codeBlock;
elseStatement: ELSE codeBlock;

conditionBlock: NL* LEFTBRACKET NL* conditionContent* NL* RIGHTBRACKET NL* ;

codeBlock: NL* LEFTCURLYBRACKET NL* blockContent* NL* RIGHTCURLYBRACKET (NL* SEMI? NL*)  ;

blockContent: (sentences | whileLoop | ifStatement)+;
conditionContent: sentence;

sentences: (sentence SEMI? NL*)+;

sentence: sentence PIPE NL*? sentence
	| words PIPE NL*? words
	| words;

words: (word|arth)+;
word: ALPHANUMERIC | LESS | GREATER | RAW_STRING | QUOTED_STRING | UNCLOSED_QUOTED_STRING;

arth: BACKTICK expr BACKTICKA
	| BACKTICK expr;

expr: expr ADD expr     // '+'  
| expr SUB expr   // '-'  
| expr MUL expr   // '*'  
| expr DIV expr   // '/'  
| expr MODULO expr // '%'  
| expr EQUAL expr  // '=='  
| expr GREATERA expr // '>'  
| expr LOWER expr  // '<'  
| expr NOTEQUAL expr // '!='  
| expr GREATEROREQUAL expr // '>='  
| expr LOWEROREQUAL expr // '<='  
| LEFTPARENTHESIS expr RIGHTPARENTHESIS // '(' exprr ')'
| ID             // '$' NAME  
| INT;



