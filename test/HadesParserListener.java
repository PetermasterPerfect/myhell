// Generated from HadesParser.g4 by ANTLR 4.13.0
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link HadesParser}.
 */
public interface HadesParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link HadesParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(HadesParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(HadesParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#sentences}.
	 * @param ctx the parse tree
	 */
	void enterSentences(HadesParser.SentencesContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#sentences}.
	 * @param ctx the parse tree
	 */
	void exitSentences(HadesParser.SentencesContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#pipe}.
	 * @param ctx the parse tree
	 */
	void enterPipe(HadesParser.PipeContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#pipe}.
	 * @param ctx the parse tree
	 */
	void exitPipe(HadesParser.PipeContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#sentence}.
	 * @param ctx the parse tree
	 */
	void enterSentence(HadesParser.SentenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#sentence}.
	 * @param ctx the parse tree
	 */
	void exitSentence(HadesParser.SentenceContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#assignments}.
	 * @param ctx the parse tree
	 */
	void enterAssignments(HadesParser.AssignmentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#assignments}.
	 * @param ctx the parse tree
	 */
	void exitAssignments(HadesParser.AssignmentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#unclosedPipe}.
	 * @param ctx the parse tree
	 */
	void enterUnclosedPipe(HadesParser.UnclosedPipeContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#unclosedPipe}.
	 * @param ctx the parse tree
	 */
	void exitUnclosedPipe(HadesParser.UnclosedPipeContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(HadesParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(HadesParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#varName}.
	 * @param ctx the parse tree
	 */
	void enterVarName(HadesParser.VarNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#varName}.
	 * @param ctx the parse tree
	 */
	void exitVarName(HadesParser.VarNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#words}.
	 * @param ctx the parse tree
	 */
	void enterWords(HadesParser.WordsContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#words}.
	 * @param ctx the parse tree
	 */
	void exitWords(HadesParser.WordsContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#word}.
	 * @param ctx the parse tree
	 */
	void enterWord(HadesParser.WordContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#word}.
	 * @param ctx the parse tree
	 */
	void exitWord(HadesParser.WordContext ctx);
}