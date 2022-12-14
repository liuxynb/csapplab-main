/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * 刘兴元
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */
///////rfrrff
#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  /* XOR即不是同为0或者同为1时按位或 */
  // int a = x & y;
  // int b = ~x & ~y;
  return ((~(x & y)) & (~(~x & ~y))); // 9 ops
}
/*
 * tmin - return minimum two's complement integer
 * tmin - 返回最小二進制補碼整數
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
//即0x80 000 000
{
  return (0x1d << 31); // one op
}
/*
 * isTmax - returns 1 if x is the maximum two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
// maximum = 0111...., and for the minimun， x = -x.
//! :代表逻辑取反，即：把非0的数值变为0，0变为1;
//~ :表示按位取反，即在数值的二进制表示方式上,将0变为1，将1变为0；
{
  x = ~x;
  int y = ~x + 1;
  return ((!(y ^ x)) & (!!x)); // 8 ops in all
  // 1111
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *  如果 word 中的所有奇數位都設置為 1，則返回 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
//与0x55555555或运算，必得-1，-1+1 = 0.
{
  return (!((x | 0x55555555) + 1)); // 3 ops
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return (~x + 1); // 2 ops.
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
//先判断高四比特位是否为三，再判断x是否小于a。
{
  return (!((x >> 4) ^ 0x3)) & (!!((x + (~0x3a) + 1) >> 31)); // 9 ops
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
//根据x是否为0，分别屏蔽y，z。然后再按位或。
{
  return ((((!!x) << 31) >> 31) & y) | (((!!x) - 1) & z); // 8 ops.
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
//
int isLessOrEqual(int x, int y)
//需注意大数溢出。
//先判断是否同号，如同号减法判断；如不同号直接利用符号判断。
{
  int a = ((((x >> 31) & 0x1) + ((y >> 31) & 0x1)) & 0x1);
  int isNagetive = (y + (~x) + 1) >> 31;
  return (((!a) & !isNagetive) | (a & (!!(x >> 31))));
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
//对于非0和非minimum的数有x|((~x)+1)== 0.
{
  return (((x | (~x + 1)) >> 31) + 1); // 5 ops.
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
//负数取反后可与正数类似
//关注0001
{
  x = conditional(x & 0x80000000, ~x, x); // 8 ops
  int right16 = (!!(x >> 16)) << 4;
  x = x >> right16;
  int right8 = (!!(x >> 8)) << 3;
  x = x >> right8;
  int right4 = (!!(x >> 4)) << 2;
  x = x >> right4;
  int right2 = (!!(x >> 2)) << 1;
  x = x >> right2;
  int right1 = (!!(x >> 1));
  x = x >> right1;
  int right0 = (!!x);
  return right16 + right8 + right4 + right2 + right1 + right0 + 1; // 26 + 8 = 34 ops.
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
//注意两倍f
{
  unsigned s = uf & (1 << 31);
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned frac = uf & 0x7fffff;
  if (exp == 0xff)
    return uf;
  if (exp == 0)
    return (frac << 1 | s);
  ++exp;
  if (exp == 255)
    return 0x7f800000 | s;       //返回无穷大。
  return s | (exp << 23) | frac; //一般情况。10 ops.
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
// equivalent 相等的
// argument 参数
int floatFloat2Int(unsigned uf)
// Just notice that E = e - bias, and in the float, the bias equals to 127.(in double 1023)
{
  unsigned s = uf & (1 << 31);
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned frac = uf & 0x7fffff; //提取编码符号s，编码阶码M和编码尾数E。
  int shiftNum = exp - 127 - 23; //移动位数，注意公式((-1)^s)*M*2^E.
  if (shiftNum < -23)
    return 0;
  else if (shiftNum >= 31)
    return 0x80000000u;
  else
  {
    if (!s)
    {
      if (shiftNum & (0x80000000))
        return ((frac + (1 << 23)) >> ((~shiftNum) + 1));
      else
        return ((frac + (1 << 23)) << (shiftNum));
    }
    else
    {
      if (shiftNum & (0x80000000))
        return (~((frac + (1 << 23)) >> ((~shiftNum) + 1))) + 1;
      else
        return (~((frac + (1 << 23)) << (shiftNum))) + 1; // 30 ops in total.
    }
  }
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
// 公式((-1)^s)*M*2^E. or((-1)^s)*(1.frac)*2^(exp-127)[规格化]
{
  int exp = x + 127;
  if (exp <= 0)
    return 0;
  if (exp >= 255)
    return 0x7f800000;
  return exp << 23;
}
