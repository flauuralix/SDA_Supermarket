#include "header.h"
#include "boolean.h"
#include<stdio.h>



boolean cek_nodepelanggan(address_BB p){  
//prosedure bertujuan untuk mengcek linked kosong atau tidak kosong dan 
//mengembalikan nilai true jika linked kosong dan sebaliknya jika else
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void node_baru(address_BB *p){	
//prosedure bertujuan untuk membuat node baru pada linked. node baru akan di
//simpan pada alamat yang ditunjuk pointer p

	*p = (address_BB)malloc(sizeof(List_BarangBelian));
	
}

void isi_nodebarang (address_BB *p , infotype harga, infochar Nama_Barang, infotype Jumlah_Barang){	// check
//prosedure bertujuan untuk mengisi data pada node barang yang di tumjuk oleh pointer p
//data terdiri dari barang,harga dan jumla barang
	if(isEmpty_BarangBelian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Harga(*p) = harga;
		Nama_Barang(*p) = nama_barang;
		Jumlah_Barang(*p) = jumlah_barang;
	}
	
}

void node_Insakhir (address_BB *p, address_BB PNew){	
//prosedure bertujuan untuk mengisi node baru (Pnew) pada akhir linked
//barang yang ditunjuk oleh pointer p 
	address_BB A;
	if(isEmpty_BarangBelian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_BarangBelian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}

void del_awalbarang (address_BB * p, infochar * X){	// check
//prosedure bertujuan untuk menghapus node pertama pada linked barang yang ditunjuk oleh pointer p.
//barang yang dihapus akan di simpen pada variabel x	
	address_BB A;
	
	if(isEmpty_BarangBelian(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = Nama_Barang(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
}
