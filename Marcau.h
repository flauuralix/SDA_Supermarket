#ifndef Marcau_h
#define Marcau_h
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define Nil NULL

typedef char infotype;
typedef struct addressNode *address;
typedef struct addressNode{
  infotype info;
  address next;
}AddressNode;

typedef struct tElmtListdata *address;
typedef struct tElmtListdata {
	 infotype nm;
	 address  br;
} ElmtListdata;
//tampilan nama supermarket marcau
void header ();

//tampilan kasir 
void tampilan_kasir ();

//tampilan menu utama
void menu ();

// prosedur pelanggan
void pelanggan (address *First, address *Last);

//prosedur transaksi
void transaksi (address *First, address *Last);

//prosedur pilih kasir
void pilih_kasir (address *First, address *Last);

//prosedur dan tampilan history transaksi
void history (address *First, address *Last);

//prosedur exit 
void exit (address *First, address *Last);



