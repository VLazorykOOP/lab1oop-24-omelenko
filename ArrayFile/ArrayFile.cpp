 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
  }

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}

void Task1(int N, int M, int* A, int* B)
{
    int* C =  new int[N+M];//(int*)malloc((N+M)*sizeof(int));

    if (C == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    int c_i = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i] > 0)
        {
            C[c_i] = A[i];
            c_i++;
        }
    }
    for(int i = 0; i < M; i++)
    {
        if(B[i] > 0)
        {
            C[c_i] = B[i];
            c_i++;
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(A[i] < 0)
        {
            C[c_i] = A[i];
            c_i++;
        }
    }
    for(int i = 0; i < M; i++)
    {
        if(B[i] < 0)
        {
            C[c_i] = B[i];
            c_i++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}

void Task2(int N, int* A, int ak, int bk)
{
    int firstPosIndex;
    if(ak > N || bk > N)
    {}
    else
    {
        for(int i = ak; i < bk; i++)
        {
            if(A[i] > 0)
            {
                firstPosIndex = i;
                break;
            }
        }
        int max = 0;
        int max_index = 0;
        for(int i = firstPosIndex; i < bk; i++)
        {
            if(A[i] > max)
            {
                max = A[i];
                max_index = i;
            }
        }
        cout << "Max element index: ";
        cout << max_index;
        cout << " Max element: ";
        cout << max << endl;
    }
}

void Task3(int k, int N, int* A, int* A1)
{
    if (N < 200)
    {
        int A1_i = 0;
        for (int i = N - k; i < N; i++)
        {
            A1[A1_i] = A[i];
            A1_i++;
        }
        for (int i = 0; i < N - k; i++)
        {
            A1[A1_i] = A[i];
            A1_i++;
        }
    }
}

/*
*  Task  Var
* 
* 
*/

void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << '1' << endl; break;//Task1(); break;
             case '2': cout << '2' << endl; break;//Task2(); break;
             //case '3': Task3(); break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);
    
}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}


int main()
{ 
    int N = 5;
    int k = 2;
    int* A = new int[N];
    int* A1 = new int[N];

    cout << "Array: \n";
    for(int i = 0; i < N; i++)
    {
        A[i] = i+1;
    }
    cout<<endl;

    cout << "Moved Array: \n";
    for(int i = 0; i < N; i++)
    {
        A1[i] = i+1;
    }
    cout<<endl;
    
    Task3(k, N, A, A1);

    for(int i = 0; i < N; i++)
    {
        cout << A1[i] << " ";
    }
}
