#include <stdio.h>

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



// List Antrian

datakasir Kasir[4];

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

void Tampil_Antrian (address_A p){		// check
	int i = 1;
	if(isEmpty_Antrian(p)){
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
			printf("%d. %s",i,&p->nama);
			p = next(p);
			if(p != Nil){
				printf("\n");
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

	

//tampilan kasir
void Kasir_Antrian()
{
	printf ("\t___________________________________________________________________________________________________________________________________\n");
	printf ("\t|             |\n");
	printf ("\t|   Kasir 1   |"); Tampil_Antrian(Kasir[0].next);
	printf ("\t|             |\n");
	printf ("\t|----------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("\t|             |\n");
	printf ("\t|   Kasir 2   |"); Tampil_Antrian(Kasir[1].next);
	printf ("\t|             |\n");
	printf ("\t|----------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("\t|             |\n");
	printf ("\t|   Kasir 3   |"); Tampil_Antrian(Kasir[2].next);
	printf ("\t|             |\n");
	printf ("\t|----------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("\t|             |\n");
	printf ("\t|   Kasir 4   |"); Tampil_Antrian(Kasir[3].next);
	printf ("\t|             |\n");
	printf ("\t|----------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("\t|             |\n");
	printf ("\t|   Kasir 5   |"); Tampil_Antrian(Kasir[4].next);
	printf ("\t|             |\n");
	printf ("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
}

	

/*int main()
{
	//header();
	Kasir_Antrian();
}*/


