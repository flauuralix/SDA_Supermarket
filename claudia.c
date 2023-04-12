#include "claudia.h"
#include<stdio.h>

void tampilanmenu(){
	printf("Menu\n");
	printf("1. Pelanggan\n");
	printf("2. Transaksi\n");
	printf("3. Kasir\n");
	printf("4. Exit\n");
	
}
void pilihMenu(int *pilihan)
{
  do{
    printf("Masukkan pilihan anda : ");
    scanf("%d", &(*pilihan));
  }while((*pilihan)<0 || (*pilihan) > 4);
}
void pelanggan (address *First){
	ElmtListdata nama[2];
	printf("Masukkan nama : ");
	scanf("%s",&nama[1].nm);
	
}
void tempat(){
	printf("\nSilahkan memilih tempat barang\n");
	printf("1. Kerajang\n");
	printf("2. Troli\n");
    printf ("masukan pilihan anda: ");
        int pilihan;
        scanf ("%d",&pilihan);
        while (pilihan!=1&&pilihan!=2) {
            printf ("pilihan anda tidak ada di menu ketik ulang ");
            scanf ("%d",&pilihan);
        }
       
}

