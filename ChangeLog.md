# Change Log

## V1.1.0 (Future Planned)

*   Planned, or remaining tasks.
    *   Support OpenCV library.
    *   Support HTTP Server library with libhttp.
    *   The followings are planned but priority is low.
        *   Improvement with `KX_FASTENTER`.
            *   `KX_FASTENTER` is entering function without frame.
        *   Improvement with some specialized instructions.
            *   `KXOPT_LENGTH` ... for `Array`, `Binary`, `String`
            *   `KXOPT_PARSEINT` ... `Integer.parseInt`

## V1.0.0 (Planned)

*   Planned
    *   Support to read/write from/to Clipboard.
    *   Support Array of Double in native.
    *   Support Big Integer in native.
    *   User selectable installation.
    *   Documentation & SpecTest complete.
    *   Full documenting by SpecTest.

## V0.14.0 (14th Preview Release)

*   Updated
    *   Supported SSH & libssh2 library.
    *   Supported an iconv library.
    *   Supported `"\uXXXX"` and `"\u{CodePoint}"` as Unicode Code Point in a string literal.
    *   Supported a TCP/UDP socket library.
    *   Support PDF library with libHaru.
    *   Some bug fixes and improvement.

## V0.13.1 (13th Preview Release)

*   Updated
    *   Improved `String#split` to support UTF-8.
    *   Supported `Parsek#noneOf`.
    *   Added a script name into an argument list with `--exec` option.
    *   Supported a `$env` variable without a property to get all environment variables.
    *   Improved `String#each` to iterate a character according to UTF-8.
    *   Supported `String.escapeHtml`.
    *   Supported utf8 in `Parsek#oneOf`.
    *   Added a CLI support of kinx content.
    *   Some bug fixes and improvement.

## V0.12.0 (12th Preview Release)

*   Updated
    *   Supported a numbered parameter of a function argument.
        *   It is available from `_1` to `_9`, and `_1` is the first argument.
        *   `_` is also available and it is assigned the variable according to the order of appearance.
            *   `(&() => _ + _)` is same as `(&() => _1 + _2)`
    *   Supported a callback block syntax when a callback function is the last argument parameter.
        *   For example, `f(2, 10) { &(a, b) return a + b; }` means `f(2, 10, &(a, b) => { return a + b; })`.
        *   For another example, you can pass a block to `.map` like `[4, 5, 6].map { => _1 * 2 }`.
        *   See [this example](example/../examples/blockfunc.kx) to check the supported syntax.
    *   Supported the syntax to skip a parameter to ignore assignment like `[a,,c] = [1,2,3]`.
    *   Supported the syntax of array assignement with a function argument.
        *   A function argument example is `function func([a, b]) { /* ... */ }`.
    *   Supported the syntax to get the value of an object property like `var {xxx} = { xxx: 100 }`.
        *   In this case it assigns `100` to the variable of `xxx` which is same name as a property name.
        *   This syntax can be used only as a declaration or a function argument.
        *   A function argument example is `function func({ xxx, yyy }) { /* ... */ }`.
    *   Improved `.each` for Object. The callback will receive `[key, value]` pair as array.
        ```
        { x: 100, y: 200, z: 300 }.each { &([key, value])
            System.println([key, value]);
        };
        ```
    *   Some bug fixes and improvement.

## V0.11.0 (11th Preview Release)

*   Updated
    *   Supported a Parser Combinator Library named as `Parsek`.
    *   Some bug fixes and improvement.

## V0.10.0 (10th Preview Release)

*   Updated
    *   Changed disassembler for x64.
    *   In formatting like `"%-20s" % v` it is correctly worked with UTF8 string with correct width.
    *   Supported some of `Math` functions in native.
    *   Supported some of string operations in native.
    *   Supported some of binary operations in native.
    *   Supported some of array operations in native.
    *   Supported switch-case only with integer label in native.
    *   Kinx As A Library, see `examples/c/runkinx.c` for example.
    *   Supported underline by escape sequence.
    *   Supported `__FILE__`, `__LINE__`, `__FUNC__`.
    *   Supported Environment Variable via `$env` variable.
    *   Supported a JIT library for 64-bit integer and 64-bit floating point.
    *   Supported `libkinx.h` and a library file of `kx.lib` on Windows or `libkx.a` on Linux.
    *   Supported the option of `--version` to show the detail of the version.
    *   Supported the option of `-c` for compiling only to check the syntax.
    *   Supported the option of `-q` for quiet mode.
    *   Some bug fixes and improvement.

## V0.9.2 (9th Preview Release)

*   Updated
    *   Supported a long option by `System.getopt()`.
    *   Supported UTF8 utilities.
        *   `String.utf8Length()` to get a length of a utf8 string.
        *   `String.splitUtf8String()` to split a string as an array of a utf8 string.
        *   `String.splitUtf8Object()` to split a string as an array of a utf8 information object.
        *   `String.eastAsianWidth()` to get a width of a utf8 character.
        *   `String.eastAsianWidthType()` to get a type character of width of a utf8 character.
    *   Supported REPL (Read-Eval-Print Loop) with updated below.
        *   Auto-complete by `[TAB]` key.
        *   Moving by word with Ctrl + arrow left/right.
    *   Some bug fixes and improvement.

## V0.8.1 (8th Preview Release)

*   Updated
    *   Updated some of native code output.
    *   Supported a dot style of string literal like `.abc` means `"abc"`.
    *   Supported Process library.
    *   Supported `System.getopt()`.
    *   Supported Escape Sequence with `\e`, `\033`, or `\x1b` even with Windows.
    *   Supported a part of REPL (Read-Eval-Print Loop), but it is not a full version.
    *   Some bug fixes and improvement.

## V0.7.1 (7th Preview Release)

*   Updated
    *   Bug fixes for operator override.
        *   `<<`, `>>` ... Making it parse correctly.
    *   Added `toString()` method to the class Boolean.
    *   Some runtime optimaizations for function call.
    *   Replaced Bison of a parser generator by Kmyacc.
    *   Supported a DateTime class.
    *   Supported a CSV/TSV class.
    *   Supported some optimizations.
    *   Supported `System.gc()` to perform GC forcely.
    *   Supported a Database class for easier to use than a SQLite class.
    *   Some bug fixes and improvement.

## V0.6.0 (6th Preview Release)

Updates from v0.5.2.

*   Updated
    *   Fixed a bug of `String#next`.
    *   Supported Net.Http class.
    *   Supported the operator '~' for bitwise not.
    *   Supported operator override for class instance as below.
        *   `==`, `!=`, `>`, `>=`, `<`, `<=`, `<=>`, `<<`, `>>`, `+`, `-`, `*`, `/`, `%`, `[]`, `()`.
    *   Supported multi-threading as `Isolate` with `Mutex` and `Condition`.
    *   Supported `Enumerable#sum` & `Range#sum`.
    *   Fixed to parse a big integer from hex.
    *   Function Object is always evaluated as `false`. Only `.isFunction` property returns `true`.
    *   Append alias methods for Array/Enumerable below.
        *   `Array#collect` for `Array#map`.
        *   `Array#collectConcat` for `Array#flatMap`.
        *   `Array#inject` for `Array#reduce`.
        *   `Array#select`, `Array#findAll` for `Array#filter`.
    *   Some bug fixes and improvement.

## V0.5.2 (5th Preview Release)

Updates from v0.4.1.

*   Updated
    *   Updated OpenSSL library path.
    *   Changed a function name to be treated as a constant.
    *   Supported some binary special methods.
    *   Applying a `toString` method automatically when applying an object to
        `System.print/println`, `Array#join`, and `Array#toString`.
    *   Supported a spread operator for String like `<..."abc">` or `[..."abc"]`.
    *   Supported the option of `binary` with true/false for `Zip#extract`.
    *   Supported applying a Range object to the index for String, Binary, and Array.
    *   Some bug fixes and improvement.

## V0.4.1 (4th Preview Release)

Updates from v0.3.1.

*   Updated
    *   Supported Enumerable module.
    *   Supported Range object and the syntax of `n..m` and `n...m`.
    *   Supported `for-in` statement.
    *   Updated a spread operator to use with any expressions.
    *   Supported some operators like `==` as a property name.
    *   Supported a spread operator with declaration statement.
    *   Some bug fixes.

## V0.3.1 (3rd Preview Release)

Updates from v0.2.0.

*   Updated
    *   Combining ternary expressions.
    *   Updated Fiber.
    *   Supported Signal.
    *   Some bug fixes.

## V0.2.0 (2nd Preview Release)

Updates from v0.1.0.

*   Updated
    *   Supported Standard I/O.
        *   `$stdin`, `$stdout`, `$stderr` has same methods as `File`.
        *   There are constant variables as `STDIN`, `STDOUT`, `STDERR` 
            corresponding to `$stdin`, `$stdout`, `$stderr`.
    *   Added or modified `File` instance methods.
        *   Supported `getch`, `putch`, `peek`.

## V0.1.0 (1st Preview Release)

*   Initial Release.
