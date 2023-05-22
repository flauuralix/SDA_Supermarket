/*       
File Name		: Antrian.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "header.h"

/* ======= End of Header File ====== */


//============================================================================================
/*   			                Pengembangan modul pada program  	    		        	*/

boolean isEmpty_Antrian(address_A p)
/*
I.S : Ada address_A (Antrian) terdefinisi p
F.S : Mengembalikan nilai true jika address_P kosong (NULL), false jika address_P tidak kosong
*/
{
	
	if(p == NULL)	// Mengecek apakah p = kosong ?
	{
		return 1;	// true
	}else{
		return 0;	// false
	}
	
}
//------------------------------------------------------------------------------------------------------ 01


void Create_Node_Antrian (address_A *p)
/*
I.S : Address_A terdefinisi *p
F.S : Node baru berhasil dialokasi kan pada memori dan pointer *p menunjuk Node tersebut

*/
{
	*p = (address_A)malloc(sizeof(List_Antrian));
	
}
//------------------------------------------------------------------------------------------------------ 02

void Isi_Node_Antrian (address_A *p , infochar nama)
/*
I.S : *p alamat node yang akan diisi oleh infochar nama
F.S : Node Antrian akan terisi dengan nama 
	Jika node belum dialokasikan, maka program akan menampilkan pesan "Node Belum di Alokasi".
*/
{	
	if(isEmpty_Antrian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		nama(*p) = nama;
	}
	
}
//------------------------------------------------------------------------------------------------------ 03


void Tampil_List_Antrian (address_A p)
{
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
//------------------------------------------------------------------------------------------------------ 04


void Ins_Akhir_Antrian (address_A *p, address_A PNew)
{
	
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
//------------------------------------------------------------------------------------------------------ 05


void Del_Awal_Antrian (address_A * p, infochar * X)
{	
	address_A A;
	
	if(isEmpty_Antrian(*p)){
		printf("Antrian Kosong\n");
	}else{
		A = *p;
		*X = nama(A);
		*p= next(*p);
		A = NULL;
		free(A);
	}
	
}
//------------------------------------------------------------------------------------------------------ 06



void Dequeue_Antrian(Queue_A *p,infochar *X)
{	
	Del_Awal_Antrian(&(*p),&(*X));
}
//------------------------------------------------------------------------------------------------------ 07
//============================================================================================
/*   			               Penambahan modul pada program  	    		        		*/


void data_antrian (address_A p)
{
	int i = 0;
	if(isEmpty_Antrian(p)){
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
//			printf("%d. %s",i,&p->nama);
			p = next(p);
			if(p != Nil){
				printf("\t\n");
			}
		i++;	
		}
		printf("Jumlah pelanggan : %d\n",i);
	}	
	
}

void Hapusantrian(address_A *p,infochar *X) 
{
    /* Deklarasi Variabel */
    address_A temp;
    char input[MAX_LENGTH];
    bool ketemu = false;
    infotype inputData;

  
   printf("Masukkan nama: ");
   scanf("%s", input);
    
    if (strcmp(input, nama(*p)) == 0) {
        ketemu = true;
        
    Del_Awal_Antrian(&(*p),&(*X));
    } else {
        temp = *p;
        while (next(temp) != Nil) {
            temp = next(temp);
            if (strcmp(input, nama(next(temp))) == 0) {
                ketemu = true;
                Hapus_Last(&temp);
                break;
            }
        }
        if (!ketemu) {
            printf("\nama tidak diketahui\n");
        }
    }
   
	
}

void Hapus_Last(address_A (*p))
{
    address_A temp = (*p)->next;
    (*p)->next = (*p)->next->next;
    free(temp);
}

void HapusFirst(address_A (*p)) 
{
    address_A temp = (*p);
    (*p)= temp->next;
    free(temp);
}


void DelAntrian(address_A *p, infochar *X)
{
    if (isEmpty_Antrian(*p)){
		printf("Antrian Kosong\n");
	}else {
        
        address_A A = *p;
        *X = nama(A);
        *p = next(*p);

        free(A);
    }
}