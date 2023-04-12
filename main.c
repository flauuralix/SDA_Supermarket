#include "claudia.h"
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