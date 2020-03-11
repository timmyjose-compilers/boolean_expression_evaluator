# Boolean Expression Parser and Evaluator

A simple parser (and evaluator) for boolean expressions. We take in a string representing a boolean expression expressed in terms of variables, and then
we evaluate the expression, generating its truth table.

For instance, suppose we are given an expression like so: `(p ^ q) -> r`. Then we have three variables, meaning a total of 8 possible states. We then proceed to generate the
truth table for the expression by evaluating the expression for all the possible states. For practical reasons, we restrict the number of such variables to 10 (meaning a total 
posisble truth table size of 1024 states).

The evaluation of this expression might proceed as follows:

## Scanning

Scanning will generate the following token stream:

```

[
{
  kind: 'LPAREN',
  spelling: '('
},
{
  kind: 'VARIABLE',
  spelling: 'p'
},
{
  kind: 'OPERATOR',
  spelling: '^'
},
{
  kind: 'VARIABLE',
  spelling: 'q'
},
{
  kind: 'RPAREN',
  spelling: ')'
},
{
  kind: 'OPERATOR',
  spelling: '->'
},
{
  kind: 'VARIABLE',
  spelling: 'r'
}
]

```

## Parsing

Parsing this token stream will produce the following AST:

```

{
  type: 'ImplicationExpression',
  antecedent: 
  { 
   type: 'AndExpression',
   left: 
    {
       type: 'Var',
       value: 'p'
    },
   right: 
    {
      type: 'Var',
      value: 'q'
      }
     },
  consequent: 
    {
     type: 'Var',
     value: 'r'
     }
}

```

## Evaluation

To evaluate the boolean expresson, we will need to provide the evaluator with values for each of the unique variables in the expression. The evaluator will then walk the AST and 
generate the final truth value.

### Generating Truth Tables

Given that we know the unique list of variables for a (valid) boolean expression, we can then generate all the possible states, pass each combination of state onto the evaluator, and then compare the resulting values to generate the truth table for the whole expression.