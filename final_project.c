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

//bubble sort char #prototype
void bubble_sort(int data[],int n){
  int i,j,k;
     for (i = 0; i < n; ++i){
         for (j = i + 1; j < n; ++j){
             if (data[i] > data[j]){
                    k =  data[i];
                    data[i] = data[j];
                    data[j] = k;
            }
         }
      }
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
  int cari,cari_index;
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
    view_all(data);
  }else if(input == '3'){
    printf(" Masukkan data yang ingin dicari : ");
    fflush(stdin);
    scanf("%d",&cari);
    cari_index = jumpSearch(data,cari,n);
    view(data[cari_index]);
  }else if(input == '4'){
    bubbleSort_int(data,n);
  }else if(input == 'q'){
    trims();
    loop_menu=0;
  }else{
    printf(" Input Tidak Valid");
  }
  }
}

//bubble sort
void bubbleSort_int(struct dir arr[], int n){  //prototype
    int i, j, tmp_index;
    int tmp_int;
    char tmp_chr[10];
      for(i = 0; i < index_data ; i++){
          for(j=i+1; j < index_data; j ++){
              if(arr[i].id > arr[j].id){
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
        strcpy(tmp_chr      , arr[j].owner);
        strcpy(arr[j].owner     , arr[j+1].owner);
        strcpy(arr[j+1].owner,  tmp_chr);
              }
          }
        //After looking for index of the smallest

      } 
}
/*
                  //int main() {
                    int array[100], n, i, j;
                    printf("Masukkan banyak elemen: ");
                    scanf("%d", &n);
                    printf("Masukkan nilai: \n");
                    for(i = 0; i < n; i++){
                      scanf("%d", &array[i]);
                    }
                    bubbleSort(array, n);
                    printf("Hasil pengurutan sebagai berikut:\n");
                    for(i = 0; i < n; i++){
                      printf("%d ", array[i]);
                    }
                    printf("\n");
                  }
*/

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
  	//nama
	while (arr[min(step, index_data)-1].nama < x){
            prev = step;
            step += sqrt(index_data);
            if (prev >= index_data) 
                return -1;
    }
    // Melakukan pencarian untuk data didalam blok
    // dimulai dari prev. 
    while (arr[prev].nama < x) {
        prev++;
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, index_data)){
       return -1;
    	}
    }
    // Jika elemen ditemukan 
    if (arr[prev].nama == x){
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
