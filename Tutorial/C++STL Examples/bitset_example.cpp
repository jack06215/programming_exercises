#include <bitset>
#include <iostream>

using namespace std;

void example_1() {
    std::bitset<8> bs;      // 8 bit set, initialize all bits to 0
    bs[0] = 1;              // set bit 0 to 1
    bs[1] = 0;              // set bit 1 to 0
    bs[2] = true;           // set bit 2 to 1
    bs[3] = false;          // set bit 3 to 0
    cout << bs << endl;
}

void example_2() {
    unsigned long int value = 23244;
    bitset<32> bs(value);                   // 無符號長整型可以用於初始化bs，若整型數值的位數超過bs的位數，只取低位部分
    bitset<8> bs8(value);
    unsigned long int new_value = bs.to_ulong();     // bitset可以轉換為無符號長整型

    cout << "value=" << hex << value << endl;
    cout << "bs=" << bs << endl;
    cout << "bs8=" << bs8 << endl;
    cout << "new_value=" << hex << new_value << endl;
}

void example_3() {
    string str = "011001011101";
    bitset<8>bs1(str);                  // 字串長度大於bs，只取字串左邊
    bitset<16>bs2(str);                 // 字串長度小於bs，高位補零
    bitset<8>bs3(str, 4);               // 從str中第4個位置開始複製
    bitset<8>bs4(str, 3, 6);            // 從str中第3個位置開始複製6個位，高位剩餘位補零
    string str1 = bs1.to_string();
    string str2 = bs2.to_string();
    string str3 = bs3.to_string();
    string str4 = bs4.to_string();

    cout << "str=" << str << endl;
    cout << "bs1=" << bs1 << endl;
    cout << "bs2=" << bs2 << endl;
    cout << "bs3=" << bs3 << endl;
    cout << "bs4=" << bs4 << endl;
    cout << "str1=" << str1 << endl;
    cout << "str2=" << str2 << endl;
    cout << "str3=" << str3 << endl;
    cout << "str4=" << str4 << endl;
}

void example_4() {
    bitset<16>bs("011001011101");
    cout << "bs=" << bs << endl;
    cout << "bs中是否存在1？ " << bs.any() << endl;         // any()方法判斷是否存在置為1的二進位制位
    cout << "bs中是否不存在1？ " << bs.none() << endl;      // none()方法判斷是否不存在置為1的二進位制位，即全為0
    cout << "bs的總位數" << bs.size() << endl;              // size()方法計算二進位制位數
    cout << "bs中1的總位數：" << bs.count() << endl;        // count()方法計算二進位制中1的位數
    cout << "bs第四位是否為1？ " << bs.test(4) << endl;     // test(size_t pos)方法判斷pos位是否為1
    cout << "按位取反後bs=" << bs.flip() << endl;           // flip()方法將bitset按位取反
    cout << "bs第3位取反後bs=" << bs.flip(3) << endl;       // flip(size_t pos)將bitset的pos位取反
    cout << "bs全置1後bs=" << bs.set() << endl;             // set()方法將bs全置1
    cout << "bs全置0後bs=" << bs.reset() << endl;           // reset()方法將bs全置0
    cout << "bs第5位置1後bs=" << bs.set(5) << endl;         // set(size_t pos)將bs的第pos位置1
    cout << "bs第5位置0後bs=" << bs.reset(5) << endl;       // reset(size_t pos)將bs的第pos位置0
}

int main() {
    // example_1();
    // example_3();
    example_4();
    return 0;
}