
/**
 * @mainpage Documentation Circular Queues
 *
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 *
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 *
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 *
 * @author Profil
 * - nama : Al-Bukhari Insan Kamil
 * - nim  : 20240140270
 * - kelas : F
 
 * @brief
 * @version 1.0
 * @date 2025-06-23
 * 
 * @copyright albukhari.insan.ft24@mail.umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
 */
class Queues {
private:
    int FRONT; ///< variable private front untuk menyimpan posisi depan antrian
    int REAR;  ///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5; ///< variable private max untuk menyimpan kapasitas antrian
    int queue_array[5]; ///< array untuk menyimpan elemen antrian

public:
    /** 
     * @brief Constructor a new Queues object
     * set default queues dan null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */
    void insert() {
        int num;///< variable num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;
    }
};

#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert () {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            // jika REAR sudah mencapai akhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief method untuk menghapus data dari antrian
     * data dihapus dari variable queue_array
     */
    void remove() {
        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "\nQueue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << endl;

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // jika elemen yang dihapus berada di posisis terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief method untuk menghapus data dari antrian
     * data dihapus dari variable queue_array
     */
    void display() {
        int FRONT_position = FRONT; ///< variable front_position untuk menyimpan posisi depan antrian
        int REAR_position = REAR; ///< variable rear_position untuk menyimpan posisi belakang antrian

        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "\nQueue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // jika FRONT_position <= REAR_positition, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max -1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
            FRONT_position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */

int main() {
    Queues q;///< objek untuk menggunakan member yang ada pada class Queues
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1' : {
                q.insert();
                break;
            } 
            case '2' : {
                q.remove();
                break;
            }
            case '3' : {
                q.display();
                break;
            }
            case '4' : {
                return 0;
            }
            default: {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
    }
}