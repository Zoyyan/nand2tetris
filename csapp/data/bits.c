/* 
 * CS:APP Data Lab 
 * bits.c - Source file with your solutions to the Lab.
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

#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  /* expliot & and ~ to compute ^ */
  int a = x & ~y;
  int b = ~x & y;
  int ret = ~(~a & ~b);
  return ret;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  /* exploit shift to get Tmin */
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  //! pass when use unsigned (but unsigned not allowed)
  //! fail when use int
  /* exploit overflow*/
  // should make sure x != -1

  //                 nx        nx*2
  // Tmax [01..1]   [10..0]   [0...0]
  //   -1 [1...1]   [0...0]   [0...0]
  int nx = x + 1;
  int nx2 = nx + nx;
  int ret = (!nx2) & (!!nx);
  return ret;
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  int odd = 0xAA;
  int oddBits = odd;
  odd <<= 8;
  oddBits |= odd;
  odd <<= 8;
  oddBits |= odd;
  odd <<= 8;
  oddBits |= odd; // 0xAAAAAAAA;
  return !(~(x | ~oddBits));
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
  return ~x + 1;
}
//3
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
{
  int last4Bits = x & 0xF;
  int otherBits = x & ~0xF;
  int ret = 1;
  // last 4 bits:   <= 0x9
  int sub = 0x9 + ~last4Bits + 1; // 0x9 - last4 >= 0
  int sign = (sub >> 31) & 1;     // should = 0
  ret &= !sign;
  // other bits:    0x30
  ret &= !(~(~0x30 ^ otherBits));
  return ret;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  //    x            nx        a          b        fb
  //  [0...0]      [0..01]  [10..0]    [1..1]    [0..0]
  //  [0..101]     [0...0]  [0...0]    [0..0]    [1..1]
  int nx = !x;
  int a = nx << 31;
  int b = a >> 31; // arthm
  int fb = ~b;
  return (b & z) | (fb & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  int ret = 0;
  int msb_mask = 1 << 31;
  int sub = y + (~x + 1); //y - x
  // sign: 0 -> [0..0]; 1 -> [1..1]
  int x_sign = (x & msb_mask) >> 31; // arthm shift
  int y_sign = (y & msb_mask) >> 31;
  int sub_sign = (msb_mask & sub) >> 31;

  // same sign: 0 -> [0..0]; 1 -> [1..1]
  int is_same_sign = x_sign ^ (~y_sign);

  // 1: diff sign: sub may overflow
  //  (y - x >= 0)  -> (y_sign == [0..0]) -> 1
  ret |= (~is_same_sign) & (!y_sign);

  // 2: same sign
  // (sub >= 0) -> (sub_sign == [0..0]) -> 1
  ret |= is_same_sign & (!sub_sign);
  return ret;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) // is Zero ?
{
  // answer:
  // return ((x | (~x + 1)) >> 31) + 1;
  // exploit -0 == 0          (! -[10..0] == [10..0], because overflow
  // after |, sign bit is 0   (but [10..0] sign bit is 1
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
int howManyBits(int x) //!s1: too many steps
{
  // from msb to lsb, start cnt when bit changes
  // i.e. -5 = 1011; 1 = 01
  // special case: 0, -1 (not change)
  int cnt;
  int flag = 0;                  // whether cnt current bit
  int xor = x ^ (x >> 1);        // each pair of bit, whether diff value (30 pairs: 30 -> 0)
  int is_diff = (xor >> 30) & 1; // diff value -> current bit of xor == 1;
  flag = is_diff;                // start cnt when diff value
  cnt = flag;
  is_diff = (xor >> 29) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 28) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 27) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 26) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 25) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 24) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 23) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 22) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 21) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 20) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 19) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 18) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 17) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 16) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 15) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 14) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 13) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 12) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 11) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 10) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 9) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 8) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 7) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 6) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 5) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 4) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 3) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 2) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 1) & 1;
  flag |= is_diff;
  cnt += flag;
  is_diff = (xor >> 0) & 1;
  flag |= is_diff;
  cnt += flag;
  cnt += 1;
  return cnt;
}

//! s2: binary divide
/*
int howManyBits(int x)
{
  int s, c1, c2, c3, c4, c5, c6;
  int cnt = 0;
  s = (x >> 31) & 1; //	sign

  // 2 case:                                                  | 1 at 31      | 1 at 8       |
  x = ((s << 31) >> 31) ^ x; // get abs(x)
  s = !!(x >> 16);           // whether ? has 1               | 31..16 -> 1  |  31..16 -> 0 |
  c1 = s << 4;               // bits used to represent ?      | 15..0  -> 16 |  15..0  -> 0 |

  x >>= c1;       // shift ?                                  | 15..0        |            0 |
  s = !!(x >> 8); // wherher ? has 1                          | 31..24 -> 1  |  31..8  -> 1 |
  c2 = s << 3;    // bits used to represent ?                 | 24..16 -> 8  |   7..0  -> 8 |

  x >>= c2;
  s = !!(x >> 4);
  c3 = s << 2;

  x >>= c3;
  s = !!(x >> 2);
  c4 = s << 1;

  x >>= c4;
  s = !!(x >> 1);
  c5 = s;

  x >>= c5;
  c6 = !!x;                              // 判断最低位是否为1
  cnt = c1 + c2 + c3 + c4 + c5 + c6 + 1; // 将每次获得的低位有效位相加，再加1位符号位
  return cnt;
}
*/

//float: 1-8-23
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
{
  unsigned exp_mask = 0xff << 23;          // 8 bits of 1, 23 bits of 0
  unsigned frac_mask = (0xfffff << 3) + 7; // 23 bits of 1
  unsigned frac = frac_mask & uf;
  unsigned exp = (exp_mask & uf) >> 23; // move to right

  if (exp == 0xff) // special val
  {
  }
  else if (exp != 0) // normal
  {
    // exp ++
    uf += 1 << 23;
  }
  else // denormal
  {
    // whether overflow or not
    // frac *= 2
    // cause: when overflow and become normal, bits are continue inc
    uf += frac;
  }
  return uf;
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
int floatFloat2Int(unsigned uf)
{
  unsigned frac_mask = (0xfffff << 3) + 7; // 23 bits of 14
  unsigned frac = frac_mask & uf;
  unsigned m = (1 << 23) + frac;        // 1.frac without point
  unsigned m_point = 23;                // how many bits after pint of 1.frac
  unsigned exp_mask = 0xff << 23;       // 8 bits of 1, 23 bits of 0
  unsigned exp = (exp_mask & uf) >> 23; // move to right
  unsigned sign = (uf >> 31) & 1;       // sign
  unsigned bias = 127;
  // unsign: [Tmin, Tmax]
  // float:  [Tmin, -1] {0} [1, Tmax]
  int ret = 0;
  if (exp == 0xff) // special value
  {
    ret = 0x80000000u;
  }
  else if ((sign == 0 && exp >= bias + 31) || // not in [Tmin, Tmax]
           (sign == 1 && exp > bias + 31))
  {
    ret = 0x80000000u;
  }
  else if (exp < 127) // smaller than 1
  {
    ret = 0;
  }
  else
  {
    ret = m;
    // exp
    for (; exp > 127; exp--)
    {
      if (m_point > 0)
      {
        m_point--;
      }
      else
      {
        ret <<= 1;
      }
    }
    ret >>= m_point; // round
    // sign
    ret *= sign ? -1 : 1;
  }
  return ret;
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
// 测试文件有问题，会超时，
// 需要把btest.c的第35行改成#define TIMEOUT_LIMIT 100
unsigned floatPower2(int x)
{
  unsigned bias = 127;
  // unsigned uf_1 = bias << 23;
  // unsigned exp = bias;
  // e [-127, 128]
  unsigned inf = 0x7f800000;
  unsigned ret = 0;
  if (x >= 128) // too large (include nan and inf)
  {
    ret = inf;
  }
  else if (x < -126 - 23) // too small: smaller than float [0..0][0..01]
  {
    ret = 0;
  }
  else if (x >= -126) // normal:  [bias + x][0..0]
  {
    ret = (x + bias) << 23;
  }
  else // denarmal: [0..0][0..010..0]
  {
    // exp == 0, e = 1 - bias = -126
    ret = 1 << 22;      // largest [0..0][10..0] == 2 ^ -127
    ret >>= (-127 - x); // set frac
  }
  return ret;
}

// int main()
// {
//   // printf("%d ",
//   isTmax(0x7fffffff);
// }