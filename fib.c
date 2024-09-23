#include <stdio.h>
#include <stdlib.h>

unsigned long long int fibonacciIterative(unsigned long long int n) {
   // the sums of the terms preceding are the current
   if (n == 1) {
      printf("0");
      return 0;
   } else if (n == 2) {
      printf("1");
      return 0;
   }
   // F(1) is firstPrevious and F(2) is secondPrevious
   unsigned long long int firstPrevious = 0;
   unsigned long long int secondPrevious = 1;
   unsigned long long int fibonacciSum = 1;

   // start for loop from 3 since if covers the other base cases
   for (unsigned long long int i = 3; i <= n; i++) {
      fibonacciSum = firstPrevious + secondPrevious;
      firstPrevious = secondPrevious;
      secondPrevious = fibonacciSum;
   }
   return fibonacciSum;
}



unsigned long long int fibonacciRecursive(unsigned long long int n) {
   // indexing was off at first since Fibonacci number 1 is 0
   if (n <= 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main(int argc, char *argv[]) {
   // assign command line arguments to appropriate variables
   //unsigned long long int firstFibNumber;
   int firstFibNumber;
   //char *endptr;
   //firstFibNumber = strtoull(argv[1], &endptr, 10);
   firstFibNumber = atoi(argv[1]);
   char method = argv[2][0];

      
   if (method == 'i') {
      // here do the iterative method
      //printf("This is the Iterative method up to: %d\n", fibonacciNum);
      printf("%lld", (fibonacciIterative(firstFibNumber)));
   } else {
      // here do the recursive method
      //printf("This is the Recursive method up to: %d\n", fibonacciNum);
      printf("%lld", (fibonacciRecursive(firstFibNumber)));
   }
   return 0;
}
