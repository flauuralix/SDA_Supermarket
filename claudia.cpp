#include <stdio.h>
#include "header.h"



/* ======= End of Header File ====== */



//==================================== List Pelanggan

//void CreateEmpty_Pembeli(Queue_P *Q){	// gakepake
//	
//	*Q = NULL;
//	
//}

//boolean IsEmpty_Pembeli(Queue_P Q){	// gakepake
//	
//	return(isEmpty_Pembeli(Q));
//	
//}

void Enqueue_Pembeli(Queue_P *Q, Queue_BB *P, infochar Y, infotype Z){ // check
	
	address_P a = NULL;
	address_BB b = NULL;
	
	Create_Node_Pembeli(&a);
	Create_Node_BarangBelian(&b);
	Isi_Node_Pembeli(&a, &b, Y, Z);
	Ins_Akhir_Pembeli(&(*Q),a);
	
}

//void Dequeue_Pembeli(Queue_P *Q,infochar *X){
//	
//	Del_Awal_Pembeli(&(*Q),&(*X));
//	
//}


// List Pelanggan

boolean isEmpty_Pembeli(address_P p){ // check
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Pembeli (address_P *p){	// check
	
	*p = (address_P)malloc(sizeof(List_Pembeli));
/*	if(p != Nil){
		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
	}else{
		printf("Gagal Alokasi\n");
	}*/
	
}

void Isi_Node_Pembeli (address_P *p , address_BB *q, infochar Nama_Pembeli, infotype No_Kasir){ // check
	
	if(isEmpty_Pembeli(*p)){
		printf("Node Belum di Alokasi");
	}else{
		next(*p) = Nil;
		BarangBelian(*p) = *q;
		Nama_Pembeli(*p) = Nama_Pembeli;
		No_Kasir(*p) = No_Kasir;
	}
	
}

void Ins_Akhir_Pembeli (address_P *p, address_P PNew){ // check
	
	address_P A;
	if(isEmpty_Pembeli(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Pembeli(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}

void tampilan_kasir(){
	    printf("\t|-----------------------------|");
       	printf("\n\t|\t     MENU             |");    
       	 printf("\n\t|-----------------------------|");
		printf(" \n\t|     1.  PELANGGAN           |\n");
		 printf("\t|-----------------------------|");
		printf(" \n\t|     2. PROSES KASIR         |\n");
		printf("\t|-----------------------------|");
		printf("\n\t|     3. PEMABAYARAN          |\n");
		printf("\t|-----------------------------|");
		printf(" \n\t|     4.   HISTORY            |\n");
		printf("\t|-----------------------------|");
		printf(" \n\t|     5.     EXIT             |\n");
		printf("\t|-----------------------------|");
	}

//void tempat(int *index){
//
////    int pil;
////    scanf("%d", &pil);
////   
////    while (pil!=1&& pil!=2) {
////        printf ("Pilihan Anda tidak ada, ketik ulang: ");
////        scanf("%d",&pil);
////    }
////    switch (pil) {
////        case 1:
////            printf("\t\t ---ANDA MEMILIH KERAJANG---\n");
////           
////            break;
////        case 2:
////            printf("\t\t ---ANDA MEMILIH TROLI---\n");
////            break;
////    }
//}

//====================================