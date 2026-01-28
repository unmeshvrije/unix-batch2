#include<stdio.h>

int main(void) {

  /*
   * byte
   * 1  2  3  4
   * 0A 0B 0C 0D
   *
   * 
   *    0    A
   * 0000 1010
   *
   * nibble = 4 bits = 2 ^ 4 = 16 = 0,1,2,a,b,..f
   *
   *
   *
   * MSB : Most Significant Byte
   *
   * LSB : Least Significant Byte
   *
   * What is MSB and LSB of 0x0A0B0C0D ?
   * 
   * MSB = 0A
   * LSB = 0D
   *
   *
   * 435
   * 4  *100 + 3 * 10 + 5  * 1
   *
   * MSB = 4 
   * LSB = 5
   *
   *    network / host (ntohl, htonl)
   *
   *    Big Endian (Network byte order)
   *
   *    A         B          C           D
   * 1000      1001       1002        1003
   *
   *
   *    Little Endian (Intel)
   *
   *    D         C          B           A
   * 1000      1001       1002        1003
   *
   * */
  int num = 0x0A0B0C0D;
  /* Address of num and cast it to (char*) pointer */

  /* Read 4 bytes of number and interpret only one byte as character*/
  char* byte = (char*) &num ;

  /* printf("%X\n", *byte); */

  if (0xD == *byte) {
    printf("Little Endian\n");
  } else {
    printf("Big Endian\n");
  }

  return 0;
}
