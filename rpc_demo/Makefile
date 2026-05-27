# Makefile for RPC calculator demo
#
# Steps:
#   1. make gen      - run rpcgen to generate stubs
#   2. make          - compile client and server
#   3. sudo ./calc_server &   (server needs root for rpcbind registration)
#   4. ./calc_client localhost

CC = gcc
CFLAGS = -Wall -Wno-incompatible-function-pointer-types

# rpcgen generates these files from calc.x
GEN_SRCS = calc_clnt.c calc_svc.c calc_xdr.c
GEN_HDR  = calc.h

all: calc_client calc_server

gen: calc.x
	rpcgen -C calc.x

calc_client: calc_client.c calc_clnt.c calc_xdr.c $(GEN_HDR)
	$(CC) $(CFLAGS) -o $@ calc_client.c calc_clnt.c calc_xdr.c

calc_server: calc_server.c calc_svc.c calc_xdr.c $(GEN_HDR)
	$(CC) $(CFLAGS) -DRPC_SVC_FG -o $@ calc_server.c calc_svc.c calc_xdr.c

clean:
	rm -f calc_client calc_server $(GEN_SRCS) $(GEN_HDR)

.PHONY: all gen clean
