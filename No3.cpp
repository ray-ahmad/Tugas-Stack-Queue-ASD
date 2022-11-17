#include <iostream>
using namespace std;

/*  Nama: Rayhan Ahmad Rizalullah
    NIM: 121140002
    Kelas: RB
    Tugas Stack dan Queue
    No. 3
*/

// Inisialisasi dan deklarasi variabel global
typedef struct elmlist *address;

struct elmlist {
    int num;
    address next;
};

struct list {
    address first;
};
int maxData;
address create_Elm(int num);

int nbElmt(list &L){
  if(L.first == NULL ){
    return 0;
  }
  else{
    int banyak = 0;
    address cur = L.first;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

// Buat linked list baru
void createList(list &l) {
    l.first = NULL;
}

// Buat node baru
address create_Elm(int num){
    address p;
    p = new elmlist;
    p->num = num;
    p -> next = NULL;
    return p;
}

// Masukkan data di urutan pertama
void insert_first(list &l, address p) {
    p -> next = l.first;
    l.first = p;
}

// Masukkan data di akhir
void add(list &L, address P) {
  if(nbElmt(L) == 0){
    insert_first(L, P);
  }
  else{
    address pointer; 
    pointer = L.first;
    while (pointer -> next != NULL) {
        pointer = pointer -> next;
    }
    pointer -> next = P;
  }
}

bool isFull(list &L){
  if(nbElmt(L) == maxData){
    return true;
  }else{
    return false;
  }
}

bool isEmpty(list &L)
{
  if(nbElmt(L) == 0){
    return true;
  }else{
    return false;
  }
}

// Mencetak semua data 
void printQ(list &l) {
    address p;
    p = l.first;
    while (p != NULL) {
        cout<<p->num;

        p = p -> next;
        if(p!=NULL)
          cout<<", ";
    }
}

// Menghapus kepala (elemen pertama) dari antrian
void dell(list &l, address p) {
    p = l.first;
    l.first = p -> next;
    p -> next = NULL;
}

bool terkecil(list &L, int maks, int min) {
    address p;
    p = L.first;
    while (p != NULL) {
        if(p->num == min or (p->num < maks and p->num == min)){
          dell(L, p);
          return true;
        }
        p = p -> next;
    }
    return false;
}

// hapus node
void deallocate(address &p) {
    delete(p);
}

int main(){
    // deklarasi variabel
    int i,j=0,k=0,x=0,N,num,maxNum=0,maxQ=3,minNum=0;
    address now;
    list l[maxQ];

    cout<<"Masukkan jumlah data: ";
    cin>>maxData;

    cout<<"Masukkan data: \n";
    for(i=0;i<maxData;i++){
      cin>>num;
      /* pada perulangan pertama, max dan min = num
      dan masukkan data di queue pertama*/
      if(i==0){
        createList(l[j]);
        maxNum = num;
        minNum = num;
        now=create_Elm(num);
        add(l[j],now);
      }
      else {
        // jika num > maxNum, masukkan di queue pertama juga
        if (num>maxNum) {
          maxNum = num;
          now=create_Elm(num);
          add(l[0],now);
        }
        else{
          if(j==maxQ-1){
            while(k<maxQ){
              if(terkecil(l[k], maxNum, minNum))
                break;
              
              k++;
            }
            k=0;
          }
          else{
            j++;
            if(num < minNum)
              minNum = num;
            createList(l[j]);
            now=create_Elm(num);
            add(l[j],now);
          }
        }
      }
    }
  cout<<endl<<endl;
  for (i = 0; i < maxQ; i++){
    cout<<"Antrian "<<i+1<<": [";
    printQ(l[i]);
    cout<<"]\n";

  }
  
}