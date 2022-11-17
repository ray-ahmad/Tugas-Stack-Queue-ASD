#include <iostream>
using namespace std;

/*  Nama: Rayhan Ahmad Rizalullah
    NIM: 121140002
    Kelas: RB
    Tugas Stack dan Queue
    No. 2
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
int maxQ;
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
  if(nbElmt(L) == maxQ){
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
    int i=1;
    while (p != NULL) {
        cout<<p->num<<" ";

        p = p -> next;
        i++;
    }
}

// Menghapus kepala (elemen pertama) dari antrian
void dell(list &l, address p) {
    p = l.first;
    l.first = p -> next;
    p -> next = NULL;
}

// hapus node
void deallocate(address &p) {
    delete(p);
}

int main(){
    // deklarasi variabel
    int i,j,maxData,N,num;
    address now;

    cout<<"Masukkan data maksimal seluruhnya: ";
    cin>>maxData;
    cout<<"Masukkan pembagi: ";
    cin>>N; // bisa disebut juga baris

    maxQ=maxData/N;
    list l[N];

    for(i=0;i<N;i++){
      cout<<"Masukkan data pada queue ke-"<<i+1<<": \n";
      createList(l[i]);
      for(j=0;j<maxQ;j++){
        cin>>num;
        now=create_Elm(num);
        add(l[i],now);
      }
    }
    cout<<endl;

    for(i=0;i<N;i++){
      printQ(l[i]);
      cout<<endl;
    }
}