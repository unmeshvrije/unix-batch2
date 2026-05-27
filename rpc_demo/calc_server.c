/* calc_server.c - Server-side procedure implementations */

#include <stdio.h>
#include "calc.h"

int *add_1_svc(operands *argp, struct svc_req *rqstp)
{
    static int result;
    result = argp->a + argp->b;
    printf("Server: %d + %d = %d\n", argp->a, argp->b, result);
    return &result;
}

int *sub_1_svc(operands *argp, struct svc_req *rqstp)
{
    static int result;
    result = argp->a - argp->b;
    printf("Server: %d - %d = %d\n", argp->a, argp->b, result);
    return &result;
}

int *mul_1_svc(operands *argp, struct svc_req *rqstp)
{
    static int result;
    result = argp->a * argp->b;
    printf("Server: %d * %d = %d\n", argp->a, argp->b, result);
    return &result;
}
