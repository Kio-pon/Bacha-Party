#include<iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T1, typename T2> 
class Map_Key
{
        private:
            T1 key;
            T2 val;
        public:
        Map_Key() {};
        Map_Key(const T1& k, const T2& v) : key(k), val(v)
         {};
        bool check(T1 k) const {
            return (this->key == k);
        }
        //get()  {}
        
        T2 get(const T1& k){
            if (check(k)){
                return this->val;
            }
            return NULL;
        }
        Map_Key<T1, T2> operator+(const Map_Key& mk) const
        {
            Map_Key<T1 , T2> sum ;
            sum.key = key + mk.key;
            sum.val = val + mk.val;
            return sum;
        }
};

int main()
{

    Map_Key<string, int> mk_1("One", 1232), mk_2("Two", 2);
    Map_Key<int ,string> mk(123 , "Hello");
    cout << "Key checking : m" << mk_1.check("Ten")<< endl;   // false
    cout << "Key checking : m" << mk_1.check("One")<< endl;    // true
 
    cout << "Value of mk_1 : " << mk_1.get("One")<< endl;  //1232 
    cout << "Value of mk_1 : " << mk_1.get("Bye")<< endl;  // 0
    cout << "Value of mk : " << mk.get(123)<< endl; //Hello
   // cout << "Value of mk_1 : " << mk.get(12)<< endl;  // NULL/0 // Exception catch //error handling

    Map_Key<string, int> mk_3 = mk_1 + mk_2; //key : One + Two = OneTwo // val : 1232+2 = 1234
    cout << "Value of mk_3 : " << mk_3.get("OneTwo")<< endl;  //1234 

    return 0;
}
