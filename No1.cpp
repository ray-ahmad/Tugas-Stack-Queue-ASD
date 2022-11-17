#include<iostream>
using namespace std;

/*  Nama: Rayhan Ahmad Rizalullah
    NIM: 121140002
    Kelas: RB
    Tugas Stack dan Queue
    No. 1
*/

struct data{
  int num;

  data *prev;
  data *next;
};

data *head, *tail, *cur, *newNode, *del;
int maksimal = 9999;

void create(int num){
  head = new data();
  head->num = num;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int count(){
  if(head == NULL){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while(cur != NULL){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

// cek apakah stack penuh
bool isFull(){
  if( count() == maksimal ){
    return true;
  }else{
    return false;
  }
}

// cek apakah stack kosong
bool isEmpty(){
  if( count() == 0 ){
    return true;
  }else{
    return false;
  }
}

void push(int num){

  if(isFull()){
    cout << "Stack Penuh" << endl;
  }
  else{
    if(isEmpty()){
      create(num);
    }
    else{
      newNode = new data();
      newNode->num = num;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }

}

// hapus data terakhir
void pop(){
  if(count() == 1){
    delete head;
    head = NULL;
    tail = NULL;
  }
  else{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}

// cetak data
void display(){
  if(isEmpty()){
    cout << "Data kosong";
  }
  else{
    cur = tail;
    while(cur != NULL){
      cout << cur->num <<" ";
      cur = cur->prev;
    }
  }
}

void destroy() {
  cur = head;
  while(cur != NULL){
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main(){
    int N,i,j,d;
    string kalimat;

    cout<<"Masukkan jumlah kasus: ";
    cin>>N; cin.ignore(); 
    cout<<endl;

    for(i=0;i<N;i++){
      cout<<"Masukkan kalimat ke-"<<i+1<<": ";
      getline(cin,kalimat);

      // Perulangan dari 0 sampai panjang variabel kalimar
      for(j=0;j<kalimat.length();j++){
        /* dalam aturan ASCII angka 0 di urutan ke 48 dan angka 9
        di urutan ke 57
        Percabangan ini hanya menerima char di urutan ASCII tersebut
        dan lakukan push, selain itu abaikan....*/
        if(int(kalimat[j]) >= 48 && int(kalimat[j]) <= 57){
          d = kalimat[j]-48;
          push(d);
        }
        /* ...kecuali underscore
        jika terdapat underscore, lakukan pop
        */
        if(kalimat[j] == '_'){
          pop();
        }
      }

    cout<<"Data kalimat ke-"<<i+1<<": ";
    display();
    //  hapus stack untuk diisi dengan kasus kalimat yang lain
    destroy();
    cout<<"\n\n";
    }
}