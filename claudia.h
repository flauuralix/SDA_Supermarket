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

typedef struct tElmtListdata *addressdt;
typedef struct tElmtListdata {
	 infotype nm;
	 addressdt  br;
} ElmtListdata;
void pelanggan (address *First);
void tampilanmenu();
void pilihMenu(int *pilihan);
void tempat();
