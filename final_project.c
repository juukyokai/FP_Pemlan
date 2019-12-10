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
  char nama[128];
  int jenis;
  int ekstensi;
  struct tanggal tanggal;
  char owner[128]; 
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
    
    
    
    
/*fungsi pembanding*/
int min(int a, int b){
  if(a<b){
    return a;
  }else {
    return b;
  }
}


/*fungsi tukar*/
//tukar string
void tukar_str(char a[], char b[]){
  char temp[128];
  strcpy(temp,a);
  strcpy(a,b);
  strcpy(b,temp);
}
//tukar int
void tukar(struct dir arr[], int j){
  int temp_int;
  //tukar id
  temp_int = arr[j].id;
  arr[j].id = arr[j+1].id;
  arr[j+1].id = temp_int;
  //tukar nama
  tukar_str(arr[j].nama,arr[j+1].nama);
  //tukar jenis
  temp_int = arr[j].jenis;
  arr[j].jenis = arr[j+1].jenis;
  arr[j+1].jenis = temp_int;
  //tukar ekstensi
  temp_int = arr[j].ekstensi;
  arr[j].ekstensi = arr[j+1].ekstensi;
  arr[j+1].ekstensi = temp_int;
  //tukar tanggal
  temp_int = arr[j].tanggal.tanggal;
  arr[j].tanggal.tanggal = arr[j+1].tanggal.tanggal;
  arr[j+1].tanggal.tanggal = temp_int;
  //tukar bulan
  temp_int = arr[j].tanggal.bulan;
  arr[j].tanggal.bulan = arr[j+1].tanggal.bulan;
  arr[j+1].tanggal.bulan = temp_int;
  //tukar tahun
  temp_int = arr[j].tanggal.tahun;
  arr[j].tanggal.tahun = arr[j+1].tanggal.tahun;
  arr[j+1].tanggal.tahun = temp_int;
  //tukar owner
  tukar_str(arr[j].owner,arr[j+1].owner);
}



/*fungsi Teknis*/
//Insert function
void insert(int n, struct dir data[n]){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int loop=1;
  char temp_case;

  //Create temp variables
  int temp_id;
  char temp_nama[128];
  int temp_jenis;
  int temp_eksten;
  int temp_tgl=tm.tm_mday;
  int temp_bulan=tm.tm_mon+1;
  int temp_tahun=tm.tm_year+1900;
  char temp_owner[128];
  
  while(loop==1){
   system("cls");
   //checking if there's sufficient space at array
   if(index_data<n){
     //Setting ID
   temp_id = index_data+1;
     //input nama
     printf("masukkan nama file : \n");
     printf("Input : ");
     fflush(stdin);
   scanf("%[^\n]",&temp_nama);
     //input jenis
     printf("masukkan Jenis file : \n");
     printf("\t1. Word\n");
     printf("\t2. Excel\n");
     printf("\t3. Music\n");
     printf("\t4. Video\n");
     printf("\t5. PDF\n");
   fflush(stdin);
     printf("Input : ");
   scanf("%d",&temp_jenis);
     temp_eksten = temp_jenis;
     //printf("%d %d \n",temp_jenis,temp_eksten);
     //input owner
     printf("masukkan owner file : ");
     fflush(stdin);
     scanf("%[^\n]",&temp_owner);  
    }
    else{
     printf("Maaf data penuh :'('");
    }
   //saving data to real structure
   printf("Apakah anda yakin dengan data yang telah anda input? (y/n)\n");
   fflush(stdin);
   scanf("%c",&temp_case);
   if(temp_case == 'y' || temp_case == 'Y'){
    //id
     data[index_data].id = temp_id;
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
     printf("ulangi input? (y/n)");
     scanf("%c",&temp_case);
     if (temp_case == 'y' || temp_case == 'Y'){
       loop=1;
     }else{
       loop=0;
     }
   }
   else{
     printf("input tidak valid, ulangi dari awal!");
   }
  }
}

//view all
void view_all(struct dir data[]){
  int i;
  for(i=0;i<index_data;i++){
    printf("%d. %s",(i+1),data[i].nama);
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
    printf(" (id : %d)\n",data[i].id);
    switch(data[i].jenis){
      case 1:
        printf("\tWord File\n");
        break;
      case 2:
        printf("\tExcel File\n");
        break;
      case 3:
        printf("\tMusic File\n");
        break;
      case 4:
        printf("\tVideo File\n");
        break;
      case 5:
        printf("\tPDF File\n");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf("\tLast Modified : %d-%d-%d",data[i].tanggal.tanggal,data[i].tanggal.bulan,data[i].tanggal.tahun);
    printf(" By %s",data[i].owner);
    printf("\n");
  }
  getch();
}

//view specifics
void view(struct dir data){
  printf("* %s ",data.nama);
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
    printf(" (id : %d)\n",data.id);
    switch(data.jenis){
      case 1:
        printf("\tWord File\n");
        break;
      case 2:
        printf("\tExcel File\n");
        break;
      case 3:
        printf("\tMusic File\n");
        break;
      case 4:
        printf("\tVideo File\n");
        break;
      case 5:
        printf("\tPDF File\n");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf("\tLast Modified : %d-%d-%d",data.tanggal.tanggal,data.tanggal.bulan,data.tanggal.tahun);
    printf(" By %s",data.owner);
    printf("\n");
}

//main menu
void menu(struct dir data[], int n){
  int cariInt,cari_index,pil,pil1;
  char cariChar[128];
  char input;
  int loop_menu=1;
  while(loop_menu==1){
    system("cls");
    //output memory
  printf("\n\n\n\n\t\t\t     ________________________________________________________\n");
    printf("\t\t      |     Directory Management                 |\n");
    printf("\t\t      |  1. Make New Directory                               |\n");
    printf("\t\t      |  2. View All Files in directory (sorted ID by default) |\n");
    printf("\t\t\t    |  3. Search file in Directory                           |\n");
    printf("\t\t\t    |  4. Sort file in Directory                             |\n");
    printf("\t\t\t    | \t\tPress 'q' to Exit        |\n");
    printf("\t\t\t    |________________________________________________________|\n");
    fflush(stdin);
    printf("\t\t\t    |  Input Here : ");scanf("%c",&input);printf("                             |\n");
  
    //switch-case
    if(input == '1'){
      insert(n,data);
  }else if(input == '2'){
    if(index_data == 0){
      printf("data masih kosong !!");
      getch();
    }else {
      bubbleSort_id(data,n,pil1);
      view_all(data);
    }
  }else if(input == '3'){
    if(index_data == 0){
      printf("data masih kosong !!");
      getch();
    }else {
      printf("Mau cari berdasarkan ID atau nama? (1 / 2)\n");
      scanf("%d",&pil);
      switch(pil){
        case 1:
          bubbleSort_id(data,n,1);
          printf("masukkan data yang ingin dicari : ");
          scanf("%d",&cariInt);
          fflush(stdin);
          cari_index = jumpSearch_int(n,cariInt,data);
          printf("%d\n",cari_index);
          if(cari_index != -1){
            view(data[cari_index]);
          }else{
            printf("data tidak ada !!\n");
          }
          getch();
          break;
        case 2:
          bubbleSort_nama(data,n,1);
          printf("masukkan data yang ingin dicari : ");
          fflush(stdin);
          scanf("%[^\n]",&cariChar);
          cari_index = jumpSearch_char(n,cariChar,data);
          printf("%d\n",cari_index);
                    if(cari_index != -1){
            view(data[cari_index]);
          }else{
            printf("data tidak ada !!\n");
          }
          getch();
          break;
        default:
          printf("Invalid Input!!\n");
          break;
      }
        
    }
  }else if(input == '4'){
    if(index_data == 0){
      printf("data masih kosong!!\n");
      getch();
    }else {
      printf("Mau sort berdasarkan apa? \t\n1. ID\t\n2. Nama\t\n3. Jenis/Ekstensi\t\n4. Terakhir Dibuat\t\n5. Owner berkas)\n");
      scanf("%d",&pil);
      fflush(stdin);
      printf("Mau ascending apa descending? (1 / 2)\n");
      scanf("%d",&pil1);
      fflush(stdin);
        //pilih jenis sort
        switch(pil){
          case 1:
            bubbleSort_id(data,n,pil1);
            view_all(data);
            break;
          case 2:
            bubbleSort_nama(data,n,pil1);
            view_all(data);
            break;
          case 3:
            bubbleSort_jenis(data,n,pil1);
            view_all(data);
            break;
          case 4:
            bubbleSort_tanggal(data,n,pil1);
            view_all(data);
            break;
          case 5:
            bubbleSort_owner(data,n,pil1);
            view_all(data);
            break;
          default:
            printf("Invalid Input!!\n");
            break;
        }
    }
  }else if(input == 'q'){
    trims();
    loop_menu=0;
  }else{
    printf("input tidak valid");
  }
  }
}




/*fungsi tugas*/
//bubble sort char 1 - nama
void bubbleSort_nama(struct dir arr[],int n,int pil){
  int i,j;
    /* sorts the string */
  switch(pil){
    case 1: //ascending
    for (i = 0; i < index_data-1 ; i++) {
          for (j = 0; j < index_data-i-1 ; j++){
        if (strcmp(arr[j].nama,arr[j+1].nama) > 0){
                //After looking for index of the smallest
            tukar(arr,j);
          }
      }
    }
      break;
    case 2: //descending
    for (i = 0; i < index_data-1 ; i++) {
          for (j = 0; j < index_data-i-1 ; j++){
            if (strcmp(arr[j].nama,arr[j+1].nama) < 0){
                //After looking for index of the smallest
            tukar(arr,j);
          }
      }
    }
      break;   
    }
}

//bubble sort char 1 - owner
void bubbleSort_owner(struct dir arr[],int n,int pil){
  int i,j;
    /* sorts the string */
  switch(pil){
    case 1: //ascending
    for (i = 0; i < index_data-1 ; i++) {
          for (j = 0; j < index_data-i-1 ; j++){
        if (strcmp(arr[j].owner,arr[j+1].owner) > 0){
                //After looking for index of the smallest
            tukar(arr,j);
          }
      }
    }
      break;
    case 2: //descending
    for (i = 0; i < index_data-1 ; i++) {
          for (j = 0; j < index_data-i-1 ; j++){
            if (strcmp(arr[j].owner,arr[j+1].owner) < 0){
                //After looking for index of the smallest
            tukar(arr,j);
          }
      }
    }
      break;   
    }
}

//bubble sort int 1 - id
void bubbleSort_id(struct dir arr[], int n,int pil){
      int i, j;
    switch(pil){
      case 1:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].id > arr[j+1].id){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
      case 2:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].id < arr[j+1].id){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
    }
      
}

//bubble sort int 2 - jenis
void bubbleSort_jenis(struct dir arr[], int n,int pil){
      int i, j;
    switch(pil){
      case 1:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].jenis > arr[j+1].jenis){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
      case 2:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].jenis < arr[j+1].jenis){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
    }
      
}

//bubble sort int 3 - ekstensi
void bubbleSort_ekstensi(struct dir arr[], int n,int pil){
      int i, j;
    switch(pil){
      case 1:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].ekstensi > arr[j+1].ekstensi){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
      case 2:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].ekstensi < arr[j+1].ekstensi){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
    }
      
}

//bubble sort int 4 - date
void bubbleSort_tanggal(struct dir arr[], int n,int pil){
      int i, j;
    switch(pil){
      case 1:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].tanggal.tanggal > arr[j+1].tanggal.tanggal && arr[j].tanggal.bulan > arr[j+1].tanggal.bulan && arr[j].tanggal.tahun > arr[j+1].tanggal.tahun){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
      case 2:
        for(i = 0; i < index_data-1 ; i++){
            for(j=0 ; j < index_data-i-1 ; j ++){
                if(arr[j].tanggal.tanggal > arr[j+1].tanggal.tanggal && arr[j].tanggal.bulan > arr[j+1].tanggal.bulan && arr[j].tanggal.tahun > arr[j+1].tanggal.tahun){
                  //After looking for index of the smallest
            tukar(arr,j);
                }
            }
        }
        break;
    }
      
}

//Jump Search int
int jumpSearch_int(int n, int x, struct dir arr[]) {           
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

//Jump Search char
int jumpSearch_char(int n, char x[], struct dir arr[]) {           
    // Finding block size to be jumped 
    int step = sqrt(index_data) ;
      
    // Finding the block where element is 
    // present (if it is present) 
    int prev = 0; 
    while (strcmp(arr[min(step, index_data)-1].nama,x) < 0){ 
            prev = step; 
            step += sqrt(index_data); 
            if (prev >= index_data) 
                return -1; 
    }
    // Doing a linear search for x in block 
    // beginning with prev. 
    while (strcmp(arr[prev].nama,x) < 0) {
        prev++; 
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, index_data)){
       return -1; 
    }
    } 
    // If element is found 
    if (strcmp(arr[prev].nama,x) == 0){
      return prev; 
  }
    return -1; 
}



/*fungsi tambahan*/
void trims(){
  system("cls");
  printf("Makasih !!");
}

int main(int argc, char *argv[]){
  int i,j,k;    //loop bases
  int n=10;
  struct dir data[n];
  
  menu(data,n);
  return 0;
}
