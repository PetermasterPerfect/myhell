grammar AssHades;


assignments: (WS? assignment WS?)+;
assignment: ALPHANUM ASSIGN words*; 

words: (LESS|GREATER) WS? word+
	| word+;

word: VAR | ALPHANUM | RAW_STRING | QUOTED_STRING;

WS: [ \t]+;
LESS: '<';
GREATER: '>';
ASSIGN: '=';
VAR: '$' ALPHANUM;

ALPHANUM: [a-zA-Z] [a-zA-Z0-9]*;
RAW_STRING: (STRING_ESCAPE | ~[ <>=|\t\r\n'"`;])+;
STRING_ESCAPE: '\\'.;

QUOTED_STRING: '\'' (STRING_ESCAPE | ~[\\'])* '\''
		| '"' (STRING_ESCAPE | ~[\\"])* '"'
		| '`' (STRING_ESCAPE | ~[\\`])* '`';



