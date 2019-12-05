#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
typedef struct dir dir;
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
    
    
int main(int argc, char *argv[]){
  int i,j,k;    //loop bases
  
  int index_data = 0;  //tracing banyak data
  
  int n=10;
  struct dir data[n];
  insert();
  
  
  
  
  
  return 0;
}

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
void insert(dir data[], int n, int index_data){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int loop=1;
  char temp_case;

  //Create temp variables
  char temp_id[3];
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

     //input nama
     printf("masukkan nama file : \n");
     printf("Input : ");scanf("%s",&temp_nama);
     //input jenis
     printf("masukkan Jenis file : \n");
     printf("\t1. Word\n");
     printf("\t2. Excel\n");
     printf("\t3. Music\n");
     printf("\t4. Video\n");
     printf("\t5. PDF\n");
     printf("Input : ");scanf("%d",&temp_jenis);
     temp_jenis = temp_eksten;
     //input owner
     printf("masukkan owner file : ");
     scanf("%s",&temp_owner);  
    }
    else{
     printf("Maaf data penuh :'('");
    }
   //saving data to real structure
   printf("Apakah anda yakin dengan data yang telah anda input? (y/n)\n");
   scanf("%c",&temp_case);
   if(temp_case == 'y' || temp_case == 'Y'){
     data[index_data].id = index_data+1;
     strcpy(data[index_data].nama,temp_nama);
     data[index_data].jenis = temp_jenis;
     data[index_data].ekstensi = temp_eksten;
     data[index_data].tanggal.tanggal = temp_tgl;
     data[index_data].tanggal.bulan = temp_bulan;
     data[index_data].tanggal.tahun = temp_tahun;
     strcpy(data[index_data].owner,temp_owner);
     index_data++;
     loop=0;
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

//view function
void view(dir data[], int n, int index_data){
  int i,j;
  for(i=0;i<index_data;i++){
    printf("%d. %s",(i+1),data[i].nama);
    switch(data[i].ekstensi){
      case 1:
        printf(".docx\n");
        break;
      case 2:
        printf(".xlsx\n");
        break;
      case 3:
        printf(".mp3\n");
        break;
      case 4:
        printf(".mp4\n");
        break;
      case 5:
        printf(".pdf\n");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    switch(data[i].jenis){
      case 1:
        printf("\t Word File\n");
        break;
      case 2:
        printf("\t Excel File\n");
        break;
      case 3:
        printf("\t Music File\n");
        break;
      case 4:
        printf("\t Video File\n");
        break;
      case 5:
        printf("\t PDF File\n");
        break;
      default:
        printf("Invalid Input");
        break;    
    }
    printf("%d");
  }
  
}

//main menu
void menu(dir data[], int n, int index_data){
  int input;
  int loop_menu=1;
  while(loop_menu==1){
    system("cls");
    //output memory
    printf("Directory Management\n");
    printf("1. Make New Directory\n");
    printf("2. View All Files in directory (sorted ID by default)\n");
    printf("3. Search file in Directory\n");
    printf("4. Sort file in Directory\n");
    printf("press 'q' to exit\n");
    scanf("%c",&input);
    //switch-case
    switch(input){
      case '1': // insert
          insert(data,n,index_data);
      break;
      case '2': //view
          view(data,n,index_data);
      break;
      case '3': //search
          jumpSearch();
      break;
      case '4': //sort
          bubbleSort();
      break;
      case 'q':
        loop_menu=0;
        break;
    }
    
  }
}
void bubbleSort(dir arr[], int n){  //prototype
      int i, j, tmp;
      for(i = 0; i < n; i++){
          for(j=0; j < n-i-1; j ++){
              if(arr[j] > arr[j+1]){
                 tmp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = tmp;
              }
          }
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


int jumpSearch(int arr[], int x, int n) {           //prototipe belum disesuaikan dengan array of struct
                  // Finding block size to be jumped 
                  int step = sqrt(n); 

                  // Finding the block where element is 
                  // present (if it is present) 
                  int prev = 0; 
                  while (arr[min(step, n)-1] < x) 
                  { 
                      prev = step; 
                      step += sqrt(n); 
                      if (prev >= n) 
                          return -1; 
                  } 

                  // Doing a linear search for x in block 
                  // beginning with prev. 
                  while (arr[prev] < x) 
                  { 
                      prev++; 

                      // If we reached next block or end of 
                      // array, element is not present. 
                      if (prev == min(step, n)) 
                          return -1; 
                  } 
                  // If element is found 
                  if (arr[prev] == x) 
                      return prev; 

                  return -1; 
              } 

              // Driver program to test function 
              //int main() 
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


