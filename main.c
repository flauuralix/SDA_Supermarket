/*       
File Name		: main.c
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "claudia.h"


/* ======= End of Header File ====== */



int main(){
  address First = Nil, Last = Nil;
  	 
  int menu=4;

  while (menu != 0)
  {
  	
    menu = 4;
    
    tampilanmenu();
    pilihMenu(&menu);
    switch (menu){
    	case 1:
       pelanggan(&First);
       tempat();
        system("cls");
    		break;
    	case 2:
    		
    		break;
    	case 3:
    		
    		break;
    	case 4:
    		
    		break;
	}
}
}