#include <iostream>
using namespace std;
class person
{
public:
    person()
    {
        cout << "Function with no arguments!" << endl;
    }
    ~person()
    {
        cout << "Destructor!" << endl;
    }
};
int main(void)
{
    person p1;
    return 0;
}