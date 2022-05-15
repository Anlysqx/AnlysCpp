#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <array>

using namespace std;

long get_a_target_long()
{
    long target = 0;
    cout<<"target (0~" << RAND_MAX << "):";
    cin>>target;
    return target;
}

string get_a_target_string()
{
    long target = 0;
    char buf[10];
    cout<<"target (0~" << RAND_MAX << "):";
    cin>>target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareLongs(const void * a, const void * b)
{
    return *(long *) a - *(long *)b;
}

int compareStrings(const void * a, const void * b)
{
    if (*(string *)a > *(string *) b)
        return 1;
    else if (*(string *)a < *(string *)b)
        return -1;
    return 0;
}

const long ASIZE = 500000;
void test_array()
{
    cout<<"\n test_array()........\n";
    array<long, ASIZE> c;
    clock_t timeStart = clock();
    for (long i = 0 ; i < ASIZE ; i++){
        c[i] = rand();
    }
    cout<<"milli-seconds : "<<(clock() - timeStart)<<endl;
    cout<<"array.size() = "<<c.size()<<endl;
    cout<<"array.front() = "<<c.front()<<endl;
    cout<<"array.back() = "<<c.back()<<endl;
    cout<<"array.data() = "<<c.data()<<endl;

    long target = get_a_target_long();
    timeStart = clock();
    qsort(c.data(), ASIZE, sizeof(long), compareLongs);
    cout<<endl;
    long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
    cout<<"qsort + binary search milli-seconds = "<<(clock() - timeStart)<<endl;
    if (pItem != NULL)
        cout<<"found, "<<*pItem<<endl;
    else
        cout<<"not found"<<endl;

}



int main()
{
    test_array();
    return 0;
}
