# Kinx Quick Reference Guide

## 1st Step

### Hello, world.

You can write the program on the top level of source.
Prepare the following file named as `hello.kx`.

```javascript:hello.kx
System.println("hello, world.");
```

Execute it as follows, and you will get it.

```
$ ./kinx hello.kx
hello, world.
```

Kinx can be executed without compiling.

### Import Library

You can import standard or your own library with `import` directive.

```javascript
import LibraryName;
```

### Comment

Here is the comment.
You can use Javacript or C/C++ style.

```javascript
/* Comment */
// Comment
```

You can also use the general script style comment started with `#`.

```coffee
# Comment
```

### Declare Variable

Use `var` for declaration.

```javascript
var a = 100;
```

### Data Types

#### List of Data Types

Here is data types you can use.
As using CheckProperty, you can check the type of a variable.

|   Type    |        CheckProperty        |            Example            |                                 Meaning                                  |
| --------- | --------------------------- | :---------------------------: | ------------------------------------------------------------------------ |
| Undefined | `isUndefined`               |             null              | The value is not defined. Initial value.                                 |
| Integer   | `isInteger`, `isBigInteger` |           100, 0x02           | Integer value. Converting automatically between integer and big integer. |
| Double    | `isDouble`                  |              1.5              | Double value.                                                            |
| String    | `isString`                  |         "aaa", 'bbb'          | String value. Double quote and single quote is the same meaning.         |
| Binary    | `isBinary`                  |            <1,2,3>            | Byte array. Each value is 0x00-0xFF.                                     |
| Array     | `isArray`, `isObject`       |         [1,a,["aaa"]]         | Array of any data.                                                       |
| Object    | `isObject`                  |        { a: 1, b: x }         | Key-value data structure like JSON.                                      |
| Function  | `isFunction`                | function(){},<br/>&() => expr | Function object like function, lambda, or native function.               |

Note that the Array is a part of Object.
One Object can have both array data and key-value structure.

#### Numbers

##### Assignment

Numbers can be used as a direct value, and also it can be assigned to a variable.
Constant integer number can have a '_' character without meaning for only easy-to-read.

```javascript
var i = 2;
var j = 100_000_000;
var num = 1.234;
```

##### Arithmetic Operations

Here is basic arithmetic operations.
If the result becomes not to be integer, it is automatically converted to double.

```javascript
num = 3 + 2;    // 5
num = 3 - 2;    // 1
num = 3 * 2;    // 6
num = 3 / 2;    // 1.5
num = 3 % 2;    // 1
```

##### Increment and Decrement

Kinx supports both prefix and postfix type of increment/decrement.

```javascript
var a = 10;
System.println(a++);    // 10
System.println(++a);    // 12
System.println(a--);    // 12
System.println(--a);    // 10
```

#### String

##### Basic Style

String value is shown basically as double-quoted string or single-quoted string.
Quotation style is nothing different except escaping quote-character.

```javascript
var a = "\"aaa\", 'bbb'";
var b = '"aaa", \'bbb\'';
System.println(a == b ? "same" : "different");  # same
```

##### Inner Expression

String value can have **inner expression** like example below.

```javascript
for (var i = 0; i < 10; ++i) {
    System.println("i = %{i}, i * 2 = %{i * 2}");
}
```

You can write any expressions between `%{` and `}` inside string.
Here is the result.

```
i = 0, i * 2 = 0
i = 1, i * 2 = 2
i = 2, i * 2 = 4
i = 3, i * 2 = 6
i = 4, i * 2 = 8
i = 5, i * 2 = 10
i = 6, i * 2 = 12
i = 7, i * 2 = 14
i = 8, i * 2 = 16
i = 9, i * 2 = 18
```

Here is another example.

```javascript
var a = 100;
var str = "You can put expression like %{a * (a + 2)} as inner expression in the string.";
System.println(str);
```

Here is the result.

```
You can put expression like 10200 as inner expression in the string.
```

##### Non-Escaping Style

By using the following style, you can use a raw text
without any escaping except for starting or ending characters.
In this style, you can use newline, tab, etc.

```javascript
var a = 100;
var b = 10;
var str = %{
This is a string without escaping control characters.
New line is available in this area.
{ and } can be nested here.
};
System.println(str);
var str = %-{
This is a string without escaping control characters.
New line is available in this area.
But newlines at the beginning and the end are removed when starting with '%-'.
};
System.println(str);
```

Here is the result.

```

This is a string without escaping control characters.
New line is available in this area.
{ and } can be nested here.

This is a string without escaping control characters.
New line is available in this area.
But newlines at the beginning and the end are removed when starting with '%-'.
```

About available characters of starting and ending characters, see below.

| Start |  End  |
| :---: | :---: |
|  `{`  |  `}`  |
|  `(`  |  `)`  |
|  `[`  |  `]`  |
|  `<`  |  `>`  |

Starting character is always following `%`.
And starting and ending character can be included in the string as long as it is nested.
If you want to use it without nesting,
escaping by `\` can be available only for the starting and ending characters.

If you use directly `%{` and `}`,
the newlines right after `%{` and right before `}` has been included into the text.
Use `%-{` instead of `%{` when you want to trim the newlines,
or use `.trim()` method for the string.

You can also use the following characters with the style like `%|...|`.
Those are the same for starting and ending.

*   `|`, `!`, `^`, `~`, `_`, `.`, `,`, `+`, `*`, `@`, `&`, `$`, `:`, `;`, `?`, `'`, `"`.

Note that the methods for string value will be described at another document, but it is under construction now.

#### Array

Array is the list of any values, which is integer, double, array, object, function, and so on.
Here is the example below.

```javascript
var a = [1,2,3];
var b = [a, 1, 2];
System.println(b[0][2]);    // 3
```

The index can be a negative value.
It means accessing array from the end item.

```javascript
var a = [1,2,3];
System.println(a[-1]);      // 3
```

Note that the methods for array will be described at another document, but it is under construction now.

#### Object

Object is the value having a property as string.
It is like a JSON structure.
Here is the example below.

```javascript
var a = { a: 100 };
a.b = 1_000;
a["c"] = 10_000;
System.println(a.a);        // 100
System.println(a.b);        // 1000
System.println(a.c);        // 10000
```

The property access is the same style as array index.
And also you can use `.`(dot) instead of `[]` for convenience.

In fact, Array and Object is the same internally and those can be sharing the value in one object.

```javascript
var a = { a: 100 };
a.b = 1_000;
a["c"] = 10_000;
a[1] = 10;
System.println(a[1]);       // 10
System.println(a.a);        // 100
System.println(a.b);        // 1000
System.println(a.c);        // 10000
```

The property for the type checking of `isArray` becomes true
only when the object has a array value.

#### Function

##### `function`

`function` is the object, and can be assigned to a variable.
And a function name is a variable name which have a function object itself.

See example below.

```javascript
function name(a, b) {
    return a + b;
}
var other = name;
System.println(other(1, 2));    // 3
```

A function has a lexical scope, so you can also use it as a closure.

```javascript
function newCounter() {
    var i = 0;          // a lexical variable.

    return function() { // an anonymous function.
        ++i;            // a reference to a lexical variable.
        return i;
    };
}

var c1 = newCounter();
System.println(c1()); // 1
System.println(c1()); // 2
System.println(c1()); // 3
System.println(c1()); // 4
System.println(c1()); // 5
```

You can use an anonymous function inside an expression as above.

##### `native`

`native` function is the function which is compiled to the machine native code.
It is very fast but there are some limitations.

First, please look at the performance.

```javascript
function fib(n) {
    if (n < 3) return n;
    return fib(n-2) + fib(n-1);
}

System.println("fib(34) = ", fib(34));
```

```
$ time ./kinx examples/fib.kx
fib(34) = 9227465

real    0m0.578s
user    0m0.516s
sys     0m0.016s
```

In my environment, calculating a fibonacci number 34 takes about 500 ms.

```javascript
native fib(n) {
    if (n < 3) return n;
    return fib(n-2) + fib(n-1);
}

System.println("fib(34) = ", fib(34));
```

```
$ time ./kinx examples/native_fib.kx
fib(34) = 9227465

real    0m0.092s
user    0m0.031s
sys     0m0.000s
```

After replacing `function` by `native`, it was shortened to 30 ms.

But there are limitations below.

*   Currently you can use the type of integer only.
*   Integer value is not automatically promoted to big integer, just overfow it.
*   Can not call a script function. Only can call a native function.
*   `switch-case` is not supported.
*   Forward declaration of a native function is not supported.
*   Can access to the lexical scope and variables, but only for an integer value.
*   Exceptions with `try-catch-finally` is supported, but a stack trace is not available.
*   Support 64bit only. Libraries are supporting x64, ARM, MIPS, but sorry I can not test it except x64 Windows or Linux.

I will challenge to remove those, but the performance may be a little slower.

#### Class

Kinx is strongly supporting OOP (Object Oriented Programming).

Class is a definition of an object structure.
When you define the class and instanciate it via `new` operator,
the object will be created following the class structure.

Inherit mechanism is also supported.

##### Class Definition

The basic shape of class definition is as below.

```javascript
class ClassName {

    var privateVar_;

    private initialize() {
        privateVar_ = 0;
        this.publicVar = 0;
    }

    /* private method */
    private method1() { /* ... */ }
    private method2() { /* ... */ }

    /* public method */
    public method3() { /* ... */ }
    public method4() { /* ... */ }

}

var obj = new ClassName();
```

Public members are defined as a property of `this` object.
The `initialize` method is a special method for instanciate by `new` operator.
This `initialize` method is automatically called at the end of creating a class instance.
Therefore you can initialize instance internal state via this method.

By the way, this `initialize` method can be `public` instead of `private`.
If you set it to `public`,
you can call `initialize` method via class instance as same as other public methods.

##### Constructor

The class constructor has arguments like below.

```javascript
class ClassName(arg0, arg1) {

    private initialize() {
        privateVar_ = arg0;
        this.publicVar = arg1;
    }

    /* ... */
}

var obj = new ClassName(1, 2);
```

Note that all arguments of a constructor are **NOT** arguments of `initialize` method.

##### Class Inheritance

Use `:` with a base class name before class block like below.

```javascript
class ClassName : BaseClass {
    /* ... */
}
```

Of course you can use argument and pass it to the base class's constructor.

```javascript
class ClassName(a0, a1) : BaseClass(a1) {
    /* ... */
}
```

You can use a special instance named as `super` to call the methods of a base class.
If the method is overridden, there is no chance to access a base class's method if you do not use `super`.

```javascript
class BaseClass(a0) {
    public method1() { /* ... */ }
}
class ClassName(a0, a1) : BaseClass(a1) {
    public method1() { /* ... */ }
    public method2() {
        method1();          // This is calling ClassName class's method.
        this.method1();     // This is also calling ClassName class's method.
        super.method1();    // This is calling BaseClass class's method.
    }
}
```

##### `instanceOf`

Every class instance has `instanceOf` method automatically.
The argument of this method is a class name like `ClassName`.
This returns **true** if the object is an instance of the specified class.
This also returns **true** even if the object is an instance of a base class.

```javascript
class BaseClass {}
class ClassName : BaseClass {}
var x = new BaseClass();
var y = new ClassName();
System.println(x.instanceOf(BaseClass));    // 1
System.println(x.instanceOf(ClassName));    // 0
System.println(y.instanceOf(BaseClass));    // 1
System.println(y.instanceOf(ClassName));    // 1
```

##### `@` as Alias of `this.`

You can use `@` instead of `this.`, which is `this` plus `.`(dot).
Here is an example.

```javascript
class ClassName(arg0, arg1) {

    private initialize() {
        privateVar_ = arg0;
        @publicVar = arg1;  // Same as `this.publicVar = arg1;`
    }

    /* ... */
}

var obj = new ClassName(1, 2);
```

## Expression

### Priority Order

Here is the expression's priority order.
The order of upside of the list is higher.

|   #   |     Type     |                                     Excample                                     |
| :---: | ------------ | -------------------------------------------------------------------------------- |
|   1   | Factor       | Variable, Number, String, ...                                                    |
|   2   | Postfix      | `++`, `--`, `[]`, `.`, `()`                                                      |
|   3   | Prefix       | `!`, `+`, `-`, `++`, `--`                                                        |
|   4   | Mul,...      | `*`, `/`, `%`                                                                    |
|   5   | Add,...      | `+`, `-`                                                                         |
|   6   | Shift        | `<<`, `>>`                                                                       |
|   7   | Compare      | `<`, `>`, `>=`, `<=`                                                             |
|   8   | Equals       | `==`, `!=`                                                                       |
|   9   | Bit AND      | `&`                                                                              |
|  10   | Bit XOR      | `^`                                                                              |
|  11   | Bit OR       | `&#124;`                                                                         |
|  12   | Logical AND  | `&&`                                                                             |
|  13   | Logical OR   | `&#124;&#124;`                                                                   |
|  14   | Ternary Expr | ` ? : `, `function(){}`                                                          |
|  15   | Assignment   | `=`, `+=`, `-=`, `*=`. `/=`. `%=`, `&=`, `&#124;=`, `^=`, `&&=`, `&#124;&#124;=` |

## Statement
### Basic Statement
#### Expression Statement

Expression statement is the statement of expression with ';' at the end.
Here is the example below.

```javascript
a = 10 * b;
```

Expression statement can have a if modifier like below.

```javascript
function test(a) {
    a = 10 * b if (a % 10 == 0);
    return a;
}
System.println(test(101));  // 101
System.println(test(100));  // 1000
```

#### Declaration Statement

Declaration statement is a declaration of variables.
It can declare multiple variables separated by `,` and initialize it like assignment.
See the sample below.

```javascript
var a, b, c;            // not initialized yet, all variables are undefined.
var a, b = 10, c = 100; // b and c is initialized, but a is undefined.
```

#### Block Statement

Block statement is a scope between `{` and `}`
The declared variable in the other scope has a different storage.
See example below.

```javascript
var a = 10;
{
    var a = 100;
    System.println(a);
}
System.println(a);
```

Here is the result.

```
100
10
```

### Flow Controls

#### `if-else` Statement

`if-else` statement is a conditional jump.
`else` clause is not always necessary.

```javascript
if (a == 0) {
    // then clause
}
```

Here is an example with `else` clause.

```javascript
if (a == 0) {
    // then clause
} else {
    // else clause
}
```

You can combine multiple `if-else` statements as following a flow.

```javascript
if (a == 0) {
    // then clause
} else if (b == 0) {
    // next if-else statement
} else {
    // else clause
}
```

#### `while` Statement

`while` statement is a loop by pre-testing a condition.

```javascript
while (a > 0) {
    // loop block
}
```

You can use `continue` inside the loop to go to the head of loop,
and also can use `break` to exit the loop.

```javascript
while (a > 0) {
    /* ... */
    if (x) break;
    /* ... */
    if (y) continue;
    /* ... */
}
```

#### `do-while` Statement

`do-while` statement is a loop by post-testing a condition.
This means a loop is done at least 1 time.

```javascript
do {
    // loop block
} while (a > 0);
```

You can use `continue` inside the loop to go to the location of a condition expression,
and also can use `break` to exit the loop.

```javascript
do {
    /* ... */
    if (x) break;
    /* ... */
    if (y) continue;
    /* ... */
} while (a > 0);
```

#### `for` Statement

`for` statement has 3 parts of conditions as:

*   An initializing part ... do it only 1 time before starting a loop.
*   A condition part ... do it every loop and check if making the loop ended.
*   An incremental part ... update a condition at the end of every loop.

Here is the example below.

```javascript
for (var i = 0; i < 10; ++i) {
    // loop block
}
```

If you set `var` for the loop counter as example above,
it is available in a scope of `for` statement only.
If not, the variable is what is defined at outside scope.

You can also make the all parts empty.
This is same as `while (1) {}` of infinite loop.

```javascript
for ( ; ; ) {
    /* infinite loop */
}
```

#### `switch-case` Statement

`switch-case` statement is also available.
For a condition of `case` statement, you can put an expression.
If the condition's value in case as a result is same, direct value's is checked first.
Otherwise, the condition written first is checked first.

For example, see below.
It is not necessary to put `default` case at the bottom.

```javascript
var array = [1,2,3,4,5,6,7,8,9,10];
function switchTest(n) {
    switch (n) {
    case 1:     System.println(n); break;
    case 2:     System.println(n); break;
    case 3:     System.println(n); break;
    case 4:     System.println(n); break;
    case 5:     System.println(n); break;
    case 6:     System.println(n); break;
    case 7:     System.println(n); break;
    case 8:     System.println(n); break;
    case 100:   System.println(n); break;

    default:
        System.println("default");
        break;
    case array.length():
        System.println("array-length:%{n}");
        break;
    case "aaa":
        System.println(n);
        break;
    case "bbb":
        System.println(n);
        break;
    }
}
0.upto(100, function(i) {
    System.print("%{i} => ");
    switchTest(i);
});
```

#### `break` Statement

`break` statement is used to exit a loop or a block.
For loop, a label is not always necessary.
In that case, `break` statement will exit from the most inside loop.

```javascript
var i;
for (i = 0; i < 10; ++i) {
    if (i == 5) break;
}
System.println("i = %{i}"); // i = 5
```

A label is necessary to exit a block.

```javascript
var a = 10;
LABEL: {
    a = 20;
    while (1) {
        break LABEL if (++a == 50);
    }
}
System.println("a = %{a}"); // a = 50
```

Look at the above example.
You can also use `break` statement  with if modifier as below.

```javascript
break if (a == 0);          // without label
break LABEL if (a == 0);    // with label
```

#### `continue` Statement

`continue` statement is used to go back to the top of a loop.
A label is available like `break`, but a label is not always necessary.
In that case, `continue` statement will go back to the top of the most inside loop.

```javascript
for (var i = 0; i < 10; ++i) {
    if (i == 5) continue;   // skip displaying `i = 5`
    System.println("i = %{i}");
}
```

Same as `break`, you can also use `continue` statement  with if modifier.

```javascript
continue if (a == 0);           // without label
continue LABEL if (a == 0);     // with label
```

#### `return` Statement

`return` statement is used to return from a function.
`return` statement can return with a return value.

```javascript
return;         // return without value, this means `return null`
return value;   // return with value
```

#### `throw` Statement

`throw` statement throws an exception to inform some error.
`throw` usually have an exception value,
but `throw` without anything is available only in `catch` clause.
This means the same exception as the exception caught by `catch` is thrown.

```javascript
throw RuntimeException("message");  // with exception message
throw;                              // throw the same exception as the exception caught by `catch`
```

#### Label Statement

Label statement is just defined the location on the source code.
It will be used by `break` or `continue`.

```javascript
SOME_LABEL:
    /* ... */
```

You can go outside nested loop with using a label as below.

```javascript
var a = 0, b = 0;
LABEL:
while (1) {
    a = 0;
    while (a < 10) {
        ++a;
        if (a == 5 && b == 5) {
            break LABEL;
        }
    }
    ++b;
}
System.println("a = %{a}");
System.println("b = %{b}");
```

The label for `continue` is sometimes pointed to a little different location.
For example, when it is used at the head of a `do-while` loop,
the label is actually pointed to the previous location of the condition expression.
When it is `for` loop, it is pointed to the previous location of its incremental part.
It is because it is more natural for the loop.

On the other hand, the label for `break` will always go to the end of block.
Here is the example below.

```javascript
LABEL:
for (var i = 0; i < 10; ++i) {
    System.println(i);
    if (i % 2 == 0) continue LABEL;
    System.println("-- %{i}");
}
```

Here is the result.

```
0
1
-- 1
2
3
-- 3
4
5
-- 5
6
7
-- 7
8
9
-- 9
```

#### `try-catch-finally` Statement

`try-catch-finally` statement is used with the exception mechanism.
Either `catch` or `finally` can be omitted.
If you omit `catch`, the thrown exception will not be caught but `finally` block is done when exitting `try` block.
On the other hand, if you omit `finally`, nothing but catching an exception.

See an example below.

```javascript
function func() {
    throw RuntimeException("This is a message.");
}

var a = 0;
try {
    func(); // throw exception
} catch (e) {
    System.println(e.what());
    a = 10;
}
System.println("a = %{a}");
```

Here is the result.

```
This is a message.
a = 10
```

```javascript
function func() {
    throw RuntimeException("This is a message.");
}

var a = 0;
try {
    try {
        try {
            func(); // throw exception
        } finally {
            ++a;
            System.println("1");
        }
    } finally {
        ++a;
        System.println("2");
    }
} catch (e) {
    ++a;
}
System.println("a = %{a}");
```

Here is the result.

```
1
2
a = 3
```