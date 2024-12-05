grammar Arithmetic;

expr: expr ADD expr  #add
| expr SUB expr #sub 
| expr MUL expr  #mul  
| expr DIV expr   #div  
| expr MODULO expr #modulo  
| expr EQUAL expr  #equal  
| expr GREATERA expr #greater  
| expr LOWER expr  #lower
| expr NOTEQUAL expr #notequal  
| expr GREATEROREQUAL expr #greaterorequal  
| expr LOWEROREQUAL expr #lowerorequal
| LEFTPARENTHESIS expr RIGHTPARENTHESIS #parens
| ID #id
| INT #int;


NAME: [a-zA-Z][a-zA-Z0-9]*;
ID: '$' NAME;
INT: [0-9]+;

ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MODULO: '%';
EQUAL: '==';
GREATERA: '>';
LOWER: '<';
NOTEQUAL: '!=';
GREATEROREQUAL: '>=';
LOWEROREQUAL: '<=';
LEFTPARENTHESIS: '(';
RIGHTPARENTHESIS: ')';

WS: [ \t\r\n]+ -> skip;

