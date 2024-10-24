// Generated from Hades.g4 by ANTLR 4.13.0
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link HadesParser}.
 */
public interface HadesListener extends ParseTreeListener {
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
	 * Enter a parse tree produced by {@link HadesParser#functionDefinition}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefinition(HadesParser.FunctionDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#functionDefinition}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefinition(HadesParser.FunctionDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#whileLoop}.
	 * @param ctx the parse tree
	 */
	void enterWhileLoop(HadesParser.WhileLoopContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#whileLoop}.
	 * @param ctx the parse tree
	 */
	void exitWhileLoop(HadesParser.WhileLoopContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#ifStatement}.
	 * @param ctx the parse tree
	 */
	void enterIfStatement(HadesParser.IfStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#ifStatement}.
	 * @param ctx the parse tree
	 */
	void exitIfStatement(HadesParser.IfStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#conditionBlock}.
	 * @param ctx the parse tree
	 */
	void enterConditionBlock(HadesParser.ConditionBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#conditionBlock}.
	 * @param ctx the parse tree
	 */
	void exitConditionBlock(HadesParser.ConditionBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#closedConditionBlock}.
	 * @param ctx the parse tree
	 */
	void enterClosedConditionBlock(HadesParser.ClosedConditionBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#closedConditionBlock}.
	 * @param ctx the parse tree
	 */
	void exitClosedConditionBlock(HadesParser.ClosedConditionBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#unclosedConditionBlock}.
	 * @param ctx the parse tree
	 */
	void enterUnclosedConditionBlock(HadesParser.UnclosedConditionBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#unclosedConditionBlock}.
	 * @param ctx the parse tree
	 */
	void exitUnclosedConditionBlock(HadesParser.UnclosedConditionBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#codeBlock}.
	 * @param ctx the parse tree
	 */
	void enterCodeBlock(HadesParser.CodeBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#codeBlock}.
	 * @param ctx the parse tree
	 */
	void exitCodeBlock(HadesParser.CodeBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#closedCodeBlock}.
	 * @param ctx the parse tree
	 */
	void enterClosedCodeBlock(HadesParser.ClosedCodeBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#closedCodeBlock}.
	 * @param ctx the parse tree
	 */
	void exitClosedCodeBlock(HadesParser.ClosedCodeBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#unclosedCodeBlock}.
	 * @param ctx the parse tree
	 */
	void enterUnclosedCodeBlock(HadesParser.UnclosedCodeBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#unclosedCodeBlock}.
	 * @param ctx the parse tree
	 */
	void exitUnclosedCodeBlock(HadesParser.UnclosedCodeBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#blockContent}.
	 * @param ctx the parse tree
	 */
	void enterBlockContent(HadesParser.BlockContentContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#blockContent}.
	 * @param ctx the parse tree
	 */
	void exitBlockContent(HadesParser.BlockContentContext ctx);
	/**
	 * Enter a parse tree produced by {@link HadesParser#conditionContent}.
	 * @param ctx the parse tree
	 */
	void enterConditionContent(HadesParser.ConditionContentContext ctx);
	/**
	 * Exit a parse tree produced by {@link HadesParser#conditionContent}.
	 * @param ctx the parse tree
	 */
	void exitConditionContent(HadesParser.ConditionContentContext ctx);
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