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
  int status;
};

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
     printf("\n\n\n\t\t\t\t\t ______________________\n");
     printf("\t\t\t\t\t| Masukkan Nama file : |\n");
     printf("\t\t\t\t\t|______________________|\n");
     printf("\t\t\t\t\tInput : ");
     fflush(stdin);
   scanf("%[^\n]",&temp_nama);
     //input jenis
     printf("\n\t\t\t\t\t _______________________\n");
     printf("\t\t\t\t\t| Masukkan Jenis file : |\n");
     printf("\t\t\t\t\t| \t1. Word         |\n");
     printf("\t\t\t\t\t| \t2. Excel        |\n");
     printf("\t\t\t\t\t| \t3. Music        |\n");
     printf("\t\t\t\t\t| \t4. Video        |\n");
     printf("\t\t\t\t\t| \t5. PDF          |\n");
     printf("\t\t\t\t\t|_______________________|\n");
   fflush(stdin);
     printf("\t\t\t\t\tInput : ");
   scanf("%d",&temp_jenis);
     temp_eksten = temp_jenis;
     //printf("%d %d \n",temp_jenis,temp_eksten);
     //input owner
     printf("\n\t\t\t\t\t _______________________\n");
     printf("\t\t\t\t\t| Masukkan owner file : |\n");
     printf("\t\t\t\t\t|_______________________|\n");
     printf("\t\t\t\t\tInput : ");
     fflush(stdin);
     scanf("%[^\n]",&temp_owner);  
    }
    else{
     printf("\n\t\t\t\t\t ________________________\n");
     printf("\n\t\t\t\t\t| Maaf data penuh :'(    |");
     printf("\n\t\t\t\t\t|________________________|\n");
     getch();
     break;
    }
   //saving data to real structure
   printf("\n\t\t\t\t\tApakah anda yakin? (y/n)\n");
   printf("\t\t\t\t\tInput : ");
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
     data[index_data].status = 1;
     index_data++;
     loop=0;
     getch();
   }else if(temp_case == 'n' || temp_case == 'n'){
     printf("\n\t\t\t\t\tulangi input? (y/n)");
     fflush(stdin);
     scanf("%c",&temp_case);
     if (temp_case == 'y' || temp_case == 'Y'){
       loop=1;
     }else{
       loop=0;
     }
   }
   else{
     printf("\n\t\t\t\tinput tidak valid, ulangi dari awal!");
   }
  }
}

//update
int update(struct dir data[], int cari_index){
  printf("\t\t\t\t _________________________________________________\n");
  printf("\t\t\t\t|                                                 |\n");
  printf("\t\t\t\t|                   Fungsi Ubah !                 |\n");
  printf("\t\t\t\t|_________________________________________________|\n");
  char input,input1;
  char temp_nama[128];
  int temp_int;
    system("cls");
    printf("\t\t\t\t _________________________________________________\n");
    printf("\t\t\t\t|                                                  |\n");
    printf("\t\t\t\t| Bagian mana yang ingin anda ubah?                |\n");
    printf("\t\t\t\t| 1. Nama                                          |\n");
    printf("\t\t\t\t| 2. Jenis                                         |\n");
    printf("\t\t\t\t| 3. owner                                         |\n");
    printf("\t\t\t\t|              Tekan q untuk keluar                |\n");
    printf("\t\t\t\t|__________________________________________________|\n");
    printf("\t\t\t\t\tInput : ");
    fflush(stdin);
    scanf("%c",&input);
    if(input == '1'){
      printf("\t\t\t\t __________________________________________________\n");
      printf("\t\t\t\t|                                                  |\n");
      printf("\t\t\t\t|                   Masukkan nama :                |\n");
      printf("\t\t\t\t|__________________________________________________|\n");
      printf("\t\t\t\t\tInput : ");
      fflush(stdin);
      scanf("%[^\n]",&temp_nama);
      printf("\t\t\t\t __________________________________________________\n");
      printf("\t\t\t\t|                                                  |\n");
      printf("\t\t\t\t|             Apakah anda yakin? (y/n)             |\n");
      printf("\t\t\t\t|__________________________________________________|\n");
      printf("\t\t\t\t\tInput : ");
      fflush(stdin);
      scanf("%c",&input1);
      if(input1 == 'y' || input1 == 'Y'){
        strcpy(data[cari_index].nama,temp_nama);
      }else if(input1 == 'n' || input1 == 'N'){
        strcpy(data[cari_index].nama,data[cari_index].nama);
      }else {
        printf("Invalid Input");
      }
    }else if(input == '2'){
      printf("\t\t\t\t __________________________________________________\n");
      printf("\t\t\t\t|                                                  |\n");
      printf("\t\t\t\t|             Masukkan Jenis file :                |\n");
        printf("\t\t\t\t|             1. Word                              |\n");
        printf("\t\t\t\t|             2. Excel                             |\n");
        printf("\t\t\t\t|             3. Music                             |\n");
        printf("\t\t\t\t|             4. Video                             |\n");
        printf("\t\t\t\t|             5. PDF                               |\n");
        printf("\t\t\t\t|__________________________________________________|\n");
        printf("\t\t\t\t\tInput : ");
      fflush(stdin);
      scanf("%d",&temp_int);
        printf("\t\t\t\t __________________________________________________\n");
      printf("\t\t\t\t|                                                  |\n");
      printf("\t\t\t\t|             Apakah anda yakin? (y/n)             |\n");
      printf("\t\t\t\t|__________________________________________________|\n");
      printf("\t\t\t\t\tInput : ");
        fflush(stdin);
        scanf("%c",&input1);
      if(input1 == 'y' || input1 == 'Y'){
        data[cari_index].jenis = temp_int;
        data[cari_index].ekstensi = temp_int;
      }else if(input1 == 'n' || input1 == 'N'){
        data[cari_index].jenis = data[cari_index].jenis;
        data[cari_index].ekstensi = data[cari_index].ekstensi;
      }else {
        printf("\n\t\t\t\t\tInvalid Input");
      }
    }else if(input == '3'){
      printf("\t\t\t\t __________________________________________________\n");
      printf("\t\t\t\t|                                                  |\n");
      printf("\t\t\t\t|                   Masukkan nama :                |\n");
      printf("\t\t\t\t|__________________________________________________|\n");
      printf("\t\t\t\t\tInput : ");
      fflush(stdin);
      scanf("%[^\n]",&temp_nama);
      printf("\t\t\t\t __________________________________________________\n");
      printf("\t\t\t\t|                                                  |\n");
      printf("\t\t\t\t|             Apakah anda yakin? (y/n)             |\n");
      printf("\t\t\t\t|__________________________________________________|\n");
      printf("\t\t\t\t\tInput : ");
      fflush(stdin);
      scanf("%c",&input1);
      if(input1 == 'y' || input1 == 'Y'){
        strcpy(data[cari_index].nama,temp_nama);
      }else if(input1 == 'n' || input1 == 'N'){
        strcpy(data[cari_index].nama,data[cari_index].nama);
      }else {
        printf("\n\t\t\t\tInvalid Input!!\n");
      }
    }else if(input == 'q' || input == 'Q'){
    }else{
      printf("\n\t\t\t\tInvalid Input!!\n");
    }
}

//delete
void hapus(struct dir data[], int cari_index){
  char input;
  printf("\n\t\t\t\t\t _________________________________________________\n");
  printf("\t\t\t\t\t|                                                 |\n");
  printf("\t\t\t\t\t| Apakah anda yakin ingin menghapus berkas? (y/n) |\n");
  printf("\t\t\t\t\t|_________________________________________________|\n");
  fflush(stdin);
  scanf("%c",&input);
  if(input == 'y' || input == 'Y'){
    data[cari_index].status = 0;
  }else if(input == 'n' || input == 'N'){
    data[cari_index].status = 0;
  }else {
    printf("Invalid Input");
  }
  
}

//view all
void view_all(struct dir data[]){
  int i;
  system("cls");
  printf("\t\t\t\t _________________________________________\n");
  printf("\t\t\t\t|                                         |\n");
  printf("\t\t\t\t|               DAFTAR FILE               |\n");
  printf("\t\t\t\t|_________________________________________|\n");
  for(i=0;i<index_data;i++){
    if(data[i].status != 0){
      printf("\t\t\t\t  %d. %s",(i+1),data[i].nama);
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
      printf(" (id : %d)\t\t\n",data[i].id);
      printf("\t\t\t\t|\t");
      switch(data[i].jenis){
        case 1:
          printf("\tWord File");
          break;
        case 2:
          printf("\tExcel File");
          break;
        case 3:
          printf("\tMusic File");
          break;
        case 4:
          printf("\tVideo File");
          break;
        case 5:
          printf("\tPDF File");
          break;
        default:
          printf("\tInvalid Input");
          break;    
      }
      printf("\t\t  |\n");
      printf("\t\t\t\t| Last Modified : %d-%d-%d",data[i].tanggal.tanggal,data[i].tanggal.bulan,data[i].tanggal.tahun);
      printf(" By %s\t  |\n",data[i].owner);
      printf("\t\t\t\t|_________________________________________|\n");
    }
  }
  getch();
}

//view specifics
void view(struct dir data){
  printf("\t\t\t\t * %s ",data.nama);
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
    printf(" (id : %d)\t\t\n",data.id);
    printf("\t\t\t\t\t");
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
    printf("\t\t  \n");
    printf("\t\t\t\t Last Modified : %d-%d-%d",data.tanggal.tanggal,data.tanggal.bulan,data.tanggal.tahun);
    printf(" By %s\t  \n",data.owner);
    printf("\n");
}

//main menu
void menu(struct dir data[], int n){
  int cariInt,cari_index,pil,pil1,ubah;
  char cariChar[128];
  char input;
  int loop_menu=1;
  while(loop_menu==1){
    system("cls");
    //output memory
  printf("\n\n\n\t\t\t\t\t\t The A Team Presents ");
  printf("\n\t\t\t     ________________________________________________________\n");
    printf("\t\t      |     Directory Management                 |\n");
    printf("\t\t      |  1. Make New Directory                               |\n");
    printf("\t\t      |  2. View All Files in directory (sorted ID by default) |\n");
    printf("\t\t\t    |  3. Search file in Directory                           |\n");
    printf("\t\t\t    |  4. Sort file in Directory                             |\n");
    printf("\t\t\t    |  5. Change file in Directory                           |\n");
    printf("\t\t\t    | \t\tPress 'q' to Exit        |\n");
    printf("\t\t\t    |________________________________________________________|\n");
    fflush(stdin);
    printf("\t\t\t    | Input Here : ");scanf("%c",&input);
  
    //switch-case
    if(input == '1'){     //insert
      insert(n,data);
  }else if(input == '2'){   //view-all
    if(index_data == 0){
      printf("data masih kosong !!");
      getch();
    }else {
      bubbleSort_id(data,n,pil1);
      view_all(data);
    }
  }else if(input == '3'){   //search data
    if(index_data == 0){
      printf("data masih kosong !!");
      getch();
    }else {
      printf("\t\t\t     ________________________________________________________\n");
      printf("\t\t\t    |        Mau cari berdasarkan ID atau nama? (1 / 2)      |\n");
      printf("\t\t\t    |________________________________________________________|\n");
      printf("\t\t\t      Input : ");
      fflush(stdin);
      scanf("%d",&pil);
      switch(pil){
        case 1:
          bubbleSort_id(data,n,1);
          printf("\t\t\t     ________________________________________________________\n");
          printf("\t\t\t    |           Masukkan data yang ingin dicari :            |\n");
          printf("\t\t\t    |________________________________________________________|\n");
          printf("\t\t\t     Input : ");
          scanf("%d",&cariInt);
          fflush(stdin);
          cari_index = jumpSearch_int(n,cariInt,data);
          //printf("%d\n",cari_index);
          if(cari_index != -1 && data[cari_index].status != 0){
            view(data[cari_index]);
            getch();
          }else{
            printf("\t\t\t    data tidak ada !!\n");
          }
          getch();
          break;
        case 2:
          bubbleSort_nama(data,n,1);
          printf("\t\t\t     ________________________________________________________\n");
          printf("\t\t\t    |           Masukkan data yang ingin dicari :            |\n");
          printf("\t\t\t    |________________________________________________________|\n");
          printf("\t\t\t     Input : ");
          fflush(stdin);
          scanf("%[^\n]",&cariChar);
          cari_index = jumpSearch_char(n,cariChar,data);
          //printf("%d\n",cari_index);
          if(cari_index != -1 && data[cari_index].status != 0){
            view(data[cari_index]);
          }else{
            printf("\t\t\t    data tidak ada !!\n");
          }
          getch();
          break;
        default:
          printf("\t\t\t    Invalid Input!!\n");
          getch();
          break;
      }
    }
  }else if(input == '4'){     //sort data
    if(index_data == 0){
      printf("\t\t\t    data masih kosong!!\n");
      getch();
    }else {
      printf("\t\t\t     __________________________________\n");
      printf("\t\t\t    |  Mau sort berdasarkan apa?       |\n"); 
      printf("\t\t\t    |  1. ID                           |\n");
      printf("\t\t\t    |  2. Nama                         |\n");
      printf("\t\t\t    |  3. Jenis/Ekstensi               |\n");
      printf("\t\t\t    |  4. Terakhir Dibuat              |\n");
      printf("\t\t\t    |  5. Owner berkas                 |\n");
      printf("\t\t\t    |__________________________________|\n");
      printf("\t\t\t     Input : ");
      scanf("%d",&pil);
      fflush(stdin);
      printf("\t\t\t     ________________________________________________________\n");
      printf("\t\t\t    |          Mau ascending apa descending? (1 / 2)         |\n");
      printf("\t\t\t    |________________________________________________________|\n");
      printf("\t\t\t     Input : ");
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
  }else if(input == '5'){
    bubbleSort_nama(data,n,1);
    printf("\t\t\t     ________________________________________________________\n");
    printf("\t\t\t    |           Masukkan data yang ingin dicari :            |\n");
    printf("\t\t\t    |________________________________________________________|\n");
    printf("\t\t\t     Input : ");
    fflush(stdin);
    scanf("%[^\n]",&cariChar);
    cari_index = jumpSearch_char(n,cariChar,data);
    if(cari_index != -1 && data[cari_index].status != 0){
      view(data[cari_index]);
      printf("\t\t\t     ________________________________________________________\n");
      printf("\t\t\t    |             Mau Hapus atau Ubah? (1 / 2)               |");
      printf("\t\t\t    |________________________________________________________|\n");
      printf("\t\t\t     Input : ");
      scanf("%d",&ubah);
      switch(ubah){
        case 1:
          hapus(data,cari_index);
          break;
        case 2:
          update(data,cari_index);
          break;
        default:
          printf("Invalid Input!!\n");
          break;
      }
    }else{
      printf("\t\t\t    data tidak ada !!\n");
    }
    getch();
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
  //system("cls");
  printf("\t\t\t     ________________________________________________________\n");
  printf("\t\t\t    |                       Terimakasih !!                   |\n");
  printf("\t\t\t    |________________________________________________________|\n");

}

int main(int argc, char *argv[]){
  int i,j,k;    //loop bases
  int n=10;
  struct dir data[n];
  
  menu(data,n);
  return 0;
}
