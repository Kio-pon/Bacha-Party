#include <iostream>
using namespace std;

int main(){
    // DYNAMIC MEMORY ALLOCATION
    /*
        Before we understand what dynamic memory allocation we need to understand the what stack
        and heap are.
        
        => STACK
        Stack is region of memory used for function calls, local variables, and control flow.
        Imagine a literal stack of bags!
        So when we call a function (remember main is also a function), that function is assigned to the stack
            function is like a bag, with its own variable.
        Just like a stack of bags, you can add more bags (functions) on top of it. and when you have to remove
            a bag, you start from the one on top (last added)
        Just like any ordinary stack of bags, where you have to know the size of bag before you add it to stack
            stack in computer's memory needs to know the size of memory being allocated
            
        => HEAP
        Heap, as the name suggests, a region of memory managed at runtime, and can be allocated to your program on request
        Imagine a literal heap of clothes!
        That heap can be used when you are in a hurry and haven't planned your day ahead.
        Similary, when you don't know how much memory your program might needs in future, you use the heap to assign
            the program memory
        Just like the heap of clothes on your chair, you need to clean the heap memory after you used it in memory!
    */

    int* new_int = new int;         // new int-> this is dynamic memory allocation, C++ is returning a pointer to this memory
                                    //              this point is then stored in int* new_int
    
    
    // Do whatever you want with new_int (like maybe assigning it a value *new_int = 5) then printing it
    *new_int = 5;
    cout << "Value assigned to the dynamic memory: " << *new_int << endl;
    // END of "do whatever"

    delete new_int;                 // now that you have used the memory, its time to DEALLOCATE it
    cout << "Value assigned to the dynamic memory: " << *new_int << endl;    // this will output garbage, because the memory has been "freed" or  "deallocated", so its no more ours           
    new_int = nullptr;              // no more dangling pointers

    /*
        What if we want more than a single integer
        No worries, we will just allocate our program an array from heap
    */

    int* new_array = new int[10];
    // here we can take the size using cin, as variable length arrays for dynamic memory allocation are allowed

    delete[] new_array;

    /*
        Now we will put this knowledge to use and see how we can make a primitive implementation
        of lists in python
        Remember in C++ we cannot append another element to the array, but in python's lists we can
        Lets implement it
    */

    /*
        struct is just data aggreggation
            so we will keep track of size and a pointer (lets call this records, cause its keeping records of the data we want to have) 
                which will point to a dynamically allocated array
            Why dynamically allocated? because then we can create whatever size array we want during run-time
                and just assign that to our pointer
    */
    struct list{
        int size = 0;
        int* records = NULL;

        /*
            these functions are defined within the structure list, so they are member functions, so they will be accessed just like
            other variables ie list_instance.size, list_instance.records, list_instance.add_int() etc

            This is just a design option, you can define these functions outside of the stucture. This will require these functions
                to explicity take in a "list" argument (as they will be changing a list instance) like void add_int(int x, list y)

            You will see a fucntion like ~list(), ignore that for now, we will see what it does in future
        */
        void append(int x){
            int* new_array = new int[size + 1]; // a new block of memory just one bigger than what already have 
            
            // copying data from records (smaller array) to new_array (bigger array)
            for(int i = 0; i < size; i++){
                new_array[i] = records[i];
            }
            new_array[size] = x;        // assigning the last index the number we want to append
                                        //  remember at this point, this new_array has not been assigned to our list, its just in the heap
            delete[] records;           // since we have a copy of records (with the appended number), we don't need them
                                        //  so we will free that memory
            records = new_array;        // now records point to the new_array (update copy of records), so our structure has updated copy
            size++;                     // update the size
        }

        /*
            remember in python when you did list.append, it can take one input like list.append(1) or more list.append([1,2,3])
            how can the same fucntion can have different functionalities
            this is called function overloading. (we will work on this in future)
        */
        void append(int* x, int input_size){
            int* new_array = new int[size + input_size]; // allocate a new block of memory big enough to hold old records + new input
            
            // copy old records into the new block
            for(int i = 0; i < size; i++){
                new_array[i] = records[i];
            }

            // append the new elements one by one after the existing records
            for(int i = 0; i < input_size; i++){
                new_array[size + i] = x[i];
            }

            delete[] records;       // free the old smaller block, since its contents have been copied
            records = new_array;    // now records points to the new, bigger block
            size += input_size;     // update size to reflect the newly added elements
        }

        void show(){
            for(int i = 0; i < size; i++){
                cout << records[i] << " ";
            }
        }

        ~list() {
            delete[] records;
        }
    };

    list python_like_list;
    python_like_list.append(1);
    python_like_list.append(2);
    python_like_list.append(3);
    python_like_list.append(4);
    
    int list[3] = {5,6,7};
    python_like_list.append(list, 3);
    python_like_list.show();
    cout << endl;

}