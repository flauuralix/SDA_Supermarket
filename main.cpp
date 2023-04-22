/*       
File Name		: main.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "header.h"
#include "antri.h"


/* ======= End of Header File ====== */


datakasir Kasir[5];
DataBarang list[5];

address_P Head_Pembeli = NULL;
address_BB Head_BarangBelian = NULL;
address_B Head_Barang = NULL;
address_P Pembeli = NULL;
address_B Barang; 
address_BB BarangBelian;
address_A Antrian;
	
infotype pil,kode,jml,nokasir,harga,lagi,Nomor,i=0;
infochar nama,riwayat,Nama_Barang,pilih;

void list_barang(){
	int i;
	
	for(i=0;i<5;i++){
		printf("%d. %s\t\t\t\t%d\t\t\t\t\t%d\n",i+1,list[i].nama,list[i].stok,list[i].harga);
	}
}

int main(){
	Kasir[0].Nomor = 1; 
	Kasir[1].Nomor = 2;
	Kasir[2].Nomor = 3;
	Kasir[3].Nomor = 4;
	Kasir[4].Nomor = 5;
	
	list[0].nama = "Daging Ayam	",list[0].stok = 10,list[0].harga = 25000;
	list[1].nama = "Daging Sapi	",list[1].stok = 10,list[1].harga = 40000;
	list[2].nama = "Daging Kambing",list[2].stok = 10,list[2].harga = 30000;
	list[3].nama = "Mie Goreng	",list[3].stok = 100,list[3].harga = 3000;
	list[4].nama = "Mie Rebus	",list[4].stok = 100,list[4].harga = 3000;
	for(;;){
		system ("cls");
	     header();
	     int tekan;
	     printf("TEKAN ENTER UNTUK LANJUT..");
	     scanf("%c",&tekan);
	     system ("cls");
		void Kasir_Antrian();
		printf ("\t___________________________________________________________________________________________________________________________________");
		printf ("\n\t|             |");
		printf ("\n\t|   Kasir 1   |"); Tampil_List_Antrian(Kasir[0].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t|             |");
		printf ("\n\t|   Kasir 2   |");
		Tampil_List_Antrian(Kasir[1].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t|             |");	
		printf ("\n\t|   Kasir 3   |");
		Tampil_List_Antrian(Kasir[2].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t|             |");
		printf ("\n\t|   Kasir 4   |");
		Tampil_List_Antrian(Kasir[3].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");	
		printf ("\n\t|             |");	
		printf ("\n\t|   Kasir 5   |");
		Tampil_List_Antrian(Kasir[4].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n");
		tampilan_kasir();			
		printf("\nPilihan : "); 
		scanf("%d", &pil);
		system("cls");
		switch(pil)
		{
			case 1 :{
					lagi = 1;
			    printf("--SElAMAT DATANG DI SUPERMAERKET MARCAU--");
				printf("\n\tNAMA PELANGGAN: ");
				scanf("%s",&nama);
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
					Pembeli = Pembeli->next;	
				}
			
  	printf   ("\t\t  +======================================+ \n");
	printf   ("\t\t  |   TEMPAT BELANJA YANG TERSEDIA       | \n");
	printf   ("\t\t  |--------------------------------------| \n");
	printf   ("\t\t  |           - KERANJANG                | \n");
	printf   ("\t\t  |           - TROLI                    | \n");
    printf   ("\t\t  |--------------------------------------| \n");
    printf("\t\t Silahkan ketik pilihan anda:");
    scanf("%s",&pilih);


				list_barang();
				while (lagi == 1){
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					Nama_Barang = list[kode-1].nama;
					harga = list[kode-1].harga * jml;
					list[kode-1].stok = list[kode-1].stok-jml;
				if(list[kode-1].stok<0){
					printf("Maaf Barang Habis\n");
					list[kode-1].stok = 0;
				}
					Pembeli->BarangBelian = Head_BarangBelian;				
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
				}
				break;
			}
			case 2 :{
			
				printf("\nPilih No. Kasir (1-5): ");
				scanf("%d",&nokasir);
				Antrian = NULL;
				Create_Node_Antrian(&Antrian);
				Isi_Node_Antrian(&Antrian, Pembeli->Nama_Pembeli);
				Ins_Akhir_Antrian(&Kasir[nokasir-1].next,Antrian);
				printf("\nAnda Sudah Masuk Antrian\n");
				system("pause");	
				break;
			}
			case 3 :
				int item;
			printf("Apakah anda ingin menambahkan atau mengurangi Item? \n1.Ya\n2.Tidak\nInput Pilihan:");
			scanf("%d",&item);
			    switch(item){
				case 1:
			    printf("Anda di kasir berapa(1-5)?: ");
				scanf("%d",&i);
				Dequeue_Antrian(&Kasir[i-1].next,&nama);
				system("pause");
				printf("Nama %s telah dikeluar dari antrian silahkan antri kembali\n",&nama);
			   	lagi = 1;
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
					Pembeli = Pembeli->next;	
				}
				
				list_barang();
				while (lagi == 1){
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					Nama_Barang = list[kode-1].nama;
					harga = list[kode-1].harga * jml;
					
					list[kode-1].stok = list[kode-1].stok-jml;
				if(list[kode-1].stok<0){
					printf("Maaf Barang Habis\n");
					list[kode-1].stok = 0;
				}
					Pembeli->BarangBelian = Head_BarangBelian;				
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
				}
				printf("\nNAMA PELANGGAN: ");
				scanf("%s",&nama);
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
					Pembeli = Pembeli->next;	
				}
				
				printf("\nPilih No. Kasir (1-5): ");
				scanf("%d",&nokasir);
				Antrian = NULL;
				Create_Node_Antrian(&Antrian);
				Isi_Node_Antrian(&Antrian, Pembeli->Nama_Pembeli);
				Ins_Akhir_Antrian(&Kasir[nokasir-1].next,Antrian);
				printf("\nAnda Sudah Masuk Antrian\n");
				break;
				case 2:
					main();
			}
			
				break;
			
			case 4 :
				
  
		       	printf("\nNama: %s ",&nama);
				printf("\nno kasir: ");
				printf("\nJumlah barang: \n");
			    printf("pilihan:  %s \n",&pilih);
			   
				system("pause");
				
				break;
			
			case 5  :
				printf("Pilih Kasir(1-5): ");
				scanf("%d",&i);
				Dequeue_Antrian(&Kasir[i-1].next,&nama);
				printf("Nama %s telah dihapus dari antrian\n",&nama);
				system("pause");
				printf("Maaf Toko sudah ditutup");
				exit(1);
				break;
				printf("Pilihan Tidak Tersedia\n");
				system("pause");
				break;
	    	}
	    }
	}
	


