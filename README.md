**Objective:**
The objective was to develop a Syntax Analyzer for MINI C++ using C++ and the Recursive Descent Parser technique. The analyzer checks whether a sequence of tokens (generated by the previously implemented Lexical Analyzer) conforms to the provided context-free grammar (CFG).

**Implementation:**

**Parsing Technique Used:** Recursive Descent Parser

**Input Handling:**

The Syntax Analyzer reads a sequence of tokens from a text file (input.txt), representing the source code of a MINI C++ program.

**Context-Free Grammar (CFG):**

The CFG provided in the assignment was directly implemented using the Recursive Descent Parsing method. Each non-terminal in the CFG corresponds to a function in the code that processes the input tokens according to the grammar rules.

**Key Features:**

**Recursive Descent Parsing:**

The Recursive Descent Parser systematically analyzes the token sequence by recursively applying the production rules of the CFG.
Each production rule in the CFG was translated into a corresponding recursive function in C++.

**Error Handling:**

The parser includes mechanisms to detect and report syntax errors, including mismatches with expected tokens and invalid token sequences.

**Output:**

The results of the syntax analysis are output to a file (output.txt). For valid input, the output indicates that the syntax is correct. For invalid input, the output includes error messages specifying the nature and location of the syntax errors.

**Testing:**

**Sample Program 1:** Successfully parsed with no errors, confirming that the Syntax Analyzer correctly identifies valid MINI C++ syntax.

**Sample Program 2:** Detected and reported syntax errors, demonstrating the analyzer's ability to handle invalid syntax.

**Submission:**
The documented steps, including the CFG, source code, screenshots of results, and input/output files, are prepared and submitted as per the assignment guidelines.
