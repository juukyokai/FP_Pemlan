#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>

//global variable to trace
int index_data = 0;


//#include <bits/stdc++.h>
//using namespace std; 
struct tanggal{
  int tanggal;
  int bulan;
  int tahun;
};
struct dir{
  int id;
  char nama[10];
  int jenis;
  int ekstensi;
  struct tanggal tanggal;
  char owner[10]; 
};
//typedef struct dir dir;
/*data jenis_file;
    jenis_file word;
    jenis_file music;
    jenis_file video;
    jenis_file excel;
    jenis_file dll;

data ekstensi;
    ekstensi exe;
    ekstensi docx;
    ekstensi xlsx;
    ekstensi dll;*/

int min(int a, int b){
  if(a<b){
    return a;
  }else {
    return b;
  }
}

int max(int a, int b){
	if(a>b){
		return a;
	}else {
		return b;
	}
}

//tukar int
void tukar_int(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

//tukar string
void tukar_str(char a[], char b[]){
	char temp[124];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

//Insert function
void insert(int n, struct dir data[n]){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int loop=1;
  char temp_case;

  //Create temp variables
  int temp_id;
  char temp_nama[10];
  int temp_jenis;
  int temp_eksten;
  int temp_tgl=tm.tm_mday;
  int temp_bulan=tm.tm_mon+1;
  int temp_tahun=tm.tm_year+1900;
  char temp_owner[10];
  
  while(loop==1){
   system("cls");
   //checking if there's sufficient space at array
   if(index_data<n){
     //Setting ID
   temp_id = index_data+1;
     //input nama
     printf(" Masukkan Nama File : \n");
     printf(" Input : ");
     fflush(stdin);
   scanf("%s",&temp_nama);
     //input jenis
     printf(" Masukkan Jenis File : \n");
     printf("\t1. Word\n");
     printf("\t2. Excel\n");
     printf("\t3. Music\n");
     printf("\t4. Video\n");
     printf("\t5. PDF\n");
   fflush(stdin);
     printf(" Input : ");
   scanf("%d",&temp_jenis);
     temp_eksten = temp_jenis;
     //printf("%d %d \n",temp_jenis,temp_eksten);
     //input owner
     printf(" Masukkan Owner File : ");
     fflush(stdin);
     scanf("%s",&temp_owner);  
    }
    else{
     printf(" Maaf sudah data penuh :'('");
    }
   //saving data to real structure
   printf(" Apakah anda yakin dengan data yang telah anda input? (y/n)\n");
   fflush(stdin);
   scanf("%c",&temp_case);
   if(temp_case == 'y' || temp_case == 'Y'){
    //id
     data[index_data].id = temp_id;
     printf(" ID :%d\n",temp_id);
     //nama
     strcpy(data[index_data].nama,temp_nama);
     //jenis
     data[index_data].jenis = temp_jenis;
     //ekstensi
     data[index_data].ekstensi = temp_eksten;
     //printf("%d %d ",data[index_data].jenis,data[index_data].ekstensi);
     //tanggal
     data[index_data].tanggal.tanggal = temp_tgl;
     data[index_data].tanggal.bulan = temp_bulan;
     data[index_data].tanggal.tahun = temp_tahun;
     //owner
     strcpy(data[index_data].owner,temp_owner);
     index_data++;
     loop=0;
     getch();
   }else if(temp_case == 'n' || temp_case == 'n'){
     printf(" Ulangi input? (y/n)");
     scanf("%c",&temp_case);
     if (temp_case == 'y' || temp_case == 'Y'){
       loop=1;
     }else{
       loop=0;
     }
   }
   else{
     printf(" Input Tidak Valid, Silakan ulangi dari awal!");
   }
  }
}

//view all
void view_all(struct dir data[]){
  int i;
  for(i=0;i<index_data;i++){
    printf("\t%d. %s",(i+1),data[i].nama);
    switch(data[i].ekstensi){
      case 1:
        printf(".docx");
        break;
      case 2:
        printf(".xlsx");
        break;
      case 3:
        printf(".mp3");
        break;
      case 4:
        printf(".mp4");
        break;
      case 5:
        printf(".pdf");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf(" (ID : %d)\n",data[i].id);
    switch(data[i].jenis){
      case 1:
        printf("\t   Word File\n");
        break;
      case 2:
        printf("\t   Excel File\n");
        break;
      case 3:
        printf("\t   Music File\n");
        break;
      case 4:
        printf("\t   Video File\n");
        break;
      case 5:
        printf("\t   PDF File\n");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf("\t   Last Modified : %d-%d-%d",data[i].tanggal.tanggal,data[i].tanggal.bulan,data[i].tanggal.tahun);
    printf(" By %s",data[i].owner);
    printf("\n");
  }
  getch();
}

//view specifics
void view(struct dir data){
  printf("* %s",data.nama);
    switch(data.ekstensi){
      case 1:
        printf(".docx");
        break;
      case 2:
        printf(".xlsx");
        break;
      case 3:
        printf(".mp3");
        break;
      case 4:
        printf(".mp4");
        break;
      case 5:
        printf(".pdf");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf(" (ID : %d)\n",data.id);
    switch(data.jenis){
      case 1:
        printf("\t   Word File\n");
        break;
      case 2:
        printf("\t   Excel File\n");
        break;
      case 3:
        printf("\t   Music File\n");
        break;
      case 4:
        printf("\t   Video File\n");
        break;
      case 5:
        printf("\t   PDF File\n");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf("\t   Last Modified : %d-%d-%d",data.tanggal.tanggal,data.tanggal.bulan,data.tanggal.tahun);
    printf(" By %s",data.owner);
    printf("\n");
}

//main menu
void menu(struct dir data[], int n){
  int cari,cari_index,pil,pil1;
  char input;
  int loop_menu=1;
  while(loop_menu==1){
    system("cls");
    //output memory
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t     ________________________________________________________\n");
    printf("\t\t\t\t\t\t	    |			Directory Management                 |\n");
    printf("\t\t\t\t\t\t	    |  1. Make New Directory	                             |\n");
    printf("\t\t\t\t\t\t	    |  2. View All Files in directory (sorted ID by default) |\n");
    printf("\t\t\t\t\t\t\t    |  3. Search file in Directory                           |\n");
    printf("\t\t\t\t\t\t\t    |  4. Sort file in Directory                             |\n");
    printf("\t\t\t\t\t\t\t    |________________________________________________________|\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\tPress 'q' to Exit\n");
    fflush(stdin);
  scanf("%c",&input);
       //switch-case
    if(input == '1'){
    	insert(n,data);
	}else if(input == '2'){
		if(index_data == 0){
			printf("data masih kosong !!");
			getch();
		}else {
			view_all(data);
		}
	}else if(input == '3'){
		if(index_data == 0){
			printf("data masih kosong !!");
			getch();
		}else {
			printf("masukkan data yang ingin dicari : ");
			scanf("%d",&cari);
			fflush(stdin);
			cari_index = jumpSearch_int(n,cari,data);
			printf("%d\n",cari_index);
			view(data[cari_index]);
			getch();
		}
	}else if(input == '4'){
		printf("Mau sort berdasarkan ID atau nama? (1 / 2)\n");
		scanf("%d",&pil);
		printf("Mau ascending apa descending? (1 / 2)\n");
		scanf("%d",&pil1);
		//pilih jenis sort
		switch(pil){
			case 1:
				bubbleSort_int(data,n,pil1);
			break;
			case 2:
				bubbleSort_char(data,n,pil1);
			break;	
		}
	}else if(input == 'q'){
		trims();
		loop_menu=0;
	}else{
		printf("input tidak valid");
	}
  }
}

//bubble sort char
void bubbleSort_char(struct dir arr[],int n,int pil){
	int i,j;
    /* sorts the string */
    printf("%d",pil);
	switch(pil){
		case 1: //ascending
		for (i = 0; i < index_data-1 ; i++) {
	        for (j = 0; j < index_data-i-1 ; j++){
				if (strcmp(arr[j].nama,arr[j+1].nama) > 0){
		            //After looking for index of the smallest
			    	//changing id
			    	printf("before : %d - %d\n",arr[j].id,arr[j+1].id);
			    	tukar_int(arr[j].id,arr[j+1].id);
			    	printf("after : %d - %d\n",arr[j].id,arr[j+1].id);
			        //changing nama
			        tukar_str(arr[j].nama,arr[j+1].nama);
			        //changing jenis
			        tukar_int(arr[j].jenis,arr[j+1].jenis);
			        //changing ekstensi
			        tukar_int(arr[j].ekstensi,arr[j+1].ekstensi);
			        //changing tanggal
			        tukar_int(arr[j].tanggal.tanggal,arr[j+1].tanggal.tanggal);
			        //changing bulan
			        tukar_int(arr[j].tanggal.bulan,arr[j+1].tanggal.bulan);
			        //changing tahun
			        tukar_int(arr[j].tanggal.tahun,arr[j+1].tanggal.tahun);
			        //changing owner
			        tukar_str(arr[j].owner,arr[j+1].owner);
			    }
			}
		}
			break;
		case 2: //descending
		for (i = 0; i < index_data-1 ; i++) {
	        for (j = 0; j < index_data-i-1 ; j++){
	        	if (strcmp(arr[j].nama,arr[j+1].nama) < 0){
		            //After looking for index of the smallest
			    	//changing id
			    	printf("before : %d - %d\n",arr[j].id,arr[j+1].id);
			    	tukar_int(arr[j].id,arr[j+1].id);
			    	printf("after : %d - %d\n",arr[j].id,arr[j+1].id);
			        //changing nama
			        tukar_str(arr[j].nama,arr[j+1].nama);
			        //changing jenis
			        tukar_int(arr[j].jenis,arr[j+1].jenis);
			        //changing ekstensi
			        tukar_int(arr[j].ekstensi,arr[j+1].ekstensi);
			        //changing tanggal
			        tukar_int(arr[j].tanggal.tanggal,arr[j+1].tanggal.tanggal);
			        //changing bulan
			        tukar_int(arr[j].tanggal.bulan,arr[j+1].tanggal.bulan);
			        //changing tahun
			        tukar_int(arr[j].tanggal.tahun,arr[j+1].tanggal.tahun);
			        //changing owner
			        tukar_str(arr[j].owner,arr[j+1].owner);
			    }
			}
		}
			break;   
    }
    getch();
}

//bubble sort int 1 - digit
void bubbleSort_int(struct dir arr[], int n,int pil){
      int i, j;
	  int tmp_int;
	  char tmp_chr[10];
	  switch(pil){
	  	case 1:
	  		for(i = 0; i < index_data-1 ; i++){
	          for(j=0 ; j < index_data-i-1 ; j ++){
	              if(arr[j].id > arr[j+1].id){
	              	//After looking for index of the smallest
			    	//changing id
			        tmp_int = arr[j].id;
			        arr[j].id = arr[j+1].id;
			        arr[j+1].id = tmp_int;
			        //changing nama
			        strcpy(tmp_chr,arr[j].nama);
			        strcpy(arr[j].nama,arr[j+1].nama);
			        strcpy(arr[j+1].nama,tmp_chr);
			        //changing jenis
			        tmp_int = arr[j].jenis;
			        arr[j].jenis = arr[j+1].jenis;
			        arr[j+1].jenis = tmp_int;
			        //changing ekstensi
			        tmp_int = arr[j].ekstensi;
			        arr[j].ekstensi = arr[j+1].ekstensi;
			        arr[j+1].ekstensi = tmp_int;
			        //changing tanggal
			        tmp_int = arr[j].tanggal.tanggal;
			        arr[j].tanggal.tanggal = arr[j+1].tanggal.tanggal;
			        arr[j+1].tanggal.tanggal = tmp_int;
			        //changing bulan
			        tmp_int = arr[j].tanggal.bulan;
			        arr[j].tanggal.bulan = arr[j+1].tanggal.bulan;
			        arr[j+1].tanggal.bulan = tmp_int;
			        //changing tahun
			        tmp_int = arr[j].tanggal.tahun;
			        arr[j].tanggal.tahun = arr[j+1].tanggal.tahun;
			        arr[j+1].tanggal.tahun = tmp_int;
			        //changing owner
			        strcpy(tmp_chr			,	arr[j].owner);
			        strcpy(arr[j].owner			,	arr[j+1].owner);
			        strcpy(arr[j+1].owner,	tmp_chr);
	              }
	          }
	      }
	  		break;
	  	case 2:
	  		for(i = 0; i < index_data-1 ; i++){
	          for(j=0 ; j < index_data-i-1 ; j ++){
	              if(arr[j].id < arr[j+1].id){
	              	//After looking for index of the smallest
			    	//changing id
			        tmp_int = arr[j].id;
			        arr[j].id = arr[j+1].id;
			        arr[j+1].id = tmp_int;
			        //changing nama
			        strcpy(tmp_chr,arr[j].nama);
			        strcpy(arr[j].nama,arr[j+1].nama);
			        strcpy(arr[j+1].nama,tmp_chr);
			        //changing jenis
			        tmp_int = arr[j].jenis;
			        arr[j].jenis = arr[j+1].jenis;
			        arr[j+1].jenis = tmp_int;
			        //changing ekstensi
			        tmp_int = arr[j].ekstensi;
			        arr[j].ekstensi = arr[j+1].ekstensi;
			        arr[j+1].ekstensi = tmp_int;
			        //changing tanggal
			        tmp_int = arr[j].tanggal.tanggal;
			        arr[j].tanggal.tanggal = arr[j+1].tanggal.tanggal;
			        arr[j+1].tanggal.tanggal = tmp_int;
			        //changing bulan
			        tmp_int = arr[j].tanggal.bulan;
			        arr[j].tanggal.bulan = arr[j+1].tanggal.bulan;
			        arr[j+1].tanggal.bulan = tmp_int;
			        //changing tahun
			        tmp_int = arr[j].tanggal.tahun;
			        arr[j].tanggal.tahun = arr[j+1].tanggal.tahun;
			        arr[j+1].tanggal.tahun = tmp_int;
			        //changing owner
			        strcpy(tmp_chr			,	arr[j].owner);
			        strcpy(arr[j].owner			,	arr[j+1].owner);
			        strcpy(arr[j+1].owner,	tmp_chr);
	              }
	          }
	      }
	  		break;
	  		case 3:
	  		for(i = 0; i < index_data-1 ; i++){
	          for(j=0 ; j < index_data-i-1 ; j ++){
	              if(arr[j].jenis < arr[j+1].jenis){
	              	//After looking for index of the smallest
			    	//changing jenis
			        tmp_int = arr[j].jenis;
			        arr[j].jenis = arr[j+1].jenis;
			        arr[j+1].jenis = tmp_int;
					//changing id
			        tmp_int = arr[j].id;
			        arr[j].id = arr[j+1].id;
			        arr[j+1].id = tmp_int;
			        //changing nama
			        strcpy(tmp_chr,arr[j].nama);
			        strcpy(arr[j].nama,arr[j+1].nama);
			        strcpy(arr[j+1].nama,tmp_chr);
			        //changing ekstensi
			        tmp_int = arr[j].ekstensi;
			        arr[j].ekstensi = arr[j+1].ekstensi;
			        arr[j+1].ekstensi = tmp_int;
			        //changing tanggal
			        tmp_int = arr[j].tanggal.tanggal;
			        arr[j].tanggal.tanggal = arr[j+1].tanggal.tanggal;
			        arr[j+1].tanggal.tanggal = tmp_int;
			        //changing bulan
			        tmp_int = arr[j].tanggal.bulan;
			        arr[j].tanggal.bulan = arr[j+1].tanggal.bulan;
			        arr[j+1].tanggal.bulan = tmp_int;
			        //changing tahun
			        tmp_int = arr[j].tanggal.tahun;
			        arr[j].tanggal.tahun = arr[j+1].tanggal.tahun;
			        arr[j+1].tanggal.tahun = tmp_int;
			        //changing owner
			        strcpy(tmp_chr			,	arr[j].owner);
			        strcpy(arr[j].owner			,	arr[j+1].owner);
			        strcpy(arr[j+1].owner,	tmp_chr);
	              }
	          }
	      }
	  		break;
	  		case 4:
	  		for(i = 0; i < index_data-1 ; i++){
	          for(j=0 ; j < index_data-i-1 ; j ++){
	              if(arr[j].ekstensi < arr[j+1].ekstensi){
	              	//After looking for index of the smallest
			    	//changing jenis
			        tmp_int = arr[j].jenis;
			        arr[j].jenis = arr[j+1].jenis;
			        arr[j+1].jenis = tmp_int;
					//changing id
			        tmp_int = arr[j].id;
			        arr[j].id = arr[j+1].id;
			        arr[j+1].id = tmp_int;
			        //changing nama
			        strcpy(tmp_chr,arr[j].nama);
			        strcpy(arr[j].nama,arr[j+1].nama);
			        strcpy(arr[j+1].nama,tmp_chr);
			        //changing ekstensi
			        tmp_int = arr[j].ekstensi;
			        arr[j].ekstensi = arr[j+1].ekstensi;
			        arr[j+1].ekstensi = tmp_int;
			        //changing tanggal
			        tmp_int = arr[j].tanggal.tanggal;
			        arr[j].tanggal.tanggal = arr[j+1].tanggal.tanggal;
			        arr[j+1].tanggal.tanggal = tmp_int;
			        //changing bulan
			        tmp_int = arr[j].tanggal.bulan;
			        arr[j].tanggal.bulan = arr[j+1].tanggal.bulan;
			        arr[j+1].tanggal.bulan = tmp_int;
			        //changing tahun
			        tmp_int = arr[j].tanggal.tahun;
			        arr[j].tanggal.tahun = arr[j+1].tanggal.tahun;
			        arr[j+1].tanggal.tahun = tmp_int;
			        //changing owner
			        strcpy(tmp_chr			,	arr[j].owner);
			        strcpy(arr[j].owner			,	arr[j+1].owner);
			        strcpy(arr[j+1].owner,	tmp_chr);
	              }
	          }
	      }
	  		break;
	  }
      
}
//Jump Search
int jumpSearch(int n, int x, struct dir arr[]) {           //prototipe belum disesuaikan dengan array of struct
    // Menemukan ukuran blok untuk dilompati 
    int step = sqrt(index_data);
      
    // Menemukan blok yang ditempati oleh elemen 
    // present (if it is present) 
    int prev = 0;
    //id
    while (arr[min(step, index_data)-1].id < x){
            prev = step;
            step += sqrt(index_data);
            if (prev >= index_data) 
                return -1;
    }
    // Melakukan pencarian untuk data didalam blok
    // dimulai dari prev. 
    while (arr[prev].id < x) {
        prev++;
        // If we reached next block or end of 
        // array, element is not present.
        if (prev == min(step, index_data)){
       return -1;
    }
    }
    // Jika elemen ditemukan 
    if (arr[prev].id == x){
      return prev;
  	}
  	
    return -1;
}

//Jump Search
int jumpSearch_char(int n, int x, struct dir arr[]) {           
    // Finding block size to be jumped 
    int step = sqrt(index_data) ;
			
    // Finding the block where element is 
    // present (if it is present) 
    int prev = 0; 
    while (arr[min(step, index_data)-1].id < x){ 
            prev = step; 
            step += sqrt(index_data); 
            if (prev >= index_data) 
                return -1; 
    }
    // Doing a linear search for x in block 
    // beginning with prev. 
    while (arr[prev].id < x) {
        prev++; 
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, index_data)){
		   return -1; 
		}
    } 
    // If element is found 
    if (arr[prev].id == x){
    	return prev; 
	}
    return -1; 
}


// Driver program to test function 
 /*             //int main() 
              { 
                  int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                              34, 55, 89, 144, 233, 377, 610 };//data 
                  int x = 55; 
                  int n = sizeof(arr) / sizeof(arr[0]); 

                  // Find the index of 'x' using Jump Search 
                  int index = jumpSearch(arr, x, n); 

                  // Print the index where 'x' is located 
                  printf("\nNumber %d is at index" index,x); 
                  return 0; 
              } 

*/
void trims(){
  system("cls");
  printf(" Makasih !!");
}

int main(int argc, char *argv[]){
  int i,j,k;    //loop bases
  
  int n=10;
  struct dir data[n];
  menu(data,n);
  printf("%d",index_data);

  return 0;
}
