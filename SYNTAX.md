# Syntax for nil

## Types
```
i8      - Signed 8 bit integer
i16     - Signed 16 bit integer
i32     - Signed 32 bit integer
i64     - Signed 64 bit integer
u8      - Unsigned 8 bit integer
u16     - Unsigned 16 bit integer
u32     - Unsigned 32 bit integer
u64     - Unsigned 64 bit integer
f32     - 32 bit floating point
f64     - 64 bit floating point
bool    - Boolean
string  - String
```
<br>

## Variables
Structure of a variable:
```
[var/let/const] [name]: [type] = [data];
```
Difference:
```
var    - Mutable
let    - Immutable
const  - Constant
```
Example:
```
var i: u64 = 0;
let j: i16 = 123;
const x: bool = false;
```
<br>

## Functions
Structure of a function:
```
func [name][generics]([args]) [return] {}
```
Example:
```
func test<T>(i: T) T {
    return i;
}

func main() i8 {
    return 0;
}
```
