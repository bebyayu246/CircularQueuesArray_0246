#include <iostream>
using namespace std;

class Queues //kelas yang mengimplementasikan struktur data antrian (queue) menggunakan array statis.
{
private:
    int FRONT, REAR, max = 5; //front =menunjuk ke elemen pertama dalam antrian (yang akan dihapus/dikeluarkan berikutnya).
    int queue_array[5];     //REAR menunjuk ke elemen terakhir dalam antrian (tempat elemen baru akan ditambahkan). 
                            //max 5 maksudnya antrian memliki kapasitas 5 elemen
public:                   //int queue_array[5];Ini adalah array (larik) dengan ukuran 5 yang digunakan untuk menyimpan elemen-elemen antrian. Array ini memiliki indeks dari 0 hingga 4.
    Queues()
    {
        FRONT = -1; // Inisialisasi: antrian kosong dan tidak ada elemen yang bisa diambil (dequeue).
        REAR = -1;
    }
    void insert() //Fungsi ini bertujuan untuk memasukkan sebuah angka ke dalam antrian (queue).
      //Pengguna akan diminta memasukkan sebuah bilangan, lalu bilangan tersebut akan diproses (kemungkinan dimasukkan ke antrian).
    {
        int num;
        cout << "Enter a number: ";
        cin >> num; //Mengambil input dari pengguna melalui keyboard dan menyimpannya ke variabel num.
        cout << endl;

        // cek apakah antrian penuh/Pengecekan Overflow (ketika antrian sudah penuh dan tidak bisa menambah elemen baru)
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) //kasus linear || kasus circular
        {    //FRONT == 0 (elemen pertama antrian ada di indeks 0)
             //REAR == max - 1 (elemen terakhir antrian ada di indeks terakhir array)
             // front==rear+1    REAR sudah "melewati" FRONT secara melingkar
             //ika max = 5, FRONT = 3, dan REAR = 2, maka FRONT == REAR + 1 → penuh.
            cout << "\nQueue overflow\n"; //tanda kalau sudah penuh
            return;
        }
        // cek apakah antrian kosong
        if (FRONT == -1) //tanda kalau antrian kosong 
        {
            FRONT = 0; //RONT dan REAR ke 0 (indeks pertama array) 
            REAR = 0; // karena elemen pertama akan dimasukkan.
        }
        else
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array (circular)
            if (REAR == max - 1) //Mengecek REAR sudah berada di indeks terakhir array
                REAR = 0; //penanda kalau disuruh ke awal array (circular)
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num; //Menyimpan nilai num ke dalam array queue_array pada posisi yang ditunjuk oleh REAR
    }
        
        void remove() {
            //cek apakah antrian kosong
            if ( FRONT == -1 ) {
                cout << " Queue underflow\n";
                return;
            }
            cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

            //cek jika antrian hanya memiliki satu elemen
            if ( FRONT == REAR ) {
                FRONT = 1;
                REAR = 1;
            }

            //jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if ( FRONT == max -1 ) 
                 FRONT = 0;
            else    
                FRONT = FRONT + 1;
        }
        void display() {
    int FRONT_position = FRONT;
    int REAR_position = REAR;

    //cek apakah antrian kosong
    if ( FRONT == -1 ) {
        cout << " Queue is empty\n ";
        return;
    }

    cout << "\nElements in the queue are...\n";

    //Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
    if ( FRONT_position <= REAR_position) {
        while ( FRONT_position <= REAR_position) {
            cout << queue_array[FRONT_position] << " ";
            FRONT_position++;
        }
        cout <<  endl;
    }
    else {
        //jika FRONT_position > REAR_position iterasi dari FRONT hingga akhir array
        while ( FRONT_position <= max - 1) {
            cout << queue_array[FRONT_position] << " ";
            FRONT_position++;
        }

        FRONT_position = 0;

        //iterasi dari awal array hingga REAR
        while ( FRONT_position <= REAR_position ) {
            cout << queue_array[FRONT_position] << " ";
            FRONT_position++;
        }
        cout << endl;
        }
    }   
};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try 
        {
            cout << " Menu " << endl;
            cout << " 1. Implementasi insert opreation " << endl;
            cout << " 2. Implementasi delete opreation  " << endl;
            cout << " 3. Display values " << endl;
            cout << " 4. Exit " << endl;
            cout << " Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
                }
            }
            catch ( exception &e)
            {
                cout << "Check for the values entered." << endl;
            }
        }
};


//fungsi rear untuk menambahkan data
//fungsi front nilai utama atau pertama
//ketika rear sudah ditambahkan maka dia berada di posisi index 0 (pertama) dan berada pada ujung disebur circular.
//nilai dapat ditambahkan ke dalam kolom index tetapi hasilnya akan rear