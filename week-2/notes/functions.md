# Functions

Also known as procedures, methods (object-oriented languages), or subroutines

## What are functions?

A *black box* with a set of 0+ inputs and 1 output.

For example,

    func(a,b,c) // 3 inputs & 1 output

We don't need to know the underlying implementation, \
we just need to ouput.

## Why use functions?

* Organization: Break complicated problems into manageable sub-parts.
* Simplification: Smaller components are easier to design, debug, and implement.
* Reusability: Can be recycled; only need to be written once.

## Function Declarations

Functions need to be declared at th top of the code, even before main().

Standard form:

    return-type name(argument-list);

* return-type: the kind of variable the function will output.
* name: function name.
* argument-list: comma-separated set of inputs, each with a type and a name.

## Function Definitions

Function is defined at the top with a semicolon
    
    return-type name(argument-list);

    int main(void);
    {
    
    }
    
    return-type name(argument-list)
    {
        // function body
        return return-value;    
    }

## Function Miscellany

Function sometimes doesn't have an input:

    int main(void);

Function sometimes don't also have an output:

    void name(argument-list);
