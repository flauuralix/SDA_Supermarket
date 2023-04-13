#include <stdio.h>
#include "header.h"


//void CreateEmpty_BarangBelian(Queue_BB *Q){	// gakepake
//	
//	*Q = NULL;
//	
//}

//boolean IsEmpty_BarangBelian(Queue_BB Q){		// gakepake
//		
//	return(isEmpty_BarangBelian(Q));
//	
//}

void Enqueue_BarangBelian(Queue_BB *Q,infotype X, infochar Y, infotype Z){	// check
	
	address_BB a = NULL;
	
	Create_Node_BarangBelian(&a);
	Isi_Node_BarangBelian(&a, X, Y, Z);
	Ins_Akhir_BarangBelian(&(*Q),a);
	
}

//void Dequeue_BarangBelian(Queue_BB *Q,infochar *X){	// gakepake
//	
//	Del_Awal_BarangBelian(&(*Q),&(*X));
//	
//}


// List BarangBelian

boolean isEmpty_BarangBelian(address_BB p){  // check
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_BarangBelian (address_BB *p){	// check
	
	*p = (address_BB)malloc(sizeof(List_BarangBelian));
	
}

void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar nama_barang, infotype jumlah_barang){	// check
	
	if(isEmpty_BarangBelian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Harga(*p) = harga;
		Nama_Barang(*p) = nama_barang;
		Jumlah_Barang(*p) = jumlah_barang;
	}
	
}

void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew){	// check
	
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


void Del_Awal_BarangBelian (address_BB * p, infochar * X){	// check
	
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