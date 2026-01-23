# Command-Line Arguments

To collect **command-line arguments** from the user,
main() must be declared as:

    int main(int argc, string argv[])
    {   

## argc (argument count)

This ineger-type variable store the **number** of
command-line arguments the user typed when the program was executed.

| command                 | argc |
| :---------------------: | :--: |
| ./program               | 1    |
| ./program input1 input2 | 3    |

## argv (argument vector)

This **array of strings** stores, one string per element.

* The 1st element of argv: argv[0]
* The last element of argv: argv[argc-1]

    ./program input1 input2

| argv indicies | argv contents |
| :-----------: | :-----------: |
| argv[0]       | "/.greedy"    |
| argv[1]       | "input1"      |
| argv[2]       | "input2"      |
| argv[3]       |               |
