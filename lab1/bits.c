/* 
 * CSE 351 Lab 1 (Data Lab )
 * 
 * <Please put your name and userid here>
 * 
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

You will provide your solution to this homework by
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
  3. Has *undefined* behavior when shifting by a negative amount or an amount
  greater than or equal to the number of bits in the value being shifted.
  e.g. For x >> n, shifts by n < 0 or n >= *size of x* are undefined 
  e.g. if x is a 32-bit int, shifts by >= 32 bits are undefined 
  Undefined means you do not know what result you will get from the operation.

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

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
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
 */


#endif
// Rating: 1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  //return x & y;
  int r1 = ~x;
  int r2 = ~y;
  int r3 = r1 | r2;
  int r4 = ~r3;
  return r4;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //return 2;
  int r, r1, r2;
  r1 = (~x)&y;
  r2 = x&(~y);
	r1 = ~r1;
	r2 = ~r2;
	r = ~(r1 & r2);
	return r;
}
/* 
 * thirdBits - return 32-bit quantity with every third bit 
 * (starting from the least significant bit) set to 1 (other bits set to zero).
 *   Example: ....1001001
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  //return 2;
	int r = (0x49<<24) + (0x24<<16) + (0x92<<8) + 0x49;
	return r;
}
// Rating: 2
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  //return 2;
	int n1 = n + (~0);
	int x1 = x >> n1;
	int x11 = !x1;
	// x11 is the case for x is positive
	int x2 = ~x;
	// x2 is the case x is -1
	int y1 = !(~(x>>31));
	int y2 = !(x2>>n1);
	int y3 = y1 & y2;
	// y3 is the case that x is negative. In this case, we check whether ~x is the number within the range of [0, (pow(2,n-1)-1)]
	// actually y3 includes the case x==-1
	return x11 /*| !x2 */| y3;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    //return 2;
	int n1 = !(!x); // 0
	int n2 = x>>31; // <0
	int n3 = !(x>>31); // >0
	return n1 | n2 | (n1&n3);
}
/* 
 * getByte - Extract byte n from int x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  //return 2;
	int n0 = n<<3;
	int n1 = x>>n0;
	int n2 = n1 & 0xff;
	return n2;
}
// Rating: 3
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //return 2;
	int n1 = x>>n;
	int n2 = ~n1;
	int n3 = ((1<<31) >> n) << 1;
	int n4 = ~(n3 | n2);
	return n4;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	int n1 = ((x>>31) ^ (y>>31)) & 1;
	int add = x+y;
	int n2 = ((add>>31) ^ (x>>31)) & 1;
	int n3 = !n2;
	return n1 | n3;
}
/* invert - Return x with the n bits that begin at position p inverted 
 *          (i.e., turn 0 into 1 and vice versa) and the rest left 
 *          unchanged. Consider the indices of x to begin with the low-order
 *          bit numbered as 0.
 *   Can assume that 0 <= n <= 31 and 0 <= p <= 31
 *   Example: invert(0x80000000, 0, 1) = 0x80000001,
 *            invert(0x0000008e, 3, 3) = 0x000000b6,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3  
 */
int invert(int x, int p, int n) { 
	int n1 = (~0) << n;
	int n2 = ~n1;
	int n3 = n2 << p;
	return x ^ n3;
}
// Rating: 4
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	int negative = ~x + 1;
	int sign = x>>31;
	int negative_sign = negative>>31;
	return (sign | negative_sign) + 1;
}

// Extra Credit: Rating: 3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int n0 = ~(!x) + 1; // if x==0, n0==-1; if x!=0, n0==0
	int n1 = !x + (~0); // if x==0, n1=0; if x!=0, n1=-1
	return (z&n0) | (y&n1);

}
// Extra Credit: Rating: 4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	int notneg = !(x>>31);
	int not0 = !(!x);
	int pow2 = !(x & (x+(~0)));
	return notneg & not0 & pow2;
}

