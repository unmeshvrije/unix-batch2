/* calc_client.c - Client program that calls remote procedures */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    CLIENT *cl;
    operands ops;
    int *result;
    char *server;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    server = argv[1];

    cl = clnt_create(server, CALC_PROG, CALC_VERS, "udp");
    if (cl == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }

    ops.a = 15;
    ops.b = 7;

    printf("Calling remote ADD(%d, %d)...\n", ops.a, ops.b);
    result = add_1(&ops, cl);
    if (result == NULL) {
        clnt_perror(cl, "add");
        exit(1);
    }
    printf("Result: %d\n\n", *result);

    printf("Calling remote SUB(%d, %d)...\n", ops.a, ops.b);
    result = sub_1(&ops, cl);
    if (result == NULL) {
        clnt_perror(cl, "sub");
        exit(1);
    }
    printf("Result: %d\n\n", *result);

    ops.a = 6;
    ops.b = 9;

    printf("Calling remote MUL(%d, %d)...\n", ops.a, ops.b);
    result = mul_1(&ops, cl);
    if (result == NULL) {
        clnt_perror(cl, "mul");
        exit(1);
    }
    printf("Result: %d\n\n", *result);

    clnt_destroy(cl);
    return 0;
}
