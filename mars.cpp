#include <stdio.h>
#include "header.h"


//header tampilan
void header()
{
	printf ("\n");
	printf("\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf ("\t\t\t ____________________________\n");
	printf ("\t\t\t ||                        ||   $$\\\\      $$\\     $$$$$\\\\    $$$$$$$$\\\\   $$$$$$$$$\\     $$$$$\\\\    $$\\     $$\\\n");
	printf ("\t\t\t ||   ||===============    ||   $$$ \\    $$$ |   $$ / $$ \\   $$ |   $$ |  $$ _______|   $$ / $$ \\   $$ |    $$ |\n");
	printf ("\t\t\t ||   ||\\\\        //||     ||   $$ $ \\  $ $$ |  $$ |   $$ \\  $$ |   $$ |  $$ |         $$ |   $$ \\  $$ |    $$ |\n");
	printf ("\t\t\t ||   || \\\\      // ||     ||   $$ |$ \\$ /$$ |  $$ |   $$ |  $$$$$$$$$ |  $$ |         $$ |   $$ |  $$ |    $$ |\n");
	printf ("\t\t\t ||   ||  \\\\    //  ||     ||   $$ | $$ / $$ |  $$$$$$$$$ |  $$ | $$  _|  $$ |         $$$$$$$$$ |  $$ |    $$ |\n");
	printf ("\t\t\t ||   ||   \\\\  //   ||     ||   $$ | \\_/  $$ |  $$ |   $$ |  $$ |  $$ \\   $$ |         $$ |   $$ |  $$ |    $$ |\n");
	printf ("\t\t\t ||   ||    \\\\//====||     ||   $$ |      $$ |  $$ |   $$ |  $$ |   $$ \\  $$$$$$$$$\\   $$ |   $$ |  $$$$$$$$$$ |\n");
	printf ("\t\t\t ||   ||     //     ||     ||   \\__|      \\__|  \\__|   \\__|  \\__|   \\__|  \\_________|  \\__|   \\__|  \\__________|\n");
	printf ("\t\t\t ||   ||    //      ||     ||\n");
	printf ("\t\t\t ||   ||===============    ||                'Barang Fresh Setiap Hari Dengan Harga Terjangkau'\n");
	printf ("\t\t\t ||                        ||\n");
	printf ("\t\t\t ----------------------------\n");
	printf("\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

//tampilan kasir

/*void Kasir_Antrian()
{
	
}*/


// List Antrian


//void CreateEmpty_Antrian(Queue_A *Q){	// gakepake
//	
//	*Q = NULL;
//	
//}

//boolean IsEmpty_Antrian(Queue_A Q){	// gakepake
//	
//	return(isEmpty_Antrian(Q));
//	
//}

//void Enqueue_Antrian(Queue_A *Q,infochar X,infotype Z){	// gakepake
//	
//	address_A a = NULL;
//	
//	Create_Node_Antrian(&a);
//	Isi_Node_Antrian(&a, X);
//	Ins_Akhir_Antrian(&(*Q),a);
//	
//}

void Dequeue_Antrian(Queue_A *Q,infochar *X){	// check
	
	Del_Awal_Antrian(&(*Q),&(*X));
	
}


// List Antrian

boolean isEmpty_Antrian(address_A p){	// check
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Antrian (address_A *p){	// check
	
	*p = (address_A)malloc(sizeof(List_Antrian));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Antrian (address_A *p , infochar nama){	// check
	
	if(isEmpty_Antrian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		nama(*p) = nama;
	}
	
}

void Tampil_List_Antrian (address_A p){		// check
	int i = 1;
	if(isEmpty_Antrian(p)){
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
			printf("%d. %s",i,&p->nama);
			p = next(p);
			if(p != Nil){
				printf("\t");
			}
		i++;	
		}
		printf("\n");
	}	
	
}

void Ins_Akhir_Antrian (address_A *p, address_A PNew){	// check
	
	address_A A;
	if(isEmpty_Antrian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Antrian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


void Del_Awal_Antrian (address_A * p, infochar * X){	// check
	
	address_A A;
	
	if(isEmpty_Antrian(*p)){
		printf("Antrian Kosong\n");
	}else{
		A = *p;
		*X = nama(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
	
}
