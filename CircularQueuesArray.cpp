/**
 * @mainpage Documentation circular queues
 * 
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operasi apa yang ada didalam projeknya
 * - en queues for insert elements into queues
 * - de queues for delete elements from queues
 * - show data or display data
 * @section How to use
 * 1. Insert  
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfil
 * -Nama  :
 * -Nim   :
 * -Kelas : 
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */

class Queues //kelas yang mengimplementasikan struktur data antrian (queue) menggunakan array statis.
{
private:
    ///front menunjuk ke elemen pertama dalam antrian (yang akan dihapus/dikeluarkan berikutnya).
    int FRONT;
    ///REAR menunjuk ke elemen terakhir dalam antrian (tempat elemen baru akan ditambahkan). 
    int REAR; 
    ///max 5 maksudnya antrian memliki kapasitas 5 elemen
    int max = 5; 
    ///int queue_array[5];Ini adalah array (larik) dengan ukuran 5 yang digunakan untuk menyimpan elemen-elemen antrian. Array ini memiliki indeks dari 0 hingga 4.
    int queue_array[5]; 
                            
public: 
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1; /// Inisialisasi: antrian kosong dan tidak ada elemen yang bisa diambil (dequeue).
        REAR = -1;
    }

    /**
     * @brief Method for entering data into a queues
     * Fungsi ini bertujuan untuk memasukkan sebuah angka ke dalam antrian (queue)
     */
    void insert() 
      ///Pengguna akan diminta memasukkan sebuah bilangan, lalu bilangan tersebut akan diproses (kemungkinan dimasukkan ke antrian).
    {
        int num; ///variabel publik nomor untuk mengidentifikasi nomor di elemen
        cout << "Enter a number: "; ///menampilkan hasil dari tulisan "Enter a number"
        cin >> num; ///Mengambil input dari pengguna melalui keyboard dan menyimpannya ke variabel num.
        cout << endl; ///mengakhiri program yang telah dijalankan

        /// cek apakah antrian penuh/Pengecekan Overflow (ketika antrian sudah penuh dan tidak bisa menambah elemen baru)
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) ///kasus linear || kasus circular
        {    ///FRONT == 0 (elemen pertama antrian ada di indeks 0)
             ///REAR == max - 1 (elemen terakhir antrian ada di indeks terakhir array)
             ///front==rear+1    REAR sudah "melewati" FRONT secara melingkar
             ///jika max = 5, FRONT = 3, dan REAR = 2, maka FRONT == REAR + 1 → penuh.
            cout << "\nQueue overflow\n"; ///tanda kalau sudah penuh
            return;
        }
        // cek apakah antrian kosong
        if (FRONT == -1) ///tanda kalau antrian kosong 
        {
            FRONT = 0; ///RONT dan REAR ke 0 (indeks pertama array) 
            REAR = 0; /// karena elemen pertama akan dimasukkan.
        }
        else
        {
            /// jika REAR berada di posisi terakhir array, kembali ke awal array (circular)
            if (REAR == max - 1) ///Mengecek REAR sudah berada di indeks terakhir array
                REAR = 0; ///penanda kalau disuruh ke awal array (circular)
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num; ///Menyimpan nilai num ke dalam array queue_array pada posisi yang ditunjuk oleh REAR
    }
        
    /**
     * @brief fungsi ini untuk menghapus data yang tidak mengembalikan nilai
     * 
     */
    void remove()
        ///fungsi ini untuk menghapus data yang tidak mengembalikan nilai
         {
            ///cek apakah antrian kosong
            if ( FRONT == -1 ) {
                cout << " Queue underflow\n";
                return;
            }
            cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

            ///cek jika antrian hanya memiliki satu elemen
            if ( FRONT == REAR ) {
                FRONT = 1;
                REAR = 1;
            }

            ///jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if ( FRONT == max -1 ) 
                 FRONT = 0;
            else    
                FRONT = FRONT + 1;
        }

    /**
     * @brief Menampilkan isi data dari suatu struktur data
     * 
     */
    void display() {
    int FRONT_position = FRONT; ///menyimpan posisi depan di dalam variabel front
    int REAR_position = REAR; ///menyimpan posisi belakang di dalam variabel REAR

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

/**
 * @brief titik awal eksekusi program yang akan dijalankan
 * 
 * @return int 
 */
int main()
{
    Queues q; ///object untuk menggunakan queues
    char ch; ///object untuk menggunakan character 

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