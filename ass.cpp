#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//int fopen(void);

class Flight {

private:
    struct info {

        string flightnum;
        string datetime;
        string dairport;
        string aairport;
        string seat[20];
    };

    struct info flightlist[50];

public:
    Flight()
    {

        fstream newfile;
        newfile.open("Flights.txt", ios::in);
        if (newfile.is_open()) {
            string p;
            int count = 0;
            int sc = 0;
            int flightcount = 0;

            while (getline(newfile, p)) {
                if (count == 0) {
                    flightlist[flightcount].flightnum = p;
                    //	cout << p << endl;
                }

                else if (count == 1) {
                    flightlist[flightcount].datetime = p;
                }

                else if (count == 2) {
                    flightlist[flightcount].dairport = p;
                }

                else if (count == 3) {
                    flightlist[flightcount].aairport = p;
                }

                else if (count >= 4 && p != "") {
                    flightlist[flightcount].seat[sc] = p;
                    sc++;
                }
                else if (p == "") {
                    flightcount++;
                    count = -1;
                    sc = 0;
                }

                count++;
            }

            newfile.close();
        }
    }
    void display()
    {

        int i, j, flag = 0, count;

        for (i = 0; i < 5; i++) {
            //	for(j=0 ; j < 10 ; j ++){
            j = 0;
            count = 0;
            while (flightlist[i].seat[j] != "") {
                flag = 1;
                j++;
            }
            if (flag) {
                cout << flightlist[i].flightnum << endl;
                cout << flightlist[i].datetime << endl;
                cout << flightlist[i].dairport << endl;
                cout << flightlist[i].aairport << endl;
                j = 0;
                count = 0;
                while (flightlist[i].seat[j] != "") {
                    int len = flightlist[i].seat[j].size();
                    //	count  = count + len;

                    int temp1, temp2, temp3;
                    int k;

                    cout << flightlist[i].seat[j] << endl;
                    j++;

                    char cstr[flightlist[i].seat[k].size() + 1];
                    strcpy(cstr, flightlist[i].seat[k].c_str());

                    char* token = strtok(cstr, " ");

                    while (token == NULL) {
                        cout << strlen(token) << endl;
                        token = strtok(cstr, " ");
                    }
                }
            }

            cout << count << endl;
        }
        cout << "\n\n";
    }

    void read()
    {

        int i;

        for (i = 0; i < 7; i++) {

            cout << flightlist[i].flightnum << endl;
            cout << flightlist[i].datetime << endl;
            cout << flightlist[i].dairport << endl;
            cout << flightlist[i].aairport << endl;
            cout << "\n\n";
        }
    }
};

int main()
{

    Flight f;

    cout << "please choose an option" << endl;
    cout << "*************************************" << endl;
    cout << "1 - Display available flight" << endl;
    cout << "2 - view flight" << endl;
    cout << "3 - seat availibility" << endl;
    cout << "4 - seat booking " << endl;
    cout << "*************************************" << endl;

    //	f.read() ;

    int op;

    cout << "enter the option " << endl;
    cin >> op;

    switch (op) {

    case 1:
        f.display();
        break;

    case 2:
        //	view();
        break;

    case 3:
        //	seat();
        break;

    case 4:
        //	booking();
        break;

    default:

        cout << "*************************************" << endl;
        cout << "invalid input " << endl;
        cout << "-------------------------------------" << endl;
        break;
    }
}

int view()
{

    return 0;
}

int seat()
{

    return 0;
}

int booking()
{

    return 0;
}

int fopen()
{

    return 0;
}
