# lite
The lite language interpreter is written in C++, although it was originally written completely in C.

Lite is a *simple* language consisting of basic commands separated from their parameters by *commas*.

Commands:
1. add - *add,int,int,...,int* (As many integer parameters as you wish can be added together)
2. sub - *sub,int,int,...,int* (All integers following the first parameter will be subtracted from the first parameter)
3. mul - *mul,int,int,...,int* (Just like the add command, as many integer parameters as you wish can be multiplied together)
4. div - *div,int,int,...,int* (Like the sub command, all integers following the first parameter will divide the first parameter)
5. run - *run,filepath* (runs a lite script at the provided filepath)

Commands can be **nested** within one another using brackets, for example:

```add,(sub,(mul,6,5),15),1``` is valid syntax and would return the integer 16.
