RPC Calculator Demo
===================

Demonstrates Sun RPC using rpcgen to auto-generate client stubs,
server skeleton, and XDR serialization code from a .x definition file.

Files you write:
  calc.x          - RPC interface definition (IDL)
  calc_server.c   - Server procedure implementations
  calc_client.c   - Client program

Files rpcgen creates:
  calc.h          - Common header (struct definitions, program/version constants)
  calc_clnt.c     - Client stub (marshals args, sends RPC, unmarshals result)
  calc_svc.c      - Server skeleton (registers service, dispatches calls)
  calc_xdr.c      - XDR serialization/deserialization for the operands struct

How it works:
  1. rpcgen reads calc.x and generates the glue code
  2. The server links calc_server.c (your logic) + calc_svc.c (dispatcher) + calc_xdr.c
  3. The client links calc_client.c (your calls) + calc_clnt.c (stub) + calc_xdr.c
  4. At runtime, the server registers with rpcbind (portmapper)
  5. The client contacts rpcbind to find the server, then makes RPC calls over UDP

Build and run (Linux):
  make gen               # generate stubs from calc.x
  make                   # compile client and server
  sudo ./calc_server &   # start server (needs root for rpcbind)
  ./calc_client localhost # run client

Note: macOS ships with rpcgen but rpcbind may not be running.
      This demo is best run on Linux. On Ubuntu/Debian:
        sudo apt install rpcbind
        sudo systemctl start rpcbind
