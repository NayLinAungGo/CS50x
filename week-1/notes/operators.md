# Operators in C
## Assignment Operator
Equal sign (=)

## Arithmetic Operators
- add (+)
- subtract (-)
- multiply (*)
- divide (/)
- modulus (%)

    x = x * 5;
    x *= 5;

    x++; // increment by 1
    x--; // decrement by 1

## Boolean Expressions
Every *nonzero* value is equavalent to **true**, and zero is **false**.

## Logical Operators
### Logical AND (&&)
true if and only if both operands are true, otherwise false.

| x     	| y     	| (x && y) 	|
|-------	|-------	|----------	|
| true  	| true  	| true     	|
| true  	| false 	| false    	|
| false 	| true  	| false    	|
| false 	| false 	| false    	|

### Logical OR (||)
true if and only if at least one operand is true, otherwise false.

| x     	| y     	| (x && y) 	|
|-------	|-------	|----------	|
| true  	| true  	| true     	|
| true  	| false 	| true    	|
| false 	| true  	| true    	|
| false 	| false 	| false    	|

### Logical NOT (!)
invert the value of its operand.
| x     	| !x    	|
|-------	|-------	|
| true  	| false 	|
| false 	| true  	|o

## Relational Operators
- Less than (x < y)
- Less than or equal to (x <= y)
- Greater than (x > y)
- Greater than of equal to (x >= y)
- Equality (x == y)
- Inequality (x != y)
