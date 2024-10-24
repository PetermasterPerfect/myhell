// Generated from Hades.g4 by ANTLR 4.13.0
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class HadesLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, FUNC=7, BRACKETS=8, WS=9, 
		NL=10, DOLLAR=11, SEPARATOR=12, ASSIGN=13, PIPE=14, ALPHANUMERIC=15, VAR=16, 
		RAW_STRING=17, QUOTED_STRING=18, UNCLOSED_QUOTED_STRING=19;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "FUNC", "BRACKETS", "WS", 
			"SEMI", "NL", "DOLLAR", "SEPARATOR", "ASSIGN", "PIPE", "ALPHANUMERIC", 
			"VAR", "RAW_STRING", "NEWLINE_ESCAPE", "STRING_ESCAPE", "QUOTED_STRING", 
			"UNCLOSED_QUOTED_STRING"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'while '", "'if '", "'['", "']'", "'{'", "'}'", "'func '", null, 
			null, null, "'$'", null, "'='", "'|'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, "FUNC", "BRACKETS", "WS", "NL", 
			"DOLLAR", "SEPARATOR", "ASSIGN", "PIPE", "ALPHANUMERIC", "VAR", "RAW_STRING", 
			"QUOTED_STRING", "UNCLOSED_QUOTED_STRING"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public HadesLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Hades.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0013\u00a3\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0002\u0015\u0007\u0015\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0003\u0007"+
		"I\b\u0007\u0001\u0007\u0001\u0007\u0001\b\u0004\bN\b\b\u000b\b\f\bO\u0001"+
		"\t\u0001\t\u0001\n\u0004\nU\b\n\u000b\n\f\nV\u0001\u000b\u0001\u000b\u0001"+
		"\f\u0001\f\u0003\f]\b\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000f\u0004\u000fd\b\u000f\u000b\u000f\f\u000fe\u0001\u000f\u0005\u000f"+
		"i\b\u000f\n\u000f\f\u000fl\t\u000f\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0011\u0004\u0011r\b\u0011\u000b\u0011\f\u0011s\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0003\u0013|\b"+
		"\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014\u0081\b\u0014\n"+
		"\u0014\f\u0014\u0084\t\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0005\u0014\u008a\b\u0014\n\u0014\f\u0014\u008d\t\u0014\u0001\u0014"+
		"\u0003\u0014\u0090\b\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0005\u0015"+
		"\u0095\b\u0015\n\u0015\f\u0015\u0098\t\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0005\u0015\u009d\b\u0015\n\u0015\f\u0015\u00a0\t\u0015\u0003\u0015"+
		"\u00a2\b\u0015\u0000\u0000\u0016\u0001\u0001\u0003\u0002\u0005\u0003\u0007"+
		"\u0004\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\u0000\u0015\n"+
		"\u0017\u000b\u0019\f\u001b\r\u001d\u000e\u001f\u000f!\u0010#\u0011%\u0000"+
		"\'\u0000)\u0012+\u0013\u0001\u0000\u0007\u0002\u0000\t\t  \u0002\u0000"+
		"\n\n\r\r\u0002\u0000AZaz\u0003\u000009AZaz\t\u0000\t\n\r\r  \"\"$$\')"+
		";;==||\u0002\u0000\'\'\\\\\u0002\u0000\"\"\\\\\u00b1\u0000\u0001\u0001"+
		"\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001"+
		"\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000"+
		"\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000"+
		"\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000"+
		"\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000"+
		"\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000"+
		"\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000"+
		"\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000"+
		")\u0001\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0001-\u0001"+
		"\u0000\u0000\u0000\u00034\u0001\u0000\u0000\u0000\u00058\u0001\u0000\u0000"+
		"\u0000\u0007:\u0001\u0000\u0000\u0000\t<\u0001\u0000\u0000\u0000\u000b"+
		">\u0001\u0000\u0000\u0000\r@\u0001\u0000\u0000\u0000\u000fF\u0001\u0000"+
		"\u0000\u0000\u0011M\u0001\u0000\u0000\u0000\u0013Q\u0001\u0000\u0000\u0000"+
		"\u0015T\u0001\u0000\u0000\u0000\u0017X\u0001\u0000\u0000\u0000\u0019\\"+
		"\u0001\u0000\u0000\u0000\u001b^\u0001\u0000\u0000\u0000\u001d`\u0001\u0000"+
		"\u0000\u0000\u001fc\u0001\u0000\u0000\u0000!m\u0001\u0000\u0000\u0000"+
		"#q\u0001\u0000\u0000\u0000%u\u0001\u0000\u0000\u0000\'{\u0001\u0000\u0000"+
		"\u0000)\u008f\u0001\u0000\u0000\u0000+\u00a1\u0001\u0000\u0000\u0000-"+
		".\u0005w\u0000\u0000./\u0005h\u0000\u0000/0\u0005i\u0000\u000001\u0005"+
		"l\u0000\u000012\u0005e\u0000\u000023\u0005 \u0000\u00003\u0002\u0001\u0000"+
		"\u0000\u000045\u0005i\u0000\u000056\u0005f\u0000\u000067\u0005 \u0000"+
		"\u00007\u0004\u0001\u0000\u0000\u000089\u0005[\u0000\u00009\u0006\u0001"+
		"\u0000\u0000\u0000:;\u0005]\u0000\u0000;\b\u0001\u0000\u0000\u0000<=\u0005"+
		"{\u0000\u0000=\n\u0001\u0000\u0000\u0000>?\u0005}\u0000\u0000?\f\u0001"+
		"\u0000\u0000\u0000@A\u0005f\u0000\u0000AB\u0005u\u0000\u0000BC\u0005n"+
		"\u0000\u0000CD\u0005c\u0000\u0000DE\u0005 \u0000\u0000E\u000e\u0001\u0000"+
		"\u0000\u0000FH\u0005(\u0000\u0000GI\u0003\u0011\b\u0000HG\u0001\u0000"+
		"\u0000\u0000HI\u0001\u0000\u0000\u0000IJ\u0001\u0000\u0000\u0000JK\u0005"+
		")\u0000\u0000K\u0010\u0001\u0000\u0000\u0000LN\u0007\u0000\u0000\u0000"+
		"ML\u0001\u0000\u0000\u0000NO\u0001\u0000\u0000\u0000OM\u0001\u0000\u0000"+
		"\u0000OP\u0001\u0000\u0000\u0000P\u0012\u0001\u0000\u0000\u0000QR\u0005"+
		";\u0000\u0000R\u0014\u0001\u0000\u0000\u0000SU\u0007\u0001\u0000\u0000"+
		"TS\u0001\u0000\u0000\u0000UV\u0001\u0000\u0000\u0000VT\u0001\u0000\u0000"+
		"\u0000VW\u0001\u0000\u0000\u0000W\u0016\u0001\u0000\u0000\u0000XY\u0005"+
		"$\u0000\u0000Y\u0018\u0001\u0000\u0000\u0000Z]\u0003\u0013\t\u0000[]\u0003"+
		"\u0015\n\u0000\\Z\u0001\u0000\u0000\u0000\\[\u0001\u0000\u0000\u0000]"+
		"\u001a\u0001\u0000\u0000\u0000^_\u0005=\u0000\u0000_\u001c\u0001\u0000"+
		"\u0000\u0000`a\u0005|\u0000\u0000a\u001e\u0001\u0000\u0000\u0000bd\u0007"+
		"\u0002\u0000\u0000cb\u0001\u0000\u0000\u0000de\u0001\u0000\u0000\u0000"+
		"ec\u0001\u0000\u0000\u0000ef\u0001\u0000\u0000\u0000fj\u0001\u0000\u0000"+
		"\u0000gi\u0007\u0003\u0000\u0000hg\u0001\u0000\u0000\u0000il\u0001\u0000"+
		"\u0000\u0000jh\u0001\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000k \u0001"+
		"\u0000\u0000\u0000lj\u0001\u0000\u0000\u0000mn\u0003\u0017\u000b\u0000"+
		"no\u0003\u001f\u000f\u0000o\"\u0001\u0000\u0000\u0000pr\b\u0004\u0000"+
		"\u0000qp\u0001\u0000\u0000\u0000rs\u0001\u0000\u0000\u0000sq\u0001\u0000"+
		"\u0000\u0000st\u0001\u0000\u0000\u0000t$\u0001\u0000\u0000\u0000uv\u0005"+
		"\\\u0000\u0000vw\u0007\u0001\u0000\u0000w&\u0001\u0000\u0000\u0000xy\u0005"+
		"\\\u0000\u0000y|\t\u0000\u0000\u0000z|\u0003%\u0012\u0000{x\u0001\u0000"+
		"\u0000\u0000{z\u0001\u0000\u0000\u0000|(\u0001\u0000\u0000\u0000}\u0082"+
		"\u0005\'\u0000\u0000~\u0081\u0003\'\u0013\u0000\u007f\u0081\b\u0005\u0000"+
		"\u0000\u0080~\u0001\u0000\u0000\u0000\u0080\u007f\u0001\u0000\u0000\u0000"+
		"\u0081\u0084\u0001\u0000\u0000\u0000\u0082\u0080\u0001\u0000\u0000\u0000"+
		"\u0082\u0083\u0001\u0000\u0000\u0000\u0083\u0085\u0001\u0000\u0000\u0000"+
		"\u0084\u0082\u0001\u0000\u0000\u0000\u0085\u0090\u0005\'\u0000\u0000\u0086"+
		"\u008b\u0005\"\u0000\u0000\u0087\u008a\u0003\'\u0013\u0000\u0088\u008a"+
		"\b\u0006\u0000\u0000\u0089\u0087\u0001\u0000\u0000\u0000\u0089\u0088\u0001"+
		"\u0000\u0000\u0000\u008a\u008d\u0001\u0000\u0000\u0000\u008b\u0089\u0001"+
		"\u0000\u0000\u0000\u008b\u008c\u0001\u0000\u0000\u0000\u008c\u008e\u0001"+
		"\u0000\u0000\u0000\u008d\u008b\u0001\u0000\u0000\u0000\u008e\u0090\u0005"+
		"\"\u0000\u0000\u008f}\u0001\u0000\u0000\u0000\u008f\u0086\u0001\u0000"+
		"\u0000\u0000\u0090*\u0001\u0000\u0000\u0000\u0091\u0096\u0005\'\u0000"+
		"\u0000\u0092\u0095\u0003\'\u0013\u0000\u0093\u0095\b\u0005\u0000\u0000"+
		"\u0094\u0092\u0001\u0000\u0000\u0000\u0094\u0093\u0001\u0000\u0000\u0000"+
		"\u0095\u0098\u0001\u0000\u0000\u0000\u0096\u0094\u0001\u0000\u0000\u0000"+
		"\u0096\u0097\u0001\u0000\u0000\u0000\u0097\u00a2\u0001\u0000\u0000\u0000"+
		"\u0098\u0096\u0001\u0000\u0000\u0000\u0099\u009e\u0005\"\u0000\u0000\u009a"+
		"\u009d\u0003\'\u0013\u0000\u009b\u009d\b\u0006\u0000\u0000\u009c\u009a"+
		"\u0001\u0000\u0000\u0000\u009c\u009b\u0001\u0000\u0000\u0000\u009d\u00a0"+
		"\u0001\u0000\u0000\u0000\u009e\u009c\u0001\u0000\u0000\u0000\u009e\u009f"+
		"\u0001\u0000\u0000\u0000\u009f\u00a2\u0001\u0000\u0000\u0000\u00a0\u009e"+
		"\u0001\u0000\u0000\u0000\u00a1\u0091\u0001\u0000\u0000\u0000\u00a1\u0099"+
		"\u0001\u0000\u0000\u0000\u00a2,\u0001\u0000\u0000\u0000\u0013\u0000HO"+
		"V\\ejs{\u0080\u0082\u0089\u008b\u008f\u0094\u0096\u009c\u009e\u00a1\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}