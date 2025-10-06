# CSP
 a constraint satisfaction problem contains three components:
- A set of variables
- A set of values (domain)
- A set of constraints (conditions)

we call a consistent assignment a set of values for the variables that satisfies all the constraints.
- A solution is a consistent assignment that assigns a value to every variable.

# CSP Exam  ple
- A map coloring problem is a CSP where the variables are the regions of the map, the values are the colors, and the constraints are that adjacent regions must be different colors.
- A Sudoku puzzle is a CSP where the variables are the cells of the grid, the values are the numbers 1-9, and the constraints are that each row, column, and 3x3 subgrid must contain all the numbers 1-9 exactly once.
- A N-Queens problem is a CSP where the variables are the positions of the queens on the chessboard, the values are the rows of the chessboard, and the constraints are that no two queens can be in the same row, column, or diagonal.

## some definitions
- A constraint is a relation between a subset of the variables.
- A unary constraint is a constraint that involves only one variable.
- A binary constraint is a constraint that involves two variables.
- A k-ary constraint is a constraint that involves k variables.
- A global constraint is a constraint that involves all the variables in the CSP.
- A constraint graph is a graph where the nodes are the variables and the edges are the constraints.

## preference constraints
- A preference constraint is a constraint that specifies a preference for a certain value or set of values.
- absolute constraints are constraints that must be satisfied for a solution to be valid.
- preference constraints are constraints that specify a preference for a certain value or set of values. it could be encoded as a costs on individual variable assignments.

## Constraint propagation
1. **node consistency**: A variable is node consistent if all the values in its domain satisfy the unary constraints on it.
2. **arc consistency**: A variable is arc consistent if for every value in its domain, there is a value in the domain of the other variable that satisfies the binary constraint between them.
3. **path consistency**: A variable is path consistent if for every pair of values in its domain, there is a value in the domain of the other variable that satisfies the binary constraints between them.