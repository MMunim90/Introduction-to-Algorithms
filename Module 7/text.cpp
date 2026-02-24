# Function Overloading

Function Overloading হলো এমন একটি feature যেখানে একই নামের একাধিক function তৈরি করা যায়, কিন্তু তাদের parameter ভিন্ন হতে হবে।

মানে, function এর নাম একই থাকবে, কিন্তু,

* parameter সংখ্যা আলাদা হতে পারে
* parameter এর data type আলাদা হতে পারে
* অথবা parameter এর order আলাদা হতে পারে



# উদাহরণ

#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << add(5, 3) << endl;        // int version
    cout << add(2.5, 3.5) << endl;    // double version
    cout << add(1, 2, 3) << endl;     // 3 parameter version
}


এখানে তিনটা function এর নাম add।
কিন্তু parameter আলাদা। তাই compiler বুঝতে পারে কোনটা call করতে হবে।



# Compiler কীভাবে বুঝে?

Compiler function call করার সময় argument দেখে ঠিক করে কোন function ব্যবহার করবে।
এটাকে বলে Compile Time Polymorphism।



# গুরুত্বপূর্ণ নিয়ম

১. শুধু return type আলাদা হলে overloading হবে না ❌


ভুল উদাহরণ:

int add(int a, int b);
double add(int a, int b);  // এটা error দেবে

এখানে parameter একই, শুধু return type আলাদা। এটা allowed না।



# কেন দরকার?

* কোড readable হয়
* একই কাজের জন্য আলাদা নাম দিতে হয় না
* logically related কাজগুলো একই নামে রাখা যায়


