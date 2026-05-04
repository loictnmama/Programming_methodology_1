#include <iostream>
#include <string>
using namespace std;


int main()
{
    
    //4-digit numbers

    int digits;

    cout << "Enter a 4 digits : ";
    cin >> digits;
    cout << endl;


    // invalid digits

    if (digits > 9999)
    {

        cout << "Invalid number!\n";

}
    else
        if (digits <= 0000)
        {

            cout << "Invalid number!\n";

        }
        else
        {
            //sum of the digits

            int a, b, c, d, sumDigits;

            /* I used ChatGPT to help me find the final equation. I knew every digits needed to be extracted from their position. 
            So I found : ( (digits) / (position of the digit) ) but I missed the (% 10). a worked but not b, c and d.

            Here was my prompt : " You have a 4 digits numbers in c++ and you want to make the sum of every digits. What would be the equation in c++? "

            */

            a = digits / 1000;
            b = (digits / 100) % 10;
            c = (digits / 10) % 10;
            d = digits % 10;

            sumDigits = a + b + c + d;

            cout << "The sum of digits is : " << sumDigits << endl;


        }

    return 0;



}


