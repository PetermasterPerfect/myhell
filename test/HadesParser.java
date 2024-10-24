// Generated from Hades.g4 by ANTLR 4.13.0
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class HadesParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, FUNC=7, BRACKETS=8, WS=9, 
		NL=10, DOLLAR=11, SEPARATOR=12, ASSIGN=13, PIPE=14, ALPHANUMERIC=15, VAR=16, 
		RAW_STRING=17, QUOTED_STRING=18, UNCLOSED_QUOTED_STRING=19;
	public static final int
		RULE_program = 0, RULE_functionDefinition = 1, RULE_whileLoop = 2, RULE_ifStatement = 3, 
		RULE_conditionBlock = 4, RULE_closedConditionBlock = 5, RULE_unclosedConditionBlock = 6, 
		RULE_codeBlock = 7, RULE_closedCodeBlock = 8, RULE_unclosedCodeBlock = 9, 
		RULE_blockContent = 10, RULE_conditionContent = 11, RULE_sentences = 12, 
		RULE_pipe = 13, RULE_sentence = 14, RULE_assignments = 15, RULE_unclosedPipe = 16, 
		RULE_assignment = 17, RULE_varName = 18, RULE_words = 19, RULE_word = 20;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "functionDefinition", "whileLoop", "ifStatement", "conditionBlock", 
			"closedConditionBlock", "unclosedConditionBlock", "codeBlock", "closedCodeBlock", 
			"unclosedCodeBlock", "blockContent", "conditionContent", "sentences", 
			"pipe", "sentence", "assignments", "unclosedPipe", "assignment", "varName", 
			"words", "word"
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

	@Override
	public String getGrammarFileName() { return "Hades.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public HadesParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public List<BlockContentContext> blockContent() {
			return getRuleContexts(BlockContentContext.class);
		}
		public BlockContentContext blockContent(int i) {
			return getRuleContext(BlockContentContext.class,i);
		}
		public List<FunctionDefinitionContext> functionDefinition() {
			return getRuleContexts(FunctionDefinitionContext.class);
		}
		public FunctionDefinitionContext functionDefinition(int i) {
			return getRuleContext(FunctionDefinitionContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterProgram(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitProgram(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017478L) != 0)) {
				{
				setState(44);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(42);
					blockContent();
					}
					break;
				case 2:
					{
					setState(43);
					functionDefinition();
					}
					break;
				}
				}
				setState(48);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDefinitionContext extends ParserRuleContext {
		public TerminalNode FUNC() { return getToken(HadesParser.FUNC, 0); }
		public TerminalNode ALPHANUMERIC() { return getToken(HadesParser.ALPHANUMERIC, 0); }
		public TerminalNode BRACKETS() { return getToken(HadesParser.BRACKETS, 0); }
		public CodeBlockContext codeBlock() {
			return getRuleContext(CodeBlockContext.class,0);
		}
		public List<TerminalNode> WS() { return getTokens(HadesParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(HadesParser.WS, i);
		}
		public FunctionDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDefinition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterFunctionDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitFunctionDefinition(this);
		}
	}

	public final FunctionDefinitionContext functionDefinition() throws RecognitionException {
		FunctionDefinitionContext _localctx = new FunctionDefinitionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_functionDefinition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(49);
				match(WS);
				}
			}

			setState(52);
			match(FUNC);
			setState(54);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(53);
				match(WS);
				}
			}

			setState(56);
			match(ALPHANUMERIC);
			setState(58);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(57);
				match(WS);
				}
			}

			setState(60);
			match(BRACKETS);
			setState(62);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				setState(61);
				match(WS);
				}
				break;
			}
			setState(64);
			codeBlock();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class WhileLoopContext extends ParserRuleContext {
		public ConditionBlockContext conditionBlock() {
			return getRuleContext(ConditionBlockContext.class,0);
		}
		public CodeBlockContext codeBlock() {
			return getRuleContext(CodeBlockContext.class,0);
		}
		public TerminalNode WS() { return getToken(HadesParser.WS, 0); }
		public WhileLoopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileLoop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterWhileLoop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitWhileLoop(this);
		}
	}

	public final WhileLoopContext whileLoop() throws RecognitionException {
		WhileLoopContext _localctx = new WhileLoopContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_whileLoop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(67);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(66);
				match(WS);
				}
			}

			setState(69);
			match(T__0);
			setState(70);
			conditionBlock();
			setState(71);
			codeBlock();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IfStatementContext extends ParserRuleContext {
		public ConditionBlockContext conditionBlock() {
			return getRuleContext(ConditionBlockContext.class,0);
		}
		public CodeBlockContext codeBlock() {
			return getRuleContext(CodeBlockContext.class,0);
		}
		public TerminalNode WS() { return getToken(HadesParser.WS, 0); }
		public IfStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterIfStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitIfStatement(this);
		}
	}

	public final IfStatementContext ifStatement() throws RecognitionException {
		IfStatementContext _localctx = new IfStatementContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_ifStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(74);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(73);
				match(WS);
				}
			}

			setState(76);
			match(T__1);
			setState(77);
			conditionBlock();
			setState(78);
			codeBlock();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConditionBlockContext extends ParserRuleContext {
		public ClosedConditionBlockContext closedConditionBlock() {
			return getRuleContext(ClosedConditionBlockContext.class,0);
		}
		public UnclosedConditionBlockContext unclosedConditionBlock() {
			return getRuleContext(UnclosedConditionBlockContext.class,0);
		}
		public ConditionBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditionBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterConditionBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitConditionBlock(this);
		}
	}

	public final ConditionBlockContext conditionBlock() throws RecognitionException {
		ConditionBlockContext _localctx = new ConditionBlockContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_conditionBlock);
		try {
			setState(82);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(80);
				closedConditionBlock();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(81);
				unclosedConditionBlock();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ClosedConditionBlockContext extends ParserRuleContext {
		public List<TerminalNode> WS() { return getTokens(HadesParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(HadesParser.WS, i);
		}
		public List<ConditionContentContext> conditionContent() {
			return getRuleContexts(ConditionContentContext.class);
		}
		public ConditionContentContext conditionContent(int i) {
			return getRuleContext(ConditionContentContext.class,i);
		}
		public ClosedConditionBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_closedConditionBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterClosedConditionBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitClosedConditionBlock(this);
		}
	}

	public final ClosedConditionBlockContext closedConditionBlock() throws RecognitionException {
		ClosedConditionBlockContext _localctx = new ClosedConditionBlockContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_closedConditionBlock);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(84);
				match(WS);
				}
			}

			setState(87);
			match(T__2);
			setState(89);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(88);
				match(WS);
				}
				break;
			}
			setState(94);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(91);
					conditionContent();
					}
					} 
				}
				setState(96);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			setState(98);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(97);
				match(WS);
				}
			}

			setState(100);
			match(T__3);
			setState(102);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(101);
				match(WS);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnclosedConditionBlockContext extends ParserRuleContext {
		public TerminalNode WS() { return getToken(HadesParser.WS, 0); }
		public List<ConditionContentContext> conditionContent() {
			return getRuleContexts(ConditionContentContext.class);
		}
		public ConditionContentContext conditionContent(int i) {
			return getRuleContext(ConditionContentContext.class,i);
		}
		public UnclosedConditionBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unclosedConditionBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterUnclosedConditionBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitUnclosedConditionBlock(this);
		}
	}

	public final UnclosedConditionBlockContext unclosedConditionBlock() throws RecognitionException {
		UnclosedConditionBlockContext _localctx = new UnclosedConditionBlockContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_unclosedConditionBlock);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(104);
				match(WS);
				}
			}

			setState(107);
			match(T__2);
			setState(111);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(108);
					conditionContent();
					}
					} 
				}
				setState(113);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CodeBlockContext extends ParserRuleContext {
		public ClosedCodeBlockContext closedCodeBlock() {
			return getRuleContext(ClosedCodeBlockContext.class,0);
		}
		public UnclosedCodeBlockContext unclosedCodeBlock() {
			return getRuleContext(UnclosedCodeBlockContext.class,0);
		}
		public List<TerminalNode> NL() { return getTokens(HadesParser.NL); }
		public TerminalNode NL(int i) {
			return getToken(HadesParser.NL, i);
		}
		public CodeBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_codeBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterCodeBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitCodeBlock(this);
		}
	}

	public final CodeBlockContext codeBlock() throws RecognitionException {
		CodeBlockContext _localctx = new CodeBlockContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_codeBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NL) {
				{
				setState(114);
				match(NL);
				}
			}

			setState(119);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				setState(117);
				closedCodeBlock();
				}
				break;
			case 2:
				{
				setState(118);
				unclosedCodeBlock();
				}
				break;
			}
			setState(122);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				{
				setState(121);
				match(NL);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ClosedCodeBlockContext extends ParserRuleContext {
		public List<TerminalNode> WS() { return getTokens(HadesParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(HadesParser.WS, i);
		}
		public List<BlockContentContext> blockContent() {
			return getRuleContexts(BlockContentContext.class);
		}
		public BlockContentContext blockContent(int i) {
			return getRuleContext(BlockContentContext.class,i);
		}
		public TerminalNode NL() { return getToken(HadesParser.NL, 0); }
		public TerminalNode SEPARATOR() { return getToken(HadesParser.SEPARATOR, 0); }
		public ClosedCodeBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_closedCodeBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterClosedCodeBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitClosedCodeBlock(this);
		}
	}

	public final ClosedCodeBlockContext closedCodeBlock() throws RecognitionException {
		ClosedCodeBlockContext _localctx = new ClosedCodeBlockContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_closedCodeBlock);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(125);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(124);
				match(WS);
				}
			}

			setState(127);
			match(T__4);
			setState(129);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				{
				setState(128);
				match(WS);
				}
				break;
			}
			setState(134);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(131);
					blockContent();
					}
					} 
				}
				setState(136);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			setState(138);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(137);
				match(WS);
				}
			}

			setState(141);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NL) {
				{
				setState(140);
				match(NL);
				}
			}

			setState(143);
			match(T__5);
			setState(145);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				{
				setState(144);
				match(WS);
				}
				break;
			}
			setState(148);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEPARATOR) {
				{
				setState(147);
				match(SEPARATOR);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnclosedCodeBlockContext extends ParserRuleContext {
		public List<BlockContentContext> blockContent() {
			return getRuleContexts(BlockContentContext.class);
		}
		public BlockContentContext blockContent(int i) {
			return getRuleContext(BlockContentContext.class,i);
		}
		public UnclosedCodeBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unclosedCodeBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterUnclosedCodeBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitUnclosedCodeBlock(this);
		}
	}

	public final UnclosedCodeBlockContext unclosedCodeBlock() throws RecognitionException {
		UnclosedCodeBlockContext _localctx = new UnclosedCodeBlockContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_unclosedCodeBlock);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(150);
			match(T__4);
			setState(154);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(151);
					blockContent();
					}
					} 
				}
				setState(156);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BlockContentContext extends ParserRuleContext {
		public SentencesContext sentences() {
			return getRuleContext(SentencesContext.class,0);
		}
		public WhileLoopContext whileLoop() {
			return getRuleContext(WhileLoopContext.class,0);
		}
		public IfStatementContext ifStatement() {
			return getRuleContext(IfStatementContext.class,0);
		}
		public TerminalNode NL() { return getToken(HadesParser.NL, 0); }
		public BlockContentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockContent; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterBlockContent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitBlockContent(this);
		}
	}

	public final BlockContentContext blockContent() throws RecognitionException {
		BlockContentContext _localctx = new BlockContentContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_blockContent);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NL) {
				{
				setState(157);
				match(NL);
				}
			}

			setState(163);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				{
				setState(160);
				sentences();
				}
				break;
			case 2:
				{
				setState(161);
				whileLoop();
				}
				break;
			case 3:
				{
				setState(162);
				ifStatement();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConditionContentContext extends ParserRuleContext {
		public PipeContext pipe() {
			return getRuleContext(PipeContext.class,0);
		}
		public SentenceContext sentence() {
			return getRuleContext(SentenceContext.class,0);
		}
		public ConditionContentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditionContent; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterConditionContent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitConditionContent(this);
		}
	}

	public final ConditionContentContext conditionContent() throws RecognitionException {
		ConditionContentContext _localctx = new ConditionContentContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_conditionContent);
		try {
			setState(167);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,29,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(165);
				pipe();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(166);
				sentence();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SentencesContext extends ParserRuleContext {
		public List<PipeContext> pipe() {
			return getRuleContexts(PipeContext.class);
		}
		public PipeContext pipe(int i) {
			return getRuleContext(PipeContext.class,i);
		}
		public List<SentenceContext> sentence() {
			return getRuleContexts(SentenceContext.class);
		}
		public SentenceContext sentence(int i) {
			return getRuleContext(SentenceContext.class,i);
		}
		public List<TerminalNode> SEPARATOR() { return getTokens(HadesParser.SEPARATOR); }
		public TerminalNode SEPARATOR(int i) {
			return getToken(HadesParser.SEPARATOR, i);
		}
		public SentencesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sentences; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterSentences(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitSentences(this);
		}
	}

	public final SentencesContext sentences() throws RecognitionException {
		SentencesContext _localctx = new SentencesContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_sentences);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(171);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,30,_ctx) ) {
			case 1:
				{
				setState(169);
				pipe();
				}
				break;
			case 2:
				{
				setState(170);
				sentence();
				}
				break;
			}
			setState(184);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(174); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(173);
						match(SEPARATOR);
						}
						}
						setState(176); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==SEPARATOR );
					setState(180);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
					case 1:
						{
						setState(178);
						pipe();
						}
						break;
					case 2:
						{
						setState(179);
						sentence();
						}
						break;
					}
					}
					} 
				}
				setState(186);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			}
			setState(190);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			while ( _alt!=1 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1+1 ) {
					{
					{
					setState(187);
					match(SEPARATOR);
					}
					} 
				}
				setState(192);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PipeContext extends ParserRuleContext {
		public List<SentenceContext> sentence() {
			return getRuleContexts(SentenceContext.class);
		}
		public SentenceContext sentence(int i) {
			return getRuleContext(SentenceContext.class,i);
		}
		public List<TerminalNode> PIPE() { return getTokens(HadesParser.PIPE); }
		public TerminalNode PIPE(int i) {
			return getToken(HadesParser.PIPE, i);
		}
		public PipeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pipe; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterPipe(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitPipe(this);
		}
	}

	public final PipeContext pipe() throws RecognitionException {
		PipeContext _localctx = new PipeContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_pipe);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(193);
			sentence();
			setState(194);
			match(PIPE);
			setState(195);
			sentence();
			setState(200);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==PIPE) {
				{
				{
				setState(196);
				match(PIPE);
				setState(197);
				sentence();
				}
				}
				setState(202);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SentenceContext extends ParserRuleContext {
		public List<WordsContext> words() {
			return getRuleContexts(WordsContext.class);
		}
		public WordsContext words(int i) {
			return getRuleContext(WordsContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(HadesParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(HadesParser.WS, i);
		}
		public AssignmentsContext assignments() {
			return getRuleContext(AssignmentsContext.class,0);
		}
		public SentenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sentence; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterSentence(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitSentence(this);
		}
	}

	public final SentenceContext sentence() throws RecognitionException {
		SentenceContext _localctx = new SentenceContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_sentence);
		int _la;
		try {
			int _alt;
			setState(218);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,39,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(204);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(203);
					match(WS);
					}
				}

				setState(206);
				words();
				setState(211);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(207);
						match(WS);
						setState(208);
						words();
						}
						} 
					}
					setState(213);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				}
				setState(215);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,38,_ctx) ) {
				case 1:
					{
					setState(214);
					match(WS);
					}
					break;
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(217);
				assignments();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignmentsContext extends ParserRuleContext {
		public List<AssignmentContext> assignment() {
			return getRuleContexts(AssignmentContext.class);
		}
		public AssignmentContext assignment(int i) {
			return getRuleContext(AssignmentContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(HadesParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(HadesParser.WS, i);
		}
		public AssignmentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignments; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterAssignments(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitAssignments(this);
		}
	}

	public final AssignmentsContext assignments() throws RecognitionException {
		AssignmentsContext _localctx = new AssignmentsContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_assignments);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(227); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(221);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==WS) {
						{
						setState(220);
						match(WS);
						}
					}

					setState(223);
					assignment();
					setState(225);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,41,_ctx) ) {
					case 1:
						{
						setState(224);
						match(WS);
						}
						break;
					}
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(229); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,42,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnclosedPipeContext extends ParserRuleContext {
		public WordContext word() {
			return getRuleContext(WordContext.class,0);
		}
		public TerminalNode PIPE() { return getToken(HadesParser.PIPE, 0); }
		public UnclosedPipeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unclosedPipe; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterUnclosedPipe(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitUnclosedPipe(this);
		}
	}

	public final UnclosedPipeContext unclosedPipe() throws RecognitionException {
		UnclosedPipeContext _localctx = new UnclosedPipeContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_unclosedPipe);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(231);
			word();
			setState(232);
			match(PIPE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignmentContext extends ParserRuleContext {
		public VarNameContext varName() {
			return getRuleContext(VarNameContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(HadesParser.ASSIGN, 0); }
		public List<WordContext> word() {
			return getRuleContexts(WordContext.class);
		}
		public WordContext word(int i) {
			return getRuleContext(WordContext.class,i);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitAssignment(this);
		}
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_assignment);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(234);
			varName();
			setState(235);
			match(ASSIGN);
			setState(237); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(236);
					word();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(239); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarNameContext extends ParserRuleContext {
		public TerminalNode ALPHANUMERIC() { return getToken(HadesParser.ALPHANUMERIC, 0); }
		public VarNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterVarName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitVarName(this);
		}
	}

	public final VarNameContext varName() throws RecognitionException {
		VarNameContext _localctx = new VarNameContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_varName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(241);
			match(ALPHANUMERIC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class WordsContext extends ParserRuleContext {
		public List<WordContext> word() {
			return getRuleContexts(WordContext.class);
		}
		public WordContext word(int i) {
			return getRuleContext(WordContext.class,i);
		}
		public WordsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_words; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterWords(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitWords(this);
		}
	}

	public final WordsContext words() throws RecognitionException {
		WordsContext _localctx = new WordsContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_words);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(244); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(243);
					word();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(246); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class WordContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(HadesParser.VAR, 0); }
		public TerminalNode RAW_STRING() { return getToken(HadesParser.RAW_STRING, 0); }
		public TerminalNode ALPHANUMERIC() { return getToken(HadesParser.ALPHANUMERIC, 0); }
		public TerminalNode QUOTED_STRING() { return getToken(HadesParser.QUOTED_STRING, 0); }
		public TerminalNode UNCLOSED_QUOTED_STRING() { return getToken(HadesParser.UNCLOSED_QUOTED_STRING, 0); }
		public WordContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_word; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).enterWord(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof HadesListener ) ((HadesListener)listener).exitWord(this);
		}
	}

	public final WordContext word() throws RecognitionException {
		WordContext _localctx = new WordContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_word);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(248);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1015808L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0013\u00fb\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007"+
		"\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007"+
		"\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0001\u0000\u0001"+
		"\u0000\u0005\u0000-\b\u0000\n\u0000\f\u00000\t\u0000\u0001\u0001\u0003"+
		"\u00013\b\u0001\u0001\u0001\u0001\u0001\u0003\u00017\b\u0001\u0001\u0001"+
		"\u0001\u0001\u0003\u0001;\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001"+
		"?\b\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0003\u0002D\b\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0003\u0003K\b"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004\u0001"+
		"\u0004\u0003\u0004S\b\u0004\u0001\u0005\u0003\u0005V\b\u0005\u0001\u0005"+
		"\u0001\u0005\u0003\u0005Z\b\u0005\u0001\u0005\u0005\u0005]\b\u0005\n\u0005"+
		"\f\u0005`\t\u0005\u0001\u0005\u0003\u0005c\b\u0005\u0001\u0005\u0001\u0005"+
		"\u0003\u0005g\b\u0005\u0001\u0006\u0003\u0006j\b\u0006\u0001\u0006\u0001"+
		"\u0006\u0005\u0006n\b\u0006\n\u0006\f\u0006q\t\u0006\u0001\u0007\u0003"+
		"\u0007t\b\u0007\u0001\u0007\u0001\u0007\u0003\u0007x\b\u0007\u0001\u0007"+
		"\u0003\u0007{\b\u0007\u0001\b\u0003\b~\b\b\u0001\b\u0001\b\u0003\b\u0082"+
		"\b\b\u0001\b\u0005\b\u0085\b\b\n\b\f\b\u0088\t\b\u0001\b\u0003\b\u008b"+
		"\b\b\u0001\b\u0003\b\u008e\b\b\u0001\b\u0001\b\u0003\b\u0092\b\b\u0001"+
		"\b\u0003\b\u0095\b\b\u0001\t\u0001\t\u0005\t\u0099\b\t\n\t\f\t\u009c\t"+
		"\t\u0001\n\u0003\n\u009f\b\n\u0001\n\u0001\n\u0001\n\u0003\n\u00a4\b\n"+
		"\u0001\u000b\u0001\u000b\u0003\u000b\u00a8\b\u000b\u0001\f\u0001\f\u0003"+
		"\f\u00ac\b\f\u0001\f\u0004\f\u00af\b\f\u000b\f\f\f\u00b0\u0001\f\u0001"+
		"\f\u0003\f\u00b5\b\f\u0005\f\u00b7\b\f\n\f\f\f\u00ba\t\f\u0001\f\u0005"+
		"\f\u00bd\b\f\n\f\f\f\u00c0\t\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r"+
		"\u0005\r\u00c7\b\r\n\r\f\r\u00ca\t\r\u0001\u000e\u0003\u000e\u00cd\b\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0005\u000e\u00d2\b\u000e\n\u000e"+
		"\f\u000e\u00d5\t\u000e\u0001\u000e\u0003\u000e\u00d8\b\u000e\u0001\u000e"+
		"\u0003\u000e\u00db\b\u000e\u0001\u000f\u0003\u000f\u00de\b\u000f\u0001"+
		"\u000f\u0001\u000f\u0003\u000f\u00e2\b\u000f\u0004\u000f\u00e4\b\u000f"+
		"\u000b\u000f\f\u000f\u00e5\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0004\u0011\u00ee\b\u0011\u000b\u0011\f\u0011"+
		"\u00ef\u0001\u0012\u0001\u0012\u0001\u0013\u0004\u0013\u00f5\b\u0013\u000b"+
		"\u0013\f\u0013\u00f6\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u00be\u0000"+
		"\u0015\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018"+
		"\u001a\u001c\u001e \"$&(\u0000\u0001\u0001\u0000\u000f\u0013\u0113\u0000"+
		".\u0001\u0000\u0000\u0000\u00022\u0001\u0000\u0000\u0000\u0004C\u0001"+
		"\u0000\u0000\u0000\u0006J\u0001\u0000\u0000\u0000\bR\u0001\u0000\u0000"+
		"\u0000\nU\u0001\u0000\u0000\u0000\fi\u0001\u0000\u0000\u0000\u000es\u0001"+
		"\u0000\u0000\u0000\u0010}\u0001\u0000\u0000\u0000\u0012\u0096\u0001\u0000"+
		"\u0000\u0000\u0014\u009e\u0001\u0000\u0000\u0000\u0016\u00a7\u0001\u0000"+
		"\u0000\u0000\u0018\u00ab\u0001\u0000\u0000\u0000\u001a\u00c1\u0001\u0000"+
		"\u0000\u0000\u001c\u00da\u0001\u0000\u0000\u0000\u001e\u00e3\u0001\u0000"+
		"\u0000\u0000 \u00e7\u0001\u0000\u0000\u0000\"\u00ea\u0001\u0000\u0000"+
		"\u0000$\u00f1\u0001\u0000\u0000\u0000&\u00f4\u0001\u0000\u0000\u0000("+
		"\u00f8\u0001\u0000\u0000\u0000*-\u0003\u0014\n\u0000+-\u0003\u0002\u0001"+
		"\u0000,*\u0001\u0000\u0000\u0000,+\u0001\u0000\u0000\u0000-0\u0001\u0000"+
		"\u0000\u0000.,\u0001\u0000\u0000\u0000./\u0001\u0000\u0000\u0000/\u0001"+
		"\u0001\u0000\u0000\u00000.\u0001\u0000\u0000\u000013\u0005\t\u0000\u0000"+
		"21\u0001\u0000\u0000\u000023\u0001\u0000\u0000\u000034\u0001\u0000\u0000"+
		"\u000046\u0005\u0007\u0000\u000057\u0005\t\u0000\u000065\u0001\u0000\u0000"+
		"\u000067\u0001\u0000\u0000\u000078\u0001\u0000\u0000\u00008:\u0005\u000f"+
		"\u0000\u00009;\u0005\t\u0000\u0000:9\u0001\u0000\u0000\u0000:;\u0001\u0000"+
		"\u0000\u0000;<\u0001\u0000\u0000\u0000<>\u0005\b\u0000\u0000=?\u0005\t"+
		"\u0000\u0000>=\u0001\u0000\u0000\u0000>?\u0001\u0000\u0000\u0000?@\u0001"+
		"\u0000\u0000\u0000@A\u0003\u000e\u0007\u0000A\u0003\u0001\u0000\u0000"+
		"\u0000BD\u0005\t\u0000\u0000CB\u0001\u0000\u0000\u0000CD\u0001\u0000\u0000"+
		"\u0000DE\u0001\u0000\u0000\u0000EF\u0005\u0001\u0000\u0000FG\u0003\b\u0004"+
		"\u0000GH\u0003\u000e\u0007\u0000H\u0005\u0001\u0000\u0000\u0000IK\u0005"+
		"\t\u0000\u0000JI\u0001\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000KL\u0001"+
		"\u0000\u0000\u0000LM\u0005\u0002\u0000\u0000MN\u0003\b\u0004\u0000NO\u0003"+
		"\u000e\u0007\u0000O\u0007\u0001\u0000\u0000\u0000PS\u0003\n\u0005\u0000"+
		"QS\u0003\f\u0006\u0000RP\u0001\u0000\u0000\u0000RQ\u0001\u0000\u0000\u0000"+
		"S\t\u0001\u0000\u0000\u0000TV\u0005\t\u0000\u0000UT\u0001\u0000\u0000"+
		"\u0000UV\u0001\u0000\u0000\u0000VW\u0001\u0000\u0000\u0000WY\u0005\u0003"+
		"\u0000\u0000XZ\u0005\t\u0000\u0000YX\u0001\u0000\u0000\u0000YZ\u0001\u0000"+
		"\u0000\u0000Z^\u0001\u0000\u0000\u0000[]\u0003\u0016\u000b\u0000\\[\u0001"+
		"\u0000\u0000\u0000]`\u0001\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000"+
		"^_\u0001\u0000\u0000\u0000_b\u0001\u0000\u0000\u0000`^\u0001\u0000\u0000"+
		"\u0000ac\u0005\t\u0000\u0000ba\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000"+
		"\u0000cd\u0001\u0000\u0000\u0000df\u0005\u0004\u0000\u0000eg\u0005\t\u0000"+
		"\u0000fe\u0001\u0000\u0000\u0000fg\u0001\u0000\u0000\u0000g\u000b\u0001"+
		"\u0000\u0000\u0000hj\u0005\t\u0000\u0000ih\u0001\u0000\u0000\u0000ij\u0001"+
		"\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000ko\u0005\u0003\u0000\u0000"+
		"ln\u0003\u0016\u000b\u0000ml\u0001\u0000\u0000\u0000nq\u0001\u0000\u0000"+
		"\u0000om\u0001\u0000\u0000\u0000op\u0001\u0000\u0000\u0000p\r\u0001\u0000"+
		"\u0000\u0000qo\u0001\u0000\u0000\u0000rt\u0005\n\u0000\u0000sr\u0001\u0000"+
		"\u0000\u0000st\u0001\u0000\u0000\u0000tw\u0001\u0000\u0000\u0000ux\u0003"+
		"\u0010\b\u0000vx\u0003\u0012\t\u0000wu\u0001\u0000\u0000\u0000wv\u0001"+
		"\u0000\u0000\u0000xz\u0001\u0000\u0000\u0000y{\u0005\n\u0000\u0000zy\u0001"+
		"\u0000\u0000\u0000z{\u0001\u0000\u0000\u0000{\u000f\u0001\u0000\u0000"+
		"\u0000|~\u0005\t\u0000\u0000}|\u0001\u0000\u0000\u0000}~\u0001\u0000\u0000"+
		"\u0000~\u007f\u0001\u0000\u0000\u0000\u007f\u0081\u0005\u0005\u0000\u0000"+
		"\u0080\u0082\u0005\t\u0000\u0000\u0081\u0080\u0001\u0000\u0000\u0000\u0081"+
		"\u0082\u0001\u0000\u0000\u0000\u0082\u0086\u0001\u0000\u0000\u0000\u0083"+
		"\u0085\u0003\u0014\n\u0000\u0084\u0083\u0001\u0000\u0000\u0000\u0085\u0088"+
		"\u0001\u0000\u0000\u0000\u0086\u0084\u0001\u0000\u0000\u0000\u0086\u0087"+
		"\u0001\u0000\u0000\u0000\u0087\u008a\u0001\u0000\u0000\u0000\u0088\u0086"+
		"\u0001\u0000\u0000\u0000\u0089\u008b\u0005\t\u0000\u0000\u008a\u0089\u0001"+
		"\u0000\u0000\u0000\u008a\u008b\u0001\u0000\u0000\u0000\u008b\u008d\u0001"+
		"\u0000\u0000\u0000\u008c\u008e\u0005\n\u0000\u0000\u008d\u008c\u0001\u0000"+
		"\u0000\u0000\u008d\u008e\u0001\u0000\u0000\u0000\u008e\u008f\u0001\u0000"+
		"\u0000\u0000\u008f\u0091\u0005\u0006\u0000\u0000\u0090\u0092\u0005\t\u0000"+
		"\u0000\u0091\u0090\u0001\u0000\u0000\u0000\u0091\u0092\u0001\u0000\u0000"+
		"\u0000\u0092\u0094\u0001\u0000\u0000\u0000\u0093\u0095\u0005\f\u0000\u0000"+
		"\u0094\u0093\u0001\u0000\u0000\u0000\u0094\u0095\u0001\u0000\u0000\u0000"+
		"\u0095\u0011\u0001\u0000\u0000\u0000\u0096\u009a\u0005\u0005\u0000\u0000"+
		"\u0097\u0099\u0003\u0014\n\u0000\u0098\u0097\u0001\u0000\u0000\u0000\u0099"+
		"\u009c\u0001\u0000\u0000\u0000\u009a\u0098\u0001\u0000\u0000\u0000\u009a"+
		"\u009b\u0001\u0000\u0000\u0000\u009b\u0013\u0001\u0000\u0000\u0000\u009c"+
		"\u009a\u0001\u0000\u0000\u0000\u009d\u009f\u0005\n\u0000\u0000\u009e\u009d"+
		"\u0001\u0000\u0000\u0000\u009e\u009f\u0001\u0000\u0000\u0000\u009f\u00a3"+
		"\u0001\u0000\u0000\u0000\u00a0\u00a4\u0003\u0018\f\u0000\u00a1\u00a4\u0003"+
		"\u0004\u0002\u0000\u00a2\u00a4\u0003\u0006\u0003\u0000\u00a3\u00a0\u0001"+
		"\u0000\u0000\u0000\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a3\u00a2\u0001"+
		"\u0000\u0000\u0000\u00a4\u0015\u0001\u0000\u0000\u0000\u00a5\u00a8\u0003"+
		"\u001a\r\u0000\u00a6\u00a8\u0003\u001c\u000e\u0000\u00a7\u00a5\u0001\u0000"+
		"\u0000\u0000\u00a7\u00a6\u0001\u0000\u0000\u0000\u00a8\u0017\u0001\u0000"+
		"\u0000\u0000\u00a9\u00ac\u0003\u001a\r\u0000\u00aa\u00ac\u0003\u001c\u000e"+
		"\u0000\u00ab\u00a9\u0001\u0000\u0000\u0000\u00ab\u00aa\u0001\u0000\u0000"+
		"\u0000\u00ac\u00b8\u0001\u0000\u0000\u0000\u00ad\u00af\u0005\f\u0000\u0000"+
		"\u00ae\u00ad\u0001\u0000\u0000\u0000\u00af\u00b0\u0001\u0000\u0000\u0000"+
		"\u00b0\u00ae\u0001\u0000\u0000\u0000\u00b0\u00b1\u0001\u0000\u0000\u0000"+
		"\u00b1\u00b4\u0001\u0000\u0000\u0000\u00b2\u00b5\u0003\u001a\r\u0000\u00b3"+
		"\u00b5\u0003\u001c\u000e\u0000\u00b4\u00b2\u0001\u0000\u0000\u0000\u00b4"+
		"\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b7\u0001\u0000\u0000\u0000\u00b6"+
		"\u00ae\u0001\u0000\u0000\u0000\u00b7\u00ba\u0001\u0000\u0000\u0000\u00b8"+
		"\u00b6\u0001\u0000\u0000\u0000\u00b8\u00b9\u0001\u0000\u0000\u0000\u00b9"+
		"\u00be\u0001\u0000\u0000\u0000\u00ba\u00b8\u0001\u0000\u0000\u0000\u00bb"+
		"\u00bd\u0005\f\u0000\u0000\u00bc\u00bb\u0001\u0000\u0000\u0000\u00bd\u00c0"+
		"\u0001\u0000\u0000\u0000\u00be\u00bf\u0001\u0000\u0000\u0000\u00be\u00bc"+
		"\u0001\u0000\u0000\u0000\u00bf\u0019\u0001\u0000\u0000\u0000\u00c0\u00be"+
		"\u0001\u0000\u0000\u0000\u00c1\u00c2\u0003\u001c\u000e\u0000\u00c2\u00c3"+
		"\u0005\u000e\u0000\u0000\u00c3\u00c8\u0003\u001c\u000e\u0000\u00c4\u00c5"+
		"\u0005\u000e\u0000\u0000\u00c5\u00c7\u0003\u001c\u000e\u0000\u00c6\u00c4"+
		"\u0001\u0000\u0000\u0000\u00c7\u00ca\u0001\u0000\u0000\u0000\u00c8\u00c6"+
		"\u0001\u0000\u0000\u0000\u00c8\u00c9\u0001\u0000\u0000\u0000\u00c9\u001b"+
		"\u0001\u0000\u0000\u0000\u00ca\u00c8\u0001\u0000\u0000\u0000\u00cb\u00cd"+
		"\u0005\t\u0000\u0000\u00cc\u00cb\u0001\u0000\u0000\u0000\u00cc\u00cd\u0001"+
		"\u0000\u0000\u0000\u00cd\u00ce\u0001\u0000\u0000\u0000\u00ce\u00d3\u0003"+
		"&\u0013\u0000\u00cf\u00d0\u0005\t\u0000\u0000\u00d0\u00d2\u0003&\u0013"+
		"\u0000\u00d1\u00cf\u0001\u0000\u0000\u0000\u00d2\u00d5\u0001\u0000\u0000"+
		"\u0000\u00d3\u00d1\u0001\u0000\u0000\u0000\u00d3\u00d4\u0001\u0000\u0000"+
		"\u0000\u00d4\u00d7\u0001\u0000\u0000\u0000\u00d5\u00d3\u0001\u0000\u0000"+
		"\u0000\u00d6\u00d8\u0005\t\u0000\u0000\u00d7\u00d6\u0001\u0000\u0000\u0000"+
		"\u00d7\u00d8\u0001\u0000\u0000\u0000\u00d8\u00db\u0001\u0000\u0000\u0000"+
		"\u00d9\u00db\u0003\u001e\u000f\u0000\u00da\u00cc\u0001\u0000\u0000\u0000"+
		"\u00da\u00d9\u0001\u0000\u0000\u0000\u00db\u001d\u0001\u0000\u0000\u0000"+
		"\u00dc\u00de\u0005\t\u0000\u0000\u00dd\u00dc\u0001\u0000\u0000\u0000\u00dd"+
		"\u00de\u0001\u0000\u0000\u0000\u00de\u00df\u0001\u0000\u0000\u0000\u00df"+
		"\u00e1\u0003\"\u0011\u0000\u00e0\u00e2\u0005\t\u0000\u0000\u00e1\u00e0"+
		"\u0001\u0000\u0000\u0000\u00e1\u00e2\u0001\u0000\u0000\u0000\u00e2\u00e4"+
		"\u0001\u0000\u0000\u0000\u00e3\u00dd\u0001\u0000\u0000\u0000\u00e4\u00e5"+
		"\u0001\u0000\u0000\u0000\u00e5\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e6"+
		"\u0001\u0000\u0000\u0000\u00e6\u001f\u0001\u0000\u0000\u0000\u00e7\u00e8"+
		"\u0003(\u0014\u0000\u00e8\u00e9\u0005\u000e\u0000\u0000\u00e9!\u0001\u0000"+
		"\u0000\u0000\u00ea\u00eb\u0003$\u0012\u0000\u00eb\u00ed\u0005\r\u0000"+
		"\u0000\u00ec\u00ee\u0003(\u0014\u0000\u00ed\u00ec\u0001\u0000\u0000\u0000"+
		"\u00ee\u00ef\u0001\u0000\u0000\u0000\u00ef\u00ed\u0001\u0000\u0000\u0000"+
		"\u00ef\u00f0\u0001\u0000\u0000\u0000\u00f0#\u0001\u0000\u0000\u0000\u00f1"+
		"\u00f2\u0005\u000f\u0000\u0000\u00f2%\u0001\u0000\u0000\u0000\u00f3\u00f5"+
		"\u0003(\u0014\u0000\u00f4\u00f3\u0001\u0000\u0000\u0000\u00f5\u00f6\u0001"+
		"\u0000\u0000\u0000\u00f6\u00f4\u0001\u0000\u0000\u0000\u00f6\u00f7\u0001"+
		"\u0000\u0000\u0000\u00f7\'\u0001\u0000\u0000\u0000\u00f8\u00f9\u0007\u0000"+
		"\u0000\u0000\u00f9)\u0001\u0000\u0000\u0000-,.26:>CJRUY^bfioswz}\u0081"+
		"\u0086\u008a\u008d\u0091\u0094\u009a\u009e\u00a3\u00a7\u00ab\u00b0\u00b4"+
		"\u00b8\u00be\u00c8\u00cc\u00d3\u00d7\u00da\u00dd\u00e1\u00e5\u00ef\u00f6";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}